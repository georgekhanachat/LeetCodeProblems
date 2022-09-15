#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int diff = 0;
        auto minVal = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            minVal = min(minVal, prices[i]);
            diff = max(diff, prices[i] - minVal);
        }
        return diff;
    }
};

int main() {
    Solution sol;
    vector<int> prices;
    // 7
    prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices) << endl;
    // 4
    prices = {1, 2, 3, 4, 5};
    cout << sol.maxProfit(prices) << endl;
    // 0
    prices = {7, 6, 4, 3, 1};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}
