# M9b — Memoization  ·  THE RECURSION→DP BRIDGE  (teaching notes — reread cold, they rebuild the model)

> These notes TEACH, they don't just remind. Read top to bottom and the understanding comes back.
> Memoization is not a new algorithm — it's **recursion that stops repeating itself.** It's the
> single step from "recursion" to "dynamic programming." Live-proven on LC70 (2026-07-05): a correct
> brute recursion got TLE; the same recursion + a notepad went green.

---

## BIT 0 — The one sentence
> **Memoization = the SAME recursive function + a notepad: solve each subproblem ONCE, write down
> its answer, and next time that subproblem is asked, return the note instead of re-exploring it.**

Recursion + cache = **top-down dynamic programming.** That's the whole idea.

---

## BIT 1 — Why it exists (the "why")
A forking recursion **recomputes identical subproblems**, exponentially many times. `fib(n)` calls
`fib(n-1)` AND `fib(n-2)`, which **overlap** — they both need `fib(n-2)`, `fib(n-3)`, …

```
                 fib(5)
            /            \
        fib(4)          fib(3)   ← fib(3) computed AGAIN
       /     \         /     \
   fib(3)  fib(2)   fib(2)  fib(1)   ← fib(2) computed 3 TIMES
```
Nothing changes between two calls of `fib(3)` — it's *always* 2 — but the brute re-explores its whole
subtree every time. That waste is the **O(φⁿ) ≈ O(1.618ⁿ)** blow-up (lopsided tree → golden ratio,
not 2ⁿ). For `n=45` that's **~3.7 BILLION calls** → TLE. Memo kills the repeats.

> **The disease: recursion re-solves the same subproblem. The cure: remember the answer the first time.**

---

## BIT 2 — When memo actually helps (the trigger — don't miss this)
Memo pays off ONLY when subproblems **overlap** (the same input is asked more than once). Two things
must be true — the DP conditions:
1. **Overlapping subproblems** — the recursion tree revisits identical states. *(This is what memo fixes.)*
2. **Optimal substructure** — the answer is built from answers to smaller subproblems.

- **`fib` / `climbStairs`** — forks into overlapping subproblems → **memo is a massive win.**
- **`factorial` / `sum(1..n)`** — `fact(5)→fact(4)→fact(3)…`, each called **exactly once**, NO overlap
  → **memo does NOTHING** (there's nothing repeated to cache).

> Trigger: **forking recursion where the same input recurs → memoize.** Straight-line recursion → leave it.

---

## BIT 3 — The mechanics (two lines wrap your existing recursion)
Take the brute recursion you already wrote. Change NOTHING about its logic. Add two lines:
```cpp
long long fib(int n, vector<long long>& memo) {
    if (n <= 1) return n;                 // base case (unchanged)
    if (memo[n] != -1) return memo[n];    // ① SEEN IT? return the note, skip the subtree
    return memo[n] = fib(n-1,memo) + fib(n-2,memo);  // ② solve ONCE, STORE, then return
}
// driver: allocate the cache, seed with a "not computed yet" sentinel
long long fib(int n){ vector<long long> memo(n+1, -1); return fib(n, memo); }
```
- **① at the TOP:** cache hit → return immediately. This is the line that prunes the whole repeated subtree.
- **② at the RETURN:** compute once, `memo[n] = ...`, return the stored value. `x = (memo[n] = ...)`
  both stores and returns in one line.
- **Sentinel:** init to a value the answer can NEVER be (here `-1`, since counts ≥ 0) so "not computed"
  is distinguishable from a real answer of 0.

---

## BIT 4 — Hand-run: watch the tree collapse (Climbing Stairs, LC70)
`climbStairs(n)` = ways to reach step `n` taking 1 or 2 at a time = `climb(n-1)+climb(n-2)` (it's fib!).
Base: `n==0 → 1` (one way: stand still at the top), `n<0 → 0` (overshot, dead path).

**Brute, n=45:** number of calls ≈ `2 × answer − 1` = `2 × 1,836,311,903 − 1` ≈ **3.7 billion** → TLE.

**Memoized, n=45:** each `climb(k)` for `k = 0..45` is solved **once**, then every later ask is a cache
hit → **46 real computations.** The tree flattens into a line.

> **Same n. Same logic. 3,700,000,000 calls → 46.** That is the entire payoff of a notepad.

⚠️ Guard `n<0` BEFORE indexing `memo[n]` — a negative index is out-of-bounds. (Your LC70 solution had
`if(n<0) return 0;` sitting correctly above the cache read.)

---

## BIT 5 — The recipe (turn ANY brute recursion into memoized DP)
1. **Write the correct brute recursion first** (base + recursive case). Don't optimize yet.
2. **Identify the STATE** — which parameter(s) change between calls and fully describe a subproblem?
   That's your memo KEY. (fib/climb: just `n` → a 1-D array. Two changing params → a 2-D array/map.)
3. **Add the two lines:** cache-check at the top, store-before-return at the bottom.
4. **Size + seed the cache:** dimensions = the ranges of the state; sentinel = an impossible answer.
This is called **top-down DP** — you still think recursively, the cache just removes the waste.

---

## BIT 6 — Complexity, read straight off the states
> **Time = (number of DISTINCT states) × (work per state). Space = cache size + recursion depth.**

- `fib`/`climb`: `n` distinct states × O(1) each = **O(n) time**, O(n) cache + O(n) stack = **O(n) space**.
- A 2-D state `(i, j)` over an `m×n` grid: `m·n` states × O(1) = **O(m·n)**.
This is why memo turns exponential into polynomial: you can only ever do work once per distinct state,
and there are only polynomially many states.

---

## BIT 7 — Top-down (memo) vs bottom-up (tabulation) — a preview
Two ways to do DP; same recurrence, opposite direction:
- **Top-down (memoization):** the recursion you have + a cache. Lazy — only computes states it needs.
  Easiest to write (add 2 lines to the brute). Costs recursion-stack space.
- **Bottom-up (tabulation):** an explicit loop filling a table from the base cases UP, no recursion.
  `dp[0]=1; dp[1]=1; for i… dp[i]=dp[i-1]+dp[i-2];`. Often O(1)-space-optimizable (keep last 2 vars).
Learn top-down first (it's just recursion). Bottom-up comes in the DP module (M20). Both are DP.

---

## BIT 8 — The classic TRAPS (execution focus, boss)
1. **Wrong / colliding sentinel** — init to a value the real answer can take (e.g. `0` when 0 is a
   legal answer) → you re-treat a solved state as unsolved, or worse, trust garbage. Use an IMPOSSIBLE
   value (`-1` for non-negative answers).
2. **Reading `memo[n]` before guarding a negative/out-of-range `n`** → out-of-bounds. Base/edge guards
   come BEFORE the cache read. (This is your boundary leak — order the guards.)
3. **Forgetting to STORE before returning** → `return fib(n-1)+fib(n-2);` without `memo[n] =` → still
   exponential, still TLE. The store is the whole point.
4. **Keying on too few params** — if TWO things change between calls, the memo key needs BOTH, or
   different subproblems collide onto one slot → wrong answer.
5. **"Small n so brute is fine"** — n=45 with O(2ⁿ)/O(φⁿ) is billions of calls. Runtime scales with the
   NUMBER OF CALLS (~exponential), not with n. Small bound + "count ways / try all" often SIGNALS
   "exponential brute → must memoize." (See `01-Complexity-from-Constraints.md`.)

---

## BIT 9 — Recognition cue (fill in YOUR words after reps)
> **A recursion that FORKS and asks the same subproblem again → memoize it.** Surface tells: *"count
> the number of ways", "min / max cost over a sequence of choices", "can you reach / make X"* + a brute
> that TLEs. If the brute is correct but too slow AND subproblems repeat → add the notepad.

Problems that teach it (the DP on-ramp): **LC509 Fibonacci** · **LC70 Climbing Stairs** (fib in a
costume — the recognition rep) · **LC198 House Robber** · **LC746 Min Cost Climbing Stairs** ·
**LC322 Coin Change** · **LC1143 LCS** (2-D state). These live fully in the DP module (M20) — memo is
your bridge to them.

## 🔲 TO FILL AFTER REPS
- [ ] My cue in my own words: how do I spot "this brute needs memo"?
- [ ] The state I keyed on + why those exact params
- [ ] The TLE→AC moment (LC70) in one line — what the notepad changed
