#include <iostream>
#include <vector>
#include <algorithm>
#include "Util/TreeNode.h"
#include <map>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>&& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        map<int, int> freqMap;

        for (auto& i : hand) {
            freqMap[i]++;
        }

        while (!freqMap.empty()) {
            auto it = freqMap.begin();
            for (int i = 0; i < groupSize - 1; ++i) {
                if (freqMap.find(it->first + 1 + i) == freqMap.end())
                    return false;

                freqMap[it->first + 1 + i] -= it->second;
                if (freqMap[it->first + 1 + i] < 0)
                    return false;
                else if (freqMap[it->first + 1 + i] == 0)
                    freqMap.erase(it->first + 1 + i);
            }
            freqMap.erase(it->first);
        }

        return freqMap.empty();
    }
};

int main() {
    Solution sol;
    cout << sol.isNStraightHand({1,2,3,4,5},4);
    return 0;
}
