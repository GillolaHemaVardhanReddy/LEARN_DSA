# Binary Search — Practice Set (building-block ladder)

> Each rung sets the **same engine's knobs** differently (condition · move-direction · range · what-to-return).
> Do them IN ORDER. Recognition-first: write the cue + the 4 knob settings BEFORE coding. Judge = ground truth.
> MCP-verified constraints/difficulty (2026-06-09). Treated as a fresh topic.

## The ladder (why this order)
| # | Problem | Diff | NEW knob-setting / sub-skill |
|---|---------|------|------------------------------|
| 01 | LC704 Binary Search | easy | **Exact search** — the core `lo<=hi`, overflow-safe mid, `lo=mid+1`/`hi=mid-1`. |
| 02 | LC35 Search Insert Position | easy | **Lower bound** — return where it *belongs* (store-candidate, search left on a hit). |
| 03 | LC34 First & Last Position | med | **Both boundaries** — find first occurrence AND last (store-candidate twice); handle not-found + **empty array**. |
| 04 | LC875 Koko Eating Bananas | med | **Search on the ANSWER** — `lo/hi` are VALUES `[1, max(pile)]`; `feasible(k)` = hours ≤ h. |
| 05 | LC410 Split Array Largest Sum | **hard** | Hard search-on-answer — `feasible(maxSum)` = can split into ≤ k parts. **WEEKEND.** |

## The 4 knobs (from `Notes/06-Binary-Search.md`)
For every problem, decide BEFORE coding:
1. **Condition** — `a[mid]==x` / `a[mid]>=x` / `feasible(mid)` ?
2. **Move direction** — min/first → go LEFT on a hit; max/last → go RIGHT.
3. **Range** — array indices `[0,n-1]`, or a *derived value range* (Koko: `[1, max(pile)]`)?
4. **Return** — the index / the stored `ans` / `lo`.

## The rule for each problem
1. Cue line: `cue: ___ → binary search because ___` (which variant? what's monotonic?).
2. State the 4 knobs in words.
3. Predict complexity from constraints (10⁸ rule): O(log n) or O(n·log range).
4. Code it → **boundary checklist before submit** (your #1 leak + the BS pitfalls): `lo<=hi` vs `lo<hi`, `mid=lo+(hi-lo)/2`, `lo=mid+1` makes progress (no infinite loop), `hi=mid` vs `hi=mid-1`, empty array, target out of range.
5. Submit. Bring Tommy whatever fights back.

## Cadence
This week: **01–04** (2 easy + 2 medium). **05 (hard) → weekend.** After the set: fill `Notes/06` TO-FILL + spaced drill later.
Optional extensions: LC33 (rotated), LC162 (peak), LC69 (sqrt), LC1011 (ship capacity).
