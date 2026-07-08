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

// 2) BRIDGE — the three questions.
//    (1) Where's the repeated work? Brute re-scans the window to find its max and min every
//        time the window moves by one. What did the previous window already know?
//    (2) You solved "window max in O(1) as it slides" four days ago. What was it? (LC239.)
//    (3) Validity here needs BOTH ends of the window's range, not one. So how many of that
//        structure do you need, and what is each one's monotonic direction?
//
//    Then the shrink question — this is the part that actually bites:
//        when the window is invalid and you move `l` forward, how does each structure learn
//        that the element it was holding is no longer inside the window?
//        (You answered this cold on 7/08: "expiry is a POSITION question." Use that.)
//    >>> your words:
//
//
//
// 3) OPTIMAL: two monotonic deques.  O(n) time.  >>> boss writes <<<
int longestSubarray(vector<int>& nums, int limit) {
    int n = nums.size(), best = 0, l = 0;
    deque<int> maxDq, minDq;          // what do these HOLD? indices or values? decide, then comment it
    // TODO(boss):
    //   Drive with r. For each r, three things happen in some order — figure out the order:
    //     - the new element enters both deques (what gets evicted to preserve monotonicity?)
    //     - while the window is invalid, l advances (what's the invalidity test, in one line?)
    //     - record the best length
    //   Trap to pre-commit against: when l advances, which deque(s) might need a pop_front,
    //   and what is the guard condition? Write that guard BEFORE you write the loop.
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
