// LC 525 — Contiguous Array  (Prefix family — transform 0 -> -1, then sum == 0)
// Paste ONLY the Solution class into LeetCode. main() is for local testing on onlinegdb.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // ───── YOUR CODE HERE ─────
        // Transform: 0 -> -1, 1 -> +1. Then "equal 0s and 1s" == "subarray sum 0".
        // LONGEST (not count) -> map stores the FIRST index a running sum appeared.
        // length = current index - first index of that same running sum.
        // What single entry must the map hold before the loop (running sum 0 at "index -1")?
        int sum = 0;
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> seen;
        for(int i = 0; i<n; i++){
            sum += (nums[i] == 1) ? 1 : -1;
            if(seen.count(sum)) ans = max(ans, i-seen[sum]);
            else seen[sum] = i;
        }
        
        return ans; // replace
    }
};

// ───────── local test harness (ignore when pasting to LeetCode) ─────────
int main() {
    Solution sol;

    vector<int> a = {0, 1};
    cout << sol.findMaxLength(a) << "  (expect 2)\n";

    vector<int> b = {0, 1, 0};
    cout << sol.findMaxLength(b) << "  (expect 2)\n";

    vector<int> c = {0, 1, 1, 1, 0, 0};
    cout << sol.findMaxLength(c) << "  (expect 6)\n";

    return 0;
}
