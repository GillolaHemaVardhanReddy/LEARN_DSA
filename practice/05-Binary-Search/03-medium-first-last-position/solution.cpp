// LC 34 — Find First and Last Position  ·  BOTH boundaries (store-candidate twice)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // knobs: same engine twice. FIRST: on hit store + go LEFT. LAST: on hit store + go RIGHT.
        // handle empty array -> {-1,-1}.
        // YOUR CODE HERE
        return {-1, -1};
    }
};

int main() {
    Solution sol;
    vector<int> a = {5,7,7,8,8,10};
    auto r1 = sol.searchRange(a, 8);  cout << "[" << r1[0] << "," << r1[1] << "]  (expect [3,4])\n";
    auto r2 = sol.searchRange(a, 6);  cout << "[" << r2[0] << "," << r2[1] << "]  (expect [-1,-1])\n";
    vector<int> b = {};
    auto r3 = sol.searchRange(b, 0);  cout << "[" << r3[0] << "," << r3[1] << "]  (expect [-1,-1])\n";
    return 0;
}
