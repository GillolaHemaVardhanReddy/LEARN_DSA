// LC 862 — Shortest Subarray with Sum at Least K  (Prefix + monotonic deque)
// STRETCH problem. Attempt, then discuss with Tommy.
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // ───── YOUR CODE HERE ─────
        // prefix P (long long, size n+1). deque of indices with increasing P.
        // front: while P[j]-P[front] >= k -> ans=min(ans, j-front), pop front.
        // back:  while P[j] <= P[back] -> pop back. then push j.
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
