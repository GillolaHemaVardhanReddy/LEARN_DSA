// LC 219 — Contains Duplicate II  ·  easy  ·  SOLO  (your drill miss Q7!)
// True if there are two indices i, j with nums[i]==nums[j] AND |i-j| <= k.
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // cue: ___ -> hashing because ___   (this is NOT two pointers — prove it)
        unordered_map<int, int> seen;
        for(int i = 0 ; i < nums.size(); i++){
            if(seen.count(nums[i])){
                if(abs(i - seen[nums[i]]) <= k){
                    return true;
                }
            }
            seen[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1,2,3,1};
    vector<int> b = {1,0,1,1};
    vector<int> c = {1,2,3,1,2,3};
    cout << sol.containsNearbyDuplicate(a, 3) << "  (expect 1)\n";
    cout << sol.containsNearbyDuplicate(b, 1) << "  (expect 1)\n";
    cout << sol.containsNearbyDuplicate(c, 2) << "  (expect 0)\n";
    return 0;
}
