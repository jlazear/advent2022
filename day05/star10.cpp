#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <array>
#include <vector>
#include <ctype.h>

typedef std::array<std::list<char> , 9> Deques;
typedef std::vector<std::array<int, 3>> Commands;

struct retval {
        Deques deques; 
        Commands commands;
        };

retval read_input(const std::string& fname) {
    std::ifstream f (fname);
    std::string line;
    Deques deques;
    Commands commands;

    while (std::getline(f, line)) {
        if (line.empty()) break;
        
        for (int i=0; i<9; i++) {
            char c {line.at(1 + i*4)};
            if (isalpha(c)) {
                deques[i].push_front(c);
            }
        }
    }

    while (std::getline(f, line)) {
        std::string junk;
        std::array<int, 3> mya;
        std::stringstream sline (line);
        
        sline >> junk >> mya[0] >> junk >> mya[1] >> junk >> mya[2];
        commands.push_back(mya);
    }

    return retval {deques, commands};
}

void execute_command(Deques& deques, std::array<int, 3> command) {
    int n {command[0]};
    int source {command[1] - 1};
    int dest {command[2] - 1};

    std::list<char> temp;

    for (int i=0; i<n; i++) {
        temp.push_front(deques[source].back());
        deques[source].pop_back();
    }
    for (int i=0; i<n; i++) {
        deques[dest].push_back(temp.front());
        temp.pop_front();
    }
}

void print_answer(const Deques& deques) {
    for (auto d : deques) {
        std::cout << d.back();
    }
}

int main() {
    auto retval = read_input("input.txt");
    Deques deques {retval.deques}; 
    Commands commands {retval.commands};

    std::cout << std::endl << std::endl;

    for (auto command : commands) {
        execute_command(deques, command);
    }

    print_answer(deques);
}