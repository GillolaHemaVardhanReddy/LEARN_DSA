# PHASE 1 — SYLLABUS COVERED (Linear / Array patterns · M1–M7)

> The body of work this folder holds. Levels are the live ones from root `PROGRESS.md`
> (single source of truth); this is the "what we covered" map for the phase.

## Patterns

| ID | Pattern | Level | Covered | Key problems solved |
|----|---------|-------|---------|---------------------|
| M1 | Complexity Analysis | L3* | O(1)→O(n²), log-rule, Ω/O/Θ, constraints→target-complexity | (folds into every problem) |
| M2 | Arrays & Hashing | **L4** | complement / frequency / group-by-key / membership; bucket & counting sort | LC1, 242, 49, 128, 217, 219, 347, 36 |
| M3 | Two Pointers | **L4** | converging · same-direction · Dutch-flag (gap) | LC167, 11, 15, 125, 977, 283, 680, 75 |
| M4 | Sliding Window | **L5** ✅ | fixed window · variable window · derive-don't-maintain | LC209, 3, 1004, 567, 438, 904 |
| M5 | Prefix Sum | **L4** | running sum · prefix+hash (GOAL×KEY) · prefix-MOD | LC560, 974, 525, 724, 238, 523, 1590 |
| M6 | Binary Search | **L4** | exact · predicate · search-on-answer · rotated · discard-ability | LC704, 35, 34, 875, 33, 153, 162, 1011 |
| M7 | Stacks & Monotonic | **L4** ✅ | plain stack · monotonic (NGE/temps) · circular · min-stack · 132 · greedy-build | LC20, 739, 503, 155, 456, 219, 402, 1047, 682, 735 |

> Only **M4 Sliding Window** is a confirmed L5. The rest are L4 (the Phase-1 bar). L5 on the top
> patterns comes via the cold TEST drill (`test/`) — the only L4→L5 path.

## What's in this folder
- `notes/` — plain-English study notes per pattern (`00-Recognition-Map` … `07-Stacks-Monotonic`).
- `learn/` — first-time guided solves (Socratic, brute→bridge→optimal).
- `practice/` — per-pattern rep sets (2 easy + 2 medium each) + `solo-set/` L4 gates.
- `drills/` — `01-mixed-gauntlet` (24 disguised recognition Qs) · `02-monotonic-stack` (4 stack flavors)
  · `03-hard-gauntlet` (every Phase-1 hard, one home).
- `test/` — cold closed-book recognition (the L4→L5 proof).
- `mistakes.md` — every mistake hit during Phase 1 (root cause + re-test).
- `syllabus.md` — this file.

## Still owed in Phase 1 (before it's fully closed)
- **Hard gauntlet** (`phase-1/drills/03-hard-gauntlet/`) — 8 hards to grind (weekend cadence).
- **L5 push** — cold TEST drill on the top patterns.
- A few mistake re-tests (see `mistakes.md` + root `REVISION_QUEUE.md`): #9, #10, #11, #12; Stock Span.
- **LC862** (prefix+deque) is parked → it rides into Phase 2 once M8 Deque is learned.

## ▶️ Phase 2 = copy this exact folder
`phase-2/` mirrors this skeleton: `notes/ learn/ practice/ drills/ test/ mistakes.md syllabus.md`.
Patterns: M8 Queues/Deque → M9 Recursion → M10 Backtracking → M11 Linked Lists.
