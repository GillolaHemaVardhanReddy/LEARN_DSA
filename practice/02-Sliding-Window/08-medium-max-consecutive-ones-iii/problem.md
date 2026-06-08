# LC 1004 — Max Consecutive Ones III  ·  Medium  ·  VARIABLE WINDOW

**Link:** https://leetcode.com/problems/max-consecutive-ones-iii/
**Topic:** Variable sliding window (LONGEST) + bounded count of "bad" elements

---

## Problem (plain English)
Given a binary array `nums` and an integer `k`, you may flip **at most `k` zeros** to ones.
Return the length of the **longest run of consecutive 1s** you can make.

## Examples
| nums | k | answer | why |
|---|---|---|---|
| [1,1,1,0,0,0,1,1,1,1,0] | 2 | 6 | flip two 0s → six 1s in a row |
| [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1] | 3 | 10 | flip three 0s |

## Constraints
- `1 ≤ nums.length ≤ 10^5`, each `nums[i]` is `0` or `1`, `0 ≤ k ≤ nums.length`

## Before you code — this is the binary twin of LC 424
Map it onto what you already know:
1. In LC 424 a window was valid when `windowLen - maxFreq ≤ k` (≤ k chars to replace).
2. Here the "chars to fix" are exactly the **zeros** in the window. A window is valid when
   `(number of zeros in window) ≤ k`.
3. So: grow `right`; if the zero-count exceeds `k`, shrink from the left until it's ≤ k
   again; track the longest valid length.

Notice you DON'T need a 26-array here — just one counter. What is it counting?

## Result log
- Status: ___   How this maps onto LC 424 (one sentence): ___
