// LC 76 — Minimum Window Substring  (Variable Window, shortest + frequency)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // ───── YOUR CODE HERE ─────
        // need[char]++, required = distinct chars. expand right; while valid, record + shrink left.
        return ""; // replace
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    cout << sol.minWindow("ADOBECODEBANC", "ABC") << "  (expect BANC)\n";
    cout << sol.minWindow("a", "a")               << "  (expect a)\n";
    cout << "[" << sol.minWindow("a", "aa")       << "]  (expect [])\n";
    return 0;
}
