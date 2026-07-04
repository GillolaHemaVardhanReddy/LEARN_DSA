# Phase 2 — Linear + Recursion  (syllabus)

> Self-contained folder for Phase 2. Structure mirrors `phase-1/`:
> `notes/ learn/ practice/ drills/ test/ syllabus.md mistakes.md`.
> Live cross-phase tracking stays at repo root (COMMAND_CENTER, PROGRESS, etc.).

## Modules
| ID | Module | Status | Notes |
|----|--------|--------|-------|
| M8 | Queues & Deque | **STARTED 2026-07-03** | FIFO/circular buffer + ⭐ monotonic deque (twin of monotonic stack). Trigger: "max/min of EVERY window of size k" → monotonic deque O(n). Payoff: LC239 Sliding Window Maximum. Clears parked LC862. Striver [312]. |
| M9 | Recursion | **NEXT (opens 2026-07-05 AM)** | THE keystone — foundation under Backtracking/Trees/DP. Go slower+deeper. Notes ready (`notes/09-recursion.md`). Striver Step 7 [008–012]. Ladder: print N → 1..N → sum/factorial (param+functional) → reverse/palindrome → Fibonacci (multiple recursion → gateway to trees/DP). Unlock = the "leap of faith" (trust the smaller call). |
| M10 | Backtracking | L0 | Builds on recursion. |
| M11 | Linked Lists | L0 | Fast/slow pointers, reversal. |

## M8 ladder
1. Implement Queue using Stacks (LC232, E) — mechanics → L3
2. Number of Recent Calls (LC933, E) — plain queue
3. ⭐ Sliding Window Maximum (LC239, H) — the canonical monotonic-deque problem, learned here
- **Gate:** explain why the deque keeps the window's extreme in O(1) amortized.
