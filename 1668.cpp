#include <iostream>

using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        if (sequence.length() < word.length()) return 0;
        int count = 0;
        string temp = word;
        while (temp.length() <= sequence.length()) {
            if (sequence.find(temp) != string::npos) count++;
            temp += word;
        }
        return count;
    }
};

int main() {
    Solution sol;

    std::cout << sol.maxRepeating("ababc", "ab") << std::endl;
    std::cout << sol.maxRepeating("ababc", "ba") << std::endl;
    std::cout << sol.maxRepeating("aaabaaaabaaabaaaabaaaabaaaabaaaaba", "aaaba") << std::endl;

    return 0;
}
