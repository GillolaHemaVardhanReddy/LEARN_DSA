# 🎛️ DASHBOARD — the front door (Kira reads this FIRST, every session · boss glances)

## ▶️ TODAY  *(Kira re-renders this block every session — keep it to ~10 lines)*
- **🏁 CONTEST FIRST — next = Sat 2026-10-10, 20:00 IST, LC Biweekly** (v2 contest #1, Phase 1 = participation only) · then Sun 10-11 08:00 Weekly. **Two weeklies missed in a row (09-27 didn't know · 10-04 knew and worked instead).** Evening slot is easier to protect — alarm the night before, not that morning. Kira names the contest in line 1 of every session; inside 48 h it is the first thing said.
- **⏯️ RESUME — topic 01 Hashing, rung 5/6: LC454 4Sum II.** New idea: **split the search space in half and hash one half — n⁴ becomes n².** Scaffold it just-in-time in `practice/01-hashing/learn/`. Nothing is carried mid-problem; the last block closed clean.
- **Due before that block (2 cards, re-derive in words, no code):** **LC128** — why only a run's HEAD starts a walk, and why the outer loop must iterate the SET not the array · **LC560** — the identity, the map's key→value, the seeded `{0:1}`, and why lookup comes BEFORE insert. Both slid from 10-04 (a zero day).
- **📚 STRUCTURE:** one topic, start-to-finish, as a named ladder (`practice/01-hashing/HASHING-SET.md` — **Kira teaches from that file, never improvises a detour**). **Hashing: 4/6 CLOSED** (LC49 · LC347 · LC128 · LC560). Left: rung 5 LC454, rung 6 LC205, then the **combined reps round** (all 6 shuffled, no labels, cold, one sitting). **Topic 02 does not open until that round is clean.**
- **⏱️ THE UNIT IS ONE HOUR BLOCK.** 1 block = 1 problem CLOSED = (1) budget line said · (2) code written · (3) **AC on LeetCode** · (4) complexity in one sentence with the line behind each factor. Kira opens every block naming what it will complete and confirms at the end that it closed.
- **📈 PACE — the number that decides Feb 2027.** Actual: **7 blocks in the 9 days since day 1 ≈ 5.4/week** vs the 18/week target. At 5/wk the syllabus lands ~Jan 2028 ✗. **Interview-ready (~150 blocks, topics 01–12) by mid-Jan 2027 needs ~10 blocks/week sustained.** The gap between 5 and 10 isn't talent — it's 10-01, 10-02 and 10-04. Floor stays one block; zero is the only failure.
- **⚡ PROTOCOL (boss, 2026-09-25):** **no quiz opener, ever.** A session opens with a problem on the screen. Retrieval happens by **re-solving old problems as problems**. Gates A/B/C are Kira's silent checklist.
- **🔴 LIVE LEAK — V#2, "traces his intent, not his code."** Fired **3× in one session** (LC560 insert-before-lookup · LC347 walk start `n-1` one minute after saying "index 4" · LC128 run-start 09-30). The spoken invariant is right and the written line contradicts it — invisible to the compiler every time. **Kira's move on the next wrong answer: name the line numbers and say nothing else.** His rule: trace what the machine does with those exact tokens, never what the line is *for*.
- **🟡 M#13 counter: 1 of 3 banked.** "No adjectives in a budget line" — multiply the numbers and write the digits ("slightly more than 10^8" was **2.5×10^9**, 25× over).
- **🔧 C++ track:** 10 min after the block on `resources/cpp-for-cp.md` — **next = #1 number types** (owed since 09-28, still not done). New gaps logged 10-03/10-05: looping a hash container (#12), map-vs-set choice (#13), `vector operator[]` does not create slots (#14), one bucket slot can't hold one value (#15). **🔴 Re-test FAILED: `std::sort` returns void** — identical bug on LC49 six days apart; say which list a function is on before writing `x = f(...)`.
- **Days kept:** **6 / 66** · build days **6** · repair token: could not apply this week (two consecutive zeros) · *(09-27 LC49 · 09-28 LC347 · 09-29 bucket · 09-30 LC128 partial · **10-03 three blocks** · 10-05 LC347 re-solve)* · zero: 10-01, 10-02, 10-04. Day 66 = **2026-12-01**.
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
