# LC 3 — Longest Substring Without Repeating Characters  ·  Medium

**Link:** https://leetcode.com/problems/longest-substring-without-repeating-characters/
**Module:** M4 Sliding Window  **Pattern:** Variable Sliding Window (**LONGEST** variant)

---

## Problem (plain English)
Given a string `s`, find the **length of the longest substring** that has **no repeating
characters**. ("Substring" = contiguous, just like subarray but for strings.)

## Examples
| s | answer | the substring |
|---|---|---|
| "abcabcbb" | **3** | "abc" |
| "bbbbb" | **1** | "b" |
| "pwwkew" | **3** | "wke"  (note: "pwke" is a *subsequence*, not substring — not allowed) |
| "" | **0** | — |

## Constraints
- `0 ≤ s.length ≤ 5 * 10^4`   → need **O(n)**
- `s` may contain letters, digits, symbols, spaces.

---

## This is the LONGEST variant — so it flips LC209
- LC209 (shortest): shrink **while valid**, record answer **inside** the while.
- LC3 (longest): you keep a **valid** window and shrink only **while it becomes invalid**
  (a duplicate appeared), recording the best length **after** the window is valid again.

## The new sub-question to solve
"No repeating characters" — **how do you know, in O(1), whether the character you just added
is already inside the current window?** Think about what data structure answers
"is this here / how many times?" instantly. (We'll discuss it together.)

## Before you code — decide these
1. What's `best` initialized to for a *longest* hunt? (Different from the min case!)
2. When a duplicate enters, what exactly do you remove from the left, and until when?
3. Where does `best = max(...)` go — inside or after the shrink loop?

## Result log (fill after submitting)
- Status: ___   Runtime: ___   Hints used (L0–L5): ___
- What tripped me up: ___
