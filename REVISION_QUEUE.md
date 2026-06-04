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
| 2026-06-05 | Prefix Sum formula (meaning, not shape) | re-test | re-test (MISTAKE #1) | Derive cold on LC 724 Pivot Index; then 1 more prefix problem |
| 2026-06-05 | Variable Sliding Window | +1d | recall | Reconstruct grow/shrink template closed-book (taught + LC209 AC on 6/4) |
| 2026-06-05 | Boundary/order values (**WEAK**, recurred 3×) | re-test | re-test (MISTAKE #2) | LC1004 done but off-by-one recurred. Re-test = next medium solved with ZERO boundary bugs; run the pre-code boundary checklist. Clears after 2 clean. |

## Scheduled (upcoming)
| Due date | Topic / Pattern | Interval stage | Last result |
|---|---|---|---|
| 2026-06-07 | Fixed Sliding Window signal | +3d | provisional pass (revision Q3) |
| 2026-06-07 | O(log n) analysis reasoning | +3d | provisional pass (revision Q1) |

## Completed checkpoints (log)
| Date done | Topic / Pattern | Stage | Result (pass/fail) | Next due |
|---|---|---|---|---|
| — | — | — | — | — |

---

### How a topic moves through this file
```
reaches L3 → add at +1d (Scheduled)
   ↓ due today → move to Due → run closed-book recall
       pass → log Completed, schedule next interval (+3d, then +7d, …)
       fail → log Completed(fail), reschedule +1d, flag weak in PROGRESS.md
```
