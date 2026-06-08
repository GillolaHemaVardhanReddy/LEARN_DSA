# LC 26 — Remove Duplicates from Sorted Array · easy · TWO POINTERS

**Link:** https://leetcode.com/problems/remove-duplicates-from-sorted-array/
**Building block:** FAST/SLOW same-direction — the **write pointer** (in-place rearrange). A different shape from LC167.

---

## Problem (plain English)
Sorted array `nums`. Remove duplicates **in place** so each unique value appears once,
keeping order. Return `k` = number of unique elements; the first `k` slots of `nums` must hold them.

## Examples
| nums | k | nums[0..k-1] |
|---|---|---|
| [1,1,2] | 2 | [1,2] |
| [0,0,1,1,1,2,2,3,3,4] | 5 | [0,1,2,3,4] |

## Constraints
- 1 ≤ n ≤ 3·10⁴ · sorted ascending.

## Before you code (recognition-first)
- cue line: **in-place rearrange a sorted array** → which two-pointer **shape**?
- Shape = **fast/slow, same direction**: a **slow/write** pointer marks where the next unique goes;
  a **fast/read** pointer scans ahead. When `nums[fast] != nums[write-1]` (a new value), write it.
- This **write-pointer** idea is the building block behind "move zeroes", partitions, and the 3Sum dedup next.
- ⚠️ Boundary: where does `write` start? what about a single element?

## Result log
- Status: ___   Building block (fast/slow write pointer): ___
