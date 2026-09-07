// LC992 — Subarrays with K Different Integers · Hard
// https://leetcode.com/problems/subarrays-with-k-different-integers/
// HARD GAUNTLET · P4 (Sliding Window). Paste ONLY the Solution class. main() local.
//
// GATES: name the flavor · build your OWN hostile input · self-trace before "done".
//   ⭐ This is your owed MISTAKE #11 re-test — atMost(k) - atMost(k-1), unconditional ans += r-l+1.
//
//   PATTERN (name it BEFORE you code): ____________________
//   Hint: EXACTLY k is hard to window directly. exactly(k) = atMost(k) - atMost(k-1). atMost is a
//   clean variable window: shrink while distinct > k, then add (r-l+1) UNCONDITIONALLY each step.
// =============================================================================
#include <bits/stdc++.h>
using namespace std;

// OPTIMAL — exactly(k) = atMost(k) - atMost(k-1). atMost(m): grow r, while distinct>m shrink l,
//   ans += r-l+1 every step (counts all subarrays ending at r).   Time: O(n)   Space: O(n)
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // TODO (boss)
        return 0;
    }
};

// HOW I DERIVED BRUTE -> OPTIMAL  (The Bridge — your words)
//   Q1. Why is "exactly k distinct" awkward for one window but "at most k" easy? ->
//   Q2. In atMost, why does `ans += r - l + 1` (no if-guard, no ans++) count exactly the new
//       subarrays ending at r? ->  (this is the trap you missed before — UNCONDITIONAL add)
//   Q3. Why does atMost(k) - atMost(k-1) leave precisely the exactly-k count? ->
//   My derivation: ->

// BRUTE ORACLE — fill FIRST. For each (l,r) count distinct; ++ans when distinct == k. O(n^2).
class SolutionBrute {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // TODO (boss): O(n^2) distinct-count oracle.
        return 0;
    }
};

// STRESS — brute is the oracle.
int main() {
    Solution opt; SolutionBrute bru;
    vector<pair<vector<int>,int>> ex = {{{1,2,1,2,3},2},{{1,2,1,3,4},3},{{1},1}};
    for (auto& [v,k] : ex) {
        int o = opt.subarraysWithKDistinct(v,k), r = bru.subarraysWithKDistinct(v,k);
        printf("%d  %s\n", o, (o==r) ? "" : " <-- MISMATCH vs oracle");
    }
    unsigned seed = 992;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    for (int t = 0; t < 50000; ++t) {
        int n = 1 + rnd()%9; vector<int> v(n);
        for (int i=0;i<n;++i) v[i] = 1 + rnd()%4;
        int k = 1 + rnd()%4;
        if (opt.subarraysWithKDistinct(v,k) != bru.subarraysWithKDistinct(v,k)) {
            printf("STRESS MISMATCH k=%d on: ", k);
            for (int x:v) printf("%d ", x); printf("\n"); return 1;
        }
    }
    printf("stress: 50k cases passed\n");
    return 0;
}
