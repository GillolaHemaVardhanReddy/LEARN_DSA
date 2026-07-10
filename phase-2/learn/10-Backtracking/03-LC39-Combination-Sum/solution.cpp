// LC39 — Combination Sum   (MEDIUM · ⭐ backtracking: REUSE a choice)  ·  M10 LEARN — rep 3
// ---------------------------------------------------------------------
// Given DISTINCT integers `candidates` and a `target`, return all UNIQUE combinations
// where the chosen numbers sum to target. The SAME number may be chosen UNLIMITED times.
// Two combinations are different only if the multiset of counts differs.
//   Constraints: 1 <= n <= 30,  2 <= candidates[i] <= 40,  1 <= target <= 40, distinct.
//   URL: https://leetcode.com/problems/combination-sum/
//
// NEW IDEA vs LC46: a choice can be REUSED. The frame does not always advance.
//   Striver [L8] — https://youtu.be/OyZFFqQtu98   (watch AFTER your attempt)
// =====================================================================
#include <bits/stdc++.h>
using namespace std;

// 1) BRUTE — the oracle. NO recursion (M#9: different machinery than the optimal).
//    Idea: iterative build-up, one candidate at a time (this is what kills permutation dupes).
//      dp[t] = set of combinations summing to exactly t, using only candidates seen SO FAR.
//      dp[0] = { {} }.  For each candidate c, for t = c .. target:
//          every combo in dp[t-c], with c appended, is a combo for t.
//    Because you finish candidate c before starting c+1, [2,3] and [3,2] can't both appear.
//    Time: O(target * n * (#combos))   Space: same
vector<vector<int>> combinationSumBrute(vector<int>& candidates, int target) {
    // TODO(boss): build dp as vector<set<vector<int>>>, dp[0]={{}}, loop candidates OUTER,
    //             t INNER (t from c to target). Return dp[target] flattened to a vector.
    return {};
}

// 2) BRIDGE
//    Q1: LC46's frame advanced to d+1 after every choice. Here, after you take a 5,
//        you may take another 5. What index do you pass to the recursive call after
//        CHOOSING candidates[i]?  And what index after DECIDING TO SKIP it forever?
//    >>> your words:
//
//    Q2: if every frame looped `for (i = 0; i < n; i++)`, you'd emit both [2,3] and [3,2].
//        What single change to the loop's starting point makes each combination appear once?
//        (Say WHY it works — what ordering does it force on the output?)
//    >>> your words:
//
//    Q3: `target` shrinks as you choose. Name the base case that EMITS, and the base case
//        that ABANDONS the branch. Why is the abandoning one a *prune*, not just a guard?
//        (What would happen without it — wrong answer, or just slow?)
//    >>> your words:
//
//    Q4: un-choose. What exactly must be restored here? Is `target` one of them?
//        (Careful — think about whether you pass it by value or mutate a shared one.)
//    >>> your words:
//
// 3) OPTIMAL — backtracking, loop over choices from `start`, reuse allowed.
//    Time: O(?)   Space: O(?) (call stack + path)
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    // TODO(boss): two base cases (one emits, one abandons — your Q3).
    //             Then a loop frame from `start`: choose candidates[i] → recurse with the index
    //             your Q1 answer says → un-choose.
    return {};
}

// ---------------------------------------------------------------------
// Normalizer (DO NOT edit): sorts inside each combination, then sorts the collection.
vector<vector<int>> normalized(vector<vector<int>> v) {
    for (auto& c : v) sort(c.begin(), c.end());
    sort(v.begin(), v.end());
    return v;
}

// 4) STRESS: brute IS the oracle.
int main() {
    // --- hardcoded edges ---
    {
        vector<int> c = {2};
        auto got = normalized(combinationSum(c, 1));           // ANSWER edge: none exists
        if (!got.empty()) { printf("EDGE FAIL: target unreachable, want 0 combos, got %zu\n", got.size()); return 1; }

        auto got2 = normalized(combinationSum(c, 4));          // reuse edge: [2,2]
        auto exp2 = normalized(combinationSumBrute(c, 4));
        if (got2 != exp2 || got2.size() != 1) { printf("EDGE FAIL: single candidate reuse\n"); return 1; }
    }

    // --- random stress ---
    srand(39);
    for (int it = 0; it < 3000; it++) {
        int n = rand() % 4 + 1;                                 // n in [1,4]
        int target = rand() % 18 + 1;                           // target in [1,18]
        set<int> s;
        while ((int)s.size() < n) s.insert(rand() % 9 + 2);      // distinct, in [2,10]
        vector<int> cand(s.begin(), s.end());

        auto bru = normalized(combinationSumBrute(cand, target));
        auto opt = normalized(combinationSum(cand, target));
        if (bru != opt) {
            printf("MISMATCH it=%d target=%d cand=[", it, target);
            for (int x : cand) printf("%d ", x);
            printf("]: brute %zu vs optimal %zu\n", bru.size(), opt.size());
            return 1;
        }
    }
    printf("all combination-sum cases passed\n");
    return 0;
}
