// LC 680 — Valid Palindrome II  ·  easy  ·  SOLO (converging + at-most-one skip)
// Return true if s can be a palindrome after deleting AT MOST ONE character.
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkPoly(string s, int start, int end){
        while(start<end){
            if(s[start]!=s[end]) return false; 
            start++; 
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        // cue: ___ -> converging two pointers; on a mismatch you may skip ONE char (two options to try)
        int n = s.length();
        int st = 0 , en = n-1;
        while(st<en){
            if(s[st]!=s[en]){
                return checkPoly(s, st+1, en) || checkPoly(s, st, en-1);   
            }
            st++;
            en--;
        }
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
