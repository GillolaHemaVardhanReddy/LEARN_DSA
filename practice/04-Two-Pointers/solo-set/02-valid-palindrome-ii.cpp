// LC 680 — Valid Palindrome II  ·  easy  ·  SOLO (converging + at-most-one skip)
// Return true if s can be a palindrome after deleting AT MOST ONE character.
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        // cue: ___ -> converging two pointers; on a mismatch you may skip ONE char (two options to try)
        // YOUR CODE HERE
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.validPalindrome("aba")   << "  (expect 1)\n";
    cout << sol.validPalindrome("abca")  << "  (expect 1)\n";   // delete 'c' (or 'b')
    cout << sol.validPalindrome("abc")   << "  (expect 0)\n";
    return 0;
}
