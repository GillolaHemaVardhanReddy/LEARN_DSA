# 🧮 01 — Complexity from Constraints (the 10⁸ rule)

> The most practical complexity skill: **read the constraints → know the target complexity
> BEFORE writing code.** Also: knowing when to STOP optimizing (every problem has a floor).
> Part of M1 Complexity. Re-read before any problem — it tells you what solution they want.

---

## ⭐ The ONE fact behind everything
> A judge/computer does ~**10⁸ (100 million) simple operations per second.**
> Time limit ≈ **1 second** → your algorithm must do **under ~10⁸ operations.**

**"Operations" = your complexity formula with the MAX `n` plugged in.**
- Plug max `n` into your Big-O → compare to 10⁸.
- **Under 10⁸ → fast enough ✅ · Over → too slow, need a better approach ❌**

That single rule *generates* the whole table below — nothing is memorized.

## Worked examples (watch the rule work)
| n (max) | idea | work = O(...) at max n | vs 10⁸ | verdict |
|---|---|---|---|---|
| 10⁵ | O(n²) | (10⁵)² = **10¹⁰** | 100× over | ❌ too slow → need O(n log n)/O(n) |
| 5,000 | O(n²) | 5000² = **2.5×10⁷** | under | ✅ fine — O(n²) allowed |
| 20 | O(2ⁿ) | 2²⁰ ≈ **10⁶** | under | ✅ fine — brute force expected |
| 10⁶ | O(n²) | **10¹²** | 10⁴× over | ❌ → need O(n) or O(n log n) |
| 10⁶ | O(n log n) | 10⁶·20 = **2×10⁷** | under | ✅ fine |

## 🎯 The REVERSE use (the one you actually do)
Read `n`'s max **before coding** → "what's the slowest complexity still under 10⁸?" = your **target**:

| `n` up to… | Target complexity | Typical pattern |
|---|---|---|
| 10–12 | O(n!) | permutations |
| ~20–25 | O(2ⁿ) | subsets, bitmask, backtracking |
| ~500 | O(n³) | 3 nested loops OK |
| ~5,000 | O(n²) | pairs, simple DP, 2 loops |
| 10⁵–10⁶ | **O(n log n) or O(n)** | sort / sliding window / hash / two pointers |
| 10⁸+ | O(n) or O(log n) | math, binary search |

> The constraints are the setter **telling you what solution they want** before you write a line.

## Reference values worth knowing
- `log₂(10⁵) ≈ 17`, `log₂(10⁶) ≈ 20` → log factor is tiny (~20), basically "free."
- `2¹⁰ ≈ 10³`, `2²⁰ ≈ 10⁶`, `2³⁰ ≈ 10⁹`.
- `10! ≈ 3.6×10⁶`; factorial explodes past **n ≈ 11–12**.

---

## 🧱 The FLOOR — when to STOP optimizing (don't chase O(n) blindly)
Every problem has a **lower bound** — a floor no algorithm can beat. The skill is **aim for the floor, not for O(n).**
- Must **read** the input → floor **Ω(n)**.
- Must examine **all pairs**, no structure helps → floor **Ω(n²)**.
- **Sorting** inherent → floor **Ω(n log n)**.
- Must **output** something huge (all subsets) → floor **Ω(2ⁿ)**.

**Example — 3Sum's floor is O(n²)** (the famous *3SUM conjecture*: believed impossible to beat O(n² by more than log factors). Striver stopping at O(n²) wasn't lazy — that's the **wall**. Over-optimizing past the floor isn't smart, it's impossible.

> Mental model: ask *"what's the minimum work I'm FORCED to do?"* (read? all pairs? sort?) — that sets the target. Then constraints confirm it. Don't assume every problem collapses to O(n).

---

## ⚠️ Related complexity traps (full list in `00-Recognition-Map.md` §④)
- **"There's a sort" ≠ O(n log n).** Sort of `X` items = `O(X log X)`. Sort `k` items `n` times = **`O(n·k log k)`** (the `log` attaches to one sort's size; count of sorts multiplies outside).
- **`while` inside `for` ≠ automatically O(n²).** It's O(n) if the inner index never *resets* (sliding window: `left` only moves forward → ≤2n total).
- **A loop of n iterations is O(n) only if each iteration is O(1).**

_Last updated 2026-06-08. M1 Complexity (solidifying). See PROGRESS.md._
