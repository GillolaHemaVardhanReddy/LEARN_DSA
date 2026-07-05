# 🔪 06 — Binary Search  ·  THE PITFALL KING  (teaching notes — reread cold, they rebuild the model)

> These notes TEACH, they don't just remind. Read top to bottom and the understanding comes back.
> This is the **most boundary-pitfall-prone** pattern you'll meet — that's exactly YOUR #1 leak, boss.
> So we go slow on the template split (BIT 5). Get that reflex and binary search stops surprising you.

## 0. Striver videos (watch AFTER these notes, in order)
- **[045] BS-1 Introduction** — https://youtu.be/MHf6awe89xw  ⭐ start here (core mechanic)
- **[046] BS-2 Lower/Upper Bound, Search Insert, Floor/Ceil** — https://youtu.be/6zhGS79oQ4k  (boundary variant)
- **[047] BS-3 First/Last Occurrence, Count** — https://youtu.be/hjR1IYVx9lY  (boundaries w/ duplicates)
- **[056] BS-12 Koko Eating Bananas** — https://youtu.be/qyfekrNni90  (search-on-the-answer payoff)

---

## BIT 0 — The one sentence
> **Binary search = one cheap check on the MIDDLE that provably lets you throw away HALF the search space, repeated until one thing is left.**

Look at mid → prove a whole half can't contain the answer → delete it → repeat. `log₂(n)` steps.
10³ → ~10 steps · 10⁶ → **~20** · 10⁹ → **~30**. Halving is dramatically powerful. Space O(1).

---

## BIT 1 — Why it exists (the "why")
Linear search reads every element: O(n). But if the space is **ordered so that one look tells you
which side the answer is on**, checking the middle collapses the problem to half in a single step.
That's the entire trade: you spend one comparison to buy the deletion of half the candidates.

The classic home is a **sorted array** — `a[mid] < target` instantly says "target is to the RIGHT,
delete everything left." But sortedness is just the *easiest* thing that gives you that property.
The real requirement is deeper — that's BIT 4.

---

## BIT 2 — The MONOTONICITY view (not just "sorted")
Binary search works on anything shaped like a **single flip** — a yes/no test that goes NO…NO…YES…YES:
```
NO   NO   NO   YES   YES   YES
                ↑ find this boundary
```
A sorted array is ONE example (`a[mid] >= target` flips NO→YES exactly once). But ANY predicate that
flips from NO→YES exactly once is binary-searchable, even when there's no array at all. *That* is the
real cue — not "is it literally sorted," but "is there a yes/no check that flips once."

---

## BIT 3 — The mental UNLOCK (read twice, this is the whole game)
> **Binary search isn't about sortedness — it's about DISCARD-ABILITY.**
> If ONE check on `mid` can PROVABLY throw away half the search space, you can binary-search it —
> even when you're searching over the ANSWER itself, with no array in sight.

Stop asking "is it sorted?" Start asking: **"If I test the middle candidate, can I prove one whole
half is dead?"** If yes → binary search. The sorted array is a special case of this. Search-on-the-
answer (BIT 7) is the same idea wearing a costume.

### Hand-run trace ①: classic search — WATCH which half dies and WHY
`a = [2, 5, 8, 12, 16, 23, 38]` (indices 0..6), `target = 23`. Range `[lo,hi]` = `[0,6]`.
```
lo=0 hi=6  mid=3  a[3]=12  →  12 < 23, target must be RIGHT   ⇒ DELETE [0..3], lo = mid+1 = 4
lo=4 hi=6  mid=5  a[5]=23  →  HIT. return 5
```
Why the left half died at step 1: the array is sorted, so *everything* at index ≤3 is ≤12 < 23.
Not "probably" — **provably**. One check, four candidates gone. That proof is the license to discard.

### Hand-run trace ②: search-on-the-answer — SAME engine, no array
**Koko Eating Bananas** (LC875): piles `[3,6,7,11]`, deadline `H=8` hours. Speed `k` bananas/hr.
Find the **smallest `k`** that finishes in ≤ H hours. There's no sorted array to index into — the
thing we search is `k` itself, living in `[1, max(pile)] = [1, 11]`.

The discard proof: `hours(k) = Σ ceil(pile/k)`. Bigger `k` ⇒ fewer hours ⇒ **once a `k` is feasible,
every larger `k` is too** (NO…NO…YES…YES over `k`). So `feasible(mid)` tells us which half is dead.
```
lo=1 hi=11  mid=6   hours = ceil(3/6)+ceil(6/6)+ceil(7/6)+ceil(11/6) = 1+1+2+2 = 6 ≤ 8  FEASIBLE
                     → k=6 works, but maybe smaller works too. DELETE [7..11], keep 6. hi = mid = 6
lo=1 hi=6   mid=3   hours = 1+2+3+4 = 10 > 8  NOT feasible  → DELETE [1..3], lo = mid+1 = 4
lo=4 hi=6   mid=5   hours = 1+2+2+3 = 8 ≤ 8   FEASIBLE  → keep 5, hi = mid = 5
lo=4 hi=5   mid=4   hours = 1+2+2+3 = 8 ≤ 8   FEASIBLE  → keep 4, hi = mid = 4
lo=4 hi=4   → lo==hi, answer = 4
```
Notice: on a FEASIBLE `mid` we kept it (`hi = mid`, not `mid-1`) because **mid itself might be the
answer**. That single decision is BIT 5 — and it's where your bugs live.

---

## BIT 4 — The overflow-safe mid (fix this reflex NOW)
Always compute:
```cpp
int mid = lo + (hi - lo) / 2;      // overflow-safe
```
Never `mid = (lo + hi) / 2`. WHY it overflows: if `lo` and `hi` are both near `INT_MAX` (say around
2·10⁹), `lo + hi` ≈ 4·10⁹ **wraps past the 32-bit `int` ceiling (~2.1·10⁹) to a negative number** →
`mid` goes garbage/negative → out-of-bounds read or infinite loop. `lo + (hi-lo)/2` never forms a sum
bigger than `hi`, so it can't overflow. Same value, safe arithmetic. Make it muscle memory.

---

## BIT 5 — ⭐ THE TEMPLATE SPLIT (this is where your leak lives — burn it in)
Two loop shapes. They are NOT interchangeable. Mixing the condition with the wrong update = bug.
The ONE question that picks the template:

> ### **"Could `mid` be the answer?"**
> - **NO — mid is only ever checked for exact equality, a miss is a miss** → template A, `while(lo<=hi)`, drop mid with `hi = mid-1` / `lo = mid+1`, `return mid` on hit.
> - **YES — mid could be the boundary/answer I'm hunting** → template B, `while(lo<r)`, **KEEP mid** with `hi = mid` (never `mid-1`), converge to it.

### Template A — EXACT target (could mid be the answer? NO)
```cpp
int lo = 0, hi = n - 1;                 // CLOSED range [lo, hi]
while (lo <= hi) {                       // <= : lo==hi is a valid single element to check
    int mid = lo + (hi - lo) / 2;
    if (a[mid] == target) return mid;    // found it, done
    else if (a[mid] < target) lo = mid + 1;   // left half dead → discard (+1!)
    else                      hi = mid - 1;   // right half dead → discard (-1!)
}
return -1;                               // never found
```
Here a miss at `mid` means mid is definitely NOT the answer, so we drop it (`±1`). Because we shrink
by at least one every step and `lo` can pass `hi`, it always terminates. Used by **LC704 (search),
LC35 (search-insert if you tweak the return)**.

### Template B — BOUNDARY / first-true / answer (could mid be the answer? YES)
```cpp
int lo = 0, hi = n;                      // hi = n : answer can be "past the end" (insert position)
while (lo < hi) {                        // < here, NOT <=  (lo==hi is the converged answer)
    int mid = lo + (hi - lo) / 2;
    if (cond(mid)) hi = mid;             // mid MIGHT be the answer → KEEP it (hi = mid, NOT mid-1)
    else           lo = mid + 1;         // mid fails → it's dead, discard it
}
return lo;                               // lo == hi == first index where cond is true
```
Here a satisfying `mid` is a *candidate we can't afford to throw away* — so `hi = mid`, not `mid-1`.
The loop narrows `[lo,hi)` until the two pointers meet exactly on the boundary. Used by lower/upper
bound, first/last occurrence, and search-on-answer.

> **The rule, one line:** if `mid` passing the test could BE your answer, never write `hi = mid-1` —
> you'd throw the answer away. Keep it: `hi = mid`.

### Method A — STORE-THE-CANDIDATE (the unified default — use this when in doubt)
One way to think about ALL of upper/lower bound + min/max + search-on-answer without juggling `<`
vs `<=`: keep a saved `ans`; on every `mid` that satisfies the condition, **save it and search the
side that could hold a better one**; run the loop FULLY until `lo > hi`.
```cpp
int lo = START, hi = END, ans = DEFAULT;   // array: [0,n-1]; answer-search: [minVal,maxVal]
while (lo <= hi) {                          // run FULLY until lo > hi
    int mid = lo + (hi - lo) / 2;
    if (condition(mid)) { ans = mid; hi = mid - 1; }  // candidate! save, then hunt a BETTER one
    else                { lo = mid + 1; }
}
return ans;                                 // last saved candidate — can't get lost
```
- **min / first → on a hit go LEFT** (`hi = mid-1`). **max / last → on a hit go RIGHT** (`lo = mid+1`).
- `condition` = `a[mid] >= x` (lower bound) · `a[mid] > x` (upper bound) · `feasible(mid)` (Koko).
- **What you halve:** array search → `lo/hi` are **indices**; search-on-answer → `lo/hi` are **values**
  (derive the range, e.g. Koko `lo=1, hi=max(pile)`). Same engine either way.
- `ans` can't get "lost" — you saved it every time the condition held; loop breaks at `lo>hi` → confident.

> ONE TOOL, FOUR KNOBS: **condition · move-direction (min→left / max→right) · range (indices or a
> derived value-range) · what you return.**

---

## BIT 6 — First & last occurrence (LC34) — boundary in duplicates
Array `[5,7,7,7,8,8,10]`, find first and last index of `8`. Don't stop on the first match — that's
some middle copy, not the boundary. Use Method A twice:
- **First occurrence** = smallest index with `a[mid] >= target`, then check it equals target
  (this is lower-bound). On a hit, go LEFT (`hi = mid-1`) to find an earlier one.
- **Last occurrence** = largest index with `a[mid] <= target`. On a hit, go RIGHT (`lo = mid+1`).

Count of a value = `last - first + 1`. The tell is "**first / last / count with duplicates**" — a
boundary hunt, template B / Method A, never template A's `return mid`.

---

## BIT 7 — Search on the ANSWER (the FAANG favorite — BIT 3 trace ② formalized)
When the problem says "**minimum/maximum value such that <something> is possible**" and there's a huge
value range + a cheap per-candidate check, you binary-search the ANSWER, not an array.

The recipe (three blanks to fill):
1. **What is the answer, and what's its range `[lo, hi]`?** (Koko: a speed `k` in `[1, max(pile)]`.)
2. **`feasible(x)` — a monotonic yes/no check.** (Koko: `Σ ceil(pile/x) <= H`.) Must flip NO→YES once.
3. **Which end do you want?** Smallest feasible → go left on a hit. Largest feasible → go right.
```cpp
int lo = 1, hi = maxPossibleAnswer;
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (feasible(mid)) hi = mid;         // works → try smaller (this is a KEEP-mid = template B)
    else               lo = mid + 1;     // fails → need bigger
}
return lo;                               // smallest feasible value
```
Complexity: **O(n · log(range))** — `log(range)` candidates × O(n) per feasibility check.
Classics: **LC875 Koko**, ship-within-D-days capacity, smallest divisor, **LC410 Split Array Largest
Sum** (min the largest subarray sum → feasible = "can split into ≤ k parts each ≤ mid"), **LC852
Peak Index** (peak = boundary where `a[mid] > a[mid+1]` flips true).
> ⚠️ **Size the accumulator.** In `feasible`, the running sum (e.g. LC410's subarray sum, or hours)
> can exceed `int`. If any `+`/`*` accumulator can pass ~2·10⁹, make it **`long long`.** This is your
> overflow leak dressed as a feasibility check — pre-commit the type before you code the check.

---

## BIT 8 — Rotated sorted array (LC33 / LC153) — which half is sorted?
`[4,5,6,7,0,1,2]` is sorted-then-shifted. It's not globally monotonic, so plain binary search breaks.
The save: **at any `mid`, at least ONE half `[lo..mid]` or `[mid..hi]` is still perfectly sorted.**
Identify the sorted half, and you can check in O(1) whether the target lies inside it.
```cpp
while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (a[mid] == target) return mid;
    if (a[lo] <= a[mid]) {                       // LEFT half [lo..mid] is sorted
        if (a[lo] <= target && target < a[mid]) hi = mid - 1;  // target in the sorted left → go left
        else                                    lo = mid + 1;  // else the (dead) other side
    } else {                                     // RIGHT half [mid..hi] is sorted
        if (a[mid] < target && target <= a[hi]) lo = mid + 1;  // target in the sorted right → go right
        else                                    hi = mid - 1;
    }
}
return -1;
```
The recognition: "sorted array but rotated / a pivot" → find the sorted half, decide from its ends.
**LC153 (find min)** is the same idea reduced to "which half holds the rotation point."

## BIT 8.5 — 2D matrix (LC74) — flatten to 1D
A fully row+col sorted matrix (each row sorted, first of a row > last of previous) is just a sorted
array folded into `m×n`. Binary-search indices `0 .. m*n-1`, and map `mid → (mid / n, mid % n)` to
read the cell. Same template A engine. (Weaker "sorted rows, sorted cols" variants → walk from a
corner instead.)

---

## BIT 9 — Complexity, read straight off the shape
- **Array search / boundary:** `log₂(n)` steps × O(1) work → **O(log n) time, O(1) space.**
- **Search-on-answer:** `log(range)` steps × O(n) feasibility → **O(n · log(range)).**
- **Rotated / matrix:** still **O(log n)** — one half dies each step, same as classic.

---

## BIT 10 — The DECISION RECIPE (run this BEFORE coding — your Gate-A for BS)
Answer these four, in order, out loud, before a line of code:
1. **Could `mid` be the answer?** → NO = template A `while(lo<=hi)`, `±1`, `return mid`.
   YES = template B `while(lo<r)`, **`hi = mid`** keep-candidate. *(This is your #1 leak — decide it first.)*
2. **Is `mid` overflow-safe?** → `lo + (hi - lo) / 2`, never `(lo+hi)/2`.
3. **Does every branch make progress?** → at least one side must move PAST mid (`lo = mid+1`), or you
   loop forever. In template A, `lo=mid` (no `+1`) is the classic infinite loop.
4. **Search-on-answer? Size the accumulator.** → any sum/product in `feasible` that can pass ~2·10⁹ →
   **`long long`.** State the range `[lo,hi]` of the answer explicitly.

---

## BIT 11 — The classic TRAPS (execution focus — these ARE your leaks, boss)
1. **`lo <= hi` vs `lo < hi` mixed with the wrong update** — the #1 bug. `[lo,hi]` closed pairs with
   `<=` + `±1`; boundary-hunt pairs with `<` + `hi = mid`. Don't cross the wires.
2. **`hi = mid` vs `hi = mid - 1`** — when `mid` *could be the answer*, keep it (`hi = mid`). When
   `mid` is definitely not (exact-search miss), drop it (`hi = mid-1`). The "could mid be the answer?"
   question decides. Writing `hi = mid-1` in a boundary hunt **silently deletes the answer.**
3. **Midpoint overflow** — `(lo+hi)/2` on large indices/values → negative garbage. Always `lo+(hi-lo)/2`.
4. **Infinite loop / no progress** — if a branch does `lo = mid` (not `mid+1`) with the wrong loop
   condition, `lo`/`hi` never move → hang. Guarantee at least one side steps past `mid`.
5. **Accumulator overflow in `feasible`** — LC410 subarray sum, hours totals, capacities. `long long`.
6. **Returning `mid` at the end of a boundary loop** — luck-dependent + garbage on empty. Return the
   stored `ans` (Method A) or `lo` (template B).

### 🚫 NO band-aid special-cases (your reactive-debugging trap, 2026-06-09)
Stop the loop of "submit → one failing test → bolt on `if(lo==hi){...}`." The clean templates handle
single-element / empty / insert-at-end / target-past-the-end **by design.** A special case means you
don't trust the template. **Trace these 4 edges BEFORE submitting** (don't wait for the judge):
single element (present/absent) · empty array · target < all / > all (insert 0 / n) · target at first /
last index. Reason the edges up front → the judge stops surprising you → the patches disappear.

---

## BIT 12 — Recognition cue (memorize; fill YOUR words after reps)
> **"sorted array"** · **"first / last / boundary / insert position"** · **"min/max value such that
> feasible"** · **"monotonic yes/no"** · **"rotated / pivot"** → binary search.
> Target **O(log n)** (or **O(n·log range)** for search-on-answer). Constraint tell: huge `n`/range +
> "find a value / threshold." Deeper cue: **not "is it sorted" but "can one check on mid discard a half?"**

Problems that teach it: **LC704** (exact) · **LC35** (insert position) · **LC34** (first/last) ·
**LC875 Koko** (search-on-answer) · **LC33 / LC153** (rotated) · **LC852 / LC540** (peak / single element)
· **LC74** (2D matrix) · **LC410** (split array largest sum).

## 🔲 TO FILL AFTER REPS
- [ ] My cue in my own words; which template I default to + why
- [ ] The boundary-template bug that actually bit me this week (lo<hi, hi=mid, overflow…)
- [ ] Search-on-answer: writing `feasible()` cleanly + the `long long` I nearly forgot

_Originally theory 2026-06-09; rewritten to teaching-BITS format. See PROGRESS.md for level._
