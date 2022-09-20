#include <iostream>
#include "Util/TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) return NULL;
        if (root->val == val) return root;
        if (root->val < val) {
            return searchBST(root->right,val);
        } else {
            return searchBST(root->left,val);
        }
        return root;
    }
};

int main() {
    Solution sol;

    vector<string> a = {"4","2","7","1","3"};
    sol.searchBST(createBinaryTree(a), 2);

    return 0;
}
