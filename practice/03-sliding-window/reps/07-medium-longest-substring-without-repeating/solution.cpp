// LC 3 — Longest Substring Without Repeating Characters  (Variable Window, LONGEST)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // YOUR CODE HERE.
        unordered_map<char, int> seen;
        int ans = 0, left = 0, n = s.length();
        for(int right = 0 ; right < n; right++){
            seen[s[right]]++;
            while(seen[s[right]] > 1) {
                seen[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcabcbb") << "  (expect 3)\n";
    cout << sol.lengthOfLongestSubstring("bbbbb")    << "  (expect 1)\n";
    cout << sol.lengthOfLongestSubstring("pwwkew")   << "  (expect 3)\n";
    cout << sol.lengthOfLongestSubstring("")         << "  (expect 0)\n";
    return 0;
}
