# 🔪 06 — Binary Search — Study Notes

> ⚠️ **THEORY note (2026-06-09)** — written after Stage ① theory, before problems. The
> `TO FILL` section gets my real cues + gotchas after reps. Classifier → `00`. This pattern
> is the **most pitfall-prone** one — the boundary section below is the part to revise hardest.

---

## What it is / why
Search a **sorted (or monotonic)** space by repeatedly looking at the **middle** and throwing
away **half** each step. Turns O(n) search into **O(log n)**.
- 10³ → ~10 steps · 10⁶ → **~20** · 10⁹ → **~30**. (Halving is dramatically powerful.)
- `log₂(n)` steps because each step halves the range. Space O(1).

## 🧠 The deep principle: MONOTONICITY (not just "sorted")
Binary search works on anything shaped like a single flip:
```
NO   NO   NO   YES   YES   YES
                ↑ find this boundary
```
A sorted array is ONE example (`a[mid] < target` is monotonic). But ANY **yes/no test that
flips from NO→YES exactly once** is binary-searchable. *That* is the real cue, not "is it sorted."

---

## 🔍 Recognition map (the variants)
| Variant | What it looks like | Idea |
|---|---|---|
| **1. Exact search** | "is `x` in this sorted array, where?" | stop when `a[mid]==x` |
| **2. Lower/Upper bound** | "first ≥ x", "last occurrence", "insert position", count with duplicates | don't stop on match — shrink toward the boundary |
| **3. 🌟 Search on the ANSWER** | "**min/max value such that** feasible" (Koko speed, ship capacity, smallest divisor) | answer is a number in a range + a monotonic feasibility check |
| **4. Rotated sorted array** | sorted then shifted, e.g. `[4,5,6,7,1,2,3]` | one half is always sorted → decide which half holds target |
| **5. 2D matrix** | row/col-sorted matrix | treat as 1D, or walk from a corner |
| **6. On a function** | integer sqrt, peak element, nth root | binary-search the value where `f` crosses |

### Variant 3 explained (the FAANG favorite — no array in sight!)
**Koko Eating Bananas:** piles `[3,6,7,11]`, deadline `H=8`. Speed `k`/hr. Find the **smallest `k`** to finish in ≤ H hours.
- The answer `k` lives in **`[1, max(pile)]`**.
- For a given `k`, hours = `Σ ceil(pile/k)`; feasible if ≤ H.
- Faster `k` ⇒ never more hours ⇒ once feasible, always feasible → **monotonic** → binary-search `k`.
- **Tell:** "minimum/maximum value such that possible" + huge answer range + cheap per-candidate check → search the answer. O(n·log(range)).

---

## Templates (memorize the SHAPES)

### A) Exact search
```cpp
int lo = 0, hi = n - 1;                 // CLOSED range [lo, hi]
while (lo <= hi) {                       // <= because lo==hi is a valid single element
    int mid = lo + (hi - lo) / 2;        // overflow-safe midpoint
    if (a[mid] == target) return mid;
    else if (a[mid] < target) lo = mid + 1;   // discard left half (+1!)
    else                      hi = mid - 1;   // discard right half (-1!)
}
return -1;
```

### B) Lower bound / first index where condition is TRUE
```cpp
int lo = 0, hi = n;                      // note hi = n (answer can be "past the end")
while (lo < hi) {                        // < here, NOT <=
    int mid = lo + (hi - lo) / 2;
    if (cond(mid)) hi = mid;             // mid might be the answer → keep it (hi = mid, NOT mid-1)
    else           lo = mid + 1;
}
return lo;                               // lo == hi == first index where cond is true
```

### C) Search on the answer (Koko shape)
```cpp
int lo = 1, hi = maxPossibleAnswer;
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (feasible(mid)) hi = mid;         // works → try smaller
    else               lo = mid + 1;     // fails → need bigger
}
return lo;                               // smallest feasible value
```

### ⭐ Method A — STORE-THE-CANDIDATE (my intuitive default — use this one)
The unified way I think about ALL of upper/lower bound + min/max + search-on-answer:
keep a saved `ans`; on every `mid` that satisfies the condition, **save it and search the side
that could hold a better one**; run until `lo > hi`.
```cpp
int lo = START, hi = END, ans = DEFAULT;   // array: [0,n-1]; answer-search: [minVal,maxVal]
while (lo <= hi) {                          // run FULLY until lo > hi
    int mid = lo + (hi - lo) / 2;
    if (condition(mid)) { ans = mid; hi = mid - 1; }   // candidate! save, then look for a BETTER one
    else                { lo = mid + 1; }
}
return ans;
```
- **min / first → on a hit go LEFT** (`hi = mid - 1`). **max / last → on a hit go RIGHT** (`lo = mid + 1`).
- `condition` = `a[mid] >= x` (lower bound) · `a[mid] > x` (upper bound) · `feasible(mid)` (Koko).
- **What you halve:** array search → `lo/hi` are **indices**; search-on-answer → `lo/hi` are **values** (derive the range: e.g. Koko `lo=1, hi=max(pile)`). Same engine either way.
- ans can't get "lost" — you saved it every time the condition held. Loop breaks at `lo > hi` → confident answer.

> ONE TOOL, FOUR KNOBS: **condition · move-direction (min→left/max→right) · range (indices or a derived value-range) · what you return.**

---

## 🚫 NO band-aid special-cases (my reactive-debugging trap, 2026-06-09)
I keep submitting, seeing one failing test, and bolting on an `if(s==e){...}` patch. **STOP.** The clean
templates handle single-element / empty / insert-at-end **by design** — a special case means I don't trust
the template. Also: never `return mid` at the end (luck-dependent + garbage on empty) — return the stored `ans`.
**Process fix — trace these 4 BEFORE submitting (don't wait for the judge):**
single element (present/absent) · empty · target < all / > all (insert 0 / n) · target at first / last index.
Reason the edges up front → the judge stops surprising me → the patches disappear.

## ⚠️ THE PITFALLS (my #1 leak lives here — revise HARDEST)
1. **`lo <= hi` vs `lo < hi`** — they pair with different update styles. Mixing them = bug.
   - `[lo, hi]` closed + `lo <= hi` + `lo=mid+1 / hi=mid-1` (exact search).
   - `[lo, hi)` or boundary-hunt + `lo < hi` + `lo=mid+1 / hi=mid`.
2. **Midpoint overflow:** use **`lo + (hi - lo) / 2`**, never `(lo + hi) / 2` (can overflow `int`).
3. **Must make progress → no infinite loop:** at least one branch must move past `mid` (`lo = mid + 1`).
   If you ever write `lo = mid` (not `mid+1`) with the wrong loop condition → **infinite loop**.
4. **`hi = mid` vs `hi = mid - 1`:** when `mid` *could be the answer* (boundary search), keep it: `hi = mid`.
   When `mid` is definitely *not* the answer (exact-search miss), drop it: `hi = mid - 1`.
5. **Pre-code check (binary search edition):** single-element array? target smaller than all / bigger than all?
   empty array? answer "past the end" (lower bound returns n)?

---

## The cue (memorize)
> **"sorted array"** · **"first/last/boundary"** · **"min/max value such that feasible"** · **"monotonic yes/no"** → binary search.
> Target **O(log n)** (or **O(n·log range)** for search-on-answer). Constraint tell: huge `n`/range + "find a value/threshold".

## 🔲 TO FILL AFTER REPS
- [ ] My cues in my own words; which loop template I default to + why
- [ ] The boundary-template bugs that actually bit me (lo<hi, hi=mid, overflow…)
- [ ] Search-on-answer: writing the `feasible()` check cleanly
- [ ] Problems that taught me: LC704, LC35, LC34, LC875 (Koko), LC33 (rotated), …

## 📺 Striver videos (Stage ②)
- **[045] BS-1 Introduction** — https://youtu.be/MHf6awe89xw  ← start here (core mechanic)
- **[046] BS-2 Lower/Upper Bound, Search Insert, Floor/Ceil** — https://youtu.be/6zhGS79oQ4k  (boundary variant)
- **[047] BS-3 First/Last Occurrence, Count** — https://youtu.be/hjR1IYVx9lY  (boundaries w/ duplicates)
- **[056] BS-12 Koko Eating Bananas** — https://youtu.be/qyfekrNni90  (search-on-the-answer payoff)

_Last updated 2026-06-09 (theory). Level: L1 (introduced). See PROGRESS.md._
