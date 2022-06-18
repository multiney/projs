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
