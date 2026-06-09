# LC 34 — Find First and Last Position of Element in Sorted Array · MEDIUM · BINARY SEARCH

**Link:** https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
**Building block:** BOTH boundaries — run the store-candidate search TWICE (first occurrence, last occurrence). Handle not-found + empty.

---

## Problem (plain English)
Non-decreasing array (may have **duplicates**) + target. Return `[firstIndex, lastIndex]` of target, or `[-1,-1]` if absent. O(log n).

## Examples
| nums | target | answer |
|---|---|---|
| [5,7,7,8,8,10] | 8 | [3,4] |
| [5,7,7,8,8,10] | 6 | [-1,-1] |
| [] | 0 | [-1,-1] |

## Constraints
- **0 ≤ n ≤ 10⁵** (empty array possible!) · −10⁹ ≤ nums[i] ≤ 10⁹ · non-decreasing.

## Before you code (recognition-first — 4 knobs, run TWICE)
- Two boundary searches on the same array:
  - **FIRST occurrence:** on `nums[mid]==target` → store, then search **LEFT** (`hi=mid-1`) for an earlier one.
  - **LAST occurrence:** on `nums[mid]==target` → store, then search **RIGHT** (`lo=mid+1`) for a later one.
- That direction flip (left vs right on a hit) is the whole lesson: min/first→left, max/last→right.
- **Return** the two stored `ans` values; if first is -1, the value is absent → `[-1,-1]`.
- ⚠️ Empty array (n=0) → must return `[-1,-1]` without indexing. Range is `[0, n-1]`.

## Result log
- Status: ___   Direction flip (first→left, last→right) understood?: ___
