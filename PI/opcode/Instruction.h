//
// Created by 22753 on 2024/4/7.
//

#pragma once
#include "opcode.h"

namespace pi::opcode {

    class Instruction {
    public:
        Instruction() = default;
        ~Instruction() = default;

        bool make(Opcode::Type type,const std::vector<int>& oprands = {});

    private:

    };

}
