#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int lengthOfLIS(const vector<int> &nums) {
        vector<int> dp(nums.size(), 1);
        int maxV = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxV = max(maxV, dp[i]);
                }
            }
        }
        return maxV;
    }
};

class Solution1 {
public:
    int lengthOfLIS(const vector<int> &nums) {
        int n = nums.size();
        int len = 1;
        vector<int> temp;
        temp.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                len++;
            } else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }
};

int main() {
    Solution sol;
    Solution1 sol1;

//    cout << sol.lengthOfLIS({0,1,3,3,4}) << endl;
    cout << sol1.lengthOfLIS({0,3,1,3,4}) << endl;

    return 0;
}
