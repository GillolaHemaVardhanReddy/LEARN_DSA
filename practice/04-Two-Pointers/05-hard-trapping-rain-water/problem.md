# LC 42 — Trapping Rain Water · HARD · TWO POINTERS (capstone)

**Link:** https://leetcode.com/problems/trapping-rain-water/
**Building block:** STATEFUL converging — two pointers closing in while tracking **left-max / right-max**. Synthesizes everything; builds directly on LC11's "move the limiting side."

---

## Problem (plain English)
`height[i]` = elevation map bar widths 1. Return total **units of rain water trapped** after raining.
Water above bar `i` = `min(maxLeft[i], maxRight[i]) - height[i]` (if positive).

## Examples
| height | answer |
|---|---|
| [0,1,0,2,1,0,1,3,2,1,2,1] | 6 |
| [4,2,0,3,2,5] | 9 |

## Constraints
- 1 ≤ n ≤ 2·10⁴ · 0 ≤ height[i] ≤ 10⁵.

## Before you code (recognition-first)
- **First, the honest brute force:** for each bar, water = `min(maxLeft, maxRight) - height[i]`.
  Computing maxLeft/maxRight per bar by scanning = O(n²). Then optimize.
- **Step 1 optimization (prefix idea you KNOW):** precompute `maxLeft[]` and `maxRight[]` arrays in two passes → O(n) time, O(n) space.
- **Step 2 (the two-pointer capstone):** do it in **O(1) space** with converging pointers:
  carry `leftMax` and `rightMax`; move the pointer on the side with the **smaller** wall (the LC11 insight!) —
  that side's water is fully decided by its running max. Track *why* that's safe.
- Build the brute/prefix version first (your "correct-then-optimize" rule), THEN the two-pointer one.

## Result log
- Status: ___   Versions done (brute / prefix-arrays / two-pointer O(1)): ___
- The capstone insight (why move the smaller side decides its water): ___
