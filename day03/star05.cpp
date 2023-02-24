#include <fstream>
#include <string>
#include <iostream>
#include <cctype>

int score(char c) {
    return std::islower(c) ? 1 + c - 'a' : 27 + c - 'A';
}

int main() {
    std::ifstream f {"input.txt"};
    std::string line, left, right;
    
    int total {0};
    while (std::getline(f, line)) {
        left = line.substr(0, line.length()/2);
        right = line.substr(line.length()/2);
        for (auto c : left) {
            if (right.find(c) != std::string::npos) {
                total += score(c);
                break;
            }
        }
    }

    std::cout << "total = " << total << std::endl;
}