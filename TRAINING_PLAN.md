# TRAINING PLAN — Becoming a Strong Problem Solver (Hema Vardhan)

> Kira's plan, not a mirror of requests. Written 2026-06-13. Pairs with
> `drill1/PRACTICE_PROTOCOL.md` (per-problem mechanics) and the state files
> (`PROGRESS.md`, `PATTERN_JOURNAL.md`, `MISTAKE_JOURNAL.md`, `REVISION_QUEUE.md`).

---

## 1. Honest diagnosis — where you actually are (and what's really blocking you)

Your **pattern recognition is already good** — L4 across all five patterns, 6/7 cold on the
last drill. More disguised-recognition reps alone will NOT make you FAANG-ready, because
recognition isn't the bottleneck. Four things actually are:

1. **Execution cleanliness (your #1 chronic leak).** Logic right, *edges* wrong —
   first-element, off-by-one, sentinel, overflow/magnitude. This loses real interviews.
2. **Two reflex misfires.** (a) unsorted pair → reach for sort+two-pointers (MISTAKE #9, 4×);
   (b) the *inverse* — over-applying hashing on **sorted** data (drill1 P2). The disqualifier
   gate ("is it sorted? what does sorting cost me?") is not yet automatic.
3. **C++ fluency** — a *separate* skill from DSA. Primitive gaps (copy a vector, overflow
   types) blindside you mid-problem and *feel* like DSA failure. They are not.
4. **First-instinct discipline** — skipping "restate + dry-run" under pressure (cost you Q4/Q6).

**So this plan weights toward execution + reflex repair + C++ fluency — not just more recognition.**

---

## 2. Two parallel tracks

- **Track 1 — Problem solving (the drills).** ~85% of time. Recognition, design, optimal coding.
- **Track 2 — C++ fluency (the gaps log).** ~10 min/session. Every primitive gap that surfaces
  (vector copy, `long long`, iterators, `unordered_map` idioms, sort comparators…) gets logged
  to a running `CPP_GAPS.md` with the one-liner that fixes it. A vocabulary gap ≠ a thinking
  failure. Reviewing it weekly stops the same gap blindsiding you twice.

---

## 3. What "strong" means — measurable bars (track in PROGRESS.md)

| Dimension | Weak (now) | Strong (FAANG-ready) |
|---|---|---|
| Recognition (first instinct, before hints) | ~6/7, reflexes misfire | ≥ 95% cold, gates automatic |
| First-submit-clean (no band-aid patches) | rare | majority of mediums |
| Boundary/overflow bugs | recurring | ~zero (checklist internalized) |
| Brute→optimal articulation | improving | states bottleneck + cue every time |
| Medium independence | partial | solves cold, no hints |
| Communication (think aloud) | untested | clear decomposition, interview-ready |

The boundary leak **clears** when you hit **2 consecutive mediums first-submit-clean**.

---

## 4. Drill architecture — the repeating cycle

```
PRACTICE 1  →  PRACTICE 2  →  PRACTICE 3  →  TEST  →  (escalate)  →  repeat
```

- **PRACTICE drills** (learning mode): full `PRACTICE_PROTOCOL.md` loop — brute → bottleneck →
  pattern hunt → optimal → compare. Hints ≤4 then full explanation. Deep on mediums/hards,
  light on easies.
- **TEST drill** (assessment, every ~4th): no scaffolding, no hints, cold recognition + optimal
  directly, graded vs an explicit pass bar. **This is the only thing that promotes a level.**
- **Escalation:** pass a TEST well → next practice block drops easies, hardens mediums, adds
  multi-tool hards. Stall on a TEST → repeat that block, targeted at the failing dimension.

Every drill is **interleaved** (mixed patterns) — that's what trains *which tool applies*.

---

## 5. The macro arc — phases

- **Phase 0 — CONSOLIDATE (now).** Finish `drill1`. Goal: fix the two reflexes, clean execution,
  build the brute→optimal habit on the 5 known patterns. Not about new content.
- **Phase 1 — PROVE.** A TEST drill on the 5 patterns. Patterns named cold + first-submit-clean
  → earn **L5**. (This is how SW/Prefix/Hashing/2ptr/BS finally convert from L4.)
- **Phase 2 — Monotonic Stack.** Striver → teach → dedicated practice drill → fold into mixed drills.
- **Phase 3+ — Roadmap (NeetCode-150 scope), one topic at a time, each via the same pipeline**
  (Striver → teach → practice drill → interleave + spaced tests):
  Queues/Deque → Recursion → Backtracking → Linked Lists → Trees → BST → Heaps →
  Graphs/BFS-DFS → Topo/Union-Find → DP (1D→2D) → Greedy → Intervals.
- **Endgame — MOCKS.** Timed `/interview` sessions: communication, decomposition, hire-call feedback.

New topics always **fold back** into mixed drills so old patterns stay warm (spaced + interleaved).

---

## 6. Weekly cadence (honors the agreed rhythm)

- **Weekdays:** L4 work — easies + mediums via practice drills (~3h/day).
- **Weekends:** hard problems + a TEST drill or mock (~5h/day).
- **L5:** earned only via spaced TEST drills, never immediately after L4 (same-day = recall, not transfer).
- **Every session:** 10 min Track-2 (C++ gaps review) + whatever's due in `REVISION_QUEUE.md`.

---

## 7. The deliberate-practice rules (non-negotiable, every problem)

1. **Restate + dry-run BEFORE naming a pattern.** No exceptions. (Kills the Q4/Q6 failure mode.)
2. **Run the gates aloud.** Sorted? → 2ptr/BS possible. Unsorted pair/dup? → hashing.
   Negatives/±1? → prefix+hash. Say the disqualifier first.
3. **Brute force first in practice** (baseline + exposes the bottleneck). On a TEST, go straight to optimal.
4. **Boundary checklist before every submit** (empty/single/first&last/overflow). No band-aid patches.
5. **Extract the cue** → `PATTERN_JOURNAL.md`. Every bug → `MISTAKE_JOURNAL.md` (root cause + re-test).
6. **Re-derive after any tap-out.** A given answer doesn't count until you rebuild it cold.
7. **The judge is truth.** "Solved" = Accepted on LeetCode, not Kira's approval.

---

## 8. Anti-frustration rules (because this is a marathon)

- One problem at a time. No obligation to finish a batch in a sitting.
- A C++/primitive gap is a *win* (found cheaply), not a failure — log it, move on.
- When stuck, the hint ladder exists — use it; asking is not weakness.
- We never delete progress over a bad moment. Reset, cool mind, continue.
