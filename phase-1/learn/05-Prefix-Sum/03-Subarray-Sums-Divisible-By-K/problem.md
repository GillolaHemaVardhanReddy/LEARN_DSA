# LC 974 — Subarray Sums Divisible by K  ·  Medium

**Link:** https://leetcode.com/problems/subarray-sums-divisible-by-k/
**Module:** M5 Prefix Sum  **Pattern:** Prefix family — TWIST IS YOURS TO FIND  **Tier:** B

---

## Problem (plain English)
Given an integer array `nums` and an integer `k`, return the **count** of contiguous
subarrays whose sum is **divisible by k** (sum % k == 0). Negatives are present.

## Examples
| nums | k | answer |
|---|---|---|
| [4,5,0,-2,-3,1] | 5 | **7** |
| [5] | 9 | **0** |

## Constraints
- `1 ≤ nums.length ≤ 3·10^4`   → need **O(n)**
- `-10^4 ≤ nums[i] ≤ 10^4`,  `2 ≤ k ≤ 10^4`

---

## Your job (no approach handed to you — this is transfer practice)
It's the **prefix-sum family**, very close to LC560. But "sum = k" became "sum
**divisible by** k." So the thing you look up in the map is **NOT the raw running sum.**
- What property of two prefix sums makes the chunk between them divisible by k?
- So what should you use as the **map key**? (and watch out: negatives mod k in C++ can go negative — how do you normalize?)
- What pre-loaded entry plays the role `seen[0]=1` did before?

Figure out the key. That's the whole problem.

## Result log (fill after submitting)
- Status: ___   The "key" I used: ___   Hints used (L0–L5): ___
- What tripped me up: ___
