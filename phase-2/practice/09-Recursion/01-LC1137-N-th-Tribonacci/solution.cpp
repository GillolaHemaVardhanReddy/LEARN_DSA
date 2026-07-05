// LC1137 — N-th Tribonacci Number   (EASY · recursion -> memoization)  ·  M9 practice
// ---------------------------------------------------------------------
// T0=0, T1=1, T2=1, T(n)=T(n-1)+T(n-2)+T(n-3).  Return T(n), 0 <= n <= 37.
//   URL: https://leetcode.com/problems/n-th-tribonacci-number/
// =====================================================================
#include <bits/stdc++.h>
using namespace std;

// 1) BRUTE: naive triple recursion — recompute every subcall from scratch.  O(3^n)
//    base: n==0 -> 0, n<=2 -> 1, else trib(n-1)+trib(n-2)+trib(n-3).
//    >>> boss fills first <<<
int tribBrute(int n) {
    if(n<=1) return n;
    if(n==2) return 1;
    return tribBrute(n-1) + tribBrute(n-2) + tribBrute(n-3);   // BRUTE = no memo (memo isn't in scope here)
}

// 2) BRIDGE: brute recomputes the same T(k) an exponential number of times.
//    Q1: where's the repeated work?  (which subcall fires again and again?)
//    Q2: what gets recomputed on every branch of the tree?
//    Q3: tool = memoization — a notepad (cache) so each T(k) is computed ONCE.
//    >>> your words:
//
//
// 3) OPTIMAL: top-down memo — check cache, compute+store, reuse.  O(n) time, O(n) space.
//    >>> boss writes <<<
int trimemo(int n , vector<int>& memo){
    if(n<=1) return n;
    if(n==2) return 1;
    if(memo[n] != -1) return memo[n];
    return memo[n] = trimemo(n-1, memo) + trimemo(n-2, memo) + trimemo(n-3, memo);
}
int trib(int n) {
    vector<int> memo(n+1, -1);
    return trimemo(n, memo);
}

// ORACLE (correct, iterative): the truth we test both boss-functions against.
int tribOracle(int n) {
    if (n == 0) return 0;
    if (n <= 2) return 1;
    int a = 0, b = 1, c = 1;   // T0, T1, T2
    for (int i = 3; i <= n; i++) {
        int nxt = a + b + c;
        a = b; b = c; c = nxt;
    }
    return c;
}

// 4) STRESS: compare BOTH boss-functions vs the oracle.
//    NOTE: tribBrute is O(3^n) — only safe for small n, so cap the brute at n <= 28.
//          The memo trib and the oracle run the full range n = 0..37.
int main() {
    // brute: capped at 28 (3^n blows up past that)
    for (int n = 0; n <= 28; n++) {
        int got = tribBrute(n);
        int exp = tribOracle(n);
        if (got != exp) {
            printf("MISMATCH (brute) n=%d  got=%d exp=%d\n", n, got, exp);
            return 1;
        }
    }
    // memo: full range 0..37
    for (int n = 0; n <= 37; n++) {
        int got = trib(n);
        int exp = tribOracle(n);
        if (got != exp) {
            printf("MISMATCH (memo) n=%d  got=%d exp=%d\n", n, got, exp);
            return 1;
        }
    }
    printf("all tribonacci cases passed\n");
    return 0;
}
