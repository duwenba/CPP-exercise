//
// Created by 22753 on 2024/4/4.
//

#pragma once
#include <ast/node.h>

namespace pi {

    namespace ast{
        class Integer : public Expression {
        public:
            Integer() = default;
            Integer(int value)  : Expression(INTEGER) {};
            ~Integer() override = default;

            virtual json::value toJson() override {
                json::value json;
                json["value"] = std::to_string(value);
                json["type"] = name();
                return json;
            }

        public:
            int64_t value;
        };
    }
}


