// P21 — find a peak (LeetCode signature wired in below).
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
    // Time:  O(n)   — why: one loop only
    // Space: O(1)   — why: no extra space
    int findPeakElementBrute(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        for(int i = 0 ; i < n; i++) {
            if( ((i==n-1) && (nums[i]>nums[i-1])  
                || ((i==0) && (nums[i] > nums[i+1]))
                || ( (!(i==n-1) && !(i==0)) && (nums[i-1] < nums[i]) && (nums[i] > nums[i+1])))
            ) return i;
        }
        return 0;
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
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), mid = 0, l = 0 , r = n-1;
        if(n==1) return 0;
        while(l<=r){
            mid = l + ( r - l ) / 2 ;
            if(nums[mid] < nums[mid+1]){
                l = mid + 1;
            } else if(nums[mid - 1] > nums[mid]){
                r = mid - 1;
            } else {
                return mid;
            }
        }
        return mid;
    }
};

// ---------- local test harness (optional) — build an example and print ----------
int main() {
    Solution sol;
    // build the example input, call brute + optimal, compare outputs.
    return 0;
}
