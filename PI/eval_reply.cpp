#include <evaluator/evaluator.h>
#include <lexer/lexer.h>
#include <parser/parser.h>

using namespace pi::parser;
using namespace pi::lexer;
using namespace pi::eval;

const string prompt = "<< ";
const string welcome = "Welcome to the Pi Programing  Language!\n";

int main(int argc, char **argv) {
    std::cout << welcome << std::endl;

    Evaluator evaluator;
    while (true) {
        std::cout << prompt;
        std::string line;
        std::getline(std::cin, line);
        if (line == "exit") {
            break;
        }


        shared_ptr<Lexer> lexer(new Lexer(line.c_str(), line.size()));
        shared_ptr<Parser> parser(new Parser(lexer));
        shared_ptr<Node> program = parser->parseProgram();
        auto errors = parser->getErrors();
        if (!errors.empty()) {
            for (auto &error: errors) {
                std::cout << error << std::endl;
            }
            continue;
        }

        auto evaluated = evaluator.eval(program);
        if (evaluated) {
            std::cout<< "=" << evaluated->toString() << std::endl;
        }
    }

    return 0;
}