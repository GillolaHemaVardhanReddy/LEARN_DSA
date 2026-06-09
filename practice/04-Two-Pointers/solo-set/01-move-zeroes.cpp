// LC 283 — Move Zeroes  ·  easy  ·  SOLO (fast/slow write pointer)
// Move all 0s to the end IN PLACE, keep relative order of non-zeros. Do not copy the array.
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // cue: ___ -> two pointers, which shape?
        // YOUR CODE HERE
    }
};

int main() {
    Solution sol;
    vector<int> a = {0,1,0,3,12};
    sol.moveZeroes(a);
    cout << "["; for (int x : a) cout << x << " "; cout << "]  (expect 1 3 12 0 0)\n";
    return 0;
}
