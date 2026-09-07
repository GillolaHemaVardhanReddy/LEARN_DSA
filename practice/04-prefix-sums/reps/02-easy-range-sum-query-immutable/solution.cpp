// LC 303 — Range Sum Query - Immutable  (Prefix Sum)
// Class design: precompute prefix in constructor, answer sumRange in O(1).
// ⚠️ Watch the left==0 boundary (prefix[-1] crash). Consider 1-indexed prefix (size n+1).
// Paste ONLY the NumArray class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    // ───── YOUR STATE HERE ─────
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        // ───── build prefix once ─────
        int sum = 0, n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            sum+=nums[i];
            prefix.push_back(sum);
        }
    }

    int sumRange(int left, int right) {
        // ───── O(1) using prefix; handle left==0 safely ─────
        if(left == 0) return prefix[right];
        return prefix[right] - prefix[left - 1]; // replace
    }
};

// ───────── local test harness ─────────
int main() {
    vector<int> a = {-2, 0, 3, -5, 2, -1};
    NumArray na(a);
    cout << na.sumRange(0, 2) << "  (expect 1)\n";
    cout << na.sumRange(2, 5) << "  (expect -1)\n";
    cout << na.sumRange(0, 5) << "  (expect -3)\n";
    return 0;
}
