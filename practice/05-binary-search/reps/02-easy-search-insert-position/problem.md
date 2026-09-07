# LC 35 — Search Insert Position · easy · BINARY SEARCH

**Link:** https://leetcode.com/problems/search-insert-position/
**Building block:** LOWER BOUND — return where the target *belongs* (first index `>=` target). Store-candidate, search left on a hit.

---

## Problem (plain English)
Sorted distinct array + target. Return the index of target if present, else the index **where it would be inserted** to stay sorted. O(log n).

## Examples
| nums | target | answer | why |
|---|---|---|---|
| [1,3,5,6] | 5 | 2 | found at 2 |
| [1,3,5,6] | 2 | 1 | inserts between 1 and 3 |
| [1,3,5,6] | 7 | 4 | past the end |

## Constraints
- 1 ≤ n ≤ 10⁴ · distinct · sorted ascending.

## Before you code (recognition-first — 4 knobs)
- This is **lower bound**: the first index where `nums[i] >= target`.
- **Condition:** `nums[mid] >= target` → candidate (store `ans=mid`), search **left** (`hi=mid-1`). Else `lo=mid+1`.
- **Range:** indices, but note the answer can be **n** (past the end) → default `ans = n`.
- **Return:** the stored `ans` (Method A from your notes).
- ⚠️ "inserts at the end" (target > all) and "inserts at front" (target < all) are the edge cases.

## Result log
- Status: ___   Lower-bound / store-candidate clicked?: ___
