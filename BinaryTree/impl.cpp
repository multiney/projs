#include "BT.h"

#include <stack>
#include <algorithm>
#include <queue>

using std::stack;
using std::queue;

// preorder traversal
void traversal(TreeNode* curr, vector<int>& vec)
{
    if (curr == nullptr) return;
    vec.push_back(curr->val);
    traversal(curr->left, vec);
    traversal(curr->right, vec);
}

vector<int> TreeNode::preorderTraversal()
{
    vector<int> ret;
    traversal(this, ret);
    return ret;
}

vector<int> TreeNode::preorderTraversalStk()
{
    stack<TreeNode*> stk;
    vector<int> ret;
    // if (this == nullptr) return ret;
    stk.push(this);
    while (!stk.empty()) {
        TreeNode* node = stk.top();
        stk.pop();
        ret.push_back(node->val);
        if (node->right) stk.push(node->right);
        if (node->left) stk.push(node->left);
    }
    return ret;
}

vector<int> TreeNode::inorderTraversal()
{
    stack<TreeNode*> stk;
    vector<int> ret;
    TreeNode* curr = this;
    while (curr || !stk.empty()) {
        if (curr) {
            stk.push(curr);
            curr = curr->left;
        }
        else {
            curr = stk.top();
            stk.pop();
            ret.push_back(curr->val);
            curr = curr->right;
        }
    }
    return ret;
}

vector<int> TreeNode::postorderTraversal()
{
    stack<TreeNode*> stk;
    vector<int> vec;
    stk.push(this);
    while (!stk.empty()) {
        TreeNode* node = stk.top();
        stk.pop();
        vec.push_back(node->val);
        if (node->left) stk.push(node->left);
        if (node->right) stk.push(node->right);
    }
    reverse(vec.begin(), vec.end());
    return vec;
}

vector<int> TreeNode::inorderTraversalUnify()
{
    stack<TreeNode*> stk;
    vector<int> ret;
    stk.push(this);
    while (!stk.empty()) {
        TreeNode* node = stk.top();
        if (node) {
            stk.pop();
            if (node->right) stk.push(node->right);
            stk.push(node);
            stk.push(nullptr);
            if (node->left) stk.push(node->left);
        }
        else {
            stk.pop();
            node = stk.top();
            stk.pop();
            ret.push_back(node->val);
        }
    }
    return ret;
}

vector<vector<int>> TreeNode::levelOrder()
{
    queue<TreeNode*> que;
    vector<vector<int>> ret;
    que.push(this);
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        TreeNode* node;

        while (size--) {
            node = que.front();
            que.pop();
            vec.push_back(node->val);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        ret.push_back(vec);
    }
    return ret;
}

void order(TreeNode* curr, vector<vector<int>>& ret, unsigned depth)
{
    if (curr == nullptr) return;
    if (ret.size() == depth) ret.push_back(vector<int>());
    ret[depth].push_back(curr->val);
    order(curr->left, ret, depth + 1);
    order(curr->right, ret, depth + 1);
}

vector<vector<int>> TreeNode::levelOrderRecursive()
{
    vector<vector<int>> ret;
    unsigned depth = 0;
    order(this, ret, depth);
    return ret;
}


