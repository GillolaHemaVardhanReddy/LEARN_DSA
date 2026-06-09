// LC 15 — 3Sum  ·  FIX ONE + converging two pointers + skip-duplicates
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // cue: triplet sum=0 -> sort + fix one + two-pointer the rest (= Two Sum II inside)
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0 ; i < n ; i++ ) {
            int k = n-1;
            int j = i+1;
            while( j < k ) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    int check_j = nums[j], check_k = nums[k];
                    while(nums[j] == check_j){
                        j++;
                    }
                    while(nums[k] == check_k){
                        k--;
                    }
                } else {
                    j++;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> a = {-1,0,1,2,-1,-4};
    auto r = sol.threeSum(a);
    cout << "got " << r.size() << " triplets (expect 2):\n";
    for (auto& t : r) { cout << "  ["; for (int x : t) cout << x << " "; cout << "]\n"; }
    return 0;
}
