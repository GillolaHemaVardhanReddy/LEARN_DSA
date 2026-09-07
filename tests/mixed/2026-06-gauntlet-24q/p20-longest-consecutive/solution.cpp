// P20 — longest consecutive (LeetCode signature wired in below).
// Workflow: fill BRUTE first (your words + TC/SC), then derive OPTIMAL in the
// bridge comment, then implement OPTIMAL. No notes.md needed.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ============================ BRUTE FORCE ============================
    // My idea (plain words):
    //   obvious thing to do is just sort the array and scan whole array for the consicutive ness
    //
    // Time:  O(nlogn)   — why: caused due to sort
    // Space: O(1)   — why: no extra space used 
    int longestConsecutiveBrute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 1) return 1;
        int count = 1 , ans = 0;
        for(int i = 1 ; i < nums.size(); i++ ) {
            ans = max(ans, count);
            if(nums[i-1] == nums[i]-1){
                count++;
            } else if(nums[i-1]==nums[i]){
                continue;
            } else {
                count = 1;
            }
        }
        return ans > 0 ? ans : 0;
    }

    // ================= HOW I DERIVED BRUTE -> OPTIMAL =================
    // The Bridge (answer in order, your own words):
    //   1. Where is the repeated work?        -> no repeated work here
    //   2. What is it recomputing each pass?   -> nothing recomputing on each process
    //   3. What tool kills that recompute?     -> expensive work is sort so we need to reduce that
    //
    // My derivation, clearly:
    //   since we always check for prev num if that is equal when added by 1 we could simply use hash map for this
    // =================================================================

    // ============================== OPTIMAL =============================
    // My idea (plain words):
    //   ...
    //
    // Time:  O(n)   — why: due to loop
    // Space: O(n)   — why: due to hash map
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), count = 0, ans = INT_MIN;
        if(n==1) return 1;
        unordered_map<int, int> seen;
        for(int i = 0 ; i < n ; i++ ) {
            seen[nums[i]];
        }
        for(auto& [k,v] : seen) {
            count = 0;
            if(seen.count(k-1)){
                continue;
            }
            long long start = k;
            while(seen.count(start)){
                count++;
                start++;
            }
            ans = max(ans, count);
        }
        if(ans==INT_MIN) return 0;
        return ans;
    }
};

// ---------- local test harness (optional) — build an example and print ----------
int main() {
    Solution sol;
    // build the example input, call brute + optimal, compare outputs.
    return 0;
}
