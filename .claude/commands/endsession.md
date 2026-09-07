---
description: Save all progress to the dashboard files and ship it (add + commit + push, verified)
---
End the session per `.claude/CLAUDE.md` §8. Update only what actually happened — never inflate a level:
1. `dashboard/README.md` TODAY — resume line, this week, days kept (mark today kept if ≥ the floor was done), next contest.
2. `dashboard/PROGRESS.md` — level changes **with evidence**, habit row, counters, leak board dates.
3. `dashboard/LOG.md` §1 — one dated block: what we did · levels changed (+ evidence) · problems AC (LC verdict) · leaks fired/held · next.
4. `dashboard/REVISION_QUEUE.md` — ladder dates for every AC / card result; prune if > 3 due tomorrow.
5. `dashboard/PATTERN_JOURNAL.md` (cue / card, "reduces to ___") · `MISTAKES.md` · `CONTESTS.md` · `LEARNING_PROFILE.md` (experiment log) — as applicable.

## SHIP IT — add + commit + push is ONE atomic move
```
git status -sb          # look at the ?? list BEFORE staging — nothing gets left behind
git add -A
git commit -m "session <YYYY-MM-DD>: <topics> — <what changed>"
git push origin main
git status -sb          # must show: no "ahead by N"  AND  zero ?? lines
```
Only after both checks pass may you say the session is saved. Finish with the single highest-ROI objective for tomorrow (one line).
