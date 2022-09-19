#include <iostream>
#include <vector>
#include <algorithm>
#include "Util/TreeNode.h"

using namespace std;

class Solution {
public:
    int sum = 0;
    void sumLeft(TreeNode* root) {
        if(!root)
            return;
        if (root->left != nullptr && (root->left->left == nullptr && root->left->right == nullptr))
            sum += root->left->val;
        sumLeft(root->left);
        sumLeft(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        sumLeft(root);
        return sum;
    }
};

int main() {
    Solution sol;
    vector<string> tree = {"3", "9", "20", "null", "null", "15", "7"};
    cout << sol.sumOfLeftLeaves(createBinaryTree(tree));
    return 0;
}
