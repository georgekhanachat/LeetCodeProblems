#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        res[0] = {1};
        if (numRows == 1) return res;
        res[1] = {1,1};
        for (int i = 2; i < numRows; ++i) {
            res[i].push_back(1);
            for (int j = 0; j < i - 1; ++j) {
                res[i].push_back(res[i-1][j] + res[i-1][j+1]);
            }
            res[i].push_back(1);
        }
        return res;
    }
};

void printPascal(const vector<vector<int>> &pascal) {
    const size_t n = pascal.size();
    for (size_t i = 0; i < n; ++i) {
        // Padding
        for(size_t j = i; j < n; ++j) cout << " ";
        for(size_t j = 0; j < i+1; ++j) {
            cout << pascal[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution sol;

    cout << "Test 1: " << endl;
    printPascal(sol.generate(5));

    cout << "Test 2: " << endl;
    printPascal(sol.generate(1));



    return 0;
}
