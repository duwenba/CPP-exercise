//
// Created by 22753 on 2024/4/4.
//

#ifndef PI_LEXER_H
#define PI_LEXER_H

//#define DEBUG true

#include <token/token.h>
#include <string>
using std::string;
using namespace pi::token;

namespace pi {

    namespace lexer {
        class Lexer {
        public:
            Lexer() = default;
            Lexer(const string & file);
            ~Lexer() = default;

            Token nextToken();

        private:
            void    skipWhitespace();
            void    readChar();
            void    unreadChar();
            string  readNumber();
            bool    isDigit(char c);
        public:
            Token   newToken(Token::Type type, string & literal);

        private:
            string  source;
            int     pos;
            int     next_pos;
            char    ch;

        };
    }
}


#endif //PI_LEXER_H
