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
    while (expectPeek(token::Token::TOKEN_SEMICOLON)){
        nextToken();
    }
    return s;
}

shared_ptr<Program> Parser::parseProgram() {
    std::shared_ptr<Program> s(new Program());
    while (!currentTokenIs(token::Token::TOKEN_EOF)) {
        auto  stmt = parseStatement();
        if (stmt) s->statements.push_back(stmt);
        nextToken();
    }
    return s;
}