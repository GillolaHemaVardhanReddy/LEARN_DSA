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
| 2026-06-07 | Prefix Sum + Hash (GOAL×KEY) | +1d (RESET) | recall | **FAILED closed-book 6/6** — applied LONGEST machinery to a COUNT problem; said "count doesn't use a map". Re-test via the GOAL(count→freq,seen[0]=1 / longest→first-index,seen[0]=-1) × KEY(complement/remainder/equal) map. Then solve LC560+LC525 from scratch. |
| 2026-06-07 | Recognition: 3 patterns cold | +1d (RESET) | recall | **FAILED 6/6** — misclassified unsorted Two Sum as "two pointers" (it's HASHING); couldn't reconstruct variable window. Re-test = name pattern + cue on a mixed set (/drill). |
| 2026-06-07 | Boundary/order values (**WEAK**) | re-test | re-test | seen[0] meaning still memorised not understood (count=1 vs longest=−1). Clears after 2 clean mediums. |

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

---

### How a topic moves through this file
```
reaches L3 → add at +1d (Scheduled)
   ↓ due today → move to Due → run closed-book recall
       pass → log Completed, schedule next interval (+3d, then +7d, …)
       fail → log Completed(fail), reschedule +1d, flag weak in PROGRESS.md
```
