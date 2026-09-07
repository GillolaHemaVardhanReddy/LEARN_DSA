// LC 560 — Subarray Sum Equals K  (Prefix Sum + Hash Map of complements)
// Paste ONLY the Solution class into LeetCode. main() is for local testing on onlinegdb.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // ───── YOUR CODE HERE ─────
        // running total + unordered_map<int,int> seen;  pre-load seen[0]=1.
        // For each element: add to running; count += seen[running - k]; then seen[running]++.
        // Remember: this is a TALLY (count++), not a shortest/longest window.
        int n = nums.size();
        int count = 0;
        vector<int> prefix;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            prefix.push_back(sum);
        }
        unordered_map<int, int> seen;
        seen[0] = 1;
        for(int right = 0; right<n; right++){
            count += seen[prefix[right] - k];
            seen[prefix[right]] += 1;
        }

        return count; // replace
    }
};

// ───────── local test harness (ignore when pasting to LeetCode) ─────────
int main() {
    Solution sol;

    vector<int> a = {1, 1, 1};
    cout << sol.subarraySum(a, 2) << "  (expect 2)\n";

    vector<int> b = {1, 2, 3};
    cout << sol.subarraySum(b, 3) << "  (expect 2)\n";

    vector<int> c = {3, 4, 7};
    cout << sol.subarraySum(c, 7) << "  (expect 2)\n";

    vector<int> d = {-1, -1, 1};      // negatives
    cout << sol.subarraySum(d, 0) << "  (expect 1)\n";

    return 0;
}
