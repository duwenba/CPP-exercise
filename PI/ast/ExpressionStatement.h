//
// Created by 22753 on 2024/4/4.
//

#ifndef PI_EXPRESSIONSTATEMENT_H
#define PI_EXPRESSIONSTATEMENT_H

#include <ast/node.h>
#include <memory>

namespace pi {
    namespace ast {

        class ExpressionStatement : public Node {
        public:
            ExpressionStatement() : Node(Type::EXPRESSION_STATEMENT) {};
            ~ExpressionStatement() override = default;

        public:
            std::shared_ptr<Expression> expression;
        };// ExpressionStatement

    } // ast
} // pi

#endif //PI_EXPRESSIONSTATEMENT_H
