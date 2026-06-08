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
| ✅ DONE 2026-06-08 | ~~Hashing SOLO SET (L4 gate)~~ | done | solo | **ALL 4 AC SOLO** (LC217/219/347/36). M2 Hashing → **L4 EARNED**. LC219 cleared drill Q7 (chose hashing, not two pointers). |
| 2026-06-09 | Hashing concept recall (+1d) | +1d | recall | Closed-book: why O(1) avg / O(n) worst? what's a collision & how resolved? the 4 sub-pattern cues (complement/freq/group-by-key/membership)? |
| 2026-06-13+ | **L5 recognition drill (DELAYED + interleaved)** | L5 test | `/drill` | Learner's call (good instinct): do NOT test L5 immediately after L4 — immediate = short-term recall, not transfer. Take a gap + learn M3 Two Pointers first, THEN cold-drill SW/Prefix/Hashing interleaved. Prior 4/7 (hashing 0/2); target ≥6/7 incl. all hashing Qs → that earns L5. |
| 2026-06-08 | Prefix Sum + Hash (GOAL×KEY) | +1d | recall | Heavily reinforced 6/7 (LC238/LC523 AC). Re-test: reconstruct GOAL×KEY cold + solve one prefix problem map-closed. |
| 2026-06-08 | Boundary/INDEX values (**WEAK**, 7×) | re-test | re-test | Recurred 6/7 (LC523 truthiness/overwrite/off-by-one). He now self-IDs them as index bugs. Clears after 2 clean mediums w/ zero index bugs. |
| 2026-06-11 | MISTAKE #6 re-test (hashing recognition) | re-test | recall | After hashing lesson: LC1 Two Sum + LC219 Contains Duplicate II — must reach for hashing, NOT two pointers. |
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

---

### How a topic moves through this file
```
reaches L3 → add at +1d (Scheduled)
   ↓ due today → move to Due → run closed-book recall
       pass → log Completed, schedule next interval (+3d, then +7d, …)
       fail → log Completed(fail), reschedule +1d, flag weak in PROGRESS.md
```
