#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

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

int find_infimum(std::vector<int> sizes, const int& threshold) {
    int smallest = *std::max_element(sizes.begin(), sizes.end());

    for (const auto& x : sizes) {
        if (x >= threshold && x < smallest) {
            smallest = x;
        }
    }
    return smallest;
}

int main() {
    std::vector<int> sizes = parse_lines("input.txt");

    int total_disk_size = 70000000;
    int size_needed_for_update = 30000000;
    int max_allowed = total_disk_size - size_needed_for_update;

    int min_to_delete = *std::max_element(sizes.begin(), sizes.end()) - max_allowed;
    std::cout << "min_to_delete = " << min_to_delete << std::endl;

    int sum = find_infimum(sizes, min_to_delete);
    std::cout << "smallest = " << sum << std::endl;
}