#ifndef BT_FUNCTION
#define BT_FUNCTION

#include "BT.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

// total method
void writeAllOrdersVVI(string folderPath); 

TreeNode* CreateTreeByLevel(const vector<int>&);

// TODO: how to do it?
TreeNode* CreateTreeByPre(const vector<int>&);

/**
  * create a vector of a vector of tree node value;
  * and specify the levelorder for value;
  * it is used to create trees by `CreateTreeByLevel` function
  */ 
// basic method, created by random int
vector<vector<int>> createTreeVecs();
vector<vector<int>> createTreeVecsUnique();

/**
  * create a vector of a vector of tree node value;
  * created by vector<TreeNode*>
  */ 
vector<vector<int>> createTreeVecsPreorder(const vector<TreeNode*>&);
vector<vector<int>> createTreeVecsInorder(const vector<TreeNode*>&);
vector<vector<int>> createTreeVecsPostorder(const vector<TreeNode*>&);

vector<TreeNode*> createTreesByLevel();
vector<TreeNode*> createTreesByLevel(const vector<vector<int>>&);

vector<vector<int>> readFileToVec(string);

/**
  * write level/pre/in/post order trees to the specific file
  */ 
// basic write method
void writeTreeVec(const vector<vector<int>>&, string);

/**
  * 144. Binary Tree Preorder Traversal
  */ 
vector<int> preorderTraversal(TreeNode*);
vector<int> preorderTraversalStk(TreeNode*);

/**
  * 94. Binary Tree Inorder Traversal
  */ 
vector<int> inorderTraversal(TreeNode*);

/**
  * 145. Binary Tree Postorder Traversal
  */ 
vector<int> postorderTraversal(TreeNode*);

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

/**
  * 106. Construct Binary Tree from Inorder and Postorder Traversal
  */ 
TreeNode* buildTreeInPost(const vector<int>&, const vector<int>&); 

/**
  * 105. Construct Binary Tree from Preorder and Inorder Traversal
  */ 
TreeNode* buildTreePreIn(const vector<int>&, const vector<int>&);

/**
  * 654. Maximuum Binary Tree
  */ 
TreeNode* constructMaximumBinaryTree(const vector<int>&);
#endif // !BT_FUNCTION
