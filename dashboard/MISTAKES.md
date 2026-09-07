# MISTAKES.md — root causes + re-tests (one file, all eras)

> **How to use:** every bug gets (1) the wrong move, (2) the ROOT cause (a mental-model error, never
> "careless"), (3) the corrected model, (4) a prevention rule, (5) an unseen re-test + date → also
> into `REVISION_QUEUE.md`. A root cause that fires 3× is promoted to the **watchlist** and to the
> kryptonite pre-load (Gate 1). "Which gate would've caught this?" — one line, every time.
>
> **Live watchlist (v2, 2026-09-07)** = the leak board in `PROGRESS.md`. Top two: **M#12 tool-carryover**
> (answering with the previous question's tool → the 4-question disqualifier gate BEFORE naming a
> pattern) and **M#13 complexity as decoration** (wrong on 6/9 → "which line produces each factor?").
>
> **Numbering:** era-1 entries are `#1–#11` (Jun 2026), era-2 entries are `M#1–M#13` (Jul–Aug 2026).
> **v2 entries continue as `#14, #15, …`** below the watchlist. Era files are kept verbatim after.

## v2 entries (from 2026-09-07)

_(none yet)_

---

# ERA 2 — Phase-2 mistakes (M#1–M#13, 2026-07-04 → 2026-08-10)

# Phase 2 — Mistakes (root cause + re-test)

> One entry per mistake: root cause → corrected mental model → re-test problem & date.
> Feeds the leak scoreboard in dashboard/PROGRESS.md (leak board) and the queue in REVISION_QUEUE.md.
> (Phase-1 mistakes live in `dashboard/MISTAKES.md`.)

### M#1 — "empty-container read returns 0" (2026-07-04, LC933)
- **Root cause:** believed `deque.back()` on an empty container returns `0`. It's **undefined behavior** (garbage/crash), never a clean 0. His #1 boundary/empty-container leak surfacing in C++ form.
- **Corrected model:** before reading an end (`.back()/.front()/.top()`), GUARANTEE non-empty — either `!c.empty()` in the loop guard, or a proven invariant. In LC933 the just-pushed `t ≥ t-3000` is a sentinel that keeps the deque non-empty, so the loop can't pop the last element. He derived this himself once corrected.
- **Re-test:** on LC239 (next), before every `dq.front()`/`dq.back()` read, he states out loud what guarantees it's non-empty. Clears when he guards an end-read unprompted. Also see CPP_GAPS #9. → ✅ **PASSED on LC239** (guarded every end-read behind `!dq.empty()`).

### M#2 — "small n so brute is fine" + brute recursion needs memo (2026-07-05, LC70)
- **Root cause:** wrote a CORRECT brute `climbStairs(n)=climb(n-1)+climb(n-2)`, got **TLE**, and was surprised "because n≤45." Mental model gap: judged cost by the SIZE of n, not by the NUMBER OF CALLS. The naive fib-shaped recursion makes ~`2·answer` ≈ **3.7 billion** calls at n=45 (grows like φⁿ ≈ 1.618ⁿ, the lopsided-tree bound — not 2ⁿ).
- **Corrected model:** runtime tracks the call-tree SIZE, which is exponential for forking recursion → a small bound + "count ways / try all" often SIGNALS "exponential brute, must **memoize**." Memo = same recursion + a notepad (cache each state once); collapses O(φⁿ)→O(n). He transferred `fibMemo` onto LC70 himself → AC. See `practice/09-recursion/notes-memoization.md` + `01-Complexity-from-Constraints.md`.
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

### M#8 — the `pick` flag: redundant maintained state, as a recursion parameter (2026-07-10, LC78 Subsets)
- **Root cause:** wrote `getsets(nums, ans, i, sett, int pick)` with `if(pick) push` … `if(pick) pop`. Three failures fell out of that one design: (1) the **pop landed BETWEEN the two child calls** — it removes `nums[i]`, but those calls decide about `nums[i+1]`, so the subtree that should still live inside "I picked `nums[i]`" ran without it; (2) the **decision about `nums[i]` lives at the PARENT's call site** (`getsets(...,1)` vs `getsets(...,0)`) while the **action lives in the child** — choose and un-choose in different frames; (3) the root was a single forced `getsets(...,pick=1)`, so **nobody ever forked on `nums[0]`** → `{}` and every subset without `nums[0]` could never be born. Trace of `[1,2,3]` emitted 8 entries with `[1]` twice, `[]` three times, and `[2] [1,3] [2,3]` missing.
- **Corrected model:** **this is the DERIVE-DON'T-MAINTAIN leak wearing a recursion costume.** The flag is a variable whose only job is to agree with a fact the code already knows ("did I push?") — two things that must stay in sync. Delete it: frame `i` picks `nums[i]` *itself*, both ways, and `push / recurse / pop / recurse` sit in a straight line in one frame. Nothing to sync, nothing to desync. Bonus: every frame becomes uniform, so the root is just `solve(0)` with no special case. **Uniform frames are the tell of a correct recursion.** He derived the fix and the invariant himself: *"if we go to next call with a state and come back then we should have same state of sett."*
- **Re-test:** LC46 Permutations + LC39 Combination Sum. Frame owns its own choice; no boolean/flag parameter threaded down; `choose → explore → un-choose` visible as three consecutive lines. Clears when he writes a backtracking frame with zero state passed down beyond the index/start. Feeds the **band-aid / redundant maintained state** leak row.

### M#9 — oracle contamination: the brute slot held the thing under test (2026-07-10, LC78 Subsets)
- **Root cause:** deleted the scaffolded **bitmask** brute and wrote the *recursion* into `subsetsBrute()`, leaving `subsets()` returning `{}`. The stress harness then compares the recursion against… the recursion. Had both been wired, a shared bug would print `all subset cases passed`. Then declared "fixed and submitted" without running it — the harness actually dies instantly on the n=1 edge (`EDGE FAIL n=1: got 0 subsets`), which one run would have shown.
- **Corrected model:** **an oracle must be built a DIFFERENT WAY than the thing it checks.** Two independent derivations agreeing is evidence; one derivation agreeing with itself is a tautology. That's the whole reason the scaffold pairs `bitmask` (iterative, `mask & (1<<i)`) with `recursion` (tree, choose/explore/un-choose) — different machinery, same answer. If the brute and the optimal share an idea, the stress test is decoration. Second half: **"submitted" is not "verified."** Run the harness, read the output, then speak. (Ties to leak: premature "done" — declared finished before self-running Gate C.)
- **Re-test:** on the next brute→optimal scaffold, before coding he names *how the brute's machinery differs from the optimal's* in one sentence, and he pastes the stress output himself before saying "done." Clears when he catches an oracle that shares the optimal's idea, unprompted.
- **Status 2026-07-14 (LC46): STILL OPEN.** The brute *was* independent machinery (`next_permutation`, iterative, zero recursion) — but that was the **scaffold's** call, not his, so the rep didn't happen. And he immediately fired the sibling bug below (M#10). Stays open.

### M#10 — the oracle MUTATED the input its test subject was about to read (2026-07-14, LC46 Permutations)
- **Root cause:** wrote `permuteBrute(vector<int>& nums)` — a **reference** — then `sort(nums.begin(), nums.end())` and let `next_permutation` stomp it all the way to fully-descending. The scaffold said *sort a **copy***; he sorted the caller's array. In `main()` the harness calls `permuteBrute(nums)` **first** and `permute(nums)` **second**, so the optimal received the wreckage the oracle left behind. The two functions were sharing mutable state through the harness.
- **Why it's nasty — IT PASSES.** Permutations of a *set* don't depend on the input's arrival order (perms of `[3,1,2]` ≡ perms of `[1,2,3]`), and `normalized()` sorts the collection before comparing. So both sides agree, the harness prints `all permutation cases passed`, and the bug is **invisible**. No compiler warning, no failing test. It only *happens* to be defused by this one problem being order-insensitive — the next problem where input order matters (perms **with duplicates**, anything emitting in index order) and the harness lies to your face while you trust it.
- **Corrected model:** **an oracle must be independent in MACHINERY *and* in STATE.** Different algorithm is only half of it — if it reaches into the data the thing-under-test is about to read and rearranges it, it isn't a witness, it's a participant. Rule: **a brute takes a copy, never a mutable reference.** `vector<int> a = nums;` first line, always. Generalizes past oracles: *a function that must not change the world should not accept a handle to it.*
- **Meta-leak:** boss did **not** catch this — Kira did. And the green stress test would have blessed it forever. Same family as M#9 (a stress test you can't trust is worse than none: it converts an unknown into a false *known*).
- **Re-test:** next brute→optimal scaffold, **before** running the stress he states (a) how the brute's machinery differs, **and (b) whether the brute can touch anything the optimal reads.** Clears when he flags a mutating/shared-state oracle unprompted. Re-attempt date: **LC39 Combination Sum, next session.**

### M#11 — dedup on one form, store another: the canonical-key mismatch (2026-07-15, LC39 Combination Sum brute)
- **Root cause:** in the brute oracle he guarded with the **sorted** copy but stored the **raw** one: `sort(check…); if(!ans.contains(check)) ans.insert(chk);`. `check` and `chk` are two spellings of the same combo. A `set` dedups by *exact* key, so the guard ("is sorted `[2,3]` present?") and the storage (`[3,2]`) never agree → both permutations survive. Fired only on **unsorted** candidates: `[3,2]` t=5 → returns `[2,3]` **and** `[3,2]`.
- **Why the stress DIDN'T catch it (the nasty part, again):** the harness's generator builds candidates via `set<int>` (line 98) → always **sorted ascending**, and with sorted candidates the DFS finds the ascending permutation *first*, so the sorted-guard happens to catch every later dupe. 3000 random cases GREEN. A latent bug the test can't see — same family as M#9/M#10: a green stress that's blessing a bug because the input distribution never exercises it. Kira only exposed it by hand-feeding `[3,2]`.
- **Corrected model:** **to dedup, pick ONE canonical form and use it for BOTH the key and the stored value.** Store the same thing you compare on. Once you insert the sorted `check`, `set::insert` already no-ops dupes → the `!ans.contains` guard is dead weight. He fixed it himself (`insert(check)`); verified correct across the LC examples + no internal dups.
- **Re-test:** next time he dedups a collection (subsets-with-dups LC90, n-queens boards, any `set<vector>`/`set<string>` of canonicalized states), he states the canonical form ONCE and uses it for key **and** value. Clears when he never stores a non-canonical spelling of a key he dedups on.

### M#12 — TOOL-CARRYOVER: answering a new statement with the previous question's tool (2026-08-10, Comeback Gauntlet Q5→Q7)
- **Root cause:** three consecutive questions, and the tool is inherited each time instead of chosen. **Q5** → he picks pick/not-pick recursion (correct). **Q6** opens with the literal words ***"here also its pick not pick"*** — on a **subarray** counting problem, where pick/not-pick is structurally incapable of the job. He then invents sliding window for Q6, and **Q7** opens with ***"this is a fixed sliding window"*** — on a pairing problem that needs sort + converging two pointers. The tool arrives **before** the statement is interrogated; the statement is then bent to fit it.
- **Why it's nasty:** it is *invisible in single-topic practice*. Inside a topic folder, carrying the topic's tool forward is always right, so the habit gets rewarded for weeks. It only fires under interleaving — i.e. **exactly and only in an interview or a contest**, where nothing tells you which chapter you're in. This is also why it went undetected through four L4 promotions.
- **Sub-leak (a recurrence): subarray → pick/not-pick.** The Q6 answer is the **same vocab trap he corrected on 2026-07-14** and banked in `PATTERN_JOURNAL.md`: **subarray = CONTIGUOUS**; pick/not-pick emits `[1,3]` from `[1,2,3]`, so it makes **subsequences**. He wrote the cue down and it did not fire when it mattered. A banked cue that only fires when you're already thinking about the topic isn't banked.
- **Corrected model:** **the tool is the LAST thing you choose, not the first.** Before naming any pattern, run a 4-question **disqualifier gate** on the statement itself: **(1) contiguous or not?** (subarray vs subsequence/subset) · **(2) sorted, or am I allowed to sort?** (2-pointer vs hashing) · **(3) does ORDER matter, or only MEMBERSHIP?** (loop+`used[]` vs pick/not-pick) · **(4) am I asked to COUNT, to find the BEST, or to LIST ALL?** (counting math vs greedy/DP vs enumeration). The gate is about the *problem*, not the toolbox — that's the point: it can't be biased by the previous question. Only after all four does a tool get named.
- **Re-test:** **Q10 → Q20 of this same gauntlet, live.** The tell to watch for is any answer that opens with *"here also…"*, *"this is the same as…"*, or that names a tool before restating what's being asked. Clears when he names the disqualifier answers **before** the pattern on a question whose neighbour used a different tool. Also re-tested at Part C.

### M#13 — complexity stated as decoration, not as a derived quantity (2026-08-10, Comeback Gauntlet Q1–Q9)
- **Root cause:** he answers the complexity slot in every question, fluently and fast — and it was **wrong on 6 of 9**: Q5 *"O(n log n)"* on an exponential brute (a bound that corresponds to no step in his own algorithm — there is no sort and no halving anywhere in it) · Q7 O(n)/O(1) quoted for an algorithm that doesn't solve the problem · Q9 O(n)/O(1) for a machine that must re-scan or re-sort on every shrink · Q1 space O(n) for a map holding n² entries · Q2 O(log n) with the O(n) feasibility check dropped · Q3 a **per-day** O(n) quoted as the **total** (it's O(n²)).
- **Why it's nasty:** wrong complexity is the one error that **never produces a failing test**. It passes silently in practice and then decides, in an interview, whether he optimizes at all — Q3 is the proof: he quoted his brute as O(n), so from where he was standing **there was nothing left to improve**, and the monotonic stack became unreachable. A complexity error doesn't just misreport the answer; **it hides the bottleneck**, which kills step 4 of the whole problem-solving loop.
- **Corrected model:** complexity is **counted off your own written algorithm**, never pattern-matched to a shape you've seen. Say it as a sentence with the work in it — *"for each of the n days I walk back up to n steps ⇒ n·n"*, *"the map holds one entry per (i,j) pair ⇒ n² entries"* — and **the letters in the bound must be traceable to real steps in the code**: an `n log n` needs a sort or a halving you can point at; an `O(1)` space needs you to name every container and show it's bounded. **Per-item cost × number of items = total** (the Q3 killer).
- **Re-test:** Q10→Q20, plus **standing on every future problem**: after stating a bound he must name **which line produces each factor**. Clears after 3 consecutive problems with a complexity that survives that challenge. **M1 Complexity's L3\* is self-reported and is now contradicted by evidence — it does not get re-rated up until this clears.**

### M#9 / M#10 — LC39 re-attempt status (2026-07-15): STILL OPEN.
- The re-test rode on this session but **didn't complete**: the optimal (`combinationSum`, the thing under test) was never written — it stayed `return {}`, so brute-vs-optimal never actually ran. He submitted the optimal **straight to LeetCode** (bypassing his own harness) and hit WA on `[8,7,4,3]` t=11 — the exact case the harness would have caught locally. **M#10 independence line (b) not stated unprompted.** Both re-tests roll to the NEXT session, when he writes the optimal and runs the stress. (Note: this rep's brute is *recursion*, the optimal is *start-index backtracking* — different structure, but weaker machinery-independence than the dp the scaffold originally asked for; it survives only because the blind-enumerate+set-dedup brute cannot share the `start`-index bug.)

---

## ✅ CLEARED

### M#8 — CLEARED 2026-07-14 (LC46 Permutations)
Wrote `permuteRecur` with **zero flag parameters**. `choose → explore → un-choose` sit as three straight lines in one frame, and he restored **both** pieces of state (`chk.pop_back()` **and** `ind[j] = 0`) after the recursive call returned — un-choosing a *second* piece of state, unprompted, having only ever seen the one-piece version. Frame owns its own choice. The invariant he named on 7/10 transferred without being re-taught. Verified: 20k random stress GREEN vs an independent oracle.


---

# ERA 1 — Phase-1 mistakes (#1–#11, 2026-06)

# dashboard/MISTAKES.md — Error Eradication for Hema Vardhan

> Mistakes are the highest-signal data you have. The goal isn't to feel bad — it's
> to find the **root cause** and schedule a **re-test** so the same error can't
> survive. Every entry gets a re-attempt date that also goes into `REVISION_QUEUE.md`.

Mistake types: Logic · Complexity · Edge case · Pattern-recognition · Concept-
misunderstanding · Implementation/syntax.

---

## Entry template
```
### [#id] <short title>
Date:
Module / Pattern:
Problem:
Type:
What I did (the wrong move):
Root cause (the real reason — not "careless"; what mental model was off?):
Correct understanding:
Prevention rule (a checklist item I'll apply next time):
Re-test problem (similar, unseen):
Re-attempt on:  (date — also in REVISION_QUEUE.md)
Status: Open / Re-tested-pass / Re-tested-fail
```

---

## Entries
> Newest first. Keep them short and honest.

### [#11] `atMost(k)−atMost(k−1)`: filtered the helper to "exactly k" + merged counter into answer
Date: 2026-06-16
Module / Pattern: Sliding window — count-subarrays-with-exactly-k via `atMost(k) − atMost(k−1)` (P14 / LC1248)
Problem: P14 Count Number of Nice Subarrays, the third (window-subtraction) approach.
Type: Concept-misunderstanding + Implementation
What I did (the wrong move): (a) Inside `atMost`, mentally counted only subarrays with EXACTLY k odds — threw out the shorter windows with fewer odds (e.g. claimed `[2,2,3,2,3]`'s suffixes `[2 3]` and `[3]` "don't count" because they have 1 odd, not 2). (b) In code, stapled the subarray-count length `r−l+1` onto the odd-COUNTER variable `cnt` (`cnt += r−l+1`) instead of onto `ans`; and clung to an `if(cnt<=k) ans+=… else { while-shrink; ans++ }` structure that double-counted and under-added.
Root cause: didn't internalize WHY `atMost` must over-count — the whole machine works because `atMost(k)` deliberately includes the 0-odd and skimpy windows, and the subtraction cancels everything below exactly-k. Suppressing them inside the helper breaks the cancellation. The code leak is the same boundary-family habit: two responsibilities (count-the-odds vs count-the-subarrays) collapsed into one variable, plus a redundant guard after a `while` whose invariant already guarantees `cnt<=k`.
Correct understanding: `atMost(k)` = for each r, shrink while `cnt>k`, then UNCONDITIONALLY `ans += r−l+1` (every subarray ending at r is valid because the while restored the invariant — the `if(cnt<=k)` after it is dead code). `exactly(k) = atMost(k) − atMost(k−1)`: exactly-k survives (+1−0), fewer-than-k cancels (1−1), more-than-k stays 0 (0−0).
Prevention rule: (1) One variable = one job — a COUNTER counts events, the ANSWER accumulates results; never `+=` a length onto a counter. (2) After a `while` that restores a condition, that condition is an INVARIANT — don't re-guard it with an `if`. (3) For `atMost−atMost`, never filter the helper to "exactly" — the helper MUST over-count or the subtraction is meaningless.
Re-test problem (similar, unseen): LC930 Binary Subarrays With Sum (goal==S) or LC992 Subarrays with K Different Integers — both want exactly-k via `atMost(k)−atMost(k−1)`; write `atMost` clean from scratch (unconditional `ans += r−l+1`).
Re-attempt on: 2026-06-19 (also in REVISION_QUEUE.md)
Status: Open

### [#10] Skipped "restate the problem" → two MISreads under drill pressure
Date: 2026-06-13
Module / Pattern: Process (problem-solving loop step 1) — surfaced on M6 search-on-answer (Q4) + binary-search-on-answer combo (Q6)
Problem: hard interleaved drill — Q4 (max-min router gap) read as "find min difference / avoid consecutive"; Q6 (k-th smallest pairwise distance) read TWICE as "find the minimum distance".
Type: Concept-misunderstanding / comprehension
What I did (the wrong move): jumped straight to pattern-hunting on the surface words ("distance", "pair", "min") without first restating what the problem actually asks. Q4: collapsed "maximize the minimum gap" into "find the min gap." Q6: collapsed "k-th smallest distance" into "the smallest distance" — even after a correction, repeated the same misread.
Root cause: under drill/time pressure, step 1 of the loop (restate + tiny dry run) gets skipped. The pattern vocabulary is strong enough that it fires on keywords before comprehension finishes — so a misread problem gets a confidently-wrong pattern. Both misses were READING failures, not tool failures: once the statement was pinned down (via a 3-element dry run), the right pattern (binary-search-on-answer) came quickly.
Correct understanding: ALWAYS restate the problem in one plain sentence + run a 3-element dry run BEFORE naming a pattern. For Q4 "largest possible minimum gap" and Q6 "k-th smallest among all pairwise distances," a tiny example (e.g. [1,3,7], k=2 → distances {2,4,6} → 4) instantly exposes the real ask.
Prevention rule: **Before pattern-hunting, write/say: (1) one-sentence restatement, (2) the answer on a 3-5 element example by hand.** If I can't produce both, I don't understand the problem yet — no pattern call allowed.
Re-test problem (similar, unseen): next drill — a wordy/disguised statement (esp. a min/max-of-something or k-th-something) restated correctly on the FIRST read with a dry run, before naming a tool.
Re-attempt on: 2026-06-14 (next drill)
Status: Open

### [#9] Unsorted-pair FIRST instinct still reaches for two pointers (recovers, but isn't reflexive)
Date: 2026-06-10
Module / Pattern: M2 Hashing ↔ M3 Two Pointers discrimination (drill Q1)
Problem: `/drill` Q1 — unsorted array, return indices of a pair summing to target
Type: Pattern-recognition
What I did (the wrong move): led with "sort + two pointers (or binary search), O(n)/O(log n)", THEN hedged to a hash map. The pattern was eventually right but the FIRST move was the over-application — and the sort idea is doubly wrong here (O(n log n), and sorting destroys the original indices the problem asks for). Also claimed an impossible O(log n) (must read every element → O(n) floor).
Root cause: the disqualifier check isn't automatic. "Two pointers" fires on "find a pair" by surface feature, before checking the gate "is the data SORTED? would sorting lose indices?". Twin failure: hashing under-fires while two-pointers over-fires — same coin.
Correct understanding: unsorted + find a pair (esp. return INDICES) → **one-pass hash map** value→index, look up `target-x`, O(n). Two pointers earns the call ONLY when the data is already sorted.
Prevention rule: before saying "two pointers," run the gate OUT LOUD — "Is it sorted? No → two pointers is OFF the table → hashing." Make the disqualifier the first thought, not the recovery.
Re-test problem (similar, unseen): next `/drill` — an unsorted pair/complement question named HASHING on the first instinct, no two-pointers detour. Earns Hashing + Two-Pointers L5 together.
Re-attempt on: 2026-06-14 (next interleaved drill)
Status: **RE-TESTED FAIL ×3 (2026-06-13, then again 2026-06-20)** — 5th occurrence on the 6/20 recognition recap: "unsorted, find any two summing to target" → led with "first SORT then two pointers" AGAIN (then named two-pointers cleanly on the very NEXT question that WAS sorted — so the knowledge is there, the GATE isn't firing). **NEW ROOT CAUSE he surfaced himself (the real breakthrough): "2 sum means I just directly go to 2 pointer, I don't know why."** → it's a **WORD COLLISION**: "**Two** Sum" (the problem name) ↔ "**Two** Pointers" (the technique) both contain "two" → his brain pattern-matches on the *word*, not the *structure*. The re-anchor given: **"Two Sum is a HASHING problem; the 'two' = count of numbers, NOT pointers; the technique is decided by *is it sorted?* — never by the title."** Also re-taught: complement = `target − curr` (he flipped the sign), and classic Two Sum needs NO min/max-index bookkeeping (check-before-insert handles dups). Earlier (6/13) wrinkles still stand: O(n) floor (must read every element), indices-destroyed-by-sort disqualifier. Hashing + 2ptr stay L4. The word-collision frame is the new weapon — re-test whether it kills the reflex.

### [#8] Integer overflow — didn't reason the MAGNITUDE of the arithmetic (only indices)
Date: 2026-06-10
Module / Pattern: M6 Binary Search (LC875 Koko, search-on-answer)
Problem: LC875 Koko Eating Bananas — runtime crash `signed integer overflow: 1610612736 + 805306368 cannot be represented in type 'int'`
Type: Edge case / boundary-value (magnitude)
What I did (the wrong move): wrote `mid=(s+e)/2` with `s,e` as VALUES up to 1e9 → the SUM (2.4e9) overflows `int` before the `/2`. Also `int sum` for the feasibility accumulator Σceil(pile/k), which at k=1 = total bananas up to 1e13 — also overflows. Reasoned the index edges but never the SIZE of the numbers.
Root cause: my boundary checklist covered init values / off-by-one / sentinels / order — but had NO line for "how big can each `+`/`*`/accumulator get? does it fit the type?" The leak is the same family as the index bugs (an edge not reasoned up front), just on magnitude instead of position.
Correct understanding: `mid=lo+(hi-lo)/2` keeps every intermediate ≤ hi (≤1e9, fits int). Accumulators that can exceed ~2.1e9 must be `long long` (and so must the function's RETURN type). int ≈ ±2.1e9; long long ≈ ±9.2e18.
Prevention rule: **NEW checklist line — for every `+`, `*`, and running accumulator, ask "what's the max value, and does it fit `int`?" If it can pass ~2e9 → `long long`. Always use `mid=lo+(hi-lo)/2`.**
Re-test problem (similar, unseen): a future search-on-answer (LC1011 Capacity to Ship / LC410 Split Array) — set the value range + a long-long accumulator correctly on the FIRST write, no overflow crash.
Re-attempt on: 2026-06-12 (next search-on-answer problem)
Status: **RE-TESTED FAIL (2026-06-13, drill1 P3 Sqrt(x))** — brute force `if(i*i > x)` with `i` an int: at x≈INT_MAX, `i*i` (≈2.15e9) overflows int BEFORE the comparison → "signed integer overflow." Same root cause (magnitude not reasoned up front), now on a `*` instead of a `+`. Fix = `(long long)i*i`. The magnitude checklist line is NOT yet a reflex. ALSO recurred: nested-function structure bug (defined mySqrt inside main instead of in the Solution class — same as 6/10). Keep #8 OPEN; clears on a first-write-clean overflow-prone problem.

### [#7] Reactive debugging — band-aid `if(s==e)` patches instead of reasoning edges up front
Date: 2026-06-09
Module / Pattern: M6 Binary Search (LC704, LC35) — but cross-cutting
Type: Process / boundary-execution
What I did (the wrong move): submit → see ONE failing test case → bolt on a special-case patch (`if(s==e){...}`) for exactly that case → resubmit. Repeated every problem. Also wrote `return mid;` at the end (luck-dependent; garbage on empty array). Recognition was fine; the loop was "patch the symptom the judge showed me."
Root cause: not trusting the clean template (which handles single/empty/insert-at-end BY DESIGN), and reasoning edges only AFTER the judge fails, never before. The patches are band-aids that make the code fragile.
Correct understanding: the clean templates (exact search; store-candidate lower bound) need ZERO special cases — single element, empty, target<all/>all all fall out of the standard loop. Return the stored `ans`, never a stray `mid`.
Prevention rule: **BEFORE submitting, trace the 4 edges myself** — single element (present/absent), empty, target < all / > all (insert 0 / n), target at first/last index. No `if(s==e)` patches. Trust the template. (In practice/README.md (recognition map) boundary framework + practice/05-binary-search/notes.md.)
Re-test problem: LC34 First/Last + LC875 Koko (tomorrow) — solve with the clean template, edges reasoned up front, ZERO special-case patches, first-submit AC.
Re-attempt on: 2026-06-10 (BS mediums)
Status: **RE-TESTED PARTIAL (2026-06-10)** — LC34 + LC875 AC, no `if(s==e)` band-aids this time (template trusted ✅). BUT Koko still needed a debug cycle on the overflow (a *different* edge — magnitude, see #8), not first-submit-clean. The band-aid reflex looks fixed; the "reason ALL edges up front" discipline isn't fully there. Keep on watchlist; clears on a first-submit-clean medium.

### [#6] Defaulted HASHING problems to "two pointers"; SW over-fired on a transformed array
Date: 2026-06-08
Module / Pattern: M2 Hashing recognition (drill) · M4/M5 discrimination
Problem: `/drill` mixed set — Q3 (unsorted Two Sum), Q6 (longest equal 0/1), Q7 (duplicate within k). Scored 4/7.
Type: Pattern-recognition
What I did (the wrong move): (a) **Q3** unsorted Two Sum → said "two pointers (didn't complete yet)". (b) **Q7** "duplicate value within index distance k" → said "two pointers" again. (c) **Q6** longest equal-0s/1s → got the 0→−1 transform but classified it as **sliding window**.
Root cause: No formal hashing recognition map yet (M2 still L2), so every pair/duplicate/complement problem gets parked under "two pointers." AND sliding window over-fires onto transformed arrays — once 0→−1 introduces negatives, a window can't decide when to shrink, so it MUST be prefix+hash, not SW.
Correct understanding: **Two pointers requires SORTED / monotonic structure.** Unsorted + pair/complement/duplicate → **HASHING** (Q3 = complement map storing value→index; Q7 = last-seen index map, check `i - last ≤ k`). **Negatives or a ±1 transform kill sliding window → prefix sum + hash** (Q6 = transform 0→−1, first-index map, `seen[0]=-1`, longest run with prefix repeat).
Prevention rule: Before saying "two pointers," ask **"is the data sorted/monotonic?"** If no → hashing. Before saying "sliding window," ask **"can values be negative (or did I transform to ±1)?"** If yes → prefix+hash.
Re-test problem (similar, unseen): LC1 Two Sum (after hashing lesson), LC219 Contains Duplicate II, LC525 cold (already owed), + a fresh `/drill` post-hashing.
Re-attempt on: 2026-06-11 (after M2 Hashing formal lesson)
Status: **RE-TESTED MOSTLY-CLEARED (2026-06-10 drill, 6/7)** — Q7 (dup within k) named cold as hashing ✅ (the exact 6/08 miss, now correct). Q1 (unsorted Two Sum): recognition RECOVERED to the hash map, but the FIRST instinct still reached for "sort + two pointers." So: hashing recognition restored; the residual is the unsorted-pair *first-instinct* (logged fresh as #9). Down from 0/2 hashing → effectively 1.5/2.

### [#5] `if(map[key])` truthiness trap + overwriting the first index
Date: 2026-06-07
Module / Pattern: M5 Prefix Sum + Hash
Problem: LC523 Continuous Subarray Sum (test 97 / [23,0,0])
Type: Logic / boundary-value
What I did (the wrong move): (a) checked map presence with `if(seen[rem])` — but a stored index of **0** is falsy, so a remainder first seen at index 0 looked "absent." (b) Used `seen[rem]=i+1` then compared `i-seen[rem]>=2` → off-by-one (required length ≥3, missed length-2 subarrays). (c) Wrote the index EVERY iteration → overwrote the earliest occurrence, shrinking every gap.
Root cause: `operator[]` can't distinguish "absent" from "value is 0/false"; and for LONGEST/length problems you must keep the FIRST index (earliest = largest gap), never overwrite.
Correct understanding: use `.count()`/`.find()` for presence (so index 0 is valid); store the real index; store ONLY on first occurrence (`else` branch); compare `i - seen[rem] >= 2`.
Prevention rule: **`if(map[key])` is poison for indices.** Presence → `.count()`. Write-once → `else`. For "longest" keep the earliest index.
Re-test problem: re-solve LC523 cold in a week; also LC525 (first-index pattern).
Re-attempt on: 2026-06-14
Status: Open (LC523 AC'd 6/7 after coaching, but the bugs were heavy → re-test cold)

### [#4] Treated target SUM `k` as a window LENGTH
Date: 2026-06-05
Module / Pattern: M5 Prefix Sum
Problem: LC560 Subarray Sum Equals K (design phase)
Type: Pattern-recognition / Concept-misunderstanding
What I did (the wrong move): Tried to use a fixed-length window `i .. i+k-1` and `prefix[i+k-1]-prefix[i]`, treating `k` (a target sum) as a length. Yesterday's fixed-window pattern over-fired.
Root cause: Surface-feature anchoring on "k" → "window of size k" from M4, without re-reading what k MEANS in this problem.
Correct understanding: `k` is a TARGET SUM; subarray length is free. Never write `i+k-1` for a sum target.
Prevention rule: Before coding, state in words what each input MEANS. If "k" is a sum, there is no length window.
Re-test problem: a future "subarray sum = k" variant solved without reaching for a length window.
Re-attempt on: next prefix/hash problem (LC930/LC1248 in day-01).
Status: Open

### [#3] Confused "count ALL subarrays" with "find ONE shortest/longest window"
Date: 2026-06-05
Module / Pattern: M5 Prefix Sum
Problem: LC560 Subarray Sum Equals K (design phase)
Type: Concept-misunderstanding
What I did (the wrong move): When a running prefix repeated, wanted to "pick the nearest occurrence (shortest)" — applying min/max-window thinking to a COUNTING problem.
Root cause: Two paradigms blurred: window problems optimize ONE answer; counting problems TALLY every match.
Correct understanding: For "count subarrays with property", every earlier matching prefix is its own valid subarray → `count += seen[key]`, never pick one.
Prevention rule: First classify the GOAL — count / longest / shortest / exists — that decides the whole shape (tally vs max vs min vs boolean).
Re-test problem: LC1248 Count Nice Subarrays (day-01).
Re-attempt on: day-01 practice.
Status: Open

### [#2] Minimum-tracker initialized so it can never update
Date: 2026-06-04
Module / Pattern: M4 Sliding Window (Variable)
Problem: LC 209 Minimum Size Subarray Sum
Type: Edge case / boundary-value
What I did (the wrong move): For a MIN hunt, init `ans = 0` and update with `if(len < ans)`. Since lengths are positive, `len < 0` is never true → `ans` never updated, returned 0 always. After fixing init, forgot the "no valid window → return 0" case and returned the sentinel (105).
Root cause: Logic was correct; the **boundary values** were wrong. A minimum tracker must start at +∞ (INT_MAX), and the "not found" sentinel must be converted back to 0 at return.
Correct understanding: `ans = INT_MAX`; update with `<`; `return ans == INT_MAX ? 0 : ans`.
Prevention rule: When tracking a min, ask two questions BEFORE coding: (1) what start value guarantees the first real candidate wins? (2) what do I return if nothing ever qualified?
Re-test problem (similar, unseen): LC 1004 Max Consecutive Ones III (longest variant — opposite init/return) — get the boundary values right cold.
Re-attempt on: 2026-06-06  (also in REVISION_QUEUE.md)
Status: RE-TESTED (LC1004, 6/4) — min-init not repeated ✅, BUT the boundary family **recurred**
(off-by-one `right-left+1` + step order). Weakness confirmed → kept active on the watchlist.

### [#1] Prefix-sum range formula recalled as shape, not meaning
Date: 2026-06-04
Module / Pattern: M5 Prefix Sum
Problem: Closed-book revision (transfer session)
Type: Concept-misunderstanding
What I did (the wrong move): Wrote `sum(L,R) = prefix[L] - prefix[R]` — wrong order AND wrong subtracted index. Test on [2,4,1,3,5] gave −4 for sum(1,3) (should be 8).
Root cause (the real reason): Recalled the formula by visual *shape* ("prefix minus prefix") instead of its *meaning*: prefix[R] = sum of everything up to R; subtract the part **before L**, which is prefix[L-1].
Correct understanding: `sum(L,R) = prefix[R] - prefix[L-1]`. L=0 → nothing before it → sum(0,R)=prefix[R]. (Or 1-index prefix with prefix[0]=0 to kill the special case.)
Prevention rule: Don't recall a formula by shape — re-derive it from "total up to R minus total before L," then sanity-test on a 3–5 element array before using it.
Re-test problem (similar, unseen): LC 724 Find Pivot Index (pure prefix-sum reasoning, no hashing) — derive the formula cold.
Re-attempt on: 2026-06-05  (also in REVISION_QUEUE.md)
Status: **RE-TESTED PASS (2026-06-05)** — derived `prefix[R]-prefix[L-1]` cold from meaning, handled L=0 (prefix[-1]=0), sanity-tested on [2,4,1,3,5]. Formula recall is now by meaning, not shape. CLEARED.

---

## Recurring-mistake watchlist
> When the same root cause appears 2+ times, it graduates here and becomes a
> standing pre-submit checklist item until it stops recurring.

| Pattern of error | Times seen | Standing rule | Last occurrence |
|---|---|---|---|
| **Logic right, boundary/sentinel/ORDER/INDEX value wrong** (prefix L-1; min-init+return; off-by-one `right-left+1` & `i+1`; `prefix[-1]`/`prefix[n]` OOB; forgot `seen[0]=-1`; `if(map[key])` index-0 trap; first-index overwrite; reverse-loop `i++`; LC567 missing `-'a'` ×2 + left-never-incremented; LC1 lookup-vs-insert ORDER; LC128 fwd-vs-bwd compare + loop `<size()-1` + empty-array; **P15 `append(a,i)` arg-SWAP (should be (count,char)), bucket size `n` vs `n+1`, `=` overwrite vs `.push_back`, loop start `n-1` vs `n`; **P16 minimized WRONG variable `min(ans,k)` (day-count) instead of `min(ans,i)` (capacity); greedy day-count missed the TRAILING partial day (only `d++` on fill ≥cap) → undercounts, e.g. `[3,4,3]`/cap5 gave 2 not 3**; **P18 check-then-advance loop missed the LAST window (`r<n` stops one early) + trailing `comp2[s[r]]++` read off the end when extended; also `k==m` should be `k==26` (compared length vs bucket-count)**) | **15** | Run the pre-code boundary checklist BEFORE coding. #1 leak — STILL the dominant failure mode. NEW sub-face = **check-then-advance loops**: the last item is checked one iteration AFTER its add, so loop must run one step past the final add AND guard that add (`if(r>=n) break;`) — or flip to add-first-then-check. Standing pre-submit Qs: does the loop touch FIRST & LAST element (incl. the final window)? does the trailing increment read past the end on the last pass? empty input? arg order on every library call? RE-RUN after any edit. **Progress sign (P18): he added `if(n<m) return {}` unprompted** — boundary guard firing on its own. **(2026-06-20) P20 LC128: optimal TLE'd (O(n²)) by looping `nums` WITH DUPS, re-walking a run per duplicate start — fix = loop the SET; container leak `unordered_map` used for presence (should be `unordered_set`). P21 LC162 optimal OOB: `while(l<=r)` + referencing BOTH `mid±1` collapses onto the boundary → `[1,2,3]`→`nums[n]`, `[3,2,1]`→`nums[-1]`; fix = `while(l<r)`, compare `nums[mid]` vs `nums[mid+1]` only, `else r=mid`, `return l`. GOOD: he TRACED & properly GUARDED the P21 *brute* boundary himself (review-catch).** | 17 | Run the pre-code boundary checklist BEFORE coding. #1 leak — STILL the dominant failure mode. NEW sub-face = **check-then-advance loops**: the last item is checked one iteration AFTER its add, so loop must run one step past the final add AND guard that add (`if(r>=n) break;`) — or flip to add-first-then-check. Standing pre-submit Qs: does the loop touch FIRST & LAST element (incl. the final window)? does the trailing increment read past the end on the last pass? **does the loop's `<=` vs `<` let lo/hi collapse onto an index where `mid±1` goes OOB?** empty input? arg order on every library call? container = set vs map matches what I store? RE-RUN after any edit. **⭐ 2026-06-25 = the leak getting CAUGHT, not fired blind:** two empty-container edges (Min Stack `!stack.size()`/`minStack[size()-1]` OOB on first push; 132 `!(chk.size()>0)` negation + `.top()`-on-empty) — but **he found BOTH by tracing his own code**, and Min Stack's was caught BEFORE submit → first judge submit clean. The boundary bug is still his first-instinct, but the self-trace now intercepts it. Caveat: LC219 was a **Compile Error then AC** = raw C++ mechanical fluency gap (see CPP_GAPS), a different leak from boundary-logic. | 2026-06-25 (Min Stack + 132 empty-container, both self-caught via trace) |
| **Unsorted pair/duplicate/complement → FIRST instinct = "two pointers" instead of HASHING** | **5 (last fire 6/20) — clean rep landed 6/25** | Before "two pointers," ask "is the data SORTED/monotonic?" If no → hashing. ROOT CAUSE found 6/20: "**Two** Sum" ↔ "**Two** pointers" = word collision; technique is decided by *is it sorted?*, NOT the title. **2026-06-25 WIN: LC219 Contains Dup II solved COLD as an interleaved trap (in the stacks folder) — he rejected the stack via friction-as-signal and routed to hashing himself, no 2ptr detour.** The dup-within-k sub-case stays fixed; need one clean *unsorted pair-SUM* (Two Sum shape) rep to fully clear. Make the gate the FIRST spoken thought. See #9. | 2026-06-20 (recognition recap Q1) |
| **STATEMENT COMPREHENSION — dense notation not decoded** (folds into #10 restate-discipline) | **1 (NEW, surfaced in contest)** | 2026-06-20 contest Q1: couldn't even PARSE the grid statement — flipped `(m-1,n-1)`, didn't decode "right = `(i,j)→(i,j+1)`". FIX = when a statement is `(i,j)`-notation-heavy, **DRAW it**: sketch a tiny 2×3 grid, label coords (row `i` = up/down, col `j` = left/right), walk one move by hand. This is Gate A's dry-run aimed at the STATEMENT, not the algorithm. Drill it via `/forge` comprehension track. | 2026-06-20 (contest Q1 grid) |
| **PREMATURE "DONE" — fixes 1 bug, declares finished / asks "check" before self-tracing the rest** | **6 (4× 6/23, 2× 6/25) — but ANTIDOTE NOW LANDING** | The self-Gate-C leak: after fixing ONE bug he reaches for external validation ("check now") instead of re-running the check on his WHOLE code. STANDING RULE: before "done," **trace your own current code on a hostile input** and read the output. **2026-06-25 = REAL PROGRESS:** the "check now" *reflex* still fired twice (Min Stack, 132), but each time I **refused to check** and handed him the input → **he self-traced and found his OWN boundary bugs both times** (Min Stack empty-edge `!stack.size()`; 132 negation `!(chk.size()>0)`). On Min Stack he caught it BEFORE submitting → **first judge submit clean** (the bug never reached the judge). The antidote (refuse-to-be-the-checker → he traces his own code) is converting the reflex into a catch. Tell HIM: *wanting to ask "is it ok" IS the cue to trace it yourself.* Clears when HE self-traces without me having to refuse first. | 2026-06-25 (Min Stack, 132 — both self-caught) |
| **Sliding window over-fires onto problems with negatives / ±1 transforms** | **1** | Before "sliding window," ask "can values be negative (or did I transform to ±1)?" If yes → prefix+hash. | 2026-06-08 (drill Q6) |
| **Reactive debugging — patch the failing test instead of reasoning edges up front** | **2ptr+BS** | Trace the edges BEFORE submit. No band-aid `if(s==e)` patches — trust the clean template. 6/10: band-aids GONE on LC34/875 ✅, but Koko still hit a debug cycle on overflow (an edge not reasoned up front). | 2026-06-10 (LC875 overflow) |
| **Integer OVERFLOW — type too small for the magnitude of `+`/`*`/accumulator** | **1** | For every add/multiply/accumulator ask "max value? fits int (±2.1e9)? else long long." Always `mid=lo+(hi-lo)/2`. (LC875: `(s+e)` and `int sum` of Σceil both overflowed.) | 2026-06-10 (LC875) |

---

## Pre-submit checklist (grows from the watchlist)
> Run this before declaring any solution "done."
- [ ] Did I test the empty / single-element / all-same / max-size input?
- [ ] Is my stated complexity actually what the code does?
- [ ] Did I name the pattern before coding, or did I jump in blind?
- [ ] **BOUNDARY CHECK (my #1 leak):** init values right? (min→INT_MAX, max→0/−∞) · length
      formula `right-left+1` (the +1!) · "not found" sentinel converted back at return · derive
      formulas by *meaning* not shape.
- [ ] **ORDER CHECK:** for windows, is it strictly include → restore-validity → record? Record
      only when the window is guaranteed valid. For hash maps: look up BEFORE inserting current.
- [ ] **CLASSIFY THE GOAL FIRST:** count / longest / shortest / exists? → tally (`count+=`) /
      max(first-index, `seen[0]=-1`) / min / boolean. This decides the whole shape.
- [ ] **MEANING OF EACH INPUT:** is `k` a sum, a length, a count? (don't write `i+k-1` for a sum.)
- [ ] **Prefix+hash pre-load:** COUNT → `seen[0]=1`. LONGEST(first-index) → `seen[0]=-1`. Negatives mod k → `((x%k)+k)%k`.
- [ ] **OVERFLOW / MAGNITUDE (new, MISTAKE #8):** for every `+`, `*`, and running accumulator, what's the MAX value? Fits `int` (±2.1e9)? If it can pass ~2e9 → `long long` (incl. the function's return type). Binary search: always `mid=lo+(hi-lo)/2`.

