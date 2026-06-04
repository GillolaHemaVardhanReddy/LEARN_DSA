# PROGRESS.md — Live Tracker for Hema Vardhan

> The mentor reads this at session start and updates it at session end (via an
> UPDATE BLOCK you paste back, or directly if file-writing is wired up).
> **Every level must be backed by witnessed evidence (see `CLAUDE.md` §6).
> No level is raised without the proof logged in the session log.**

Level key: L0 not started · L1 introduced · L2 understands · L3 implements (from
memory) · L4 applies (≥2 easy + ≥2 medium solo) · L5 recognizes (named cold on
unseen) · L6 teaches. Dashboard %: L0=0, L1=15, L2=35, L3=55, L4=75, L5=90, L6=100.

---

## Learner setup
- Primary language: **C++** (using onlinegdb.com — macOS 26 beta toolchain bug locally; rebuilding fundamentals, self-rated ~4/10)
- Weekly hours available: **~25 hrs/week** (≈3h × weekdays + 5h × weekend days)
- Start date: **2026-06-04**
- Goal bar: majority of medium problems solved independently — **stretch goal: FAANG-level interviews in ~5 months** (FAANG bar leans into some hards + tight communication)
- Target horizon: ~5 months → projected ready ≈ **2026-11-04** (recompute after observing velocity)

## Snapshot
- Current phase: Foundations → Linear patterns
- Current module: **M4 Sliding Window — DONE (L4)**. Next: Day 2 (June 5) M5 Prefix Sum finish.
- Current topic: → Prefix Sum (O(n) hashmap optimization, LC560) next session
- Overall mastery (started topics): ~55% (M4 L4 earned; M1/M2/M5 still provisional/self-reported)
- Observed velocity: Day 1 = 1 pattern to L4 + 3 mediums (heavy one-time setup; expect faster Days 2–6)
- Projected ready date: ~2026-11-04 | vs goal: On track (re-project after Day 3)

> **Levels below are PROVISIONAL (self-reported on transfer 2026-06-04).** Marked `*`.
> They convert to earned levels only as I witness the evidence (§6). First verification: this session's revision.

---

## Topic levels
> One row per module from `CURRICULUM.md`. Update the level + the date + a one-line
> evidence note when it changes. Keep `solved` as `easy/medium` counts.

| ID | Module | Level | Last touched | Solved (E/M) | Evidence note |
|----|--------|-------|--------------|--------------|---------------|
| M1 | Complexity Analysis | L3* | 2026-06-04 | 0/0 | *Self-reported: O(1)→O(n²), log-rule (i*=k→log n), 4 rules, Ω/O/Θ. Verify recall. |
| M2 | Arrays & Hashing | L2* | 2026-06-04 | 0/0 | *Arrays/memory understood (address formula, O(n) shift). HASHING not started (L0). |
| M3 | Two Pointers | L0 | — | 0/0 | Upcoming. |
| M4 | Sliding Window | L4 | 2026-06-04 | 2/3 | **WITNESSED L4**: 3 mediums AC — LC209 (shortest, largely solo), LC3 (longest, +set primitive), LC1004 (≤k-zeros). Recognition + approach independent on all 3. NOTE: execution needed coaching on **boundary/order values** (off-by-one, sentinel, step order) — that's the residual weak area, not the pattern. Fixed-window easies (LC643/1343) self-reported. |
| M5 | Prefix Sum | L3* | 2026-06-04 | 0/0 | *4 problems (range queries, zero-sum count O(n²), equilibrium idx, longest sum=k). HashMap O(n) opt pending. |
| M6 | Binary Search | L0 | — | 0/0 | |
| M7 | Stacks & Monotonic Stack | L0 | — | 0/0 | |
| M8 | Queues & Deque | L0 | — | 0/0 | |
| M9 | Recursion | L0 | — | 0/0 | |
| M10 | Backtracking | L0 | — | 0/0 | |
| M11 | Linked Lists | L0 | — | 0/0 | |
| M12 | Trees | L0 | — | 0/0 | |
| M13 | Binary Search Trees | L0 | — | 0/0 | |
| M14 | Heaps / Priority Queue | L0 | — | 0/0 | |
| M15 | Tries | L0 | — | 0/0 | |
| M16 | Graphs + BFS/DFS | L0 | — | 0/0 | |
| M17 | Topological Sort | L0 | — | 0/0 | |
| M18 | Union-Find | L0 | — | 0/0 | |
| M19 | Shortest Paths (Dijkstra) | L0 | — | 0/0 | |
| M20 | 1-D DP | L0 | — | 0/0 | |
| M21 | 2-D / sequence DP | L0 | — | 0/0 | |
| M22 | Greedy | L0 | — | 0/0 | |
| M23 | Intervals | L0 | — | 0/0 | |
| M24 | Bit Manipulation | L0 | — | 0/0 | |

_Advanced-tier modules added here only if pursued._

---

## Weak / repaired topics
> Topics where a gate failed or a revision recall failed. Cleared when re-passed.
- ⚠️ **Boundary / sentinel / order values** (NOT a topic — a cross-cutting execution weakness).
  Recurred **3×** on Day 1: prefix `[L-1]` index, LC209 min-init+not-found return, LC1004
  off-by-one (`right-left+1`) + step order. Pattern recognition is fine; the *values at the
  edges* are the leak. Standing fix: the **pre-code boundary checklist** (see MISTAKE_JOURNAL).
  Clears when 2 consecutive mediums are solved with zero boundary bugs.

## Problem counters
- Easy solved: 2 (LC643, LC1343 — transfer-reported) · Medium solved: 3 (LC209, LC3, LC1004 — **witnessed/judge-verified**) · Hard (stretch): 0 · Total: 5

## Interview readiness (estimate — label as such)
- Problem solving: 0/100
- Complexity analysis: 0/100
- Coding quality: 0/100
- Communication: 0/100
- **Overall: 0/100**

---

## Session log
> Append one block per session. This is the audit trail for every level change.

```
[Date] — Module(s): — | Did: — | Levels changed: — (evidence) | Problems: — | Next: —

2026-06-04 — Module(s): M4 Sliding Window (Variable) | Did: transfer/First-Run setup; closed-book revision (O(log n) reasoning ✓, prefix-sum formula ✗→repaired, window cue ✓); taught Variable Sliding Window (caterpillar); set up SPRINT_PLAYBOOK + readable solutions/ + Notes/ + run.sh (fixed macOS linker bug = Anaconda stale ld) + LeetCode MCP (live next restart). | Levels changed: M4 L3* → L3 EARNED (LC209 Medium coded from understanding, Accepted on judge). Variable window L2 (explained back) → L3 (implemented). | Problems: LC209 + LC3 + LC1004 all Accepted (**3 mediums**). LC3 introduced `unordered_set` (first Hashing taste). | Levels: **M4 → L4**. | KEY INSIGHT: boundary/order values recurred 3× — flagged as the #1 weak area; pre-code boundary checklist is now standing. | Next: **Day 2 (June 5) — Prefix Sum finish (O(n) hashmap, LC560) + revision due** (prefix re-test LC724, variable-window recall). Then Two Pointers.
```
