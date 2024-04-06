#pragma once

#include <object/object.h>

#include <utility>

namespace pi::obj {
    class Error : public Object {
    public:
        Error() : Object(Object::Type::OBJ_ERROR) {};
        explicit Error(string message) : Object(Object::Type::OBJ_ERROR), message(std::move(message)) {};

        string toString() const override  {
            return "ERROR: " + message;
        }

    public:
        string message;
    };
}