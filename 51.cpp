#include <iostream>
#include <vector>
#include "LCUtils/LCPrint.h"
#include <array>
#include <unordered_set>

using namespace std;

class Solution {
private:
    unordered_set<int> cols, posDiag, negDiag;
public:
    void helper(vector<vector<string>> &res, vector<string> &grid, int row, int n) {
        if (row == n) {
            res.push_back(grid);
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

            helper(res, grid, row + 1, n);

            cols.erase(col);
            posDiag.erase(row + col);
            negDiag.erase(row - col);
            grid[row][col] = '.';
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> grid(n, string(n, '.'));

        helper(res, grid, 0, n);

        return res;
    }
};

int main() {
    Solution sol;
    auto res = sol.solveNQueens(5);
    return 0;
}