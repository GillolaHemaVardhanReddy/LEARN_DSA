# LC 875 — Koko Eating Bananas · MEDIUM · BINARY SEARCH (search on the answer)

**Link:** https://leetcode.com/problems/koko-eating-bananas/
**Building block:** SEARCH ON THE ANSWER — `lo/hi` are VALUES, not indices. The FAANG-favorite variant you reasoned out.

---

## Problem (plain English)
`piles[i]` bananas in pile `i`. Koko eats speed `k`/hour: each hour she picks one pile and eats up to `k` from it
(if the pile is smaller, she finishes it and idles the rest of the hour). Return the **minimum `k`** to eat everything within `h` hours.

## Examples
| piles | h | answer |
|---|---|---|
| [3,6,7,11] | 8 | 4 |
| [30,11,23,4,20] | 5 | 30 |
| [30,11,23,4,20] | 6 | 23 |

## Constraints
- 1 ≤ piles.length ≤ 10⁴ · piles.length ≤ h ≤ 10⁹ · 1 ≤ piles[i] ≤ 10⁹.

## Before you code (recognition-first — 4 knobs)
- **No array to search — search the SPEED `k`.**
- **Range:** `lo = 1` (slowest), `hi = max(piles)` (fastest useful). These are VALUES.
- **feasible(k):** hours = `Σ ceil(pile / k)`; works if `hours <= h`. (ceil: `(pile + k - 1) / k`.)
- **Condition/move:** `feasible(mid)` → store + search **left** (smaller k); else `lo = mid+1`.
- **Return:** smallest feasible k.
- ⚠️ `Σ pile` can overflow int (piles up to 10⁹ × 10⁴) → use **`long long`** for the hour sum. (Your boundary/overflow family.)
- Complexity: O(n · log(max pile)).

## Result log
- Status: ___   "search the answer, lo/hi are values" landed?: ___   Did I use long long?: ___
