// LC 977 — Squares of a Sorted Array  ·  CONVERGING (compare ends, fill from back)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // cue: sorted, largest squares at the ENDS -> converging two pointers
        // compare |nums[L]| vs |nums[R]|, take bigger square, fill result from the back.
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> a = {-4,-1,0,3,10};
    auto r1 = sol.sortedSquares(a);
    cout << "["; for (int x : r1) cout << x << " "; cout << "]  (expect 0 1 9 16 100)\n";
    vector<int> b = {-7,-3,2,3,11};
    auto r2 = sol.sortedSquares(b);
    cout << "["; for (int x : r2) cout << x << " "; cout << "]  (expect 4 9 9 49 121)\n";
    return 0;
}
