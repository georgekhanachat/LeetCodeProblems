#include "LCUtils/LCIncludes.h"
#include "LCUtils/LCUtils.h"

#define RUN_SOLUTION 0
/**
 * Solution 0 - Zero Solution
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
#if RUN_SOLUTION == 0

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string> &products,
                                             string searchWord) {
        vector<vector<string>> res(searchWord.length());
        sort(products.begin(), products.end());

        for (int i = 0; i < searchWord.length(); ++i) {
            string str = searchWord.substr(0,i + 1);
            for (const auto& p: products) {
                if (res[i].size() == 3) break;
                if (str == p.substr(0, i+1)) {
                    res[i].push_back(p);
                }
            }
        }

        return res;
    }
};

#endif

int main() {
    Solution sol;
    vector<string> products;
    products = {"mouse", "mobile", "moneypot", "monitor", "mousepad"};
    LC::print(sol.suggestedProducts(products, "mouse"));
    products = {"havana"};
    LC::print(sol.suggestedProducts(products, "havana"));
    return 0;
}