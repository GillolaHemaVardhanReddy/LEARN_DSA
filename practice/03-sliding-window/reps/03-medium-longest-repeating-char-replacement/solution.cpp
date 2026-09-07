// LC 424 — Longest Repeating Character Replacement  (Variable Window, longest)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int seen[26] = {0};
        int ans = 0, maxFreq = 0, left = 0;
        for(int right = 0; right < s.length(); right++) {
            seen[s[right] - 'A']++;
            maxFreq = max(maxFreq, seen[s[right] - 'A']);
            if((right - left +1) - maxFreq > k){
                seen[s[left]]--;
                left++;
            }
            ans = max(ans, right-left+1);
        }   
        return ans; 
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    cout << sol.characterReplacement("ABAB", 2)    << "  (expect 4)\n";
    cout << sol.characterReplacement("AABABBA", 1) << "  (expect 4)\n";
    return 0;
}
