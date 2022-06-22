#include "func.h"
// #include "BT.h"

#include <queue>
#include <random>
#include <stack>
#include <bits/stdc++.h>

using std::queue;
using std::stack;

TreeNode* CreateTreeByLevel(const vector<int>& nums) {
    int len = nums.size();
    if (len == 0 || nums[0] == -1) return nullptr;

    int index = 0;
    queue<TreeNode*> que;
    TreeNode* root = new TreeNode(nums[index++]);
    que.push(root);
    TreeNode* p = nullptr;

    while (!que.empty() && index < len) {
        p = que.front();
        que.pop();

        if (nums[index] != -1) {
            p->left = new TreeNode(nums[index]);
            que.push(p->left);
        }
        ++index;

        if (index < len && nums[index] != -1) {
            p->right = new TreeNode(nums[index]);
            que.push(p->right);
        }
        ++index;
    }

    return root;
}

// TreeNode* CreateTreeByPre(const vector<int>& nums) {
//     int len = nums.size();
//     if (len == 0 && nums[0] == -1) return nullptr;
//     int index = 0;
//     TreeNode* root = new TreeNode(nums[index++]);
//     stack<TreeNode*> stk;
//     stk.push(root);
//     TreeNode* p = nullptr;
//     
//     while (!stk.empty()) {
//         p = stk.top();
//         stk.pop();
//
//         if (nums[index] != -1) {
//             p->left = nums[index];
//             stk.
//         }
//     }
// }

vector<vector<int>> createTreeVecs() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist1000(1, 1000);

    vector<vector<int>> vvi;
    int treeNum = 10000;
    while (treeNum--) {
        vector<int> vec;
        int len = dist1000(rng);
        while (len--) {
            vec.push_back(dist1000(rng));
        }
        vvi.push_back(vec);
    }
    return vvi;
}

vector<vector<int>> createTreeVecsUnique() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist10000(1, 10000);

    vector<vector<int>> vvi;
    int treeNum = 10000;
    while (treeNum--) {
        vector<int> vec;
        int len = 1000;
        while (len--) {
            int val = dist10000(rng);
            bool flag = true;
            for (auto i : vec)
                if (i == val)
                    flag = false;
            if (flag)
                vec.push_back(val);
        }
        vvi.push_back(vec);
    }
    return vvi;
}

vector<TreeNode*> createTreesByLevel() {
    auto vvi = createTreeVecs();
    vector<TreeNode*> vt;

    for (unsigned int i = 0; i < vvi.size(); ++i) {
        TreeNode* root = CreateTreeByLevel(vvi[i]);
        vt.push_back(root);
    }
    return vt;
}

vector<TreeNode*> createTreesByLevel(const vector<vector<int>>& vvi) {
    vector<TreeNode*> vt;

    for (unsigned int i = 0; i < vvi.size(); ++i) {
        TreeNode* root = CreateTreeByLevel(vvi[i]);
        vt.push_back(root);
    }
    return vt;
}

/**
  * Binary tree Preorder traversal 
  */ 
void preorder(TreeNode* curr, vector<int>& ret) {
    if (curr == nullptr) return;
    ret.push_back(curr->val);
    preorder(curr->left, ret);
    preorder(curr->right, ret);
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ret;
    preorder(root, ret);
    return ret;
}

vector<int> preorderTraversalStk(TreeNode* root) {
    vector<int> ret;
    if (root == nullptr) return ret;
    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
        TreeNode* node = stk.top();
        stk.pop();

        ret.push_back(node->val);
        if (node->right) stk.push(node->right);
        if (node->left) stk.push(node->left);
    }
    return ret;
}

/**
  * 94. Binary Tree Inorder traversal 
  */ 
void inTraversalOf94(TreeNode* curr, vector<int>& ret) {
    if (curr == nullptr) return;
    inTraversalOf94(curr->left, ret);
    ret.push_back(curr->val);
    inTraversalOf94(curr->right, ret);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ret;
    inTraversalOf94(root, ret);
    return ret;
}

/**
  * 145. Binary Tree Postorder Traversal 
  */ 
void postTraversalOf145(TreeNode* curr, vector<int>& ret) {
    if (curr == nullptr) return;
    postTraversalOf145(curr->left, ret);
    postTraversalOf145(curr->right, ret);
    ret.push_back(curr->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ret;
    postTraversalOf145(root, ret);
    return ret;
}

// LeetCode
int getHight(TreeNode* node) {
    if (node == nullptr) return 0;
    int leftHight = getHight(node->left);
    if (leftHight == -1) return -1;
    int rightHight = getHight(node->right);
    if (rightHight == -1) return -1;
    return abs(leftHight - rightHight) > 1 ? -1 : 1 + std::max(leftHight, rightHight);
}
bool isBalanced(TreeNode* root) {
    return getHight(root) == -1 ? false : true;
}

// 没看
int getDepth(TreeNode* cur) {
    stack<TreeNode*> st;
    if (cur != NULL) st.push(cur);
    int depth = 0; // 记录深度
    int result = 0;
    while (!st.empty()) {
        TreeNode* node = st.top();
        if (node != NULL) {
            st.pop();
            st.push(node);                          // 中
            st.push(NULL);
            depth++;
            if (node->right) st.push(node->right);  // 右
            if (node->left) st.push(node->left);    // 左

        } else {
            st.pop();
            node = st.top();
            st.pop();
            depth--;
        }
        result = result > depth ? result : depth;
    }
    return result;
}
bool isBalancedIter(TreeNode* root) {
    stack<TreeNode*> st;
    if (root == NULL) return true;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();                       // 中
        st.pop();
        if (abs(getDepth(node->left) - getDepth(node->right)) > 1) {
            return false;
        }
        if (node->right) st.push(node->right);           // 右（空节点不入栈）
        if (node->left) st.push(node->left);             // 左（空节点不入栈）
    }
    return true;
}



// my own version
// vector<string> paths;
// void getPath(TreeNode* curr, string path) {
//     if (!curr->left && !curr->right) {
//         paths.push_back(path);
//         return;
//     }
//     if (curr->left) getPath(curr->left, path + "->" + std::to_string(curr->left->val));
//     if (curr->right) getPath(curr->right, path + "->" + std::to_string(curr->right->val));
// }
// vector<string> binaryTreePaths(TreeNode* root) {
//     if (root == nullptr) return paths;
//     string path = std::to_string(root->val);
//     getPath(root, path);
//     return paths;
// }

// optimized version of mine
// TODO: why so slow?
vector<string> paths;
void getPath(TreeNode* curr, string path) {
    path += std::to_string(curr->val);
    if (!curr->left && !curr->right) {
        paths.push_back(path);
        return;
    }
    if (curr->left) getPath(curr->left, path + "->");
    if (curr->right) getPath(curr->right, path + "->");
}
vector<string> binaryTreePaths(TreeNode* root) {
    if (root == nullptr) return paths;
    string path;
    getPath(root, path);
    return paths;
}

void traversalPath(TreeNode* curr, string path, vector<string>& ret) {
    path += std::to_string(curr->val); // 直接加curr->val为什么不行?
    if (!curr->left && !curr->right) {
        ret.push_back(path);
        return;
    }
    if (curr->left) traversalPath(curr->left, path + "->", ret);
    if (curr->right) traversalPath(curr->right, path + "->", ret);
}
vector<string> binaryTreePaths2(TreeNode* root) {
    vector<string> ret;
    if (root == nullptr) return ret;
    string path;
    traversalPath(root, path, ret);
    return ret;
}

vector<string> binaryTreePathsStk(TreeNode* root) {
    vector<string> ret;
    if (root == nullptr) return ret;
    stack<string> pathStk;
    stack<TreeNode*> treeStk;
    treeStk.push(root);
    pathStk.push(std::to_string(root->val));
    
    while (!treeStk.empty()) {
        TreeNode* node = treeStk.top(); treeStk.pop();
        string path = pathStk.top(); pathStk.pop();

        if (!node->left && !node->right) {
            ret.push_back(path);
            continue;
        }

        if (node->right) {
            treeStk.push(node->right);
            pathStk.push(path + "->" + std::to_string(node->right->val));
        }
        if (node->left) {
            treeStk.push(node->left);
            pathStk.push(path + "->" + std::to_string(node->left->val));
        }
    }
    return ret;
}


bool isSameTree(TreeNode* tree1, TreeNode* tree2) {
    if (!tree1 && !tree2) return true;
    if (!tree1 || !tree2 || (tree1->val != tree2->val)) return false;

    bool leftCompare = isSameTree(tree1->left, tree2->left);
    bool rightCompare = isSameTree(tree1->right, tree2->right);
    return leftCompare && rightCompare;
}

bool isSameTreeIter(TreeNode* tree1, TreeNode* tree2) {
    if (!tree1 && !tree2) return true;
    stack<TreeNode*> stk1;
    stack<TreeNode*> stk2;
    stk1.push(tree1);
    stk2.push(tree2);

    while (!stk1.empty() && !stk2.empty()) {
        TreeNode* node1 = stk1.top(); stk1.pop();
        TreeNode* node2 = stk2.top(); stk2.pop();

        if (!node1 && !node2) continue;
        if (!node1 || !node2 || (node1->val != node2->val)) return false;

        stk1.push(node1->right);
        stk1.push(node1->left);
        stk2.push(node2->right);
        stk2.push(node2->left);
    }
    return true;
}


/**
  * 104. maximum depth of binary tree 
  */ 
int ret;
void getDepthOfMaxDepth(TreeNode* curr, int depth) {
    ret = ret > depth ? ret : depth;
    if (!curr->left && !curr->right) return;
    if (curr->left) getDepthOfMaxDepth(curr->left, depth + 1);
    if (curr->right) getDepthOfMaxDepth(curr->right, depth + 1);
}
int maxDepth(TreeNode* root) {
    ret = 0;
    if (root == nullptr) return ret;
    getDepthOfMaxDepth(root, 1);
    return ret;
}

int maxDepthPre(TreeNode* root) {
    int ret = 0;
    if (root == nullptr) return ret;
    stack<TreeNode*> stk;
    stack<int> depthStk;
    stk.push(root);
    depthStk.push(1);

    while (!stk.empty()) {
        TreeNode* node = stk.top(); stk.pop();
        int depth = depthStk.top(); depthStk.pop();

        ret = ret > depth ? ret : depth;

        if (node->right) {
            stk.push(node->right);
            depthStk.push(depth + 1);
        }
        if (node->left) {
            stk.push(node->left);
            depthStk.push(depth + 1);
        }
    }
    return ret;
}

int maxDepthLevel(TreeNode* root) {
    int ret = 0;
    if (root == nullptr) return ret;
    queue<TreeNode*> que;
    que.push(root);

    while (!que.empty()) {
        int size = que.size();
        ++ret;

        while (size--) {
            TreeNode* node = que.front(); que.pop();
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
    }
    return ret;
}

/**
  * 404. Sum of Left Leaves
  */ 
int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;
    int leftVal = sumOfLeftLeaves(root->left);
    int rightVal = sumOfLeftLeaves(root->right);
    
    int midVal = 0;
    if (root->left && !root->left->left && !root->left->right)
        midVal = root->left->val;

    return leftVal + rightVal + midVal;
}

int sumOfLeftLeavesStk(TreeNode* root) {
    if (root == nullptr) return 0;
    stack<TreeNode*> stk;
    stk.push(root);
    int ret = 0;

    while (!stk.empty()) {
        TreeNode* p = stk.top();
        stk.pop();

        if (p->left && !p->left->left && !p->left->right)
            ret += p->left->val;

        if (p->right) stk.push(p->right);
        if (p->left) stk.push(p->left);
    }
    return ret;
}

/**
  * 513. Find Bottom Left Tree Value
  */ 
int max_depth = INT_MIN;
int maxLeftVal;
void preTraversalOf513(TreeNode* curr, int depth) {
    if (!curr->left && !curr->right) {
        if (depth > max_depth) {
            max_depth = depth;
            maxLeftVal = curr->val;
        }
    }

    if (curr->left)
        preTraversalOf513(curr->left, depth + 1);

    if (curr->right)
        preTraversalOf513(curr->right, depth + 1);
}
int findBottomLeftValue(TreeNode* root) {
    // TODO: throw an error notification when "root == nullptr", next function as well
    preTraversalOf513(root, 0);
    return maxLeftVal;
}

int findBottomLeftValueQue(TreeNode* root) {
    queue<TreeNode*> que;
    que.push(root);
    int bottomLeftVal = 0;

    while (!que.empty()) {
        int size = que.size() - 1;
        TreeNode* p = que.front();
        que.pop();
        bottomLeftVal = p->val;

        if (p->left) que.push(p->left);
        if (p->right) que.push(p->right);

        while (size--) {
            p = que.front();
            que.pop();

            if (p->left) que.push(p->left);
            if (p->right) que.push(p->right);
        }
    }
    return bottomLeftVal;
}

/**
  * 112. Path Sum
  */ 
// my own version of helper function
bool preTraversalOf112(TreeNode* curr, int targetSum) {
    if (!curr) return false;
    if (!curr->left && !curr->right) {
        if (targetSum == curr->val)
            return true;
        return false; // can remove, but will run more code if remove.
    }
    bool left = preTraversalOf112(curr->left, targetSum - curr->val);
    bool right = preTraversalOf112(curr->right, targetSum - curr->val);
    return left || right;
}
bool hasPathSum(TreeNode* root, int targetSum) {
    return preTraversalOf112(root, targetSum);
}

bool hasPathSumStk(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;
    stack<TreeNode*> nodeStk;
    stack<int> numStk;
    nodeStk.push(root);
    numStk.push(targetSum);

    while (!nodeStk.empty()) {
        TreeNode* node = nodeStk.top(); nodeStk.pop();
        int num = numStk.top(); numStk.pop();

        if (!node->left && !node->right && num == node->val)
            return true;
        if (node->right) {
            nodeStk.push(node->right);
            numStk.push(num - node->val);
        }
        if (node->left) {
            nodeStk.push(node->left);
            numStk.push(num - node->val);
        }
    }
    return false;
}

/**
  * 113. Path Sum II 
  */ 
void preTraversalOf113(TreeNode* curr, int targetSum, vector<int>& path, vector<vector<int>>& ret) {
    if (!curr) return;
    path.push_back(curr->val);
    if (!curr->left && !curr->right) {
        if (targetSum == curr->val)
            ret.push_back(path);
        path.pop_back();
        return;
    }
    preTraversalOf113(curr->left, targetSum - curr->val, path, ret);
    preTraversalOf113(curr->right, targetSum - curr->val, path, ret);
    path.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> ret;
    if (root == nullptr) return ret;
    vector<int> path;
    preTraversalOf113(root, targetSum, path, ret);
    return ret;
}

/**
  * 106. Construct Binary Tree from Inorder and Postorder traversal
  */ 
TreeNode* traversalOf106(const vector<int>& inorder, int iBegin, int iEnd, const vector<int>& postorder, int pBegin, int pEnd) {
    if (pBegin == pEnd)  return nullptr;

    int nodeVal = postorder[pEnd - 1];
    TreeNode* root = new TreeNode(nodeVal);
    if (pEnd - pBegin == 1) return root; // trim

    int delimiterIndex = iBegin;
    for (; delimiterIndex < iEnd; ++delimiterIndex)
        if (inorder[delimiterIndex] == nodeVal) break;

    int leftIBegin = iBegin;
    int leftIEnd = delimiterIndex;
    int leftPBegin = pBegin;
    int leftPEnd = pBegin + delimiterIndex - iBegin;
    root->left = traversalOf106(inorder, leftIBegin, leftIEnd, postorder, leftPBegin, leftPEnd);

    int rightIBegin = delimiterIndex + 1;
    int rightIEnd = iEnd;
    int rightPBegin = pBegin + delimiterIndex - iBegin;
    int rightPEnd = pEnd - 1;
    root->right = traversalOf106(inorder, rightIBegin, rightIEnd, postorder, rightPBegin, rightPEnd);

    return root;
}
TreeNode* buildTreeInPost(const vector<int>& inorder, const vector<int>& postorder) {
    if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
    return traversalOf106(inorder, 0, inorder.size(), postorder, 0, postorder.size());
}

/**
  * 105. Construct Binary Tree from Preorder and Inorder Tarversal
  */ 
TreeNode* traversalOf105(const vector<int>& preorder, int preBegin, int preEnd, const vector<int>& inorder, int inBegin, int inEnd) {
    if (preBegin == preEnd) return nullptr;

    int nodeVal = preorder[preBegin];
    TreeNode* node = new TreeNode(nodeVal);
    if (preEnd - preBegin == 1) return node;

    int delimiterIndex;
    for (delimiterIndex = inBegin; delimiterIndex < inEnd; ++delimiterIndex)
        if (inorder[delimiterIndex] == nodeVal)
            break;

    int leftInBegin = inBegin;
    int leftInEnd = delimiterIndex;
    int leftPreBegin = preBegin + 1;
    int leftPreEnd = preBegin + 1 + delimiterIndex - inBegin;
    node-> left = traversalOf105(preorder, leftPreBegin, leftPreEnd, inorder, leftInBegin, leftInEnd);

    int rightInBegin = delimiterIndex + 1;
    int rightInEnd = inEnd;
    int rightPreBegin = preBegin + 1 + delimiterIndex - inBegin;
    int rightPreEnd = preEnd;
    node->right = traversalOf105(preorder, rightPreBegin, rightPreEnd, inorder, rightInBegin, rightInEnd);

    return node;
}
TreeNode* buildTreePreIn(const vector<int>& preorder, const vector<int>& inorder) {
    if (inorder.size() == 0 || preorder.size() == 0) return nullptr;
    return traversalOf105(preorder, 0, preorder.size(), inorder, 0, inorder.size());
}

/**
  * 654. Maximum Binary Tree
  */ 
TreeNode* buildOf654(const vector<int>& nums, int begin, int end) {
    if (begin == end) return nullptr;

    int delimiterIndex = begin;
    for (int i = begin + 1; i < end; ++i)
        if (nums[i] > nums[delimiterIndex])
            delimiterIndex = i;

    TreeNode* node = new TreeNode(nums[delimiterIndex]);
    if (end - begin == 1) return node;

    int leftBegin = begin;
    int leftEnd = delimiterIndex;
    node->left = buildOf654(nums, leftBegin, leftEnd);

    int rightBegin = delimiterIndex + 1;
    int rightEnd = end;
    node->right = buildOf654(nums, rightBegin, rightEnd);
    return node;
}
TreeNode* constructMaximumBinaryTree(const vector<int>& nums) {
    if (nums.size() == 0) return nullptr;
    return buildOf654(nums, 0, nums.size());
}
