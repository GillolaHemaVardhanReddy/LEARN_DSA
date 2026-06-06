# LC 303 — Range Sum Query - Immutable  ·  Easy   ·   PREFIX SUM

**Link:** https://leetcode.com/problems/range-sum-query-immutable/
**Topic:** Prefix Sum (range query in O(1)) — ⚠️ YOUR boundary leak lives here

---

## Problem (plain English)
Build `NumArray(nums)` once, then answer many `sumRange(left, right)` queries — the sum of
`nums[left..right]` inclusive — each in **O(1)**.

## Examples
```
NumArray([-2,0,3,-5,2,-1])
sumRange(0,2) -> 1     sumRange(2,5) -> -1     sumRange(0,5) -> -3
```

## Constraints
- `1 ≤ nums.length ≤ 10^4`, up to `10^4` queries → precompute prefix in constructor.

## Before you code  ⚠️ BOUNDARY CHECK (your #1 leak)
1. `sumRange(left,right) = prefix[right] - prefix[left-1]`. **What happens when `left == 0`?**
   `prefix[-1]` does NOT exist → crash. Two clean fixes:
   - guard: `left == 0 ? prefix[right] : prefix[right] - prefix[left-1]`, OR
   - **1-index the prefix**: make `prefix` size `n+1` with `prefix[0]=0`, then
     `sumRange = prefix[right+1] - prefix[left]` (no negative index, ever).
2. Run the boundary checklist before submitting.

## Result log
- Status: ___   How I killed the left==0 boundary: ___
