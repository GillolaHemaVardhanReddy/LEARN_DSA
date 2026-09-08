---
description: Save all progress to the dashboard files and ship it (add + commit + push, verified)
---
End the session per `.claude/CLAUDE.md` §8. Update only what actually happened — never inflate a level:
1. `dashboard/README.md` TODAY — resume line, this week, days kept (mark today **kept** if ≥ the floor was done, **build day** if a BUILD was attempted; once per date), next contest, anchor.
2. `dashboard/PROGRESS.md` — level changes **with evidence**, the habit row (kept days · build days · repair token), counters, leak board dates.
3. `dashboard/LOG.md` §1 — one dated block **inserted directly under the marker line beneath `## 1. Session log`** (newest first). Format: `YYYY-MM-DD — <mode/topic> | Did: … | Levels: … (+ evidence) | AC: … (LC verdict) | Leaks: fired/held | Next: …`. A second session the same day appends to that day's block.
4. `dashboard/REVISION_QUEUE.md` — ladder dates for every BUILD problem / upsolve (+1d in-BUILD card, +7d weekend re-solve, +30d, +90d cards) and every card result; slide (never drop) anything that won't fit tomorrow's 2 items.
5. `dashboard/PATTERN_JOURNAL.md` (cue / card, "reduces to ___") · `MISTAKES.md` (`V#n`) · `CONTESTS.md` · `LEARNING_PROFILE.md` (experiment log) — as applicable.

## SHIP IT — add + commit + push is ONE atomic move
```
git status -sb          # look at the ?? list BEFORE staging — nothing gets left behind
git add -A
git commit -m "session <YYYY-MM-DD>: <topics> — <what changed>"
git push origin main
git status -sb          # must show: no "ahead by N"  AND  zero ?? lines
```
Only after both checks pass may you say the session is saved. Finish with the single highest-ROI objective for tomorrow (one line).
