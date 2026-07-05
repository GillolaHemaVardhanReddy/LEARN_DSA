// LC50 — Pow(x, n)   (MEDIUM · ⭐ fast exponentiation / binary power)  ·  M9 practice
// ---------------------------------------------------------------------
// Compute x^n.  -100 < x < 100,  -2^31 <= n <= 2^31-1.
//   URL: https://leetcode.com/problems/powx-n/
// =====================================================================
#include <bits/stdc++.h>
using namespace std;

// 1) BRUTE: multiply x by itself |n| times, then invert if n<0.   O(|n|)
//    >>> boss fills first <<<
//    NOTE: this TLEs on LeetCode for large |n| (up to 2^31) — that's the
//          whole motivation to find the O(log n) version below.
double myPowBrute(double x, int n) {
    // careful: -n overflows int when n == INT_MIN → widen to long long first.
    long long e = n;                 // copy exponent into a wide type
    bool neg = e < 0;
    if (neg) e = -e;                 // safe now (e is long long)
    double result = 1.0;
    // TODO(boss): multiply `result` by x, e times   (for i in [0,e): result *= x)
    //             then if (neg) result = 1.0 / result;
    return result;                   // placeholder
}

// 2) BRIDGE: linear multiply redoes work — x^n recomputes every factor from scratch.
//    Q1: where's the repeated work in multiplying x by itself |n| times?
//    Q2: what does the identity  x^n = (x^(n/2))^2  buy you? (how many multiplies
//        remain if each step HALVES the exponent instead of decrementing it?)
//    Q3: how do you handle an ODD n (one leftover x) and a NEGATIVE n (1 / x^|n|)?
//        — and why must the INT_MIN case negate through a `long`, not an `int`?
//    >>> your words:  O(n) -> O(log n) collapse because each recursion halves n
//
//
// 3) OPTIMAL: fast exponentiation — halve the exponent each call.   O(log n)
//    >>> boss writes <<<
double myPow(double x, int n) {
    long long e = n;                 // widen BEFORE any negation (INT_MIN trap)
    if (e < 0) return 1.0 / myPow(x, /* pass -e as the positive exp */ 0);  // TODO(boss): fix
    // TODO(boss): base case  e == 0 -> return 1.0
    //             half = myPow(x, e/2);
    //             return half * half * (e % 2 ? x : 1.0);
    return 1.0;                      // placeholder
}

// ---------------------------------------------------------------------
// ORACLE (correct, DO NOT edit): iterative fast-power with long long exponent.
// (Uses binary exponentiation — NOT std::pow, whose rounding differs from ours.)
double powOracle(double x, int n) {
    long long e = n;                 // widen first → INT_MIN-safe
    bool neg = e < 0;
    if (neg) e = -e;
    double result = 1.0, base = x;
    while (e > 0) {
        if (e & 1) result *= base;   // odd bit → fold in current base
        base *= base;                // square the base
        e >>= 1;                     // next bit
    }
    return neg ? 1.0 / result : result;
}

// 4) STRESS: optimal vs oracle. Doubles → compare with a tolerance, never ==.
int main() {
    // --- hardcoded edge tests ---
    struct { double x; int n; double exp; } edges[] = {
        {2.0,   0,        1.0},        // n = 0  → 1 for any x
        {-3.5,  0,        1.0},        // n = 0  → 1
        {2.0,  -2,        0.25},       // negative exponent
        {1.0,   INT_MIN,  1.0},        // INT_MIN, x=1  → 1 (negation must not overflow)
        {-1.0,  INT_MIN,  1.0},        // INT_MIN, x=-1 → 1 (even exponent)
    };
    for (auto& t : edges) {
        double got = myPow(t.x, t.n);
        if (fabs(got - t.exp) > 1e-6) {
            printf("EDGE MISMATCH x=%.4f n=%d  got=%.9g exp=%.9g\n", t.x, t.n, got, t.exp);
            return 1;
        }
    }

    // --- random stress: small magnitudes so values stay finite/representable ---
    srand(50);
    for (int it = 0; it < 20000; it++) {
        double x = (rand() % 40001) / 10000.0 - 2.0;   // x in [-2.0, 2.0]
        int n = rand() % 51 - 25;                      // n in [-25, 25]
        double got = myPow(x, n);
        double exp = powOracle(x, n);
        // relative tolerance guards against large-magnitude results (e.g. 2^25)
        double denom = max(1.0, fabs(exp));
        if (fabs(got - exp) / denom > 1e-6) {
            printf("MISMATCH x=%.6f n=%d  got=%.9g exp=%.9g\n", x, n, got, exp);
            return 1;
        }
    }
    printf("all pow cases passed\n");
    return 0;
}
