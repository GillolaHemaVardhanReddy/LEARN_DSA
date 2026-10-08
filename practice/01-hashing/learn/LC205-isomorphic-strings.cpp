// LC205 Isomorphic Strings — rung 6/6 · 2026-10-08
// https://leetcode.com/problems/isomorphic-strings/
// s and t are isomorphic if you can replace characters in s to get t.
// Every occurrence of a character must be replaced with the same character.
// Two different characters may NOT map to the same character. A character may map to itself.
// 1 <= s.length <= 5 * 10^4 · t.length == s.length · s, t = any valid ASCII characters
//
// "egg",   "add"    -> true
// "foo",   "bar"    -> false
// "paper", "title"  -> true
//
// STEP 1 — restate in exact units + dry run on "foo"/"bar" (what breaks?):
//
// STEP 2 — budget line (brute in digits, what I can afford):
//
// STEP 3 — code:

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> ck, cv;
        for(int i = 0 ; i < s.length(); i++ ) {
            if((ck.count(s[i]) && ck[s[i]] != t[i]) || (cv.count(t[i]) && cv[t[i]] != s[i])){
                return false;
            }
            ck[s[i]] = t[i];
            cv[t[i]] = s[i];
        }
        return true;
    }
};

// STEP 4 — complexity: (times the loop runs) x (cost of one iteration), time AND memory, line behind each factor:
