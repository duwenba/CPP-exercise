//
// Created by 22753 on 2024/4/4.
//

#ifndef PI_INTEGER_H
#define PI_INTEGER_H

#include <ast/node.h>

namespace pi {

    namespace ast{
        class Integer : public Expression {
        public:
            Integer(int value)  : Expression(INTEGER) {};
            ~Integer() override = default;

        public:
            int64_t value;
        };
    }
}

#endif //PI_INTEGER_H
