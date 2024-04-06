//
// Created by 22753 on 2024/4/6.
//

#include "evaluator.h"

using namespace pi::eval;

shared_ptr<Object> Evaluator::evalProgram(std::list<shared_ptr<ast::Statement>> &statements) {
    shared_ptr<Object> result = nullptr;
    for(auto &statement : statements){
        result = eval(statement);
        if(result->getType() == Object::Type::OBJ_ERROR){
            break;
        }
    }
    return result;
}