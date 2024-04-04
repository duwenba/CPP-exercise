#include <parser/Parser.h>

using namespace pi::parser;
using namespace pi::ast;


shared_ptr<Expression> Parser::parseExpression(int precedence) {
    auto prefix = prefixParseFns.find(currentToken.type());
    if (prefix == prefixParseFns.end()) {
        addError("no prefix parse function for " + currentToken.literal());
        return  nullptr;
    }
    std::shared_ptr<Expression> e = (this->*(prefix->second))();

    while (precedence < peekPrecedence() && !peekTokenIs(token::Token::TOKEN_SEMICOLON)){
        auto infix = infixParseFns.find(currentToken.type());
        if (infix == infixParseFns.end()) {
            addError("no infix parse function for " + currentToken.literal());
            return nullptr;
        }
        nextToken();
        e = (this->*(infix->second))(e);
    }
    return e;
}
