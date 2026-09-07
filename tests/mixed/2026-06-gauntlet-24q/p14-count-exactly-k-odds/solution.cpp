// P14 — Count subarrays with exactly K odd numbers (LeetCode 1248).
// Workflow: fill BRUTE first (your words + TC/SC), then derive OPTIMAL in the
// bridge comment, then implement OPTIMAL. No notes.md needed anymore.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ============================ BRUTE FORCE ============================
    // My idea (plain words):
    //   ...
    //
    // Time:  O(n^2)   — why: because of 2 loops 
    // Space: O(1)   — why: no extra space
    int numberOfSubarraysBrute(vector<int>& nums, int k) {
        // TODO(boss): the obvious "try all subarrays, count odds, tally == k".
        int n = nums.size(), cnt = 0 , ans = 0;
        for(int i = 0 ; i < n ; i++ ) {
            cnt = 0;
            for(int j = i ; j < n ; j++) {
                if(nums[j]%2) cnt++;
                if(cnt == k) ans++;
            }
        }
        return ans; // placeholder so it compiles while you work
    }

    // ================= HOW I DERIVED BRUTE -> OPTIMAL =================
    // The Bridge (answer in order, your own words):
    //   1. Where is the repeated work? well its actually we scan subarrays on every fixed index
    //   2. What is it recomputing each pass? we recompute count of odd numbers on each pass
    //   3. What tool kills that recompute? variable sliding window

    //
    // My derivation, clearly:
    /*
        well as per my knowledge we can kill recompute by using : my first thought since its calculating
        various sub arrays of different lengths so we can use variable sliding window concept here and check 
        on each variable sub array if we have k odd numbers 
        1. we recompute the cnt each time so what i was thinking is to we build count and reduce the cnt on shrinking window
        2. we check on each shrink and expand the k condition 

     */
    // =================================================================

    // ============================== OPTIMAL =============================
    // My idea (plain words):
    //   ...
    //
    // Time:  O(n)   — why: single loop that covers all sub arrays of a condition
    // Space: O(1)   — why: no extra space

    vector<int> transForm(vector<int>& nums){
        vector<int> ans;
        for(int i = 0 ; i < nums.size(); i++) {
            ans.push_back(nums[i]%2);
        }
        return ans;
    }

    int maxZeros(vector<int>& nums, int k){
        int n = nums.size(), l = 0, ans = 0, sum = 0;
        unordered_map<int, int> seen;
        seen[0] = 1;
        for(int r = 0 ; r < n ; r++ ) {
            sum+=nums[r];
            if(seen.count(sum-k)){
                ans+=seen[sum-k];
            }
            seen[sum]++;
        }
        return ans;
    }
    int atMost(vector<int>& nums, int k){
        int n = nums.size(), l = 0, ans = 0, cnt = 0;
        for(int r = 0 ; r < n ; r++ ) {
            if(nums[r]%2) cnt++;
            while(cnt>k){
                if(nums[l]%2) cnt--;
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, ans1 = atMost(nums, k) , ans2 = atMost(nums, k-1);
        ans = ans1-ans2;
        return ans;
    }
};

// ---------- local test harness (optional) — build an example and print ----------
int main() {
    Solution sol;
    // vector<int> nums = {2, 1, 1};
    // cout << sol.numberOfSubarraysBrute(nums, 2) << '\n';  // expect 2
    // cout << sol.numberOfSubarrays(nums, 2)      << '\n';  // expect 2
    return 0;
}
