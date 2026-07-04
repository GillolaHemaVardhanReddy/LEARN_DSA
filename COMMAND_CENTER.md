# 🎛️ COMMAND CENTER — Hema Vardhan (the single front door)

> **Read this first, every session.** It indexes everything — it does NOT duplicate the
> journals (those stay the deep store). One place to answer: *where am I, what's due, what's
> next, where's everything for topic X.* Kira keeps it current; commit it with the rest.

---

## ▶️ TODAY  *(Kira re-renders this block at session start)*
- **Date:** 2026-07-04 (**M8 mechanics banked — deque muscle building**)
- **Current topic / workspace:** **M8 Queues & Deque → L3 EARNED.** `phase-2/learn/08-Queues-Deque/`. ✅ LC232 (two-stack FIFO → amortized O(1), killed own pour-back) · ✅ LC933 (front-expiry queue O(1)) · ✅ **LC239 Sliding Window Maximum — the monotonic-deque GATE, judge-AC + 20k stress-green.** The unlock: stuck on "drop the front" → fix = **store INDICES not values** (TRANSFERRED from his M7 monotonic stack); expiry `front <= i-k` derived from the index, no counter (his derive-don't-maintain reflex firing right). Explained front=max invariant + O(n) amortized in his words. **Empty-container UB leak caught+logged** (believed `.back()` on empty returns 0 → it's UB; CPP #9 / mistakes M#1). **NEXT: M8 practice set** (`phase-2/practice/08-Queues-Deque/` — LC622/1438/862/1696, staged for when free; ≥2 judge-AC → M8 L4) OR resume the hard gauntlet. **M8 recall due +1d (2026-07-05).**
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
| M8 Queues/Deque | **L3** | [297][312] | LC232 · LC933 · LC239 | recall +1d (7/05); practice set staged | LC622/1438/862/1696 → ≥2 AC = L4 |
| M9+ Recursion → DP → Graphs | L0 | see STRIVER_VIDEOS | — | — | back half (heavier per-pattern) |

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
| **Premature "done" — declared finished before self-running Gate C / trace** | 2026-06-25 | 0 🟡 | **Fired 6× total (4× 6/23, 2× 6/25) — but the ANTIDOTE is LANDING.** 6/25: the "check now" reflex fired twice (Min Stack, 132), but each time I **refused to check → he self-traced and found his own boundary bug.** The refuse-to-be-the-checker move is converting the reflex into a self-catch. Name the tell: *wanting to ask "is it ok" IS the cue to trace it yourself.* Clears when he traces before I have to refuse. |
| **Band-aid / redundant maintained state** (patch over wrong structure) | 2026-06-22 | 0 🔴 | **⭐ Derive-don't-maintain:** P23 hand-synced 6 vars (cut to 2); P24 bolted on an `ans` tracker to patch a bad `mid±1`. Audit before submit: any var that's really `r-l+1`? any two vars that must agree? |
| **Constraint-drop / reading miss** (brute omits a stated rule, or misreads what's asked) | 2026-06-23 | 0 🔴 | **pos-vs-distance RECURRED on LC739 (6/23, same as 6/22):** restate said "find the POSITION of the warmer day"; gentle example `[73,74,71]` hid it (distance==index), hostile `[72,71,76]` exposed it (position 2 ≠ wait 1) → corrected to `j-i`. `answer[i]` is a DISTANCE, not a position. Lesson: pick the example so position≠distance. Restate WHAT is returned, in exact units; Gate A keeps earning its keep. |
| **Reduction trap** (drops a constraint) | 2026-06-20 | 1 🟡 | Gate B: hostile input, run ORIGINAL vs REDUCED |
| **Overflow magnitude** (#8) | 2026-06-29 | 0 🔴 | **FIRED 6/29 (LC402):** `stoi(ans)` on a result up to 1e5 digits → `out_of_range` crash on submit. Fix = never convert; the only question was "empty/all-zeros?" → string-only (`.empty()`). Cue widened: not just `+`/`*` accumulators — **any `stoi`/`stol` on attacker-sized input.** Gate C: seed/accumulator type, size the number |
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
