# DRILL 1 — PRACTICE Drill (Hema Vardhan)

> **30 problems — 8 easy · 16 medium · 6 hard**, interleaved across every pattern we've
> covered **except monotonic stack**: Sliding Window · Prefix Sum · Hashing · Two Pointers ·
> Binary Search. Statements are **disguised** (no titles, no patterns) so you train
> *recognition*, not title-matching.
>
> **This is a PRACTICE drill — learning mode.** Read **`PRACTICE_PROTOCOL.md`** first: every
> problem runs **brute force → bottleneck → pattern hunt → optimal → compare**, hints allowed
> (≤4 small, then full explanation). After a few practice drills comes a **TEST drill**
> (no scaffolding, graded) to prove it transferred — then difficulty ratchets toward FAANG-ready.
>
> **No answer key.** `LINKS.md` has only the LeetCode link per problem. Guess the pattern
> FIRST (in the `.cpp` header), then open the link, submit, and verify on the judge — the
> judge is ground truth, not my approval.

---

## WHY THIS MIX (Tommy's calibration call)
You're at **L4** on all five patterns, so a beginner-style easy-heavy set would waste your
time. The FAANG bar lives at **confident medium**, so this drill is medium+hard heavy (73%):
- **8 easy** — fast warm-ups, one per base mechanic, to confirm fundamentals are reflexive.
- **16 medium** — the core, ~3 per pattern, deliberately spanning *sub-variants* (e.g. binary
  search shows up as exact, predicate, rotated, find-min, peak, and search-on-answer).
- **6 hard** — genuine transfer, including the two-tool combos (P29 at-most-k trick, P30 the
  k-th distance problem we cracked last session).

Canonical must-knows are included even though you may have seen them years ago — those build
the mind; re-derive them fresh, don't recall old code.

---

## THE RULES (these ARE the drill — don't skip)
For **every** problem, in the `.cpp` header, in this order:
1. **RESTATE** in ONE plain sentence. (MISTAKE #10 — the thing that cost you Q4/Q6. No
   pattern call until you can restate it.)
2. **DRY-RUN** the example by hand.
3. **CONSTRAINTS → complexity.** What Big-O does the input size demand?
4. **NAME THE PATTERN** + a 3-line sketch. Say the gates out loud:
   - Before "two pointers": **"Is it sorted/monotonic?"** No → **hashing**. (MISTAKE #9.)
   - Before "sliding window": **"Negatives / ±1 transform?"** Yes → **prefix+hash**.
5. **Open the link** (`LINKS.md`), code in the stub, **submit** to LeetCode.
6. **Boundary checklist** before submit: empty / single / first&last / overflow & magnitude.

Go **top to bottom** — it's already interleaved. Don't batch by pattern.

---

## EASY (1–8)
- **P1** `p01-pair-sum-to-target` — two numbers in an UNSORTED array adding to a target; return indices.
- **P2** `p02-remove-sorted-duplicates` — remove dups in place from a SORTED array, return new count.
- **P3** `p03-integer-sqrt` — integer (floor) square root, no built-in sqrt.
- **P4** `p04-highest-altitude` — highest altitude from a list of net gains.
- **P5** `p05-max-vowels-substring` — max vowels in any substring of fixed length k.
- **P6** `p06-ransom-note` — can note be built from magazine letters (each used once)?
- **P7** `p07-subsequence-check` — is s a subsequence of t (in order, not contiguous)?
- **P8** `p08-first-bad-version` — first bad version via a good→bad oracle, fewest checks.

## MEDIUM (9–24)
- **P9** `p09-count-subarrays-sum-k` — count subarrays summing to k (values may be negative).
- **P10** `p10-four-sum-count` — count 4-array tuples summing to 0.
- **P11** `p11-search-rotated` — find a target in a rotated sorted array, O(log n).
- **P12** `p12-zero-sum-triplets` — all unique triplets summing to 0.
- **P13** `p13-longest-after-k-replaces` — longest single-letter run after ≤ k replacements.
- **P14** `p14-count-exactly-k-odds` — count subarrays with exactly k odd numbers.
- **P15** `p15-sort-by-frequency` — sort a string's chars by decreasing frequency.
- **P16** `p16-min-ship-capacity` — min ship capacity to ship ordered packages within D days.
- **P17** `p17-sort-three-values` — sort 0/1/2 in place in ONE pass (3-way partition, not selection sort).
- **P18** `p18-all-rearrangement-indices` — all start indices of anagrams of p in s.
- **P19** `p19-min-subarray-remove-divisible` — shortest subarray to remove so the rest is divisible by p.
- **P20** `p20-longest-consecutive` — longest run of consecutive integers in an unsorted array, O(n).
- **P21** `p21-find-a-peak` — any peak element, O(log n).
- **P22** `p22-closest-triplet-sum` — three-element sum closest to a target.
- **P23** `p23-fruit-into-baskets` — longest contiguous stretch using at most 2 distinct values.
- **P24** `p24-min-in-rotated` — minimum of a rotated sorted array, O(log n).

## HARD (25–30) — restate + dry run is MANDATORY
- **P25** `p25-trapped-rain-water` — water trapped between bar heights.
- **P26** `p26-min-largest-split` — split into m contiguous parts minimizing the largest sum.
- **P27** `p27-shortest-covering-substring` — shortest substring of s covering all of t.
- **P28** `p28-median-two-sorted` — median of two sorted arrays in O(log(m+n)).
- **P29** `p29-subarrays-k-distinct` — count subarrays with exactly k distinct integers.
- **P30** `p30-kth-smallest-pair-distance` — k-th smallest pairwise distance. *(Prove last session stuck.)*

---

## RECOGNITION LOG (your scoreboard — fill as you go)

| # | My pattern guess | Correct? (✓/✗) | Restated first try? | Brute done? | AC on judge? | Notes / where I slipped |
|---|---|---|---|---|---|---|
| 1 | Two pointers (→ recovered to Hashing) | ✗ | ✓ | — | ✓ AC | #9 reflex fired AGAIN (sorted+2ptr); also misread complexity (saw 1e9 value→hunted O(log n); real: n≤1e4, O(n) floor). Recovered to one-pass hash map after coaching. Gate "sorted? indices? → hashing" must fire FIRST. |
| 2 | Hashing (over-applied; correct = Two Pointers in-place) | ✗ | ✓ | extra-vector | ✓ AC | SORTED array → 2ptr, but reached for hash map+extra vector (P1 over-correction). C++ gap found: copy a vector (`nums=d` / `.assign`). Off-by-one: forgot first element counts → fixed by returning `j`. Boundary leak (first-element). TODO: redo in-place O(1) space as the optimal. |
| 3 | (brute: linear scan); optimal pending | — | — | ✓ O(√x) | ✓ AC | Brute AC after 2 fixes: nested-function bug (mySqrt inside main) + `i*i` int overflow at x≈INT_MAX → `(long long)i*i` (MISTAKE #8 recurred). Optimal = BS-on-answer (monotonic i*i) O(log x) still to do. Spawned the overflow-detection rule in CPP_GAPS.md. |
| 4 | | | | | | |
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

> **Grading:** bring me a batch and we grade recognition together. A pattern earns progress
> toward L5 only when you name it **cold and correct on first instinct**. Misses → logged to
> `MISTAKE_JOURNAL.md` with root cause + re-test. Pass Drill 1 well → Drill 2 gets harder.

### Pass bar for Drill 1 (what "came out better" means)
- **Recognition:** ≥ 26/30 patterns named correctly on first instinct (incl. P1 as hashing, no sort-reflex).
- **Restate discipline:** restated correctly first try on ≥ 27/30 (the MISTAKE #10 fix).
- **Independence:** all 8 easies + ≥ 12/16 mediums solved with no hints; hards may use the hint ladder.
- **Judge:** every attempted problem ends in an Accepted submission (fix-and-resubmit is fine).
