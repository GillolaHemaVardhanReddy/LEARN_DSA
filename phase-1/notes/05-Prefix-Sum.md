# ➕ 05 — Prefix Sum (+ Hash)  ·  (teaching notes — reread cold, they rebuild the model)

> These notes TEACH, they don't just remind. Read top to bottom and the understanding comes back.
> Terse cues live in `PATTERN_JOURNAL.md`; classifier in `00-Recognition-Map.md`. This is the deep one.
> Prefix Sum is the engine under range queries, "subarray sums to k", divisibility, and 2D grids.

## 0. Striver / references (watch AFTER these notes)
- **Striver A2Z — Prefix sum + hashing** (Step: Arrays / Hashing) — subarray-sum-equals-k walkthrough.
- Core LC ladder we coded: **LC560 · LC974 · LC525 · LC523 · LC724 · LC238 · LC1590**.

---

## BIT 0 — The one sentence
> **Prefix sum = precompute cumulative totals ONCE, then any range sum is a single subtraction in O(1).**

Everything below is *why that works*, and the twist that turns it into "count subarrays that sum to k."

---

## BIT 1 — Why it exists (the "why")
Brute force for range sums re-adds the same elements over and over. Ask "sum of `L..R`" a thousand
times and you re-walk overlapping stretches a thousand times — O(n) per query, O(n·q) total.

The waste is **recomputed overlap**. `sum(0..5)` and `sum(0..6)` share five elements. So compute the
running total to *every* index ONCE and store it. Then a range is just the difference of two stored
totals. Q queries drop from O(n·q) to O(n) precompute + O(1) each.

> **"Prefix" = ANY cumulative aggregate, not just sums.** The operator can be `+`, `×`, `^` (xor), or
> a **count**. Same idea: a running fold you can diff. (Product-except-self LC238 = prefix× times suffix×.)

Analogy: a bank balance. You don't re-add every past transaction to know your balance today — you keep
a running balance. "How much did I spend between Tuesday and Friday?" = `balance[Fri] − balance[Mon]`.

---

## BIT 2 — The mechanics (the range formula, derived by MEANING)
Build the prefix array with a **sentinel zero** so there's no special case at the left edge:

```cpp
vector<long long> pre(n + 1, 0);              // pre[0] = 0  ← empty-prefix sentinel
for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];   // pre[i+1] = sum of a[0..i]
```

**Range formula:** `sum(a[L..R]) = pre[R+1] − pre[L]` (1-indexed prefix), i.e. **total up to R minus
the part before L**. Derive it by *meaning*, never by shape:

- everything up to and including R  =  `pre[R+1]`
- everything strictly before L      =  `pre[L]`
- what's left = exactly `L..R`. Subtract.

`pre[0]=0` means "nothing before index 0," which is why L=0 needs no special case — the sentinel *is*
the empty prefix. That single 0 is doing real work; keep it.

---

## BIT 3 — THE mental unlock (read twice) ⭐
The subtraction goes one way for range **queries**. Now **flip it** for "subarray sums to k":

> Precompute cumulative sums ONCE; any range sum is a single subtraction `pre[r] − pre[l−1]` in O(1).
> For "subarray sums to k," flip it — you need `pre[j] − pre[i] = k`, so as you sweep j you **look for
> `pre[i] = pre[j] − k` in a hash map.** The map IS the inner loop.

A condition on a *subarray* becomes a condition on **two prefix values**:
`sum(L..R)=k` ⟺ `pre[R] − pre[L−1] = k` ⟺ `pre[L−1] = pre[R] − k`.

So as you sweep the right end, **store every prefix you've seen** and O(1)-look-up the one you need.
"Scan all start points" (O(n²)) collapses to one hash lookup → **O(n)**. *It is literally Two Sum on
prefix sums.*

---

## BIT 4 — HAND-RUN the prefix+hash sweep (the part you RUN BY HAND)
Count subarrays summing to **k = 3**, array `a = [1, 2, 1, 3]`. GOAL = COUNT, KEY = complement.
`run` = running prefix. `seen` = frequency of prefixes seen so far. Pre-load `seen = {0:1}` (empty prefix).

```
start: run=0   seen={0:1}   ans=0

i=0  a=1  run=1   need pre = run-k = 1-3 = -2 → seen[-2]=0 → ans+=0 (0)   seen={0:1, 1:1}
i=1  a=2  run=3   need pre = 3-3 =  0 → seen[0]=1  → ans+=1 (1)   seen={0:1,1:1,3:1}
                    (that 1 = the empty-prefix hit → subarray a[0..1]=[1,2] sums to 3 ✅)
i=2  a=1  run=4   need pre = 4-3 =  1 → seen[1]=1  → ans+=1 (2)   seen={...,4:1}
                    (prefix 1 was at i=0 → subarray a[1..2]=[2,1] sums to 3 ✅)
i=3  a=3  run=7   need pre = 7-3 =  4 → seen[4]=1  → ans+=1 (3)   seen={...,7:1}
                    (prefix 4 was at i=2 → subarray a[3..3]=[3] sums to 3 ✅)

ANSWER = 3.
```

Burn in: the **`seen[0]=1` sentinel** is what let `[1,2]` (a prefix starting at index 0) count. Drop it
and you silently undercount every subarray that starts at the very front. That one line is the whole
edge case.

---

## BIT 5 — GOAL × KEY (decide TWO axes separately) ⭐ your known confusion
This is the heart, and the thing you've mixed before. **Pick GOAL and KEY independently, then combine.**

**Axis 1 — GOAL** (what's asked → which machinery):

| Goal | Store | Pre-load | Update inside loop |
|---|---|---|---|
| **COUNT** subarrays | **frequency** of each prefix | `seen[0] = 1` | `ans += seen[key];  seen[key]++` |
| **LONGEST** subarray | **first index** of each prefix | `seen[0] = -1` | `if(seen.count(key)) ans=max(ans, i-seen[key]);  else seen[key]=i` |

> ⚠️ Your 6/6 drill fail was mixing these. Lock it: **COUNT → frequency + `seen[0]=1`, `ans +=`.**
> **LONGEST → first-index + `seen[0]=-1`, store on FIRST sight ONLY** (earliest index = biggest gap).

Why `seen[0]=-1` for LONGEST: index −1 = "position just before the array." A prefix that equals a target
at index i, first seen at −1, gives length `i−(−1) = i+1` — the whole front stretch. Same empty-prefix
idea, encoded as a position instead of a count.

**Axis 2 — KEY** (what two prefixes must match on):

| Key | Compute | Use it for | Note |
|---|---|---|---|
| **complement** | `key = run`, look up `run − k` | subarray **sum = k** (LC560) | Two-Sum on prefixes |
| **remainder / mod** | `key = ((run % k) + k) % k` | sum **divisible by k** (LC974, LC523) | NORMALIZE negatives! |
| **transform** (0→−1) | fold ±1, look for a **repeat** | **equal counts** / balanced (LC525) | repeated prefix ⇒ zero-sum stretch |

### Universal template (both goals, any key)
```cpp
unordered_map<int,int> seen;
seen[0] = 1;                     // COUNT   (use seen[0] = -1 for LONGEST)
int run = 0, ans = 0;
for (int i = 0; i < n; i++) {
    run += a[i];
    int key = run;               // run  |  ((run % k) + k) % k  |  run-after-±1-transform
    // COUNT:   ans += seen[key - k];  seen[key]++;
    // LONGEST: if (seen.count(key)) ans = max(ans, i - seen[key]);
    //          else seen[key] = i;                 // ← FIRST sight only
}
```

---

## BIT 6 — Prefix-with-MOD (divisibility) — the negative trap
For "count subarrays with sum divisible by k": two prefixes give a divisible stretch iff they have the
**same remainder mod k** — `(pre[j] − pre[i]) % k == 0` ⟺ `pre[j] % k == pre[i] % k`. So the KEY is the
**residue**, and you count pairs of equal residues (COUNT machinery, `seen[0]=1`).

The bug that bites: C++ `%` returns a **negative** for negative operands (`-1 % 5 == -1`, not 4).
That splits one residue class into two buckets and corrupts the count. **Always normalize:**

```cpp
int key = ((run % k) + k) % k;   // maps into [0, k-1] — the residue, negatives fixed
```

Dropping this `+k` normalization is the single most common divisibility bug. Bake it into your fingers.

---

## BIT 7 — The inverse tool: DIFFERENCE ARRAYS (range UPDATE, point query)
Prefix sum answers **range query on a static array**. Its mirror answers **many range UPDATES, then
read**: the **difference array**. Add `val` to all of `L..R`? Don't touch R−L+1 cells — touch **two**:

```cpp
diff[L]   += val;
diff[R+1] -= val;               // the "off switch" at R+1 (guard R+1 < size, or size n+1)
// after ALL updates, prefix-sum diff ONCE → final array
for (int i = 1; i < n; i++) diff[i] += diff[i-1];
```

Q range-updates go from O(n·q) to O(q + n). It's prefix sum run **backwards**: you write the *deltas*,
then integrate. (LC1590 "Make Sum Divisible by P" leans on prefix+mod reasoning; range-update problems
lean on this.) Recognition: **"add x to every element in [L,R], many times, then read the array."**

---

## BIT 8 — When prefix+hash, when NOT (vs sliding window)
> **Sliding window needs monotonicity** — with all positives, adding grows the sum, so you know exactly
> when to shrink. **Prefix+hash does NOT need it** — it compares stored prefix *values*, so it survives
> **negatives**, ±1 transforms, and **count** questions.

- Negatives present · a ±1 transform · it's a **count / divisibility** → **prefix + hash**.
- All-positive + longest/shortest *contiguous* window → **sliding window** is simpler, O(1) space.

---

## BIT 9 — Complexity, read off the shape
- Build prefix / one sweep with a hash map: **O(n) time.**
- Hash map of prefixes: **O(n) space** (worst case all distinct).
- Range queries after an O(n) build: **O(1) each.**
- Difference array: **O(q + n)** for q updates then one read.
- `unordered_map` (O(1) avg) vs `map` (O(log n), ordered) — use `unordered_map` unless you need sorted
  keys. (LC523: 150ms → 81ms just by switching.)

---

## BIT 10 — The classic TRAPS (execution focus, boss — tied to your leaks)
1. **`seen[0]` sentinel wrong or missing** → silently undercounts subarrays starting at index 0
   (COUNT) or loses the whole-front-stretch length (LONGEST). COUNT ⇒ `seen[0]=1`; LONGEST ⇒ `seen[0]=-1`.
2. **`pre[-1]` / `pre[n]` out of bounds** → derive the range formula by MEANING with the sentinel
   `pre[0]=0`, use `pre[R+1]−pre[L]`. Never index `pre[L-1]` when L=0 on a 0-indexed prefix.
3. **COUNT vs LONGEST machinery mixed** → frequency+`+=` is COUNT; first-index+`max-gap` is LONGEST.
   Don't store-first-index while incrementing a frequency. Pick the row in the BIT 5 table and commit.
4. **Dropping the mod normalization** → `((run % k) + k) % k`; a raw negative `%` splits a residue class.
5. **Presence check with `if(seen[key])`** → a stored index `0` is falsy → LC523 false-miss. Use
   `.count()` / `.find()` for "have I seen this key," never truthiness of the value.
6. **First-index overwrite** → for LONGEST, store a prefix ONLY on first sight (`else` branch);
   overwriting shrinks every later gap.
7. **Overflow** → prefixes accumulate; large n or values ⇒ seed `run` / `pre` as `long long`.

---

## BIT 11 — Recognition cue (fill in YOUR words after the ladder)
> subarray **sum = k / divisible by k / equal counts / range query** — ESPECIALLY when **sliding window
> is dead** (negatives, or it's a *count* not a window) → **prefix sum (+ hash), decide GOAL × KEY.**
> Many range *updates* then read → **difference array** (prefix run backwards).

*(Your teach-it-back line goes here once you've re-coded the ladder — that's the L6 signal.)*

## Problems that taught this (same engine, different KEY)
- **LC560** complement / COUNT · **LC974** remainder + neg-mod · **LC525** ±1 transform / LONGEST ·
  **LC523** remainder (`.count()` trap) · **LC724** pure prefix balance point · **LC238** prefix×suffix ·
  **LC1590** prefix + mod. · LC862 PARKED (needs monotonic deque, M8).
