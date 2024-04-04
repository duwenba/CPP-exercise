//
// Created by 22753 on 2024/4/4.
//

#ifndef PI_PARSER_H
#define PI_PARSER_H

#include <memory>
#include <list>
#include <lexer/lexer.h>
#include <ast/header.h>


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

            //前缀表达式构建函数原型
            typedef std::shared_ptr<ast::Expression> (Parser:: * prefixFn)();
            //中缀表达式构建函数原型
            typedef std::shared_ptr<ast::Expression> (Parser:: * infixFn)(std::shared_ptr<ast::Expression> &);

            void nextToken();
            bool currentTokenIs(Token::Type type) const;
            bool peekTokenIs(Token::Type type) const;
            bool expectPeek(Token::Type type);
            void peekError(Token::Type type);
            void addError(const string &msg);
            int  currentPrecedence();
            int  peekPrecedence() ;
            //prefix
            std::shared_ptr<ast::Expression> parseInteger();
            std::shared_ptr<ast::Expression> parseGroup();
            std::shared_ptr<ast::Expression> parseExpression(int);
            std::shared_ptr<ast::Expression> parseInfix(std::shared_ptr<ast::Expression> & left);

            std::shared_ptr<ast::Program> parseProgram();

            //parserStatement
            std::shared_ptr<ast::Statement> parseStatement();
            std::shared_ptr<ast::ExpressionStatement> parseExpressionStatement();



        private:
            std::shared_ptr<lexer::Lexer> lexer;
            Token currentToken;
            Token peekToken;
            std::list<string> errors;
            static std::map<Token::Type, prefixFn> prefixParseFns;
            static std::map<Token::Type, infixFn> infixParseFns;
            static std::map<Token::Type, int> precedences;

        };// Parser

    } // Parser
// pi

#endif //PI_PARSER_H
