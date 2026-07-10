// LC78 — Subsets   (MEDIUM · ⭐ backtracking: pick / not-pick)  ·  M10 LEARN — first rep
// ---------------------------------------------------------------------
// Given an array of DISTINCT integers, return ALL possible subsets (the power set),
// in any order, no duplicates.
//   Constraints: 1 <= n <= 10,  -10 <= nums[i] <= 10,  all values unique.
//   URL: https://leetcode.com/problems/subsets/
// =====================================================================
#include <bits/stdc++.h>
using namespace std;


// 1) BRUTE — bitmask subset enumeration (the LC402 primitive).
//    Every subset <-> one n-bit mask. Bit i set  =>  nums[i] is in.
//    Time: O(n * 2^n)   Space: O(n * 2^n) for the answer
vector<vector<int>> subsetsBrute(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> cur;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i)) cur.push_back(nums[i]);
        ans.push_back(cur);
    }
    return ans;
}

// 2) BRIDGE — this one is NOT about speed (both ways touch all 2^n subsets).
//    It's about GENERALITY — why the recursion survives where the mask dies:
//    Q1: the mask trick hard-codes "2 choices per element". What breaks when a
//        problem has MORE than 2 choices per slot (e.g. permutations: n choices)?
//    Q2: in the tree you traced by hand, what exactly are the two branches at
//        index i, and where does the "push into answer" happen?
//    Q3: ⚠️ your `path` is ONE shared array walking the WHOLE tree. After the
//        pick-branch returns and you start the not-pick branch — what state must
//        `path` be in, and whose job is it to make that true?
//    >>> your words:
//
// 3) OPTIMAL (same complexity, the PATTERN rep) — choose → explore → un-choose.
//    Recurse over indices; at each index fork pick / not-pick; base case pushes
//    the current path into the answer.
//    Time: O(?)   Space: O(?) (call stack + path)
void getsets(vector<int>& nums, vector<vector<int>>& ans, int i, vector<int>& sett) {
    if(i >= nums.size()){
        ans.push_back(sett);
        return;
    }
    sett.push_back(nums[i]);
    getsets(nums, ans, i+1, sett);
    sett.pop_back();
    getsets(nums, ans, i+1, sett);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> sett;
    getsets(nums, ans, 0, sett);
    return ans;
}

// ---------------------------------------------------------------------
// Normalizer (DO NOT edit): order-independent compare — sorts inside each
// subset, then sorts the collection. Lets bitmask-order and DFS-order agree.
vector<vector<int>> normalized(vector<vector<int>> v) {
    for (auto& s : v) sort(s.begin(), s.end());
    sort(v.begin(), v.end());
    return v;
}

// 4) STRESS: brute IS the oracle. Random distinct arrays, brute vs optimal.
int main() {
    // --- hardcoded edges ---
    {
        vector<int> one = {7};                     // size-1: expect {} and {7}
        auto got = normalized(subsets(one));
        auto exp = normalized(subsetsBrute(one));
        if (got != exp || (int)got.size() != 2) {
            printf("EDGE FAIL n=1: got %zu subsets\n", got.size());
            return 1;
        }
    }

    // --- random stress ---
    srand(78);
    for (int it = 0; it < 20000; it++) {
        int n = rand() % 8 + 1;                    // n in [1,8]
        vector<int> pool = {-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10};
        random_shuffle(pool.begin(), pool.end());
        vector<int> nums(pool.begin(), pool.begin() + n);   // distinct by construction

        auto bru = normalized(subsetsBrute(nums));
        auto opt = normalized(subsets(nums));
        if ((int)opt.size() != (1 << n)) {
            printf("COUNT MISMATCH n=%d: got %zu, want %d\n", n, opt.size(), 1 << n);
            return 1;
        }
        if (bru != opt) {
            printf("MISMATCH n=%d (it=%d): brute %zu vs optimal %zu subsets\n",
                   n, it, bru.size(), opt.size());
            return 1;
        }
    }
    printf("all subset cases passed\n");
    return 0;
}
