#include <fstream>
#include <string>
#include <iostream>
#include <cctype>
#include <array>

int score(char c) {
    return std::islower(c) ? 1 + c - 'a' : 27 + c - 'A';
}

char find_badge(std::array<std::string, 3> lines) {
    for (auto c : lines[0]) {
        if (lines[1].find(c) != std::string::npos && lines[2].find(c) != std::string::npos) {
            return c;
        }
    }
    return '\0';
}

int main() {
    std::ifstream f {"input.txt"};
    std::string line, left, right;
    std::array<std::string, 3> lines;
    
    int total {0};
    int i {0};
    while (std::getline(f, line)) {
        lines[i++] = line;
        if (i == 3) {
            i = 0;
            total += score(find_badge(lines));
        }
    }

    std::cout << "total = " << total << std::endl;
}