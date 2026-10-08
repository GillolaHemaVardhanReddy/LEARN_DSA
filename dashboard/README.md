# 🎛️ DASHBOARD — the front door (Kira reads this FIRST, every session · boss glances)

## ▶️ TODAY  *(Kira re-renders this block every session — keep it to ~10 lines)*
- **🏁 CONTEST FIRST — next = Sat 2026-10-10, 20:00 IST, LC Biweekly** (v2 contest #1, Phase 1 = participation only) · then Sun 10-11 08:00 Weekly. **Two weeklies missed in a row (09-27 didn't know · 10-04 knew and worked instead).** The evening slot is the easy one to protect — alarm the night before, not that morning. Kira names the contest in line 1 of every session; inside 48 h it is the first thing said.
- **📌 ASK BOSS ON THE MACBOOK FIRST (said 2026-10-08):** he did the **LC454 +1d cold re-solve on the night of 10-07 on the MacBook**. That file is not in this repo yet. Next MacBook session, first line: "push the LC454 re-solve file and show me the AC". Once it is seen: mark LC454 +1d ✅ in REVISION_QUEUE (next = +7d 2026-10-14) and credit **10-07 as a kept + build day** (8/66). Until then it is unverified, not counted.
- **⏯️ RESUME — rung 6/6, LC205 Isomorphic Strings.** Hashing ladder is **5/6 CLOSED** (LC49 · LC347 · LC128 · LC560 · **LC454 ✅ 10-07, id 2164619908**). LC205 is the last rung; after it comes the **combined reps round** (all 6 shuffled, no labels, cold, one sitting) and only then does topic 02 open. Open the block with **LC454's +1d cold re-solve, 15 min, blank file** (watch: `ans += count`, never `ans++`), then LC205. **LC205 is also where M#13's 3rd bound is taken.**
- **⚠️ 10-07 HAS NOT STARTED.** The LC454 AC landed 00:08 IST on 10-07, but it was one sitting that began on 10-06 and is credited there. Today still owes its one block.
- **Due Sat 2026-10-10 AM (block 1) — two cold re-solves from blank files, NOT question-cards:** **LC128** (does the outer loop iterate the SET?) · **LC560** (the seeded `{0:1}`, and lookup BEFORE insert — V#2 bait). Slid twice (10-04 zero day, 10-06 the block went to LC454). Nothing dropped.
- **⏱️ THE UNIT IS ONE HOUR BLOCK.** 1 block = 1 problem CLOSED = (1) budget line in digits · (2) code written · (3) **AC on LeetCode** · (4) complexity in one sentence with the line behind each factor. Kira opens every block naming what it will complete and confirms at the end that it closed.
- **📈 PACE — recalibrated 2026-10-06, refined 10-07.** Ceiling = **1 block/weekday + 2/weekend day = 9/week**. The Sunday Weekly takes one weekend slot and the ladder takes ~1 block ⇒ **~7 NEW blocks/week is the planning number**: **interview-ready (topics 01–12, ~150 blocks) ≈ 2027-02-26 · full 33-topic syllabus ≈ 2027-07-26** — inside the 2027-08-07 goal, month-7 gate (2027-04-07) cleared, **zero slack**. (At a clean 8/wk: 2027-02-08 / 2027-06-19. At the **actual 5.6/wk** of the first 10 days: 2027-04-09 / 2027-10-20 ✗.) **8 blocks in 10 days = 5.6/week; the target is 7.** That is 1.25× — the gap is not talent, it is 10-01, 10-02 and 10-04. **Every weekday block is non-negotiable; the weekend's 4 blocks are where the schedule is won.**
- **⚡ PROTOCOL (boss, 2026-09-25):** **no quiz opener, ever.** A session opens with a problem on the screen. Retrieval happens by **re-solving old problems as problems**. Gates A/B/C are Kira's silent checklist. Corollary confirmed 10-07: when he says "I don't know" to a fill-in-the-blank, Kira answers the question plainly instead of re-asking it.
- **🔴 LIVE LEAK — V#2, "traces his intent, not his code" — 4th fire, and PRE-WARNED** (LC454 `ans++` where `ans += count` belonged, one turn after Kira named that exact trap). **Root cause re-read: this is TRANSCRIPTION, not tracing** — the quantity in his head degrades to a flag on the way to the keyboard, because `++` is the default token for "something happened". **New catch, earlier in the pipeline: before writing any `+=`/`++`, say out loud what the right-hand side IS — a count? a 1? a max? — then write it.** Kira's move on a wrong answer stays: **name the line numbers and say nothing else** (it worked on 10-07 — he self-found it and AC'd).
- **🟡 M#13 counter: 2 of 3 banked.** 3rd attempt on 10-07 **not banked**: loop counts right and correctly **added**, but no cost-per-operation factor, no digits, and four letters where the constraints say one `n`. **A bound = how many times the loop runs × what one iteration costs. Name BOTH.** 3rd attempt re-runs on LC205.
- **🔧 C++ track:** 10 min after the block on `resources/cpp-for-cp.md` — **next = #1 number types** (owed since 09-28, still not done). **New #16 (10-07): the container sets the per-operation cost** — `unordered_map` O(1) average (hash → bucket, same step at 10 or 40,000 keys) vs `map` O(log L) (**binary search built into a structure** — the LC704/LC153 machine; it is `log L`, NOT `L log L`, which is the cost of sorting all L items once). **🔴 Re-fire: reading a map with `operator[]` INSERTS** (LC454 lines 78–79 grew the map 40k → 80k) — rule written 09-27, did not transfer; use `.count()`/`.find()`, or just `ans += m[k];` and drop the redundant `if`. Older gaps: #12 looping a hash container · #13 map-vs-set · #14 `vector operator[]` doesn't create slots · #15 one bucket slot can't hold one value. **🔴 Re-test FAILED: `std::sort` returns void** — identical bug on LC49 six days apart; say which list a function is on before writing `x = f(...)`.
- **Days kept:** **7 / 66** · build days **7** · repair token: available · *(09-27 LC49 · 09-28 LC347 · 09-29 bucket · 09-30 LC128 partial · **10-03 three blocks** · 10-05 LC347 re-solve · **10-06 LC454**)* · zero: 10-01, 10-02, 10-04. Day 66 = **2026-12-01**.
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
