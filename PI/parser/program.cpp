#include <parser/Parser.h>

using namespace pi::parser;
using namespace pi::ast;


shared_ptr<Program> Parser::parseProgram() {
    std::shared_ptr<Program> s(new Program());
    while (!currentTokenIs(token::Token::TOKEN_EOF)) {
        auto  stmt = parseStatement();
        if (stmt) s->statements.push_back(stmt);
        nextToken();
    }
    return s;
}