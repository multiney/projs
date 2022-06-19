#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void traversal(TreeNode* curr, vector<int>& vec)
{
    if (curr == nullptr) return;
    vec.push_back(curr->val);
    traversal(curr->left, vec);
    traversal(curr->right, vec);
}

vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> ret;
    traversal(root, ret);
    return ret;
}

int main()
{
    TreeNode t(1);
    t.left = new TreeNode(2);
    t.right = new TreeNode(3);
    vector<int> vec = preorderTraversal(&t);
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
}
