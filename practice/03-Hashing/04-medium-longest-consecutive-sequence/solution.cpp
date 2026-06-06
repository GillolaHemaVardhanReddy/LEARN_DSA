// LC 128 — Longest Consecutive Sequence  (Hash set, O(n))
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // ───── YOUR CODE HERE ─────
        // unordered_set of all nums. For each x with (x-1 NOT in set): walk x,x+1,... count run.
        return 0; // replace
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    vector<int> a = {100, 4, 200, 1, 3, 2};
    cout << sol.longestConsecutive(a) << "  (expect 4)\n";
    vector<int> b = {0,3,7,2,5,8,4,6,0,1};
    cout << sol.longestConsecutive(b) << "  (expect 9)\n";
    return 0;
}
