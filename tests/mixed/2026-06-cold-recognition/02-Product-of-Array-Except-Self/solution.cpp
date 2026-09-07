// LC 238 — Product of Array Except Self   ·   COLD RECOGNITION — no approach given.
// Classify the tool yourself (see problem.md), then implement. No division allowed.
// Paste ONLY the Solution class into LeetCode. main() is for local testing on onlinegdb.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // ───── YOUR CODE HERE ─────

        return {}; // replace
    }
};

// ───────── local test harness (ignore when pasting to LeetCode) ─────────
int main() {
    Solution sol;

    vector<int> a = {1, 2, 3, 4};
    for (int x : sol.productExceptSelf(a)) cout << x << " ";
    cout << "  (expect 24 12 8 6)\n";

    vector<int> b = {-1, 1, 0, -3, 3};
    for (int x : sol.productExceptSelf(b)) cout << x << " ";
    cout << "  (expect 0 0 9 0 0)\n";

    return 0;
}
