# SPRINT_PLAYBOOK.md — How Hema Vardhan & Kera Run Each Topic

> The repeatable loop for the 6-day sprint (2026-06-04 → 06-09) and beyond.
> Goal per topic: reach **L4** — "if I think hard, I can solve mediums here."

---

## The 7-step TOPIC LOOP (every topic goes through this in order)

### 1. LEARN (concept) — ~20–40 min
- Kera teaches **just-in-time**, no bloated lecture: why it exists → intuition +
  visualization → mechanics → the reusable **template** → complexity → the **pattern cue**.
- **Gate L2:** Hema explains the idea back in his own words + follows one dry run. No
  advancing until this passes.

### 2. NOTES (Hema writes, in his own words) — ~10 min
- Hema fills the topic's entry in `PATTERN_JOURNAL.md`: **trigger** ("when I see ___ →
  reach for ___"), why it works (1 line), template, complexity, gotchas.
- Writing it yourself = the encoding step. Kera only corrects, never pre-fills.

### 3. IMPLEMENT THE TEMPLATE FROM MEMORY — ~10 min
- Hema codes the bare pattern skeleton **closed-book** in C++.
- **Gate L3:** correct from memory once → topic enters `REVISION_QUEUE.md` (+1d).

### 4. PROBLEM SET (the reps) — the bulk of the time
- Kera gives problems **one at a time**, easy → medium, via the **Problem-Solving Loop**:
  Restate → Constraints/edge cases → Brute force + complexity → Bottleneck →
  Pattern hunt → Optimal → Complexity → Implement → Test.
- **Hint ladder** (Hema asks; Kera never front-runs it):
  L1 nudge · L2 name the pattern · L3 approach in words · L4 pseudocode · L5 full code.
  Typing `STUCK` advances exactly one level.

### 5. SOLVE & SUBMIT (Hema)
- Code in C++ on onlinegdb, then submit on **LeetCode = ground truth**.
- "Solved" = **Accepted on the judge**, never Kera's approval alone.
- Save each solution to `solutions/<module>/<problem>.cpp`.

### 6. EVALUATE (Kera — Code Review Mode)
- Review like a senior eng: correctness · time/space complexity · edge cases ·
  readability/naming · 1–2 concrete optimizations. Confirm the judge accepted it.
- **Per-problem scorecard** (1–5 each): Communication · Decomposition · Complexity
  accuracy · Code quality · **Independence** (max hint level used — lower = better).
- Then **extract the cue** → update `PATTERN_JOURNAL.md`. Any error → `MISTAKE_JOURNAL.md`.

### 7. GATE & LOG
- **L4 evidence:** ≥2 easy + ≥2 medium solved largely independently (hints ≤ L2).
- **L5 check (later, via revision):** name the pattern cold on an unseen problem.
- Update `PROGRESS.md` levels (with evidence) + `REVISION_QUEUE.md` checkpoints. Commit.

---

## HOW MANY PROBLEMS PER TOPIC (sprint dosage)

| Slot | Count | Purpose |
|---|---|---|
| Template implementation | 1 | L3 gate (from memory) |
| Easy | 2 | mechanics + confidence |
| Medium | 2–3 | the real target (L4) |
| Unseen "boss" check | 1 | recognition (L5 evidence, often deferred to revision) |
| **Total** | **~6–8** | enough for L4, not busywork |

Quality over count: a problem fully reasoned + reviewed + cue-extracted beats five rushed ACs.

---

## SPACED REVISION (runs alongside, daily)
- Each day **opens** with whatever is due in `REVISION_QUEUE.md` — **closed-book first**.
- Checkpoints: +1d, +3d, +7d, +14d, +30d, +90d. Pass → next interval; fail → reset +1d + flag weak.
- Reviews are **interleaved** (mixed topics) — this is what trains *recognition*, the whole point.

## DRILLS (`/drill`)
- Once 4+ patterns are L3+, run mixed **name-the-pattern-only** drills (no full coding).
  Cheap, fast, highest-ROI habit for the FAANG recognition bar.

---

## FILES = MEMORY (where everything lands)
- `PATTERN_JOURNAL.md` — your cue cheat-sheet + templates (you write these).
- `MISTAKE_JOURNAL.md` — every error: root cause + re-test date.
- `REVISION_QUEUE.md` — what's due when.
- `PROGRESS.md` — levels + session log (the audit trail).
- `solutions/<module>/` — your actual C++ code.
- Commit at every session end — the git history IS the progress log.
