# 🎛️ DASHBOARD — the front door (Kira reads this FIRST, every session · boss glances)

## ▶️ TODAY  *(Kira re-renders this block every session — keep it to ~10 lines)*
- **✅ RE-TEST 2a DONE — LC930 AC on 10-28.** Seed `check[0]=1` and **lookup before insert, cold** — the exact two lines that failed the 10-10 checkpoint, now confirmed on the judge. Budget line in digits unprompted (9·10⁸ ⇒ n or n log n). V#4 held again ("how many times" first try).
- **🟡 What slipped:** gate Q1 — he didn't know **subarray = contiguous** (→ **V#6**, fixed by the `[1,0,1]` vs sorted `[0,1,1]` trace) · brute submitted untraced → WA (judge-as-debugger **post-close fire #1**, practice) · optimal also submitted without the asked trace · the bridge needed a **table**, inline `P[..]` notation didn't land.
- **⏯️ RESUME — Thu 2026-10-29: RE-TEST 2b, S2 resumes.** S2 = LC1248 Nice Subarrays (disguised: "count subarrays with exactly k odd numbers", examples `[1,1,2,1,1]` k=3 → 2 · `[2,4,6]` k=1 → 0 · `[2,2,2,1,2,2,1,2,2,2]` k=2 → 16). **Gate already done 10-28** (V#6 held, how many times, count) — he owes only **the tool + one-line idea, cold. Tool NOT named yet — don't leak it.** He stopped tired at the cap; open fresh, no recap of the gate beyond one line. Then S3 (fresh, plain arrays) + the 2 old-topic cards + LC930 +1d card. **Pass ⇒ topic 02 Two Pointers opens.**
- **📌 THIS WEEK:** Thu 10-29 re-test 2b · Fri 10-30 BusBooking card (10 min) + 2b overflow / Two Pointers day 1 if 2b passed · **Sat 10-31 AM** LC454 + LC560 +7d · **PM** LC205 + LC347 +7d · **Sun 11-01 AM LC Weekly 08:00** + debrief · **PM** LC128 + LC187 +7d (CPP_GAPS #18). All six slid +7d rungs land this weekend — none dropped.
- **🏁 NEXT CONTEST: Sun 2026-11-01 08:00 IST LC Weekly** — read all 4, hold 2, both first-submission. (10-24 Biweekly and 10-25 Weekly: no session, not logged.) Then Sat 11-07 20:00 Biweekly.
- **🔴 Live leaks:** **V#6** subarray = contiguous · **V#5** plain arrays always (Kira's bug) · **V#4** Q3 has three branches *(🟢 held ×2)* · **M#12** zeroth question = budget out loud in digits *(🟢 held 10-23)* · **M#13** the factor comes from the **loop line**, the map makes each step O(1) · 🟡 judge-as-debugger watch: fire #1 since close, a 3rd re-opens.
- **🟡 Still open:** Q0 #3 (where a hash table runs in the world) · CPP_GAPS #18 (re-test Sun 11-01 with LC187) · #19 classes — one witnessed blank-file skeleton.
- **🤝 KIRA'S CONTEST LINE:** during a live rated contest — **triage only** (in scope / off-map). No hints, no debugging, no syntax, no compile questions. LC's anti-LLM canary flagged every contest.
- **⚠️ Three machines, one repo — PULL BEFORE THE BLOCK, PUSH AFTER IT.**
- **⏱️ THE UNIT IS ONE HOUR BLOCK** = budget line in digits · code · **AC on LeetCode** · complexity with the line behind each factor.
- **📈 PACE.** Interview-ready (01–12) ≈ 2027-02-26 assumed ~7 blocks/week; the last 3 weeks ran far below that (2 gaps: 10-14→17, 10-24→26). **Two Pointers opening this week is what puts the line back on track.** Month-7 gate 2027-04-07.
- **⚡ PROTOCOL:** no quiz opener — open with a problem · ≤ 1 gate question per turn · ONE question per turn, statement restated · library facts told, logic he leads · **3–6 lines, verdict first** (phone) · plain vocabulary · **tables beat inline notation** · never an open "reduces to ___" blank — offer a choice or confirm a written card.
- **Days kept:** **18 / 66** · build days **18** · streak **2** (10-27 → 10-28) · longest 9 · zero: 10-24, 10-25, 10-26 · 10-19 → 10-22 = declared rest. Day 66 = 2026-12-01.
- **⚠️ Needs boss's approval:** `git rm -r practice/10-backtracking/learn` — the last 8 legacy v1 files.
- **Open threads:** `PLAN.md` §4, `SYSTEM.md`, `CLAUDE.md` §3 still describe the dead 3-slot day — rewrite to the hour-block model · `dsa-map.html` still v1 · `cpp-for-cp.md` needs its classes/structs entry (#19).

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
