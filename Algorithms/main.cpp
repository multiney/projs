#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <numeric>

void countInt()
{
    std::vector<int> ivec{1, 2, 3, 4, 4, 4, 5};
    std::cout << count(ivec.begin(), ivec.end(), 4) << std::endl;
}

void countStr()
{
    std::list<std::string> lst{"a", "b", "b", "c"};
    std::cout << count(lst.begin(), lst.end(), "b") << std::endl;
}

void accumulateTest()
{
    std::vector<double> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << accumulate(ivec.begin(), ivec.end(), 0) << std::endl;
}

void equalTest()
{
    char c1[4] = "sab";
    char c2[4] = "vng";
    std::vector<char*> roster1{c1};
    std::vector<char*> roster2{c2};
    std::cout << equal(roster1.cbegin(), roster1.cend(), roster2.cbegin()) << std::endl;
    std::string str1("str");
    std::string str2("str");
    std::cout << equal(str1.cbegin(), str1.cend(), str2.cbegin());
}

int main()
{
    countInt();
    countStr();
    accumulateTest();
    equalTest();
}
