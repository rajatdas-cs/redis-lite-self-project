#include "database.hpp"
#include <chrono>
void Database::cleanup() {
    auto now = std::chrono::steady_clock::now();
    for (auto it = expiry.begin(); it != expiry.end();) {
        if (now > it->second) {
            store.erase(it->first);
            it = expiry.erase(it);
        } else {
            ++it;
        }
    }
}
void Database::set(const std::string& key, const std::string& value) {
    cleanup();
    store[key] = value;
}
std::string Database::get(const std::string& key) {
    cleanup();
    if (store.count(key)) return store[key];
    return "(nil)";
}
void Database::del(const std::string& key) {
    cleanup();
    store.erase(key);
    expiry.erase(key);
}
void Database::expire(const std::string& key, int seconds) {
    if (store.count(key)) {
        expiry[key] = std::chrono::steady_clock::now() + std::chrono::seconds(seconds);
    }
}
