// LC 410 — Split Array Largest Sum  ·  HARD search-on-answer (same engine as Koko)
// WEEKEND problem. Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // knobs: range [max(nums), sum(nums)] (VALUES);
        // feasible(maxSum)= greedily count parts (new part when running sum would exceed maxSum), parts <= k;
        // feasible -> ans=mid, hi=mid-1; else lo=mid+1.
        // YOUR CODE HERE
        return 0;
    }
};

int main() {
    Solution sol;
    vector<int> a = {7,2,5,10,8};
    cout << sol.splitArray(a, 2) << "  (expect 18)\n";
    vector<int> b = {1,2,3,4,5};
    cout << sol.splitArray(b, 2) << "  (expect 9)\n";
    return 0;
}
