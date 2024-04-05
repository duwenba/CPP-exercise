//
// Created by 22753 on 2024/4/4.
//

#ifndef PI_NODE_H
#define PI_NODE_H

#include <token/token.h>
#include <string>
#include <map>
using std::string;
using namespace pi::token;

namespace pi {

    namespace ast  {

        class Node {
        public:
            // integer,infix,prefix,psotfix,expression,statement,expression_statement,block,program
            enum Type{
                INTEGER = 0,
                INFIX,
                PREFIX,
                POSTFIX,
                EXPRESSION,
                STATEMENT,
                EXPRESSION_STATEMENT,
                BLOCK,
                PROGRAM,
                FUNCTION_DECLARATION,
                FUNCTION_LITERAL,
                FUNCTION_PARAMETER,
                FUNCTION_CALL,
                IDENTIFIER,
                LET_STATEMENT,
                RETURN_STATEMENT,
                STRING,
            };


            Node() = default;
            Node(Type type): type(type) {};
            virtual ~Node() {};

            Type getType() const { return type; }
            string name() const;

            virtual json::value toJson() = 0 ;
        public:
            Type type;
            Token token;
            static std::map<Type, string> type_name;
        };

        class Expression : public Node {
        public:
            Expression() = default;
            Expression(Type type): Node(type) {};
            ~Expression() override = default;


        };

        class Statement : public Node {
        public:
            Statement() = default;
            Statement(Type type): Node(type) {};
            ~Statement() override = default;

        };
    }
}


#endif //PI_NODE_H
