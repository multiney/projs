#include "BT.h"
#include "func.h"

#include <iostream>
#include <chrono>
#include <fstream>

using std::cout;
using std::endl;

void compareRecIter() {
    const vector<TreeNode*>& vt = createTreesByLevel();
    double time1 = 0, time2 = 0;
    for (int i = 0; i < 10; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        for (auto& tree : vt)
            maxDepth(tree);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << "Time taken by recursion: "
             << duration.count() / 1000.0 << " miliseconds" << endl;
        time1 += duration.count() / 1000.0;

        auto start2 = std::chrono::high_resolution_clock::now();
        for (auto& tree : vt)
            maxDepthLevel(tree);
        auto stop2 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);
        cout << "Time taken by iteration: "
             << duration2.count() / 1000.0 << " miliseconds" << endl;
        time2 += duration2.count() / 1000.0;
    }

    cout << "recursion: "
         << time1 / 10 << " miliseconds" << endl;
    cout << "iteration: "
         << time2 / 10 << " miliseconds" << endl;
}

void compareMySoluOther() {
    const vector<TreeNode*>& vt = createTreesByLevel();
    double time1 = 0, time2 = 0;
    for (int i = 0; i < 10; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        for (auto& tree : vt)
            binaryTreePaths(tree);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << "Time taken by my own version1: "
             << duration.count() / 1000.0 << " miliseconds" << endl;
        time1 += duration.count() / 1000.0;

        auto start2 = std::chrono::high_resolution_clock::now();
        for (auto& tree : vt)
            binaryTreePaths2(tree);
        auto stop2 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);
        cout << "Time taken by other version: "
             << duration2.count() / 1000.0 << " miliseconds" << endl;
        time2 += duration2.count() / 1000.0;
    }

    cout << "my own version1: "
         << time1 / 10 << " miliseconds" << endl;
    cout << "other version: "
         << time2 / 10 << " miliseconds" << endl;
}

void justForTest() {
    // vector<int> vec = {1, 2, 3};
    // TreeNode* tree1 = CreateTreeByLevel(vec);
    // TreeNode* tree2 = CreateTreeByLevel(vec);

    const vector<TreeNode*>& vt = createTreesByLevel();
    for (auto& tree : vt) {
        int depth = maxDepthPre(tree);
        cout << depth << endl;
    }
}



void compareWithJava() {
    const vector<vector<int>>& vvi = createTreeVecs();
    string filePath = "/mnt/f/strTrees.txt";
    writeTreeVec(vvi, filePath);
    const vector<TreeNode*>& trees = createTreesByLevel(vvi);
    double totalTime = 0;
    for (int i = 0; i < 10; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        for (auto& tree : trees)
            pathSum(tree, 5000);
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start);
        totalTime += duration.count();
    }
    double averageTime = totalTime / 10;
    cout << averageTime
         << " milliseconds" << endl;
}

void compareWithJavaStatic() {
    string folderPath = "/mnt/f";
    const vector<vector<int>>& vvi = readFileToVec(folderPath + "/levelorder.txt");
    const vector<TreeNode*>& trees = createTreesByLevel(vvi);
    double totalTime = 0;
    for (int i = 0; i < 10; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        for (auto& tree : trees)
            pathSum(tree, 5000);
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start);
        totalTime += duration.count();
    }
    double averageTime = totalTime / 10;
    cout << averageTime
         << " milliseconds(static version)." << endl;
}

void cmpJavaOrderStatic() {
    string folderPath = "/mnt/f";
    const auto& levelVVI = readFileToVec(folderPath + "/levelorder.txt");
    const auto& preVVI = readFileToVec(folderPath + "/preorder.txt");
    const auto& inVVI = readFileToVec(folderPath + "/inorder.txt");
    const auto& postVVI = readFileToVec(folderPath + "/postorder.txt");
    
    double totalTime = 0;
    for (int i = 0; i < 10; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        // for (decltype(inVVI.size()) j = 0; j < inVVI.size(); ++j)
        //     buildTreePreIn(preVVI[j], inVVI[j]);
        for (auto& vi : levelVVI)
            constructMaximumBinaryTree(vi);
            
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        totalTime += duration.count();
    }
    double averageTime = totalTime / 10;
    cout << averageTime
         << " milliseconds." << endl;
}

int main()
{
    // writeAllOrdersVVI("/mnt/f");
    // compareWithJavaStatic();
    cmpJavaOrderStatic();
}
