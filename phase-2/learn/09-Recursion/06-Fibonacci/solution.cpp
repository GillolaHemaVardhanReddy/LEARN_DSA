// 06 — Fibonacci   (M9 Recursion · ⭐ THE FORK: two calls -> the gateway to DP)
// ---------------------------------------------------------------------------------
//   fib(0)=0, fib(1)=1, fib(n)=fib(n-1)+fib(n-2)
//   fib: 0 1 1 2 3 5 8 13 21 34 ...
//
// This is the FIRST recursion that forks into TWO calls. That fork builds a whole
// TREE of calls — and that tree is where the O(2^n) catastrophe lives. Feel the pain
// here, then kill it with a notepad (memoization). That kill IS what DP is.
// =================================================================================
#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------------------------------
// 1) BRUTE — naive double recursion.   Time: O(2^n)   Space: O(n) stack
//    RECIPE:  base n<=1 -> return n;   else return fibBrute(n-1)+fibBrute(n-2)
//    >>> BOSS WRITES THIS FIRST. <<<
// ---------------------------------------------------------------------------------
long long fibBrute(int n) {
    if(n<=1) return n;
    return fibBrute(n-1) + fibBrute(n-2); // placeholder — replace me
}

// ---------------------------------------------------------------------------------
// 2) THE BRIDGE — brute -> optimal (answer in plain words before coding memo):
//    Q1. Where is the repeated work?  (draw fib(5)'s call tree — how many times is
//        fib(2) computed? fib(3)?)
//    Q2. What exactly gets recomputed each time?  (the SAME fib(k) over and over,
//        exponentially many times — nothing changes between those identical calls.)
//    Q3. What tool kills it?  (a NOTEPAD: compute each fib(k) ONCE, store it, reuse.
//        = memoization. This is recursion + a cache = top-down DP.)
//    >>> your derivation in your words:
//
//
// ---------------------------------------------------------------------------------
// 3) OPTIMAL — memoized recursion.   Time: O(n)   Space: O(n) cache + O(n) stack
//    RECIPE:  if memo[n] already set -> return it;
//             else compute fib(n-1)+fib(n-2), STORE in memo[n], return it.
//    >>> boss writes after brute + bridge. <<<
// ---------------------------------------------------------------------------------
long long fibMemo(int n, vector<long long>& memo) {
    if(n<=1) return n;
    if(memo[n] != -1) return memo[n];
    return memo[n] = fibBrute(n-1, memo) + fibBrute(n-2, memo);
}
long long fibMemo(int n) { vector<long long> memo(n + 1, -1); return fibMemo(n, memo); }

// --- ORACLE: iterative fib (the truth) -------------------------------------------
long long fibOracle(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) { long long c = a + b; a = b; b = c; }
    return b;
}

// ---------------------------------------------------------------------------------
// STRESS TEST — brute + memo vs oracle. n capped at 25 because BRUTE is O(2^n):
// 2^25 ~ 33M calls is already the edge of "instant". FEEL that — it's the point.
// (Your memo version could go to n=90 easily; brute cannot. That gap is the lesson.)
// ---------------------------------------------------------------------------------
int main() {
    for (int n = 0; n <= 25; n++) {
        long long want = fibOracle(n);
        long long b = fibBrute(n);
        long long m = fibMemo(n);
        if (b != want || m != want) {
            printf("MISMATCH n=%d  oracle=%lld  brute=%lld  memo=%lld\n", n, want, b, m);
            return 1;
        }
    }
    printf("all fib cases passed (n = 0..25; brute AND memo match oracle)\n");
    printf("now try fibMemo(90) — it's instant. try fibBrute(90) — don't, it never finishes. THAT is why DP exists.\n");
    return 0;
}
