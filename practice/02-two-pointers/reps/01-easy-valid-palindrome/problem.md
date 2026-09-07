# LC 125 — Valid Palindrome · easy · TWO POINTERS

**Link:** https://leetcode.com/problems/valid-palindrome/
**Building block:** CONVERGING pointers from both ends + **skip** unwanted chars. The gentlest converging rep.

---

## Problem (plain English)
Return `true` if `s` is a palindrome **considering only alphanumeric characters and ignoring case**.
(Lowercase everything, drop non-alphanumeric, then check it reads the same both ways.)

## Examples
| s | answer |
|---|---|
| "A man, a plan, a canal: Panama" | true ("amanaplanacanalpanama") |
| "race a car" | false |
| " " | true (empty after cleaning) |

## Constraints
- 1 ≤ s.length ≤ 2·10⁵ · printable ASCII.

## Before you code (recognition-first)
- cue line: **compare from both ends** → __?
- Shape = **converging**: `L=0`, `R=n-1`, walk toward each other comparing `s[L]` vs `s[R]`.
- The new wrinkle = **skip**: if `s[L]` (or `s[R]`) isn't alphanumeric, advance that pointer **without** comparing.
- Helpers: `isalnum(c)`, `tolower(c)`.
- ⚠️ Boundary: keep `L < R` inside the skip loops too (don't run off the end); empty/all-punctuation → true.

## Result log
- Status: ___   Building block (converging + skip): ___
