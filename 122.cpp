#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for (int i = 1; i < prices.size(); ++i)
            if (prices[i] - prices[i-1] > 0) sum += prices[i] - prices[i-1];
        return sum;
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
