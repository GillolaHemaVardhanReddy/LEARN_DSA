# LC 704 — Binary Search · easy · BINARY SEARCH

**Link:** https://leetcode.com/problems/binary-search/
**Building block:** EXACT search — the core template you'll reuse everywhere.

---

## Problem (plain English)
Sorted ascending array `nums` (unique values) + `target`. Return its **index** if present, else **-1**. Must be O(log n).

## Examples
| nums | target | answer |
|---|---|---|
| [-1,0,3,5,9,12] | 9 | 4 |
| [-1,0,3,5,9,12] | 2 | -1 |

## Constraints
- 1 ≤ n ≤ 10⁴ · unique · sorted ascending.

## Before you code (recognition-first — state the 4 knobs)
- **Condition:** `nums[mid] == target` (found) / `< target` / `> target`.
- **Move:** `< target` → discard left (`lo=mid+1`); `> target` → discard right (`hi=mid-1`).
- **Range:** indices `[0, n-1]`, loop `lo <= hi`.
- **Return:** the index, or -1 if the loop ends.
- ⚠️ Pitfalls: `mid = lo + (hi-lo)/2`; `lo=mid+1`/`hi=mid-1` (the ±1!); single-element array.

## Result log
- Status: ___   Template (exact search) clear?: ___
