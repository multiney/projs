#include "StrBlob.h"
#include <fstream>
#include <iostream>

void ex12_20()
{
    std::ifstream ifs("/home/vikung/projects/StrBlob/StrBlob.h");
    StrBlob blob;
    for (std::string line; getline(ifs, line);blob.push_back(line));
    for (StrBlobPtr pBeg(blob.begin()), pEnd(blob.end()); pBeg != pEnd; pBeg.incr())
        std::cout << pBeg.deref() << std::endl;
}

int main()
{
    ex12_20();
    return 0;
}
