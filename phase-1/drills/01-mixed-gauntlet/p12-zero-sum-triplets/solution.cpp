// See notes.md for the statement + your thinking.
// Workflow: fill notes.md steps 1-4 BEFORE you open LINKS.md / paste the signature.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Paste the exact method signature from the LeetCode link (LINKS.md), implement here.
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0 ; i < n ; i++ ) {
            if(i>0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = n-1;
            while(l<r){
                long long sum = (long long)nums[l] + nums[r];
                if(r>=0 && sum > -nums[i]) r--;
                else if(l<n && sum < -nums[i]) l++;
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++; r--;
                    while(l < n && nums[l] == nums[l-1]) l++;
                    while(r >= 0 && nums[r] == nums[r+1]) r--;
                }
            }
        }
        return ans;
    }
};

// ---------- local test harness (optional) — build the example and print the result ----------
int main() {
    Solution sol;
    // Example: construct the input from notes.md and call your method, e.g.:
    //   vector<int> nums = {2, 7, 11, 15};
    //   auto r = sol.yourMethod(nums, 9);
    //   for (auto x : r) cout << x << ' ';
    //   cout << '\n';
    return 0;
}
