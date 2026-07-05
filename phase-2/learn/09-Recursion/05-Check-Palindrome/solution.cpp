// 05 — Check Palindrome   (M9 Recursion · a recursion that can RETURN EARLY)
// ---------------------------------------------------------------------------------
// Is the string the same forwards and backwards? Two pointers from the ends inward;
// mismatch anywhere -> false immediately; if they meet/cross, every pair matched -> true.
//
//   "racecar" -> true      "abca" -> false      "" -> true      "a" -> true
//
// ⭐ New idea vs #04: this recursion has TWO base cases and can short-circuit — the
//    moment one pair disagrees you return false without touching the rest.
// =================================================================================
#include <bits/stdc++.h>
using namespace std;

// THE RECIPE:
//   (1) BASE CASE(s)?  l >= r -> return true (all pairs matched, nothing left)
//                      s[l] != s[r] -> return false (found a mismatch, done)
//   (2) SMALLER CALL?  (l+1, r-1)
//   (3) COMBINE?       if the ends match, the answer IS whatever the inside says:
//                      return isPalRec(s, l+1, r-1)

bool isPalRec(const string& s, int l, int r) {
    if(l>=r) return true;
    if(s[l] != s[r]) return false;
    return isPalRec(s, l+1, r-1);
}

bool isPalindrome(const string& s) { return s.empty() ? true : isPalRec(s, 0, (int)s.size() - 1); }

// --- ORACLE: iterative two-pointer palindrome check ------------------------------
bool palOracle(const string& s) {
    int l = 0, r = (int)s.size() - 1;
    while (l < r) { if (s[l] != s[r]) return false; l++; r--; }
    return true;
}

// ---------------------------------------------------------------------------------
// STRESS TEST — recursion vs oracle. Mix random strings (mostly non-pal) with
// deliberately-built palindromes so BOTH true and false paths get hit.
// ---------------------------------------------------------------------------------
int main() {
    srand(7);
    for (int iter = 0; iter < 20000; iter++) {
        int n = rand() % 8;
        string s(n, 'a');
        for (char& c : s) c = 'a' + rand() % 3;      // tiny alphabet -> real palindromes appear
        if (iter % 2 == 0) {                          // half the time, force a palindrome
            for (int i = 0; i < n / 2; i++) s[n - 1 - i] = s[i];
        }
        if (isPalindrome(s) != palOracle(s)) {
            printf("MISMATCH  s=\"%s\"\n", s.c_str());
            return 1;
        }
    }
    printf("all palindrome cases passed (20000 mixed strings, both true & false paths)\n");
    return 0;
}
