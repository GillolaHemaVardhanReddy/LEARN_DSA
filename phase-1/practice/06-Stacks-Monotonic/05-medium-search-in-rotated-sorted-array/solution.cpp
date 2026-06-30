// LC33 — Search in Rotated Sorted Array  ·  Medium  ·  https://leetcode.com/problems/search-in-rotated-sorted-array/
// PRACTICE (cold/interleaved). Paste ONLY the Solution class into LeetCode. main() is local.
// NOTE: this one is on your OPEN-leaks list (LC33 unsolved). The problem DEMANDS O(log n) — a
//       linear scan is the oracle here, NOT an accepted answer.
//
// GATES while you solve:  name the pattern FIRST  ·  build your own hostile input
//                         ·  self-trace before you say "done"
//                         ·  boundary: while(l<r) vs while(l<=r)? could mid be the answer?
//
//   Ascending array of DISTINCT values, possibly left-rotated at an unknown pivot. Return the
//   index of target, or -1. Must be O(log n).
//   Constraints: 1 <= n <= 5000 · -1e4 <= nums[i], target <= 1e4 · values unique.
//
//   PATTERN (name it BEFORE you code — this is the rep): ______________________________
//   Gate for yourself: at any mid, one of the two halves is still sorted. Which one, and is
//   target inside that sorted half? That single question drives the whole search.
// =============================================================================
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // TODO (boss): name the pattern above, then code the O(log n) optimal.
        return -1;
    }
};

// =============================================================================
//  BRUTE ORACLE — linear scan O(n). Correct, but NOT the asked complexity. Stress oracle only.
// =============================================================================
class SolutionBrute {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < (int)nums.size(); ++i)
            if (nums[i] == target) return i;
        return -1;
    }
};

int main() {
    Solution opt; SolutionBrute bru;
    vector<pair<vector<int>,int>> ex = {
        {{4,5,6,7,0,1,2},0}, {{4,5,6,7,0,1,2},3}, {{1},0}, {{1},1}, {{3,1},1}, {{5,1,3},5}
    };
    for (auto& p : ex) {
        auto v = p.first; int t = p.second;
        int a = opt.search(v,t), b = bru.search(v,t);
        printf("idx=%d%s\n", a, (a==b) ? "" : "  <-- MISMATCH vs oracle");
    }

    unsigned seed = 5151;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    for (int trial = 0; trial < 100000; ++trial) {
        int n = 1 + rnd() % 8;
        // build a strictly-increasing distinct array, then rotate by a random pivot.
        vector<int> v(n);
        int cur = (int)(rnd() % 7) - 3;
        for (int i = 0; i < n; ++i) { v[i] = cur; cur += 1 + rnd() % 3; }
        int pivot = rnd() % n;
        rotate(v.begin(), v.begin() + pivot, v.end());
        int target = (int)(rnd() % 25) - 5;   // often present, often not
        if (opt.search(v,target) != bru.search(v,target)) {
            printf("STRESS MISMATCH target=%d : ", target);
            for (int x : v) printf("%d ", x);
            printf("\n");
            return 1;
        }
    }
    printf("stress: 100k cases passed\n");
    return 0;
}
