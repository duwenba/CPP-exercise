#include <parser/Parser.h>

using namespace pi::parser;


std::shared_ptr<pi::ast::Expression> Parser::parseInteger() {
    std::shared_ptr<pi::ast::Integer> e(new pi::ast::Integer());
    e->token = currentToken;
    e->value = std::atol(currentToken.literal().c_str());
    return e;
}
