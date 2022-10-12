#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std::chrono;
using namespace std;

class Solution {
public:
    vector<int> candyCrushMethod1(vector<int> candy) {
        for (int i = 0; i < candy.size(); ++i) {
            auto cmp = [&candy,&i](auto c){return c != candy[i];};
            int j = distance(candy.begin(), find_if(candy.begin() + i,candy.end(), cmp));
            if (j - i >= 3) {
                candy.erase(candy.begin() + i, candy.begin() + j);
                i = distance(candy.begin(), (find_if(candy.rbegin() + candy.size() - (i + 1), candy.rend(), cmp) + 1).base());
            }
        }
        return candy;
    }
};

int main() {
    Solution sol;
    vector<int> res = sol.candyCrushMethod1({4, 1, 1, 3, 3, 2, 2, 2, 2, 3, 3, 1, 4, 4});
    for (auto &r: res)
        cout << r << " ";
    cout << endl;

    return 0;
}
