// LC 567 — Permutation in String  (Fixed Window + frequency match)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // ───── YOUR CODE HERE ─────
        int s1map[26] = {0},s2map[26] = {0};
        if(s2.length() < s1.length()) return false;
        for(int i = 0 ; i < s1.length(); i++) {
            s1map[s1[i] - 'a']++;
            s2map[s2[i] - 'a']++;
        }
        int ans = true;
        for(int i = 0; i < 26; i++){
            if(s1map[i] != s2map[i]) {ans = false; break;}
        }
        if(ans) return ans;
        for(int right = s1.length() ; right < s2.length(); right++){
            s2map[s2[right - s1.length()] - 'a']--;
            s2map[s2[right] - 'a']++;
            int ind = 0, both_match = true;
            for(int i = 0; i < 26; i++){
                if(s1map[i] != s2map[i]) {both_match = false; break;}
            }
            if(both_match) return true;
        }
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
