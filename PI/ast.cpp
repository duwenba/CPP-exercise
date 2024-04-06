//
// Created by 22753 on 2024/4/5.
//

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <configor/json.hpp>
#include <iostream>
#include <fstream>

using namespace pi::lexer;
using namespace pi::parser;
using namespace configor;

int main() {
    std::shared_ptr<Lexer> lexer(new Lexer("./../code.pi"));
    std::shared_ptr<Parser> parser(new Parser(lexer));
    auto program = parser->parseProgram();
    auto errors = parser->getErrors();
    if(!errors.empty()){
        for (auto& error : errors) {
            std::cout << error << std::endl;
        }
        return -1;
    }
    json::value j = program->toJson();
    std::ofstream ofs("./../ast.json") ;
    ofs << json::dump(j) << std::endl;
    ofs.close();
    return 0;
}