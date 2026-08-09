# RESULTS — Comeback Gauntlet (opened 2026-08-09)

> Filled in **live, question by question**. Never pre-filled. Honest ledger only —
> a 🟡 recorded as ✅ is a lie that costs him an interview later.

## Part A — Cold Recognition (20 Q)

> ⚠️ **KIRA RULE ADOPTED MID-RUN (2026-08-09):** do **NOT** reveal pattern names during Part A.
> I named them on Q1/Q2 before catching it — several later questions live in the same families
> (stack vs monotonic-stack vs deque), so a name handed over early contaminates the reading.
> **Marks only during the run; full reveal after Q20.**

| Q | Pattern (revealed after answering) | Mark | Notes — his trigger, his complexity, what leaked |
|---|---|---|---|
| 1 | Hashing — complement lookup (pair-sum split / meet-in-the-middle) | 🟡 | **Tool DERIVED cold, name missing.** Went brute O(n⁴) → rearranged `a+b = −(c+d)` → map of all A+B sums → scan C+D for the complement. Said *"I don't really know this pattern, I'm off course by a long way"* **while writing the correct answer** — pure calibration leak (Gate 6). ⭐ **#9 LEAK DID NOT FIRE AGAIN:** unsorted "find things summing to X" → he went straight to a map, no sort/two-pointer detour. Second clean instance after 7/24. Time O(n²) ✅ first try; **space wrong first pass (said O(n))**, corrected to O(n²) after one atomic nudge ("how many entries does the map hold?"). |
| 2 | Binary search **on the answer** | 🟡 | **Pattern named cold** — the hard half of BS to spot (nothing in the statement is sorted). But the machinery drifted: **feasibility check wrong** (`target = c*d`; the check is a greedy day-simulation, not an arithmetic product), **lo bound wrong** (said 1; must be `max(weights)`), and **complexity wrong** — said O(log n), missing the O(n) cost of the check itself. Repair in Part B (M6 item 4: the three pieces of search-on-answer). |
| 3 | Monotonic stack — previous-greater / span | ❌ | **MISS.** Produced only the brute (walk backwards from today while `price <= today`) and stated its cost as O(n)/O(1) — that's **per day**; across all n days it's O(n²). No monotonic-stack instinct fired at all. M7 is banked L4 → this is real decay, first hard gap of the sweep. |
| 4 | Variable sliding window (window − maxFreq > k) | ✅ | **FULL, instant.** Expand right, track maxFreq, shrink left when `(windowLen − maxFreq) > k`, record max. O(n) / O(1) ✅. M4 is his only confirmed L5 and it survived the month untouched. ⚠️ **But he bounced off the STATEMENT first** — read "one single repeated letter" as contradicting "change k chars" and stalled. Reading miss (#10 leak), **not** a recognition miss; recognition was immediate once the wording was clarified with a concrete example. |
| 5 | *(resume point — asked, not answered)* | — | Statement given, then he called the session. **Q5 is the first question of next session, re-asked from scratch.** Same bounce as Q4: called it "so vague" until handed concrete numbers (`[1,2,5]/11→3`, `[2]/3→−1`, `[1,3,4]/6→2`). |
| 6 | | | |
| 7 | | | |
| 8 | | | |
| 9 | | | |
| 10 | | | |
| 11 | | | |
| 12 | | | |
| 13 | | | |
| 14 | | | |
| 15 | | | |
| 16 | | | |
| 17 | | | |
| 18 | | | |
| 19 | | | |
| 20 | | | |

**Score after Q1–Q4 (partial run, 2026-08-09):** **1 ✅ · 2 🟡 · 1 ❌** — Q5–Q20 pending next session.

**Early read (4 questions, don't over-conclude):** the *tools* are alive — he derived Q1's machinery
cold and named Q2's pattern cold. What decayed is **naming** (Q1), **machinery detail** (Q2), and
one pattern outright (**Q3 monotonic stack**). Two separate stalls (Q4, Q5) were **statement-reading**,
not recognition — he does not grip an abstract statement until it has real numbers in it.

**Per-pattern read (fill after scoring):**

| Pattern | Qs | Survived the month? |
|---|---|---|
| M2 Hashing | 1, 10, 18 | |
| M3 Two Pointers | 7, 17 | |
| M4 Sliding Window | 4, 13 | |
| M5 Prefix Sum | 6, 16 | |
| M6 Binary Search | 2, 11, 19 | |
| M7 Stacks / Monotonic | 3, 12 | |
| M8 Queues / Deque | 9, 20 | |
| M9 Recursion + Memo | 5, 15 | |
| M10 Backtracking | 8, 14 | |
| M1 Complexity | all | |

---

## Part B — Concept recall repair
(logged after Part A determines the repair list)

---

## Part C — Cold re-test of every ❌ / 🟡
Scheduled +3d from the repair pass. Fresh statements, same patterns.
