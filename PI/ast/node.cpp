//
// Created by 22753 on 2024/4/4.
//

#include <ast/node.h>
using namespace pi::ast;

// Type to string
std::map<Node::Type, string> Node::type_name ={
        {INTEGER,               "Integer"               },
        {INFIX,                 "Infix"                 },
        {PREFIX,                "Prefix"                },
        {POSTFIX,               "Postfix"               },
        {EXPRESSION,            "Expression"            },
        {STATEMENT,             "Statement"             },
        {EXPRESSION_STATEMENT,  "ExpressionStatement"   },
        {BLOCK,                 "Block"                 },
        {PROGRAM,               "Program"               },
        {FUNCTION_DECLARATION,  "FunctionDeclaration"   },
        {FUNCTION_LITERAL,      "FunctionLiteral"       },
        {FUNCTION_PARAMETER,    "FunctionParameter"     },
        {FUNCTION_CALL,         "FunctionCall"          },
        {IDENTIFIER,            "Identifier"            },
        {LET_STATEMENT,         "LetStatement"          },
        {RETURN_STATEMENT,      "ReturnStatement"       },
        {STRING,                "String"                },
};

string Node::name() const {
    auto it = type_name.find(type);
    if (it != type_name.end()) {
        return it->second;
    }
    return "Unknown";
}
