#include <parser/Parser.h>

using namespace pi::parser;
using namespace pi::ast;


shared_ptr<Expression> Parser::parseGroup() {
    nextToken();
    auto e = parseExpression(LOWEST);
    if (!expectPeek(token::Token::TOKEN_RPAREN)){
        return nullptr;
    }
    return e;
}
