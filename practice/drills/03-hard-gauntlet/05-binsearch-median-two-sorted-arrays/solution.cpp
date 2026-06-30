// LC4 — Median of Two Sorted Arrays · Hard
// https://leetcode.com/problems/median-of-two-sorted-arrays/
// HARD GAUNTLET · P5 (Binary Search / partition). Paste ONLY the Solution class. main() local.
//
// GATES: name the flavor · build your OWN hostile input · self-trace before "done".
//
//   PATTERN (name it BEFORE you code): ____________________
//   Hint: O(log(m+n)) demands BS. Binary-search a PARTITION of the smaller array; the partition of
//   the larger one is forced (left halves must total (m+n+1)/2). Valid when maxLeftA<=minRightB and
//   maxLeftB<=minRightA. Use +/-infinity sentinels at the array edges.
// =============================================================================
#include <bits/stdc++.h>
using namespace std;

// OPTIMAL — BS the cut on the SHORTER array; derive the other cut; check the 4-way boundary; median
//   from maxLeft/minRight depending on total parity.   Time: O(log min(m,n))   Space: O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // TODO (boss)
        return 0.0;
    }
};

// HOW I DERIVED BRUTE -> OPTIMAL  (The Bridge — your words)
//   Q1. The median splits the merged array into two equal halves. If you fix how many of A's elements
//       go LEFT, how many of B's are forced? ->
//   Q2. A partition is correct when both "left maxes <= opposite right mins". Which direction do you
//       move A's cut when maxLeftA > minRightB? ->
//   Q3. Why search the SHORTER array, and what do the +/-INF sentinels protect against? ->
//   My derivation: ->

// BRUTE ORACLE — fill FIRST. Merge both sorted arrays, pick the middle (or mean of two). O(m+n).
class SolutionBrute {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        // TODO (boss): merge + middle. The oracle.
        return 0.0;
    }
};

// STRESS — brute is the oracle. Compare doubles with an epsilon.
int main() {
    Solution opt; SolutionBrute bru;
    vector<pair<vector<int>,vector<int>>> ex = {{{1,3},{2}},{{1,2},{3,4}},{{},{1}},{{2},{}}};
    for (auto& [a,b] : ex) {
        double o = opt.findMedianSortedArrays(a,b), r = bru.findMedianSortedArrays(a,b);
        printf("%.5f  %s\n", o, (fabs(o-r)<1e-6) ? "" : " <-- MISMATCH vs oracle");
    }
    unsigned seed = 4;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    for (int t = 0; t < 50000; ++t) {
        int m = rnd()%5, n = rnd()%5; if (m+n==0) continue;
        vector<int> a(m), b(n);
        for (auto& x:a) x = rnd()%20; for (auto& x:b) x = rnd()%20;
        sort(a.begin(),a.end()); sort(b.begin(),b.end());
        if (fabs(opt.findMedianSortedArrays(a,b) - bru.findMedianSortedArrays(a,b)) > 1e-6) {
            printf("STRESS MISMATCH a=["); for(int x:a)printf("%d ",x);
            printf("] b=["); for(int x:b)printf("%d ",x); printf("]\n"); return 1;
        }
    }
    printf("stress: 50k cases passed\n");
    return 0;
}
