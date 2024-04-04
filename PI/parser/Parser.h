//
// Created by 22753 on 2024/4/4.
//

#ifndef PI_PARSER_H
#define PI_PARSER_H

#include <memory>
#include <list>
#include <lexer/lexer.h>


namespace pi::parser {

        class Parser {
        public:
            enum Precedence {
                LOWEST,
                EQUALS,      // ==
                LESSGREATER, // > or <
                SUM,         // + or -
                PRODUCT,     // * or /
                PREFIX,      // -X or !X
                CALL,        // myFunction(X)
            };

            Parser() = default;
            Parser(const std::shared_ptr<lexer::Lexer> &lexer);
            ~Parser() = default;

            void nextToken();
            bool currentTokenIs(Token::Type type) const;
            bool peekTokenIs(Token::Type type) const;
            bool expectPeek(Token::Type type);
            void peekError(Token::Type type);
            int  currentPrecedence() ;
            int  peekPrecedence() ;


        private:
            std::shared_ptr<lexer::Lexer> lexer;
            Token currentToken;
            Token peekToken;
            static std::map<Token::Type, int> precedences;
            std::list<string> errors;

        };// Parser

    } // Parser
// pi

#endif //PI_PARSER_H
