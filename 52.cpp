#include <iostream>
#include <vector>
#include "Util/Print.h"
#include <array>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void helper(int& res, unordered_set<int> &cols, unordered_set<int> &posDiag, unordered_set<int> &negDiag, vector<string> &grid, int row, int n) {
        if (row == n) {
            ++res;
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (cols.find(col) != cols.end() || posDiag.find(row + col) != posDiag.end() ||
                negDiag.find(row - col) != negDiag.end())
                continue;

            cols.insert(col);
            posDiag.insert(row + col);
            negDiag.insert(row - col);
            grid[row][col] = 'Q';

            helper(res, cols, posDiag, negDiag, grid, row + 1, n);

            cols.erase(col);
            posDiag.erase(row + col);
            negDiag.erase(row - col);
            grid[row][col] = '.';
        }

    }
    int totalNQueens(int n) {
        int res = 0;
        vector<string> grid(n, string(n, '.'));
        unordered_set<int> cols, posDiag, negDiag;

        helper(res, cols, posDiag, negDiag, grid, 0, n);

        return res;
    }
};

int main() {
    Solution sol;
    auto res = sol.totalNQueens(4);
    cout << res << endl;
    return 0;
}