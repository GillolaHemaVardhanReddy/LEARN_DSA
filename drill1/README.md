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

## WHY THIS MIX (Kera's calibration call)
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
| 3 | BS-on-answer (monotonic i*i) — RECOGNIZED ✓ | ✓ | — | ✓ O(√x) | ✓ AC (O(log x)) | WIN: named & coded BS-on-monotonic-answer himself for the optimal. Brute→optimal both AC. Overflow handled `(long long)mid*mid`. RESIDUAL: structure bug AGAIN (method defined inside main() instead of the Solution class — 3rd occurrence; AC only because LeetCode pastes into the class). "method in class, main calls it" not yet a reflex. |
| 4 | Prefix / running sum | ✓ (after dry-run) | ~ (confused first; opened link to disambiguate my too-thin statement, then derived it) | running-sum | ✓ AC | Got prefix-sum eventually; process slip = opened link for clarity instead of dry-running first (statement was too terse — my fix). Boundary (start 0) handled. CODE REVIEW: had a dead first loop (min gains) — redundant; cleaned to a 3-line running-sum, ans=0 init removes need for the clamp. STRUCTURE FIXED ✓ (method in class). |
| 5 | Fixed sliding window | ~ (had brute; named SW after a cue) | ✓ | hashmap double-loop O(n·k) | ✓ AC | Good complexity reasoning (n²=1e10>1e8/s → need O(n)). Left "my pattern" blank until cued by "fixed length k". Two bugs fixed: `"a"` (string) vs `'a'` (char) in set insert; and `if/else if` skipped the entering char when leaving was a vowel → made them independent ifs + `ans=max` every step. Clean now. |
| 6 | Hashing (frequency count) | ~ (got "hashmap"; restate misread as substring; presence-vs-count gap) | ~ | presence-loop O(n²) | ✓ AC | Restate drifted to "substring" (wrong — order/contiguity irrelevant; counterexample ab/ba). Brute checked PRESENCE not COUNTS — same trap as anagram Q7 (recurring presence-vs-frequency). Optimal = freq count `int[26]`, magazine ≥ note. (Kera OVER-REVEALED the optimal — protocol breach, noted.) Placed on hashing sub-pattern map: frequency-count flavor. |
| 7 | Hashing (✗) → Two Pointers (after 1 nudge) | ~ | ✓ | his brute WAS already 2ptr | ✓ AC | First instinct = "hashmap removes inner loop" (over-applied hashing AGAIN). Recovered to two pointers after one hint (the ORDER question). KEY LEARNING: order matters → hashmap loses order → disqualified → two sequences walked in tandem = two pointers. His own brute (j never resets) was already the O(n+m) optimal. |
| 8 | Binary search (monotonic predicate) — RECOGNIZED ✓ | ✓ | ~ ("min bad point" loose) | linear scan O(n·api) | ✓ AC | Clean first-instinct recognition off the monotonicity gate. Algorithm fully correct (store-candidate lower-bound, overflow-safe mid). ONLY bug = lo/hi SWAPPED in init (`hi=1, lo=n`) → loop never ran, returned 0. Boundary/init-value leak again. Fix = say each boundary's meaning aloud before running. |
| 9 | Prefix + Hash — RECOGNIZED ✓ | ✓ | ✓ | O(n²) (implied) | ✓ AC | WIN: count-subarrays-with-NEGATIVES → chose prefix+hash on first instinct (no SW misfire — the exact discrimination he failed before). Bug = GOAL×KEY confusion (logged weakness): used LONGEST machinery (map stores index, `ans++`) on a COUNT problem. Fixed after 1 hint → map stores FREQUENCY, `seen[0]=1`, `ans += seen[sum-k]`, `seen[sum]++`. Verified on repeated-prefix case [1,-1,0]. |
| 10 | Hashing (complement-pairing / meet-in-middle) — DERIVED optimal himself ✓ | ✓ | ~ (said "indexes" not count) | wrote O(n⁴) brute (commented) | ✓ AC | WIN: derived the O(n²) pairing optimal himself (map A+B freq, look up −(C+D)). Bugs fixed via code review: (1) looked up +(C+D) not the NEGATIVE; (2) line 35 added wrong vars `nums1[k]+nums2[l]`. Also conflated brute/optimal in notes (wrote optimal in the brute slot). Open Q he raised: cast-position before/after long long — for THIS range (≤2^28) shouldn't overflow; suspect a 2nd change rode along (asked for the exact failing line). |
| 11 | Binary search (rotated) — RECOGNIZED ✓ | ✓ | ~ ("find the index") | linear scan O(n) | ✓ AC (heavily coached on impl) | Recognized BS instantly. Hardest variant — struggled on IMPLEMENTATION across 2 attempts: (1st) linear-scanned a half (no loop, O(n)); (2nd) tried to PRE-SPLIT into two BST-able halves — KEY MISCONCEPTION: splitting at mid does NOT give two sorted halves; only ONE half is sorted, the other holds the pivot → failed [5,6,1,2,3,4] target=1. LESSON he articulated: don't pre-split; in ONE loop, find the sorted half, use its ENDS (range) to pick the side. Needed the pseudocode structure (rung 4) after genuine effort + explicit ask-to-learn. NOT independent — re-test rotated BS later. |
| 12 | Two Pointers (sort + fix-one + converge) — RECOGNIZED ✓ | ✓ | ✓ | O(n³) 3-loops + set | ✓ AC O(n²)/O(1) | BEST REP of the drill. DERIVED the full path himself (only nudged): brute O(n³) → reframe "3Sum = fix one element + Two Sum on the rest" → two pointers (sort allowed b/c output is VALUES not indices, unlike P1) → killed the set via inline dedup. Bugs (all his recurring families): (1) target sign — compared sum vs nums[i] not −nums[i]; (2) `l<=r` vs `l<r` (distinct elements); (3) dedup sentinel collision — used `a&&nums[i]==a` where data value 0 collides with the "nothing yet" sentinel → fixed via neighbor-compare `nums[i]==nums[i-1]`. Learned: don't use a data value as a sentinel; sorted → compare to neighbor. |
| 13 | Variable Sliding Window — RECOGNIZED ✓ | ✓ | ✓ | O(n²) all-substrings | ✓ AC O(n) | Recognized SW instantly; chose to RE-DERIVE cold instead of recalling Striver (good). KEY CONCEPT taught (he was confused, then articulated back correctly): the "don't decrement max_freq" trick — window never shrinks, max_freq is a high-water mark; a stale max_freq can't fake a bigger answer, so no need to update it down → shrink with `if` not `while`. Impl bugs: l/r roles swapped (added at l, r never advanced), `char` vs `int` arr (overflow), backwards shrink condition. Perf: leftover `cout` → 1459ms, self-caught (CPP_GAPS: strip debug prints, recurred P9+P13). |
| 14 | | | | | | |
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
