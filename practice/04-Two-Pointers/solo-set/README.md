# Two Pointers — SOLO SET (the real L4 gate)

> Hema's own call (2026-06-09): the guided ladder doesn't cleanly prove L4, so these are **solo, cold, on your own time.**
> No coaching, no looking up the approach — recognizing + executing it yourself IS the L4 evidence.
> Chosen to cover shapes the ladder under-drilled (fast/slow write pointer, one-skip, Dutch-flag partition) + a pure converging rep.

## The rule for each
1. Cue line first: `cue: ___ → two pointers because ___` (which SHAPE? converging / fast-slow / partition?)
2. Brute force + complexity, then the two-pointer optimization.
3. **Boundary checklist before submit** (your #1 leak): loop touches first & last? `L<R` / bound guards? empty/size-1? consistent indices?
4. Submit to LeetCode. **L4 is earned when you AC both mediums (167 + 75) largely solo.**

## The set
| # | Problem | Diff | Shape / new sub-skill | Link |
|---|---------|------|------------------------|------|
| 1 | LC 283 Move Zeroes | easy | **fast/slow write pointer** (in-place, shape the ladder skipped) | https://leetcode.com/problems/move-zeroes/ |
| 2 | LC 680 Valid Palindrome II | easy | converging + **at-most-one skip** (branch into two checks) | https://leetcode.com/problems/valid-palindrome-ii/ |
| 3 | LC 167 Two Sum II | **med** | **pure sum-steered converging** (the mechanic, fully solo this time) | https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/ |
| 4 | LC 75 Sort Colors | **med** | **Dutch-flag 3-way partition** (low/mid/high pointers — new skill) | https://leetcode.com/problems/sort-colors/ |

## After this set
Ping Kira with the results. AC on 167 + 75 solo → **M3 Two Pointers L4 earned**. Then: LC42 Trapping (weekend),
and the deferred L5 recognition `/drill` later. Optional stretch: LC16 (3Sum Closest), LC18 (4Sum).
