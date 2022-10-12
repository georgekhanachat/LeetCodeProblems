#include "LCUtils/LCIncludes.h"
#include "LCUtils/LCUtils.h"

#define RUN_SOLUTION 0
/**
 * Solution 0 - Zero Solution
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
#if RUN_SOLUTION == 0

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        for (auto t: times)
            adjList[t[0]].push_back({t[1], t[2]});
        LC::print(adjList);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        vector<int> dist(n+1, INT_MAX);
        int maxTime = 0;
        q.push({0, k});
        dist[k] = 0;
        while (!q.empty()) {
            auto currTime = q.top().first;
            auto currNode = q.top().second;
            cout << currNode << " " << currTime << endl;
            q.pop();
            maxTime = currTime;
            for (auto adj: adjList[currNode]) {
                if (dist[adj.first] > dist[currNode] + adj.second) {
                    dist[adj.first] = dist[currNode] + adj.second;
                    q.push({dist[adj.first], adj.first});
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INT_MAX ? -1 : ans ;
    }
};

#endif

int main() {
    Solution sol;
    vector<vector<int>> times;
    int n, k;
    n = 4;
    k = 2;
    times = {{2, 1, 1},
             {2, 3, 1},
             {3, 4, 1}};
    LC::print(sol.networkDelayTime(times, n, k));
    n = 2;
    k = 1;
    times = {{1, 2, 1}};
    LC::print(sol.networkDelayTime(times, n, k));
    n = 2;
    k = 2;
    times = {{1, 2, 1}};
    LC::print(sol.networkDelayTime(times, n, k));
    n = 2;
    k = 2;
    times = {{1, 2, 1},
             {2, 1, 3}};
    LC::print(sol.networkDelayTime(times, n, k));
    return 0;
}