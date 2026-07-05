// 01 — Print Patterns   (M9 Recursion · mechanics rep #1: base case + the ORDER)
// ---------------------------------------------------------------------------------
// Goal: FEEL the two moving parts — the base case (the floor that stops it) and the
// recursive call — and notice how the ORDER of "do work vs recurse" flips the output.
//
//   printNTimes(3)  -> hi hi hi
//   print1toN(5)    -> 1 2 3 4 5      (work BEFORE the call  = counts UP)
//   printNto1(5)    -> 5 4 3 2 1      (work AFTER  the call  = counts DOWN)
//
// ⭐ The whole lesson of this file: same recursion skeleton, but where you put the
//    cout (before vs after the recursive call) decides up vs down. Run it and SEE it.
// =================================================================================
#include <bits/stdc++.h>
using namespace std;

// THE RECIPE — answer in your head before writing each one:
//   (1) BASE CASE?      the smallest input you answer WITHOUT recursing (stop here)
//   (2) SMALLER CALL?   how do you shrink by one honest step toward the base
//   (3) WORK + ORDER?   do you print BEFORE the call (up) or AFTER it (down)?

// --- (a) print "hi" n times ------------------------------------------------------
void printNTimes(int n) {
    if(n==0) return;
    cout << "hi" << '\n';
    return printNTimes(n-1);
}

// --- (b) print 1,2,...,n  (work BEFORE the recursive call) -----------------------
void print1toN(int n) {
    if(n==0) return;
    print1toN(n-1);
    cout << n << '\n';
}

// --- (c) print n,n-1,...,1  (work AFTER the recursive call) ----------------------
void printNto1(int n) {
    if(n==0) return;
    cout << n << '\n';
    printNto1(n-1);
}

// ---------------------------------------------------------------------------------
// No stress test here — this rep is VISUAL. Run it, compare to EXPECTED below.
// ---------------------------------------------------------------------------------
int main() {
    cout << "printNTimes(3): "; printNTimes(3); cout << "   (expect: hi hi hi)\n";
    cout << "print1toN(5):   "; print1toN(5);   cout << "   (expect: 1 2 3 4 5)\n";
    cout << "printNto1(5):   "; printNto1(5);   cout << "   (expect: 5 4 3 2 1)\n";
    return 0;
}
