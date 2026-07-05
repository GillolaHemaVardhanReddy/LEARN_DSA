# M1 — Complexity from Constraints  ·  (teaching notes — reread cold, they rebuild the model)

> These notes TEACH, they don't just remind. Read top to bottom and the understanding comes back.
> This is the most PRACTICAL complexity skill: before you write a line, the constraints already
> tell you which algorithm the setter wants. Re-read before any problem.

## 0. Striver videos (watch AFTER these notes)
- **Time & Space Complexity (Striver A2Z, Step 1)** — https://youtu.be/FPu9Uld7W-E ⭐ start here

---

## BIT 0 — The one sentence
> **The input constraints TELL you the algorithm. Read `n`, work backward to the allowed
> complexity, and that narrows the pattern before you write a single line.**

That's the whole skill. Everything below is *why that works* and *how to run it in your head*.

---

## BIT 1 — Why it exists (the "why")
Most learners read a problem and jump straight to *some* idea, then find out at submit time it's
too slow — TLE. That's coding blind. The constraint line (`1 ≤ n ≤ 2·10⁵`) isn't decoration; it's
the setter **whispering the intended complexity**. A judge runs on a real machine with a real clock,
so "too many operations" = "you lose." If you can read the target complexity off `n` first, you've
already **cut the search space of possible solutions** — you stop considering O(n²) before wasting
20 minutes coding it.

> Think of `n` like the size of a room and complexity like how fast you can clean it. A tiny room
> (n=20) you can scrub every corner twice over (O(2ⁿ)). A stadium (n=10⁶) you get **one efficient
> pass** (O(n) or O(n log n)) — no time to revisit spots.

---

## BIT 2 — The ONE fact everything is built on (the 10⁸ rule)
> A judge/computer does ~**10⁸ (100 million) simple operations per second.**
> Time limit ≈ **1 second** → your algorithm must do **under ~10⁸ operations.**

**"Operations" = your Big-O formula with the MAX `n` plugged in.**
1. Take your complexity, e.g. O(n²).
2. Plug in the **largest** `n` from the constraints.
3. Compare the number to 10⁸.

**Under 10⁸ → fast enough ✅ · Over 10⁸ → too slow, need a better approach ❌**

This single rule *generates* every table below — nothing is memorized. You derive it each time.

---

## BIT 3 — Big-O / Ω / Θ (the vocabulary, fast)
Three symbols, one idea — how work grows as `n` grows, ignoring constants:
- **Big-O (upper bound)** — "grows *no faster than* this." Your algorithm's **worst case**. This is
  the one you compute against 10⁸. When we say "O(n²) is too slow," we mean the worst case.
- **Ω (Omega, lower bound)** — "grows *at least* this fast." Used for the **problem's floor** (BIT 7):
  the minimum work ANY algorithm is forced to do.
- **Θ (Theta, tight bound)** — when upper and lower match, the growth is *pinned* exactly. E.g. a
  single flat loop over `n` is Θ(n) — no better, no worse.

Day to day you live in **Big-O for your algorithm** and **Ω for the problem's floor**. That pairing
is the whole game: aim your Big-O *down at* the problem's Ω.

---

## BIT 4 — HAND-RUN this (the part you run yourself, boss)
Constraint given: **`n ≤ 2·10⁵`**. A pairs-style idea (compare every element to every other) is O(n²).
Question: is it allowed? Run the rule by hand — don't guess.

```
Step 1  complexity        = O(n²)
Step 2  max n             = 2·10⁵ = 200,000
Step 3  plug in           = (2·10⁵)² = 4·10¹⁰   (200,000 × 200,000)
Step 4  compare to 10⁸    = 4·10¹⁰ is 400× OVER
        → at 10⁸ ops/sec that's ~400 seconds. Limit is 1s. DEAD. ❌
```
So O(n²) is off the table. What's the slowest thing still under 10⁸? Try O(n log n):
```
        O(n log n) at n=2·10⁵  = 2·10⁵ × log₂(2·10⁵) ≈ 2·10⁵ × 18 ≈ 3.6·10⁶
        3.6·10⁶ << 10⁸  → comfortably fine ✅  → THIS is the target.
```
Read it as: **"n is 2·10⁵, so I need O(n log n) or better."** That instantly points you at
**sort / two-pointers / sliding window / hashing / binary search** — and away from nested loops.
You knew the *shape* of the answer before writing anything. That's the unlock in action.

---

## BIT 5 — Worked examples (watch the rule fire)
Same 4-step check, different inputs. The verdict falls straight out of the arithmetic:

| n (max) | idea | work = O(...) at max n | vs 10⁸ | verdict |
|---|---|---|---|---|
| 10⁵ | O(n²) | (10⁵)² = **10¹⁰** | 100× over | ❌ too slow → need O(n log n)/O(n) |
| 5,000 | O(n²) | 5000² = **2.5×10⁷** | under | ✅ fine — O(n²) allowed |
| 20 | O(2ⁿ) | 2²⁰ ≈ **10⁶** | under | ✅ fine — brute force expected |
| 10⁶ | O(n²) | **10¹²** | 10⁴× over | ❌ → need O(n) or O(n log n) |
| 10⁶ | O(n log n) | 10⁶·20 = **2×10⁷** | under | ✅ fine |

Notice `n=5000` with O(n²) is **fine** — small `n` *permits* slower algorithms. Never reflexively
chase O(n); if the constraint allows O(n²), the simple double loop is the intended, correct answer.

---

## BIT 6 — The REVERSE lookup table (the move you actually make) ⭐
This is the everyday reflex: read `n`'s max **before coding** → "what's the slowest complexity still
under 10⁸?" → that's your **target**, and the target names the pattern.

| `n` up to… | Target complexity | Typical pattern |
|---|---|---|
| 10–12 | O(n!) | permutations |
| ~20–25 | O(2ⁿ) | subsets, bitmask, backtracking |
| ~500 | O(n³) | 3 nested loops OK |
| ~5,000 | O(n²) | pairs, simple DP, 2 loops |
| 10⁵–10⁶ | **O(n log n) or O(n)** | sort / sliding window / hash / two pointers |
| 10⁸+ | O(n) or O(log n) | math, binary search |

> The constraints are the setter **telling you what solution they want** before you write a line.

**Reference values worth burning in (so you don't stall on the arithmetic):**
- `log₂(10⁵) ≈ 17`, `log₂(10⁶) ≈ 20` → the log factor is tiny (~20), basically "free."
- `2¹⁰ ≈ 10³`, `2²⁰ ≈ 10⁶`, `2³⁰ ≈ 10⁹`.
- `10! ≈ 3.6×10⁶`; factorial **explodes** past `n ≈ 11–12`.

---

## BIT 7 — The FLOOR: when to STOP optimizing (Ω, the other half)
The rule above tells you the *ceiling* (don't go slower than this). The floor tells you when to
**stop** — every problem has a lower bound Ω no algorithm can beat. Aim for the **floor, not blindly
for O(n).**
- Must **read** all the input → floor **Ω(n)**.
- Must examine **all pairs**, no structure helps → floor **Ω(n²)**.
- **Sorting** is inherent → floor **Ω(n log n)**.
- Must **output** something huge (all subsets) → floor **Ω(2ⁿ)**.

**Example — 3Sum's floor is O(n²)** (the famous *3SUM conjecture*: believed impossible to beat O(n²)
by more than log factors). Striver stopping at O(n²) there wasn't lazy — that's the **wall**.
Over-optimizing past the floor isn't smart, it's impossible.

> Mental model: ask *"what's the minimum work I'm FORCED to do?"* (read everything? all pairs? sort?)
> — that sets the floor. Then the constraint (BIT 6) confirms the target. Don't assume every problem
> collapses to O(n).

---

## BIT 8 — The design recipe (run this BEFORE coding) ⭐ your Gate-A for complexity
Three questions, in order, before a single line:
1. **What's max `n`?** — read the constraint line. (If none given, assume the ceiling for that pattern.)
2. **What's the target?** — slowest Big-O still under 10⁸ at that `n` (BIT 6). *This names the pattern.*
3. **What's the floor?** — minimum forced work Ω (BIT 7). If floor == target, you're done designing;
   don't waste time chasing an impossible speedup.

Fill those three and you've pre-selected the family of solutions before touching the keyboard.

---

## BIT 9 — Classic TRAPS (execution focus, boss — these cost real submits)
1. **"There's a sort" ≠ O(n log n).** Sorting `X` items = `O(X log X)`. Sorting `k` items `n` separate
   times = **`O(n·k log k)`** — the `log` attaches to *one* sort's size; the *count* of sorts multiplies
   outside. Don't collapse them.
2. **`while` inside `for` ≠ automatically O(n²).** It's **O(n)** if the inner index never *resets*
   (sliding window: `left` only moves forward → total inner steps ≤ 2n). Count total moves, not nesting.
3. **A loop of n iterations is O(n) only if each iteration is O(1).** If the body does `O(n)` work
   (a `.find()`, a substring copy, a nested scan), it's O(n²). Look *inside* the loop.
4. **Overflow at scale.** If `n=10⁵` and you sum products, the accumulator can pass 2·10⁹ → **`int`
   overflows.** Constraints that permit big `n` often force **`long long`.** (Complexity is fine; the
   *type* betrays you.)
5. **Small `n` panic.** `n=20` with O(2ⁿ) is *fine* (10⁶ ops). Don't over-engineer a clever polynomial
   solution when brute force is what the tiny constraint is inviting.

---

## BIT 10 — Recognition cue (fill in YOUR words after a few problems)
> "See the constraint line FIRST → plug max `n` into candidate Big-O → under 10⁸ keeps it, over kills
> it → the surviving target complexity names the pattern."

*(Your teach-it-back line goes here once you've used this on a few problems — that's the L6 signal.)*

_Last updated 2026-07-05. M1 Complexity._
