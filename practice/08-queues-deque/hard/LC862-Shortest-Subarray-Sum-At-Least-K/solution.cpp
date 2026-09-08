// LC862 — Shortest Subarray with Sum >= K   (HARD · deque over prefix sums)  ·  M8 practice
// -----------------------------------------------------------------------------------------
// Shortest non-empty subarray with sum >= k, else -1. HAS NEGATIVES (why LC209 window fails).
// n<=1e5, |nums[i]|<=1e5, k<=1e9  ->  prefix sums need LONG LONG.
//   URL: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
// =========================================================================================
#include <bits/stdc++.h>
using namespace std;

// 1) BRUTE (oracle): try every subarray, track shortest with sum>=k.  O(n^2)
//    >>> boss fills first <<<
int shortestSubarrayBrute(vector<int>& nums, int k) {
    int n = nums.size(), best = INT_MAX;
    // TODO(boss): for each l, extend r, accumulate sum (long long!), if sum>=k record r-l+1 and break inner.
    return best == INT_MAX ? -1 : best;
}

// 2) BRIDGE — this is the hard one. Earn it. Do NOT read ahead to the optimal.
//
//    (0) FIRST, the reduction — and Gate B applies, so attack it:
//        LC209 (Minimum Size Subarray Sum) is the same sentence with "all positive" added.
//        You know the O(n) sliding window for LC209. Try to reuse it here.
//        Now the HOSTILE input:  nums = [2, -1, 2], k = 3.
//        Hand-run LC209's window on it. What does it return? What's the true answer?
//        Name — in one sentence — the exact property the window relied on that negatives destroy.
//        (Write that sentence down. It is the whole reason this problem is a HARD.)
//
//    (1) Where's the repeated work? Brute re-adds the same elements. What makes any subarray
//        sum O(1)? (You're L4 on this.) Define P[] and write sum(l..r-1) in terms of P.
//
//    (2) Restate the goal in terms of P only:
//            "find r and l, l < r, with P[r] - P[l] >= k, minimizing ______"
//
//    (3) Now the insight. Fix r. You're scanning candidate left endpoints l.
//        Take two of them, i < j (so j is closer to r, giving a SHORTER subarray).
//        Suppose P[i] >= P[j].
//          - Could i EVER be the best left endpoint for this r, or for any future r' > r?
//          - Argue it in one line. (Hint: compare what each gives you — is j both shorter AND
//            at least as much sum? if so, what is i good for?)
//        That argument tells you exactly which candidates to THROW AWAY, which tells you the
//        deque's monotonic direction. Derive the direction — don't guess it.
//
//    (4) Two different pops happen at each r, for two different reasons. Name each:
//          - one pop RECORDS an answer and discards a candidate. Which end? why is it gone forever?
//          - one pop DISCARDS a candidate that is dominated (your (3) argument). Which end?
//
//    ⚠️ MAGNITUDE (your leak, fired 7/06): |nums[i]|<=1e5 and n<=1e5 -> |P| up to 1e10. And k<=1e9.
//        P is already long long below. Check every OTHER place a sum or compare happens.
//    >>> your words:
//
//
//
//
// 3) OPTIMAL: monotonic deque over prefix sums.  O(n)  >>> boss writes <<<
int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> P(n + 1, 0);
    for (int i = 0; i < n; i++) P[i + 1] = P[i] + nums[i];
    int best = INT_MAX;
    deque<int> dq;                    // holds indices into P. Direction? YOU derived it in (3).
    // TODO(boss):
    //   Loop r over [0..n]  (why n+1 iterations and not n? what does r=0 mean?)
    //   Two while-loops and a push. You named all three in bridge (4). Order them.
    //   Boundary to pre-commit: is the answer length r - dq.front(), or off by one? Prove it on
    //   a 1-element array before you submit.
    return best == INT_MAX ? -1 : best;
}

// 4) STRESS: brute vs optimal, 20k random tiny cases WITH negatives.
int main() {
    srand(2024);
    for (int it = 0; it < 20000; it++) {
        int n = 1 + rand() % 8;
        int k = 1 + rand() % 10;
        vector<int> a(n);
        for (int& x : a) x = rand() % 11 - 5;   // negatives included
        vector<int> b1 = a, b2 = a;
        int g = shortestSubarray(b1, k);
        int e = shortestSubarrayBrute(b2, k);
        if (g != e) {
            printf("MISMATCH k=%d nums=[", k);
            for (int x : a) printf("%d ", x);
            printf("]  got=%d exp=%d\n", g, e);
            return 1;
        }
    }
    printf("all 20000 stress cases passed\n");
    return 0;
}
