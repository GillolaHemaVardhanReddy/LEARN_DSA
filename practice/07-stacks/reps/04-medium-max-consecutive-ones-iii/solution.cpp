// LC1004 — Max Consecutive Ones III  ·  Medium  ·  https://leetcode.com/problems/max-consecutive-ones-iii/
// PRACTICE (cold/interleaved). Paste ONLY the Solution class into LeetCode. main() is local.
// NOTE: this is your re-test for MISTAKE #2 (min/max tracker init + "not found" return). Get the
//       boundary values right COLD.
//
// GATES while you solve:  name the pattern FIRST  ·  build your own hostile input
//                         ·  self-trace before you say "done"
//
//   Binary array nums. Return the longest run of 1's you can get if you may flip at most k zeros.
//   Constraints: 1 <= n <= 1e5 · nums[i] in {0,1} · 0 <= k <= n
//
//   PATTERN (name it BEFORE you code — this is the rep): ______________________________
//   Gate for yourself: "longest something with at most k of X" — fixed window or elastic?
//   When you shrink, what exactly forces the left edge to move?
// =============================================================================
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // TODO (boss): name the pattern above, then code the optimal.
        return 0;
    }
};

// =============================================================================
//  BRUTE ORACLE — every start, extend while zeros-used <= k (O(n^2)). Correct, slow.
// =============================================================================
class SolutionBrute {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), best = 0;
        for (int i = 0; i < n; ++i) {
            int zeros = 0;
            for (int j = i; j < n; ++j) {
                if (nums[j] == 0) zeros++;
                if (zeros > k) break;
                best = max(best, j - i + 1);
            }
        }
        return best;
    }
};

int main() {
    Solution opt; SolutionBrute bru;
    vector<pair<vector<int>,int>> ex = {
        {{1,1,1,0,0,0,1,1,1,1,0},2},
        {{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1},3},
        {{0},0}, {{1},0}, {{0,0,0},2}
    };
    for (auto& p : ex) {
        auto v = p.first; int k = p.second;
        int a = opt.longestOnes(v,k), b = bru.longestOnes(v,k);
        printf("%d%s\n", a, (a==b) ? "" : "  <-- MISMATCH vs oracle");
    }

    unsigned seed = 3690;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    for (int trial = 0; trial < 100000; ++trial) {
        int n = 1 + rnd() % 10;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) v[i] = rnd() % 2;
        int k = rnd() % (n + 1);
        if (opt.longestOnes(v,k) != bru.longestOnes(v,k)) {
            printf("STRESS MISMATCH on k=%d : ", k);
            for (int x : v) printf("%d ", x);
            printf("\n");
            return 1;
        }
    }
    printf("stress: 100k cases passed\n");
    return 0;
}
