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
    // Time:  O(?)   — why: ...
    // Space: O(?)   — why: ...
    int numberOfSubarraysBrute(vector<int>& nums, int k) {
        // TODO(boss): the obvious "try all subarrays, count odds, tally == k".
        return 0; // placeholder so it compiles while you work
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
    int numberOfSubarrays(vector<int>& nums, int k) {
        // TODO(boss): implement the optimal you derived above.
        return 0; // placeholder so it compiles while you work
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
