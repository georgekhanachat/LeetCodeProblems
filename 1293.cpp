#include <stack>
#include "LCUtils/LCIncludes.h"

class Solution {
public:
    template<typename T1, typename T2>
    struct hash_pair final {
        size_t operator()(const std::pair<T1, T2> &p) const noexcept {
            size_t hash1 = std::hash<T1>{}(p.first);
            hash1 <<= sizeof(size_t) * 4;
            hash1 ^= std::hash<T2>{}(p.second);
            return std::hash<size_t>{}(hash1);
        }
    };

    int shortestPath(vector<vector<int>> &&grid, int k) {
        queue<tuple<int, int, int, int>> q;
        q.push({0, 0, 0, k});
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),-1));
        vector<array<int, 2>> dir = {{1,  0},
                                     {0,  1},
                                     {-1, 0},
                                     {0,  -1}};

        while (!q.empty()) {
            int i = get<0>(q.front());
            int j = get<1>(q.front());
            int steps = get<2>(q.front());
            int temp_k = get<3>(q.front());
            q.pop();

            for (auto d: dir) {
                int x = i + d[0];
                int y = j + d[1];
                if (x == grid.size() - 1 && y == grid[0].size() - 1) return steps + 1;
                if ((x < 0 || x > grid.size() - 1) || (y < 0 || y > grid[0].size() - 1)) continue;
                if (grid[x][y] == 1) {
                    if (temp_k > 0)
                        temp_k--;
                    else
                        continue;
                }
                if (visited[x][y] >= temp_k && visited[x][y] != -1) continue;

                q.push({x, y, steps + 1,temp_k});
                visited[x][y] = temp_k;
            }
        }

        return -1;
    }
};


int main() {
    Solution sol;
    cout << sol.shortestPath({
                                     {0, 0, 0},
                                     {1, 1, 0},
                                     {0, 0, 0},
                                     {0, 1, 1},
                                     {0, 0, 0},
                             }, 1);
}