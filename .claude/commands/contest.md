---
description: Log a contest and scaffold the one upsolve; or show the next contest times
argument-hint: "[next | log]"
---
If `$ARGUMENTS` is `next` (or empty and no contest just happened): print the next LeetCode Weekly (Sun 08:00 IST) and Biweekly (alternate Sat 20:00 IST), plus CodeChef Starters (Wed 20:00 IST, from month 2) and Codeforces (~20:05 IST, from month 3), from `dashboard/CONTESTS.md`. Remind: full 90 min, all 4 attempted, no help, disqualifier gate before each problem.
Otherwise **log** the contest per `dashboard/PLAN.md` §6:
1. Ask for: solved count, time per problem, the LC contest name, rating after (or fetch via MCP `get_user_contest_ranking` for `hemavardhan2076`). Append a row to `dashboard/CONTESTS.md` (log + rating history).
2. Scaffold **exactly one upsolve** — the easiest unsolved — in `tests/contests/<YYYY-MM-DD>-<contest>/` (statement seeded with the contest examples, real signature, bare file). Kira coaches at ≤1 hint; due within 48 h.
3. Every unsolved problem → one card in `dashboard/PATTERN_JOURNAL.md` (front: disguised statement; back: trigger + idea + why + "reduces to").
4. Calibration line: name one concrete receipt from the contest before any verdict. Update README TODAY, then `/endsession`.
