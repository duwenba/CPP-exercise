//
// Created by 22753 on 2024/4/4.
//

#include <lexer/lexer.h>
#include <fstream>
#include <sstream>
#include <cstdio>

using namespace pi::lexer;


void Lexer::skipWhitespace() {
    //log

    while (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
        readChar();
    }

}

void Lexer::readChar() {


    if (pos >= source.length()) {
        ch = 0;
    } else {
        ch = source[next_pos];
        pos = next_pos;
        next_pos++;
    }
}

void Lexer::unreadChar() {
    next_pos = pos;
    pos--;
    ch = source[pos];
}

string Lexer::readNumber() {

    int p = pos;
    while (isDigit(ch)) {
        readChar();
    }
    return source.substr(p, pos - p);
}

bool Lexer::isDigit(char c) {

    return (c >= '0' && c <= '9');
}

Token Lexer::newToken(Token::Type type, string &literal) {

    Token token = Token(type, literal);
    return token;
}


Lexer::Lexer(const string &file) {

    ch = 0;
    pos = 0;
    next_pos = 0;

    std::ifstream ifs(file);
    if (ifs.is_open()) {
        std::ostringstream str;
        str << ifs.rdbuf();
        source = str.str();
        ifs.close();
    }

}

Token Lexer::nextToken() {

    readChar();
    skipWhitespace();
    switch (ch) {
        case '=': {
            string token_str;
            token_str += ch;
            if (next_pos < source.length() && source[next_pos] == '=') {
                readChar();
                token_str += ch;
                return newToken(Token::TOKEN_EQ, token_str);
            } else {
                return newToken(Token::TOKEN_ASSIGN, token_str);
            }
        }
        case '+': {
            string token_str;
            token_str += ch;
            return newToken(Token::TOKEN_PLUS, token_str);
        }
        case '-': {
            string token_str;
            token_str += ch;
            return newToken(Token::TOKEN_MINUS, token_str);
        }
        case '*': {
            string token_str;
            token_str += ch;
            return newToken(Token::TOKEN_ASTERISK, token_str);
        }
        case '/': {
            string token_str;
            token_str += ch;
            return newToken(Token::TOKEN_SLASH, token_str);
        }
        case '(': {
            string token_str;
            token_str += ch;
            return newToken(Token::TOKEN_LPAREN, token_str);
        }
        case ')': {
            string token_str;
            token_str += ch;
            return newToken(Token::TOKEN_RPAREN, token_str);
        }
        case ',': {
            string token_str;
            token_str += ch;
            return newToken(Token::TOKEN_COMMA, token_str);
        }
        case ';': {
            string token_str;
            token_str += ch;
            return newToken(Token::TOKEN_SEMICOLON, token_str);
        }
        case 0: {
            string token_str;
            token_str = "EOF";
            return newToken(Token::TOKEN_EOF, token_str);
        }
        default:
            if (isDigit(ch)) {
                string literal = readNumber();
                unreadChar(); // unread the last read digit
                return newToken(Token::TOKEN_INTEGER, literal);
            } else {
                string token_str;
                token_str += ch;
                return newToken(Token::TOKEN_ILLEGAL, token_str);
            }
    }
}


