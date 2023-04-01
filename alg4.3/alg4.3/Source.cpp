#include <iostream>
#include <unordered_map>

void countChars(const std::string& str) {
    std::unordered_map<char, int> charCounts;

    for (char c : str) {
        auto it = charCounts.find(c);
        if (it == charCounts.end()) {
            charCounts[c] = 1;
        }
        else {
            ++it->second;
        }
    }

    for (const auto& kv : charCounts) {
        std::cout << kv.first << ": " << kv.second << '\n';
    }
}

int main() {
    std::string inputStr = "hello mirea";
    countChars(inputStr);
    return 0;
}