---
description: Log a contest and scaffold the one upsolve; or show the next contest times
argument-hint: "[next | log]"
---
**Calendar (IST):** LC Weekly every **Sunday 08:00**; LC Biweekly every 14 days from the anchor **Sat 2026-09-12 20:00** (Biweekly 191); CodeChef Starters **Wed 20:00** from month 2 (Oct 2026); Codeforces Div 3/4/Edu **~20:05** from month 3 (Dec 2026; create the handle in Nov); GFG weekly paused (Kira re-checks monthly). Facts + handles live in `dashboard/CONTESTS.md`.
If `$ARGUMENTS` is `next` (or no contest just happened): print the next Weekly and Biweekly dates computed from the anchors, plus the other platforms once their month arrives. Remind: full 90 min, all 4 attempted, no help, disqualifier gate before each problem.
Otherwise **log** the contest per `dashboard/PLAN.md` §6:
1. Ask for solved count, time per problem, contest name, rating after (or fetch via MCP `get_user_contest_ranking` for `hemavardhan2076`). Append a row to `dashboard/CONTESTS.md` (log + rating history).
2. **One same-day receipt before any verdict** (calibration leak — 2026-06-20 precedent).
3. Every unsolved problem → one card in `dashboard/PATTERN_JOURNAL.md` tagged by why: reading / routing / machinery / execution / speed — or **unopened topic** (a tool from a tier not yet reached: logged "not yet", **no card**, never a recognition miss).
4. Scaffold **exactly one upsolve per weekend** — the easiest unsolved *within opened topics* (none ⇒ the easiest at most one tier ahead, taught just-in-time, or logged out-of-scope) — in `tests/contests/<YYYY-MM-DD>-<contest>/` (statement with the contest examples, real signature, bare file). Kira coaches at ≤1 hint; due within 48 h; the upsolve enters the ladder.
5. Update README TODAY, then `/endsession`.
