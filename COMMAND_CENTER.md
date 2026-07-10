# 🎛️ COMMAND CENTER — Hema Vardhan (the single front door)

> **Read this first, every session.** It indexes everything — it does NOT duplicate the
> journals (those stay the deep store). One place to answer: *where am I, what's due, what's
> next, where's everything for topic X.* Kira keeps it current; commit it with the rest.

---

## ▶️ TODAY  *(Kira re-renders this block at session start)*
- **Date:** 2026-07-10 (**M10 BACKTRACKING L2→L3 🏆 — un-choose DERIVED FROM HIS OWN BUG; boss out ~1h**)
- **🏆 THE REP OF THE WEEK — he taught himself un-choose.** It was withheld for two sessions on purpose. He wrote a flag-based recursion; Kira **refused to check it** and handed him `[1,2,3]`; he traced **his own code**, found the dupes + missing subsets himself. One question later (*"your `pop_back` sits between the two recursive calls of frame i — which element does it pop, and which do those calls decide about?"*) he answered cold: *"pop back decides current and recursion calls decide next."* Then, after a single `STUCK`→L3 nudge, he **stated the invariant unprompted**:
  > *"if we go to next call with a state and come back then we should have same state of sett"*
  **That is backtracking.** Never explained to him. Banked verbatim in `PATTERN_JOURNAL.md`. His recursion: **20,000 random cases GREEN** vs an independent bitmask oracle.
- **🩹 BUT TWO LEAKS FIRED — both logged, both re-tested next session:**
  - **M#8 — the `pick` flag** = his own *derive-don't-maintain* rule in recursion costume (a var that must agree with "did I push?"). Broke 3 ways: pop landed between the two child calls · decision at the parent's call-site but action in the child · forced `pick=1` root ⇒ `{}` could never be born. **Re-test = LC46 Permutations** (zero flags; forces the loop-over-choices shape a boolean can't express).
  - **M#9 — oracle contamination (NEW).** He deleted the bitmask brute and wrote the *recursion* into `subsetsBrute()`, leaving `subsets()` returning `{}`. The stress would compare the thing to itself. Then said "fixed and submitted" without running it — **it dies instantly**: `EDGE FAIL n=1: got 0 subsets`. An oracle must be built a DIFFERENT WAY than the thing it checks.
- **⏯️ RESUME POINT (~1h):** `phase-2/learn/10-Backtracking/01-LC78-Subsets/solution.cpp` is **mis-wired — his correct recursion sits in the brute slot and `subsets()` is empty.**
  1. Move the recursion → `subsets()`. Restore the **bitmask** → `subsetsBrute()` (LC402 primitive).
  2. Answer **bridge Q3 IN WRITING** (his own invariant sentence goes here).
  3. **He runs the 20k stress himself and pastes the output** ← the M#9 re-test + the refuse-to-check gate handed back. Kira does NOT run it.
  4. **Name the LC78 AC** (MCP signed out — the submit is CLAIMED, not verified, so it is NOT counted).
  Then **LC46 Permutations** = the M#8 re-test. Consolidation only after the code: Striver [L10 Subset Sum I] https://youtu.be/rYkfBRtMJr8
- **⚠️ TAP-OUT NOTED, not scolded:** "run urself" + "never got to read theory" arrived *right after* the hard derivation — fatigue, not coasting. He did the expensive cognitive work; the check is the cheap part. First item next session, not a lecture.
- **📌 Theory call (standing exception):** Striver-then-practice holds for **unopened** topics. Mid-derivation, when he's ≥80% of the way to the idea, a video overwrites his own derivation — **consolidation after the code, never instruction before it.** (→ LEARNING_PROFILE)
- **Prior day (2026-07-08) — 🏆 M9 RECURSION L4 EARNED:** reconciled the state-file lag against commits 5d7aee4/6a8e157 — **Q4 LC746 ✅ + Q5 LC198 ✅ were AC'd 7/07**. LC198 was the crown: **self-derived a NON-standard always-take recurrence `f(i)=nums[i]+max(f(i+2),f(i+3))` and PROVED gap≤3 from nums≥0** (500k stress green). Ladder T1+T2 CLEAR: LC1137 · LC231 · LC50 · LC746 · LC198 — 2 mediums + 4 easies on the judge = L4. The M#2/M#7 re-tests rode on 746/198 and held (memo justified by naming the overlap).
- **✅ REVISION BLOCK 3/3 (closed-book):** **M9 recursion+memo** (was 2d overdue) — leap-of-faith + wrote FAST power cold unprompted, memo-two-lines + sentinel-why clean; call-tree magnitude needed the trace nudge → re-flag 7/11. **LC50 fast power** — getpow cold ✅, INT_MIN order ✅; two-call-O(n) wobbled twice before the level table (1→2→4→8, total 2n−1) landed it → produce "doubling cancels halving" FIRST next time. **M8 deque CLEAN SWEEP** → promoted +7d (07-15).
- **⚠️ M8 PRACTICE CLAIM UNVERIFIED — THE open thread:** boss opened saying queues/deque practice was done, but all 4 scaffolds (LC622/1438/862/1696) still have TODO holes + zero commits. Asked twice for LC AC confirmation; session ended without an answer. **M8 HOLDS L3.** First order of business next session: name the ACs (verify) or grind ≥2 of the set → M8 L4. LC862 = the parked Phase-1 hard.
- **Phase-2 wall check:** M8 ✗ · **M9 ✅** · **M10 ◐ (L2, LC78 in flight)** · M11 ✗ (+ 1 disguised drill owed). **M8 settles in parallel** (holds L3 — claimed ACs never named; LC622/1438/862/1696, ≥2 AC → L4).
- **Prior day (2026-07-07):** LC50 fast power derived live (M#6 two-call trap + M#7 memo-overkill climbed, M#4 re-test passed unprompted) → then LC746 + LC198 closed the ladder same day. Fast Power journal entry at L3.
- **⭐ KIRA WORKFLOW RULE (standing, his call-out 7/06):** boss runs code ONLY on LeetCode — diagnose every "wrong ans" from the LC verdict, never from local build mechanics (→ LEARNING_PROFILE).
- **Prior day (2026-07-05):** M9 Recursion opened → L3 · all notes rebuilt to teaching-BITS · memoization taught · LC70 AC.
- **Current topic / workspace:** **M10 Backtracking OPEN at L2 (7/09) — workspace `phase-2/learn/10-Backtracking/`, LC78 first rep in flight. M8 practice owed in parallel (`phase-2/practice/08-Queues-Deque/`).** _Archive of the 7/05 L3 day:_ `phase-2/learn/09-Recursion/`. Coded the full ladder from memory — ✅ print-patterns · ✅ sum 1..N (both shapes) · ✅ factorial · ✅ reverse-array · ✅ palindrome · ✅ **Fibonacci brute + memoized** (02/03/04/05 stress-GREEN first pass). **LC70 Climbing Stairs judge-AC** — recognized AS fib → correct brute → **TLE** → transferred memoization cold → AC (the whole why-DP arc, LIVE). Owns leap-of-faith (`power(x,n)` combine cold), the two shapes, and **memo = recursion + a notepad** (explained fib(5) overlap + O(φⁿ)→O(n) himself). **⭐ BIG META WIN: notes overhaul** — he called the old reference-card notes "garbage"; rewrote ALL topic notes (M1–M9 + new `09b-memoization.md`) to the **teaching-BITS format** (essence→why→hand-run trace→unlock→recipe→traps→cue) via 8 parallel agents, spot-checked + committed `6837d37`. Saved to memory as his **confirmed best learning mode** (notes AND live coaching). **NEXT SESSION: finish M9→L4** — fix `'hi'`→`"hi"` in 01-Print, submit **LC509** (plain fib) + **LC344** (reverse string) + **LC125** (valid palindrome) for judge-ACs. **M9 recall due +1d (2026-07-06).** **In parallel / when free:** M8 practice set (`phase-2/practice/08-Queues-Deque/` LC622/1438/862/1696 — ≥2 AC → M8 L4); then M10 Backtracking (recursion's payoff).
- **⭐ NEW CADENCE (boss's call 2026-07-04, saved to memory `phase-progression-cadence`):** advance to the NEXT topic at **L3** (don't stall for L4); **backfill L4 via practice in parallel**; **hard phase wall** — don't cross Phase 2→3 until ALL of M8/M9/M10/M11 are L4 **and** ≥1 disguised/interleaved drill is cleared.
- **⏸️ HARD GAUNTLET (weekend, deferred behind M8):** P1 LC149 ✅ JUDGE-AC 7/03 (first hard). P2 = LC42 Trapping / LC84 Largest Rectangle — pick up after M8 pattern gate lands. LC149 +1d revision ✅ PASSED 7/04 (float-key: symptom→real killer via his own hostile trace).
- **⏸️ DEFERRED (boss's call 2026-06-29):** LC402 **readability refactor** — replace `stack<int>` (indices + reverse) with a `string` AS the stack (`push_back`/`pop_back`/`back()`, builds in-order so NO reverse). He DERIVED the whole chain himself. Complexity already optimal (O(n)/O(n)); this is readability + constant-factor only. Predict-before-run owed: what does `pop_back` on empty string do vs `stack.pop()`? Re-stress + re-submit after.
- **⭐ BIG WINS:** (1) **He DERIVED the greedy optimal BY HAND** off a seeded trace (`1432219,k=3`→`[1,2,1,9]`→"1219") and saw *the result-list he invented IS the monotonic stack* — concept built before I named it. (2) **Self-caught his #1 kryptonite** — sentinel `!= 0` (int NUL) vs `!= '0'` (char) in the brute, found by his OWN trace of `"10200",k=1`. (3) **New primitive banked:** bitmask subset enumeration (`mask&(1<<i)` + `__builtin_popcount`) for the brute oracle.
- **Honest ledger (no inflation):** LC402 **✅ JUDGE-AC 2026-06-29** (boss reports accepted; the `num`→`nums` compile fix landed himself). NOT first-submit-clean — multiple RE/WA on the grind (brute `1<<n` overflow + `stoi` RE), all now understood. Optimal grind beat 4 real issues (i++ vs pop · `<`→`>` direction · leftover-k slicing the original instead of the stack → `"10",k=2`="1" bug · **MAGNITUDE leak FIRED: `stoi` on a 1e5-digit string → crash**, fixed string-only). **Teach-it-back cue captured** (greedy build trigger, his words) + **readability refactor DEFERRED** (string-as-stack, see above).
- **Revision CLEARED 6/30 (3/3 PASS):** ~~132 cold re-derive~~ ✅ (debt cleared, his cue banked) · ~~monotonic concept recall~~ ✅ ("stack holds INDICES") · ~~Min Stack aux-stack~~ ✅ ("remember don't recompute"). All rescheduled +7d ≈ 2026-07-07. **Still owed:** remaining stacks practice **LC1004** (Mistake #2 re-test) + **LC901 Stock Span** · P19 prefix-MOD · derive-don't-maintain cold recall · BS discard-ability (LC852/540) · MISTAKE #9/#10/#11 re-tests · **hards block tomorrow (LC84 · LC42 Trapping · LC410).**
- **Clean-streak focus:** **best 1 (LC33/Min Stack), current 1.** LC402 will NOT be clean (multiple RE/WA submits already) — fine, it's a learning grind on a *new* pattern. Next clean shot = a fresh SOLO start-to-finish once LC402 closes. Run the 6 gates, self-trace before "done" — the antidote is working.

### 📋 BOSS'S FORWARD PLAN (restructured 2026-06-30) — Phase-1 close-out + Phase-2 open
> **All Phase-1 work now lives in one self-contained folder: `phase-1/` (`notes/ learn/ practice/ drills/ test/ syllabus.md mistakes.md`). Phase 2 = copy that skeleton.**
0. ✅ **DONE 6/30: (a) consolidated ALL Phase-1 hards into ONE home** — `phase-1/drills/03-hard-gauntlet/` (8 active + LC862 parked); swept every folder, deduped triplicated LC42/LC410, folded in the 5 missed (LC149/LC76/LC992/LC4/LC719); removed scattered `05-hard-*` + drill1 p25–30 (empty dups), drill1 → 24Q. **(b) Physically moved all Phase-1 assets into `phase-1/`.**
1. **TOMORROW: the HARD BLOCK** — grind `phase-1/drills/03-hard-gauntlet/` (start LC84 → LC42 → LC410 → the rest). All scaffolded brute→bridge→optimal→stress, ready to open.
2. **Deep revision pass** — ✅ 132 / monotonic / Min Stack cleared 6/30; still owed Stock Span, #9/#10/#11/#12 re-tests (note: #11 LC992 + LC719 now live in the gauntlet).
3. **NEW practice drill — 20 Q, Phase-1 UNSEEN, help-allowed** (FAANG prep, PRACTICE mode). → `phase-1/drills/04-phase1-unseen/`. Runs ALONGSIDE Phase 2.
4. **TEST drill — 20 Q, Phase-1 COLD SOLO** (the only L4→L5 path, TEST mode). → `phase-1/test/phase1-gauntlet/`. Built after #3, run ALONGSIDE Phase 2.
5. **Phase 2 opens: M8 Queues/Deque (fast, monotonic-stack twin, clears parked LC862) → M9 Recursion (the keystone, deep).** Create `phase-2/` by cloning `phase-1/`'s skeleton.

---

## 🗺️ TOPIC HUB  *(status only — links route to the deep files)*
Level scale: L0–L6 (see `PROGRESS.md` §6). 🎥 = Striver video id (`STRIVER_VIDEOS.md`).

| Pattern | Lvl | 🎥 | Solved | Open leaks / re-tests | Next action |
|---|---|---|---|---|---|
| M1 Complexity | L3* | — | — | verify recall | fold into drills |
| M2 Hashing | **L4** | [013] | E:4 M:4 | #9 unsorted→hashing gate (3× fail) | cold drill → L5 |
| M3 Two Pointers | **L4** | [049+] | E:4 M:2 | Dutch-flag re-code (LC75); over-fire gate | weekend LC75 + L5 drill |
| M4 Sliding Window | **L5** ✅ | — | M:3+ | (clean) | keep warm in drills |
| M5 Prefix Sum | **L4** | — | approaching L5 (pulled back, needs track record) | P19 re-derive 6/21 | L5 drill after streak |
| M6 Binary Search | **L4** | [045/046/047/056] | E:2 M:3 | #8 overflow magnitude; **LC33 ✅ (6/25, first-submit-clean)**; LC74 unsolved | LC74 2D + LC852/LC540 ladder → L5 |
| M7 Stacks + Monotonic | **L4** ✅ | [297][298][300][301][303] | LC20 · LC739 · LC503 · LC155 · LC456 · LC219 | **L4 EARNED** (DT+NGE II judge-AC); 132 over-revealed→re-derive 6/28; Stock Span owed for depth | LC1004/LC33/Stock Span → then M8 |
| M8 Queues/Deque | **L3** | [297][312] | LC232 · LC933 · LC239 | deque recall ✅ CLEAN 7/08 → +7d (07-15); **practice claim UNVERIFIED — scaffolds still hole-y, no ACs named** | settle it: verify claimed ACs or grind ≥2 of LC622/1438/862/1696 → L4 |
| M9 Recursion | **L4** ✅ | [008-012] | ladder · LC70 · **LC1137 · LC231 · LC50 (M) · LC746 · LC198 (M) — ladder T1+T2 ALL ✅ (L4 banked 7/08)** | +1d recall ✅ PASSED 7/08; flag: call-tree MAGNITUDE cold (→ 7/11); M#2/M#6/M#7 re-tests held on 746/198 | keep warm in drills; T3 (LC78/46) folds into M10 Backtracking |
| M10 Backtracking | **L3** | [L10] | 0/0 (LC78 AC claimed, unverified) | **un-choose DERIVED from his own bug 7/10** ✅ · M#8 `pick`-flag (→ LC46 re-test) · M#9 oracle contamination (→ rewire LC78 + he runs the stress) | rewire LC78 file → stress green → name the AC → **LC46 Permutations**; ladder LC39/90/79/131 (+LC51 stretch) |
| M11+ LinkedLists → DP → Graphs | L0 | see STRIVER_VIDEOS | — | — | back half (heavier per-pattern) |

> Only **M4 Sliding Window** is a confirmed L5. M5 was claimed L5 then honestly pulled back to
> L4 (one clean call ≠ track record). Don't inflate.

---

## 🧭 MODE LEGEND — which mode am I in? (paths are inside the current phase folder, e.g. `phase-1/`)
| Mode | Folder | Purpose | Promotes level? | How it runs |
|---|---|---|---|---|
| **LEARN** | `phase-N/learn/<NN>-Topic/` | first meeting of a pattern | builds toward L3 | full Socratic, brute→bridge→optimal |
| **PRACTICE** | `phase-N/practice/<NN>-Topic/` · `phase-N/drills/<NN>-…/` | reps, calibration, disguised recognition | **no** (it's training) | ≤1 hint then stop; no answer key on drills |
| **TEST** | `phase-N/test/` (`cold-recognition/`, `/drill`, `/interview`) | cold, closed-book | **yes — the only L4→L5 path** | no help; help costs signal |

> **Each phase = one self-contained folder** (`phase-1/` = M1–M7): `notes/ learn/ practice/ drills/
> test/ syllabus.md mistakes.md`. Live cross-phase tracking stays at root (this file, `PROGRESS.md`,
> `REVISION_QUEUE.md`, `PATTERN_JOURNAL.md`, `LEARNING_PROFILE.md`, `CLAUDE.md`, `CURRICULUM.md`).
> **Phase 2 = copy `phase-1/`'s skeleton.**

Rule of thumb: if Kira is teaching/hinting, it's LEARN or PRACTICE. If you're cold and alone, it's TEST.

---

## 🩹 LEAK SCOREBOARD — boss's execution bottleneck (the #1 thing we're fixing)
> **⭐ BOSS'S 6 GATES now standing (`CLAUDE.md` §5.1)** — 3 defense (kryptonite pre-load · refuse-to-check · he builds the hostile input) + 3 offense (teach-it-back · predict-before-reveal · calibration check). Run every problem; adopted 2026-06-24 at his request.
> Recognition is strong; **execution** is the leak. Every bug updates this; every clean solve grows the streak.
> 🔴 = fired recently · 🟡 = building clean days · 🟢 = reflex forming. Update dates whenever a leak fires.

| Leak | Last seen | Days clean | Catch it with |
|---|---|---|---|
| **Boundary / index / sentinel** | 2026-06-29 | 0 🟡 | Gate C: 4 boundary edges + ANSWER edge. **6/29 = CAUGHT again by his own trace** — brute sentinel `check[m] != 0` (int NUL) vs `!= '0'` (char), found tracing `"10200",k=1`. **6/25 = the leak getting CAUGHT, not fired blind:** two empty-container edges (Min Stack `!stack.size()`→OOB on first push; 132 `!(chk.size()>0)` negation + `.top()`-on-empty) — **he found BOTH by self-tracing**, Min Stack's BEFORE submit (first submit clean). Still first-instinct, but the trace intercepts it now. Cue: "could mid be the answer?" + "what does the stack HOLD — index or value?" + "is the empty-container branch guarded BEFORE I read `.top()`/`.back()`?" |
| **Premature "done" — declared finished before self-running Gate C / trace** | **2026-07-10** | 0 🔴 | **FIRED 7/10 (7th):** said *"i fixed and its submitted"* while `subsets()` still returned `{}` — the harness dies on line one (`EDGE FAIL n=1`). Then *"ok run urself"* = handed the check back. **New tell: "submitted" ≠ "verified."** Context matters — it landed right after a hard self-derivation, so this reads as fatigue, not dodging; the fix is to make the stress-run the FIRST move of the next session, not a lecture. **⭐ NEW SIBLING LEAK — M#9 oracle contamination:** he wrote the optimal's own algorithm into the brute slot. A stress test where brute and optimal share machinery proves nothing; two independent derivations agreeing is evidence, one agreeing with itself is a tautology. Prior: **Fired 6× (4× 6/23, 2× 6/25) — the ANTIDOTE was LANDING.** 6/25: the "check now" reflex fired twice (Min Stack, 132), but each time I **refused to check → he self-traced and found his own boundary bug.** The refuse-to-be-the-checker move is converting the reflex into a self-catch. Name the tell: *wanting to ask "is it ok" IS the cue to trace it yourself.* Clears when he traces before I have to refuse. |
| **Band-aid / redundant maintained state** (patch over wrong structure) | **2026-07-10** | 0 🔴 | **FIRED 7/10 in a NEW COSTUME (M#8, LC78): a recursion PARAMETER.** The `pick` flag is a var that must agree with "did I push?" — `if(pick) push` … `if(pick) pop`. Desynced immediately (pop between the two child calls), and the forced `pick=1` root made `{}` unborn. **Cue widened: the two-things-that-must-agree check now applies to function PARAMETERS, not just loop variables.** Delete the flag → frame owns its choice → `push/recurse/pop/recurse` in a straight line, uniform frames, root is just `solve(0)`. Prior: **⭐ Derive-don't-maintain:** P23 hand-synced 6 vars (cut to 2); P24 bolted on an `ans` tracker to patch a bad `mid±1`. Audit before submit: any var that's really `r-l+1`? any two vars — or params — that must agree? |
| **Constraint-drop / reading miss** (brute omits a stated rule, or misreads what's asked) | 2026-06-23 | 0 🔴 | **pos-vs-distance RECURRED on LC739 (6/23, same as 6/22):** restate said "find the POSITION of the warmer day"; gentle example `[73,74,71]` hid it (distance==index), hostile `[72,71,76]` exposed it (position 2 ≠ wait 1) → corrected to `j-i`. `answer[i]` is a DISTANCE, not a position. Lesson: pick the example so position≠distance. Restate WHAT is returned, in exact units; Gate A keeps earning its keep. |
| **Reduction trap** (drops a constraint) | 2026-06-20 | 1 🟡 | Gate B: hostile input, run ORIGINAL vs REDUCED |
| **Overflow magnitude** (#8) | **2026-07-06** | 0 🔴 | **FIRED 7/06 (LC50, M#4): `abs(n)` on an int at n=INT_MIN** — the sign flip ran in the NARROW type before the long long ever saw the value. Cue widened again: not just accumulators and `stoi` — **NEGATION is arithmetic too; widen BEFORE any arithmetic on a bound-sized input.** He wrote the widen-then-negate fix himself once traced. Prior: 6/29 (LC402) `stoi` on 1e5-digit string. Gate C: seed/accumulator type, size the number, and now: any sign flip near INT_MIN? |
| **Gate slip** (sorted?→2ptr vs hash; set vs map) | 2026-06-21 | 0 🔴 | Gate C: container + sorted check |

**First-submit-clean streak:** `1` 🆕  ·  **best:** `1`  (**LC33 Search Rotated 6/25 = first submit clean, recognized cold** — closed a 2-week-open BS leak; approach-coached (which-half-sorted) but execution clean. Earlier Min Stack also first-submit-clean (scaffolded) then broke on 132 WA / Contains-Dup-II CE; LC33 restarts the streak at 1. Next: keep it alive with another SOLO clean.)
*(A clean solve = AC on judge with ZERO boundary band-aids and no overflow/reduction/gate slip.)*
*Positive signals 2026-06-22: **the ⭐ DERIVE-DON'T-MAINTAIN principle TRANSFERRED across patterns in one session** — taught on a window (P23), he applied it to BINARY SEARCH an hour later (P24: killed his own `ans` band-aid → clean `while(l<r)` converge). **TRACE-FIRST caught BOTH misses** (P23 reading, P24 boundary) — his #1 modality confirmed again. **First local stress-test ever run** (100k cases, oracle silent) — toolchain unblocked, this is now standing. **He CALLED his own traps** twice (P23 "this is over-engineered", P24 "this is too easy = I'm dodging the rep"). Residual leak = FIRST-INSTINCT execution (defaults to exact-target BS template + redundant maintained state), then fixes on review — now NAMED + SCHEDULED.*

---

## 📚 WHERE EVERYTHING LIVES
**Root = live cross-phase OS:**
- **Rules / how Kira works:** `CLAUDE.md` · **Pre-flight ritual + stress-test template:** `CHECKLIST.md`
- **Levels & session log:** `PROGRESS.md` · **Spaced repetition:** `REVISION_QUEUE.md`
- **Recognition cues:** `PATTERN_JOURNAL.md` · **How I learn (Kira's model):** `LEARNING_PROFILE.md`
- **C++ fluency gaps:** `CPP_GAPS.md` · **24-module master map:** `CURRICULUM.md` · **Videos:** `STRIVER_VIDEOS.md`

**Each phase = one self-contained folder** (`phase-1/` = M1–M7; Phase 2 copies the skeleton):
- **Syllabus covered:** `phase-N/syllabus.md` · **Mistakes + root causes:** `phase-N/mistakes.md`
- **Study notes:** `phase-N/notes/` · **Code:** `phase-N/learn/` (LEARN) · `phase-N/practice/` + `phase-N/drills/` (PRACTICE) · `phase-N/test/` (TEST)
- **Hard gauntlet (all Phase-1 hards):** `phase-1/drills/03-hard-gauntlet/`
