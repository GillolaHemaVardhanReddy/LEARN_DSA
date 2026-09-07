// P22 — closest triplet sum (LeetCode signature wired in below).
// Workflow: fill BRUTE first (your words + TC/SC), then derive OPTIMAL in the
// bridge comment, then implement OPTIMAL. No notes.md needed.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ============================ BRUTE FORCE ============================
    // My idea (plain words):
    //   ...
    //
    // Time:  O(n^3)   — why: 3 loops
    // Space: O(1)   — why: no extra space
    int threeSumClosestBrute(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0 , ans = INT_MAX, compare = INT_MAX;
        for(int i = 0 ; i < n ; i++ ) {
            for(int j = i+1 ; j < n ; j++ ) {
                for(int k = j+1 ; k < n ; k++ ) {
                    sum = nums[i]+nums[j]+nums[k];
                    if(compare > abs(sum - target)){
                        compare = abs(sum - target);
                        ans = sum;
                    }

                }
            }
        }
        return ans;
    }

    // ================= HOW I DERIVED BRUTE -> OPTIMAL =================
    // The Bridge (answer in order, your own words):
    //   1. Where is the repeated work?        -> ...
    //   2. What is it recomputing each pass?   -> ...
    //   3. What tool kills that recompute?     -> ...
    //
    // My derivation, clearly:
    //   ...
    // =================================================================

    // ============================== OPTIMAL =============================
    // My idea (plain words):
    //   ...
    //
    // Time:  O(?)   — why: ...
    // Space: O(?)   — why: ...
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), l = 0 , r = n-1, sum = 0, ans = INT_MAX, compare = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int f = 0 ; f < n ; f++ ) {
            l = f+1; r = n-1;
            while(r>l){
                sum = nums[f] + nums[r] + nums[l];
                if(compare > abs(sum-target)){
                    compare = abs(sum-target);
                    ans = sum;
                }
                if((sum<target)) l++;
                else if((sum > target)) r--;
                else {
                    r--;
                    l++;
                }
            }
        }
        return ans;
    }
};

// ---------- local test harness (optional) — build an example and print ----------
int main() {
    Solution sol;
    // build the example input, call brute + optimal, compare outputs.
    return 0;
}
