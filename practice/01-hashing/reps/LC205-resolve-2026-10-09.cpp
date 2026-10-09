// LC205 Isomorphic Strings — +1d COLD re-solve · 2026-10-09 · blank file, no peeking at learn/
// https://leetcode.com/problems/isomorphic-strings/
// Can you replace characters in s to get t? Every occurrence of a char maps to the same char;
// two different chars may NOT map to the same char. 1 <= s.length <= 5*10^4 · t.length == s.length · any ASCII
//
// "egg",   "add"    -> true
// "foo",   "bar"    -> false
// "badc",  "baba"   -> false
//
// STEP 1 — code:

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> ck, cv;
        int n = s.length();
        for(int i = 0; i < n ; i++ ) {
            if((ck.count(s[i]) && ck[s[i]]!=t[i]) || (cv.count(t[i]) && cv[t[i]]!=s[i])){
                return false;
            }
            ck[s[i]] = t[i];
            cv[t[i]] = s[i];
        }
        return true;
    }
};

// STEP 2 — complexity: (times the loop runs) x (cost of one iteration), time AND memory:
