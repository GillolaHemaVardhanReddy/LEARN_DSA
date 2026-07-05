# M9 Recursion — PRACTICE LADDER  (confidence → "I can face anything")

> **Mode: PRACTICE** (help-allowed, ≤1 hint then work, submit to the real judge). This is REPS,
> not a test — no level pressure. The point: see enough recursion SHAPES that the next unseen one
> is just "oh, it's that shape again."
>
> **Every problem, run your loop:** the 3-question recipe FIRST (① base case? ② smaller subproblem?
> ③ combine step?), then the leap of faith (trust the smaller call), then your gates before submit
> (trace a size-1 and empty input by hand — recursion's boundary lives in the base case).
>
> Climb in order. **Clear Tier 1 + Tier 2 fully = you're recursion-confident.** Tier 3–4 are the
> stretch that previews what's coming (Backtracking / Trees / Linked Lists).

---

## TIER 1 — Warm-up WINS (pure recursion, cement the reflex)
Start here to stack quick greens and feel the mechanics fire.

| # | Problem | Diff | Link | The shape → what to derive |
|---|---------|------|------|-----------------------------|
| 1 | **LC509 Fibonacci Number** | Easy | https://leetcode.com/problems/fibonacci-number/ | Branching recursion (your memoized fib). Instant win. |
| 2 | **LC1137 N-th Tribonacci** | Easy | https://leetcode.com/problems/n-th-tribonacci-number/ | Same fib shape, THREE terms `T(n)=T(n-1)+T(n-2)+T(n-3)`. Base cases 0,1,1. Feel the pattern generalize. |
| 3 | **LC344 Reverse String** | Easy | https://leetcode.com/problems/reverse-string/ | Two-pointer recursion (your `reverseRec`). Base = `l>=r`. Submit it. |
| 4 | **LC231 Power of Two** | Easy | https://leetcode.com/problems/power-of-two/ | Linear recursion: `n` is a power of 2 iff `n>0 && (n%2==0) && isPow(n/2)`, base `n==1→true`. |
| 5 | **LC50 Pow(x, n)** ⭐ | Medium | https://leetcode.com/problems/powx-n/ | **Fast power** — the O(log n) seed I planted! `pow(x,n)=pow(x*x, n/2)` (halve the exponent, not step down). Watch: negative `n` → `1/pow(x,-n)`, and `n = INT_MIN` overflow on negation (use `long`). |

---

## TIER 2 — Branching + MEMO (the DP on-ramp — your natural next step)
These are "count the ways / min cost over choices" → correct brute recursion, then memoize. Exactly
the LC70 move, on new costumes. This is where recursion becomes powerful.

| # | Problem | Diff | Link | The shape → what to derive |
|---|---------|------|------|-----------------------------|
| 6 | **LC70 Climbing Stairs** | Easy | https://leetcode.com/problems/climbing-stairs/ | ✅ done — re-affirm the memo transfer if rusty. |
| 7 | **LC746 Min Cost Climbing Stairs** | Easy | https://leetcode.com/problems/min-cost-climbing-stairs/ | `minCost(i) = cost[i] + min(minCost(i-1), minCost(i-2))`. Same fib skeleton, `+` → `min`. Memoize. |
| 8 | **LC198 House Robber** ⭐ | Medium | https://leetcode.com/problems/house-robber/ | The CHOICE recursion: at house `i`, **rob it** (`nums[i]+rob(i-2)`) OR **skip it** (`rob(i-1)`) → take the max. Base `i<0→0`. Memoize on `i`. This "pick max of two choices" is THE DP template. |
| 9 | **LC509→ compare** | — | — | After #8, notice: House Robber is fib's twin with a choice. That recognition = the win. |

---

## TIER 3 — "TRY ALL CHOICES" / generate (bridge to Backtracking, M10)
Recursion that builds a TREE of options. This IS the next module — treat these as a confident preview.

| # | Problem | Diff | Link | The shape → what to derive |
|---|---------|------|------|-----------------------------|
| 10 | **LC78 Subsets** ⭐ | Medium | https://leetcode.com/problems/subsets/ | At each element: **include it** OR **exclude it** → two recursive branches. The include/exclude tree. Collect the path at the leaf. This is the backtracking heartbeat. |
| 11 | **LC46 Permutations** | Medium | https://leetcode.com/problems/permutations/ | Recurse over "which unused element goes next," mark used / unmark on the way back. First taste of choose→recurse→**undo**. |

---

## TIER 4 — Recursion on STRUCTURES (preview Linked Lists M11 / Trees M12)
Recursion isn't just numbers — it shines on self-similar data. Optional stretch; builds fearlessness.

| # | Problem | Diff | Link | The shape → what to derive |
|---|---------|------|------|-----------------------------|
| 12 | **LC206 Reverse Linked List** | Easy | https://leetcode.com/problems/reverse-linked-list/ | Leap of faith on a list: trust `reverse(head.next)` reverses the rest, then fix the two pointers at your level. Mind-bending the first time — that's the point. |
| 13 | **LC104 Max Depth of Binary Tree** | Easy | https://leetcode.com/problems/maximum-depth-of-binary-tree/ | `depth(node) = 1 + max(depth(left), depth(right))`, base `null→0`. The purest "trust the children" recursion — your on-ramp to all of Trees. |

---

## How to work this ladder
- **Tier 1** first — bank 5 quick greens, feel unstoppable. (LC344/LC509 you basically already own.)
- **Tier 2** is the real muscle — the recursion→memo move on fresh problems. **LC198 House Robber is the
  keystone**; nail its "rob vs skip → max" and half of DP opens up.
- **Tier 3–4** when you want to stretch — they literally open M10/M11/M12. No rush.
- Scaffolds (brute→bridge→optimal→stress) get created just-in-time when you reach each — ping me
  ("scaffold LC198") and I'll wire the file, or just code it straight and submit.

**Confidence bar:** clear Tier 1 + Tier 2 → you can walk into any interview recursion warm-up cold. 🔥
