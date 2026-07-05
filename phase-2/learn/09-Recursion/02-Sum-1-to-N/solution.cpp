// 02 — Sum of 1..N   (M9 Recursion · the TWO SHAPES: parameterised vs functional)
// ---------------------------------------------------------------------------------
// Compute 1 + 2 + ... + n, TWO ways, so both shapes live in your hands:
//
//   PARAMETERISED — carry the answer DOWN as an argument; base case USES it.
//   FUNCTIONAL    — build the answer UP via the return value (leap-of-faith style).
//
//   sumParam(5, 0)  -> 15        sumFunc(5) -> 15
// =================================================================================
#include <bits/stdc++.h>
using namespace std;

// THE RECIPE:
//   (1) BASE CASE?    n==0 (nothing left to add)
//   (2) SMALLER CALL? n-1
//   (3) COMBINE?      param: pass sum+n DOWN, print/return at base
//                     func:  return n + f(n-1)  (trust f(n-1) is correct)

// --- PARAMETERISED: accumulate on the way DOWN, return the carried acc at base ----
long long sumParam(int i, long long acc) {
    if(i==0) return acc;
    return sumParam(i-1, acc+i);
}

// --- FUNCTIONAL: build on the way UP -------------------------------------------
long long sumFunc(int n) {
    if(n==0) return 0;
    return n + sumFunc(n-1); 
}

// --- ORACLE (the truth to test against): plain iterative sum ---------------------
long long sumOracle(int n) {
    long long s = 0;
    for (int i = 1; i <= n; i++) s += i;
    return s;
}

// ---------------------------------------------------------------------------------
// STRESS TEST — both recursive shapes vs the iterative oracle.
// ---------------------------------------------------------------------------------
int main() {
    for (int n = 0; n <= 2000; n++) {
        long long want = sumOracle(n);
        long long a = sumParam(n, 0);
        long long b = sumFunc(n);
        if (a != want || b != want) {
            printf("MISMATCH n=%d  oracle=%lld  param=%lld  func=%lld\n", n, want, a, b);
            return 1;
        }
    }
    printf("all sum cases passed (n = 0..2000, both shapes)\n");
    return 0;
}
