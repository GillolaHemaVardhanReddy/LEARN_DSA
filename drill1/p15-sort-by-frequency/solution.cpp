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
    // Time:  O(n)   — why: ...
    // Space: O(1)   — why: ...
    string frequencySortBrute(string s) {
        int n = s.length();
        unordered_map<char,int> check;
        for(int i = 0 ; i < n ; i++){
            check[s[i]]++;
        }
        vector<pair<char,int>> check2;
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
    string frequencySort(string s) {
        // TODO(boss): implement.
        return "";
    }
};

// ---------- local test harness (optional) — build an example and print ----------
int main() {
    Solution sol;
    // build the example input, call brute + optimal, compare outputs.
    return 0;
}
