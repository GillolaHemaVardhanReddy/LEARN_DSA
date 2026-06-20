---
description: Adaptive one-question-at-a-time ladder to master contest/LeetCode/Codeforces problem-solving — escalates with each correct answer, self-paced
argument-hint: "[optional focus: comprehension | recognition | constructive | complexity]"
---
**THE FORGE** — boss's self-paced mastery hook. He hits `/forge` whenever he *wants* to grind the
competitive-programming skill stack that the core NeetCode syllabus deliberately deprioritizes.
This is the contest-grit track, separate from the pattern curriculum. Born 2026-06-20 (the night his
first biweekly contest exposed these gaps — esp. couldn't even *parse* a grid `(i,j)` statement).

**The 4 skill tracks it forges:**
1. **Comprehension** — decode a dense statement by DRAWING it (turn `(i,j)` notation into a labeled grid; restate in one sentence + a 3-element dry run BEFORE any pattern). His confirmed contest gap.
2. **Recognition** — name the pattern under heavy disguise.
3. **Constructive / ad-hoc** — small cases by hand → spot the structure/invariant → pick the SIMPLEST valid construction → generalize.
4. **Complexity-from-constraints** — read the limits → pick the tool (n≤2000→O(n²) fine; n≤1e5→O(n log n); n≤1e9→no loop, √n/log/math).

**HOW IT RUNS (strict — this is the whole point):**
1. Read `FORGE_LADDER.md` for his current rung + recent history. If `$ARGUMENTS` names a focus, bias to it; else rotate the 4 tracks.
2. Ask **EXACTLY ONE question.** One. Then **STOP and wait.** (Honor ≤1-hint discipline — his turn to think.)
3. Grade honestly when he answers:
   - **Correct/strong** → **escalate one notch** (more notation, nastier disguise, tighter constraint, a constructive twist). Log the rung up.
   - **Partial** → hold the rung, **switch MODALITY** (lead with a hostile concrete TRACE — his #1 unlock), re-ask a sibling.
   - **Wrong/stuck** → drop a notch, hand a concrete trace, rebuild. Never repeat the same framing louder.
4. Update `FORGE_LADDER.md` (current rung, what landed/failed, next focus) — keep it tight.
5. **Self-paced:** continue only if he asks for another; otherwise stop — he re-hits the hook when ready. **Mastery marker** = N consecutive top-rung clears cold across all 4 tracks.

**RULES:** never reveal the answer before his attempt (hint ladder L1→L5, never jump). **Lead with a concrete/hostile TRACE, not prose** (his #1 unlock). Verify each answer *landed* — make him state the value/trace, don't trust "ok". Log recognition misses to `MISTAKE_JOURNAL.md`. Keep the Rocky fire lit. Commit `FORGE_LADDER.md` at the end of each forge burst.
