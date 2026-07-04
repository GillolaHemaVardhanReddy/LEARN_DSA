# Phase 2 — Mistakes (root cause + re-test)

> One entry per mistake: root cause → corrected mental model → re-test problem & date.
> Feeds the leak scoreboard in COMMAND_CENTER.md and the queue in REVISION_QUEUE.md.
> (Phase-1 mistakes live in `phase-1/mistakes.md`.)

### M#1 — "empty-container read returns 0" (2026-07-04, LC933)
- **Root cause:** believed `deque.back()` on an empty container returns `0`. It's **undefined behavior** (garbage/crash), never a clean 0. His #1 boundary/empty-container leak surfacing in C++ form.
- **Corrected model:** before reading an end (`.back()/.front()/.top()`), GUARANTEE non-empty — either `!c.empty()` in the loop guard, or a proven invariant. In LC933 the just-pushed `t ≥ t-3000` is a sentinel that keeps the deque non-empty, so the loop can't pop the last element. He derived this himself once corrected.
- **Re-test:** on LC239 (next), before every `dq.front()`/`dq.back()` read, he states out loud what guarantees it's non-empty. Clears when he guards an end-read unprompted. Also see CPP_GAPS #9.
