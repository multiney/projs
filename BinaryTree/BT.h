#ifndef BINARY_TREE
#define BINARY_TREE

#include <vector>

using std::vector;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    
    // traversal
    vector<int> preorderTraversal();
    vector<int> preorderTraversalStk();

    vector<int> inorderTraversal();

    vector<int> postorderTraversal();

    vector<int> inorderTraversalUnify();

    vector<vector<int>> levelOrder();
    vector<vector<int>> levelOrderRecursive();
};

#endif
