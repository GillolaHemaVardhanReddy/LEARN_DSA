# 🎛️ DASHBOARD — the front door (Kira reads this FIRST, every session · boss glances)

## ▶️ TODAY  *(Kira re-renders this block every session — keep it to ~10 lines)*
- **🏁 CONTEST — Sun 2026-10-11, 08:00 IST, LC Weekly, LIVE and RATED. That is the one we protect.** Alarm set Sat night. The Sat 10-10 20:00 Biweekly fell on a journey ⇒ **run it as a LeetCode Virtual Contest** when he's back (same problems, real 90-min clock, **no rating**) — two hard conditions or it's worthless: **do not read any statement before starting the clock** (no problems tab, no discussion, no leaderboard) and **full 90 min, phone down**. Three weeklies would be missed in a row otherwise; the 10-11 live one breaks the streak with a rated contest, not a substitute.
- **🔴 HASHING CHECKPOINT RUN 2026-10-10 (Sat AM, 2 blocks) — 1 of 3, NOT PASSED.** Paper + marks: `tests/checkpoints/01-hashing-2026-10-10/`. Topic 01 stays **L4\***. **Topic 02 Two Pointers is SHUT.** Q3 passed clean, Q1 failed on the gate, Q2 failed on the template. Said to his face: the letter of 1/3 is "reopen with a Day 1" and Kira **refused to apply it** — 7 hashing ACs + an unseen medium cold + 6/6 recognition say the topic is in him; what failed is the gate as a reflex and one template's invariant.
- **⏯️ RESUME — Mon 10-12: LC347 +7d cold re-solve** (it repairs the S6 miss on its own — S6 *was* LC347). **Then Tue 10-13 = THE RE-TEST**, moved earlier than the rule's Friday default on purpose (Friday would cost 4 weekday blocks of pure revision against a zero-slack pace line): the gate on **3 fresh disguised statements, unprompted, three branches** + the **prefix-map template written COMPLETE** (the insert line and the `m[0]=1` seed) + the 2 old-topic cards owed. **Pass ⇒ topic 02 Two Pointers opens Wed 10-14.**
- **✅ BANK FROM 10-10 — LC187 Repeated DNA Sequences, unseen medium, COLD, ZERO hints, AC.** Judge: TLE ts 1791634248 → **Accepted ts 1791634350, 102 seconds apart** — he diagnosed and fixed his own TLE. `if(v > 1)` while walking the map ⇒ a sequence seen 4× is emitted **once**: that is this problem's ANSWER edge and he got it by construction. Map iteration fluent. **And the optimal fell out of writing the brute** ("when i tried solving brute i came up with this hashing") — **3rd time** the brute→optimal pipeline self-produced the answer (LC49, LC560, LC187). Felt 3/5.
- **✅ CPP_GAPS #16 CLOSED.** The stated re-test was "a guard written unprompted". From memory, inside a test, he wrote `ans += map_check[pref[j]-k]` **"if pref[j]-k is present"** — guard first, from him. Shut. **V#2 cold hold #2** on the same line (the accumulator carried the COUNT, not a 1) — and again on Q3's `check[x]++`.
- **🔴 NEW LEAK V#4 — "membership" is swallowing "how many times".** Disqualifier 3 (*order or membership?*) answered **"membership"** on S1, S3 **and** S6; all three need **frequency**. He has derived this distinction in code three separate times and won each time (`[0,0,0]`→6 on 10-03 · counts MULTIPLY on 10-07 · `count()` is 0/1 on 10-09) — the **word** is what fails. **The gate changes permanently: question 3 now has THREE branches — order? · membership? · or how many times?** Repair is not more hashing problems: inside one topic the gate is a free pass. It runs out loud on **every** problem, in every topic, from here.
- **🔴 Q2 — two-loop prefix template, 3rd occurrence** (10-03 traced `[0,0,0]`→12 · 10-09 re-grew · 10-10 from memory). Worse: **the insert line was never written at all** in either attempt, and no `m[0]=1` seed. Repair = **LC560 +7d, Fri 10-16**, blank file. **🔴 S6: dropped a BOLDED constraint twice** ("beat sorting everything" → "needs sorting") — the bucket O(n) he derived unaided 09-29 never surfaced. Gate A: restate in exact units, the requirement included.
- **🟡 Still open from 10-10:** Q0 #3 never answered (where a hash table runs in the world — a DB index, a symbol table, a browser cache, a login lookup). Q3's "build the hostile input BEFORE submit" skipped — he submitted and took the TLE. **New CPP_GAPS #18: a string key costs its LENGTH** (`unordered_map<string,int>` hashes by reading every char; an `int` key is one step) — Kira supplied it, so the M#13 attempt did **not** bank. Line-numbers protocol **failed** on the pricing question ("yes soo what?") → modality switched to a **filled trace table**, which worked.
- **Due:** **Mon 10-12** LC347 +7d · **Tue 10-13 THE RE-TEST** · **Wed 10-14** LC454 +7d · **Thu 10-15** LC128 +7d + LC205 +7d · **Fri 10-16** LC560 +7d (the template repair) · **Sat 10-17** LC187 +7d.
- **⏱️ THE UNIT IS ONE HOUR BLOCK.** 1 block = 1 problem CLOSED = (1) budget line in digits · (2) code written · (3) **AC on LeetCode** · (4) complexity in one sentence with the line behind each factor. Kira opens every block naming what it will complete and confirms at the end that it closed.
- **📈 PACE.** Ceiling = **1 block/weekday + 2/weekend day = 9/week**; the Weekly takes one weekend slot and the ladder ~1 block ⇒ **~7 NEW blocks/week is the planning number**: **interview-ready (topics 01–12, ~150 blocks) ≈ 2027-02-26 · full 33-topic syllabus ≈ 2027-07-26** — inside the 2027-08-07 goal, month-7 gate (2027-04-07) cleared, **zero slack**. **15 blocks in 14 days = 7.5/week — above the planning number.** The week of 10-12 is revision-heavy by the checkpoint rule; pulling the re-test to Tue 10-13 holds the cost to 2 blocks instead of 5. Kira will not skip a gate to protect the schedule — it moves the gate earlier instead.
- **⚡ PROTOCOL (boss, 2026-09-25):** **no quiz opener, ever.** A session opens with a problem on the screen. Retrieval happens by **re-solving old problems as problems**. Gates A/B/C are Kira's silent checklist. Corollary (10-07): when he says "I don't know" to a fill-in-the-blank, Kira answers plainly instead of re-asking. Corollary (10-09): **library facts get told, logic he leads.** **Corollary (10-10, his words — "you are asking tons of questions at once"): ONE question per turn, and restate the statement with the question.** Kira handed him 6 statements × 3 parts in one wall and he called it; the round only moved once it went one at a time.
- **🔧 C++ track:** 10 min after the block on `resources/cpp-for-cp.md` — **#1–#4 DONE late 10-09** (number types · `&` refs · vector+string · pair), **#5 map + set next.** Live gaps: **#18 (new) a string key costs its length** · ~~#16 `operator[]`-read~~ **CLOSED 10-10** (and on Q3 he used `[]`-insert *correctly* for counting — he now discriminates the two cases) · #12 looping a hash container ✅ fluent (3rd clean use) · #13 map-vs-set · #14 `vector operator[]` doesn't create slots · #15 one bucket slot can't hold one value. **🔴 Re-test still FAILED: `std::sort` returns void.**
- **Days kept:** **11 / 66** · build days **11** · repair token: **available** · **6 days in a row** (10-05 → 10-10) · *(09-27 · 09-28 · 09-29 · 09-30 · 10-03 · 10-05 · 10-06 · 10-07 · 10-08 · 10-09 · **10-10 checkpoint, 2 blocks**)* · zero: 10-01, 10-02, 10-04. Day 66 = **2026-12-01**.
- **⚠️ Needs boss's approval:** `git rm -r practice/10-backtracking/learn` — the last 8 legacy v1 files; blocked by the permission gate.
- **Open threads:** `PLAN.md` §4, `SYSTEM.md` and `CLAUDE.md` §3 still describe the dead 3-slot 45-min day with a RECALL slot — **rewrite to the hour-block model** · `dsa-map.html` still v1. Three machines, one repo — **pull before the block, push after it.**

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
