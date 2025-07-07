#include "repl.hpp"
#include <iostream>
void REPL::run() {
    Parser parser;
    CommandExecutor executor;
    std::string input;
    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, input)) break;
        auto tokens = parser.parse(input);
        if (tokens.empty()) continue;
        std::string output = executor.execute(tokens);
        if (!output.empty()) std::cout << output << std::endl;
    }
}