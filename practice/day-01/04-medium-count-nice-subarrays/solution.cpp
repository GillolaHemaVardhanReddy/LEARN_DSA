// LC 1248 — Count Number of Nice Subarrays
// COLD — classify it yourself (see problem.md), then implement.
// Paste ONLY the Solution class into LeetCode. main() is for local testing on onlinegdb.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // ───── YOUR CODE HERE ─────

        return 0; // replace
    }
};

// ───────── local test harness (ignore when pasting to LeetCode) ─────────
int main() {
    Solution sol;
    vector<int> a = {1, 1, 2, 1, 1};
    cout << sol.numberOfSubarrays(a, 3) << "  (expect 2)\n";
    vector<int> b = {2, 4, 6};
    cout << sol.numberOfSubarrays(b, 1) << "  (expect 0)\n";
    vector<int> c = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    cout << sol.numberOfSubarrays(c, 2) << "  (expect 16)\n";
    return 0;
}
