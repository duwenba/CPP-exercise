//
// Created by 22753 on 2024/4/4.
//

#pragma once

#include <ast/node.h>
#include <memory>

namespace pi {
    namespace ast {

        class ExpressionStatement : public Statement {
        public:
            ExpressionStatement() : Statement(Type::EXPRESSION_STATEMENT) {};
            ~ExpressionStatement() override = default;

            virtual json::value toJson() override {
                json::value json;
                json["type"] = name();
                json["expression"] = expression->toJson();
                return json;
            }

        public:
            std::shared_ptr<Expression> expression;
        };// ExpressionStatement

    } // ast
} // pi


