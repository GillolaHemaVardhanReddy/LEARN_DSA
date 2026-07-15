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

// 1) BRUTE — the oracle. BLIND enumerate + canonical dedup (M#9: no `start` index → cannot
//    share the optimal's bug). Idea: every frame loops i = 0..n-1 (reuse allowed, order-blind),
//    so it spews permutations [2,3] AND [3,2]. Then CANONICALIZE: sort each hit and drop it in a
//    `set<vector<int>>`. M#11: the dedup KEY and the STORED value must be the SAME canonical form
//    — store the sorted copy, not the raw path, or unsorted candidates leak dupes ([3,2] t=5).
//    Independent from the optimal in machinery (no start index) and state (reads a copy, never
//    mutates `candidates`).   Time: O(exp) — it's the oracle, correctness > speed.
    void combineSum(vector<int>& candidates, int target, vector<int>& chk, set<vector<int>>& ans){
        int sum = accumulate(chk.begin(), chk.end(), 0);
        if(sum >= target){
            vector<int> check(chk);
            sort(check.begin(), check.end());
            if(sum == target && !ans.contains(check)) ans.insert(check);
            return;
        }
        for(int i = 0 ; i < candidates.size() ; i++ ) {
            chk.push_back(candidates[i]);
            combineSum(candidates, target, chk, ans);
            chk.pop_back();
        }
    }
    vector<vector<int>> combinationSumBrute(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> chk;
        combineSum(candidates, target, chk, ans);
        vector<vector<int>> finalans(ans.begin(), ans.end());
        return finalans;
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
