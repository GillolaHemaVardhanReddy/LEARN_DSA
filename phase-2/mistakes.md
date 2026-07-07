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
- **Re-test:** the optimal `myPow` (owed) must handle n=INT_MIN — clears when he widens-then-negates unprompted there, and on the next negative-bound problem. → ✅ **PASSED 2026-07-07:** his AC `myPow` wrote `long long p = n; if(p<0) p = -p;` unprompted.

### M#5 — verdict literacy: read WHAT the judge says, not just red/green (2026-07-06, LC50)
- **Root cause:** with the brute's logic fully fixed he reported "even now it's worst" — treating any red LC verdict as "my logic is wrong" and hunting for a logic bug that didn't exist. The actual verdict class was scale (TLE / stack overflow at n≈2.1e9 recursive frames vs ~1e5 stack), which no logic fix can cure. Extends M#2 (LC70: cost tracks CALLS, not n's size).
- **Corrected model:** **WA = logic bug → hunt the trace. TLE/Runtime-Error at max constraints = scale wall → the ALGORITHM must change, stop polishing.** First move on any red: read the verdict TYPE + the failing input's size before touching code.
- **Re-test:** next red verdict, he names the class (logic vs scale) out loud before editing anything. Clears when that call is right unprompted.

### M#6 — the two-call recursion trap: halving the exponent but doubling the calls (2026-07-07, LC50)
- **Root cause:** wrote `return getpow(x,e/2) * getpow(x,e/2);` — believed writing the same call twice means computing it once. The machine runs BOTH; each spawns two more. Calls per level: 1, 2, 4, … 2³¹ — the doubling exactly cancels the halving, so T(e)=2T(e/2)+O(1)=**O(e)**: the brute's ~4 billion multiplications rearranged into a tree. LC verdict: TLE (and he correctly read it as a scale wall this time — M#5 holding).
- **Corrected model (his words):** *"calling recursion in multiple places made multiple calls where we can just use one time response."* **Recurse ONCE per level into a variable** (`double t = getpow(x,e/2); return t*t;`). Fast power wins by halving the WORK, not just the exponent. Same family as M#2/LC70: cost tracks the CALL TREE, and a second recursive call on the same line is a fork, not a reuse.
- **Re-test:** next divide-in-half recursion (merge sort, tree problems, LC241-style), he states the number of recursive calls per level BEFORE running, and any repeated call gets a variable unprompted. Also: given `f(n-1) + f(n-2)` vs `2*f(n/2)` vs `f(n/2)+f(n/2)`, he classifies each as chain/fork correctly.

### M#7 — memo as a hammer: cached a straight chain with an O(n) table (2026-07-07, LC50)
- **Root cause:** to kill the M#6 repeat he reached for memoization — pattern-matched "repeated work → memo" (fresh from LC70) without checking the SHAPE. Three compounding bugs: (1) `vector<long long>` memo for DOUBLE results → 0.25 truncated to 0, the cache destroys what it stores; (2) sized `memo(p)` but wrote `memo[p]` → off-by-one UB; (3) the killer: `vector(n)` at n=2³¹ = **~17 GB** → MLE. And once the t-variable fix was in, the recursion is a straight CHAIN (e → e/2 → … → 1, each state visited ONCE) → the memo gets **zero hits**. He then proposed shrinking the table to n/2 — still O(n), still ~8.5 GB: shrinking a wrong idea doesn't make it right.
- **Corrected model:** **a memo earns its memory through HITS** — it pays only when the call tree FORKS and subproblems overlap (fib/LC70). A chain has no overlap → nothing to cache. Repeated work on ONE LINE = a local variable; repeated work ACROSS calls = a memo. Before adding a cache, ask: how many distinct states, and does any state get asked twice? Also: the memo's value type must hold the answer's type (double results ≠ long long slots), and its size must fit the constraint (2³¹ slots never fits).
- **Re-test:** on LC746/LC198 (next in ladder — genuinely overlapping), he justifies the memo by naming the overlap FIRST ("state X is reached from both A and B") and states the table's size + value type before coding. Clears when he can say "memo helps here / does nothing here" correctly on both a fib-shaped and a chain-shaped recursion.
