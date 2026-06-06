// LC 567 — Permutation in String  (Fixed Window + frequency match)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // ───── YOUR CODE HERE ─────
        // target freq of s1. slide window of size s1.size() over s2; compare freqs.
        return false; // replace
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    cout << sol.checkInclusion("ab", "eidbaooo") << "  (expect 1)\n";
    cout << sol.checkInclusion("ab", "eidboaoo") << "  (expect 0)\n";
    return 0;
}
