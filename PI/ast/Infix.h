//
// Created by 22753 on 2024/4/4.
//

#pragma once

#include <memory>
#include <ast/node.h>

using std::shared_ptr;

namespace pi {
    namespace ast {

        class Infix : public Expression {
        public:
            Infix() : Expression(Type::INFIX) {};

            ~Infix() override = default;

            virtual json::value toJson() override {
                json::value  json;
                json["type"] = name();
                json["operator"] = mOperator;
                json["left"] = left->toJson();
                json["right"] = right->toJson();
                return json;
            }

        public:
            string mOperator;
            shared_ptr<Expression> left;
            shared_ptr<Expression> right;
        };

    } // ast
} // pi


