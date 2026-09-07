---
description: Log the mistake we just hit — root cause + corrected model + re-test date
---
Append a v2 entry (`#14, #15, …`) to `dashboard/MISTAKES.md`: the wrong move, the ROOT cause (a mental-model error, never "careless"), the corrected model, a prevention rule, an unseen re-test problem + date, and the one-line "which gate would've caught this?". Add the re-test to `dashboard/REVISION_QUEUE.md` and update the leak board in `dashboard/PROGRESS.md`. If this root cause has fired 3×, promote it to the watchlist + the kryptonite pre-load (Gate 1). Commit via `/endsession`.
