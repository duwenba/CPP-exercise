//
// Created by 22753 on 2024/4/6.
//
#include <evaluator/evaluator.h>

using namespace pi::eval;

shared_ptr<Object> Evaluator::evalInfix(const std::string &op,shared_ptr<pi::obj::Object> &left,shared_ptr<pi::obj::Object> &right)
{
    switch (left->getType()) {
        case Object::OBJ_INTEGER: {
            if(right->getType() == Object::OBJ_INTEGER){
                return evalIntegerInfix(op, left, right);
            }
            break;
        }
        default: {
            break;
        }
    }
    return Object::newError("unknown operator %s %s %s.",
                    left->getTypeName().c_str(),
                    op.c_str(),
                    right->getTypeName().c_str());
}


shared_ptr<Object>
Evaluator::evalIntegerInfix(const string &op, shared_ptr<Object> &left, shared_ptr<Object> &right) {
    auto l = std::dynamic_pointer_cast<obj::Integer>(left);
    auto r = std::dynamic_pointer_cast<obj::Integer>(right);
    switch (op[0]) {
        case '+':
            return Object::newInteger(l->value + r->value);
        case '-':
            return Object::newInteger(l->value - r->value);
        case '*':
            return Object::newInteger(l->value * r->value);
        case '/': {
            if (r->value == 0) {
                return Object::newError("divide by zero.");
            }
            return Object::newInteger(l->value / r->value);
        }
        default:
            return Object::newError("unknown operator %s %s %s.",
                            left->getTypeName().c_str(),
                            op.c_str(),
                            right->getTypeName().c_str());
        }
}