#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

int main()
{
    std::ifstream f ("input.txt");
    std::string line;
    int max_calories {0};
    int calories {0};
    int running {0};
    while (std::getline(f, line)) {
        if (line[0] == '\r' || line[0] == '\n') {
            max_calories = std::max(max_calories, running);
            running = 0;
        } else {
            std::stringstream ss {line};
            ss >> calories;
            running += calories;
        };
    }

    std::cout << "total = " << max_calories << '\n';
}
