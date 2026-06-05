---
description: Generate today's cold interleaved practice set (1 easy + 1 medium, recognition-first)
argument-hint: "[optional: focus pattern, or 'add-hard']"
---
Generate the next daily practice set per `CLAUDE.md` §8 (spaced + interleaved + retrieval)
and §9 (recognition is the priority). This is **revision practice**, distinct from learning
new topics.

## Steps
1. Read `PROGRESS.md` (which patterns are **L3+** — only those are eligible), `PATTERN_JOURNAL.md`
   (the cues), and `practice/PRACTICE_LOG.md` (problems already used + the last `day-NN`).
2. Compute the next day number `NN`.
3. **Difficulty mix:** 2 **Easy** + 2 **Medium** by default. Add a 3rd **Hard** ONLY when the
   learner is L4+ on ~5–6 patterns (or if `$ARGUMENTS` contains `add-hard`). Until then, no hard.
4. **Pick the problems COLD and INTERLEAVED:**
   - Draw from *different* L3+ patterns when possible (one problem per pattern), to force
     recognition rather than streak-matching.
   - **Never name the pattern** anywhere in the generated files — the learner must classify it.
   - **No repeats** — exclude anything in `PRACTICE_LOG.md`, the per-module practice queues,
     or already-solved lists in `PROGRESS.md`.
   - If `$ARGUMENTS` names a focus pattern, weight toward it but keep the set mixed.
5. **Scaffold** `practice/day-NN/` with one folder per problem:
   `practice/day-NN/01-easy-<slug>/` and `practice/day-NN/02-medium-<slug>/` (+`03-hard-<slug>/`
   when unlocked). Each folder gets:
   - `problem.md` — LeetCode link, plain-English statement, examples, constraints, and a blank
     **"YOUR recognition work"** block (brute force + bottleneck + *which pattern + what cue* +
     optimal) plus a result log. **Do NOT reveal the pattern.**
   - `solution.cpp` — the exact LeetCode signature, a bare `// YOUR CODE HERE`, and a `main()`
     local test harness with expected outputs. No approach hints.
6. Append the chosen problems to `practice/PRACTICE_LOG.md` (date, day-NN, problem, difficulty,
   the pattern it *actually* is — for the mentor's eyes, the learner works from the cold file).
7. Tell the learner the set is ready, point to the folders, and remind them to fill the
   recognition block **before** coding. Offer to review on request. Do not commit unless asked
   (or fold into `/endsession`).
