#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    std::ifstream f ("input.txt");
    std::string line;
    std::array<int, 3> max_calories {0, 0, 0};
    int calories {0};
    int running {0};
    while (std::getline(f, line)) {
        if (line[0] == '\r' || line[0] == '\n') {
            auto ptr = std::min_element(max_calories.begin(), max_calories.end());
            *ptr = std::max(*ptr, running);
            running = 0;
        } else {
            std::stringstream ss {line};
            ss >> calories;
            running += calories;
        };
    }

    int total {0};
    for (auto x : max_calories) {
        total += x;
    }
    std::cout << "total = " << total << '\n';
}
