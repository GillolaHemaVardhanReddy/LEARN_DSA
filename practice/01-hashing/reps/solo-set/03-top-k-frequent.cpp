// LC 347 — Top K Frequent Elements  ·  MEDIUM  ·  SOLO (an L4 gate problem)
// Return the k most frequent elements (any order). Aim for better than O(n log n).
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // cue: ___ -> hashing because ___
        vector<int> ans;
        unordered_map<int, int> seen;
        unordered_map<int, vector<int>> fetch;
        int n = nums.size();
        for(int i = 0 ; i < nums.size(); i++){
            seen[nums[i]]++;
        }
        for(auto &[key, value] : seen){
            fetch[value].push_back(key);
        }
        for(int i = n-1; i>=0 ; i--){
            if(k>0){
                if(fetch.count(i)){
                    for(int j = 0 ; j < fetch[i].size() ; j++){
                        ans.push_back(fetch[i][j]);
                        k--;
                    }
                }
            } else break;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1,1,1,2,2,3};
    auto r1 = sol.topKFrequent(a, 2);   // expect {1,2} in any order
    cout << "["; for (int x : r1) cout << x << " "; cout << "]  (expect 1 2)\n";
    vector<int> b = {1};
    auto r2 = sol.topKFrequent(b, 1);   // expect {1}
    cout << "["; for (int x : r2) cout << x << " "; cout << "]  (expect 1)\n";
    return 0;
}
