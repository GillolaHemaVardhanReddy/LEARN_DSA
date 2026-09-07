# M10 Backtracking — the full map

> Read `phase-2/notes/10-backtracking.md` first, then watch **[L6]** and **[L7]**.
> Everything below is one machine — `choose → explore → un-choose` — wearing different hats.
> **LEARN** = guided, builds to L3.  **PRACTICE** = reps, no promotion.  **TEST** = cold, the only L4→L5 path.

---

## LEARN ladder (`phase-2/learn/10-Backtracking/`)
Do them in this order. Each one adds **exactly one new idea** to the frame you already own.

| # | Problem | Diff | The ONE new idea | Video | Status |
|---|---|---|---|---|---|
| 01 | [LC78 Subsets](https://leetcode.com/problems/subsets/) | M | pick/not-pick fork · **un-choose** | [L6] | ✅ AC (7/10) · stress green |
| 02 | [LC46 Permutations](https://leetcode.com/problems/permutations/) | M | **loop over choices** (slot-frame) + a `used[]` that must ALSO be undone | [L12][L13] | ← next |
| 03 | [LC39 Combination Sum](https://leetcode.com/problems/combination-sum/) | M | **reuse** a choice (don't advance the index) + prune on target | [L8] | |
| 04 | [LC90 Subsets II](https://leetcode.com/problems/subsets-ii/) | M | **duplicate-skip rule** — sort, then skip same value at same depth | [L11] | |
| 05 | [LC131 Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/) | M | choices = **where to cut** (a range, not an element) + validity prune | [L17] | |
| 06 | [LC79 Word Search](https://leetcode.com/problems/word-search/) | M | backtracking on a **grid** — mark visited, unmark on return | [L18] | |
| 07 | [LC51 N-Queens](https://leetcode.com/problems/n-queens/) | H | **constraint sets** (col/diag) as undoable side-state · real pruning | [L14] | stretch |

**L3 is already earned** (LC78 written from memory, stress-green vs an independent oracle).
**L4 needs ≥2 easy + ≥2 medium, solo, judge-AC.** Backtracking has almost no true easies —
so the L4 bar here reads as **≥4 solo ACs across this ladder**, LC78 being #1.

---

## PRACTICE set (`phase-2/practice/10-Backtracking/`) — help allowed, no promotion
Run these **alongside** the learn ladder, not after it. Each maps to a learn problem it re-tests.

| Problem | Diff | Re-tests | Why it's here |
|---|---|---|---|
| [LC77 Combinations](https://leetcode.com/problems/combinations/) | M | 02 | the cleanest loop-frame there is — `start` index, fixed length k |
| [LC17 Letter Combinations](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) | M | 02 | choices come from a **map**, not the array. Classic phone-screen. |
| [LC22 Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) | M | 03 | choices constrained by *counts*, not a `used[]`. Pruning is the whole problem. |
| [LC216 Combination Sum III](https://leetcode.com/problems/combination-sum-iii/) | M | 03 | two constraints at once (count k **and** sum n) |
| [LC40 Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) | M | 04 | duplicate-skip + no reuse. The rule from 04, under pressure. |
| [LC47 Permutations II](https://leetcode.com/problems/permutations-ii/) | M | 02+04 | duplicate-skip meets `used[]`. The trickiest skip condition in the topic. |
| [LC93 Restore IP Addresses](https://leetcode.com/problems/restore-ip-addresses/) | M | 05 | partition + validity. Same shape as palindrome partitioning. |
| [LC698 Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/) | M | 01+07 | where backtracking meets "this needs real pruning or it TLEs" |
| [LC37 Sudoku Solver](https://leetcode.com/problems/sudoku-solver/) | H | 06+07 | the boss fight. `return bool`, short-circuit on first success. |

**Disguised drill owed (Phase-2 wall):** ≥1 interleaved set where the statement does *not* say
"return all subsets" — you have to recognize backtracking from the constraint bound (`n ≤ 20`).

---

## The Phase-2 wall (unchanged)
Don't cross into Phase 3 until **M8, M9, M10, M11 are ALL L4** and ≥1 disguised/interleaved drill is cleared.
- M8 Queues/Deque — **L3**, practice set unstarted (LC622/1438/862/1696, ≥2 AC → L4)
- M9 Recursion — **L4** ✅
- M10 Backtracking — **L3**, this ladder
- M11 Linked Lists — **L0**

---

## Order of operations, honestly
1. Read the notes (`phase-2/notes/10-backtracking.md`).
2. Watch **[L6]** — https://youtu.be/AxNNVECce8c — and **[L7]** — https://youtu.be/eQCS_v3bw0Q.
   L7 is the one that pays off most: same tree, three different jobs (print all / count / find one).
3. Then LC46, with the notes closed.

You already own the hard part. The un-choose invariant is the topic; the rest is which hat it wears.
