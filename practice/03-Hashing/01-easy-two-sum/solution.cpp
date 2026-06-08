// LC 1 — Two Sum  (Hash map, complement lookup)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // ───── YOUR CODE HERE ─────
        unordered_map<int, int> seen;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++ ) {
            int comp = target - nums[i];
            if(seen.count(comp)) return {seen[comp], i};
            if(!seen.count(nums[i])) seen[nums[i]] = i;
        }
        return {}; // replace
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    vector<int> a = {2, 7, 11, 15};
    auto r1 = sol.twoSum(a, 9);  cout << r1[0] << "," << r1[1] << "  (expect 0,1)\n";
    vector<int> b = {3, 2, 4};
    auto r2 = sol.twoSum(b, 6);  cout << r2[0] << "," << r2[1] << "  (expect 1,2)\n";
    return 0;
}
