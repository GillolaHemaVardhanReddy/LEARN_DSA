// LC1696 — Jump Game VI   (MEDIUM · deque-optimized DP)  ·  M8 practice
// ---------------------------------------------------------------------
// dp[i] = nums[i] + max(dp[i-k..i-1]); answer = dp[n-1].  n,k <= 1e5.
//   URL: https://leetcode.com/problems/jump-game-vi/
// =====================================================================
#include <bits/stdc++.h>
using namespace std;

// 1) BRUTE (oracle): plain DP, inner loop scans the last k states.  O(n*k)
//    >>> boss fills first <<<
int maxResultBrute(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    // TODO(boss): for i in [1,n): dp[i] = nums[i] + max(dp[j]) for j in [max(0,i-k), i-1]
    return dp[n - 1];
}

// 2) BRIDGE: the inner "max over last k dp values" is a sliding-window max -> monotonic deque.
//    >>> your words:
//
//
// 3) OPTIMAL: deque of indices over dp, front = max in window [i-k, i-1].  O(n)
//    >>> boss writes <<<
int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    deque<int> dq;                    // indices into dp, dp-values decreasing front->back
    dq.push_back(0);
    // TODO(boss):
    //   for i in [1,n):
    //     while dq.front() < i-k : pop_front         (expire)
    //     dp[i] = nums[i] + dp[dq.front()]
    //     while dq.size() && dp[dq.back()] <= dp[i] : pop_back
    //     dq.push_back(i)
    return dp[n - 1];
}

// 4) STRESS: brute vs optimal, 20k random tiny cases.
int main() {
    srand(77);
    for (int it = 0; it < 20000; it++) {
        int n = 1 + rand() % 8;
        int k = 1 + rand() % n;
        vector<int> a(n);
        for (int& x : a) x = rand() % 21 - 10;   // negatives included
        vector<int> b1 = a, b2 = a;
        int g = maxResult(b1, k);
        int e = maxResultBrute(b2, k);
        if (g != e) {
            printf("MISMATCH k=%d nums=[", k);
            for (int x : a) printf("%d ", x);
            printf("]  got=%d exp=%d\n", g, e);
            return 1;
        }
    }
    printf("all 20000 stress cases passed\n");
    return 0;
}
