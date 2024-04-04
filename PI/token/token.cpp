//
// Created by 22753 on 2024/4/4.
//

#include <token/token.h>
#include <map>
using namespace pi::token;


std::map<Token::Type, string> Token::m_name = {
        {TOKEN_ILLEGAL,    "ILLEGAL"   },
        {TOKEN_EOF,        "EOF"       },
        {TOKEN_INTEGER,    "integer"   },
        {TOKEN_ASSIGN,     "="         },
        {TOKEN_MINUS,      "-"         },
        {TOKEN_PLUS,       "+"         },
        {TOKEN_BANG,       "!"         },
        {TOKEN_ASTERISK,   "*"         },
        {TOKEN_SLASH,      "/"         },
        {TOKEN_LT,         "<"         },
        {TOKEN_GT,         ">"         },
        {TOKEN_EQ,         "=="        },
        {TOKEN_NOT_EQ,     "!="        },
        {TOKEN_SEMICOLON,  ";"         },
        {TOKEN_COMMA,      ","         },
        {TOKEN_LPAREN,     "("         },
        {TOKEN_RPAREN,     ")"         },
    };

Token::Token() : m_type(Token::Type::TOKEN_ILLEGAL)
{
    m_literal = "";
}

Token::Token(Token::Type type, string &literal) : m_type(type), m_literal(literal)
{
}

Token::Type Token::type() const {
    return m_type;
}

string Token::name() const {
    auto it = m_name.find(m_type);
    if (it != m_name.end()) {
        return it->second;
    }
    return "";
}

string Token::literal() const {
    return m_literal;
}

Token& Token::operator=(const Token &token) {
    if (this != &token) {
        m_type = token.m_type;
        m_literal = token.m_literal;
        return *this;
    }
    return *this;
}

void Token::show() const {
    printf("type: %s,\t literal: %s\n",name().c_str(), literal().c_str());
}

json::value Token::to_json() const {
    json::value j;
    j["name"] = name();
    j["literal"] = literal();
    return j;
}
