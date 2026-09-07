// LC90 — Subsets II   (MEDIUM · ⭐ backtracking: the DUPLICATE-SKIP rule)  ·  M10 LEARN — rep 4
// ---------------------------------------------------------------------
// Given an integer array `nums` that MAY CONTAIN DUPLICATES, return all possible
// subsets (the power set). The solution set must NOT contain duplicate subsets.
//   Constraints: 1 <= n <= 10,  -10 <= nums[i] <= 10.
//   URL: https://leetcode.com/problems/subsets-ii/
//
// NEW IDEA vs LC78: the input can repeat a value. [1,2,2] has 6 distinct subsets, not 8.
//   Striver [L11] — https://youtu.be/RIn3gOkbhQE   (watch AFTER your attempt)
// =====================================================================
#include <bits/stdc++.h>
using namespace std;

// 1) BRUTE — the oracle. NO recursion (M#9: different machinery than the optimal).
//    Idea: bitmask over all 2^n masks (LC78's brute), build each subset, SORT it,
//          and drop it into a std::set<vector<int>> to dedupe. Flatten the set.
//    This dedupes by brute force AFTER the fact — the optimal must dedupe DURING the walk.
//    Time: O(n * 2^n * log)   Space: O(n * 2^n)
    void subsetsRec(vector<int>& nums, set<vector<int>>& ans, vector<int>& chk, int start){
        if(start >= nums.size()){
            vector<int> check(chk.begin(), chk.end());
            sort(check.begin(), check.end());
            ans.insert(check);
            return;
        }
        for(int i = start; i < nums.size(); i++) {
            chk.push_back(nums[i]);
            subsetsRec(nums, ans, chk, i+1);
            chk.pop_back();
            subsetsRec(nums, ans, chk, i+1);
        }
    }
    vector<vector<int>> subsetsWithDupBrute(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> chk;
        subsetsRec(nums, ans, chk, 0);   
        vector<vector<int>> finalans(ans.begin(), ans.end());
        return finalans;
    }

// 2) BRIDGE
//    Q1: hand-run [1,2,2] with your LC78 pick/not-pick recursion (do it on paper, all 8 leaves).
//        Write down the 8 subsets it emits. Which pairs are duplicates of each other?
//    >>> your words:
//
//    Q2: look at the duplicate pairs. In the decision tree, the two copies of `2` are at
//        DIFFERENT DEPTHS (index 1 and index 2). Describe, in one sentence, the situation
//        that produces a duplicate: "a duplicate is born when ___."
//    >>> your words:
//
//    Q3: convert LC78's two-branch frame into a LOOP frame (like LC46/LC39: `for i = start..n-1`).
//        In a loop frame, "skip nums[i]" isn't a branch — it's just the NEXT iteration.
//        Now: at ONE loop level, if nums[i] == nums[i-1], should you recurse on it? Why not?
//        And why is `i > start` (not `i > 0`) the correct condition?
//    >>> your words:  (this is THE question of this problem — a value may legitimately
//                      repeat DOWN a path, e.g. [2,2]; it must not repeat ACROSS siblings)
//
//    Q4: what must you do to `nums` before any of this works at all?
//    >>> your words:
//
// 3) OPTIMAL — sort, then loop-frame backtracking with the same-depth duplicate skip.
//    Time: O(?)   Space: O(?)
    void subsetsRec(vector<int>& nums, set<vector<int>>& ans, vector<int>& chk, int start){
        if(start >= nums.size()){
            ans.insert(chk);
            return;
        }
        for(int i = start; i < nums.size(); i++) {
            chk.push_back(nums[i]);
            subsetsRec(nums, ans, chk, i+1);
            chk.pop_back();
            subsetsRec(nums, ans, chk, i+1);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> chk;
        sort(nums.begin(), nums.end());
        subsetsRec(nums, ans, chk, 0);   
        vector<vector<int>> finalans(ans.begin(), ans.end());
        return finalans;
    }

// ---------------------------------------------------------------------
// Normalizer (DO NOT edit): sorts inside each subset, then sorts the collection.
    void subsetsRecu(vector<int>& nums, vector<vector<int>>& ans, vector<int>& chk, int start){
        ans.push_back(chk);
        for(int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue;
            chk.push_back(nums[i]);
            subsetsRecu(nums, ans, chk, i+1);
            chk.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> chk;
        sort(nums.begin(), nums.end());
        subsetsRecu(nums, ans, chk, 0);   
        return ans;
    }

// 4) STRESS: brute IS the oracle. Duplicate-heavy inputs on purpose.
int main() {
    // --- hardcoded edges ---
    {
        vector<int> a = {1, 2, 2};                    // the canonical case: 6 subsets, not 8
        auto got = normalized(subsetsWithDup(a));
        auto exp = normalized(subsetsWithDupBrute(a));
        if (got != exp || got.size() != 6) {
            printf("EDGE FAIL [1,2,2]: got %zu subsets, want 6\n", got.size());
            return 1;
        }
        vector<int> b = {5, 5, 5, 5};                 // all-same: 5 subsets ({} .. [5,5,5,5])
        if (normalized(subsetsWithDup(b)).size() != 5) { printf("EDGE FAIL all-same\n"); return 1; }
    }

    // --- random stress: tiny value pool => lots of duplicates ---
    srand(90);
    for (int it = 0; it < 20000; it++) {
        int n = rand() % 8 + 1;                       // n in [1,8]
        vector<int> nums(n);
        for (int& x : nums) x = rand() % 3 - 1;        // values in {-1,0,1} => heavy duplication

        auto bru = normalized(subsetsWithDupBrute(nums));
        auto opt = normalized(subsetsWithDup(nums));
        if (bru != opt) {
            printf("MISMATCH n=%d (it=%d) nums=[", n, it);
            for (int x : nums) printf("%d ", x);
            printf("]: brute %zu vs optimal %zu\n", bru.size(), opt.size());
            return 1;
        }
    }
    printf("all subsets-II cases passed\n");
    return 0;
}
