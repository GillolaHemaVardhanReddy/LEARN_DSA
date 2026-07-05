// LC231 — Power of Two   (EASY · recursion drill)  ·  M9 practice
// ---------------------------------------------------------------------
// Return true iff n == 2^x for some x >= 0.  1 = 2^0 is true; 0 & negatives false.
//   URL: https://leetcode.com/problems/power-of-two/
// =====================================================================
#include <bits/stdc++.h>
using namespace std;

// 1) RECURSION (boss fills): halve while even, base n==1.  O(log n)
//    Base:  n == 1            -> true   (2^0)
//    Guard: n <= 0 || n%2 != 0 -> false (non-positive, or an odd > 1 can't be a power of 2)
//    Else:  return isPowRec(n / 2)      (peel one factor of 2)
//    >>> boss fills first <<<

bool isPowerOfTwoBrute(int n) {
    for(int i = 0 ; i < n ; i++ ) {
        if(pow(2, i) == n) return true;
    }
    return false;
}


bool checkpower(int i , int n){
    if(i>=n) return false;
    if(pow(2, i)==n) return true;
    return checkpower(i+1, n);
}
bool isPowRec(int n) {
    return checkpower(0, n);
}

// The public method LeetCode calls. Guard positivity, then recurse.
bool isPowerOfTwo(int n) {
    return isPowRec(n);
}

// 2) BRIDGE: why the guards come BEFORE the recursive call.
//    >>> your words:
//    (a) What's the base case, and why n==1 (not n==0)?
//    (b) Why must you reject n <= 0 BEFORE recursing? (trace n=0: 0/2=0/2=0... forever)
//    (c) Why reject odd n>1 BEFORE recursing? (12 -> 6 -> 3: 3 is odd, not 1 -> stop, false)
//
//

// 3) ORACLE (correct, pre-written): the bit trick.
//    A power of two has exactly one set bit -> n & (n-1) clears it to 0.
//    Must also be > 0 (kills 0 and negatives, where the trick lies).
bool isPowOracle(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// 4) STRESS: recursion vs oracle over MANY ints incl. negatives, 0, 1, exact powers of two.
int main() {
    srand(231);

    // explicit edge cases first
    int edges[] = {0, 1, -1, 2, 3, 4, INT_MIN, INT_MAX};
    for (int n : edges) {
        if (isPowerOfTwo(n) != isPowOracle(n)) {
            printf("MISMATCH (edge) n=%d  got=%d exp=%d\n",
                   n, (int)isPowerOfTwo(n), (int)isPowOracle(n));
            return 1;
        }
    }

    for (int it = 0; it < 200000; it++) {
        int n;
        int mode = rand() % 3;
        if (mode == 0) {
            // exact power of two: 1<<k for k in [0,30]
            n = 1 << (rand() % 31);
        } else if (mode == 1) {
            // full-range random signed int (negatives, 0, big)
            n = (int)((unsigned)rand() << 16 ^ (unsigned)rand());
        } else {
            // small values around the tricky low end
            n = rand() % 41 - 20;   // [-20, 20]
        }
        if (isPowerOfTwo(n) != isPowOracle(n)) {
            printf("MISMATCH n=%d  got=%d exp=%d\n",
                   n, (int)isPowerOfTwo(n), (int)isPowOracle(n));
            return 1;
        }
    }

    printf("all power-of-two cases passed\n");
    return 0;
}
