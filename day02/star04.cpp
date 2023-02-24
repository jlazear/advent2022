#include <fstream>
#include <string>
#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> game_score {{"A X", 3}, {"A Y", 1}, {"A Z", 2},
                                           {"B X", 1}, {"B Y", 2}, {"B Z", 3},
                                           {"C X", 2}, {"C Y", 3}, {"C Z", 1}};

    std::map<char, int> play_score {{'X', 0}, {'Y', 3}, {'Z', 6}};

    int total = 0;
    std::ifstream f {"input.txt"};
    std::string line;
    while (std::getline(f, line)) {
        total += game_score[line] + play_score[line[2]];
    }

    std::cout << "total = " << total << std::endl;
}
