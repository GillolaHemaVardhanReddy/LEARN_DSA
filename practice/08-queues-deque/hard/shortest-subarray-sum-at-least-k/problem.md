# LC 862 — Shortest Subarray with Sum at Least K  ·  Hard   ·   PREFIX + MONOTONIC DEQUE

**Link:** https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
**Topic:** Prefix sum + monotonic deque  ·  ⚠️ STRETCH (peeks ahead at deque — that's fine)

---

## Problem (plain English)
Return the **length of the shortest** contiguous subarray with sum **≥ k**. Return `-1` if
none. **Negatives are allowed** — that's why plain sliding window fails (like LC560).

## Examples
| nums | k | answer |
|---|---|---|
| [1] | 1 | 1 |
| [1,2] | 4 | -1 |
| [2,-1,2] | 3 | 3 |

## Constraints
- `1 ≤ nums.length ≤ 10^5`, `-10^5 ≤ nums[i] ≤ 10^5`, `1 ≤ k ≤ 10^9`

## Before you code (this is a stretch — attempt, then we discuss)
1. Build prefix sums `P` (size n+1, `P[0]=0`). A subarray `(i,j]` has sum `P[j]-P[i] ≥ k`.
2. For each `j` you want the **largest** `i < j` with `P[i] ≤ P[j]-k`, and minimize `j-i`.
3. A **monotonic deque** of candidate indices (increasing `P`) gives O(n):
   - pop FRONT while `P[j] - P[deque.front()] ≥ k` (record length, that front can't help a later j better).
   - pop BACK while `P[j] ≤ P[deque.back()]` (a smaller/equal prefix later dominates).
   - push `j`.
4. Don't stress if this is hard — get partial intuition, then bring questions.

## Result log
- Status: ___   What clicked / what I want to discuss: ___
