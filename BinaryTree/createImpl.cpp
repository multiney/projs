#include "func.h"

#include <fstream>

vector<int> strToVec(string line) {
    vector<int> ret;
    int nodeVal = 0;
    for (auto& c : line) { // when line include 0, it will be error
        if (c <= '9' && c >= '0') {
            nodeVal = nodeVal * 10 + c - '0';
        }
        else if (nodeVal){
            ret.push_back(nodeVal);
            nodeVal = 0;
        }
        else continue;
    }
    return ret;
}

vector<vector<int>> readFileToVec(string filePath) {
    vector<vector<int>> ret;
    std::ifstream in(filePath);
    
    string line;
    while (std::getline(in, line)) {
        const vector<int>& vec = strToVec(line);
        ret.push_back(vec);
    }
    return ret;
}
