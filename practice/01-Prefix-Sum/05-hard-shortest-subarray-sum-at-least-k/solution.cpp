// LC 862 — Shortest Subarray with Sum at Least K  (Prefix + monotonic deque)
// STRETCH problem. Attempt, then discuss with Tommy.
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // ───── YOUR CODE HERE ─────
        int sum = 0;
        int n = nums.size();
        int len = n+1;
        vector<int> p;
        unordered_map<int, int> seen;
        int in = 0;
        for(int i = 0 ; i < n; i++ ) {
            sum += nums[i];
            p.push_back(sum);
            int rem = p[i]-k;
            // for k we need to find rem but for k+1 we should find rem-1 meaning <=rem same for k-1 should find >=rem
            while(in<=i){
                if(seen[in] >= rem){
                    len = max(len, i - in + 1);
                }
                in++;
            }
            seen[i] = rem;
        }
        if(len != n+1) return len;
        return -1; // replace
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    vector<int> a = {1};
    cout << sol.shortestSubarray(a, 1) << "  (expect 1)\n";
    vector<int> b = {1, 2};
    cout << sol.shortestSubarray(b, 4) << "  (expect -1)\n";
    vector<int> c = {2, -1, 2};
    cout << sol.shortestSubarray(c, 3) << "  (expect 3)\n";
    return 0;
}
