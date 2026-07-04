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

// 2) BRIDGE: brute recomputes sums. Prefix sums make any subarray sum O(1) = P[r]-P[l].
//    Negatives kill window-shrinking, so which left endpoints are worth keeping? -> monotonic deque.
//    >>> your words:
//
//
// 3) OPTIMAL: increasing-P deque of indices; answer-pop front, monotonic-pop back.  O(n)
//    >>> boss writes <<<
int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> P(n + 1, 0);
    for (int i = 0; i < n; i++) P[i + 1] = P[i] + nums[i];
    int best = INT_MAX;
    deque<int> dq;                    // indices into P, P-values increasing front->back
    // TODO(boss):
    //   for r in [0..n]:
    //     while dq.size() && P[r]-P[dq.front()] >= k : best=min(best, r-dq.front()); pop_front
    //     while dq.size() && P[r] <= P[dq.back()]    : pop_back
    //     push_back(r)
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
