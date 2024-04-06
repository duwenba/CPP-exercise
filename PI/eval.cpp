#include <evaluator/evaluator.h>
#include <lexer/lexer.h>
#include <parser/parser.h>

using namespace pi::parser;
using namespace pi::lexer;
using namespace pi::eval;




int main(int argc, char** argv) {
    shared_ptr<Lexer> lexer(new Lexer("./../code.pi"));
    shared_ptr<Parser> parser(new Parser(lexer));
    shared_ptr<Node> program = parser->parseProgram();
    auto errors = parser->getErrors();
    if(!errors.empty()){
        for (auto& error : errors) {
            std::cout << error << std::endl;
        }
        return -1;
    }
    Evaluator evaluator;
    auto evaluated = evaluator.eval(program);
    if (evaluated) {
        std::cout << "return " << evaluated->toString() << std::endl;
    }
}