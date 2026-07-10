// LC46 — Permutations   (MEDIUM · ⭐ backtracking: loop-over-choices)  ·  M10 LEARN — rep 2
// ---------------------------------------------------------------------
// Given an array of DISTINCT integers, return ALL possible permutations, in any order.
//   Constraints: 1 <= n <= 6,  -10 <= nums[i] <= 10,  all values unique.
//   URL: https://leetcode.com/problems/permutations/
//
// ⚠️ THIS IS THE M#8 RE-TEST — the `pick`-flag bug (2026-07-10) in a shape where a
//    boolean CANNOT survive. Rule for this file: ZERO flag parameters threaded down.
//    A frame owns its own choice. choose → explore → un-choose, three visible lines.
// =====================================================================
#include <bits/stdc++.h>
using namespace std;

// 1) BRUTE — the oracle. Must be built a DIFFERENT WAY than the optimal (M#9).
//    Idea: sort the array, then walk std::next_permutation until it wraps.
//    No recursion anywhere in here — that's the whole point.
//    Time: O(n! * n)   Space: O(n! * n) for the answer
vector<vector<int>> permuteBrute(vector<int>& nums) {
    // TODO(boss): sort a copy, then do-while(next_permutation(...)) collecting each arrangement.
    return {};
}

// 2) BRIDGE — this is NOT about speed (both ways emit all n! permutations).
//    It's about the SHAPE of a frame when a slot has more than two choices.
//    Q1: in LC78 each index had exactly 2 branches (in / out), so you wrote two
//        recursive calls in a row. Slot 0 of a permutation has n choices.
//        How many recursive calls does frame 0 make, and what controls that number?
//    >>> your words:
//
//    Q2: LC78's frame was identified by an INDEX i ("am I taking nums[i]?").
//        Here a frame is identified by a SLOT ("what goes in position d?").
//        What does a frame need to know to avoid re-using a number already placed?
//        (Name the state. Don't name the data structure yet.)
//    >>> your words:
//
//    Q3: your invariant, from LC78, verbatim:
//          "if we go to next call with a state and come back then we should have
//           same state of sett"
//        You now have TWO pieces of state to restore, not one. Name both, and say
//        exactly where each un-choose line goes.
//    >>> your words:
//
// 3) OPTIMAL — backtracking, loop over choices.
//    Time: O(?)   Space: O(?) (call stack + path + whatever tracks "already used")
vector<vector<int>> permute(vector<int>& nums) {
    // TODO(boss): base case = path is full → emit.
    //             otherwise: for each unused candidate → choose → explore → un-choose.
    return {};
}

// ---------------------------------------------------------------------
// Normalizer (DO NOT edit): sorts the collection so emit-order can't cause a
// false mismatch. Does NOT sort inside a permutation — order IS the answer here.
vector<vector<int>> normalized(vector<vector<int>> v) {
    sort(v.begin(), v.end());
    return v;
}

// 4) STRESS: brute IS the oracle. Random distinct arrays, brute vs optimal.
int main() {
    // --- hardcoded edges ---
    {
        vector<int> one = {7};                      // size-1: expect exactly {{7}}
        auto got = normalized(permute(one));
        auto exp = normalized(permuteBrute(one));
        if (got != exp || (int)got.size() != 1) {
            printf("EDGE FAIL n=1: got %zu permutations, want 1\n", got.size());
            return 1;
        }
    }

    // --- random stress ---
    srand(46);
    int fact[7] = {1, 1, 2, 6, 24, 120, 720};
    for (int it = 0; it < 20000; it++) {
        int n = rand() % 6 + 1;                     // n in [1,6]
        vector<int> pool = {-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10};
        random_shuffle(pool.begin(), pool.end());
        vector<int> nums(pool.begin(), pool.begin() + n);   // distinct by construction

        auto bru = normalized(permuteBrute(nums));
        auto opt = normalized(permute(nums));
        if ((int)opt.size() != fact[n]) {
            printf("COUNT MISMATCH n=%d: got %zu, want %d\n", n, opt.size(), fact[n]);
            return 1;
        }
        if (bru != opt) {
            printf("MISMATCH n=%d (it=%d): brute %zu vs optimal %zu\n",
                   n, it, bru.size(), opt.size());
            return 1;
        }
    }
    printf("all permutation cases passed\n");
    return 0;
}
