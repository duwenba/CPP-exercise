//
// Created by 22753 on 2024/4/6.
//

#pragma once


#include <map>
#include <string>
#include <memory>

using std::shared_ptr;
using std::string;
using std::map;


namespace pi::obj {

    class Object {
    public:
        enum Type {
            OBJ_ERROR = 0,
            OBJ_INTEGER,
            OBJ_BOOLEAN,
            OBJ_NULL,
            OBJ_RETURN,
            OBJ_FUNCTION,
            OBJ_STRING,
            OBJ_ARRAY,
            OBJ_HASH,
            OBJ_MODULE,
            OBJ_STRUCT,
            OBJ_CLASS,
            OBJ_INSTANCE,
            OBJ_RANGE,
            OBJ_METHOD,
        };

        Object() = default;

        Object(Type type) : type(type) {};

        virtual ~Object() = default;

        Type getType() { return type; }

        string getTypeName();

        virtual string toString() const = 0;

        static shared_ptr<Object> newError(const char *format, ...);

        static shared_ptr<Object> newInteger(int64_t value);

    protected:
        Type type;
        static map<Type, string> type_name;
    };

} // obj
// pi

