#include "func.h"
// #include "BT.h"

#include <queue>
#include <random>
#include <stack>

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
    int treeNum = 1000;
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

vector<TreeNode*> createTreesByLevel() {
    auto vvi = createTreeVecs();
    vector<TreeNode*> vt;

    for (unsigned int i = 0; i < vvi.size(); ++i) {
        TreeNode* root = CreateTreeByLevel(vvi[i]);
        vt.push_back(root);
    }
    return vt;
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
