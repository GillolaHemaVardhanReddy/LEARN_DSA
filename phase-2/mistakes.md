# Phase 2 — Mistakes (root cause + re-test)

> One entry per mistake: root cause → corrected mental model → re-test problem & date.
> Feeds the leak scoreboard in COMMAND_CENTER.md and the queue in REVISION_QUEUE.md.
> (Phase-1 mistakes live in `phase-1/mistakes.md`.)

### M#1 — "empty-container read returns 0" (2026-07-04, LC933)
- **Root cause:** believed `deque.back()` on an empty container returns `0`. It's **undefined behavior** (garbage/crash), never a clean 0. His #1 boundary/empty-container leak surfacing in C++ form.
- **Corrected model:** before reading an end (`.back()/.front()/.top()`), GUARANTEE non-empty — either `!c.empty()` in the loop guard, or a proven invariant. In LC933 the just-pushed `t ≥ t-3000` is a sentinel that keeps the deque non-empty, so the loop can't pop the last element. He derived this himself once corrected.
- **Re-test:** on LC239 (next), before every `dq.front()`/`dq.back()` read, he states out loud what guarantees it's non-empty. Clears when he guards an end-read unprompted. Also see CPP_GAPS #9. → ✅ **PASSED on LC239** (guarded every end-read behind `!dq.empty()`).

### M#2 — "small n so brute is fine" + brute recursion needs memo (2026-07-05, LC70)
- **Root cause:** wrote a CORRECT brute `climbStairs(n)=climb(n-1)+climb(n-2)`, got **TLE**, and was surprised "because n≤45." Mental model gap: judged cost by the SIZE of n, not by the NUMBER OF CALLS. The naive fib-shaped recursion makes ~`2·answer` ≈ **3.7 billion** calls at n=45 (grows like φⁿ ≈ 1.618ⁿ, the lopsided-tree bound — not 2ⁿ).
- **Corrected model:** runtime tracks the call-tree SIZE, which is exponential for forking recursion → a small bound + "count ways / try all" often SIGNALS "exponential brute, must **memoize**." Memo = same recursion + a notepad (cache each state once); collapses O(φⁿ)→O(n). He transferred `fibMemo` onto LC70 himself → AC. See `phase-2/notes/09b-memoization.md` + `01-Complexity-from-Constraints.md`.
- **Re-test:** next "count the ways / min-cost over choices" problem (LC198 House Robber / LC322 Coin Change) — he predicts the brute's complexity from the constraint BEFORE coding, and reaches for memo unprompted when subproblems overlap.

### M#3 — C++ fluency: `print()` / single-quote string (2026-07-05, 01-Print-Patterns)
- **Root cause:** wrote `print('hi')` — Python muscle memory. C++ has no `print`; `'hi'` is a multi-char CHAR literal, not a string.
- **Corrected model:** print with `cout << "hi"`; **double quotes = string**, single quotes = one char. (Also self-caught a separate logic bug: `printNto1` recursed into `print1toN` — wrong self-reference — found by his own trace.) → CPP_GAPS.
- **Re-test:** clears when a print/output line compiles first try with `cout <<` and correct quoting.

### M#4 — negation in the NARROW type: `abs(n)` at INT_MIN (2026-07-06, LC50 Pow(x,n))
- **Root cause:** brute used `getpow(x, abs(n))` — `abs` runs while n is still an **int**, so at n=INT_MIN it tries to produce +2^31, which doesn't exist in int → overflow/UB *before* the value ever reaches the `long long` parameter. The widening came too late. His first model of the bug was also wrong ("long long won't hold that big") — long long tops out at ~9.2e18; +2^31 is trivial for it. The container was never the problem; the ORDER was.
- **Corrected model:** **widen BEFORE any arithmetic — negation counts as arithmetic.** `long long p = n; if (p<0) p = -p;` — copy into the wide type first, flip second. Same leak-#8 family as "size the accumulator," new costume: this time it's not the sum that overflows, it's the sign flip. He wrote the fixed version himself once the trap was traced.
- **Re-test:** the optimal `myPow` (owed) must handle n=INT_MIN — clears when he widens-then-negates unprompted there, and on the next negative-bound problem.

### M#5 — verdict literacy: read WHAT the judge says, not just red/green (2026-07-06, LC50)
- **Root cause:** with the brute's logic fully fixed he reported "even now it's worst" — treating any red LC verdict as "my logic is wrong" and hunting for a logic bug that didn't exist. The actual verdict class was scale (TLE / stack overflow at n≈2.1e9 recursive frames vs ~1e5 stack), which no logic fix can cure. Extends M#2 (LC70: cost tracks CALLS, not n's size).
- **Corrected model:** **WA = logic bug → hunt the trace. TLE/Runtime-Error at max constraints = scale wall → the ALGORITHM must change, stop polishing.** First move on any red: read the verdict TYPE + the failing input's size before touching code.
- **Re-test:** next red verdict, he names the class (logic vs scale) out loud before editing anything. Clears when that call is right unprompted.
