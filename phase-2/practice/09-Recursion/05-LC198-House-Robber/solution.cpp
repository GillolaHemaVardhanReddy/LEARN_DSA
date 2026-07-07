// LC198 — House Robber   (MEDIUM · THE keystone "choice" recursion)  ·  M9 practice
// ---------------------------------------------------------------------
// Rob houses in a row for the MAX total money; you can NOT rob two ADJACENT houses.
//   Let f(i) = best money if we TAKE house i and continue forward.
//   >>> BOSS'S RECURRENCE (self-derived):  f(i) = nums[i] + max( f(i+2), f(i+3) )
//       base: i >= n -> 0.   answer = max(f(0), f(1)).
//   WHY i+2 OR i+3, never bigger:  values are NON-NEGATIVE (0..400). Take i, then the
//   next take is i+2 (obvious non-adjacent) or i+3 (needed by cases like [2,1,1,2] where
//   the winning pair is index 0 & 3). A gap of 4+ is never optimal — the skipped middle
//   house is free money (non-adjacent to both neighbors, nums>=0), so you'd just take it.
//   ⚠ This lens RELIES on nums>=0; the canonical skip-or-take lens does not.
//   URL: https://leetcode.com/problems/house-robber/
// =====================================================================
#include <bits/stdc++.h>
using namespace std;

// 1) BRUTE: boss's always-take recurrence, NO cache.  Exponential — f(i) is re-solved
//    from many callers (overlapping subproblems).  O(2^n)
int robBrute(vector<int>& nums, int i) {
    if (i >= (int)nums.size()) return 0;
    return nums[i] + max(robBrute(nums, i + 2), robBrute(nums, i + 3)); // TAKE i, next take = i+2 or i+3
}
int robBrute(vector<int>& nums) { return max(robBrute(nums, 0), robBrute(nums, 1)); }

// 2) BRIDGE: from exponential -> linear.  (boss's words)
//    Q1: the SAME index i is reached by many different jump-paths from the left, so the
//        whole subtree under i is recomputed every time -> the exponential blow-up.
//    Q2: ONE number pins a subproblem — the index i. Nothing else. -> memo is a 1-D array.
//    Q3: memoize. The line `if (memo[i] != -1) return memo[i];` hands back a solved index
//        instead of re-exploring it, collapsing 2^n into O(n) (each index solved once).
//
// 3) OPTIMAL: same recurrence + cache f(i).  Each index solved once -> O(n).
int robMemo(vector<int>& nums, int i, vector<int>& memo) {
    if (i >= (int)nums.size()) return 0;
    if (memo[i] != -1) return memo[i];
    return memo[i] = nums[i] + max(robMemo(nums, i + 2, memo), robMemo(nums, i + 3, memo));
}
int rob(vector<int>& nums) {
    vector<int> memo(nums.size(), -1);
    return max(robMemo(nums, 0, memo), robMemo(nums, 1, memo));
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
