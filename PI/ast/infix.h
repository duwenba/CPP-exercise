//
// Created by 22753 on 2024/4/4.
//

#ifndef PI_INFIX_H
#define PI_INFIX_H

#include <memory>
#include <ast/node.h>

using std::shared_ptr;

namespace pi {
    namespace ast {

        class infix : public Expression {
        public:
            infix() : Expression(Type::INFIX) {};

            ~infix() override = default;

        public:
            string mOperator;
            shared_ptr<Expression> left;
            shared_ptr<Expression> right;
        };

    } // ast
} // pi

#endif //PI_INFIX_H
