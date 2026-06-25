# 🎛️ COMMAND CENTER — Hema Vardhan (the single front door)

> **Read this first, every session.** It indexes everything — it does NOT duplicate the
> journals (those stay the deep store). One place to answer: *where am I, what's due, what's
> next, where's everything for topic X.* Kira keeps it current; commit it with the rest.

---

## ▶️ TODAY  *(Kira re-renders this block at session start)*
- **Date:** 2026-06-25 (returned from out-day with the full haul; verified on the judge → `/endsession`)
- **Current topic / workspace:** **M7 Stacks & Monotonic → L4 EARNED ✅** — **LC739 Daily Temps + LC503 NGE II both judge-AC** (MCP-confirmed). Plus practice set: **LC155 Min Stack AC · LC456 132 Pattern AC · LC219 Contains Dup II AC · LC33 Search Rotated AC** (first-submit-clean, closed a 2-week BS leak). Next module: Stock Span + LC1004 fresh-submit → then **M8 Queues/Deque** or a cold L5-push drill.
- **⭐ BIG WINS THIS SESSION:** (1) **the premature-"done" antidote LANDED** — his self-trace caught a boundary bug LOCALLY *twice* (Min Stack empty-edge before submit = first judge submit clean; 132 negation). His #1 lifetime leak intercepted by his own hands. (2) **He named his own bottleneck** ("careful reading the question fully") and got the fix that matters: **ritual, not volume** (Gate A every problem; reading IS the first move of solving). (3) **Friction-as-signal recognition** — felt the wrong tool on the interleaved LC219 trap and scrapped the stack for hashing himself.
- **Honest ledger (no inflation):** Min Stack = **first judge submit clean → first-submit-clean BEST moved 0→1** (scaffolded, so an execution win not a recognition win); 132 = WA→AC + **I over-revealed** (re-derive owed 6/28); LC219 = Compile-Error→AC (C++ mechanical gap, not logic). Streak currently **0** (broke on 132's WA) but best is no longer 0.
- **Revision due (next session):** 132 cold re-derive (6/28) · monotonic concept recall (6/28, +3d) · Min Stack aux-stack recall (6/26) · remaining stacks practice **LC1004** (Mistake #2 re-test) + **LC33** (open BS leak) + **LC901 Stock Span** · still-overdue: P19 prefix-MOD +3d · derive-don't-maintain cold recall · BS discard-ability (LC852/540/33) · MISTAKE #9/#10/#11 re-tests · drill tail Q5/Q7/Q8 · **P25 Trapping (LC42, hard) = WEEKEND.**
- **Clean-streak focus:** **best 1 (Min Stack), current 0.** Next clean shot = a SOLO recognition+execution start-to-finish (LC1004 or LC33). Run the 6 gates, self-trace before "done" — the antidote is working, keep it.

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
| **Boundary / index / sentinel** | 2026-06-25 | 0 🟡 | Gate C: 4 boundary edges + ANSWER edge. **6/25 = the leak getting CAUGHT, not fired blind:** two empty-container edges (Min Stack `!stack.size()`→OOB on first push; 132 `!(chk.size()>0)` negation + `.top()`-on-empty) — **he found BOTH by self-tracing**, Min Stack's BEFORE submit (first submit clean). Still first-instinct, but the trace intercepts it now. Cue: "could mid be the answer?" + "what does the stack HOLD — index or value?" + "is the empty-container branch guarded BEFORE I read `.top()`/`.back()`?" |
| **Premature "done" — declared finished before self-running Gate C / trace** | 2026-06-25 | 0 🟡 | **Fired 6× total (4× 6/23, 2× 6/25) — but the ANTIDOTE is LANDING.** 6/25: the "check now" reflex fired twice (Min Stack, 132), but each time I **refused to check → he self-traced and found his own boundary bug.** The refuse-to-be-the-checker move is converting the reflex into a self-catch. Name the tell: *wanting to ask "is it ok" IS the cue to trace it yourself.* Clears when he traces before I have to refuse. |
| **Band-aid / redundant maintained state** (patch over wrong structure) | 2026-06-22 | 0 🔴 | **⭐ Derive-don't-maintain:** P23 hand-synced 6 vars (cut to 2); P24 bolted on an `ans` tracker to patch a bad `mid±1`. Audit before submit: any var that's really `r-l+1`? any two vars that must agree? |
| **Constraint-drop / reading miss** (brute omits a stated rule, or misreads what's asked) | 2026-06-23 | 0 🔴 | **pos-vs-distance RECURRED on LC739 (6/23, same as 6/22):** restate said "find the POSITION of the warmer day"; gentle example `[73,74,71]` hid it (distance==index), hostile `[72,71,76]` exposed it (position 2 ≠ wait 1) → corrected to `j-i`. `answer[i]` is a DISTANCE, not a position. Lesson: pick the example so position≠distance. Restate WHAT is returned, in exact units; Gate A keeps earning its keep. |
| **Reduction trap** (drops a constraint) | 2026-06-20 | 1 🟡 | Gate B: hostile input, run ORIGINAL vs REDUCED |
| **Overflow magnitude** (#8) | 2026-06-20 | 1 🟡 | Gate C: seed/accumulator type, size the number |
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
