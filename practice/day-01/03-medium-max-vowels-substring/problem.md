# LC 1456 — Maximum Number of Vowels in a Substring of Given Length  ·  Medium   ·   COLD

**Link:** https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
**Day:** practice/day-01   **Tier:** Medium — no pattern named. Classify it yourself.

---

## Problem (plain English)
Given a string `s` and an integer `k`, look at **every contiguous substring of length
exactly `k`**. Return the **maximum number of vowels** (`a e i o u`) any one of them
contains.

## Examples
| s | k | answer | why |
|---|---|---|---|
| "abciiidef" | 3 | **3** | "iii" has 3 vowels |
| "aeiou" | 2 | **2** | every length-2 piece is all vowels |
| "leetcode" | 3 | **2** | "lee" / "eet" / "cod"... best is "eet"→2 (and "ode"→2) |

## Constraints
- `1 ≤ k ≤ s.length ≤ 10^5`   → recomputing each window from scratch is O(n·k) → too slow; aim O(n).
- `s` is lowercase English letters.

---

## YOUR recognition work (fill BEFORE coding)
1. Brute force (count vowels in every length-k window separately) + its complexity: ___
2. The bottleneck — what work repeats between window `i` and window `i+1`? ___
3. **Which pattern, and what surface cue pointed you to it?** ___
   (hint to yourself: the window size is **fixed and given** — what does that signal?)
4. Optimal: how do you update the vowel count in O(1) when the window slides by one? ___

## Result log
- Status: ___ (Accepted / WA / TLE)   Pattern I chose: ___   Right? ___
- What tripped me up: ___
