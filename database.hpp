#ifndef DATABASE_HPP
#define DATABASE_HPP
#include <string>
#include <unordered_map>
#include <chrono>
class Database {
    std::unordered_map<std::string, std::string> store;
    std::unordered_map<std::string, std::chrono::steady_clock::time_point> expiry;
    void cleanup();
public:
    void set(const std::string& key, const std::string& value);
    std::string get(const std::string& key);
    void del(const std::string& key);
    void expire(const std::string& key, int seconds);
};
#endif