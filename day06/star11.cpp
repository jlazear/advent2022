#include <fstream>
#include <iostream>
#include <string>
#include <set>

bool check(std::string& line, const int left, const int seq_len=4) {
    std::string sub {line.substr(left, seq_len)};
    std::set<char> s {sub.begin(), sub.end()};
    
    return (s.size() == seq_len);
}

int find_sequence(std::string& line, const int seq_len=4) {
    int left = 0;
    while (!check(line, left, seq_len)) {
        left++;
    }
    return left + seq_len;
}

int main() {
    std::ifstream f ("input.txt");
    std::string line;

    f >> line;

    std::cout << find_sequence(line) << std::endl;;
}