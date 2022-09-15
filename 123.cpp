#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> vector) {
        return 1;
    }
};

int main() {
    Solution sol;
    vector<int> prices;
    // 6
    prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << sol.maxProfit(prices) << endl;
    // 4
    prices = {1, 2, 3, 4, 5};
    cout << sol.maxProfit(prices) << endl;
    // 0
    prices = {7, 6, 4, 3, 1};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}
