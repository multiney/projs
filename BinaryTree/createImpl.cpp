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





/**
  * write trees to the specific file
  */
void writeTreeVec(const vector<vector<int>>& vvi, string filePath) {
    string strTrees;
    for (auto& v : vvi) {
        string strTree = "[";
        for (decltype(v.size()) i = 0; i < v.size() - 1; ++i) {
            strTree += std::to_string(v[i]);
            strTree += ",";
        }
        strTree += std::to_string(v[v.size() - 1]);
        strTree += "]\n";
        strTrees += strTree;
    }
    std::ofstream out(filePath);
    out << strTrees;
    out.close();
}


// TODO: these three creationg method can be encapasulated?
vector<vector<int>> createTreeVecsPreorder(const vector<TreeNode *>& trees) {
    vector<vector<int>> vvi;
    for (auto& tree : trees)
        vvi.push_back(preorderTraversal(tree));
    return vvi;
}

vector<vector<int>> createTreeVecsInorder(const vector<TreeNode*>& trees) {
    vector<vector<int>> vvi;
    for (auto& tree : trees)
        vvi.push_back(inorderTraversal(tree));
    return vvi;
}

vector<vector<int>> createTreeVecspostorder(const vector<TreeNode*>& trees) {
    vector<vector<int>> vvi;
    for (auto& tree : trees)
        vvi.push_back(postorderTraversal(tree));
    return vvi;
}

void writeAllOrdersVVI(string folderPath) {
    const vector<vector<int>>& levelVVI = createTreeVecsUnique(); // it is levelorder just because I can only created tree by level order(my bad)
    const vector<TreeNode*>& trees = createTreesByLevel(levelVVI);
    const auto& preVVI = createTreeVecsPreorder(trees);
    const auto& inVVI = createTreeVecsInorder(trees);
    const auto& postVVI = createTreeVecspostorder(trees);
    writeTreeVec(levelVVI, folderPath + "/levelorder.txt");
    writeTreeVec(preVVI, folderPath + "/preorder.txt");
    writeTreeVec(inVVI, folderPath + "/inorder.txt");
    writeTreeVec(postVVI, folderPath + "/postorder.txt");
}
