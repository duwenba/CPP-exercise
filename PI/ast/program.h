//
// Created by 22753 on 2024/4/4.
//

#ifndef PI_PROGRAM_H
#define PI_PROGRAM_H


#include <ast/node.h>
#include <memory>
#include <list>


namespace pi {
    namespace ast {

        class Program : public Statement {
        public:
            Program() : Statement(Type::PROGRAM) {};
            ~Program() override = default;

        public:
            std::list<std::shared_ptr<Statement>> statements;
        };

    } // ast
} // pi

#endif //PI_PROGRAM_H
