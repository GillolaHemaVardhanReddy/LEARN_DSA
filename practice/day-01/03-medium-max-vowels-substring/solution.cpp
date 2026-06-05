// LC 1456 — Maximum Number of Vowels in a Substring of Given Length
// COLD — classify it yourself (see problem.md), then implement.
// Paste ONLY the Solution class into LeetCode. main() is for local testing on onlinegdb.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        // ───── YOUR CODE HERE ─────

        return 0; // replace
    }
};

// ───────── local test harness (ignore when pasting to LeetCode) ─────────
int main() {
    Solution sol;
    cout << sol.maxVowels("abciiidef", 3) << "  (expect 3)\n";
    cout << sol.maxVowels("aeiou", 2)     << "  (expect 2)\n";
    cout << sol.maxVowels("leetcode", 3)  << "  (expect 2)\n";
    return 0;
}
