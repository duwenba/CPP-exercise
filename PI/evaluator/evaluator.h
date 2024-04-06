//
// Created by 22753 on 2024/4/6.
//

#pragma once

#include <ast/header.h>
#include <object/header.h>

using namespace pi::obj;
using namespace pi::ast;

namespace pi::eval {

    class Evaluator {
    public:
        Evaluator() = default;
        ~Evaluator() = default;

        static bool isError(shared_ptr<Object> & obj);
//        static shared_ptr<Object> newError(const char * format, ...);

        shared_ptr<Object> eval(shared_ptr<Node> & node);
        shared_ptr<Object> evalProgram(std::list<shared_ptr<ast::Statement>> & statements);
        shared_ptr<Object> evalInteger(shared_ptr<ast::Integer> &node);
        shared_ptr<Object> evalInfix(const string &op, shared_ptr<Object> &left, shared_ptr<Object> &right);
        shared_ptr<Object> evalIntegerInfix(const string &op, shared_ptr<Object> &left, shared_ptr<Object> &right);


    };

} // eval
// pi
