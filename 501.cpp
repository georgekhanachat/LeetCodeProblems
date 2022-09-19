#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


/**
 * Definition for a binary tree node.
 */

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
    void helper(unordered_map<int, int> &freqMap, TreeNode *root) {
        if (!root)
            return;
        freqMap[root->val]++;
        helper(freqMap, root->left);
        helper(freqMap, root->right);
    }

    vector<int> findMode(TreeNode *root) {
        unordered_map<int, int> freqMap;
        helper(freqMap, root);
        auto pr = std::max_element(begin(freqMap), end(freqMap),
                                   [](const auto &p1, const auto &p2) {
                                       return p1.second < p2.second;
                                   }
        );

        vector<int> res;
        int max = pr->second;
        while (pr != freqMap.end()) {
            res.push_back(pr->first);
            pr = find_if(next(pr), end(freqMap), [=](const auto &p) {
                return p.second == max;
            });
        }


        return res;
    }
};

int main() {
    return 0;
}
