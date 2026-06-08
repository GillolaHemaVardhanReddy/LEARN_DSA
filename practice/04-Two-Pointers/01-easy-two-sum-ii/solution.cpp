// LC 167 — Two Sum II (Input Array Is Sorted)  ·  CONVERGING two pointers
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // cue: sorted + pair by sum -> two pointers
        // L=0, R=n-1; move by comparing sum to target. Return 1-INDEXED.
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> a = {2,7,11,15};
    auto r1 = sol.twoSum(a, 9);  cout << r1[0] << "," << r1[1] << "  (expect 1,2)\n";
    vector<int> b = {2,3,4};
    auto r2 = sol.twoSum(b, 6);  cout << r2[0] << "," << r2[1] << "  (expect 1,3)\n";
    return 0;
}
