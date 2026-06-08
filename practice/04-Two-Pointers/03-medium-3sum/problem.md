# LC 15 — 3Sum · MEDIUM · TWO POINTERS (the keystone)

**Link:** https://leetcode.com/problems/3sum/
**Building block:** FIX ONE element + two-pointer the rest + the **skip-duplicates** trick. Everything (4Sum, 3Sum-closest) extends this.

---

## Problem (plain English)
Return **all unique triplets** `[a, b, c]` in `nums` with `a + b + c == 0`. No duplicate triplets.

## Examples
| nums | answer |
|---|---|
| [-1,0,1,2,-1,-4] | [[-1,-1,2],[-1,0,1]] |
| [0,1,1] | [] |
| [0,0,0] | [[0,0,0]] |

## Constraints
- 3 ≤ n ≤ 3000 · −10⁵ ≤ nums[i] ≤ 10⁵.  (n ≤ 3000 → 10⁸ rule says **O(n²) is the target**.)

## Before you code (recognition-first)
- Brute force = 3 nested loops O(n³). Bottleneck = the inner pair search.
- **Key idea (the building block):** **sort** the array, then for each `i`, the rest is just
  **Two Sum II** (LC167!) on the subarray to the right → **fix `nums[i]`, two-pointer for `-nums[i]`.** O(n²).
- **The NEW hard part = duplicates.** Two places you must skip equal values to avoid duplicate triplets:
  (1) the fixed `i`, (2) `L` and `R` after recording a hit. Think through BOTH.
- Target O(n²) (from constraints). Sorting O(n log n) is free under that.
- ⚠️ Boundary: skip-duplicate conditions, `L < R`, possible `int` overflow on the sum.

## Result log
- Status: ___   Building block (fix-one + TP + dedup): ___   Where I skipped dups: ___
