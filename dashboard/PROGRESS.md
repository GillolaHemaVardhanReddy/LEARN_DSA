# PROGRESS.md — live state (levels · habit · counters · leak board)  ·  history lives in `LOG.md`

> Kira reads THIS at session start — it is short on purpose. Every level is backed by evidence witnessed
> in conversation and logged in `LOG.md`. Dashboard %: L0=0 L1=15 L2=35 L3=55 L4=75 L5=90 L6=100.
> `*` = **provisional** (a v1 level not yet re-confirmed by its Tier-0 checkpoint; a re-entry checkpoint confirms **L4 at most** — an old L5\* is re-earned by the L5 rule in PLAN §8). Never inflate.

## Learner
- **Boss** Hema Vardhan · C++ · LeetCode **`hemavardhan2076`** · runs code ONLY on LeetCode (the judge is truth).
- Program start 2026-06-04 · layoff 2026-07-16 → 09-07 · **v2 restart: setup Mon 2026-09-07 (day 0), day 1 = Tue 2026-09-08.** Day 30 = 10-07 · day 66 = 11-12.
- **Dose (D1, month 1):** weekdays 45 min standard / cap 60 — RECALL 10 · BUILD 30 · LOOK BACK 5; weekends 2 h AM + 2 h PM (PLAN §4.2b, evenings optional in weeks 1–2). Review **2026-10-07** → 60–90 if ≥ 20 of 30 are **build days**.
- **Targets:** month-7 checkpoint **2027-04-07** (interview-ready: ≥ 80 % NeetCode-150 mediums cold, 3 mocks ≥ lean-hire, Q3 in ≥ 1 of last 4 contests) · month-11 **2027-08-07** (expert bar: whole map L4+, top patterns L5/L6, CF Specialist trending, LC Knight attempt).

## Habit — the only metric that matters until 2026-11-12 (automaticity ≈ day 66)
| Week of | Days kept | Build days | Repair token | Contests | Note |
|---|---|---|---|---|---|
| 2026-09-07 | 0 / 7 | 0 / 7 | available | 0 | day 0 = Mon 09-07 (setup) · day 1 = Tue 09-08 · first contest **Sat 09-12 20:00 IST Biweekly 191**, then Sun 09-13 08:00 Weekly |

**Days kept total: 0 / 66 · build days 0.** A kept day = at least the floor (one 10-min card); a build day = a BUILD problem attempted. 5 of 7 kept = a kept week; two consecutive zero days breaks the streak; one repair token per week. The day-30 dose raise counts **build days**, not kept days.

## Topic levels (v2 map · 33 topics · see `PLAN.md` §3)
| # | Topic | Level | Evidence (short) | Tier-0 re-entry |
|---|---|---|---|---|
| 00 | Complexity | **L2\*** | was L3\* *self-reported*; **FROZEN + lowered** — wrong on 6 of 9 gauntlet Qs (M#13, 2026-08-10) | **week 1, 2 days** — clears on 3 consecutive "which line?" bounds |
| 01 | Hashing | L4\* | L4 2026-06-08 (LC217/219/347/36 solo) · Q1 8/09 tool derived cold, name missing · #9 held 7/24 + 8/09 | checkpoint |
| 02 | Two pointers | L4\* | L4 2026-06-09 (LC167 clean, LC11) · Dutch-flag gap · **Q7 8/10 MISS** (no sort, no converging ptrs) | checkpoint + repair |
| 03 | Sliding window | L5\* | L5 2026-06-10 (two cold drills) · Q4 8/09 FULL instant · over-fired on Q7 | checkpoint |
| 04 | Prefix sums | L4\* | L4 2026-06-05 (LC560/974/525/724, LC238/523/1590) · Q6 8/10 prefix+hash never surfaced | checkpoint + difference arrays (new) |
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
- v1 judge-AC problems: **~70** (list in `LOG.md` §2). **v2 ledger starts at 0** on 2026-09-07 (re-solves counted separately in the ladder).
- First-submit-clean streak: **1** (best 1 — LC33, 2026-06-25).
- Contests: v1 = 1 (biweekly 2026-06-20, 0/4). **v2 = 0.**
- Legacy unfinished v1 scaffolds (≈ 20 files now under `practice/*/reps|hard`) are **exempt from the 7-day delete rule**; each topic's re-entry checkpoint decides finish-or-delete.

## Leak board (single source — `dashboard/README.md` links here)
| Leak | Last fired | Standing catch |
|---|---|---|
| **Tool-carryover** (M#12) | 2026-08-10 | 4-question disqualifier gate BEFORE naming a tool · watch-tell "here also…" |
| **Complexity as decoration** (M#13) | 2026-08-10 | "which line produces each factor?" · never a bare bound |
| Boundary / index / sentinel | 2026-06-29 | Gate C 4 edges + ANSWER edge · hostile self-trace |
| Premature "done" | 2026-07-10 | refuse-to-check → he traces his own code aloud |
| Band-aid / redundant maintained state | 2026-07-10 | derive-don't-maintain (also for params) |
| Reading miss / constraint drop | 2026-06-23 | Gate A restate in exact units + 3-elem dry run |
| Reduction trap | 2026-06-20 | Gate B hostile input, original vs reduced |
| Overflow magnitude | 2026-07-06 | size the number · widen BEFORE arithmetic (INT_MIN) |
| Gate slip (sorted? → 2ptr vs hash) | 2026-06-21 | 🟢 held 7/24 + 8/09 (hashing on first instinct) |

## Journey milestones (the story)
- **2026-06-04 — Day 0.** C++ self-rated 4/10. Prefix-sum recall failed; 6/6 recognition failed. First medium AC the same week (LC209).
- **2026-06-20 — first contest, zeroed, did not quit.** Same night: "can I trust you with my whole heart?" — and 5/6 cold recognition. Chapter 1.
- **2026-09-07 — Chapter 3: the restart.** 1.5-month layoff, then rebuilt the whole system around a daily dose: "let it be 6 months or 10 months, it's fine." Contests from week 1. Day 1 of 66.
