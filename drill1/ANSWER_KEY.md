# DRILL 1 — ANSWER KEY 🔒

> **Open a row ONLY after you've written your pattern guess in `README.md`.** Peeking
> first turns a recognition drill into a copying exercise and teaches you nothing.
> Each row: LeetCode link (the judge) · pattern · the **recognition cue** (the surface
> feature that should have tipped you off). Approaches are one line — design the rest yourself.

---

## EASY

| # | LeetCode | Pattern | Recognition cue → approach |
|---|---|---|---|
| 1 | [LC1 Two Sum](https://leetcode.com/problems/two-sum/) | **Hashing** | UNSORTED + "find a pair summing to T" + return **indices** → one-pass hash map value→index, look up `T-x`. **NOT two pointers** (sorting destroys indices). *This is your MISTAKE #9 re-test.* O(n). |
| 2 | [LC125 Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) | **Two Pointers** | "same forwards/backwards" → converging pointers from both ends, skip non-alphanumeric. O(n). |
| 3 | [LC704 Binary Search](https://leetcode.com/problems/binary-search/) | **Binary Search** | SORTED + "O(log n)" + find exact value → classic BS. O(log n). |
| 4 | [LC303 Range Sum Query](https://leetcode.com/problems/range-sum-query-immutable/) | **Prefix Sum** | "many range-sum queries on a fixed array" → precompute prefix, `sum(i,j)=pre[j+1]-pre[i]`. O(1)/query. |
| 5 | [LC643 Max Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/) | **Sliding Window (fixed)** | "contiguous block of fixed length k" → slide a size-k window, add-right/drop-left. O(n). |
| 6 | [LC217 Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) | **Hashing** | UNSORTED + "any value appears twice" → hash set, return true on re-insert. O(n). |
| 7 | [LC88 Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) | **Two Pointers** | TWO SORTED arrays + merge in place → pointers from the **back** (free space is at the end). O(m+n). |
| 8 | [LC278 First Bad Version](https://leetcode.com/problems/first-bad-version/) | **Binary Search** | monotonic good→bad predicate + "fewest checks" → BS on the answer, find first true. O(log n). |
| 9 | [LC724 Find Pivot Index](https://leetcode.com/problems/find-pivot-index/) | **Prefix Sum** | "left sum == right sum" → total − prefix − self = right; scan. O(n). |
| 10 | [LC1456 Max Vowels in Substring](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/) | **Sliding Window (fixed)** | fixed length k + count a property → slide window counting vowels. O(n). |
| 11 | [LC242 Valid Anagram](https://leetcode.com/problems/valid-anagram/) | **Hashing** | "same chars, same counts" → int[26] freq (or map), inc/dec. **Counts, not presence.** O(n). |
| 12 | [LC283 Move Zeroes](https://leetcode.com/problems/move-zeroes/) | **Two Pointers** | in-place partition keeping order → slow pointer for next non-zero slot, fast scans. O(n). |
| 13 | [LC35 Search Insert Position](https://leetcode.com/problems/search-insert-position/) | **Binary Search** | SORTED + "where it would go" → lower-bound BS, return `lo`. O(log n). |
| 14 | [LC392 Is Subsequence](https://leetcode.com/problems/is-subsequence/) | **Two Pointers** | "in order, not contiguous" → two pointers, advance t always, s on match. O(n). |
| 15 | [LC374 Guess Number](https://leetcode.com/problems/guess-number-higher-or-lower/) | **Binary Search** | higher/lower oracle on a range → BS on [1,n]. O(log n). |

## MEDIUM

| # | LeetCode | Pattern | Recognition cue → approach |
|---|---|---|---|
| 16 | [LC560 Subarray Sum = K](https://leetcode.com/problems/subarray-sum-equals-k/) | **Prefix + Hash** | **NEGATIVES** + COUNT contiguous subarrays = k → prefix-sum freq map, `seen[0]=1`, add `seen[pre-k]`. NOT sliding window (negatives kill it). O(n). |
| 17 | [LC3 Longest Substring No Repeat](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | **Sliding Window (variable)** | "longest substring with a constraint" → grow right, shrink left on violation, track max. O(n). |
| 18 | [LC15 3Sum](https://leetcode.com/problems/3sum/) | **Two Pointers** | triplets summing to 0 → **sort** (allowed, no indices needed), fix one, converge the other two; skip dups. O(n²). |
| 19 | [LC33 Search Rotated Sorted](https://leetcode.com/problems/search-in-rotated-sorted-array/) | **Binary Search** | sorted-then-rotated + O(log n) → BS, decide which half is sorted each step. O(log n). |
| 20 | [LC347 Top K Frequent](https://leetcode.com/problems/top-k-frequent-elements/) | **Hashing (+ bucket/heap)** | "k most frequent" → freq map, then bucket-sort by count (O(n)) or a heap (O(n log k)). |
| 21 | [LC424 Longest Repeating Char Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/) | **Sliding Window (variable)** | "longest window, at most k changes" → window valid while `len − maxFreq ≤ k`. O(n). |
| 22 | [LC16 3Sum Closest](https://leetcode.com/problems/3sum-closest/) | **Two Pointers** | three elements closest to target → sort, fix one, converge two, track closest sum. O(n²). |
| 23 | [LC974 Subarray Sums Div by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/) | **Prefix + Hash** | NEGATIVES + COUNT divisible-by-k → prefix **remainder** freq map, `((r%k)+k)%k`, `seen[0]=1`. O(n). |
| 24 | [LC1011 Capacity to Ship](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) | **Binary Search on Answer** | "minimize the max capacity s.t. fits in D days" → BS on capacity ∈ [max weight, sum]; greedy feasibility check. **Koko's twin.** O(n log sum). |
| 25 | [LC438 Find All Anagrams](https://leetcode.com/problems/find-all-anagrams-in-a-string/) | **Sliding Window (fixed) + freq** | "all start indices of a rearrangement of p" → fixed window of len(p), compare **frequency** arrays. O(n). |
| 26 | [LC75 Sort Colors](https://leetcode.com/problems/sort-colors/) | **Two Pointers (Dutch flag)** | 0/1/2, one pass, in place → low/mid/high 3-way partition. *Your Dutch-flag re-code re-test — NOT selection sort this time.* O(n). |
| 27 | [LC1248 Count Nice Subarrays](https://leetcode.com/problems/count-number-of-nice-subarrays/) | **Prefix + Hash** (or atMost-SW) | COUNT subarrays with exactly k odds → map odd-count like a prefix sum (odd=+1), `seen[count-k]`. Discriminator: it's a COUNT, not a window-max. O(n). |
| 28 | [LC162 Find Peak Element](https://leetcode.com/problems/find-peak-element/) | **Binary Search** | "any peak, O(log n)" on unsorted-but-no-equal-adjacent → BS toward the higher neighbor. O(log n). |
| 29 | [LC454 4Sum II](https://leetcode.com/problems/4sum-ii/) | **Hashing** | 4 arrays, count tuples summing to 0 → map all A+B sums, look up `-(C+D)`. O(n²). |
| 30 | [LC1004 Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/) | **Sliding Window (variable)** | "longest run of 1s, flip ≤ k zeros" → window valid while zeros-inside ≤ k. O(n). |

## HARD

| # | LeetCode | Pattern | Recognition cue → approach |
|---|---|---|---|
| 31 | [LC42 Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) | **Two Pointers** | water at i = min(maxLeft,maxRight) − height[i] → converge from both ends, move the smaller wall, track running maxes. O(n). (DP/stack also work; 2ptr is O(1) space.) |
| 32 | [LC410 Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) | **Binary Search on Answer** | "minimize the largest" + contiguous split → BS on the answer ∈ [max, sum]; greedy "how many pieces if cap = mid?". **Capacity-to-Ship's twin.** O(n log sum). |
| 33 | [LC76 Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) | **Sliding Window (variable) + freq** | "shortest substring containing all of t" → grow to cover need, shrink while still valid, track min. O(n). |
| 34 | [LC4 Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) | **Binary Search** | "median of two sorted in O(log)" → BS the partition point on the shorter array so left half = right half. O(log min(m,n)). |
| 35 | [LC719 K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/) | **Binary Search on Answer + Two-Pointer count** | "k-th smallest pairwise distance" → sort; BS on distance d ∈ [0,max−min]; `count(d)` = pairs with distance ≤ d via the windowed `count += right−left`; smallest d with count ≥ k. **The exact problem we taught last session.** O(n log n + n log(maxDist)). |

---

### After you finish a batch
Bring me the recognition log. We grade together, log misses to `MISTAKE_JOURNAL.md` with
root cause + re-test, update `PROGRESS.md` levels with the evidence, and only the patterns
you name **cold and correct on first instinct** move toward L5.
