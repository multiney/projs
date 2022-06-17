#include "BT.h"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    TreeNode t(1);
    t.left = new TreeNode(2);
    t.right = new TreeNode(3);
    t.left->left = new TreeNode(4);
    vector<int> vec = t.inorderTraversalUnify();
    for (auto i : vec)
        cout << i << " ";
    cout << endl;

    cout << "level order:";
    vector<vector<int>> vvec = t.levelOrderRecursive();
    for (auto& v : vvec)
        for (auto i : v)
            cout << i << " ";
    cout << endl;
}
