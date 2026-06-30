// P23 — fruit into baskets (LeetCode signature wired in below).
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
    // Time:  O(n^2)   — why: 2 loops
    // Space: O(n)   — why: an extra set
    int totalFruitBrute(vector<int>& fruits) {
        int n = fruits.size(), sum = 1 , ans = INT_MIN;
        for(int i = 0 ; i < n ; i++ ) {
            set<int> picked;
            picked.insert(fruits[i]);
            sum = 1;
            for(int j = i+1; j<n ; j++ ) {
                if(picked.contains(fruits[j])){
                    sum++;
                } else {
                    if(picked.size()<=1) {
                        picked.insert(fruits[j]);
                        sum++;
                    } else {
                        break;
                    }
                }
            }
            ans = max(ans, sum);
        }
        return ans;
    }

    // ================= HOW I DERIVED BRUTE -> OPTIMAL =================
    // The Bridge (answer in order, your own words):
    //   1. Where is the repeated work?        -> we continuously check for sum using inner loop
    //   2. What is it recomputing each pass?   -> sum
    //   3. What tool kills that recompute?     -> variable sliding window
    //
    // My derivation, clearly:
    /*   since we move one step each and stop when 3rd encounter 
        we could just use 2 variables one acts as running another as fixed we move fixed on violation of condition
        and we move running untill condition stays true
    */
    // =================================================================

    // ============================== OPTIMAL =============================
    // My idea (plain words):
    //   ...
    //
    // Time:  O(?)   — why: ...
    // Space: O(?)   — why: ...
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), sum = 1 , ans = INT_MIN, r = 0 , l = 0;
        unordered_map<int, int> picked;
        picked[fruits[r]] = r;
        r++;
        while(l<=r && r<n){
            if(picked.count(fruits[r])){
                sum++;
                ans = max(ans, sum);
                picked[fruits[r]] = r;
                r++;
            } else {
                if(picked.size()<=1){
                    picked[fruits[r]] = r;
                    r++;
                    sum++;
                    ans = max(ans, sum);
                } else {
                    ans = max(ans, sum);
                    int target_remove = INT_MAX;
                    int key ;
                    for(auto& [k,v] : picked){
                        if(target_remove > v){
                            target_remove = v;
                            key = k;
                        }
                    }
                    picked.erase(key);
                    while( l<=target_remove ){
                        sum--;
                        l++;
                    }
                }
            }
        }
        return ans==INT_MIN ? 1 : ans;
    }
};

// ---------- local test harness (optional) — build an example and print ----------
int main() {
    Solution sol;
    // build the example input, call brute + optimal, compare outputs.
    return 0;
}
