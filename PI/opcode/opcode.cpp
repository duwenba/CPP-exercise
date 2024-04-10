//
// Created by 22753 on 2024/4/7.
//

#include "opcode.h"
#include <stdexcept>>


namespace pi::opcode {

    std::map<Opcode::Type, Opcode> Opcode::type_name = {
            {OP_PUSH,   Opcode{"push",{2}}},
            {OP_LOAD,   Opcode{"load",{2}}},
            {OP_ADD,    Opcode{"add",{}}},
            {OP_SUB,    Opcode{"sub",{}}},
            {OP_MUL,    Opcode{"mul",{}}},
            {OP_DIV,    Opcode{"div",{}}},
            {OP_POP,    Opcode{"pop",{}}},
    };

    Opcode Opcode::lookup(Opcode::Type op) {
        auto it = type_name.find(op);
        if (it != type_name.end()) {
            return it->second;
        } else {
            throw std::logic_error("undefined opcode");
        }
    }


} // opcode
// pi