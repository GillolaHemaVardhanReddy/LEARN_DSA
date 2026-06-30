// LC410 — Split Array Largest Sum · Hard
// https://leetcode.com/problems/split-array-largest-sum/
// HARD GAUNTLET · P6 (Binary-Search-on-answer). Paste ONLY the Solution class. main() local.
//
// GATES: name the flavor · build your OWN hostile input · self-trace before "done".
//
//   PATTERN (name it BEFORE you code): ____________________
//   Twin of LC1011 Capacity to Ship you already AC'd — minimize-the-max via BS on the answer.
// =============================================================================
#include <bits/stdc++.h>
using namespace std;

// OPTIMAL — binary search on the ANSWER (the largest allowed subarray sum).
//   Search space: [max(nums), sum(nums)]. feasible(cap) = greedily walk, start a new subarray when
//   running sum would exceed cap, count pieces; feasible if pieces <= k. Smallest feasible cap = answer.
//   Time: O(n log(sum))   Space: O(1)
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // TODO (boss)
        return 0;
    }
};

// HOW I DERIVED BRUTE -> OPTIMAL  (The Bridge — your words)
//   Q1. The answer (the minimized largest-sum) is monotonic: if cap C works with <=k pieces, does
//       any cap > C also work? -> that monotonicity is what unlocks BS.
//   Q2. What are the TIGHTEST low/high bounds for the answer? (one element can't be split; the whole
//       array is one piece) ->
//   Q3. feasible(cap): how do you count the MINIMUM pieces needed so no piece exceeds cap? ->
//   My derivation: ->

// BRUTE ORACLE — fill FIRST. Recursively try every split point; min over splits of the max piece sum.
//   Exponential but fine for the n<=8 stress. This is the oracle.
class SolutionBrute {
public:
    int splitArray(vector<int>& nums, int k) {
        // TODO (boss): recursive try-all-splits, minimize the maximum piece.
        return 0;
    }
};

// STRESS — brute is the oracle. Meaningful once BOTH classes are filled.
int main() {
    Solution opt; SolutionBrute bru;
    // {nums..., k} encoded: last element is k
    vector<pair<vector<int>,int>> ex = {{{7,2,5,10,8},2},{{1,2,3,4,5},2},{{1,4,4},3},{{5},1}};
    for (auto& [v,k] : ex) {
        int o = opt.splitArray(v,k), r = bru.splitArray(v,k);
        printf("%d  %s\n", o, (o==r) ? "" : " <-- MISMATCH vs oracle");
    }
    unsigned seed = 410;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    for (int t = 0; t < 50000; ++t) {
        int n = 1 + rnd()%7;
        vector<int> v(n);
        for (int i=0;i<n;++i) v[i] = rnd()%10;
        int k = 1 + rnd()%n;
        if (opt.splitArray(v,k) != bru.splitArray(v,k)) {
            printf("STRESS MISMATCH k=%d on: ", k);
            for (int x:v) printf("%d ", x); printf("\n"); return 1;
        }
    }
    printf("stress: 50k cases passed\n");
    return 0;
}
