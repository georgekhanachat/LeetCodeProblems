#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
    return 0;
}
