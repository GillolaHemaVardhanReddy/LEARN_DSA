// LC 347 — Top K Frequent Elements  ·  +7d COLD RE-SOLVE  ·  2026-10-03  ·  3rd pass
// First solve 09-28 (AC, sort-by-count) · bucket O(n) derived unaided + AC 09-29 · this = the +7d rung
// (and it settles the bucket +1d card owed since 09-30).
// Blank file on purpose. Do not open LC347-top-k-frequent.cpp.
//
//   nums = [1,1,1,2,2,3], k = 2   ->  [1,2]
//   nums = [1],           k = 1   ->  [1]
//   nums = [4,4,4,4],     k = 1   ->  [4]
//
// 1 <= nums.length <= 10^5 · -10^4 <= nums[i] <= 10^4 · 1 <= k <= number of distinct elements
// The answer is guaranteed unique. Order of the output does not matter.
//
// Follow-up on LeetCode: better than O(n log n).  Write the O(n) one — you derived it on 09-29.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> check;
        for(int i = 0 ; i < n ; i++ ) {
            check[nums[i]]++;
        }
        vector<pair<int,int>> temp(check.begin(), check.end());
        vector<vector<int>> dummy(n+1);
        for(auto& x: temp) {
            dummy[x.second].push_back(x.first);
        }
        vector<int> ans;
        for(int i = n ; i > 0 ; i-- ) {
            if(dummy[i].size() > 0){
                for(int j = 0 ; j < dummy[i].size() ; j++){
                    if(k>0) ans.push_back(dummy[i][j]);
                    else break;
                    k--;
                }
            }
        }
        return ans;
    }
};

// Closing sentence:
//   O(____) — ____ runs ____ times, and the bucket walk costs ____ because ____ .
//   Memory O(____) because ____ .
