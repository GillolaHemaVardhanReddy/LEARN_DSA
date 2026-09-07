// LC 209 — Minimum Size Subarray Sum  (Variable Window, SHORTEST)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // YOUR CODE HERE.
        int n = nums.size(), left = 0, sum = 0;
        int ans = n + 1;
        for(int right = 0 ; right < n ; right++ ) {
            sum += nums[right];
            while(sum >= target ){
                ans = min(ans, right - left + 1);
                sum-=nums[left];
                left++;
            }  
        }
        if(ans == n+1) return 0;
        return ans;
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    vector<int> a = {2,3,1,2,4,3};
    vector<int> b = {1,4,4};
    vector<int> c = {1,1,1,1,1,1,1,1};
    cout << sol.minSubArrayLen(7,  a) << "  (expect 2)\n";
    cout << sol.minSubArrayLen(4,  b) << "  (expect 1)\n";
    cout << sol.minSubArrayLen(11, c) << "  (expect 0)\n";
    return 0;
}
