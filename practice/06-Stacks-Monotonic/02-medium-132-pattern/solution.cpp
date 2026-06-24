// LC456 — 132 Pattern  ·  Medium  ·  https://leetcode.com/problems/132-pattern/
// PRACTICE (cold/interleaved). Paste ONLY the Solution class into LeetCode. main() is local.
//
// GATES while you solve:  name the pattern FIRST  ·  build your own hostile input
//                         ·  self-trace before you say "done"
//
//   A 132 pattern = indices i<j<k with nums[i] < nums[k] < nums[j].
//   Return true if any such subsequence exists.
//   Constraints: 1 <= n <= 2*10^5 · -1e9 <= nums[i] <= 1e9   (O(n^2) brute will TLE — find better)
//
//   PATTERN (name it BEFORE you code — this is the rep): ______________________________
//   Hint to yourself, not the answer: which of the three (the "1", the "3", or the "2")
//   is easiest to fix while scanning, so you only hunt for the other two?
// =============================================================================
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // TODO (boss): name the pattern above, then code the optimal.
        return false;
    }
};

// =============================================================================
//  BRUTE ORACLE — every triple i<j<k (O(n^3)). Correct, slow. Stress oracle only.
// =============================================================================
class SolutionBrute {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j)
                for (int k = j+1; k < n; ++k)
                    if (nums[i] < nums[k] && nums[k] < nums[j]) return true;
        return false;
    }
};

int main() {
    Solution opt; SolutionBrute bru;
    vector<vector<int>> ex = { {1,2,3,4}, {3,1,4,2}, {-1,3,2,0}, {1}, {1,2}, {3,5,0,3,4} };
    for (auto v : ex) {
        bool a = opt.find132pattern(v), b = bru.find132pattern(v);
        printf("%s%s\n", a ? "true " : "false", (a==b) ? "" : "  <-- MISMATCH vs oracle");
    }

    unsigned seed = 1357;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    for (int trial = 0; trial < 100000; ++trial) {
        int n = 1 + rnd() % 8;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) v[i] = (int)(rnd() % 11) - 5;  // small range -> ties + tight patterns
        if (opt.find132pattern(v) != bru.find132pattern(v)) {
            printf("STRESS MISMATCH on: ");
            for (int x : v) printf("%d ", x);
            printf("\n");
            return 1;
        }
    }
    printf("stress: 100k cases passed\n");
    return 0;
}
