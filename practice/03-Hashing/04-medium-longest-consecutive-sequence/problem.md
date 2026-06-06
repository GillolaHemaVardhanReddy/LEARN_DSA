# LC 128 — Longest Consecutive Sequence  ·  Medium   ·   HASHING (set membership)

**Link:** https://leetcode.com/problems/longest-consecutive-sequence/
**Topic:** Hash SET for O(1) membership — turn an O(n log n) sort into O(n)

---

## Problem (plain English)
Given an unsorted array, return the length of the **longest run of consecutive integers**
(e.g. 1,2,3,4) present, in **O(n)**. Order in the array doesn't matter.

## Examples
| nums | answer | run |
|---|---|---|
| [100,4,200,1,3,2] | 4 | 1,2,3,4 |
| [0,3,7,2,5,8,4,6,0,1] | 9 | 0..8 |

## Constraints
- `0 ≤ nums.length ≤ 10^5`, values can be large/negative. Must be O(n) (sorting is the "better", not optimal).

## Before you code (the O(n) trick)
1. Put all numbers in an `unordered_set`.
2. A number `x` is the **START of a run** only if `x-1` is NOT in the set. Start counting only there
   (this avoids re-walking runs → keeps it O(n) overall).
3. From each start, walk `x, x+1, x+2, ...` while they're in the set; track the longest.

## Result log
- Status: ___   Why only start counting when x-1 is absent: ___
