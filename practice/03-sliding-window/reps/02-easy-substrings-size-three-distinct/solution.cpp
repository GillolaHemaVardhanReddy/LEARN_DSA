// LC 1876 — Substrings of Size Three with Distinct Characters  (Fixed Window)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        // ───── YOUR CODE HERE ─────
        int n = s.length();
        int cnt = 0;
        for(int i = 0 ; i < n-2 ; i++ ) {
            if(s[i]!=s[i+1] && s[i+1] != s[i+2] && s[i] != s[i+2]) cnt++;
        }
        return cnt; // replace
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    cout << sol.countGoodSubstrings("xyzzaz")    << "  (expect 1)\n";
    cout << sol.countGoodSubstrings("aababcabc") << "  (expect 4)\n";
    return 0;
}
