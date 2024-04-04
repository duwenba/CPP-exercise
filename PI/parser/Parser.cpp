//
// Created by 22753 on 2024/4/4.
//

#include <parser/Parser.h>

using namespace pi::parser;

std::map<Token::Type, int> Parser::precedences = {
        {Token::TOKEN_INTEGER,LOWEST},
        {Token::TOKEN_PLUS,SUM},
        {Token::TOKEN_MINUS,SUM},
        {Token::TOKEN_ASTERISK,PRODUCT},
        {Token::TOKEN_SLASH,PRODUCT},
/*      {Token::TOKEN_BANG,},
*        {Token::TOKEN_ASSIGN,},
*        {Token::TOKEN_EQ,},
*        {Token::TOKEN_NOT_EQ,},
*        {Token::TOKEN_LT,},
*        {Token::TOKEN_GT,},
*        {Token::TOKEN_COMMA,},
*        {Token::TOKEN_SEMICOLON,},
*        {Token::TOKEN_LPAREN,},
*        {Token::TOKEN_RPAREN,},
*/
};


std::map<Token::Type, Parser::prefixFn > Parser::prefixParseFns = {
        {Token::TOKEN_INTEGER,     &Parser::parseInteger},
        {Token::TOKEN_LPAREN,      &Parser::parseGroup},

};

std::map<Token::Type, Parser::infixFn > Parser::infixParseFns = {
        {Token::TOKEN_PLUS,         &Parser::parseInfix},
        {Token::TOKEN_MINUS,        &Parser::parseInfix},
        {Token::TOKEN_ASTERISK,     &Parser::parseInfix},
        {Token::TOKEN_SLASH,        &Parser::parseInfix},
};

Parser::Parser(const std::shared_ptr<lexer::Lexer> &lexer) : lexer(lexer) {
    nextToken();
    nextToken();

}

void Parser::nextToken() {
    currentToken = peekToken;
    peekToken = lexer->nextToken();
}

bool Parser::currentTokenIs(Token::Type type) const {
    return currentToken.type() == type;
}

bool Parser::peekTokenIs(Token::Type type) const {
    return peekToken.type() == type;
}

bool Parser::expectPeek(Token::Type type) {
    if (peekTokenIs(type)) {
        nextToken();
        return true;
    }
    peekError(type);
    return false;
}

void Parser::peekError(Token::Type type) {
    std::ostringstream msg;
    msg << "expected next token to be " << type << ", got " << peekToken.type() << " instead";
    //add to errors
    errors.push_back(msg.str());
}

int Parser::currentPrecedence() {
    auto it = precedences.find(currentToken.type());
    if (it != precedences.end()) {
        return it->second;
    }
    return LOWEST;
}

int Parser::peekPrecedence() {
    auto it = precedences.find(peekToken.type());
    if (it != precedences.end()) {
        return it->second;
    }
    return LOWEST;
}

void Parser::addError(const string &msg) {
    //add to errors
    errors.push_back(msg);
}







