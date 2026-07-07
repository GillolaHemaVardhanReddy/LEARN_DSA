// LC198 — House Robber   (MEDIUM · THE keystone "choice" recursion)  ·  M9 practice
// ---------------------------------------------------------------------
// Rob houses in a row for the MAX total money; you can NOT rob two ADJACENT houses.
//   Let f(i) = the best you can do considering houses [0..i].
//   >>> At each house you face exactly TWO choices. Name them — and for each choice,
//       which houses can you still legally rob afterward? That's your recurrence. <<<
//   base: i < 0 -> 0.   answer = f(n-1).
//   URL: https://leetcode.com/problems/house-robber/
// =====================================================================
#include <bits/stdc++.h>
using namespace std;

// 1) BRUTE: naive choice recursion, NO cache.  Exponential — the branches re-solve
//    the same i over and over (overlapping subproblems).  O(2^n)
//    >>> boss fills first <<<
int robBrute(vector<int>& nums, int i) {
    // >>> boss: base case first, then the two choices at house i, then combine them.
    return 0;                                            // placeholder so it compiles
}
int robBrute(vector<int>& nums) { return robBrute(nums, (int)nums.size() - 1); }

// 2) BRIDGE: from exponential -> linear.  Answer in your own words below.
//    Q1: in the brute's call tree, where is the SAME subproblem recomputed?
//    Q2: how many numbers pin down one call — i.e. what state indexes ONE subproblem?
//    Q3: what tool kills the repeats, and which single line makes it O(n)?
//    >>> your words:
//
//
// 3) OPTIMAL: same recurrence as brute + a cache so each index is solved once.  O(n)
//    >>> boss writes <<<
int robMemo(vector<int>& nums, int i, vector<int>& memo) {
    // >>> boss: same recursion as your brute + ONE line that reuses an already-solved index.
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
