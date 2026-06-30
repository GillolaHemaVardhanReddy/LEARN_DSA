// LC42 — Trapping Rain Water · Hard
// https://leetcode.com/problems/trapping-rain-water/
// HARD GAUNTLET · P2 (Two-Pointer / stack). Paste ONLY the Solution class into LeetCode. main() local.
//
// GATES: name the flavor · build your OWN hostile input · self-trace before "done".
//
//   PATTERN (name it BEFORE you code): ____________________
//   Hint to yourself: water over bar i = min(maxLeftWall, maxRightWall) - height[i]  (clamp >=0).
// =============================================================================
#include <bits/stdc++.h>
using namespace std;

// OPTIMAL — two pointers from both ends. Keep leftMax / rightMax. The SHORTER side is the certain
//   one: if height[l] < height[r], left's water is fixed by leftMax (a taller right wall exists) →
//   add leftMax-height[l], move l. Else mirror on the right.   Time: O(n)   Space: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        // TODO (boss)
        return 0;
    }
};

// HOW I DERIVED BRUTE -> OPTIMAL  (The Bridge — your words)
//   Q1. For a single bar i, what exactly decides the water level above it? (two walls) ->
//   Q2. The brute recomputes maxLeft & maxRight by re-scanning for EVERY i (O(n^2)). What repeated
//       work is that, and how could you know each side's max in O(1)? ->
//   Q3. Two-pointer: when height[l] < height[r], WHY is the left side's water already certain even
//       though you haven't seen all the bars on the right? ->
//   My derivation: ->

// BRUTE ORACLE — fill FIRST. For each i: scan left for max, scan right for max, add
//   max(0, min(L,R) - height[i]). O(n^2). This is the stress oracle.
class SolutionBrute {
public:
    int trap(vector<int>& h) {
        // TODO (boss): the obvious per-bar two-wall scan.
        return 0;
    }
};

// STRESS — brute is the oracle. Meaningful once BOTH classes are filled.
int main() {
    Solution opt; SolutionBrute bru;
    vector<vector<int>> ex = {{0,1,0,2,1,0,1,3,2,1,2,1}, {4,2,0,3,2,5}, {0}, {5}, {3,2,1}, {1,2,3}};
    for (auto v : ex) {
        int o = opt.trap(v), r = bru.trap(v);
        printf("%d  %s\n", o, (o == r) ? "" : " <-- MISMATCH vs oracle");
    }
    unsigned seed = 42;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    for (int t = 0; t < 100000; ++t) {
        int n = 1 + rnd() % 10;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) v[i] = rnd() % 7;  // small heights incl 0 -> wells + flats
        if (opt.trap(v) != bru.trap(v)) {
            printf("STRESS MISMATCH on: ");
            for (int x : v) printf("%d ", x);
            printf("\n"); return 1;
        }
    }
    printf("stress: 100k cases passed\n");
    return 0;
}
