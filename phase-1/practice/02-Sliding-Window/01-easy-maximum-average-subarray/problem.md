# LC 643 — Maximum Average Subarray I  ·  Easy   ·   FIXED SLIDING WINDOW

**Link:** https://leetcode.com/problems/maximum-average-subarray-i/
**Topic:** Fixed-size sliding window (size k is GIVEN)

---

## Problem (plain English)
Find the contiguous subarray of **length exactly `k`** with the **maximum average**, and
return that average. (Max average = max sum, since length is fixed.)

## Examples
| nums | k | answer |
|---|---|---|
| [1,12,-5,-6,50,3] | 4 | 12.75  (window [12,-5,-6,50]=51, /4) |
| [5] | 1 | 5.0 |

## Constraints
- `1 ≤ k ≤ nums.length ≤ 10^5`,  `-10^4 ≤ nums[i] ≤ 10^4`

## Before you code
1. Window size is **fixed** → compute the first window's sum, then **slide**: `sum += nums[i] - nums[i-k]`.
2. Track the max sum; return `maxSum / (double)k`. (Cast to double or you'll get integer division — a boundary-ish trap.)

## Result log
- Status: ___   Fixed-window slide formula I used: ___
