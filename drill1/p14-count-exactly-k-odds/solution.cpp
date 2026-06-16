// See notes.md for the statement + your thinking.
// Workflow: fill notes.md steps 1-4 BEFORE you open LINKS.md / paste the signature.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Paste the exact method signature from the LeetCode link (LINKS.md), implement here.
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, cnt = 0 , ans = 0;
        for(int r = 0 ; r < n && l<=r ; r++){
            if(nums[r]%2 == 1){
                cnt++;
                if(cnt == k) ans++;
                else if(cnt>k){
                    while(cnt > k && l<n){
                        if(nums[l]%2 == 1) cnt--;
                        l++;
                        if(cnt == k) ans++;
                    }
                }
            } else {
                if(cnt == k ) ans++;
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
