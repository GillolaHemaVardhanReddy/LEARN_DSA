# DRILL 1 — Recognition Grind (Hema Vardhan)

> **35 problems** (15 easy · 15 medium · 5 hard), interleaved across every pattern we've
> covered **except monotonic stack**: Sliding Window · Prefix Sum · Hashing · Two Pointers ·
> Binary Search. Statements are **disguised on purpose** — no problem titles — so you train
> *recognition*, not title-matching. Finish this grind, then we start Monotonic Stack.

---

## THE RULES (these are the whole point — don't skip them)

For **every** problem, in this exact order:

1. **RESTATE** the problem in ONE plain sentence. (This is MISTAKE #10 — the thing that
   cost you Q4 and Q6 in the last drill. No pattern call until you can restate it.)
2. **DRY RUN** the given tiny example by hand. Confirm you understand the *actual* ask.
3. **CONSTRAINTS → complexity.** What does the input size imply about the target Big-O?
4. **NAME THE PATTERN** + a 3-line approach sketch. Write your guess in the log below.
   - Before you say "two pointers," ask out loud: **"Is the data sorted/monotonic?"**
     If no → it's probably **hashing**. (MISTAKE #9 — your 3×-recurring reflex.)
   - Before "sliding window," ask: **"Can values be negative / did I transform to ±1?"**
     If yes → it's **prefix + hash**, not a window.
5. **Reveal the link** in `ANSWER_KEY.md`, check your pattern guess, then **code & submit**
   to LeetCode (the judge is ground truth — my approval is not).
6. **Run the boundary checklist** before you submit (empty / single / first&last / overflow).

**Order of attack:** go top to bottom — it's already interleaved. Don't batch by pattern.

Drop your code in `drill1/solutions/` (e.g. `drill1/solutions/p16-subarray-sum.cpp`).

---

## EASY (1–15)

**P1.** Given an array of integers and a target value, return the indices of the two
numbers that add up to the target. The array is **not sorted**. Exactly one valid answer
exists. Example: `nums=[2,7,11,15], target=9 → [0,1]`. Constraints: n ≤ 10⁴.
> Restate: _______  Pattern guess: _______

**P2.** Given a string, decide if it reads the same forwards and backwards, considering
**only alphanumeric characters** and ignoring case. Example: `"A man, a plan, a canal: Panama" → true`.
> Restate: _______  Pattern guess: _______

**P3.** Given a **sorted** array and a target, return the index of the target, or -1 if
it's absent. Must run in O(log n). Example: `nums=[-1,0,3,5,9,12], target=9 → 4`.
> Restate: _______  Pattern guess: _______

**P4.** You'll be asked many times for the sum of elements between index `i` and `j`
(inclusive) of a fixed integer array. Make each query fast. Example: `sumRange(0,2)` on
`[-2,0,3,-5,2,-1] → 1`.
> Restate: _______  Pattern guess: _______

**P5.** Given an array and a fixed window length `k`, find the **maximum average** of any
contiguous block of `k` elements. Example: `nums=[1,12,-5,-6,50,3], k=4 → 12.75`.
> Restate: _______  Pattern guess: _______

**P6.** Given an array, return `true` if **any value appears at least twice**. The array
is **unsorted**. Example: `[1,2,3,1] → true`.
> Restate: _______  Pattern guess: _______

**P7.** You have two **sorted** integer arrays. Merge the second into the first (which has
enough trailing space) so the result is one sorted array, done **in place**. Example:
`[1,2,3,0,0,0]` + `[2,5,6] → [1,2,2,3,5,6]`.
> Restate: _______  Pattern guess: _______

**P8.** Versions 1..n are in order; from some version onward everything is "bad" and stays
bad. You have an `isBad(version)` check. Find the **first bad version** with the fewest
checks. Example: n=5, first bad=4 → 4.
> Restate: _______  Pattern guess: _______

**P9.** Given an array, find an index where the sum of everything to its **left** equals
the sum of everything to its **right**. Return the leftmost such index, or -1.
Example: `[1,7,3,6,5,6] → 3`.
> Restate: _______  Pattern guess: _______

**P10.** Given a string and an integer `k`, find the maximum number of vowels in any
contiguous substring of length `k`. Example: `s="abciiidef", k=3 → 3`.
> Restate: _______  Pattern guess: _______

**P11.** Given two strings, decide if one is a rearrangement of the other (same characters,
same counts). Example: `"anagram","nagaram" → true`; `"rat","car" → false`.
> Restate: _______  Pattern guess: _______

**P12.** Given an array, move all the zeros to the end while keeping the relative order of
the non-zero elements, **in place**. Example: `[0,1,0,3,12] → [1,3,12,0,0]`.
> Restate: _______  Pattern guess: _______

**P13.** Given a **sorted** array and a target, return the index where the target is, or
where it **would be inserted** to keep the array sorted. O(log n). Example:
`[1,3,5,6], target=5 → 2`; `target=2 → 1`.
> Restate: _______  Pattern guess: _______

**P14.** Given two strings `s` and `t`, decide whether `s` is a **subsequence** of `t`
(all of s's characters appear in t in order, not necessarily contiguous). Example:
`s="abc", t="ahbgdc" → true`.
> Restate: _______  Pattern guess: _______

**P15.** I'm thinking of a number from 1 to n. You guess; I tell you "higher", "lower", or
"correct". Find my number in the fewest guesses. Example: n=10, pick=6 → 6.
> Restate: _______  Pattern guess: _______

---

## MEDIUM (16–30)

**P16.** Given an integer array (values may be **negative**) and an integer `k`, count how
many contiguous subarrays sum to exactly `k`. Example: `nums=[1,1,1], k=2 → 2`.
> Restate: _______  Pattern guess: _______

**P17.** Given a string, find the length of the **longest substring with no repeating
characters**. Example: `"abcabcbb" → 3` ("abc").
> Restate: _______  Pattern guess: _______

**P18.** Given an array, return **all** unique triplets that sum to zero. No duplicate
triplets. Example: `[-1,0,1,2,-1,-4] → [[-1,-1,2],[-1,0,1]]`.
> Restate: _______  Pattern guess: _______

**P19.** A **sorted** array was rotated at some unknown pivot. Given the rotated array and
a target, find the target's index in O(log n), or -1. Example:
`[4,5,6,7,0,1,2], target=0 → 4`.
> Restate: _______  Pattern guess: _______

**P20.** Given an array and integer `k`, return the `k` **most frequent** elements. Better
than O(n log n) preferred. Example: `nums=[1,1,1,2,2,3], k=2 → [1,2]`.
> Restate: _______  Pattern guess: _______

**P21.** Given a string of uppercase letters and an integer `k`, you may replace **at most
`k`** characters with any letter. Find the longest substring of a single repeated letter
you can make. Example: `s="AABABBA", k=1 → 4`.
> Restate: _______  Pattern guess: _______

**P22.** Given an array and a target, find the sum of **three** elements that is **closest**
to the target. Return that sum. Example: `nums=[-1,2,1,-4], target=1 → 2`.
> Restate: _______  Pattern guess: _______

**P23.** Given an integer array (values may be **negative**) and integer `k`, count the
contiguous subarrays whose sum is **divisible by `k`**. Example: `nums=[4,5,0,-2,-3,1], k=5 → 7`.
> Restate: _______  Pattern guess: _______

**P24.** A ship leaves once a day; on day `i` it carries the next packages in order. Given
package weights (in order) and `D` days, find the **minimum ship capacity** so everything
ships within `D` days. Example: `weights=[1,2,3,4,5,6,7,8,9,10], D=5 → 15`.
> Restate: _______  Pattern guess: _______

**P25.** Given a string `s` and a pattern string `p`, return the **start indices** of every
substring of `s` that is a rearrangement of `p`. Example: `s="cbaebabacd", p="abc" → [0,6]`.
> Restate: _______  Pattern guess: _______

**P26.** Given an array containing only the values 0, 1, and 2, sort it **in place** in a
**single pass** without a library sort. Example: `[2,0,2,1,1,0] → [0,0,1,1,2,2]`.
> Restate: _______  Pattern guess: _______

**P27.** Given an array and integer `k`, count the contiguous subarrays that contain
**exactly `k` odd numbers**. Example: `nums=[1,1,2,1,1], k=3 → 2`.
> Restate: _______  Pattern guess: _______

**P28.** Given an array where no two adjacent elements are equal, find **any** "peak" — an
element strictly greater than both neighbors (ends count with -∞ beyond them). O(log n).
Example: `[1,2,1,3,5,6,4] → 5` (index of value 6) or index 1.
> Restate: _______  Pattern guess: _______

**P29.** Given four integer arrays of length n, count the tuples `(i,j,k,l)` such that
`A[i]+B[j]+C[k]+D[l] == 0`. Example: four `[...]` arrays → some count. n ≤ 200.
> Restate: _______  Pattern guess: _______

**P30.** Given a binary array (0s and 1s) and integer `k`, find the longest run of
consecutive 1s if you may **flip at most `k` zeros**. Example: `nums=[1,1,1,0,0,0,1,1,1,1,0], k=2 → 6`.
> Restate: _______  Pattern guess: _______

---

## HARD (31–35) — restate + dry run is MANDATORY here

**P31.** Given an array of bar heights (width 1 each), compute how much **rain water** is
trapped between the bars after it rains. Example:
`[0,1,0,2,1,0,1,3,2,1,2,1] → 6`.
> Restate: _______  Pattern guess: _______

**P32.** Split an array into `m` **contiguous** subarrays to **minimize the largest**
subarray sum. Return that minimized largest sum. Example: `nums=[7,2,5,10,8], m=2 → 18`.
> Restate: _______  Pattern guess: _______

**P33.** Given strings `s` and `t`, find the **shortest substring of `s`** that contains
every character of `t` (with multiplicity). Return "" if none. Example:
`s="ADOBECODEBANC", t="ABC" → "BANC"`.
> Restate: _______  Pattern guess: _______

**P34.** Given two **sorted** arrays, find the **median** of the combined set in O(log(m+n)).
Example: `[1,3]` and `[2] → 2.0`; `[1,2]` and `[3,4] → 2.5`.
> Restate: _______  Pattern guess: _______

**P35.** Given an integer array and integer `k`, find the **k-th smallest** distance among
**all pairs** (distance = absolute difference). Example: `nums=[1,3,1], k=1 → 0`.
*(You cracked this one's twin last session — prove it stuck.)*
> Restate: _______  Pattern guess: _______

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

> When you've done a batch, bring me the log and we'll grade recognition together,
> log any misses to `MISTAKE_JOURNAL.md`, and adjust. **Don't open `ANSWER_KEY.md`
> for a problem until you've written your pattern guess for it.**
