# LC 424 — Longest Repeating Character Replacement  ·  Medium   ·   VARIABLE WINDOW

**Link:** https://leetcode.com/problems/longest-repeating-character-replacement/
**Topic:** Variable sliding window (longest) + frequency count

---

## Problem (plain English)
You may change **at most `k`** characters of `s` (each to any uppercase letter). Return the
length of the **longest substring** of a single repeated letter you can make.

## Examples
| s | k | answer | why |
|---|---|---|---|
| "ABAB" | 2 | 4 | change 2 to make "AAAA" or "BBBB" |
| "AABABBA" | 1 | 4 | window "AABA"→"AAAA" (one change) |

## Constraints
- `1 ≤ s.length ≤ 10^5`, uppercase letters, `0 ≤ k ≤ s.length`

## Before you code (LONGEST variant — shrink while INVALID, record AFTER)
1. A window is **valid** if `(windowLen - countOfMostFrequentCharInWindow) ≤ k`
   (the non-majority chars are the ones you'd replace).
2. Keep a freq array (26). Track the **max frequency** seen in the window.
3. If invalid (`len - maxFreq > k`), shrink from the left by one. Answer = largest valid `len`.

## Result log
- Status: ___   What "valid" meant here: ___
