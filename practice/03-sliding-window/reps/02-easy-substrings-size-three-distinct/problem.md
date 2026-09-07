# LC 1876 — Substrings of Size Three with Distinct Characters  ·  Easy   ·   FIXED WINDOW

**Link:** https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/
**Topic:** Fixed-size sliding window (size 3) + small frequency check

---

## Problem (plain English)
Count contiguous substrings of **length exactly 3** that have **no repeated character**.
Overlapping windows count separately.

## Examples
| s | answer |
|---|---|
| "xyzzaz" | 1 |
| "aababcabc" | 4 |

## Constraints
- `1 ≤ s.length ≤ 100`, lowercase letters. (Small — but practise the O(n) window anyway.)

## Before you code
1. Slide a window of size 3; a window is "good" if all 3 chars differ.
2. Check distinctness with a tiny frequency count or a 3-way comparison.

## Result log
- Status: ___   How I checked distinctness: ___
