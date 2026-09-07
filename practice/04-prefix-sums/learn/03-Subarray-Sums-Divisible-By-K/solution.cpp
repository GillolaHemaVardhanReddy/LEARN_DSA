// LC 974 — Subarray Sums Divisible by K  (Prefix family — find the right key yourself)
// Paste ONLY the Solution class into LeetCode. main() is for local testing on onlinegdb.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // ───── YOUR CODE HERE ─────
        // Same skeleton as LC560 (running total + map + tally).
        // The ONLY change is WHAT you store as the key. Derive it.
        // Hint to yourself: handle negative running totals before using them.
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> seen;
        seen[0] = 1;
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            int rem = ((sum % k) + k) % k;
            count+=seen[rem];
            seen[rem]++; 
        }
        return count; // replace
    }
};

// ───────── local test harness (ignore when pasting to LeetCode) ─────────
int main() {
    Solution sol;

    vector<int> a = {4, 5, 0, -2, -3, 1};
    cout << sol.subarraysDivByK(a, 5) << "  (expect 7)\n";

    vector<int> b = {5};
    cout << sol.subarraysDivByK(b, 9) << "  (expect 0)\n";

    return 0;
}
