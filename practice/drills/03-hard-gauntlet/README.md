# Drill 03 — PHASE-1 HARD GAUNTLET (the ONE home for every Phase-1 hard)

> Every hard problem across all of Phase 1, **consolidated here and deduped**. Previously these were
> scattered (and triplicated) across `practice/<topic>/05-hard-*` and `drill1`'s tail — all pulled
> into this one place 2026-06-30. One hard (minimum) per Phase-1 pattern that *has* a real hard.

**Bar:** these are stretch / weekend problems (cadence: hards = weekend). FAANG leans on a few of
these. Goal = be able to *derive* each, not recall it.

| # | Pattern | Problem | LC | The hard idea | Status |
|---|---------|---------|----|----|----|
| 01 | **Hashing** | Max Points on a Line | 149 | anchor + gcd-reduced slope hash; cross-product collinearity | ☐ |
| 02 | **Two-Pointer** | Trapping Rain Water | 42 | water = min(maxL,maxR)−h; move the shorter wall | ☐ |
| 03 | **Sliding Window** | Minimum Window Substring | 76 | grow-cover / shrink-minimal; need-map + have-counter ⭐P27 re-test | ☐ |
| 04 | **Sliding Window** | Subarrays with K Different | 992 | exactly(k)=atMost(k)−atMost(k−1) ⭐#11 re-test | ☐ |
| 05 | **Binary Search** | Median of Two Sorted Arrays | 4 | BS a partition of the shorter array; ±INF sentinels | ☐ |
| 06 | **Binary Search** | Split Array Largest Sum | 410 | minimize-the-max → BS on answer + greedy feasibility (LC1011 twin) | ☐ |
| 07 | **Binary Search** | Kth Smallest Pair Distance | 719 | BS on distance + O(n) window count of pairs ≤ d | ☐ |
| 08 | **Stacks/Monotonic** | Largest Rectangle in Histogram | 84 | width between smaller bars; monotonic-increasing index stack | ☐ |
| ⏸️ | **Prefix Sum** | Shortest Subarray Sum≥K | 862 | **PARKED → Phase 2** (genuinely needs M8 monotonic deque) | 🅿️ |

**Optional canonical adds (say the word, I'll scaffold):** LC32 Longest Valid Parentheses ·
LC224 Basic Calculator · LC85 Maximal Rectangle · LC30 Substring with Concatenation.

**RULES (standing structure, every problem):** fill **BRUTE first** (it's the stress oracle) → the
**Bridge** (3 Qs, your words) → **OPTIMAL** → **STRESS** in `main()` (brute vs optimal, random, ~50k).
Paste ONLY the `Solution` class into LeetCode; `main()` is local. "Solved" = judge-AC.

**Self-gates every problem:** name the flavor · pre-load the 2–3 leaks for THIS pattern · build your
OWN hostile input · **self-trace before you say "done"** (wanting to ask "is it ok" IS the cue to
trace it yourself).
