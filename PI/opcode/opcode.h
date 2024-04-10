//
// Created by 22753 on 2024/4/7.
//

#pragma once


#include <string>
#include <map>
#include <vector>
using std::string,std::map;

namespace pi::opcode {

    class Opcode {
    public:
        enum Type{
            OP_PUSH = 0, //push value
            OP_LOAD,        //load value
            OP_ADD,         //add +
            OP_SUB,         //sub -
            OP_MUL,         //mul *
            OP_DIV,         //div /
            OP_POP,         //pop
        };
        Opcode() = default;
        ~Opcode() = default;

        static Opcode lookup(Opcode::Type op);

    public:
        string name;
        std::vector<int> mOperandsWidth;
        static map<Type, Opcode> type_name;
    };

}

