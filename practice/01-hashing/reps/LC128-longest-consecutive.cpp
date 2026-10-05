// LC 128 — Longest Consecutive Sequence  ·  Medium  ·  topic 01 hashing, rung 3/6
// 2026-09-29  ·  https://leetcode.com/problems/longest-consecutive-sequence/
//
// Given an unsorted array nums, return the length of the longest run of consecutive integers.
// Must run in O(n).
//
//   nums = [100,4,200,1,3,2]       ->  4   (1,2,3,4)
//   nums = [0,3,7,2,5,8,4,6,0,1]   ->  9   (0..8)
//   nums = []                      ->  0
//
// 0 <= nums.length <= 10^5 · -10^9 <= nums[i] <= 10^9 · duplicates allowed
//
// ── the only thing to figure out ──────────────────────────────────────────────
// Sort + scan is O(n log n). The follow-up bans the sort.
// You are holding a number x. Without order, how do you know x+1 is in the array?
// And once you can walk x, x+1, x+2 ... what stops that from being O(n^2)?
// ─────────────────────────────────────────────────────────────────────────────

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> check;
        for(int i = 0 ; i < n ; i++ ) {
            check[nums[i]] = 1;
        }
        int max_num = INT_MIN;
        int current_l = 0;
        for(auto& p : check) {
            current_l = 1;
            if(check.count(p.first-1) != 0){
                continue;
            }
            int temp = p.first+1;
            for(int j = 0 ; j < n ; j++ ) {
                if(check.count(temp++) != 0){
                    current_l++;
                } else break;
            }
            max_num = max(max_num, current_l);
        }
        return max(max_num,0);
    }
};
