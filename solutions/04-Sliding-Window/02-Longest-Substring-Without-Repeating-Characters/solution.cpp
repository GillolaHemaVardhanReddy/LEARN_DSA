// LC 3 — Longest Substring Without Repeating Characters (Variable Sliding Window, LONGEST)
// Paste ONLY the Solution class into LeetCode. main() is a local test harness.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // ───── YOUR CODE HERE ─────
        // Longest valid window: expand right; while a duplicate exists, shrink left;
        // record best AFTER the window is valid again.
        int ans = 0;
        unordered_set<char> response;
        int start_ind = 0;
        if(s.length()==0){
            return 0;
        }
        for(int i=0; i<s.length(); i++){
            while(response.count(s[i])){
                response.erase(s[start_ind]);
                start_ind++;
            }
            response.insert(s[i]);
            ans = max(ans, i - start_ind + 1);
        }

        return ans; // replace
    }
};

// ───────── local test harness (ignore when pasting to LeetCode) ─────────
int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcabcbb") << "  (expect 3)\n";
    cout << sol.lengthOfLongestSubstring("bbbbb")    << "  (expect 1)\n";
    cout << sol.lengthOfLongestSubstring("pwwkew")   << "  (expect 3)\n";
    cout << sol.lengthOfLongestSubstring("")         << "  (expect 0)\n";
    return 0;
}
