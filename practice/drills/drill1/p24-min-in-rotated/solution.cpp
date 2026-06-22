// P24 — min in rotated (LeetCode signature wired in below).
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
    // Time:  O(n)   — why: we just have to find the min and it only takes 1 loop
    // Space: O(1)   — why: no extra space
    int findMinBrute(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        for(int i = 0 ; i < n ; i++ ) {
            ans = min(nums[i], ans);
        }
        return ans;
    }

    // ================= HOW I DERIVED BRUTE -> OPTIMAL =================
    // The Bridge (answer in order, your own words):
    //   1. Where is the repeated work?        -> no repeated work
    //   2. What is it recomputing each pass?   -> no recomputation
    //   3. What tool kills that recompute?     -> 
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
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        int middle;
        while(i < j) {
            middle = (i + j) / 2;
            if(nums[middle] < nums[j]){
                j = middle;
            } else {
                i = middle + 1;
            }      
        }
        return nums[i];
    }
};

// ---------- STRESS TEST: brute (oracle) vs optimal, random rotated arrays ----------
int main() {
    Solution sol;
    mt19937 rng(12345);                 // fixed seed = reproducible failures
    const int ITERS = 100000;
    for (int t = 0; t < ITERS; t++) {
        int n = 1 + rng() % 8;          // tiny: sizes 1..8
        // build a STRICTLY INCREASING array (LC153 = distinct), then rotate.
        vector<int> a(n);
        int cur = -5 + (int)(rng() % 5);
        for (int i = 0; i < n; i++) { cur += 1 + rng() % 4; a[i] = cur; }
        int k = rng() % n;              // rotate left by k → sorted-rotated
        rotate(a.begin(), a.begin() + k, a.end());

        vector<int> b = a;              // each call may mutate; isolate inputs
        int expected = sol.findMinBrute(a);
        int got      = sol.findMin(b);
        if (expected != got) {
            cout << "MISMATCH on [";
            for (int i = 0; i < n; i++) cout << a[i] << (i+1<n?",":"");
            cout << "]  brute=" << expected << "  optimal=" << got << "\n";
            return 1;
        }
    }
    cout << "ALL " << ITERS << " RANDOM CASES PASSED  (optimal == brute oracle)\n";
    return 0;
}
