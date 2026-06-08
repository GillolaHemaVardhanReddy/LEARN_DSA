# LC 3 — Longest Substring Without Repeating Characters  ·  Medium  ·  VARIABLE WINDOW

**Link:** https://leetcode.com/problems/longest-substring-without-repeating-characters/
**Topic:** Variable sliding window (LONGEST) + "last seen" / frequency tracking

---

## Problem (plain English)
Return the length of the **longest substring** of `s` that contains **no repeated
character**.

## Examples
| s | answer | why |
|---|---|---|
| "abcabcbb" | 3 | "abc" |
| "bbbbb" | 1 | "b" |
| "pwwkew" | 3 | "wke" (note: "pwke" is a subsequence, NOT a substring) |
| "" | 0 | empty |

## Constraints
- `0 ≤ s.length ≤ 5·10^4`, any ASCII characters (NOT just uppercase — don't assume 26)

## Before you code — same family as LC 424, different cue
This is a **LONGEST** window again, but the invalid condition is different:
1. A window is **valid** while every character in it is unique.
2. Grow `right`. When the new char `s[right]` is **already in the window**, the window is
   invalid → shrink from the left until the duplicate is gone, THEN record the length.
3. Two common ways to track membership — which costs you less per step?
   (a) a freq map/array: shrink with a `while` until `count[s[right]] == 1`.
   (b) a "last seen index" map: jump `left` directly past the previous occurrence.

Edge to respect: chars can be any ASCII — pick a container that won't blow up or mis-index.

## Result log
- Status: ___   Which tracking method you chose and why: ___
