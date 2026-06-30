# Practice — Module Mastery Sets (fresh start 2026-06-06)

> Goal: real clarity & confidence on **Prefix Sum, Sliding Window, Hashing** before moving on.
> Each topic = **2 easy + 2 medium + 1 hard**, the canonical best-suited problems.
> Work a topic top-to-bottom, then **discuss with Kira** before the next topic.
> (Two Pointers intentionally skipped — not covered yet.)
> Fill the "Before you code" thinking + Result log in each `problem.md` as you go.

## 01 — Prefix Sum
| # | Problem | Diff | Idea |
|---|---|---|---|
| 1 | LC1480 Running Sum of 1d Array | Easy | build the prefix array |
| 2 | LC303 Range Sum Query - Immutable | Easy | range query O(1) — ⚠️ left==0 boundary |
| 3 | LC238 Product of Array Except Self | Medium | prefix × suffix (no division) |
| 4 | LC523 Continuous Subarray Sum | Medium | prefix + remainder + hash, length≥2 |
| 5 | LC862 Shortest Subarray Sum ≥ K | Hard | prefix + monotonic deque (stretch) |

## 02 — Sliding Window
| # | Problem | Diff | Idea |
|---|---|---|---|
| 1 | LC643 Maximum Average Subarray I | Easy | fixed window slide |
| 2 | LC1876 Substrings Size 3 Distinct | Easy | fixed window + distinct check |
| 3 | LC424 Longest Repeating Char Replacement | Medium | variable window + freq |
| 4 | LC567 Permutation in String | Medium | fixed window + freq match |
| 5 | LC76 Minimum Window Substring | Hard | variable window (shortest) + need/have |

## 03 — Hashing
| # | Problem | Diff | Idea |
|---|---|---|---|
| 1 | LC1 Two Sum | Easy | complement lookup |
| 2 | LC242 Valid Anagram | Easy | frequency count |
| 3 | LC49 Group Anagrams | Medium | map keyed by signature |
| 4 | LC128 Longest Consecutive Sequence | Medium | hash set membership, O(n) |
| 5 | LC149 Max Points on a Line | Hard | map of slopes (stretch) |

## Suggested order
Start with **Hashing** (your shakiest + it's the foundation under prefix+hash), then
**Prefix Sum** (you've got momentum), then **Sliding Window** (revision + the hard).
But your call — pick whichever you want clarity on first.
