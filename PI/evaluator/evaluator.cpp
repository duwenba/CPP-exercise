//
// Created by 22753 on 2024/4/6.
//

#include <evaluator/evaluator.h>
#include <cstdarg>
#include <memory>

using namespace pi::eval;


shared_ptr<Object> Evaluator::eval(shared_ptr<Node> &node) {
    switch (node->type) {
        case Node::Type::PROGRAM:{
            auto program = std::dynamic_pointer_cast<Program>(node);
            return evalProgram(program->statements);
        }
        case Node::Type::EXPRESSION_STATEMENT:{
            auto expression = std::dynamic_pointer_cast<ExpressionStatement>(node);
            return eval(expression->expression);
            break;
        }
        case Node::Type::INTEGER:{
            auto integer = std::dynamic_pointer_cast<Integer>(node);
            return evalInteger(integer);
            break;
        }
        case Node::Type::INFIX:{
            auto infix = std::dynamic_pointer_cast<ast::Infix>(node);
            auto left = eval(infix->left);
            if (isError(left)) {
                return left;
            }
            auto right = eval(infix->right);
            if (isError(right)) {
                return right;
            }
            return evalInfix(infix->mOperator, left, right);
            break;
        }
        default: {
            return std::shared_ptr<Object>(Object::newError("unknown node type"));
        }
    }
}

bool Evaluator::isError(shared_ptr<Object> &obj) {
    return obj->getType() == Object::Type::OBJ_ERROR;
}






