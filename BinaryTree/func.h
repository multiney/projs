#ifndef BT_FUNCTION
#define BT_FUNCTION

#include "BT.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

TreeNode* CreateTreeByLevel(const vector<int>&);

// TODO: how to do it?
TreeNode* CreateTreeByPre(const vector<int>&);

vector<vector<int>> createTreeVecs();

vector<TreeNode*> createTreesByLevel();


// LeetCode
bool isBalanced(TreeNode*);
// 没看
bool isBalancedIter(TreeNode*);

vector<string> binaryTreePaths(TreeNode*);
vector<string> binaryTreePaths2(TreeNode*);

#endif // !BT_FUNCTION
