// LC560 Subarray Sum Equals K — COLD re-solve · 2026-10-09 · blank file, no peeking at learn/
// https://leetcode.com/problems/subarray-sum-equals-k/
// Return the number of contiguous non-empty subarrays whose sum equals k.
// 1 <= nums.length <= 2*10^4 · -1000 <= nums[i] <= 1000 · -10^7 <= k <= 10^7
//
// [1,1,1],   k = 2    -> 2
// [1,2,3],   k = 3    -> 2
// [1,-1,0],  k = 0    -> 3
//
// STEP 1 — budget line (brute in digits, what I can afford):
//
// STEP 2 — code:

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
        vector<int> pf;
        unordered_map<int, int> check;
        check[0] = 1;
        int ans = 0;
        for(int i = 0 ; i < n ; i++ ) {
            sum+=nums[i];
            if(check.count(sum - k)){
                ans+=check[sum - k];
            }
            check[sum]++;
        }
        return ans;
    }
};

// STEP 3 — complexity: "the loop on line __ runs __ times x one iteration costs __ (line __) => __ in digits", time AND memory:
