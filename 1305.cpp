#include <iostream>
#include <vector>
#include <algorithm>
#include "Util/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> res;

    void help(TreeNode *root) {
        if (!root)
            return;
        res.push_back(root->val);

        help(root->left);
        help(root->right);
    }

    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        help(root1);
        help(root2);

        sort(res.begin(), res.end());

        return res;
    }
};

int main() {
    Solution sol;
    vector<string> a = {"2","1","4"};
    vector<string> b = {"1","0","3"};
    for (auto i: sol.getAllElements(createBinaryTree(a),createBinaryTree(b)))
        cout << i << " ";
    cout << endl;
    return 0;
}
