// LC128 Longest Consecutive Sequence — cold re-solve · 2026-10-08 · blank file, no peeking
// https://leetcode.com/problems/longest-consecutive-sequence/
// Return the length of the longest run of consecutive integers (values, not positions). Must be O(n).
// 0 <= nums.length <= 10^5 · -10^9 <= nums[i] <= 10^9
//
// [100,4,200,1,3,2]         -> 4   (1,2,3,4)
// [0,3,7,2,5,8,4,6,0,1]     -> 9
// [1,0,1,2]                 -> 3
//
// STEP 1 — budget line (brute in digits, what I can afford):
//
// STEP 2 — code:

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> check;
        for(int i = 0 ; i < n ; i++ ) {
            check[nums[i]] = 1;
        }
        int ans = 0, final_ans = INT_MIN;
        for(auto& [k,v]: check) {
            if(check.count(k - 1)){
                continue;
            }
            int temp = k;
            ans = 1;
            for(int j = 0 ; j < n ; j++ ) {
                if(check.count(++temp)){
                    ans++;
                } else {
                    break;
                }
            }
            final_ans = max(ans, final_ans);
        }
        final_ans = max(final_ans, 0);
        return final_ans;
    }
};

// STEP 3 — complexity: (times the loop runs) x (cost of one iteration), time AND memory, line behind each factor:
