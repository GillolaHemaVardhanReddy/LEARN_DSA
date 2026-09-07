# 05 — Check Palindrome  (M9 Recursion · a recursion that RETURNS EARLY)

🔗 **LC125 — Valid Palindrome**  ·  https://leetcode.com/problems/valid-palindrome/  (EASY)
Real judge target — with one TWIST beyond the drill: LC125 ignores non-alphanumerics and case.
Do the pure drill here first (bare two-pointer recursion), THEN handle LC125's filtering and submit.

**Goal (drill):** same forwards & backwards? Two pointers inward; mismatch → `false` at once;
pointers meet/cross → every pair matched → `true`.

## Signature (drill)
```cpp
bool isPalRec(const string& s, int l, int r);
```
## LC125 signature
```cpp
bool isPalindrome(string s);   // consider only alphanumeric, case-insensitive
```

## Example
```
drill:  "racecar" -> true    "abca" -> false    "" -> true    "a" -> true
LC125:  "A man, a plan, a canal: Panama" -> true    "race a car" -> false
```

## The idea to derive (⭐ new vs #04)
TWO base cases + **short-circuit**: `l>=r -> true`, `s[l]!=s[r] -> false`, else
`return isPalRec(s, l+1, r-1)` (the answer IS whatever the inside says). You return the moment
one pair disagrees — you don't touch the rest.

For LC125: skip non-alphanumeric on each side (`while (l<r && !isalnum(s[l])) l++;` etc.),
lowercase-compare (`tolower`). The recursion core is identical.

## Judge graduation
✅ **Submit LC125.** Watch the filter edges (all-punctuation string → `true`; `"0P"` → `false`,
`'0'` vs `'p'`). This is your boundary/sentinel leak territory — trace before submit.
