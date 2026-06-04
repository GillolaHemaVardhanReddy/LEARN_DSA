---
description: Save all progress to the state files and commit
---
End the session per `CLAUDE.md` §12. Update **all** state files to reflect what actually
happened this session — only record evidence you genuinely witnessed, never inflate a level:

1. `PROGRESS.md` — level changes **with the evidence** that justified each, a dated
   session-log line (date, what we did, problems solved), and a refreshed schedule projection.
2. `PATTERN_JOURNAL.md` — new or updated recognition triggers and templates.
3. `MISTAKE_JOURNAL.md` — any new mistakes (root cause + re-test + re-attempt date).
4. `REVISION_QUEUE.md` — new spaced-repetition checkpoints and any resolved items, with dates.

Then stage and commit:
`git add -A && git commit -m "session <YYYY-MM-DD>: <modules touched> — <level changes>"`

Finish by stating the single highest-ROI objective for the next session.
