#include "commands.hpp"
#include <algorithm>
#include <sstream>
std::string CommandExecutor::execute(const std::vector<std::string>& tokens) {
    if (tokens.empty()) return "";
    std::string cmd = tokens[0];
    std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::toupper);
    if (cmd == "SET" && tokens.size() >= 3) {
        db.set(tokens[1], tokens[2]);
        return "OK";
    } else if (cmd == "GET" && tokens.size() >= 2) {
        return db.get(tokens[1]);
    } else if (cmd == "DEL" && tokens.size() >= 2) {
        db.del(tokens[1]);
        return "OK";
    } else if (cmd == "EXPIRE" && tokens.size() == 3) {
        int seconds = std::stoi(tokens[2]);
        db.expire(tokens[1], seconds);
        return "OK";
    }
    return "(error) Unknown or malformed command";
}