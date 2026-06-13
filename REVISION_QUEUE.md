# REVISION_QUEUE.md — Spaced Repetition for Hema Vardhan

> Memory is built by recall under difficulty, not re-reading. This queue is
> date-driven: the mentor reads it at session start, runs whatever is **due today
> or overdue**, and reschedules based on the result.

## Rules
- A topic enters the queue when it first reaches **L3** (implemented from memory).
- Checkpoints: **+1d, +3d, +7d, +14d, +30d, +90d** from the last successful recall.
- Revisions are **closed-book first**: reconstruct the idea/template before looking.
- A **pass** advances to the next interval. A **fail** resets to +1d and flags the
  topic weak in `PROGRESS.md` + may create a `MISTAKE_JOURNAL.md` entry.
- Revision sets are **interleaved** (mix topics) — this trains *which tool applies*,
  i.e. pattern recognition, not just recall of one thing.
- Mistake re-tests (from `MISTAKE_JOURNAL.md`) also land here on their re-attempt date.

---

## Due / overdue  _(work these first each session)_
| Due date | Topic / Pattern | Interval stage | Type | Notes |
|---|---|---|---|---|
| ✅ RUN 2026-06-12/13 | ~~HARD L5 stress-drill (SW/Prefix/Hashing/2ptr/BS)~~ | L5 test | `/drill` | **NO L5 EARNED.** Q2 prefix+hash ✓, Q3 var-SW ✓, Q4 BS-on-answer-maximize re-derived after teaching, Q6 k-th-distance won with heavy help. MISSES: Q1 unsorted-pair→sort reflex (MISTAKE #9 FAIL, 3×), Q4+Q6 reading misses (NEW MISTAKE #10). Q5 counting mechanic / Q7 freq-fix / Q8 NOT reached. Re-run a fresh hard drill after process fixes land. |
| ✅ DONE 2026-06-08 | ~~Hashing SOLO SET (L4 gate)~~ | done | solo | **ALL 4 AC SOLO** (LC217/219/347/36). M2 Hashing → **L4 EARNED**. LC219 cleared drill Q7 (chose hashing, not two pointers). |
| 2026-06-09 | Hashing concept recall (+1d) | +1d | recall | Closed-book: why O(1) avg / O(n) worst? what's a collision & how resolved? the 4 sub-pattern cues (complement/freq/group-by-key/membership)? |
| 2026-06-13+ | **L5 recognition drill (DELAYED + interleaved)** | L5 test | `/drill` | Learner's call (good instinct): do NOT test L5 immediately after L4 — immediate = short-term recall, not transfer. Take a gap + learn M3 Two Pointers first, THEN cold-drill SW/Prefix/Hashing interleaved. Prior 4/7 (hashing 0/2); target ≥6/7 incl. all hashing Qs → that earns L5. |
| 2026-06-08 | Prefix Sum + Hash (GOAL×KEY) | +1d | recall | Heavily reinforced 6/7 (LC238/LC523 AC). Re-test: reconstruct GOAL×KEY cold + solve one prefix problem map-closed. |
| 2026-06-08 | Boundary/INDEX values (**WEAK**, 7×) | re-test | re-test | Recurred 6/7 (LC523 truthiness/overwrite/off-by-one). He now self-IDs them as index bugs. Clears after 2 clean mediums w/ zero index bugs. |
| ✅ DONE 2026-06-11→09 | ~~MISTAKE #6 re-test (hashing recognition)~~ | done | recall | LC219 solved SOLO via hashing (last-seen map), NOT two pointers → drill Q7 miss CLEARED. |
| ✅ DONE 2026-06-10 | ~~BS mediums LC34 + LC875~~ | done | solo | **BOTH AC → M6 L4 EARNED.** Band-aids gone ✅, but Koko hit an overflow debug cycle (MISTAKE #8) — not first-submit-clean. MISTAKE #7 = re-tested PARTIAL. |
| ✅ DONE 2026-06-10 | ~~L5 recognition drill (interleaved)~~ | done | `/drill` | **6/7** (up from 4/7). → M4 SW + M5 Prefix L5 RECOGNIZED. Hashing recog hole CLOSED bar the unsorted-pair first-instinct (MISTAKE #9). |
| **2026-06-14** | **Unsorted-pair first-instinct (MISTAKE #9 re-test) — FAILED AGAIN 6/13** | re-test | `/drill` | 3rd failure. Name an UNSORTED pair/complement problem as HASHING on FIRST instinct (no 2ptr detour). The spoken gate "is it sorted? no → hashing" must come FIRST. Clears → Hashing + Two-Pointers L5. |
| **2026-06-14** | **NEW: restate-the-problem discipline (MISTAKE #10)** | re-test | `/drill` | Q4/Q6 were reading misses. Re-test: a wordy min/max-of-something or k-th-something statement restated in one sentence + 3-elem dry run BEFORE naming any pattern. |
| **next session** | **Finish drill tail: Q5 counting mechanic + Q7 freq-fix + Q8** | resume | `/drill` | Q5: on sorted arr, valid window → bank `hi-lo` pairs, move which pointer? Q7: anagram check needs char FREQUENCY not presence. Q8: longest-consecutive-run = hash-set + walk-from-sequence-starts O(n) (LC128 twin). |
| ✅ 2026-06-12 | ~~Binary Search concept recall (+1d)~~ | done | recall | **PARTIAL 3/4** — monotonicity ✓, store-candidate ✓ (fuzzy), search-on-answer lo/hi ✓ (said "last" not "max"). **OVERFLOW RULE MISSED** (described halving instead of `mid=lo+(hi-lo)/2`) → reset below. |
| **2026-06-13** | **Overflow rule re-test (MISTAKE #8, +1d RESET)** | +1d | recall | Failed to surface 6/12. Closed-book: write the safe mid + say WHY `(lo+hi)/2` dies (sum computed before division, ~3e9 > int max) + when `long long` accumulator is needed. |
| 2026-06-12 | M4 SW + M5 Prefix L5 (next interval +2d) | +2d | `/drill` | Keep L5 warm — re-confirm cold in the next interleaved set (don't let fresh L5 decay). |
| weekend | **2ptr REVISIT: re-code LC75 as Dutch-flag** | revisit | solo | L4 gap — implement the low/mid/high 3-way partition (NOT selection-sort) to cement the technique. + LC42 Trapping (hard). |
| ongoing | **Boundary EXECUTION (WEAK, the #1 leak)** | standing | re-test | Now framed as PROCESS: trust clean template + reason 4 edges before submit (Notes/00 framework). Clears after 2 mediums solved first-submit with zero band-aid patches. |
| after M8 Deques | LC862 Shortest Subarray Sum≥K (**PARKED**) | deferred | hard | Needs monotonic deque. Revisit once M8 is learned — it'll be natural then. |

## Scheduled (upcoming)
| Due date | Topic / Pattern | Interval stage | Last result |
|---|---|---|---|
| 2026-06-07 | Fixed Sliding Window signal | +3d | provisional pass |
| 2026-06-07 | O(log n) analysis reasoning | +3d | provisional pass |
| 2026-06-08 | Prefix Sum formula (meaning) | +3d | **PASS** 6/5 (derived cold, L=0 handled) |
| 2026-06-08 | Variable Sliding Window template | +3d | pass 6/5 (template ✓; min-init slip noted) |

## Completed checkpoints (log)
| Date done | Topic / Pattern | Stage | Result (pass/fail) | Next due |
|---|---|---|---|---|
| 2026-06-05 | Prefix Sum formula (MISTAKE #1 re-test) | re-test | **PASS** (cold, by meaning) | 2026-06-08 |
| 2026-06-05 | Variable Sliding Window | +1d recall | PASS (template ✓; boundary min-init slipped) | 2026-06-08 |
| 2026-06-05 | Boundary/order values | re-test | **FAIL** (recurred 3× today) | 2026-06-06 |
| 2026-06-06 | Prefix+Hash recall (GOAL×KEY) | +1d recall | **FAIL** (count↔longest conflated) | 2026-06-07 |
| 2026-06-06 | Recognition: 3 patterns cold | +1d recall | **FAIL** (Two Sum→"2ptr"; var-window blank) | 2026-06-07 |
| 2026-06-06 | Variable Sliding Window template | +3d | PASS-ish (Q3 ✓ shortest record/shrink) | 2026-06-09 |
| 2026-06-07 | LC238 Product Except Self | new (L4) | PASS (prefix×suffix, fixed own loop-dir bug) | 2026-06-08 |
| 2026-06-07 | LC523 Continuous Subarray Sum | new (L4) | PASS after heavy debug (see MISTAKE #5) | 2026-06-14 (cold re-test) |
| 2026-06-08 | Recognition drill (3 patterns cold) | re-test | **PARTIAL 4/7** — SW 3/3 ✓, prefix 1/2, hashing 0/2 (→"two pointers") | 2026-06-11 re-drill post-hashing |
| 2026-06-08 | LC567 Permutation in String | new (L4, fixed-window) | PASS after 5 attempts (incremental slide; see MISTAKE #6) | 2026-06-15 (cold re-test) |
| 2026-06-08 | M2 Hashing formal lesson + LC1/242/49/128 | new (L3) | PASS coached (bug-heavy; not solo) | 2026-06-09 (+1d recall) |
| 2026-06-08 | M2 Hashing SOLO SET (LC217/219/347/36) | L4 gate | **PASS — all 4 AC SOLO → L4 EARNED** | 2026-06-11 (+3d) |
| 2026-06-09 | M3 Two Pointers solo (LC167/75/283/680) | L4 gate | **PASS (converging) → L4** — LC167 clean solo; LC75 via sorting (gap: Dutch-flag); easies coached | 2026-06-12 (+3d) |
| 2026-06-09 | M6 Binary Search easies (LC704/35) | new (L3) | PASS but reactive band-aid patches (MISTAKE #7) | 2026-06-10 (mediums + clean) |
| 2026-06-10 | M6 BS mediums (LC34 + LC875 Koko) | L4 gate | **PASS → L4** — both AC; band-aids gone; Koko overflow debug (MISTAKE #8) | 2026-06-12 (next search-on-answer) |
| 2026-06-10 | Recognition drill (5 patterns cold, interleaved) | L5 test | **6/7** — M4 SW + M5 Prefix → **L5**; Q7 hashing CORRECT; Q1 unsorted-pair flicker (MISTAKE #9) | 2026-06-14 re-drill |

---

### How a topic moves through this file
```
reaches L3 → add at +1d (Scheduled)
   ↓ due today → move to Due → run closed-book recall
       pass → log Completed, schedule next interval (+3d, then +7d, …)
       fail → log Completed(fail), reschedule +1d, flag weak in PROGRESS.md
```
