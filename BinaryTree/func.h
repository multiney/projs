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
vector<TreeNode*> createTreesByLevel(const vector<vector<int>>&);

vector<vector<int>> readFileToVec(string);

/**
  * 144. Binary Tree Preorder Traversal
  */ 
vector<int> preorderTraversal(TreeNode*);
vector<int> preorderTraversalStk(TreeNode*);

// LeetCode
bool isBalanced(TreeNode*);
// 没看
bool isBalancedIter(TreeNode*);

/**
  * 257. binary tree paths
  */
vector<string> binaryTreePaths(TreeNode*);
vector<string> binaryTreePaths2(TreeNode*);
vector<string> binaryTreePathsStk(TreeNode*);

/**
  * 100. same tree
  */ 
bool isSameTree(TreeNode*, TreeNode*);
bool isSameTreeIter(TreeNode*, TreeNode*);

/**
  * 104. maximum depth of binary tree
  */ 
int maxDepth(TreeNode*);
int maxDepthPre(TreeNode*);
int maxDepthLevel(TreeNode*);

/**
  * 404. Sum of Left Leaves
  */ 
int sumOfLeftLeaves(TreeNode*);
int sumOfLeftLeavesStk(TreeNode*);

/**
  * 513. Find Bottom Left Tree value
  */ 
int findBottomLeftValue(TreeNode*);
int findBottomLeftValueQue(TreeNode*);

/**
  * 112. Path sum 
  */ 
bool hasPathSum(TreeNode*, int); 
bool hasPathSumStk(TreeNode*, int);

/**
  * 113. Path Sum II
  */ 
vector<vector<int>> pathSum(TreeNode*, int);
// TODO: iteration version
#endif // !BT_FUNCTION
