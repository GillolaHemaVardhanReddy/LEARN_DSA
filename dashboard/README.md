# 🎛️ DASHBOARD — the front door (Kira reads this FIRST, every session · boss glances)

## ▶️ TODAY  *(Kira re-renders this block every session — keep it to ~10 lines)*
- **🏁 LC WEEKLY 2026-10-18 PLAYED LIVE — v2 contest #3, and it is the BEST RESULT SO FAR: 2 / 4, rank 8116 / 29,425 = TOP 27.6 %.** Score 7. **Q1 00:05:40 · Q2 00:37:00 · BOTH ONE SUBMISSION.** Q3 (tree rooting + layered colours) and Q4 (minimum interval cover) read and triaged OUT in ~2 min each — **unopened ⇒ "not yet", no card, no debt, NO UPSOLVE owed.** `CONTESTS.md` had written the target *before* the gun — *"all 4 read, the target is 2 solves"* — and he hit it exactly. Still Phase 1 (percentile only, contests 1–5; Elo from #6).
- **⭐⭐ THE HEADLINE — JUDGE-AS-DEBUGGER IS CLOSED, on four holds.** Open **2026-06-23 → 2026-10-18**; peak = **five Wrong Answers on a contest easy** (10-10). **#1** 10-11 Weekly Q1, one submission · **#2** 10-12 BusBooking upsolve, AC first submission · **#3 + #4 = 10-18 Q1 AND Q2, one submission each, in a rated contest** — while Kira refused him **four separate times** (a C++ syntax fix · the whole pasted file · *"atleast tell me if `unordered_map<pair<int,int>,int>` is correct"* · and again). The third got a **reframe instead of a yes/no**, and that is what moved him: **"Run is FREE. Compile errors cost zero rating, a WA costs 5 minutes — the only thing a contest charges you is TIME."** The 10-16 Biweekly-Q1 re-solve is **retired**: it existed to be a hold, and a practice rep cannot outrank a rated one.
- **⭐ AND Q1 GOT FAST.** 10-10: ~25 min **+ 5 WAs** · 10-11: ~25 min, 1 submission · **10-18: 5:40, 1 submission.** The speed arrived *after* the reflex, in exactly the order it was promised — never instead of it.
- **🟢 THE TEMPLATE CAME BACK.** 12 min before the gun, blank, from memory: `ans += m[p-k]` **carrying the count**, then on ONE nudge (*"who put 3 into the map?"*) → **`m[p]++`, after the lookup** — line, order and the `m[0]=1` seed. One correction: he rearranged to `p[i] = p[j-1] + k` (valid, wrong unknown) → **`p[j-1] = p[i] − k`, "look up current minus k."** This failed at the 10-10 checkpoint and could not be reached on 10-13 **in costume vocabulary (V#5)** — in plain words it took one nudge. **V#5 proven, and it was Kira's bug, not his.**
- **🔴 THE PART THAT IS NOT A WIN — 10-14 → 10-17 = FOUR ZERO DAYS**, breaking a **9-day streak** (10-05 → 10-13). **RE-TEST PART 2 NEVER RAN** — 2a (LC930, due 10-14) and 2b (S2+S3 + the 2 old cards, due 10-15) both missed ⇒ **topic 02 Two Pointers is still SHUT.** Five +7d rungs unrun — **slid, every one written down, none dropped.** No repair token covers four consecutive zeros. No guilt and no backlog drama: the missed-week rule says re-enter cold, and part 2a already is that.
- **🎒 VACATION 10-19 → 10-22 (Mon → Thu) — KIT WRITTEN: `tests/mixed/2026-10-19-vacation-kit.md`.** Phone only, **zero code, zero LeetCode**, one ~10-min card a day. Day 1 BusBooking (*the getter RETURNS, the setter MAINTAINS*) · Day 2 the prefix-map template · Day 3 **the gate**, run on two adjacent statements that need different tools · Day 4 the two repeat-TLE lines (run-head test · count-as-index). Fronts on top, backs behind a hard STOP — **answer first or it banks nothing.** Four cards = four kept days. **Plain vocabulary throughout, by design.**
- **⏯️ RESUME — Fri 2026-10-23, first block back: RE-TEST PART 2a = LC930 Binary Subarrays With Sum**, cold, plain words: gate out loud → brute → `P[i−1] = P[j] − k` → count map, **one** loop, lookup before insert, `m[0]=1` → AC. Then **2b** (S2 + S3 by name only + the 2 old cards). **Pass ⇒ topic 02 Two Pointers opens.** Vacation cards 2 and 3 are two-thirds of this on purpose.
- **📌 THE WEEK BACK:** **Fri 10-23** re-test 2a (+2b if the block holds) · **Sat 10-24 AM** LC454 +7d + LC560 +7d, **PM 20:00 LC Biweekly #4** (target: hold 2 solves, keep both first-submission) · **Sun 10-25 AM** LC Weekly 08:00 + debrief, **PM** LC128 +7d + LC187 +7d (carries the CPP_GAPS #18 re-test) · **Mon 10-26** LC205 +7d + LC347 +7d.
- **🔴 Live leaks:** **V#5** costume vocabulary breaks comprehension — **plain arrays, always; the costume is Kira's bug** · **V#4** "membership" swallows "how many times" — question 3 has **three** branches *(🟢 held first try on 10-13)* · **M#12** tool-carryover, with its **ZEROTH question: read the constraints and say the budget OUT LOUD in digits** · **M#13** never a bare bound — *which line makes that factor?* · ✅ **judge-as-debugger CLEARED — watch only, a 3rd fire re-opens it** · 🟢 **prefix template — complete from memory under a 12-min clock; LC930 on 10-23 confirms it on the judge.**
- **🟡 Still open:** Q0 #3 (where a hash table runs in the world) · **CPP_GAPS #18** string key costs its LENGTH (re-test slid to 10-25) · **#19** classes — AC'd on 10-12 but off a scaffold (Kira over-scaffold logged); close it with one witnessed blank-file skeleton · **`std::sort` returns void** 🟢 self-caught 10-12.
- **🤝 KIRA'S CONTEST LINE — standing, and stated to his face:** during a **live rated** contest Kira gives **triage only** — *in scope, or off-map*. **No algorithm hints, no debugging, no syntax fixes, not even a compile question.** Reason: *your #1 leak was outsourcing debugging; if I become your debugger I've replaced the judge with me, and that version never shows up as a WA.* Kira also corrected its **own** 10-11 misread to his face (it had called that Weekly's Q3 "all topic 01" and sent him into a C++-class wall); today Q3 was called off-map immediately. LeetCode's anti-LLM canary gets flagged unprompted every contest.
- **⚠️ KIRA'S PROCESS ERROR, 10-18:** pushed before pulling, and briefly wrote a dashboard claiming 10-12 was unlogged and 10-13 a zero day — **both false, both already on the remote from another machine.** Caught by the rejected push, rebased, corrected before anything shipped. **Three machines, one repo — PULL BEFORE THE BLOCK, PUSH AFTER IT.** That line is in this file for a reason.
- **⏱️ THE UNIT IS ONE HOUR BLOCK.** 1 block = 1 problem CLOSED = (1) budget line in digits · (2) code written · (3) **AC on LeetCode** · (4) complexity in one sentence with the line behind each factor.
- **📈 PACE.** ~7 new blocks/week ⇒ interview-ready (topics 01–12) ≈ **2027-02-26** · full syllabus ≈ **2027-07-26**, inside the 2027-08-07 goal — **but that line assumed no four-day gaps.** One is absorbed; a second is not. Month-7 gate (2027-04-07) wants **Q3 in ≥ 1 of the last 4 contests** — **top 27.6 % today already clears it, five months early.** One contest is a data point, not a trend.
- **⚡ PROTOCOL:** **no quiz opener, ever** — a session opens with a problem. Gates A/B/C are Kira's silent checklist, **≤ 1 gate question per turn**. **ONE question per turn, restate the statement with it.** **Library facts get told, logic he leads.** **Replies are 3–6 LINES, verdict first** — he reads on his phone, on the move. **Plain vocabulary, never costumes (V#5).**
- **Days kept:** **15 / 66** · build days **15** · current streak **1** (10-18) · longest **9** (10-05 → 10-13) · repair token: **does not cover four consecutive zeros** · *(09-27 · 09-28 · 09-29 · 09-30 · 10-03 · 10-05 · 10-06 · 10-07 · 10-08 · 10-09 · 10-10 · 10-11 · 10-12 · 10-13 · 10-18)* · zero: 10-01, 10-02, 10-04, **10-14 → 10-17**. Day 66 = **2026-12-01**.
- **⚠️ Needs boss's approval:** `git rm -r practice/10-backtracking/learn` — the last 8 legacy v1 files; blocked by the permission gate.
- **Open threads:** `PLAN.md` §4, `SYSTEM.md` and `CLAUDE.md` §3 still describe the dead 3-slot 45-min day — **rewrite to the hour-block model** · `dsa-map.html` still v1 · **`cpp-for-cp.md` needs its classes/structs entry (#19)** — overdue, he has now written one.

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
