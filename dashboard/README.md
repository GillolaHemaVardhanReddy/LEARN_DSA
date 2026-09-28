# 🎛️ DASHBOARD — the front door (Kira reads this FIRST, every session · boss glances)

## ▶️ TODAY  *(Kira re-renders this block every session — keep it to ~10 lines)*
- **Date:** **v2 day 1 = Sun 2026-09-27** (setup 09-25; boss travelling 09-25/26, planned, not missed days). 09-08 never happened (17 zero days, closed out, not carried as debt). Day 66 = **2026-12-01**.
- **⚡ PROTOCOL CHANGE (boss, 2026-09-25):** *"stop asking test questions — I lost interest."* → **no quiz opener, ever.** A session opens with a problem on the screen. No RECALL slot, no gauntlet, no "what do you remember". Retrieval happens by **re-solving old problems as problems**, never by being asked about them. Gates A/B/C = Kira's silent checklist; at most **one** question per session, and only when his code is about to be wrong.
- **⏯️ RESUME:** **LC 347 follow-up — O(n) bucket version** (same problem, no sort). Start hint already given: *a count can never exceed n — so what can you use as an INDEX?* Then rung 3 **LC128 Longest Consecutive**. **First 3 min = re-derive LC347 cold (+1d card, due 09-29): count → vector of pairs → sort by `.second` desc → take k.**
- **🔧 C++ track (boss, 2026-09-28):** after the block closes, 10 min on the next item of `resources/cpp-for-cp.md` — **next = #1 number types**. Keep it SHORT and plain (boss: "text dumped is not understandable").
- **📚 STRUCTURE (boss, 2026-09-25):** *"go slow, one topic at a time, clean, and after each topic a combined reps"* → a topic is worked start-to-finish as a **named ladder** (`practice/NN-topic/<TOPIC>-SET.md`), one problem per session, and it CLOSES with a **combined reps round** (its own problems, shuffled, no labels, cold, one sitting). The next topic does not open until that round is clean. No calendar pressure — the ladder is the schedule. **Now on: topic 01 Hashing — rungs 1–2 of 6 CLOSED (LC49 09-27 · LC347 09-28), O(n) follow-up of 347 then rung 3 LC128.** The ladder + the teaching plan + the Parked questions live in `practice/01-hashing/HASHING-SET.md` — **Kira teaches from that file, never improvises a detour.**
- **⏱️ THE UNIT IS ONE HOUR BLOCK (boss, 2026-09-26).** Not a 45-min slot, not a "day". **1 block = 1 problem CLOSED.** Closed = (1) budget line said · (2) code written · (3) **AC on LeetCode** · (4) complexity in one sentence with the line behind each factor. Kira opens every block by naming what it will complete, and ends it by confirming it closed.
- **Stacking blocks:** block 1 = next rung on the ladder · block 2 = the rung after it · block 3 = the rung after that, **or** re-solve block 1's problem cold (boss picks). Never more than 3 blocks. A block that doesn't close carries to the next block — the ladder is the schedule, the clock is not.
- **📈 PACE (boss, 2026-09-28):** **2 blocks every weekday + 4 blocks each Sat/Sun = 18 blocks/week.** ~300 blocks for the 33-topic syllabus → **~late Jan 2027 at full pace · ~Mar 2027 realistic** (≈ 80 % of blocks kept, DP/graphs slower). Floor stays one block; the 18 is the target, not the minimum.
- **Floor:** one block, one problem. Zero is the only failure.
- **Days kept:** **2 / 66** · build days **2** · repair token: available · *(day 1 = 2026-09-27 · 09-28 kept: LC49 card ✅ + LC347 AC)*
- **⚠️ Needs boss's approval:** `git rm -r practice/10-backtracking/learn` — the last 8 legacy v1 files; the delete was blocked by the permission gate. Everything else in `practice/` is clean (174 files → 24).
- **Contest:** 🏁 **NEXT = Sun 2026-10-04 08:00 IST, LC Weekly** (v2 contest #1, Phase 1 = participation only) · then Sat 10-10 20:00 Biweekly · Sun 10-11 08:00 Weekly · full 8-week table in `CONTESTS.md` 📅 · the 09-27 Weekly was missed (didn't know) → logged, no debt · **Kira opens every session with the next contest; within 48 h it's the first line.**
- **Open threads:** `PLAN.md` §4 and `SYSTEM.md` still describe the 3-slot 45-min day and the RECALL slot — **both are dead**; rewrite them to the hour-block model next session · `CLAUDE.md` §3 same · `dsa-map.html` still v1

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
