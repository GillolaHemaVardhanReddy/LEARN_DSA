# LC 209 — Minimum Size Subarray Sum  ·  Medium

**Link:** https://leetcode.com/problems/minimum-size-subarray-sum/
**Module:** M4 Sliding Window  **Pattern:** Variable Sliding Window (shortest-window variant)

---

## Problem (plain English)
You're given an array of **positive** integers `nums` and a number `target`.
Find the **shortest contiguous chunk** (subarray) of `nums` whose elements add up to
**at least `target`** (`≥`, not exactly). Return that chunk's **length**.
If no chunk ever reaches `target`, return `0`.

> "Contiguous" = the elements must be next to each other (no skipping). We don't return
> the subarray itself — just **how long** the shortest qualifying one is.

## Examples
| nums | target | answer | why |
|---|---|---|---|
| [2,3,1,2,4,3] | 7 | **2** | `[4,3]` sums to 7, length 2 — nothing shorter works |
| [1,4,4] | 4 | **1** | a single `4` already hits the target |
| [1,1,1,1,1] | 11 | **0** | whole array sums to 5 < 11 — impossible |

## Constraints
- `1 ≤ nums.length ≤ 10^5`   ← O(n²) brute force (~10^10 ops) is too slow → need **O(n)**
- `1 ≤ nums[i] ≤ 10^4`
- `1 ≤ target ≤ 10^9`

---

## Before you code — decide these on purpose
1. **`best` initial value** for a *minimum* hunt — and what to return if nothing qualifies?
2. **Window length** from `left` to `right` — write it carefully (off-by-one trap).
3. Does `best = min(...)` go **inside** or **after** the shrink `while`? (Check the dry run.)

## Why this pattern (recognition cue)
"**shortest / smallest** contiguous subarray such that **\<a condition on the window>**"
+ size **not given** → **Variable Sliding Window**. Here the condition is `sum ≥ target`,
and because all numbers are **positive**, growing the window only ever *increases* the
sum — that monotonicity is what makes the shrink step valid.

## Result log (fill after submitting)
- Status: ___ (Accepted / WA / TLE)   Runtime: ___   Hints used (L0–L5): ___
- What tripped me up: ___
