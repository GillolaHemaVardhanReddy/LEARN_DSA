# 🎛️ DASHBOARD — the front door (Kira reads this FIRST, every session · boss glances)

## ▶️ TODAY  *(Kira re-renders this block every session — keep it to ~10 lines)*
- **✅ S3 DONE — LC2364 Count Bad Pairs AC on 10-31** (sitting ran past midnight into 11-01, credited to 10-31). The separation move was taught 10-30, so this is a **learning rep, not a cold pass**. His unaided: the rewrite `j − nums[j] = i − nums[i]` · **`answer = all pairs − matching pairs`** (found it himself) · *"a set would just say yes it exists at least once"* ⇒ counts not membership · diagnosed `check[0]=1` as a **ghost index** off one hostile input (`[0]` → −1) · priced `n(n−1)` at 10¹⁰ in digits · dropped the helper vector when asked.
- **🟡 What it cost:** **M#12 fired** (prefix-sum seed carried into a label problem — his own catch, after the trace) · **Gate C magnitude MISSED** — submitted `int ans` + `int` multiply **after being told twice to price it**, then put the cast *after* the arithmetic · **V#7 born** — "order" read as ascending/descending, nC2 vs nP2 unknown · `long long(x)` cast syntax (→ CPP_GAPS #20) · M#13 🟡 ("obviously O(n)", second loop uncounted, hash mechanism only on the prompt).
- **⏯️ RESUME — Sun 2026-11-01: LC WEEKLY 08:00 IST, then the debrief.** After the contest: the **fresh S3′ cold** (unseen, plain arrays, NO teaching) + the **2 old-topic cards** — that is all that is left of re-test 2b, and **Two Pointers opens the moment it passes.** S2 and S3 both ended as learning reps, so the cold pass is still owed.
- **📌 THIS WEEK:** **Sun 11-01 AM LC Weekly 08:00** + debrief · **PM** the one upsolve *or* S3′ + 2 cards (his call — the gate is worth more than the upsolve) · six +7d rungs now stacked: **LC454 · LC560 · LC205 · LC347 · LC128 · LC187** — the whole 10-31 weekend went to S3, so all six slid again. Mon 11-02 onward: S3′ + cards first, then Two Pointers day 1.
- **🏁 NEXT CONTEST: TODAY, Sun 2026-11-01 08:00 IST LC Weekly** — read all 4, hold 2, both first-submission (that's the 10-18 standard: 2/4, top 27.6 %). Then Sat 11-07 20:00 Biweekly.
- **🔴 Live leaks:** **🔴 Overflow magnitude** — fired 10-31 after two warnings; *widen BEFORE the arithmetic* · **V#7** "order" ≠ sorted order · **V#6** subarray = contiguous *(🟢 held ×2)* · **V#4** count vs membership *(🟢 held 10-31 — but only after the abstract question failed 4× and Kira switched to a filled-in walk table)* · **M#12** zeroth question = budget in digits *(🔴 fired 10-31 on the seed)* · **M#13** the factor comes from the **loop line**, the hash makes each step O(1) · 🟡 judge-as-debugger: fire #1 stands, a 3rd re-opens.
- **🟡 Still open:** Q0 #3 (where a hash table runs in the world) · CPP_GAPS #18 (re-test with LC187) · #19 classes (blank-file skeleton) · **#20 cast syntax + placement**.
- **🤝 KIRA'S CONTEST LINE:** during a live rated contest — **triage only** (in scope / off-map). No hints, no debugging, no syntax, no compile questions. LC's anti-LLM canary flagged every contest.
- **⚠️ Three machines, one repo — PULL BEFORE THE BLOCK, PUSH AFTER IT.**
- **⏱️ THE UNIT IS ONE HOUR BLOCK** = budget line in digits · code · **AC on LeetCode** · complexity with the line behind each factor.
- **📈 PACE.** Interview-ready (01–12) ≈ 2027-02-26 at ~7 blocks/week. Topic 01 has now run 5 weeks — **the cold pass is the only thing holding topic 02 shut, and it is one block long.** Month-7 gate 2027-04-07.
- **⚡ PROTOCOL:** no quiz opener — open with a problem · ≤ 1 gate question per turn · ONE question per turn, statement restated · library facts told, logic he leads · **3–6 lines, verdict first** (phone) · plain vocabulary · **tables beat inline notation** · **never ask the same abstract question twice — switch to a filled-in table** (10-31 lesson) · never an open "reduces to ___" blank.
- **Days kept:** **21 / 66** · build days **21** · streak **5** (10-27 → 10-31) · longest 9 · zero: 10-24, 10-25, 10-26 · 10-19 → 10-22 = declared rest. Day 66 = 2026-12-01.
- **⚠️ Needs boss's approval:** `git rm -r practice/10-backtracking/learn` — the last 8 legacy v1 files.
- **Open threads:** `PLAN.md` §4, `SYSTEM.md`, `CLAUDE.md` §3 still describe the dead 3-slot day — rewrite to the hour-block model · `dsa-map.html` still v1 · `cpp-for-cp.md` needs its classes/structs entry (#19) and the cast entry (#20).

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
