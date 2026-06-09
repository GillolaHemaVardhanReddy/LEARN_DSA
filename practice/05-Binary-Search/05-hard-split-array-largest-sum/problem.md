# LC 410 — Split Array Largest Sum · HARD · BINARY SEARCH (search on the answer) · ⛅ WEEKEND

**Link:** https://leetcode.com/problems/split-array-largest-sum/
**Building block:** Hard search-on-answer — same shape as Koko, harder `feasible()`. Builds on rung 04.

---

## Problem (plain English)
Split `nums` into `k` non-empty **contiguous** subarrays so the **largest subarray sum is minimized**. Return that minimized largest sum.

## Examples
| nums | k | answer | why |
|---|---|---|---|
| [7,2,5,10,8] | 2 | 18 | [7,2,5] & [10,8] → max(14,18)=18 |
| [1,2,3,4,5] | 2 | 9 | [1,2,3] & [4,5] → max(6,9)=9 |

## Constraints
- 1 ≤ n ≤ 1000 · 0 ≤ nums[i] ≤ 10⁶ · 1 ≤ k ≤ min(50, n).

## Before you code (recognition-first — 4 knobs)
- "**minimize the maximum**" → search on the answer (the answer is the max-sum value).
- **Range of the answer:** `lo = max(nums)` (a subarray can't be smaller than its biggest element),
  `hi = sum(nums)` (one subarray = whole array). Search this VALUE range.
- **feasible(maxSum):** greedily walk nums, start a new part whenever adding would exceed `maxSum`;
  count the parts. Feasible if `parts <= k`. (Monotonic: bigger maxSum → fewer parts → still ≤ k.)
- **Condition/move:** `feasible(mid)` → store + search **left** (smaller max); else `lo = mid+1`.
- This is the SAME engine as Koko — only `feasible()` changed. That's the lesson.

## Result log
- Status: ___   Range `[max(nums), sum(nums)]` derived?: ___   feasible() = greedy part-count?: ___
