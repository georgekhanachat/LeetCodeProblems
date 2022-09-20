#include <iostream>
#include <vector>
#include "Util/Print.h"
#include <array>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void test(int n) {
        vector<vector<int>> grid(n, vector<int>(n, -3));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    grid[i][k] += 1;
                }
                for (int k = 0; k < n; ++k) {
                    grid[k][j] += 1;
                }
                int startI = i - min(j, i);
                int startJ = j - min(j, i);
                for (int k = startI, l = startJ; k < n && l < n; ++k, ++l) {
                    grid[k][l] += 1;
                }

                if (i + j <= n - 1) {
                    startI = 0;
                    startJ = j + i;
                } else {
                    startI = i - (n - 1 - j);
                    startJ = n - 1;
                }
                for (int k = startI, l = startJ; k < n && l > -1; ++k, --l) {
                    grid[k][l] += 1;
                }

                print(grid);
                cout << endl;
            }
        }
    }

    void incrementAttacks(vector<vector<int>> &grid, int i, int j, int n) {
        grid[i][j] += 1;
        for (int k = 0; k < n; ++k) {
            if (j == k) continue;
            grid[i][k] += 1;
        }
        for (int k = 0; k < n; ++k) {
            if (i == k) continue;
            grid[k][j] += 1;
        }
        int startI = i - min(j, i);
        int startJ = j - min(j, i);
        for (int k = startI, l = startJ; k < n && l < n; ++k, ++l) {
            if (j == l && i == k) continue;
            grid[k][l] += 1;
        }

        if (i + j <= n - 1) {
            startI = 0;
            startJ = j + i;
        } else {
            startI = i - (n - 1 - j);
            startJ = n - 1;
        }
        for (int k = startI, l = startJ; k < n && l > -1; ++k, --l) {
            if (j == l && i == k) continue;
            grid[k][l] += 1;
        }
    }

    void
    helper(vector<vector<string>> &res, unordered_set<int> &cols, unordered_set<int> &posDiag,
           unordered_set<int> &negDiag,
           vector<string> &grid, int row, int n) {
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

            helper(res, cols, posDiag, negDiag, grid, row + 1, n);

            cols.erase(col);
            posDiag.erase(row + col);
            negDiag.erase(row - col);
            grid[row][col] = '.';
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> grid(n, string(n, '.'));
        unordered_set<int> cols, posDiag, negDiag;

        helper(res, cols, posDiag, negDiag, grid, 0, n);

        return res;
    }
};

int main() {
    Solution sol;
    auto res = sol.solveNQueens(6);
    print(res);
    return 0;
}