#ifndef PARSER_HPP
#define PARSER_HPP
#include <vector>
#include <string>
class Parser {
public:
    std::vector<std::string> parse(const std::string& input);
};
#endif