# DRILL 1 — Recognition Grind (Hema Vardhan)

> **35 problems** (15 easy · 15 medium · 5 hard), interleaved across every pattern we've
> covered **except monotonic stack**: Sliding Window · Prefix Sum · Hashing · Two Pointers ·
> Binary Search. Statements are **disguised on purpose** — no titles, no patterns — so you
> train *recognition*, not title-matching. Finish this grind, then we start Monotonic Stack.
>
> **No answer key.** `LINKS.md` has only the LeetCode link per problem. You guess the
> pattern FIRST (in the `.cpp` header), then open the link, submit, and verify on the judge.
> Mostly **unseen** problems — the two you've solved before (P1, P26) are kept on purpose
> because they target a leak you still need to close.

---

## THE RULES (these are the whole point — don't skip them)

Open `pNN-*/problem.cpp` and, for **every** problem, in this exact order:

1. **RESTATE** the problem in ONE plain sentence in the header. (This is MISTAKE #10 — the
   thing that cost you Q4 and Q6 in the last drill. No pattern call until you can restate it.)
2. **DRY RUN** the given tiny example by hand. Confirm you understand the *actual* ask.
3. **CONSTRAINTS → complexity.** What does the input size imply about the target Big-O?
4. **NAME THE PATTERN** + a 3-line approach sketch. Write your guess in the header + the log.
   - Before "two pointers," ask out loud: **"Is the data sorted/monotonic?"** No → **hashing**.
     (MISTAKE #9 — your 3×-recurring reflex.)
   - Before "sliding window," ask: **"Can values be negative / did I transform to ±1?"**
     Yes → **prefix + hash**, not a window.
5. **Open the link** in `LINKS.md`, **code in the stub**, and **submit** to LeetCode
   (the judge is ground truth — my approval is not).
6. **Run the boundary checklist** before you submit (empty / single / first&last / overflow).

**Order of attack:** go top to bottom — it's already interleaved. Don't batch by pattern.

---

## EASY (1–15)

- **P1** `p01-pair-sum-to-target` — two numbers in an UNSORTED array adding to a target; return indices.
- **P2** `p02-remove-sorted-duplicates` — remove dups in place from a SORTED array, return the new count.
- **P3** `p03-smallest-letter-greater` — smallest letter strictly greater than a target in a sorted, wrapping list.
- **P4** `p04-min-start-value` — min positive start so a running total of given steps never drops below 1.
- **P5** `p05-min-recolors-k-black` — fewest W→B recolors to get k consecutive black blocks.
- **P6** `p06-isomorphic-strings` — do two strings map char-for-char one-to-one?
- **P7** `p07-merge-two-sorted` — merge two SORTED arrays in place into the first.
- **P8** `p08-first-bad-version` — first bad version given a good→bad oracle, fewest checks.
- **P9** `p09-highest-altitude` — highest altitude reached from a list of net gains.
- **P10** `p10-max-vowels-substring` — max vowels in any substring of fixed length k.
- **P11** `p11-word-pattern` — do space-separated words follow a pattern, one-to-one both ways?
- **P12** `p12-reverse-string` — reverse a char array in place, O(1) space.
- **P13** `p13-integer-sqrt` — integer (floor) square root without built-in sqrt.
- **P14** `p14-subsequence-check` — is s a subsequence of t (in order, not contiguous)?
- **P15** `p15-guess-number` — find a hidden number in [1,n] via higher/lower replies.

## MEDIUM (16–30)

- **P16** `p16-binary-subarrays-sum` — count contiguous subarrays of a BINARY array summing to goal.
- **P17** `p17-fruit-into-baskets` — longest contiguous run using at most 2 distinct values.
- **P18** `p18-four-sum` — all unique quadruplets summing to a target.
- **P19** `p19-search-rotated` — find a target in a rotated sorted array, O(log n).
- **P20** `p20-sort-by-frequency` — sort a string's chars by decreasing frequency.
- **P21** `p21-longest-after-k-replaces` — longest single-letter run after ≤ k replacements.
- **P22** `p22-closest-triplet-sum` — three-element sum closest to a target.
- **P23** `p23-min-subarray-remove-divisible` — shortest subarray to remove so the rest is divisible by p.
- **P24** `p24-min-ship-capacity` — min ship capacity to ship ordered packages within D days.
- **P25** `p25-all-rearrangement-indices` — all start indices of substrings that are anagrams of p.
- **P26** `p26-sort-three-values` — sort 0/1/2 in place in ONE pass. *(Do it as the 3-way partition, not selection sort.)*
- **P27** `p27-count-exactly-k-odds` — count subarrays with exactly k odd numbers.
- **P28** `p28-find-a-peak` — any peak element in O(log n).
- **P29** `p29-four-array-zero-tuples` — count 4-array tuples summing to 0.
- **P30** `p30-longest-ones-delete-one` — longest run of 1s after deleting exactly one element.

## HARD (31–35) — restate + dry run is MANDATORY here

- **P31** `p31-trapped-rain-water` — water trapped between bar heights.
- **P32** `p32-min-largest-split` — split into m contiguous parts minimizing the largest sum.
- **P33** `p33-shortest-covering-substring` — shortest substring of s covering all of t.
- **P34** `p34-median-two-sorted` — median of two sorted arrays in O(log(m+n)).
- **P35** `p35-kth-smallest-pair-distance` — k-th smallest pairwise distance. *(You cracked its twin last session — prove it stuck.)*

---

## RECOGNITION LOG (fill as you go — this is your scoreboard)

| # | My pattern guess | Correct? (✓/✗) | Restated correctly first try? | AC on judge? | Notes / where I slipped |
|---|---|---|---|---|---|
| 1 | | | | | |
| 2 | | | | | |
| 3 | | | | | |
| 4 | | | | | |
| 5 | | | | | |
| 6 | | | | | |
| 7 | | | | | |
| 8 | | | | | |
| 9 | | | | | |
| 10 | | | | | |
| 11 | | | | | |
| 12 | | | | | |
| 13 | | | | | |
| 14 | | | | | |
| 15 | | | | | |
| 16 | | | | | |
| 17 | | | | | |
| 18 | | | | | |
| 19 | | | | | |
| 20 | | | | | |
| 21 | | | | | |
| 22 | | | | | |
| 23 | | | | | |
| 24 | | | | | |
| 25 | | | | | |
| 26 | | | | | |
| 27 | | | | | |
| 28 | | | | | |
| 29 | | | | | |
| 30 | | | | | |
| 31 | | | | | |
| 32 | | | | | |
| 33 | | | | | |
| 34 | | | | | |
| 35 | | | | | |

> When you've done a batch, bring me the log. We grade recognition together, log misses to
> `MISTAKE_JOURNAL.md` with root cause + re-test, update `PROGRESS.md` levels with the
> evidence, and only patterns you name **cold and correct on first instinct** move toward L5.
