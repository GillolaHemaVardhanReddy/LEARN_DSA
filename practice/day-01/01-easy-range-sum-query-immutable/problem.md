# LC 303 — Range Sum Query - Immutable  ·  Easy   ·   COLD (you classify)

**Link:** https://leetcode.com/problems/range-sum-query-immutable/
**Day:** practice/day-01   **Tier:** Easy — no pattern named. Decide it yourself.

---

## Problem (plain English)
You're given an integer array `nums` once, up front. Then you'll be asked **many**
`sumRange(left, right)` queries — each wants the sum of `nums[left..right]` **inclusive**.
Design the class so that **each query is fast** (ideally O(1)), even if there are thousands
of queries. The array never changes after construction ("immutable").

## Examples
```
NumArray([-2,0,3,-5,2,-1])
sumRange(0, 2) -> 1     (-2 + 0 + 3)
sumRange(2, 5) -> -1    (3 + -5 + 2 + -1)
sumRange(0, 5) -> -3
```

## Constraints
- `1 ≤ nums.length ≤ 10^4`,  `-10^5 ≤ nums[i] ≤ 10^5`
- up to `10^4` calls to `sumRange` → re-summing each query (O(n) each) is too slow; precompute.

---

## YOUR recognition work (fill BEFORE coding)
1. Naive per-query approach + its cost across all queries: ___
2. What can you **precompute once** in the constructor so each query is O(1)? ___
3. **Which pattern, and what surface cue pointed you to it?** ___
4. The exact formula you'll use for `sumRange(left, right)` (watch the boundary at `left == 0`): ___

## Result log
- Status: ___ (Accepted / WA / TLE)   Pattern I chose: ___   Right? ___
- Boundary I had to get right: ___
