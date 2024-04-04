//#include <cstdio>
#include <lexer/lexer.h>
#include <configor/json.hpp>
#include <fstream>

using namespace configor;
using namespace pi::lexer;


int main () {
    auto lexer = Lexer("./../code.pi");
    json::value tokens;
    while (true)   {
        auto token = lexer.nextToken();
        token.show();
        tokens.push_back(token.to_json());
        if (token.type() == Token::TOKEN_EOF) break;
    }
    json::value root;
    root["tokens"] = tokens;

    std::ofstream ofs("./../tokens.json");
    ofs << json::dump(root);
    ofs.close();
//    json::value j = ;

//    delete lexer;
}

