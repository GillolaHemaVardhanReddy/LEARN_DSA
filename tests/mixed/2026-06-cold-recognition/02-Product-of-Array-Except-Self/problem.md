# LC 238 — Product of Array Except Self  ·  Medium   ·   COLD RECOGNITION

**Link:** https://leetcode.com/problems/product-of-array-except-self/
**Tier:** C — no pattern named. Classify it yourself.

---

## Problem (plain English)
Given an array `nums`, return an array `answer` where `answer[i]` is the **product of all
elements except `nums[i]`**. You must do it in **O(n)** and **WITHOUT using division**.

## Examples
| nums | answer |
|---|---|
| [1,2,3,4] | [24,12,8,6] |
| [-1,1,0,-3,3] | [0,0,9,0,0] |

## Constraints
- `2 ≤ nums.length ≤ 10^5`,  product fits in 32-bit int
- **No division.** O(n) time. (Follow-up: O(1) extra space besides the output.)

---

## YOUR recognition work (fill these BEFORE coding)
1. Why is the obvious division approach banned / risky? (think about a `0` in the array) ___
2. For position `i`, the answer = (product of everything to its LEFT) × (product of everything to its RIGHT). Does that phrasing remind you of a tool you just learned — but with a different operation than `+`? ___
3. **Which pattern, and what cue?** ___
4. Optimal approach + complexity: ___

## Result log
- Status: ___   Pattern I chose: ___   Was it right? ___
- What tripped me up: ___
