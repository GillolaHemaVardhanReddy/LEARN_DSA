# 🎛️ COMMAND CENTER — Hema Vardhan (the single front door)

> **Read this first, every session.** It indexes everything — it does NOT duplicate the
> journals (those stay the deep store). One place to answer: *where am I, what's due, what's
> next, where's everything for topic X.* Kira keeps it current; commit it with the rest.

---

## ▶️ TODAY  *(Kira re-renders this block at session start)*
- **Date:** 2026-06-30 (**CLEAN REVISION session** — boss's call: revise today, stack ALL the hards tomorrow as one block)
- **Current topic / workspace:** **REVISION complete — 3/3 PASS closed-book** (monotonic concept recall · 132 cold re-derive · Min Stack aux-stack). **TOMORROW = hard-problem block:** P5 LC84 Largest Rectangle (the canonical hard, completes Stacks) + owed hards (LC42 Trapping, LC410 Split Array). drill 02 P1–P3 reported done (**P3 Asteroid Collision = working-tree edits, judge-AC unconfirmed**). LC402 ✅ JUDGE-AC 6/29 = **greedy monotonic-INCREASING build** ("pop bigger predecessors while k>0 · trim leftover k from END · strip leading zeros · empty→`0`").
- **⏸️ DEFERRED (boss's call 2026-06-29):** LC402 **readability refactor** — replace `stack<int>` (indices + reverse) with a `string` AS the stack (`push_back`/`pop_back`/`back()`, builds in-order so NO reverse). He DERIVED the whole chain himself. Complexity already optimal (O(n)/O(n)); this is readability + constant-factor only. Predict-before-run owed: what does `pop_back` on empty string do vs `stack.pop()`? Re-stress + re-submit after.
- **⭐ BIG WINS:** (1) **He DERIVED the greedy optimal BY HAND** off a seeded trace (`1432219,k=3`→`[1,2,1,9]`→"1219") and saw *the result-list he invented IS the monotonic stack* — concept built before I named it. (2) **Self-caught his #1 kryptonite** — sentinel `!= 0` (int NUL) vs `!= '0'` (char) in the brute, found by his OWN trace of `"10200",k=1`. (3) **New primitive banked:** bitmask subset enumeration (`mask&(1<<i)` + `__builtin_popcount`) for the brute oracle.
- **Honest ledger (no inflation):** LC402 **✅ JUDGE-AC 2026-06-29** (boss reports accepted; the `num`→`nums` compile fix landed himself). NOT first-submit-clean — multiple RE/WA on the grind (brute `1<<n` overflow + `stoi` RE), all now understood. Optimal grind beat 4 real issues (i++ vs pop · `<`→`>` direction · leftover-k slicing the original instead of the stack → `"10",k=2`="1" bug · **MAGNITUDE leak FIRED: `stoi` on a 1e5-digit string → crash**, fixed string-only). **Teach-it-back cue captured** (greedy build trigger, his words) + **readability refactor DEFERRED** (string-as-stack, see above).
- **Revision CLEARED 6/30 (3/3 PASS):** ~~132 cold re-derive~~ ✅ (debt cleared, his cue banked) · ~~monotonic concept recall~~ ✅ ("stack holds INDICES") · ~~Min Stack aux-stack~~ ✅ ("remember don't recompute"). All rescheduled +7d ≈ 2026-07-07. **Still owed:** remaining stacks practice **LC1004** (Mistake #2 re-test) + **LC901 Stock Span** · P19 prefix-MOD · derive-don't-maintain cold recall · BS discard-ability (LC852/540) · MISTAKE #9/#10/#11 re-tests · **hards block tomorrow (LC84 · LC42 Trapping · LC410).**
- **Clean-streak focus:** **best 1 (LC33/Min Stack), current 1.** LC402 will NOT be clean (multiple RE/WA submits already) — fine, it's a learning grind on a *new* pattern. Next clean shot = a fresh SOLO start-to-finish once LC402 closes. Run the 6 gates, self-trace before "done" — the antidote is working.

### 📋 BOSS'S FORWARD PLAN (set 2026-06-29) — Phase-1 close-out sequence
1. **Finish P5 LC84** (current hard) → completes Stacks, the last new pattern in Phase 1.
2. **Deep revision pass** — recognition + all owed MISTAKE re-tests (overdue 6/28 monotonic recall, 132 re-derive, Stock Span, #9/#10/#11/#12 re-tests, etc.).
3. **Clear ALL owed hards** (LC42 Trapping = weekend · LC410 Split Array · **note: LC862 genuinely needs M8 deques → it rides to Phase 2, can't precede it**).
4. **NEW PRACTICE drill ("drill 03"): 30 Q end-to-end, Prefix Sum → Monotonic Stacks**, interleaved/disguised. Runs ALONGSIDE M8+ (Phase 2) learning — practice-while-we-advance.
5. **TEST drill for Phase 1** (cold, closed-book, the only L4→L5 path) — built after the practice drill, run ALONGSIDE Phase 2.

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
| M8 Queues/Deque | L0 | — | — | — | next up (or cold L5-push drill first) |
| M9+ Recursion → DP → Graphs | L0 | see STRIVER_VIDEOS | — | — | back half (heavier per-pattern) |

> Only **M4 Sliding Window** is a confirmed L5. M5 was claimed L5 then honestly pulled back to
> L4 (one clean call ≠ track record). Don't inflate.

---

## 🧭 MODE LEGEND — which mode am I in? (this is why folders are split)
| Mode | Folder | Purpose | Promotes level? | How it runs |
|---|---|---|---|---|
| **LEARN** | `learn/<NN>-Topic/` | first meeting of a pattern | builds toward L3 | full Socratic, brute→bridge→optimal |
| **PRACTICE** | `practice/` (`practice/<NN>-Topic/`, `practice/drills/drillN/`, `practice/day-NN/`) | reps, calibration, disguised recognition | **no** (it's training) | ≤1 hint then stop; no answer key on drills |
| **TEST** | `test/` (`test/cold-recognition/`, `/drill`, `/interview`) | cold, closed-book | **yes — the only L4→L5 path** | no help; help costs signal |

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
- **Rules / how Kira works:** `CLAUDE.md` · **Pre-flight ritual + stress-test template:** `CHECKLIST.md`
- **Levels & session log:** `PROGRESS.md` · **Spaced repetition:** `REVISION_QUEUE.md`
- **Recognition cues:** `PATTERN_JOURNAL.md` · **Mistakes + root causes:** `MISTAKE_JOURNAL.md`
- **How I learn (Kira's model):** `LEARNING_PROFILE.md` · **C++ fluency gaps:** `CPP_GAPS.md`
- **The map:** `CURRICULUM.md` · **Videos:** `STRIVER_VIDEOS.md` · **Study notes:** `Notes/`
- **Code:** `learn/` (LEARN) · `practice/` (PRACTICE) · `test/` (TEST)
