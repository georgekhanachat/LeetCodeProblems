#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "Util/TreeNode.h"

using namespace std;


class Solution {
public:
    void helper(unordered_map<int,int>& freqMap, TreeNode* root) {
        if (!root)
            return;
        freqMap[root->val]++;
        helper(freqMap, root->left);
        helper(freqMap, root->right);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> freqMap;
        helper(freqMap, root);
        auto pr = std::max_element(begin(freqMap), end(freqMap),
                                   [] (const auto& p1, const auto& p2) {
                                       return p1.second < p2.second;
                                   }
        );

        vector<int> res;
        int max = pr->second;
        while (pr != freqMap.end()) {
            res.push_back(pr->first);
            pr = find_if(next(pr), end(freqMap), [&](const auto& p) {
                return p.second == max;
            });
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> a = {"1","null","2","2"};
    vector<int> res = sol.findMode(createBinaryTree(a));
    for (auto i: res)
        cout << i << " ";
    cout << endl;
    return 0;
}
