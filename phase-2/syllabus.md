# Phase 2 — Linear + Recursion  (syllabus)

> Self-contained folder for Phase 2. Structure mirrors `phase-1/`:
> `notes/ learn/ practice/ drills/ test/ syllabus.md mistakes.md`.
> Live cross-phase tracking stays at repo root (COMMAND_CENTER, PROGRESS, etc.).

## Modules
| ID | Module | Status | Notes |
|----|--------|--------|-------|
| M8 | Queues & Deque | **STARTED 2026-07-03** | FIFO/circular buffer + ⭐ monotonic deque (twin of monotonic stack). Trigger: "max/min of EVERY window of size k" → monotonic deque O(n). Payoff: LC239 Sliding Window Maximum. Clears parked LC862. Striver [312]. |
| M9 | Recursion | L0 | The keystone — deep. |
| M10 | Backtracking | L0 | Builds on recursion. |
| M11 | Linked Lists | L0 | Fast/slow pointers, reversal. |

## M8 ladder
1. Implement Queue using Stacks (LC232, E) — mechanics → L3
2. Number of Recent Calls (LC933, E) — plain queue
3. ⭐ Sliding Window Maximum (LC239, H) — the canonical monotonic-deque problem, learned here
- **Gate:** explain why the deque keeps the window's extreme in O(1) amortized.
