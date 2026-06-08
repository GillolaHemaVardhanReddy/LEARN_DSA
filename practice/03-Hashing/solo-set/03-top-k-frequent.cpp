// LC 347 — Top K Frequent Elements  ·  MEDIUM  ·  SOLO (an L4 gate problem)
// Return the k most frequent elements (any order). Aim for better than O(n log n).
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // cue: ___ -> hashing because ___
        // brute force first (count + sort), then think how to avoid the sort.
        // YOUR CODE HERE
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> a = {1,1,1,2,2,3};
    auto r1 = sol.topKFrequent(a, 2);   // expect {1,2} in any order
    cout << "["; for (int x : r1) cout << x << " "; cout << "]  (expect 1 2)\n";
    vector<int> b = {1};
    auto r2 = sol.topKFrequent(b, 1);   // expect {1}
    cout << "["; for (int x : r2) cout << x << " "; cout << "]  (expect 1)\n";
    return 0;
}
