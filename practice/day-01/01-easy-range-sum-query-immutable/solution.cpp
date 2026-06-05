// LC 303 — Range Sum Query - Immutable   ·   COLD — classify it yourself (see problem.md).
// This one is a CLASS design: precompute in the constructor, answer queries in sumRange.
// Paste ONLY the NumArray class into LeetCode. main() is for local testing on onlinegdb.

#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    // ───── YOUR STATE HERE (what do you precompute?) ─────

    NumArray(vector<int>& nums) {
        // ───── build your precomputed structure once ─────
    }

    int sumRange(int left, int right) {
        // ───── answer in O(1) using what you precomputed ─────
        return 0; // replace
    }
};

// ───────── local test harness (ignore when pasting to LeetCode) ─────────
int main() {
    vector<int> a = {-2, 0, 3, -5, 2, -1};
    NumArray na(a);
    cout << na.sumRange(0, 2) << "  (expect 1)\n";
    cout << na.sumRange(2, 5) << "  (expect -1)\n";
    cout << na.sumRange(0, 5) << "  (expect -3)\n";
    return 0;
}
