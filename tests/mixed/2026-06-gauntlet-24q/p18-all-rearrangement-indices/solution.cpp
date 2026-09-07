// P18 — all rearrangement indices (LeetCode signature wired in below).
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
    // Time:  O(n*m*logm)   — why: 2 loops 
    // Space: O(m)   — why: comp
    vector<int> findAnagramsBrute(string s, string p) {
        int n = s.length(), m = p.length();
        vector<int> ans;
        string comp1 = "", comp2 = p;
        sort(comp2.begin(), comp2.end());
        for(int i = 0 ; i <= n-m ; i ++){
            int k = 0;
            comp1 = "" ;
            for(int j = i; j< i+m; j++) {
                comp1.append(1, s[j]);
            }
            sort(comp1.begin(), comp1.end());
            for(int j = 0 ; j < m; j++) {
                if(comp1[j]==comp2[j]) k++;
                else break;
            }
            if(k==m) ans.push_back(i);
        }
        return ans;
    }

    // ================= HOW I DERIVED BRUTE -> OPTIMAL =================
    // The Bridge (answer in order, your own words):
    //   1. Where is the repeated work?        -> we repeatedly sort the taken part from s and compare with p repeatedly
    //   2. What is it recomputing each pass?   -> sort and compare
    //   3. What tool kills that recompute?     -> i was thinking about fixed sliding window? because p is fixed length which we scan in s
    //
    // My derivation, clearly:
    //   so since we each time go from i till i+m on s we could just use fixed sliding window and see if the addition of next char
    //   and removal of first char benifits for anagram or not and then if not then we can move whole fixed window from next char till +m
    // =================================================================

    // ============================== OPTIMAL =============================
    // My idea (plain words):
    //   ...
    //
    // Time:  O(n)   — why: its just one pass
    // Space: O(1)   — why: no extra space
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), m = p.length(), l = 0, k = 0;
        if(n<m) return {};
        vector<int> ans;
        int comp1[26] = {0}, comp2[26] = {0};
        for(int i = 0 ; i < m ; i++ ) {
            comp1[p[i]-'a']++;
        }
        for(int r = 0 ; r < m ; r++ ) {
            comp2[s[r]-'a']++;
        }
        for(int r = m; r <= n ; r++ ) {
            k = 0;
            for(int i = 0 ; i < 26 ; i++ ) {
                if(comp1[i]!=comp2[i]) break;
                else k++;
            }
            if(k==26) ans.push_back(l);
            if(r>=n) break;
            comp2[s[l]-'a']--;
            l++;
            comp2[s[r]-'a']++;
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
