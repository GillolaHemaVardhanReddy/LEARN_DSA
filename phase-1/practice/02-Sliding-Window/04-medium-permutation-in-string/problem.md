# LC 567 — Permutation in String  ·  Medium   ·   FIXED WINDOW + FREQUENCY MATCH

**Link:** https://leetcode.com/problems/permutation-in-string/
**Topic:** Fixed-size sliding window (size = s1.length) comparing frequency maps

---

## Problem (plain English)
Return `true` if `s2` contains a **permutation of `s1`** as a contiguous substring — i.e.
some window in `s2` of length `s1.length` has the **same letter frequencies** as `s1`.

## Examples
| s1 | s2 | answer |
|---|---|---|
| "ab" | "eidbaooo" | true ("ba") |
| "ab" | "eidboaoo" | false |

## Constraints
- `1 ≤ s1.length, s2.length ≤ 10^4`, lowercase letters.

## Before you code
1. Window size is **fixed** = `s1.length`. Build a target freq (26) for `s1`.
2. Slide a same-size window over `s2`, maintaining its freq; when the two freq arrays match → true.
3. O(26) comparison per step, or keep a "matches" counter to make each step O(1).

## Result log
- Status: ___   How I compared the two frequency maps efficiently: ___
