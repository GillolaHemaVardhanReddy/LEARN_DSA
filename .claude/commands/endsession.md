---
description: Save all progress to the state files and commit
---
End the session per `CLAUDE.md` §12. Update **all** state files to reflect what actually
happened this session — only record evidence you genuinely witnessed, never inflate a level:

1. `PROGRESS.md` — level changes **with the evidence** that justified each, a dated
   session-log line (date, what we did, problems solved), and a refreshed schedule projection.
2. `PATTERN_JOURNAL.md` — new or updated recognition triggers and templates.
3. `phase-N/mistakes.md` (current phase folder) — any new mistakes (root cause + re-test + re-attempt date).
4. `REVISION_QUEUE.md` — new spaced-repetition checkpoints and any resolved items, with dates.
5. `COMMAND_CENTER.md` — leak scoreboard / first-submit-clean streak / today's plan.

## SHIP IT — add + commit + push is ONE atomic move (non-negotiable)

Never stop at commit. A commit that isn't on `origin` doesn't exist, and a file that was never
staged doesn't exist either — both end with boss's work stranded on one laptop.

```
git status -sb          # LOOK at the untracked (??) list BEFORE staging — nothing gets left behind
git add -A
git commit -m "session <YYYY-MM-DD>: <modules touched> — <level changes>"
git push origin main
```

**Then VERIFY, don't assume.** Re-run `git status -sb` and require BOTH:
- `## main...origin/main` with **no** "ahead by N" — everything is pushed.
- **Zero `??` lines** — nothing untracked. If a file is deliberately excluded, gitignore it;
  never leave it dangling.

Only after both checks pass may you report the session as saved. Do not say "committed and
pushed" unless you ran the verification and saw it.

Finish by stating the single highest-ROI objective for the next session.
