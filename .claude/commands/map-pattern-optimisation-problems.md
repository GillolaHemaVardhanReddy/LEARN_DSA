---
description: Generate problems on the "hash map replaces an O(n) inner scan" meta-pattern
argument-hint: "[optional: count | easy/medium/hard | how many]"
---
Hema wants to drill the **map-as-inner-loop** meta-pattern he discovered (2026-06-06):
*a hash map collapses a brute-force O(n²) "scan all earlier elements/prefixes" into O(n)
by remembering what's been seen.* This spans Two Sum-style complement lookup, prefix+hash
(sum=k / divisible / equal-counts), frequency maps, and remainder maps.

## Steps
1. Read `PROGRESS.md` (level), `practice/PRACTICE_LOG`-style history, and `learn/` to avoid repeats.
2. Generate a focused set (default 4: ~2 easy + 2 medium; honor `$ARGUMENTS` for count/difficulty/number).
3. Each problem must be one where the **insight is "store seen values in a map, look one up in O(1)"**.
   Good pool: Two Sum, Subarray Sum = K, Subarrays Divisible by K, Contiguous Array, Longest
   Subarray Sum = K, Subarray with XOR = K, Count Nice Subarrays, Binary Subarrays With Sum,
   Longest Consecutive Sequence, 4Sum II, Continuous Subarray Sum.
4. Scaffold each under `practice/` as a folder with `problem.md` (link, plain-English, examples,
   constraints, and a **"map plan" block**: what's the KEY? what's the VALUE — frequency or index?
   what's pre-loaded as the empty/seen base?) + `solution.cpp` (signature + test harness).
5. **Reinforce the framework** in each problem.md: GOAL decides map VALUE (count→frequency,seen[0]=1 /
   longest→first-index,seen[0]=-1); CONDITION decides the KEY (complement / remainder / transform).
6. Tell him to fill the "map plan" before coding. Offer review. Don't commit unless asked.
