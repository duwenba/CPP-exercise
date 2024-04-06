//
// Created by 22753 on 2024/4/6.
//

#include <object/header.h>

#include <memory>
#include <cstdarg>

using namespace pi::obj;

map<Object::Type, string> Object::type_name = {
        {OBJ_ERROR,         "error"     },
        {OBJ_INTEGER,       "integer"   },
        {OBJ_BOOLEAN,       "boolean"   },
        {OBJ_NULL,          "null"      },
        {OBJ_RETURN,        "return"    },
        {OBJ_FUNCTION,      "function"  },
        {OBJ_STRING,        "string"    },
        {OBJ_ARRAY,         "array"     },
        {OBJ_HASH,          "hash"      },
        {OBJ_MODULE,        "module"    },
        {OBJ_STRUCT,        "struct"    },
        {OBJ_CLASS,         "class"     },
        {OBJ_INSTANCE,      "instance"  },
        {OBJ_RANGE,         "range"     },
        {OBJ_METHOD,        "method"    },
};

string Object::getTypeName() {
    auto it = type_name.find(type);
    if (it != type_name.end()) {
        return it->second;
    }
    return "unknown";
}

shared_ptr<Object> Object::newInteger(int64_t value) {
    return std::make_shared<obj::Integer>( value );
}

shared_ptr<Object> Object::newError(const char *format, ...) {
    char buffer[1024] = {0};
    va_list args;
    va_start(args, format);
    int len = vsnprintf(buffer,sizeof(buffer),format, args);
    va_end(args);

    return std::make_shared<Error>(string(buffer, len));
}




