# 🎛️ DASHBOARD — the front door (Kira reads this FIRST, every session · boss glances)

## ▶️ TODAY  *(Kira re-renders this block every session — keep it to ~10 lines)*
- **🟡 TUE 10-13 — THE RE-TEST, PART 1: tapped out clean on S1, NOT PASSED yet.** S1 = LC560 in a sensor costume (0/1 array, count subarrays with exactly k ones). His: budget line in digits ✅ (9·10⁸ > 10⁸) · gate Q2/Q3/Q4 cold — **Q3 "how many times" FIRST TRY (V#4 reversed)** · Q1 after one prompt · **broke his own sliding window by trace** (`[0,0,0]` k=0 → 5, not 6). Not his: recognition (Kira revealed LC560) · the `P[j]−k` lookup didn't land — he asked to stop "with a free mind". He *did* say the idea back right once ("find 1 from 3−2, chopping happened 2 times ⇒ 2 ans at final j").
- **🔴 Logged against Kira (2):** (1) **the gate was never handed over** — Kira always asked the questions, so "run your gate unprompted" tested something he was never given. Now handed: **0 budget · 1 contiguous? · 2 sorted / may I sort? · 3 order / membership / HOW MANY TIMES? · 4 count / best / list-all?** (2) **costume words broke comprehension** — "stretches", "clicker", "sensor" cost ~6 turns. **Disguise hides the pattern NAME, never the vocabulary: statements in plain arrays / subarrays / sums.**
- **⏯️ RESUME — Wed 10-14: RE-TEST PART 2.** (a) **S1 cold re-derive, plain words** = LC930 https://leetcode.com/problems/binary-subarrays-with-sum/ — gate out loud → brute → `P[i−1] = P[j] − k` → map of prefix COUNTS → **one loop, look up BEFORE insert, `m[0]=1`** → AC. (b) Then S2 + S3 (plain-vocabulary disguised) + the 2 old-topic cards = **Thu 10-15**. Pass both ⇒ topic 02 opens.
- **📌 THE WEEK (everything slid one day for the re-test, nothing dropped):** **Wed 10-14** re-test part 2a (LC930) · **Thu 10-15** S2 + S3 + 2 old cards · **Fri 10-16** LC454 +7d + Biweekly 193 Q1 clean brute · **Sat 10-17** LC128 +7d + LC205 +7d + LC187 +7d · **Sun 10-18** LC Weekly 08:00 + BusBooking blank-file re-solve PM · **Mon 10-19** LC560 +7d + LC347 +7d. Rating for 10-10/10-11 **still not fetched — never guess.**
- **🔴 Live leaks:** **V#4** "membership" swallows "how many times" — question 3 has **three branches** now, run out loud on every problem in every topic · **M#12** tool-carryover, with its **ZEROTH gate question: read the constraints and say the budget OUT LOUD in digits** before naming any tool · **Q2-template** (two-loop prefix, insert line never written, 3rd occurrence) · **M#13** never accept a bare complexity bound — *which line makes that factor?*
- **🟡 Still open from 10-10:** Q0 #3 unanswered (where a hash table runs in the world — DB index, symbol table, browser cache, login lookup) · **CPP_GAPS #18** a string key costs its LENGTH (re-test = the 10-17 LC187 closing sentence) · **`std::sort` returns void** — re-test still FAILED.
- **⏱️ THE UNIT IS ONE HOUR BLOCK.** 1 block = 1 problem CLOSED = (1) budget line in digits · (2) code written · (3) **AC on LeetCode** · (4) complexity in one sentence with the line behind each factor. Kira opens every block naming what it will close, and confirms at the end that it closed.
- **📈 PACE.** ~**7 new blocks/week** is the planning number ⇒ interview-ready (topics 01–12) ≈ **2027-02-26** · full 33-topic syllabus ≈ **2027-07-26** — inside the 2027-08-07 goal, month-7 gate (2027-04-07) cleared, **zero slack**. The 10-12 week is revision-heavy by the checkpoint rule; pulling the re-test to Tue holds the cost to 2 blocks instead of 5.
- **⚡ PROTOCOL:** **no quiz opener, ever** — a session opens with a problem. Retrieval = re-solving old problems as problems. Gates A/B/C are Kira's silent checklist, **≤ 1 gate question per turn**. **ONE question per turn, restate the statement with it** (10-10). **Library facts get told, logic he leads** (10-09). **NEW (10-11, his words — "cant read that much text"): replies are 3–6 LINES, verdict first.** He reads Kira on his phone, mid-contest, on the move — a wall of text is not thorough, it is unread. Long form only inside a seated block, when he asks for depth.
- **Days kept:** **14 / 66** · build days **14** · **9 days in a row** (10-05 → 10-13) · repair token: **available** · *(09-27 · 09-28 · 09-29 · 09-30 · 10-03 · 10-05 · 10-06 · 10-07 · 10-08 · 10-09 · 10-10 · 10-11 · 10-12 · **10-13 re-test pt 1**)* · zero: 10-01, 10-02, 10-04. Day 66 = **2026-12-01**.
- **⚠️ Needs boss's approval:** `git rm -r practice/10-backtracking/learn` — the last 8 legacy v1 files; blocked by the permission gate.
- **Open threads:** `PLAN.md` §4, `SYSTEM.md` and `CLAUDE.md` §3 still describe the dead 3-slot 45-min day with a RECALL slot — **rewrite to the hour-block model** · `dsa-map.html` still v1 · **`cpp-for-cp.md` needs a classes/structs entry** (#19). Three machines, one repo — **pull before the block, push after it.**

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
