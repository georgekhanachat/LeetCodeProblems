#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0, product = 1;
        while (n > 0) {
            product *= n % 10;
            sum += n % 10;
            n /= 10;
        }

        return product - sum;
    }
};

int main() {
    Solution sol;
    cout << sol.subtractProductAndSum(10) << endl;
    return 0;
}
