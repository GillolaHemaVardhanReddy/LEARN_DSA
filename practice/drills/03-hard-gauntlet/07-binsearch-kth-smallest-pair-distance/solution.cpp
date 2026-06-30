// LC719 — Find K-th Smallest Pair Distance · Hard
// https://leetcode.com/problems/find-k-th-smallest-pair-distance/
// HARD GAUNTLET · P7 (Binary-Search-on-answer + window count). Paste ONLY the Solution class. main() local.
//
// GATES: name the flavor · build your OWN hostile input · self-trace before "done".
//
//   PATTERN (name it BEFORE you code): ____________________
//   Hint: BS on the DISTANCE itself. countPairs(<=d) is monotonic in d; smallest d with
//   countPairs(<=d) >= k is the answer. Count via sort + a sliding window (for each right, how far
//   left stays within d). This is the "k-th smallest" twin you tapped out on before — own it now.
// =============================================================================
#include <bits/stdc++.h>
using namespace std;

// OPTIMAL — sort; BS d in [0, max-min]; countPairs(d) = for each r, advance l while nums[r]-nums[l]>d,
//   add (r-l). Smallest d with count >= k.   Time: O(n log n + n log(maxDist))   Space: O(1)
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // TODO (boss)
        return 0;
    }
};

// HOW I DERIVED BRUTE -> OPTIMAL  (The Bridge — your words)
//   Q1. There are ~n^2 distances — too many to sort. But the ANSWER is one integer in [0,max-min].
//       What monotonic question lets you BS it? ->
//   Q2. After sorting nums, for a fixed d, how do you count pairs with distance <= d in O(n)
//       (not O(n^2))? (two pointers: for each r, smallest l with nums[r]-nums[l] <= d) ->
//   Q3. Why "smallest d with count >= k" rather than "count == k"? (ties / duplicates) ->
//   My derivation: ->

// BRUTE ORACLE — fill FIRST. Collect all n(n-1)/2 pair distances, sort, return the k-th (1-indexed). O(n^2 log).
class SolutionBrute {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // TODO (boss): all pair distances, sort, pick index k-1.
        return 0;
    }
};

// STRESS — brute is the oracle.
int main() {
    Solution opt; SolutionBrute bru;
    vector<pair<vector<int>,int>> ex = {{{1,3,1},1},{{1,1,1},2},{{1,6,1},3}};
    for (auto& [v,k] : ex) {
        int o = opt.smallestDistancePair(v,k), r = bru.smallestDistancePair(v,k);
        printf("%d  %s\n", o, (o==r) ? "" : " <-- MISMATCH vs oracle");
    }
    unsigned seed = 719;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    for (int t = 0; t < 50000; ++t) {
        int n = 2 + rnd()%7; vector<int> v(n);
        for (auto& x:v) x = rnd()%15;
        int maxk = n*(n-1)/2, k = 1 + rnd()%maxk;
        if (opt.smallestDistancePair(v,k) != bru.smallestDistancePair(v,k)) {
            printf("STRESS MISMATCH k=%d on: ", k);
            for (int x:v) printf("%d ", x); printf("\n"); return 1;
        }
    }
    printf("stress: 50k cases passed\n");
    return 0;
}
