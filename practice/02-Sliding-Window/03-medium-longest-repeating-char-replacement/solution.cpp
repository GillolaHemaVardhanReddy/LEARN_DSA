// LC 424 — Longest Repeating Character Replacement  (Variable Window, longest)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        // ───── YOUR CODE HERE ─────
        // freq[26], maxFreq. expand right; while (len - maxFreq > k) shrink left.
        // ans = max valid window length.
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
