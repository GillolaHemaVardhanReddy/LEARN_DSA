// LC 42 — Trapping Rain Water  ·  capstone: converging two pointers + left/right max
// Paste ONLY the Solution class into LeetCode. main() is for local testing.
// Suggested path: brute O(n^2) -> prefix maxLeft/maxRight O(n) space -> two-pointer O(1) space.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // cue: water above bar = min(maxLeft, maxRight) - height[i]
        // capstone: two pointers, carry leftMax/rightMax, move the smaller side.
        return 0;
    }
};

int main() {
    Solution sol;
    vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(a) << "  (expect 6)\n";
    vector<int> b = {4,2,0,3,2,5};
    cout << sol.trap(b) << "  (expect 9)\n";
    return 0;
}
