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
