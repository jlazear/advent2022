#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::vector<int> parse_lines(std::string&& fname) {
    std::string line;
    std::ifstream f (fname);
    std::vector<int> sizes {};
    std::vector<int> stack {};

    while (std::getline(f, line)) {
        if (line.substr(0, 7) == "$ cd ..") {
            stack.pop_back();
        } else if (line.substr(0, 4) == "$ cd") {
            stack.push_back(sizes.size());
            sizes.push_back(0);
        } else if (std::isdigit(line.at(0))) {
            int fsize;
            std::stringstream(line) >> fsize;
            for (int i=0; i<stack.size(); i++) {
                sizes[stack[i]] += fsize;
            }
        }
    }
    return sizes;
}

int sum_small(std::vector<int> sizes, const int& threshold) {
    int sum = 0;
    for (const auto& x : sizes) {
        if (x <= threshold) {
            sum += x;
        }
    }
    return sum;
}

int main() {
    std::vector<int> sizes = parse_lines("input.txt");

    int sum = sum_small(sizes, 100000);
    std::cout << "sum = " << sum << std::endl;
}