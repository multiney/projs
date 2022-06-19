#include "PersonInfo.h"

#include <iostream>
#include <fstream>
#include <sstream>

bool valid(const std::string& str)
{
    return std::isdigit(str[0]);
}

std::string format(const std::string& str)
{
    return str.substr(0, 3) + "-" + str.substr(3, 4) + "-" + str.substr(7);
}

int main()
{
    std::ifstream ifs("/home/vikung/projects/PersonInfo/data.txt");
    if (!ifs) {
        std::cerr << "No data?!" << std::endl;
    }

    std::vector<PersonInfo> people;
    std::string line, word;
    std::istringstream record;
    while (getline(ifs, line)) {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    for (const auto& entry : people) {
        std::ostringstream formatted, badNums;
        for (const auto& nums : entry.phones) {
            if (!valid(nums))
                badNums << " " << nums;
            else
                formatted << " " << format(nums);
        }

        if (badNums.str().empty())
            std::cout << entry.name << formatted.str() << std::endl;
        else
            std::cerr << "input error: " << entry.name << " invalid number(s)"
                      << badNums.str() << std::endl;
    }
    return 0;
}
