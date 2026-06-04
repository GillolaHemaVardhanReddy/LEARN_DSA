# LC 1004 — Max Consecutive Ones III  ·  Medium

**Link:** https://leetcode.com/problems/max-consecutive-ones-iii/
**Module:** M4 Sliding Window  **Pattern:** Variable Sliding Window (**LONGEST** variant)
**This is your L4 test + boundary-value re-test (MISTAKE #2). Drive it solo.**

---

## Problem (plain English)
You're given a binary array `nums` (only 0s and 1s) and an integer `k`.
You may **flip at most `k` zeros into ones**. Return the length of the **longest run of
consecutive 1s** you can make.

## Examples
| nums | k | answer |
|---|---|---|
| [1,1,1,0,0,0,1,1,1,1,0] | 2 | **6** (flip the two 0s in `...0,0,1,1,1,1` → six 1s) |
| [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1] | 3 | **10** |

## Constraints
- `1 ≤ nums.length ≤ 10^5`, `nums[i] ∈ {0,1}`, `0 ≤ k ≤ nums.length` → need **O(n)**.

---

## Reframe it as a window (this is the whole trick)
"Flip at most `k` zeros" = find the **longest window that contains at most `k` zeros**.
The window's length *is* the answer (the 1s stay, the ≤k zeros get flipped).

So: **longest** variant → expand right; when the window has **too many zeros (> k)**,
shrink from the left until it's valid again; track the max length.

## Before you code — your boundary checklist (you journaled this!)
1. What do you track as you slide? (Hint to *yourself*: how many zeros are in the window.)
2. `best` init for a *longest* hunt — and is there even a "not found" case here?
3. Window length = `right - left + 1`. Record it where?

## Result log (fill after submitting)
- Status: ___   Runtime: ___   Hints used (L0–L5): ___
- What tripped me up: ___
