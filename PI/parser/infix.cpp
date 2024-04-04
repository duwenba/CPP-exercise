#include <parser/Parser.h>

using namespace pi::parser;
using namespace pi::ast;

shared_ptr<Expression> Parser::parseInfix(shared_ptr<ast::Expression> & left) {
    std::shared_ptr<infix> e(new infix());
    e->left = left;
    e->mOperator = currentToken.literal();
    int precedence = currentPrecedence();
    nextToken();
    e->right = parseExpression(precedence);
    return e;
}
