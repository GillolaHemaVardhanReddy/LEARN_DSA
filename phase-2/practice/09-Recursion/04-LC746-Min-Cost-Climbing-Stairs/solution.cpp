// LC746 — Min Cost Climbing Stairs   (EASY · recursion -> memo DP)  ·  M9 practice
// ---------------------------------------------------------------------
// f(i) = min cost to REACH the top starting FROM step i = cost[i] + min(f(i+1), f(i+2)).
// base f(i) = 0 when i >= n (already at/past the top).  answer = min(f(0), f(1)).
//   URL: https://leetcode.com/problems/min-cost-climbing-stairs/
// =====================================================================
#include <bits/stdc++.h>
using namespace std;

// 1) BRUTE: naive recursion of f(i), NO cache.  Exponential (~2^n).
//    >>> boss fills first <<<
int fBrute(int i, vector<int>& cost) {
    int n = cost.size();
    // TODO(boss): base case -> if (i >= n) return 0;
    // TODO(boss): return cost[i] + min( fBrute(i+1,cost), fBrute(i+2,cost) );
    return 0;   // placeholder so it compiles
}
int minCostClimbingStairsBrute(vector<int>& cost) {
    return min(fBrute(0, cost), fBrute(1, cost));
}

// 2) BRIDGE: brute -> optimal, the 3 questions.
//    (1) repeated subproblems?  fBrute(i) is called from both i-1 and i-2 -> same i recomputed
//        over and over -> the exponential blow-up.
//    (2) what's recomputed each call?  the WHOLE subtree under index i, every time we reach i.
//    (3) the tool that kills it?  memoize: cache f(i) keyed by the step index i (sentinel -1).
//    >>> your words:
//
//
// 3) OPTIMAL: same recurrence, but cache f(i).  Each index solved once -> O(n).
//    >>> boss writes <<<
int fMemo(int i, vector<int>& cost, vector<int>& memo) {
    int n = cost.size();
    // TODO(boss): if (i >= n) return 0;
    // TODO(boss): if (memo[i] != -1) return memo[i];
    // TODO(boss): return memo[i] = cost[i] + min( fMemo(i+1,cost,memo), fMemo(i+2,cost,memo) );
    return 0;   // placeholder so it compiles
}
int minCostClimbingStairsMemo(vector<int>& cost) {
    int n = cost.size();
    vector<int> memo(n, -1);
    return min(fMemo(0, cost, memo), fMemo(1, cost, memo));
}

// ORACLE (correct, do not touch): iterative bottom-up DP.  dp[i] = min cost to REACH top from i.
int minCostOracle(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n + 2, 0);          // dp[n] = dp[n+1] = 0 (at/past the top)
    for (int i = n - 1; i >= 0; i--)
        dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
    return min(dp[0], dp[1]);
}

// 4) STRESS: brute + memo vs oracle, random small cost arrays.
int main() {
    srand(746);
    for (int it = 0; it < 20000; it++) {
        int n = 2 + rand() % 9;                 // n in [2,10]
        vector<int> cost(n);
        for (int& x : cost) x = rand() % 21;    // values in [0,20]
        vector<int> c1 = cost, c2 = cost, c3 = cost;
        int b = minCostClimbingStairsBrute(c1);
        int m = minCostClimbingStairsMemo(c2);
        int o = minCostOracle(c3);
        if (b != o || m != o) {
            printf("MISMATCH cost=[");
            for (int x : cost) printf("%d ", x);
            printf("]  brute=%d memo=%d oracle=%d\n", b, m, o);
            return 1;
        }
    }
    printf("all min-cost cases passed\n");
    return 0;
}
