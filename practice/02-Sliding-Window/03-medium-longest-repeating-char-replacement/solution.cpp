// LC 424 — Longest Repeating Character Replacement  (Variable Window, longest)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        // ───── YOUR CODE HERE ─────
        int n = s.length();
        unordered_map<char, int> seen;
        int start_ind = 0;
        for(int i = 0 ; i < n ; i++ ) {
            
            seen[s[i]]+=1;
        }
        return 0; // replace
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    cout << sol.characterReplacement("ABAB", 2)    << "  (expect 4)\n";
    cout << sol.characterReplacement("AABABBA", 1) << "  (expect 4)\n";
    return 0;
}
