//
// Created by 22753 on 2024/4/6.
//

#pragma once


#include <object/object.h>

namespace pi::obj {

    class Integer : public Object {
    public:
        Integer() : Object(OBJ_INTEGER) {};
        explicit Integer(int64_t value) : Object(OBJ_INTEGER), value(value) {};

        string toString() const override {
            return std::to_string(value);
        }


    public:
        int64_t value = 0;
    };

} // obj
// pi


