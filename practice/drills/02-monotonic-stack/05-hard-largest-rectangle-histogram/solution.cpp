// LC84 — Largest Rectangle in Histogram · Hard
// https://leetcode.com/problems/largest-rectangle-in-histogram/
// DRILL 02 · P5 (HARD). Paste ONLY the Solution class into LeetCode. main() is local.
//
// GATES: name the flavor · build your OWN hostile input · self-trace before "done".
//
//   PATTERN (name it BEFORE you code): ____________________
//   Hint to yourself: for each bar as the LIMITING height, the rectangle stretches left & right
//   until it hits a SHORTER bar. So per bar you need nearest-smaller-to-LEFT and nearest-smaller-
//   to-RIGHT -> a monotonic-INCREASING index stack gives both in O(n). (Sentinel 0 at the end flushes.)
// =============================================================================
#include <bits/stdc++.h>
using namespace std;

// OPTIMAL — monotonic-increasing index stack. A shorter incoming bar CLOSES the taller bars it
//   pops: for a popped bar h, right boundary = i, left boundary = the new top → area = h*(i-left-1).
//   Idea: ____      Time: O(n)   Space: O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // TODO (boss)
        return 0;
    }
};

// HOW I DERIVED BRUTE -> OPTIMAL  (The Bridge — your words)
//   Q1. Fix bar i as the shortest in its rectangle. How far LEFT and RIGHT can it stretch, and
//       what STOPS it on each side? ->
//   Q2. The brute re-scans out from every bar (O(n^2)). When a SHORTER bar appears, which earlier
//       bars are now permanently bounded on their RIGHT? ->
//   Q3. Monotonic-increasing index stack: when you pop bar h because heights[i] < heights[top],
//       what's its right boundary, its left boundary, and the area? ->
//   My derivation: ->

// BRUTE ORACLE — fill FIRST. For each bar, expand left & right while >= its height; area = h*width. O(n^2).
class SolutionBrute {
public:
    int largestRectangleArea(vector<int>& h) {
        // TODO (boss): the obvious expand-from-each-bar version — oracle.
        return 0;
    }
};

// STRESS — brute is the oracle. Meaningful once BOTH classes are filled.
int main() {
    Solution opt; SolutionBrute bru;
    vector<vector<int>> ex = {{2,1,5,6,2,3}, {2,4}, {0}, {5,5,5}, {6,2,5,4,5,1,6}};
    for (auto v : ex) {
        int o = opt.largestRectangleArea(v), r = bru.largestRectangleArea(v);
        printf("%d  %s\n", o, (o == r) ? "" : " <-- MISMATCH vs oracle");
    }
    unsigned seed = 84;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    for (int t = 0; t < 100000; ++t) {
        int n = 1 + rnd() % 8;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) v[i] = rnd() % 6;  // small heights incl 0 -> ties + zero-height
        if (opt.largestRectangleArea(v) != bru.largestRectangleArea(v)) {
            printf("STRESS MISMATCH on: ");
            for (int x : v) printf("%d ", x);
            printf("\n"); return 1;
        }
    }
    printf("stress: 100k cases passed\n");
    return 0;
}
