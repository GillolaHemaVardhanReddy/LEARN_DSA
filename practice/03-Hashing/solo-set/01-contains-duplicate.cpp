// LC 217 — Contains Duplicate  ·  easy  ·  SOLO (name the cue first)
// Return true if any value appears at least twice in the array.
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // cue: ___ -> hashing because ___
        // YOUR CODE HERE
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1,2,3,1};
    vector<int> b = {1,2,3,4};
    cout << sol.containsDuplicate(a) << "  (expect 1)\n";
    cout << sol.containsDuplicate(b) << "  (expect 0)\n";
    return 0;
}
