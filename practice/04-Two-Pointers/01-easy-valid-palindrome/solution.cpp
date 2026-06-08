// LC 125 — Valid Palindrome  ·  CONVERGING two pointers + skip
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // cue: compare from both ends -> converging two pointers
        // L=0, R=n-1; skip non-alphanumeric; compare tolower. Keep L<R while skipping.
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << "  (expect 1)\n";
    cout << sol.isPalindrome("race a car")                     << "  (expect 0)\n";
    cout << sol.isPalindrome(" ")                              << "  (expect 1)\n";
    return 0;
}
