# Topic 01 — Hashing · the teaching plan  (v2, restarted 2026-09-26)

## The contract (boss, 2026-09-26)
1. **The plan is written before it is taught.** Kira teaches from this file. No improvised detours.
2. **Side questions get PARKED, not answered at length.** If a question belongs to a later topic,
   Kira gives the 10-second usable version and writes it in the Parked list at the bottom.
   The full derivation happens when that topic arrives.
3. **One problem per session.** Code first. Stop when it's AC'd and the complexity is said.
4. **No quizzing.** Retrieval happens by re-solving problems, never by being asked what you remember.

## The habit that runs in FRONT of every problem (this is topic 00)
Before any code, one line out loud:

> **n = ___ , and one item costs ___ , so I can afford ___ , which rules out ___ .**

Rule of thumb: a judge does ~10^8 simple operations per second.

| n up to | affordable | typical tool |
|---|---|---|
| 10–20 | O(2^n), O(n!) | backtracking, bitmask |
| ~500 | O(n^3) | Floyd, interval DP |
| ~5000 | O(n^2) | DP-2D, pairwise |
| 10^5–10^6 | O(n log n), O(n) | sort, hash, two pointers, window |
| 10^9 | O(log n) | binary search, math |

**The trap (M#13):** counting the items and forgetting what ONE item costs.
`s == t` on 100-char strings is not 1 operation. It is 100.

## What hashing IS (the one sentence)
A hash map turns **"have I seen X before?"** from an O(n) scan into an O(1) lookup,
by paying memory. Every problem below is a different answer to: **what is X?**

## The ladder — 6 problems, one per session

| # | Problem | LC | The ONE new idea | You can say this at the end | Status |
|---|---|---|---|---|---|
| 1 | Group Anagrams | 49 | the key is something you **BUILD**, not something you're given | "anagrams collide when I choose a key that ignores order" | **CLOSED** 2026-09-27 · AC · O(n·L log L) |
| 2 | Top K Frequent Elements | 347 | count first, then put a **second structure** on the counts | "I hashed to counts, then bucketed by count" | ▶ **next** |
| 3 | Longest Consecutive Sequence | 128 | a set for **membership**, not counting · only start at a run's head | "the head check is what makes it O(n) and not O(n^2)" | |
| 4 | Subarray Sum Equals K | 560 | hash **what you have seen so far** — a prefix sum as a key | "I asked the map for a past prefix instead of re-scanning" | |
| 5 | 4Sum II | 454 | **split the search space** in half, hash one half | "n^4 became n^2 by meeting in the middle" | |
| 6 | Isomorphic Strings | 205 | two maps, and **why one is not enough** | "one map allows two letters to map onto the same letter" | |

## Then: the combined reps round
The 6 statements above, shuffled, no labels, cold, one sitting.
Topic 01 closes when that round is clean. Topic 02 does not open until then.

## A problem is DONE when
AC on LeetCode **and** the complexity said in one sentence **with the line that causes each factor**.
Not "it's O(n)". Instead: *"O(n·L) — the loop runs n times and building the key walks all L characters."*

## Parked — asked early, taught later
| Question | Answer for now (use it, don't derive it) | Taught properly in |
|---|---|---|
| Why does `sort` cost L log L? | log L = how many times you can halve L to reach 1 (100 → 7). Sorting makes ~that many passes, each touching all L. So ~700 for L=100. | **06 sorting** (+ the recursion tree in **09**) |
| Why `unordered_map` over `map`? | `map` = tree, O(L·log n) per op, keeps keys sorted. `unordered_map` = hash table, O(L) average, no order. Default to `unordered_map`; use `map` only when you need sorted iteration, `lower_bound`, or a guaranteed bound. **Answered in full 2026-09-27.** | — (done) |
| Can `unordered_map` be attacked in contests? | Yes — on Codeforces, hackers submit inputs engineered to collide in the default hash, turning O(1) into O(n) and causing TLE. Fix is a custom hash with a random seed. Not an issue on LeetCode. | **32 contest craft** (+ **29 string hashing**) |
