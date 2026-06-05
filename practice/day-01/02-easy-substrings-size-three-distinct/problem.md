# LC 1876 — Substrings of Size Three with Distinct Characters  ·  Easy   ·   COLD

**Link:** https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/
**Day:** practice/day-01   **Tier:** Easy — no pattern named. Classify it yourself.

---

## Problem (plain English)
A string is "good" if it has **no repeated characters**. Given a string `s`, count how many
of its **contiguous substrings of length exactly 3** are good. (Overlapping ones count
separately — return the total count, not the distinct ones.)

## Examples
| s | answer | why |
|---|---|---|
| "xyzzaz" | **1** | length-3 pieces: xyz✓, yzz✗, zza✗, zaz✗ → 1 good |
| "aababcabc" | **4** | abc, bca, cab, abc are the good ones |

## Constraints
- `1 ≤ s.length ≤ 100`  (small — but still solve it the O(n) way on purpose)
- `s` is lowercase English letters.

---

## YOUR recognition work (fill BEFORE coding)
1. Brute force + complexity: ___
2. What's fixed about the thing you're scanning? What does that signal? ___
3. **Which pattern, and what cue?** ___
4. Optimal approach + complexity: ___

## Result log
- Status: ___   Pattern I chose: ___   Right? ___
- What tripped me up: ___
