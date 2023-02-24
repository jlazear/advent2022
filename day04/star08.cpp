#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <list>
#include <array>

std::list<std::array<int, 4>> parse_input(const std::string& fname) {
    std::ifstream f (fname); 
    std::string line;
    std::list<std::array<int, 4>> mylist;
    std::array<int, 4> mya;

    while (std::getline(f, line)) {
        char d;
        std::stringstream sline (line);
        sline >> mya[0] >> d >> mya[1] >> d >> mya[2] >> d >> mya[3];
        mylist.push_back(mya);
    }
    return mylist;
}

bool check_pair(std::array<int, 4> mya) {
    return (mya[0] <= mya[2] && mya[2] <= mya[1]) || (mya[2] <= mya[0] && mya[0] <= mya[3]);
}

int main()
{
    std::list<std::array<int, 4>> mylist = parse_input("input.txt");

    int n = 0;
    for (auto mya : mylist) {
        if (check_pair(mya)) {
            n++;
        }
    }

    std::cout << "n = " << n << '\n';
    return 0;
}
