# LC 1480 — Running Sum of 1d Array  ·  Easy   ·   PREFIX SUM

**Link:** https://leetcode.com/problems/running-sum-of-1d-array/
**Topic:** Prefix Sum (the most literal version — build the prefix array itself)

---

## Problem (plain English)
Return an array `out` where `out[i] = nums[0] + nums[1] + ... + nums[i]`. That's literally
the prefix-sum array. Warm-up to lock the definition.

## Examples
| nums | out |
|---|---|
| [1,2,3,4] | [1,3,6,10] |
| [1,1,1,1,1] | [1,2,3,4,5] |
| [3,1,2,10,1] | [3,4,6,16,17] |

## Constraints
- `1 ≤ nums.length ≤ 1000`,  `-10^6 ≤ nums[i] ≤ 10^6`

## Before you code
1. One pass, carry a running total, push it each step. O(n) time.
2. Can you do it **in place** (overwrite nums)? `nums[i] += nums[i-1]`.

## Result log
- Status: ___   What I learned: ___
