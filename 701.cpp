#include <iostream>
#include "Util/TreeNode.h"

using namespace std;

class Solution {
public:
    void traverse(TreeNode *root, int val) {
        if (root->val < val) {
            if (root->right != nullptr)
                traverse(root->right,val);
            else
                root->right = new TreeNode(val);
        } else if (root->val > val) {
            if (root->left != nullptr)
                traverse(root->left,val);
            else
                root->left = new TreeNode(val);
        }

        return;
    }

    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if(root == nullptr)
            return new TreeNode(val);
        traverse(root, val);
        return root;
    }
};

int main() {
    Solution sol;

    vector<string> a = {"8", "null", "55", "39", "null", "11", "null", "null", "23", "null", "null"};
    sol.insertIntoBST(createBinaryTree(a), 17);

    return 0;
}
