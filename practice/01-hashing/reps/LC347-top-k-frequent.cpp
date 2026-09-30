// LC 347 — Top K Frequent Elements  ·  Medium  ·  topic 01 hashing, problem 2/6
// 2026-09-28
//
// Given an integer array nums and an integer k, return the k most frequent elements.
// Any order. The answer is guaranteed to be unique.
//
//   nums = [1,1,1,2,2,3], k = 2   ->  [1,2]
//   nums = [1], k = 1             ->  [1]
//   nums = [4,4,-1,-1,-1,7], k = 1 ->  [-1]
//
// 1 <= nums.length <= 10^5 · -10^4 <= nums[i] <= 10^4 · k in [1, number of distinct elements]
// Follow-up: better than O(n log n).
//
// ── the only thing to figure out ──────────────────────────────────────────────
// Counting is LC49's move — you already own it.
// After counting you hold pairs (value, count). You want the k with the biggest counts.
// What do you put ON TOP of the counts to pull those k out?
// ─────────────────────────────────────────────────────────────────────────────

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> check(nums.size()+1);
        unordered_map<int, int> counts;
        for(auto& i: nums){
            counts[i]++;
        }
        for (auto& [num, c] : counts) check[c].push_back(num);
        vector<int> ans;
        for(int j = check.size() - 1 ; j > 0; j--){
            if(!check[j].empty() && k) {
                for(auto& i: check[j]){
                    if(k) {ans.push_back(i); k--;}
                    else break;
                }
            }
            if(!k) break;
        }
        return ans;
    }
};
