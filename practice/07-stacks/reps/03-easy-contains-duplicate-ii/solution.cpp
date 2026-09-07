// LC219 — Contains Duplicate II  ·  Easy  ·  https://leetcode.com/problems/contains-duplicate-ii/
// PRACTICE (cold/interleaved). Paste ONLY the Solution class into LeetCode. main() is local.
//
// GATES while you solve:  name the pattern FIRST  ·  build your own hostile input
//                         ·  self-trace before you say "done"
//
//   Return true if there are two DISTINCT indices i, j with nums[i]==nums[j] and abs(i-j) <= k.
//   Constraints: 1 <= n <= 1e5 · -1e9 <= nums[i] <= 1e9 · 0 <= k <= 1e5
//
//   PATTERN (name it BEFORE you code — this is the rep): ______________________________
//   Gate for yourself: data is UNSORTED. So what's OFF the table, and what does that leave?
//   Watch the boundary: k can be 0; values can repeat far apart AND close together.
// =============================================================================
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> chk;
        for(int i = n-1 ; i>=0 ; i-- ) {
            while((!chk.size()) && (nums[i] ==nums[chk.top()])){
                if(abs(i - chk.top()) <= k) return true;
                chk.pop();
            }
            chk.push(nums[i]);
        }
        return false;
    }
};

// =============================================================================
//  BRUTE ORACLE — check every pair within a window of k (O(n*k)). Correct, slow.
// =============================================================================
class SolutionBrute {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n && j <= i+k; ++j)
                if (nums[i] == nums[j]) return true;
        return false;
    }
};

int main() {
    Solution opt; SolutionBrute bru;
    // {nums..., k} packed: last element is k.
    vector<pair<vector<int>,int>> ex = {
        {{1,2,3,1},3}, {{1,0,1,1},1}, {{1,2,3,1,2,3},2}, {{1},0}, {{1,1},0}
    };
    for (auto& p : ex) {
        auto v = p.first; int k = p.second;
        bool a = opt.containsNearbyDuplicate(v,k), b = bru.containsNearbyDuplicate(v,k);
        printf("%s%s\n", a ? "true " : "false", (a==b) ? "" : "  <-- MISMATCH vs oracle");
    }

    unsigned seed = 2468;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    for (int trial = 0; trial < 100000; ++trial) {
        int n = 1 + rnd() % 8;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) v[i] = (int)(rnd() % 5);   // small range -> forces dup collisions
        int k = rnd() % (n + 1);
        if (opt.containsNearbyDuplicate(v,k) != bru.containsNearbyDuplicate(v,k)) {
            printf("STRESS MISMATCH on k=%d : ", k);
            for (int x : v) printf("%d ", x);
            printf("\n");
            return 1;
        }
    }
    printf("stress: 100k cases passed\n");
    return 0;
}
