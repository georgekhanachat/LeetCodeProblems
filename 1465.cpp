#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static size_t maxInPrefixDiff(int x, vector<int>& v) {
        sort(v.begin(),v.end());
        int maxi = INT_MIN;
        maxi = max(maxi,v[0]);
        for (int i = 1; i < v.size(); ++i) {
            maxi = max(maxi,v[i] - v[i-1]);
        }

        maxi = max(maxi, x - v[v.size() - 1]);

        return maxi;
    }

    static int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        return (size_t)(maxInPrefixDiff(h, horizontalCuts) * maxInPrefixDiff(w, verticalCuts)) % (1000000000 + 7);
    }
};

int main() {
    int h, w;
    vector<int> horizontalCuts, verticalCuts;
    h = 5;
    w = 4;
    horizontalCuts = {1, 2, 4};
    verticalCuts = {1, 3};
    // Output: 4
    std::cout << Solution::maxArea(h, w, horizontalCuts, verticalCuts) << std::endl;
    h = 5;
    w = 4;
    horizontalCuts = {3, 1};
    verticalCuts = {1};
    // Output: 6
    std::cout << Solution::maxArea(h, w, horizontalCuts, verticalCuts) << std::endl;
    h = 5;
    w = 4;
    horizontalCuts = {3};
    verticalCuts = {3};
    // Output: 9
    std::cout << Solution::maxArea(h, w, horizontalCuts, verticalCuts) << std::endl;
    return 0;
}
