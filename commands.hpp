#ifndef COMMANDS_HPP
#define COMMANDS_HPP
#include <string>
#include <vector>
#include "database.hpp"
class CommandExecutor {
    Database db;
public:
    std::string execute(const std::vector<std::string>& tokens);
};
#endif