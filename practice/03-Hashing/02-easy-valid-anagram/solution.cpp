// LC 242 — Valid Anagram  (Frequency count)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // ───── YOUR CODE HERE ─────
        // unordered_map<char,int> seen1, seen2;
        if(s.length() != t.length()) return false;
        // for(int i = 0 ; i < s.length(); i++){
        //     seen1[s[i]]++;
        //     seen2[t[i]]++;
        // }
        // for(int i = 0 ; i < t.length(); i++){
        //     if(!seen1.count(t[i])) return false;
        //     else if(seen1[t[i]] != seen2[t[i]]) return false;
        // }
        int check[26] = {0};
        for(int i = 0 ; i < s.length(); i++){
            check[s[i]-'a']++;
            check[t[i]-'a']--;
        }
        for(int i = 0 ; i < s.length(); i++){
            if(check[s[i]-'a'] > 0) {
                return false;
            }
        }
        return true; // replace
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    cout << sol.isAnagram("anagram", "nagaram") << "  (expect 1)\n";
    cout << sol.isAnagram("rat", "car")         << "  (expect 0)\n";
    return 0;
}
