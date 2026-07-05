// 04 — Reverse an Array   (M9 Recursion · two-pointer recursion, work on the way DOWN)
// ---------------------------------------------------------------------------------
// Reverse in place using recursion instead of a while loop. Two pointers l, r walk
// inward; swap the ends, then recurse on the smaller inside chunk.
//
//   [1,2,3,4,5] -> [5,4,3,2,1]
//
// ⭐ The base case is the interesting bit here — it's NOT n==0. Think: when do the
//    two pointers have nothing left to swap? (they meet, or cross.)
// =================================================================================
#include <bits/stdc++.h>
using namespace std;

// THE RECIPE:
//   (1) BASE CASE?    l >= r  -> nothing left to swap, return   (meet OR cross)
//   (2) SMALLER CALL? move both pointers inward: (l+1, r-1)
//   (3) COMBINE?      swap a[l], a[r] FIRST, then recurse on the inside

void reverseRec(vector<int>& a, int l, int r) {
    if(l>=r) return;
    int temp = a[r];
    a[r] = a[l];
    a[l] = temp;
    return reverseRec(a, l+1, r-1);
}

// convenience: reverse the whole thing
void reverseArray(vector<int>& a) { if (!a.empty()) reverseRec(a, 0, (int)a.size() - 1); }

// --- ORACLE: the standard library reverse ----------------------------------------
vector<int> reverseOracle(vector<int> a) { reverse(a.begin(), a.end()); return a; }

// ---------------------------------------------------------------------------------
// STRESS TEST — recursive reverse vs std::reverse on random tiny arrays.
// ---------------------------------------------------------------------------------
int main() {
    srand(2026);
    for (int iter = 0; iter < 20000; iter++) {
        int n = rand() % 9;                    // include n=0 and n=1 edges
        vector<int> a(n);
        for (int& x : a) x = rand() % 100;
        vector<int> want = reverseOracle(a);
        vector<int> got = a; reverseArray(got);
        if (got != want) {
            printf("MISMATCH  n=%d\n", n);
            return 1;
        }
    }
    printf("all reverse cases passed (20000 random arrays, incl. empty & size-1)\n");
    return 0;
}
