// P15 — sort by frequency (LeetCode signature wired in below).
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
    // Time:  O(n)   — why: we just push freq maps and then use that freq map sort and build the ans string
    // Space: O(n)   — why: other than ans we have 2 extra spaces of size n
    string frequencySortBrute(string s) {
        int n = s.length();
        unordered_map<char,int> check;
        for(int i = 0 ; i < n ; i++){
            check[s[i]]++;
        }
        vector<pair<int,char>> check2;
        for(auto& [key, value]: check){
            check2.push_back({value, key});
        }
        sort(check2.begin(), check2.end(), greater<>());
        string ans = "";
        for(auto& [v,c]: check2){
            ans.append(v,c);
        }
        return ans;
    }

    // ================= HOW I DERIVED BRUTE -> OPTIMAL =================
    // The Bridge (answer in order, your own words):
    //   1. Where is the repeated work?        -> repeated work is near create freq map and dumping into another array by sorting
    //   2. What is it recomputing each pass?   -> work of pushing data from one space to another
    //   3. What tool kills that recompute?     -> well you actually revealed the answer previously bucket sort where we keep index as freq and value as char

    //
    // My derivation, clearly:
    //   ...
    // =================================================================

    // ============================== OPTIMAL =============================
    // My idea (plain words):
    /*
        so since we have more auxilaryn space we need to reduce that and TC stays same
    */
    //
    // Time:  O(n)   — why: ...
    // Space: O(1)   — why: ...
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char,int> check;
        for(int i = 0 ; i < n ; i++){
            check[s[i]]++;
        }

        vector<vector<int>> freq(n+1);
        for(auto& [a,b] : check) {
            freq[b].push_back(a);
        }
        
        string ans = "";
        for(int i = n-1 ; i > 0 ; i-- ) {
            for(auto& a:freq[i]) ans.append(i,a);
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
