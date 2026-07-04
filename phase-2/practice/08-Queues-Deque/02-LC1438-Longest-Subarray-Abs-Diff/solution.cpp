// LC1438 — Longest Subarray with |max-min| <= limit   (MEDIUM · two deques)  ·  M8 practice
// -----------------------------------------------------------------------------------------
// Variable window; validity = (windowMax - windowMin) <= limit. n<=1e5, nums[i]<=1e9.
//   URL: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// =========================================================================================
#include <bits/stdc++.h>
using namespace std;

// 1) BRUTE (oracle): every subarray, track its own max/min, keep the longest valid.
//    Time: O(n^2)   >>> boss fills first <<<
int longestSubarrayBrute(vector<int>& nums, int limit) {
    int n = nums.size(), best = 0;
    // TODO(boss): for each l, extend r, maintain running max/min, break when diff>limit.
    return best;
}

// 2) BRIDGE: brute re-derives max/min for every window. What keeps the window max in O(1)
//    as it slides? (LC239.) You need BOTH ends of validity -> TWO monotonic deques.
//    >>> your words:
//
//
// 3) OPTIMAL: maxDq (decreasing) + minDq (increasing), both holding INDICES.  O(n)
//    >>> boss writes <<<
int longestSubarray(vector<int>& nums, int limit) {
    int n = nums.size(), best = 0, l = 0;
    deque<int> maxDq, minDq;          // indices; maxDq vals decreasing, minDq vals increasing
    // TODO(boss):
    //   for r in [0,n): push r into both (pop_back to keep monotonic)
    //     while nums[maxDq.front()] - nums[minDq.front()] > limit:
    //         l++ ; pop_front any deque whose front index < l
    //     best = max(best, r - l + 1)
    return best;
}

// 4) STRESS: brute vs optimal, 20k random tiny cases.
int main() {
    srand(999);
    for (int it = 0; it < 20000; it++) {
        int n = 1 + rand() % 8;
        int limit = rand() % 6;
        vector<int> a(n);
        for (int& x : a) x = rand() % 8;        // small range -> lots of valid/invalid edges
        vector<int> b1 = a, b2 = a;
        int g = longestSubarray(b1, limit);
        int e = longestSubarrayBrute(b2, limit);
        if (g != e) {
            printf("MISMATCH limit=%d nums=[", limit);
            for (int x : a) printf("%d ", x);
            printf("]  got=%d exp=%d\n", g, e);
            return 1;
        }
    }
    printf("all 20000 stress cases passed\n");
    return 0;
}
