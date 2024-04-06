//
// Created by 22753 on 2024/4/6.
//
#include <evaluator/evaluator.h>

using namespace pi::eval;

shared_ptr<Object> Evaluator::evalInteger(shared_ptr<ast::Integer> &node) {
    return Object::newInteger(node->value);
}