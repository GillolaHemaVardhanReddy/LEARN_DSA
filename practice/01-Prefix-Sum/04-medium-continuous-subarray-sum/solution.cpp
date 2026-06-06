// LC 523 — Continuous Subarray Sum  (Prefix + remainder + hash, length >= 2)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // ───── YOUR CODE HERE ─────
        // map: remainder -> FIRST index. seen[0] = -1. running sum, rem = sum % k.
        // if rem seen before AND (i - firstIndex) >= 2 -> true.
        return false; // replace
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    vector<int> a = {23, 2, 4, 6, 7};
    cout << sol.checkSubarraySum(a, 6) << "  (expect 1)\n";
    vector<int> b = {23, 2, 6, 4, 7};
    cout << sol.checkSubarraySum(b, 6) << "  (expect 1)\n";
    vector<int> c = {23, 2, 6, 4, 7};
    cout << sol.checkSubarraySum(c, 13) << "  (expect 0)\n";
    return 0;
}
