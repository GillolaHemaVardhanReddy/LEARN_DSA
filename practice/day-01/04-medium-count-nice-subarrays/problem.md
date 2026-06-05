# LC 1248 — Count Number of Nice Subarrays  ·  Medium   ·   COLD

**Link:** https://leetcode.com/problems/count-number-of-nice-subarrays/
**Day:** practice/day-01   **Tier:** Medium — no pattern named. Classify it yourself.

---

## Problem (plain English)
Given an integer array `nums` and an integer `k`, a subarray is **"nice"** if it contains
**exactly `k` odd numbers**. Return the **count** of nice contiguous subarrays.

## Examples
| nums | k | answer | why |
|---|---|---|---|
| [1,1,2,1,1] | 3 | **2** | [1,1,2,1] and [1,2,1,1] each have exactly 3 odds |
| [2,4,6] | 1 | **0** | no odd numbers at all |
| [2,2,2,1,2,2,1,2,2,2] | 2 | **16** | |

## Constraints
- `1 ≤ nums.length ≤ 5·10^4`   → need around **O(n)**
- `1 ≤ nums[i] ≤ 10^5`,  `1 ≤ k ≤ nums.length`

---

## YOUR recognition work (fill BEFORE coding)
1. Brute force + complexity: ___
2. You only care whether each number is **odd or even**, not its value. What simple
   **transform** turns this into a problem you've already solved? (think: odd → ?, even → ?) ___
3. After that transform, "exactly k odd numbers" becomes "________ equals k". **Which pattern
   does that phrasing trigger, and what's the cue?** ___
4. Optimal approach + complexity: ___

## Result log
- Status: ___   Transform + pattern I chose: ___   Right? ___
- What tripped me up: ___
