// LC239 — Sliding Window Maximum   (HARD)  ·  M8 Queues & Deque · monotonic deque GATE
// -----------------------------------------------------------------------------------
// "max of EVERY window of size k."   n<=1e5,  k<=n,  nums[i] in [-1e4, 1e4].
// Return an array: the maximum of each contiguous window of length k, left->right.
//
//   nums=[1,3,-1,-3,5,3,6,7], k=3  ->  [3,3,5,5,6,7]
//
// REAL LeetCode signature:  vector<int> maxSlidingWindow(vector<int>& nums, int k)
//   URL: https://leetcode.com/problems/sliding-window-maximum/
// ===================================================================================
#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------------------------
// 1) BRUTE  (the oracle).  Idea: for each window start, scan all k and take max.
//    Time:  O(n*k)      Space: O(1) extra
//    >>> BOSS FILLS THIS FIRST. <<<
// ---------------------------------------------------------------------------
vector<int> maxSlidingWindowBrute(vector<int>& nums, int k) {
    vector<int> ans;
    // TODO(boss): for each window [i .. i+k-1], find the max, push it.
    return ans;
}

// ---------------------------------------------------------------------------
// 2) THE BRIDGE — how brute -> optimal (answer in plain words before coding):
//    Q1. Where is the repeated work? (each window re-scans k elements; overlap
//        between consecutive windows is k-1 elements re-examined every step.)
//    Q2. When the window slides, what do we actually need to recompute?
//    Q3. What tool kills it? A shortlist of live candidates kept DECREASING, so
//        the front is always the max -> monotonic DEQUE (twin of monotonic stack).
//    >>> your derivation in your words:
//
//
// ---------------------------------------------------------------------------
// 3) OPTIMAL — monotonic deque.  Time: O(n) amortized   Space: O(k)
//    >>> boss writes after brute + bridge. <<<
// ---------------------------------------------------------------------------
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    // TODO(boss): deque of INDICES, values decreasing front->back.
    //   expire left (front <= i-k) · enter right (pop_back while smaller) · read front when window full
    return ans;
}

// ---------------------------------------------------------------------------
// 4) STRESS TEST — brute (oracle) vs optimal on random tiny inputs.
// ---------------------------------------------------------------------------
int main() {
    srand(12345);
    for (int iter = 0; iter < 20000; iter++) {
        int n = 1 + rand() % 8;
        int k = 1 + rand() % n;
        vector<int> a(n);
        for (int& x : a) x = rand() % 11 - 5;      // small range to force ties
        vector<int> b1 = a, b2 = a;
        vector<int> got = maxSlidingWindow(b1, k);
        vector<int> exp = maxSlidingWindowBrute(b2, k);
        if (got != exp) {
            printf("MISMATCH  k=%d  nums=[", k);
            for (int x : a) printf("%d ", x);
            printf("]\n  got: "); for (int x : got) printf("%d ", x);
            printf("\n  exp: "); for (int x : exp) printf("%d ", x);
            printf("\n");
            return 1;
        }
    }
    printf("all %d stress cases passed\n", 20000);
    return 0;
}
