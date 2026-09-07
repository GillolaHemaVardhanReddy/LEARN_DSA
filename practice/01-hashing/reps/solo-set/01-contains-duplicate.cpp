// LC 217 — Contains Duplicate  ·  easy  ·  SOLO (name the cue first)
// Return true if any value appears at least twice in the array.
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // cue: ___ -> hashing because ___
        unordered_map<int,int> seen;
        for(int i = 0 ; i < nums.size(); i++) {
            if(seen.count(nums[i])) return true; // this here reduced the O(n^) work to O(n) repeated work removed with lookup
            seen[nums[i]] = i;
        }
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
