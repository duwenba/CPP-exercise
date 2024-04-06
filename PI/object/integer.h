//
// Created by 22753 on 2024/4/6.
//

#ifndef PI_INTEGER_H
#define PI_INTEGER_H

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

#endif //PI_INTEGER_H
