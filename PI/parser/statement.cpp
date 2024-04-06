#include <parser/Parser.h>

using namespace pi::parser;
using namespace pi::ast;

std::shared_ptr<Statement> Parser::parseStatement() {
    return parseExpressionStatement();
}

std::shared_ptr<ExpressionStatement> Parser::parseExpressionStatement() {
    std::shared_ptr<ExpressionStatement> s(new ExpressionStatement());
    s->expression = parseExpression(LOWEST);
    s->token = currentToken;
    //fixed a bug
    while (peekTokenIs(token::Token::TOKEN_SEMICOLON)){
        nextToken();
    }
    return s;
}