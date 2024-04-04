//
// Created by 22753 on 2024/4/4.
//

#ifndef PI_TOKEN_H
#define PI_TOKEN_H


#include <string>
#include <map>
#include <configor/json.hpp>

using namespace configor;
using std::map;
using std::string;

namespace pi::token {
    class Token {
    public:
        enum Type {
            TOKEN_ILLEGAL = 0,  // 非法
            TOKEN_EOF,          // EOF
            TOKEN_INTEGER,      // 123
            TOKEN_PLUS,         // +
            TOKEN_MINUS,        // -
            TOKEN_ASTERISK,     // *
            TOKEN_SLASH,        // /
            TOKEN_BANG,         // !
            TOKEN_ASSIGN,       // =
            TOKEN_EQ,           // ==
            TOKEN_NOT_EQ,       // !=
            TOKEN_LT,           // <
            TOKEN_GT,           // >
            TOKEN_COMMA,        // ,
            TOKEN_SEMICOLON,    // ;
            TOKEN_LPAREN,       // (
            TOKEN_RPAREN,       // )
        };

        Token();

        Token(Type type, string &literal);

        ~Token() = default;

        Type type() const;

        string name() const;

        string literal() const;

        Token &operator=(const Token &token);

        void show() const;

        json::value to_json() const;

    private:
        Type m_type;
        string m_literal;
        static map<Type, string> m_name;
    };
}


#endif //PI_TOKEN_H
