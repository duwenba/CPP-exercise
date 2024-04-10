//
// Created by 22753 on 2024/4/7.
//

#include "Instruction.h"

namespace pi::opcode {

    bool Instruction::make(Opcode::Type type, const std::vector<int> &oprands) {
        auto opcode = Opcode::lookup(type);
        int len = 1;
        for (auto &width : oprands) {
            len += width;
        }
        
    }
}