// LC198 — House Robber   (MEDIUM · THE keystone "choice" recursion)  ·  M9 practice
// ---------------------------------------------------------------------
// f(i) = max money robbing houses [0..i], can't rob two ADJACENT.
//   at each house: ROB it (nums[i] + f(i-2))  OR  SKIP it (f(i-1))  -> MAX.
//   base: i < 0 -> 0.   answer = f(n-1).
//   THIS is the canonical DP "choice" template — every take-vs-skip DP is this.
//   URL: https://leetcode.com/problems/house-robber/
// =====================================================================
#include <bits/stdc++.h>
using namespace std;

// 1) BRUTE: naive choice recursion. rob(i) = max(nums[i]+rob(i-2), rob(i-1)).
//    base i<0 -> 0.  Exponential — the two branches re-solve the same i over
//    and over (overlapping subproblems).  O(2^n)
//    >>> boss fills first <<<
int robBrute(vector<int>& nums, int i) {
    // TODO(boss):
    //   if (i < 0) return 0;
    //   int robIt  = nums[i] + robBrute(nums, i - 2);   // take, jump the neighbor
    //   int skipIt = robBrute(nums, i - 1);             // skip, look left
    //   return max(robIt, skipIt);
    return 0;                                            // placeholder so it compiles
}
int robBrute(vector<int>& nums) { return robBrute(nums, (int)nums.size() - 1); }

// 2) BRIDGE: from exponential -> linear.
//    Q1: where's the repeated work?  (robBrute(i-2) & robBrute(i-1) both recompute
//        the same smaller i's — the tree overlaps massively.)
//    Q2: what state indexes ONE subproblem?  (just the index i — nothing else.)
//    Q3: what tool kills the repeats?  (memoize: cache the answer per i, sentinel -1.)
//    NOTE: this "max of ROB-vs-SKIP" is the canonical DP choice template. Learn it once,
//          reuse it for every take/skip DP (paint house, delete-and-earn, ...).
//    >>> your words:
//
//
// 3) OPTIMAL: memoized rob. cache[i] holds f(i) once computed, -1 = not yet.  O(n)
//    >>> boss writes <<<
int robMemo(vector<int>& nums, int i, vector<int>& memo) {
    if (i < 0) return 0;
    // TODO(boss):
    //   if (memo[i] != -1) return memo[i];
    //   int robIt  = nums[i] + robMemo(nums, i - 2, memo);
    //   int skipIt = robMemo(nums, i - 1, memo);
    //   return memo[i] = max(robIt, skipIt);
    return 0;                                           // placeholder so it compiles
}
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> memo(n, -1);
    return robMemo(nums, n - 1, memo);
}

// ---- ORACLE (correct, DON'T touch): iterative rolling DP. This is the truth. ----
//   prev2 = f(i-2), prev1 = f(i-1); f(i) = max(nums[i]+prev2, prev1).
int robOracle(vector<int>& nums) {
    int prev2 = 0, prev1 = 0;               // f(-2), f(-1)
    for (int x : nums) {
        int cur = max(x + prev2, prev1);    // ROB x  vs  SKIP x
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

// 4) STRESS: brute + memo vs oracle, random small arrays.
int main() {
    srand(198);
    for (int it = 0; it < 20000; it++) {
        int n = 1 + rand() % 12;            // n in [1,12]
        vector<int> a(n);
        for (int& x : a) x = rand() % 21;   // values in [0,20]
        vector<int> b1 = a, b2 = a, b3 = a;
        int truth = robOracle(b1);
        int gBrute = robBrute(b2);
        int gMemo  = rob(b3);
        if (gBrute != truth || gMemo != truth) {
            printf("MISMATCH nums=[");
            for (int x : a) printf("%d ", x);
            printf("]  oracle=%d brute=%d memo=%d\n", truth, gBrute, gMemo);
            return 1;
        }
    }
    printf("all house-robber cases passed\n");
    return 0;
}
