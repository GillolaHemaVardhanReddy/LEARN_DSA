// LC 242 — Valid Anagram  (Frequency count)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // ───── YOUR CODE HERE ─────
        // length check, then count s up / t down in a 26-array (or map); all zero -> true.
        return false; // replace
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    cout << sol.isAnagram("anagram", "nagaram") << "  (expect 1)\n";
    cout << sol.isAnagram("rat", "car")         << "  (expect 0)\n";
    return 0;
}
