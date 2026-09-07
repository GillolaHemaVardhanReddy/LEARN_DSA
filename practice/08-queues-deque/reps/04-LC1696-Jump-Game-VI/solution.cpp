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

// 2) BRIDGE — the three questions.
//    (1) Where's the repeated work? Write out the inner loop of the brute in plain English.
//        "for each i, find the ______ of the last k dp values."
//    (2) That sentence is a problem you have already solved. Name it. What was its answer?
//    (3) What's DIFFERENT here: in LC239 the window slid over a fixed input array. Here the
//        window slides over `dp` — an array you are BUILDING as you go. Does that break
//        anything? (Trace it: when you compute dp[i], is every value the deque points at
//        already final?)
//
//    Note the shape: this is a DP whose transition is a sliding-window max. That combination
//    is the whole recognition cue — bank it.
//    >>> your words:
//
//
//
// 3) OPTIMAL: deque-optimized DP.  O(n)  >>> boss writes <<<
int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    deque<int> dq;                    // holds what? over which array? which direction? comment it
    dq.push_back(0);
    // TODO(boss):
    //   for i in [1,n): three steps, and the ORDER matters more than in LC239 — think about why.
    //     - expire: which indices are no longer reachable from i? (what's the window here — is it
    //       [i-k, i-1] or [i-k, i]? get this exactly right, it's the whole boundary)
    //     - read:   dp[i] = ?
    //     - insert: what gets evicted from the back before i goes in? (<= or < ? does it matter?)
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
