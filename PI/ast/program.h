//
// Created by 22753 on 2024/4/4.
//
#pragma once



#include <ast/node.h>
#include <memory>
#include <list>
#include <iostream>


namespace pi::ast {

        class Program : public Statement {
        public:
            Program() : Statement(Type::PROGRAM) {};
            ~Program() override = default;

            virtual json::value toJson() override {
                json::value json;
                json["type"] = name();
                json::value  statement_json = json::array{};
                try {
                    for (auto &statement: statements) {
                        statement_json.push_back(statement->toJson());
                    }
                } catch (const std::exception &e) {
                    std::cerr << e.what() << std::endl;
                }
                json["statements"] = statement_json;
                return json;
            }

        public:
            std::list<std::shared_ptr<Statement>> statements;
        };

} // ast



