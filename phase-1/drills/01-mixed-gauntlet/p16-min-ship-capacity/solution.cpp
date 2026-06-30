// P16 — min ship capacity (LeetCode signature wired in below).
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
    // Time:  O(k*n)   — why: k is loop on max till sum and n is on i = 0 till length of weights
    // Space: O(1)   — why: not used any extra space

    int checkWeight(vector<int>& w, int cap){
        int sum = 0, d = 0;
        for(int i = 0 ; i < w.size(); i++){
            if(sum + w[i]>cap) {
                d++;
                sum = 0
            }
            sum+=w[i];
        }
        return d+1;
    }

    int shipWithinDaysBrute(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end()), end = accumulate(weights.begin(), weights.end(), 0), ans = end+1;
        // brute force
        for(int i = start; i <= end; i++ ) {
            int k = checkWeight(weights, i);
            if(k <= days) ans = min(ans, i);
        }
        return ans;
    }

    // ================= HOW I DERIVED BRUTE -> OPTIMAL =================
    // The Bridge (answer in order, your own words):
    //   1. Where is the repeated work?        -> no repeated work here
    //   2. What is it recomputing each pass?   -> checkweight on each pass
    //   3. What tool kills that recompute?     -> binary search
    //
    // My derivation, clearly:
    /*
        well since its monotonic and can be deterministic and so we can just start from random middle so we can know which side to move to get min
        also we know as we incr size we can move packages of more weights in less days
    */   
    // =================================================================

    // ============================== OPTIMAL =============================
    // My idea (plain words):
    //   ...
    //
    // Time:  O(k*logn)   — why: ...
    // Space: O(1)   — why: ...
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end()), end = accumulate(weights.begin(), weights.end(),0), ans = end+1;
        while(start <= end){
            int mid = start + (end - start)/2;
            int k = checkWeight(weights, mid);
            if(k > days) start = mid + 1;
            else {
                ans = min(ans, mid);
                end = mid - 1;
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
