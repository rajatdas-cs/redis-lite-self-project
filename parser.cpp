#include "parser.hpp"
#include <sstream>
std::vector<std::string> Parser::parse(const std::string& input) {
    std::istringstream iss(input);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token) tokens.push_back(token);
    return tokens;
}
