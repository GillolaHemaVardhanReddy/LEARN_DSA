# PROGRESS.md — live state (levels · habit · counters · leak board)  ·  history lives in `LOG.md`

> Kira reads THIS at session start — it is short on purpose. Every level is backed by evidence witnessed
> in conversation and logged in `LOG.md`. Dashboard %: L0=0 L1=15 L2=35 L3=55 L4=75 L5=90 L6=100.
> `*` = **provisional** (a v1 level not yet re-confirmed by its Tier-0 checkpoint; a re-entry checkpoint confirms **L4 at most** — an old L5\* is re-earned by the L5 rule in PLAN §8). Never inflate.

## Learner
- **Boss** Hema Vardhan · C++ · LeetCode **`hemavardhan2076`** · runs code ONLY on LeetCode (the judge is truth).
- Program start 2026-06-04 · layoff 2026-07-16 → 09-07 · **v2 restart: setup 09-07 then 09-25 (the 09-08 start never happened — 17 zero days, closed out). REAL day 1 = Sun 2026-09-27.** Day 30 = **2026-10-26** · day 66 = **2026-12-01**.
- **Dose — the HOUR BLOCK (boss, 2026-09-26; the 45-min 3-slot day is DEAD).** 1 block = 1 problem CLOSED (budget line · code · **AC on LeetCode** · complexity with the line behind each factor). Target **2 blocks/weekday + 4 each Sat/Sun = 18/week** (boss, 2026-09-28). Floor = one block. **No quiz opener, ever** (boss, 2026-09-25) — retrieval happens only by re-solving problems.
- **Targets:** month-7 checkpoint **2027-04-07** (interview-ready: ≥ 80 % NeetCode-150 mediums cold, 3 mocks ≥ lean-hire, Q3 in ≥ 1 of last 4 contests) · month-11 **2027-08-07** (expert bar: whole map L4+, top patterns L5/L6, CF Specialist trending, LC Knight attempt).

## Habit — the only metric that matters until 2026-11-12 (automaticity ≈ day 66)
| Week of | Days kept | Build days | Repair token | Contests | Note |
|---|---|---|---|---|---|
| 2026-09-07 | 0 / 7 | 0 / 7 | — | 0 | **VOID** — v2 never started; 17 zero days closed out on 09-25, not carried as debt |
| 2026-09-21 | 1 / 7 | 1 / 7 | available | 0 | **v2 day 1 = Sun 2026-09-27** · LC49 AC (brute TLE → optimal) · unit is now the **hour block**, not the 45-min slot |
| 2026-09-28 | **4 / 7** | **4 / 7** | **could not apply** (two consecutive zeros 10-01 + 10-02 — a token needs the floor met the next day) | 0 (missed 09-27 Weekly — didn't know · **missed 10-04 Weekly — knew, chose other work**) | Mon 09-28: LC49 +1d card ✅ cold · **LC347 AC** (sort-by-count, first comparator/lambda) · Tue 09-29: **LC347 bucket O(n) derived unaided + AC** · Wed 09-30: LC128 approach + run-start rule, code mid-debug · **ZERO 10-01, ZERO 10-02** (streak broken) · Sat 10-03: **3 blocks — LC128 AC + LC560 brute AC + LC560 optimal AC + LC49 cold re-solve AC** · **ZERO 10-04** (+ contest missed) |
| 2026-10-05 | 1 / 7 (in progress) | 1 / 7 | available | 0 — next Sat **10-10 20:00** Biweekly | Mon 10-05: LC347 bucket cold re-solve AC (3 bugs, all found by trace/judge) |

**Days kept total: 6 / 66 · build days 6.** *(09-27 · 09-28 · 09-29 · 09-30 · 10-03 · 10-05 — zero: 10-01, 10-02, 10-04)* A kept day = at least the floor (one 10-min card); a build day = a BUILD problem attempted. 5 of 7 kept = a kept week; two consecutive zero days breaks the streak; one repair token per week. The day-30 dose raise counts **build days**, not kept days.

## Topic levels (v2 map · 33 topics · see `PLAN.md` §3)
| # | Topic | Level | Evidence (short) | Tier-0 re-entry |
|---|---|---|---|---|
| 00 | Complexity | **L2\*** | was L3\* *self-reported*; **FROZEN + lowered** — wrong on 6 of 9 gauntlet Qs (M#13, 2026-08-10). **1 of 3 banked 2026-09-27**: named "O(n·L log L), the one-time sort" on LC49 unprompted — but called the `map` insert "simple" when it was the costliest line | **no longer a separate 2-day block** — it is the budget line run in front of every problem; clears on 3 consecutive "which line?" bounds |
| 01 | Hashing | L4\* | L4 2026-06-08 (LC217/219/347/36 solo) · Q1 8/09 tool derived cold, name missing · #9 held 7/24 + 8/09 · **2026-09-27 LC49 AC**, key derived unaided · **2026-09-28 LC347 AC** (count → pairs → sort by count), LC49 key recalled cold at +1d · **2026-09-29 LC347 bucket O(n) derived unaided + AC** · **2026-10-03 LC128 AC** (run-start rule + iterate-the-set fix, TLE→AC) · **2026-10-03 LC560 AC — prefix+hash DERIVED almost entirely unaided** (own table → sum(i..j)=P[j]−P[i−1] → the growing map) · **2026-10-03 LC49 cold re-solve at +7d, 3rd pass, AC** · **2026-10-05 LC347 bucket cold re-solve at +7d, AC**. Still **L4\*** — ACs are not the topic test; the combined reps round is | **the combined reps round** (all 6 shuffled, cold, one sitting) · **ladder 4/6 CLOSED, rung 5 LC454 next** |
| 02 | Two pointers | L4\* | L4 2026-06-09 (LC167 clean, LC11) · Dutch-flag gap · **Q7 8/10 MISS** (no sort, no converging ptrs) | checkpoint + repair |
| 03 | Sliding window | L5\* | L5 2026-06-10 (two cold drills) · Q4 8/09 FULL instant · over-fired on Q7 | checkpoint |
| 04 | Prefix sums | L4\* | L4 2026-06-05 (LC560/974/525/724, LC238/523/1590) · ~~Q6 8/10 prefix+hash never surfaced~~ → **DEBT PAID 2026-10-03: derived prefix+hash from scratch on LC560 (own table, own identity, own invariant) + AC** | checkpoint + difference arrays (new) |
| 05 | Binary search | L4\* | L4 2026-06-10 (LC34/875) · LC33 first-submit-clean 6/25 · Q2 8/09 named, machinery drifted | checkpoint + repair |
| 06 | Sorting | L1 | bucket sort built (LC347) · merge/quick/comparators never formalized | **NEW** (3 days) |
| 07 | Stacks + monotonic | L4\* | L4 2026-06-25 (LC739/503) · LC402/456/155 · **Q3 8/09 MISS = real decay** | checkpoint + rebuild NGE cold |
| 08 | Queues + deque | L3\* | L3 2026-07-04 (LC239 AC) · practice claim unverified · Q9 8/10 window ✅ / deque absent | checkpoint |
| 09 | Recursion (+ memo, fast power) | L4\* | L4 2026-07-08 (LC50/746/198) · Q5 8/10 recursion ✅ / memo absent | checkpoint |
| 10 | Backtracking | L3\* | L3 2026-07-10 (un-choose derived from own bug) · LC39 self-derived 7/16 · **Q8 8/10 tapped out** | checkpoint + repair |
| 11 | Bits | L1 | bitmask enumeration used as an oracle (LC78/LC402) | **NEW** (3 days) |
| 12–32 | Tiers 1–5 | L0 | — | open per `PLAN.md` §7 |

**Overall mastery (in-scope = Tier 0, 12 topics, provisional):** (35+75+75+90+75+75+15+75+55+75+55+15)/12 = **59 %** — will be re-derived from the Tier-0 checkpoints by 2026-10-11.  Interview readiness: **not estimated** until then.

## Counters
- v1 judge-AC problems: **~70** (list in `LOG.md` §2). **v2 judge-AC ledger: 4 distinct problems / 8 accepted submissions** — LC49 (09-27, + cold re-solve 10-03) · LC347 (09-28 sort, 09-29 bucket, + cold re-solve 10-05) · LC128 (10-03) · LC560 (10-03 brute **and** optimal).
- **Blocks closed (the real unit):** 7 in the 9 days since day 1 = **~5.4 / week** vs the 18/week target. Interview-readiness by Feb 2027 needs **~10 / week** sustained.
- First-submit-clean streak: **1** (best 1 — LC33, 2026-06-25).
- Contests: v1 = 1 (biweekly 2026-06-20, 0/4). **v2 = 0 played, 2 weeklies missed (09-27 didn't know · 10-04 knew).**
- Legacy v1 scaffolds: **DELETED 2026-09-27 on boss's instruction** ("they are not remembered anyways") — practice went 174 files → 24; all `reps/`, `learn/`, `hard/` for topics 01–09 removed via `git rm` (recoverable from history), every `notes.md` kept. **Outstanding: `practice/10-backtracking/learn/` (8 files) — the delete was blocked by the permission gate and needs boss's approval.**

## Leak board (single source — `dashboard/README.md` links here)
| Leak | Last fired | Standing catch |
|---|---|---|
| **Tool-carryover** (M#12) | 2026-08-10 | 4-question disqualifier gate BEFORE naming a tool · watch-tell "here also…" |
| **Complexity as decoration** (M#13) | **2026-10-03 🔴** — priced 2.5×10^9 as "slightly more than 10^8" (25× off) on LC128; also put the log on `n` instead of `L` for LC49 | "which line produces each factor?" · never a bare bound |
| Boundary / index / sentinel | 2026-06-29 | Gate C 4 edges + ANSWER edge · hostile self-trace |
| **Traces his INTENT, not his CODE** (V#2) | **2026-10-05 🔴 — 3× in one session** (LC560 insert-before-lookup · LC347 walk start `n-1` right after saying `n` · LC128 09-30 run-start) | read the characters on the line aloud, never the purpose of the line |
| Premature "done" | **2026-10-03 🟢 held** (asked "check then" twice, refused both times; his own trace found both bugs) | refuse-to-check → he traces his own code aloud |
| Band-aid / redundant maintained state | 2026-07-10 | derive-don't-maintain (also for params) |
| Reading miss / constraint drop | 2026-06-23 | Gate A restate in exact units + 3-elem dry run |
| Reduction trap | 2026-06-20 | Gate B hostile input, original vs reduced |
| Overflow magnitude | 2026-07-06 | size the number · widen BEFORE arithmetic (INT_MIN) |
| Gate slip (sorted? → 2ptr vs hash) | 2026-06-21 | 🟢 held 7/24 + 8/09 (hashing on first instinct) |

## Journey milestones (the story)
- **2026-06-04 — Day 0.** C++ self-rated 4/10. Prefix-sum recall failed; 6/6 recognition failed. First medium AC the same week (LC209).
- **2026-06-20 — first contest, zeroed, did not quit.** Same night: "can I trust you with my whole heart?" — and 5/6 cold recognition. Chapter 1.
- **2026-09-07 — Chapter 3: the restart.** 1.5-month layoff, then rebuilt the whole system around a daily dose: "let it be 6 months or 10 months, it's fine." Contests from week 1. Day 1 of 66.
