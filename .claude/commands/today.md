---
description: Run today's 3-slot dose (RECALL → BUILD → LOOK BACK) — the v2 daily habit
argument-hint: "[optional: 'floor' for the 10-min minimum day | 'resume']"
---
Run the 3-slot day per `.claude/CLAUDE.md` §3 and `dashboard/PLAN.md` §4.
1. Read `dashboard/README.md` (TODAY), `dashboard/REVISION_QUEUE.md` (due rows), `dashboard/PROGRESS.md` (head), and the latest 2 entries of `dashboard/LOG.md`. Print exactly 4 lines: **why today matters** (today → Friday checkpoint → tier gate → month-7 bar), days kept x/7 · n/66, what's due, next contest. No dashboard wall.
2. **RECALL (10 min):** 1–2 due items, a different topic than today's BUILD. Seed every statement with 2–3 examples. Marks only; reveal after.
3. **BUILD (30 min, cap):** ONE problem in the current topic. Scaffold it just-in-time (one problem, real LC signature via MCP). Gate A first (restate in units + 3-elem dry run + the 4 disqualifier questions before any tool is named). LEARN = brute → bridge → optimal; REP = solve → LC verdict → look back. ≤1 hint then silence; `STUCK` = one level.
4. **LOOK BACK (5 min):** complexity as a sentence with the work in it; cue into `dashboard/PATTERN_JOURNAL.md` ending "reduces to ___"; ladder dates into `REVISION_QUEUE.md`.
5. **At the cap, stop** — write the resume line into README TODAY, then run `/endsession`.
If `$ARGUMENTS` is `floor`: do slot 2 only as one card (≤10 min), mark the day kept, `/endsession`. If boss missed 2+ days: open with ONE 5-min card, no backlog, no guilt.
