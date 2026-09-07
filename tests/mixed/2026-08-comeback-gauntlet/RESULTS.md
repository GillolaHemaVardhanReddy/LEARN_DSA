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
| 5 | Recursion + **memoization** (unbounded coin change / 1-D DP) | 🟡 | **Re-asked from scratch 8/10 WITH numbers seeded — answered immediately, zero statement stall** (yesterday the same statement drew "so vague"; the seeding fix works). Named exhaustive **pick/not-pick recursion**, correct min-tracking, correct prune-on-overshoot. ⭐ **Unlimited-supply mechanic CORRECT on one probe** — *"it stays on pick, it only moves forward on non-pick"*. **What's missing: memoization was never mentioned** (this is the M9 pattern's whole payoff — LC70 taught him brute→TLE→memo live on 7/05). **Complexity badly wrong: said O(n log n)** — brute is exponential, memo is O(n·amount). |
| 6 | Prefix-sum + hash map (or window `atMost(goal) − atMost(goal−1)`) | 🟡 | **First instinct ❌ then SELF-CORRECTED unprompted ✅.** Opened with *"here also its pick not pick"* — **the subarray→subsequence vocab trap, RECURRING** (he corrected this exact cue on 7/14: pick/not-pick emits *subsequences*; **subarray = contiguous**, so it's the wrong machine). Quoted O(2ⁿ), which is honest for the machine he chose. **Then, one question later and with no prompting, he came back: *"in Q6 we could also use dynamic sliding window"*** — right family, arrived late. Neither prefix+hash nor the `atMost` subtraction surfaced. → **M#12 logged.** |
| 7 | **Sort + converging two pointers** (greedy pair lightest↔heaviest) | ❌ | **MISS, and the algorithm is wrong, not just unnamed.** Called it *"fixed sliding window"* and paired **adjacent** people (check `i`+`i+1`, else ship `i` alone, advance). **No sort anywhere.** Breaks immediately: `people=[1,1,3,3], limit=4` → his machine ships `[1,1]`, `[3]`, `[3]` = **3 boats**; the answer is **2** (`1+3`, `1+3`). Claimed O(n)/O(1) for a wrong algorithm. ⚠️ **Tool-carryover:** he named "sliding window" one message after inventing sliding window for Q6. |
| 8 | Backtracking (n-ary frame, one digit per depth level) | ❌ | **Tapped out — *"i dont know it".*** BUT he stated **the exact trigger** in his own words: *"i might use loops if its 0 or 1 or 2 lengths but it can be any no of digits"* — **"the number of nested loops isn't known until runtime" IS the backtracking cue.** He had the door handle and didn't turn it. He then guessed at "combination of first string to other strings, double loop" and abandoned it. No recursion instinct fired **on a question one slot away from Q5, where he chose recursion**. |
| 9 | Variable window + **two monotonic deques** (max-deque & min-deque) | 🟡 | **Strong on the window half, cold and instant:** *"since its subarray its variable sliding window"*, shrink `while(max−min > limit)`, record before shrinking — the invariant is verbatim correct. **Missed the entire hard half until probed**: asked *"you dropped the element that WAS the max — how do you get the new max?"* he replied ***"well well thats a huge problem i didnt see comming"*** — then **built a working fix on the spot** (ordered multiset, drop on eviction, take next largest). That's a valid O(n log n) answer; the deque O(n) answer (M8) never surfaced. **Complexity claim O(n)/O(1) wrong** on both counts. |
| 10 | *(next session — asked, not answered)* | — | **RESUME HERE, re-asked from scratch with numbers seeded.** |
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

**Score after Q1–Q9 (partial run, 8/09 + 8/10):** **1 ✅ · 5 🟡 · 3 ❌** — Q10–Q20 pending next session.
(8/09: Q1 🟡 · Q2 🟡 · Q3 ❌ · Q4 ✅ — 8/10: Q5 🟡 · Q6 🟡 · Q7 ❌ · Q8 ❌ · Q9 🟡)

**Read at the halfway mark (9 questions — now large enough to say things out loud):**

1. **✅ THE STATEMENT-SEEDING FIX WORKED — 5 for 5.** Yesterday two questions stalled at the
   *reading* layer ("a contradiction", "so vague"). Today every statement shipped with 2–3
   concrete input→output lines and **there was not one reading stall in five questions**, including
   Q5 — the exact statement that had stalled him cold the day before. This is now standing.
2. **⚠️ THE HEADLINE PROBLEM IS *TOOL-CARRYOVER*, NOT DECAY.** Look at the sequence: Q5 he chose
   recursion → **Q6 opens with *"here also its pick not pick"*** → he then invents sliding window
   for Q6 → **Q7 opens with *"this is a fixed sliding window"***. He is answering each question with
   **the tool from the previous question**, not with a fresh read of the statement. Interleaving is
   supposed to *defeat* this; instead the gauntlet is measuring it. **He is not running a
   disqualifier gate** ("is it contiguous? is it sorted? do I need order or membership?") before
   reaching for a tool. That single missing habit explains Q6, Q7 and arguably Q8 — three of the
   four non-✅ marks today.
3. **🔴 M1 COMPLEXITY IS THE MOST BROKEN THING ON THE BOARD, and it is invisible because it never
   fails loudly.** Q5 O(n log n) (a bound that matches *nothing* in the problem) · Q7 O(n)/O(1) for
   a wrong algorithm · Q9 O(n)/O(1) for a machine that is O(n log n)/O(k) at best. Add yesterday's
   Q1 (space O(n)→O(n²)), Q2 (dropped the O(n) feasibility factor) and Q3 (quoted a per-day cost as
   the total). **That is 6 of 9 questions with a wrong complexity.** M1 sits at L3\* — *self-reported,
   never verified*. It is now the single most-evidenced gap in the file.
4. **✅ THE REPAIR MACHINERY IS FULLY INTACT — this is the good news and it's big.** Q6 he
   **self-corrected with zero prompting**. Q9 he was handed one probe and **built a correct
   multiset solution on the spot** from nothing. Q5's unlimited-supply mechanic was right on first
   ask. Nothing here reads as "the knowledge is gone" — it reads as **first-instinct routing is
   unguarded**, and everything downstream of a correct route still works. That is a much cheaper
   fix than relearning nine patterns.
5. **Genuinely dead so far: monotonic stack (Q3) and backtracking-by-name (Q8).** Q8 is the
   frustrating one — he *articulated the trigger* ("it can be any number of digits, I can't just
   write loops") and still didn't reach for recursion, one question after choosing recursion himself.

**Prior read (after 4 questions, 8/09):** the *tools* are alive — he derived Q1's machinery
cold and named Q2's pattern cold. What decayed is **naming** (Q1), **machinery detail** (Q2), and
one pattern outright (**Q3 monotonic stack**). Two separate stalls (Q4, Q5) were **statement-reading**,
not recognition — he does not grip an abstract statement until it has real numbers in it.

**Per-pattern read (fill after scoring):**

*(partial — filled as questions land; final read after Q20)*

| Pattern | Qs | Survived the month? |
|---|---|---|
| M2 Hashing | 1, 10, 18 | 🟡 Q1 tool derived cold, name gone. Q10/Q18 pending. |
| M3 Two Pointers | 7, 17 | ❌ Q7 missed outright — no sort, no converging pointers, wrong answer. Q17 pending. |
| M4 Sliding Window | 4, 13 | ✅ Q4 full + instant. Also **over-fires** — reached for it wrongly on Q7. Q13 pending. |
| M5 Prefix Sum | 6, 16 | ❌→🟡 Q6 never surfaced prefix+hash at all (went recursion, then window). Q16 pending. |
| M6 Binary Search | 2, 11, 19 | 🟡 Q2 named cold, machinery drifted. Q11/Q19 pending. |
| M7 Stacks / Monotonic | 3, 12 | ❌ Q3 dead — zero instinct on a banked L4. Q12 pending. |
| M8 Queues / Deque | 9, 20 | 🟡 Q9 window half cold ✅, deque half absent (built a multiset instead). Q20 pending. |
| M9 Recursion + Memo | 5, 15 | 🟡 Q5 recursion + unbounded mechanic ✅, **memo absent**. Q15 pending. |
| M10 Backtracking | 8, 14 | ❌ Q8 tapped out despite naming the trigger. Q14 pending. |
| M1 Complexity | all | 🔴 **WORST ON THE BOARD — wrong on 6 of 9.** L3\* is self-reported and now contradicted by evidence. |

---

## Part B — Concept recall repair
(logged after Part A determines the repair list)

---

## Part C — Cold re-test of every ❌ / 🟡
Scheduled +3d from the repair pass. Fresh statements, same patterns.
