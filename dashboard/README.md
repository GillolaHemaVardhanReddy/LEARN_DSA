# 🎛️ DASHBOARD — the front door (Kira reads this FIRST, every session · boss glances)

## ▶️ TODAY  *(Kira re-renders this block every session — keep it to ~10 lines)*
- **🏁 CONTEST FIRST — next = Sat 2026-10-10, 20:00 IST, LC Biweekly** (v2 contest #1, Phase 1 = participation only) · then Sun 10-11 08:00 Weekly. **Two weeklies missed in a row (09-27 didn't know · 10-04 knew and worked instead).** The evening slot is the easy one to protect — alarm the night before, not that morning. Kira names the contest in line 1 of every session; inside 48 h it is the first thing said.
- **✅ CLOSED 2026-10-08 (on the MacBook) — the LC454 +1d re-solve is VERIFIED.** The file was written the night of 10-07, submitted from the MacBook on 10-08: **AC id 2166496160**. He wrote `ans += check[-1*(C[i]+D[j])]` **cold, 24 h after V#2's 4th fire on that exact line** ⇒ **V#2 beaten while pre-warned** — bank it, it is the first pre-warned leak he has held. 10-07 credited as a kept + build day; repair token returned.
- **⏯️ RESUME — Sat 10-10 AM = the COMBINED REPS ROUND** (all 6 hashing problems — LC49 · LC347 · LC128 · LC560 · LC454 · LC205 — shuffled, no labels, cold, one sitting) = the hashing checkpoint; topic 02 Two Pointers opens only after it passes. Everything behind him is closed and verified: **10-09 LC205 +1d ✅ clean · LC560 cold re-solve ✅ AC · M#13 3 of 3 BANKED — complexity debt from 08-10 CLEARED.**
- **10-07 = 1 block (LC454 +1d re-solve, verified 10-08) · 10-08 = 2 blocks** (LC205 new + LC128 cold re-solve), done tired after work. Three machines, one repo — **pull before the block, push after it**, every time.
- **Due:** Sat 10-10 AM — combined reps round · Sat 20:00 — **Biweekly** · Mon 10-12 — LC347 +7d · Wed 10-14 — LC454 +7d · Thu 10-15 — LC128 +7d again · LC205 +7d · Fri 10-16 — LC560 +7d.
- **⏱️ THE UNIT IS ONE HOUR BLOCK.** 1 block = 1 problem CLOSED = (1) budget line in digits · (2) code written · (3) **AC on LeetCode** · (4) complexity in one sentence with the line behind each factor. Kira opens every block naming what it will complete and confirms at the end that it closed.
- **📈 PACE — recalibrated 2026-10-06, refined 10-07.** Ceiling = **1 block/weekday + 2/weekend day = 9/week**. The Sunday Weekly takes one weekend slot and the ladder takes ~1 block ⇒ **~7 NEW blocks/week is the planning number**: **interview-ready (topics 01–12, ~150 blocks) ≈ 2027-02-26 · full 33-topic syllabus ≈ 2027-07-26** — inside the 2027-08-07 goal, month-7 gate (2027-04-07) cleared, **zero slack**. (At a clean 8/wk: 2027-02-08 / 2027-06-19. At the **actual 5.6/wk** of the first 10 days: 2027-04-09 / 2027-10-20 ✗.) **8 blocks in 10 days = 5.6/week; the target is 7.** That is 1.25× — the gap is not talent, it is 10-01, 10-02 and 10-04. **Every weekday block is non-negotiable; the weekend's 4 blocks are where the schedule is won.**
- **⚡ PROTOCOL (boss, 2026-09-25):** **no quiz opener, ever.** A session opens with a problem on the screen. Retrieval happens by **re-solving old problems as problems**. Gates A/B/C are Kira's silent checklist. Corollary confirmed 10-07: when he says "I don't know" to a fill-in-the-blank, Kira answers the question plainly instead of re-asking it.
- **🔴 LIVE LEAK — V#2, "traces his intent, not his code" — 4th fire, and PRE-WARNED** (LC454 `ans++` where `ans += count` belonged, one turn after Kira named that exact trap). **Root cause re-read: this is TRANSCRIPTION, not tracing** — the quantity in his head degrades to a flag on the way to the keyboard, because `++` is the default token for "something happened". **New catch, earlier in the pipeline: before writing any `+=`/`++`, say out loud what the right-hand side IS — a count? a 1? a max? — then write it.** Kira's move on a wrong answer stays: **name the line numbers and say nothing else** (it worked on 10-07 — he self-found it and AC'd).
- **🟡 M#13 counter: 2 of 3 banked.** 3rd attempt on 10-07 **not banked**: loop counts right and correctly **added**, but no cost-per-operation factor, no digits, and four letters where the constraints say one `n`. **A bound = how many times the loop runs × what one iteration costs. Name BOTH.** 3rd attempt re-runs on LC205.
- **🔧 C++ track:** 10 min after the block on `resources/cpp-for-cp.md` — **next = #1 number types** (owed since 09-28, still not done). **New #16 (10-07): the container sets the per-operation cost** — `unordered_map` O(1) average (hash → bucket, same step at 10 or 40,000 keys) vs `map` O(log L) (**binary search built into a structure** — the LC704/LC153 machine; it is `log L`, NOT `L log L`, which is the cost of sorting all L items once). **🟡 `operator[]`-read, 3rd fire (LC454 re-solve line 20) — but 10-08 he named the mechanism HIMSELF** ("reading a missing key inserts it with 0") and proposed the `count()` guard before being asked. Mechanism OWNED, reflex not yet. One correction he needed: it costs **memory and time, never correctness** (40k real + 40k garbage = 80k entries; an inserted 0 still reads back as 0). **Re-test = Sat's combined reps round + the LC454 +7d on 10-14; a guard written unprompted closes #16.** Older gaps: #12 looping a hash container · #13 map-vs-set · #14 `vector operator[]` doesn't create slots · #15 one bucket slot can't hold one value. **🔴 Re-test FAILED: `std::sort` returns void** — identical bug on LC49 six days apart; say which list a function is on before writing `x = f(...)`.
- **Days kept:** **10 / 66** · build days **10** · repair token: **available** · **7 days in a row** (10-03 · 10-05 → 10-09 minus none: 10-05 · 10-06 · 10-07 · 10-08 · 10-09) · *(09-27 · 09-28 · 09-29 · 09-30 · 10-03 · 10-05 · 10-06 · 10-07 · 10-08 · **10-09 two re-solves**)* · zero: 10-01, 10-02, 10-04. Day 66 = **2026-12-01**.
- **⚠️ Needs boss's approval:** `git rm -r practice/10-backtracking/learn` — the last 8 legacy v1 files; blocked by the permission gate.
- **Open threads:** `PLAN.md` §4, `SYSTEM.md` and `CLAUDE.md` §3 still describe the dead 3-slot 45-min day with a RECALL slot — **rewrite to the hour-block model** · `dsa-map.html` still v1.

## 🗺️ WHERE THINGS ARE
| I want… | Open |
|---|---|
| the plan (syllabus · the day · calendar · contests) | `dashboard/PLAN.md` |
| how Kira teaches (stuck protocol · mastery · tests · references · struggle · the meta-learning lab) | `dashboard/SYSTEM.md` |
| my levels · habit · leak board | `dashboard/PROGRESS.md` |
| what's due for recall | `dashboard/REVISION_QUEUE.md` |
| my cues / cards | `dashboard/PATTERN_JOURNAL.md` |
| my mistakes + re-tests | `dashboard/MISTAKES.md` |
| contests + ratings | `dashboard/CONTESTS.md` |
| the gates (A/B/C) | `dashboard/CHECKLIST.md` |
| how I learn (Kira's model + experiments) | `dashboard/LEARNING_PROFILE.md` |
| the session history | `dashboard/LOG.md` |
| C++ gaps · Striver videos · books | `dashboard/CPP_GAPS.md` · `dashboard/resources/` |
| a topic's notes / code | `practice/<NN>-<topic>/{notes.md, learn/, reps/, hard/}` · sequence in `practice/README.md` |
| cold tests · contest upsolves · mocks | `tests/{checkpoints, mixed, contests, interviews}` |
| the visual map | `dashboard/dsa-map.html` |

## 🧭 MODES
| Mode | Where | Promotes? |
|---|---|---|
| **LEARN** — first meeting of a pattern (brute → bridge → optimal, question-holes) | `practice/NN/learn/` | → L3 |
| **REPS** — plain solves, hards | `practice/NN/reps/`, `hard/` | → L4 evidence (with the Friday checkpoint) |
| **TEST** — cold, closed-book | `tests/` | **the only L4 → L5 path** |

If Kira is hinting, it's LEARN or REPS. If you're cold and alone, it's TEST.

## ⌨️ COMMANDS
`/today` (the 3-slot day) · `/learn <topic>` · `/checkpoint` (Friday) · `/contest` (log + upsolve) · `/revise` · `/drill` (5 cards) · `/interview` · `/logmistake` · `/dashboard` · `/endsession` · type **`STUCK`** for exactly one hint level.
