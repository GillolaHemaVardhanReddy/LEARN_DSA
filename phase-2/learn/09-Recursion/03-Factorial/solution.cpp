// 03 — Factorial   (M9 Recursion · the cleanest self-similar definition)
// ---------------------------------------------------------------------------------
//   n! = n * (n-1) * ... * 1,   0! = 1
//   Self-similar:  n! = n * (n-1)!   <-- the smaller problem is the SAME problem.
//
//   fact(5) -> 120
//
// ⚠️ MAGNITUDE: factorial explodes. 21! overflows even long long. Keep n <= 20.
//    (long long max ~9.2e18;  20! = 2.4e18 fits, 21! = 5.1e19 does NOT.)
// =================================================================================
#include <bits/stdc++.h>
using namespace std;

// THE RECIPE:
//   (1) BASE CASE?    n==0 -> return 1   (empty product is 1, NOT 0)
//   (2) SMALLER CALL? (n-1)!
//   (3) COMBINE?      return n * fact(n-1)   (trust fact(n-1) hands you (n-1)!)

long long fact(int n) {
    if(n==0) return 1;
    return n * fact(n-1);
}

// --- ORACLE: iterative factorial -------------------------------------------------
long long factOracle(int n) {
    long long f = 1;
    for (int i = 2; i <= n; i++) f *= i;
    return f;
}

// ---------------------------------------------------------------------------------
// STRESS TEST — recursion vs iterative oracle, safe range n = 0..20.
// ---------------------------------------------------------------------------------
int main() {
    for (int n = 0; n <= 20; n++) {
        long long want = factOracle(n), got = fact(n);
        if (got != want) {
            printf("MISMATCH n=%d  oracle=%lld  fact=%lld\n", n, want, got);
            return 1;
        }
    }
    printf("all factorial cases passed (n = 0..20)\n");
    return 0;
}
