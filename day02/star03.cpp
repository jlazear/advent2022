#include <fstream>
#include <string>
#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> game_score {{"A X", 3}, {"A Y", 6}, {"A Z", 0},
                                           {"B X", 0}, {"B Y", 3}, {"B Z", 6},
                                           {"C X", 6}, {"C Y", 0}, {"C Z", 3}};

    std::map<char, int> play_score {{'X', 1}, {'Y', 2}, {'Z', 3}};

    int total = 0;
    std::ifstream f {"input.txt"};
    std::string line;
    while (std::getline(f, line)) {
        total += game_score[line] + play_score[line[2]];
    }

    std::cout << "total = " << total << std::endl;
}
