// LC 15 — 3Sum  ·  FIX ONE + converging two pointers + skip-duplicates
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // cue: triplet sum=0 -> sort + fix one + two-pointer the rest (= Two Sum II inside)
        // THE tricky part: skip duplicates at i, and at L/R after a hit.
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> a = {-1,0,1,2,-1,-4};
    auto r = sol.threeSum(a);
    cout << "got " << r.size() << " triplets (expect 2):\n";
    for (auto& t : r) { cout << "  ["; for (int x : t) cout << x << " "; cout << "]\n"; }
    return 0;
}
