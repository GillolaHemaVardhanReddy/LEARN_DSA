# 🗂️ PHASE 1 — ONE-PLACE MAP + the skeleton Phase 2 copies

> **Phase 1 = the linear/array patterns (M1–M7).** This file is the single index of *everything*
> Phase-1: notes, guided solves, practice sets, drills, the hard gauntlet, cold tests. Built
> 2026-06-30 when we consolidated all the scattered hards into one home. **Phase 2 just clones the
> "Per-pattern skeleton" below — same folders, new topic numbers.**

---

## The 7 patterns of Phase 1
M1 Complexity · M2 Hashing · M3 Two Pointers · M4 Sliding Window · M5 Prefix Sum ·
M6 Binary Search · M7 Stacks & Monotonic Stack.
Levels live in `PROGRESS.md`; recognition cues in `PATTERN_JOURNAL.md`.

## Where every Phase-1 asset lives

| Layer | Path | Holds |
|---|---|---|
| **Notes** | `Notes/00-Recognition-Map.md` → `Notes/07-Stacks-Monotonic.md` | plain-English study notes per pattern (+ the cross-pattern recognition map) |
| **LEARN** (guided) | `learn/04-Sliding-Window/`, `learn/05-Prefix-Sum/`, `learn/07-Stacks/` | first-time Socratic solves, brute→bridge→optimal |
| **PRACTICE** (topic sets) | `practice/01-Prefix-Sum/` … `practice/06-Stacks-Monotonic/` | per-pattern reps: 2 easy + 2 medium each (hards moved out → gauntlet). `solo-set/` = the L4-gate sets |
| **PRACTICE** (drills) | `practice/drills/01-mixed-gauntlet/` (24 disguised recognition Qs, easy→med) · `02-monotonic-stack/` (4 stack flavors) · **`03-hard-gauntlet/`** (all Phase-1 hards, one place) | calibration + disguised recognition + the hard stretch |
| **TEST** (cold) | `test/cold-recognition/` | closed-book, the only L4→L5 path |

## The hard gauntlet (the consolidated hard home)
`practice/drills/03-hard-gauntlet/` — see its `README.md`. 8 active hards (one+ per pattern that has
one) + LC862 parked for Phase 2 (needs deque). This replaced the old scattered `practice/<topic>/
05-hard-*` folders and `drill1`'s p25–p30 tail (removed 2026-06-30, were empty dups).

---

## ⭐ PER-PATTERN SKELETON — what Phase 2 copies for each new topic
For every new Phase-2 pattern (M8 Queues/Deque, M9 Recursion, …), clone this exact shape:

```
Notes/<NN>-<Topic>.md                              ← study notes (write during LEARN)
learn/<NN>-<Topic>/<NN>-<Problem>/                 ← guided first solves
     ├── problem.md      (Kira writes the frame)
     └── solution.cpp    (you write: BRUTE → BRIDGE → OPTIMAL → STRESS)
practice/<NN>-<Topic>/                             ← reps (NO level promotion)
     ├── 01-easy-<slug>/        02-easy-<slug>/
     ├── 03-medium-<slug>/      04-medium-<slug>/
     └── solo-set/              (the L4-gate cold set)
practice/drills/<NN>-<topic>/                      ← optional disguised recognition reps
test/cold-recognition/<Problem>/                   ← cold L4→L5 proof
HARDS → add to a Phase-2 hard gauntlet (mirror of drills/03-hard-gauntlet)
```

**Standing `solution.cpp` structure (never changes):** `BRUTE` (you fill first, it's the stress
oracle) → **The Bridge** (3 Qs in your words: where's the repeated work? what's recomputed? what tool
kills it?) → `OPTIMAL` (real LC name + Time/Space) → `main()` STRESS (brute vs optimal, random ~50k).

**Phase boundaries (so the map stays clean):**
- **Phase 1 = M1–M7** (this file) — linear/array patterns. ✅ basically complete.
- **Phase 2 = M8 Queues/Deque → M9 Recursion → M10 Backtracking → M11 Linked Lists** — clone the
  skeleton above per topic; hards go to a `practice/drills/04-phase2-hard-gauntlet/`.
- Build a `PHASE_2_MAP.md` from this template when Phase 2 opens.
