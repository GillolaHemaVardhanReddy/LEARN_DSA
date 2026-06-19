// P19 — min subarray remove divisible (LeetCode signature wired in below).
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
    // Time:  O(?)   — why: ...
    // Space: O(?)   — why: ...
    int minSubarrayBrute(vector<int>& nums, int p) {
        int n = nums.size(), ans = INT_MAX;
        long long S = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0 ; i < n ; i++ ) {
            long long sum = 0;
            int j;
            for(j = i ; j < n ; j++ ) {
                sum+=nums[j];
                if((S-sum)%p==0) ans = min(ans, j - i + 1);
            }
        }
        if(ans == INT_MAX) return -1;
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
    int minSubarray(vector<int>& nums, int p) {
        // TODO(boss): implement.
        return 0;
    }
};

// ---------- local test harness (optional) — build an example and print ----------
int main() {
    Solution sol;
    // build the example input, call brute + optimal, compare outputs.
    return 0;
}
