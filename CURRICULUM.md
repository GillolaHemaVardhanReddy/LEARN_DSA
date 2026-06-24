# CURRICULUM.md — DSA Mastery Path for Hema Vardhan

> The map. Dependency-ordered, calibrated to the goal, with a concrete problem
> ladder per module. This is a plan, not a memory file — it changes rarely.
> Live state (what's mastered, what's due) lives in `PROGRESS.md` and
> `REVISION_QUEUE.md`.

---

## Goal calibration

**Goal sequence (decided 2026-06-24): Interview → CP → Advanced.**
1. **INTERVIEW-READY FIRST (priority #1, ~Nov 2026):** solve the **majority of medium problems
   independently**, with correct time/space analysis, by recognizing the underlying pattern.
   **Core tier = Phases 1–6** is everything needed to hit that bar (NeetCode 150 / Blind 75 spine).
2. **COMPETITIVE / CONTEST TRACK SECOND (Phase 7, after interview-ready):** the advanced tier is no
   longer "optional" — it's the **planned back half**. Goal: LeetCode-contest competitive (reliable
   Q3, fighting for Q4) + Codeforces rating climb. This needs CP-specific topics + a timed-contest
   regimen the interview track never touches (see Phase 7).
3. **ADVANCED TIER THIRD (Phase 8, after contest-competitive):** kept on the map, sequenced last — the
   red-coder/ICPC-deep layer (lazy segtree, suffix automaton, flows, DP optimizations, HLD, FFT).

Interview skills transfer 100% into CP — nothing is wasted. But CP has a **higher ceiling and longer
road**; do NOT dilute Phase 1–6 to rush it. Interview-ready is the gate that unlocks the CP track.

Schedule below is **indicative**. The real projected date is recomputed in
`PROGRESS.md` from actual weekly hours and observed velocity.

---

## Dependency graph (don't learn a node before its parents)

```
Complexity Analysis
   │
   ▼
Arrays & Hashing ──► Two Pointers ──► Sliding Window
   │                      │
   │                      └──► Prefix Sum
   ▼
Binary Search  (needs: arrays, "sorted/monotonic" intuition)
   │
   ▼
Stacks ─► Monotonic Stack          Queues / Deque ─► Monotonic Queue
   │
   ▼
Recursion ─► Backtracking
   │
   ▼
Linked Lists (uses fast/slow pointers, reversal)
   │
   ▼
Trees ─► BST ─► Heaps ─► Tries
   │
   ▼
Graphs (BFS/DFS) ─► Topological Sort ─► Union-Find ─► Dijkstra
   │
   ▼
Dynamic Programming (1D ─► 2D ─► on subsequences/grids/trees)
   │
   ▼
Greedy ─► Intervals          Bit Manipulation (anytime after Arrays)
```

Rule from `CLAUDE.md`: never advance past an unmet prerequisite. A module
is "cleared" only when its mastery gate (L5+) is met in `PROGRESS.md`.

---

## Phase overview (indicative)

| Phase | Modules | Indicative weeks |
|---|---|---|
| 1 — Foundations | Complexity, Arrays & Hashing, Two Pointers, Sliding Window, Prefix Sum, Binary Search | 1–6 |
| 2 — Linear + recursion | Stacks/Monotonic, Queues/Deque, Recursion, Backtracking, Linked Lists | 6–11 |
| 3 — Non-linear | Trees, BST, Heaps, Tries | 11–16 |
| 4 — Graphs | Representation, BFS/DFS, Topo sort, Union-Find, Dijkstra (intro) | 16–20 |
| 5 — DP + Greedy | 1D DP, 2D DP, Greedy, Intervals, Bit Manipulation | 20–25 |
| 6 — Consolidation | Mixed pattern drills, Blind 75 / NeetCode 150, mock interviews | 25–26+ |
| **7 — Competitive track** | CP topics + timed-contest regimen (see Phase 7 below) — **starts AFTER interview-ready** | post-Nov-2026 |
| **8 — Advanced tier** | Red-coder depth (lazy segtree, suffix automaton, flows, DP opts, HLD, FFT) — **AFTER contest-competitive** | post-Phase-7 |

---

## Module spec format

Each module below gives: **Prereqs · Objective · Patterns + trigger · Problem
ladder (E/M, optional H) · Mastery gate.** Problem names are canonical
LeetCode/Blind-75-style problems. Work the ladder top-to-bottom.

---

# PHASE 1 — FOUNDATIONS

### M1. Complexity Analysis
- **Prereqs:** none.
- **Objective:** evaluate a solution before coding it.
- **Covers:** Big-O/Θ/Ω, time vs space, nested-loop counting, recursive cost (recurrences, intuition), amortized cost, log intuition.
- **Pattern trigger:** *constraints tell you the target complexity.* n ≤ 20 → exponential/backtracking ok; n ≤ ~10³ → O(n²) ok; n ≤ ~10⁵–10⁶ → need O(n log n) or O(n); huge n → O(log n)/O(1).
- **Ladder:** no LC problems — instead, analyze the complexity of every snippet/solution from here on. Gate is applied, not problem-counted.
- **Gate:** correctly analyze unseen snippets, compare two solutions, predict the needed complexity from constraints.

### M2. Arrays & Hashing
- **Prereqs:** M1.
- **Objective:** trade time for space with maps/sets; master frequency logic.
- **Patterns:** hashing for O(1) lookup; frequency counting. **Trigger:** "have I seen X before / how many times" → hash map/set.
- **Ladder:** Contains Duplicate (E), Valid Anagram (E), Two Sum (E), Group Anagrams (M), Top K Frequent Elements (M), Product of Array Except Self (M), Longest Consecutive Sequence (M).
- **Gate:** recognize when a hash collapses an O(n²) scan to O(n), unprompted.

### M3. Two Pointers
- **Prereqs:** M2.
- **Patterns:** opposite-end pointers, same-direction pointers. **Trigger:** "sorted array + find pair/triple" or "compare from both ends" → two pointers.
- **Ladder:** Valid Palindrome (E), Two Sum II – Sorted (M), 3Sum (M), Container With Most Water (M). *Stretch:* Trapping Rain Water (H).
- **Gate:** derive the pointer-movement invariant and justify why nothing is missed.

### M4. Sliding Window
- **Prereqs:** M2, M3.
- **Patterns:** fixed window, variable window. **Trigger:** "longest/shortest/max/min over a *contiguous* subarray/substring" → sliding window.
- **Ladder:** Best Time to Buy/Sell Stock (E), Longest Substring Without Repeating Characters (M), Longest Repeating Character Replacement (M), Permutation in String (M). *Stretch:* Minimum Window Substring (H).
- **Gate:** state when to shrink vs grow the window and why it stays O(n).

### M5. Prefix Sum
- **Prereqs:** M2.
- **Patterns:** prefix sums, hash-of-prefix. **Trigger:** "sum/count over many ranges" or "subarray summing to k" → prefix sum (+ hash map for k).
- **Ladder:** Range Sum Query – Immutable (E), Find Pivot Index (E), Subarray Sum Equals K (M), Contiguous Array (M).
- **Gate:** explain why `prefix[j]-prefix[i]` gives a range sum and how the hash trick finds count = k.

### M6. Binary Search
- **Prereqs:** M1; sorting intuition.
- **Patterns:** classic search, lower/upper bound, first/last occurrence, **binary search on the answer**. **Trigger:** "sorted, OR a monotonic yes/no over a numeric range, OR minimize-the-maximum" → binary search.
- **Ladder:** Binary Search (E), Search a 2D Matrix (M), Koko Eating Bananas (M), Find Minimum in Rotated Sorted Array (M), Search in Rotated Sorted Array (M). *Stretch:* Median of Two Sorted Arrays (H).
- **Gate:** spot a hidden binary-search (search-on-answer) problem with no hint.

---

# PHASE 2 — LINEAR STRUCTURES + RECURSION

### M7. Stacks & Monotonic Stack
- **Prereqs:** M2.
- **Patterns:** LIFO, monotonic stack. **Trigger:** "matching/nesting" → stack; "next/previous greater/smaller element" → monotonic stack.
- **Ladder:** Valid Parentheses (E), Min Stack (M), Evaluate Reverse Polish Notation (M), Daily Temperatures (M), Car Fleet (M). *Stretch:* Largest Rectangle in Histogram (H).
- **Gate:** recognize the "next greater" family and explain the amortized O(n).

### M8. Queues & Deque
- **Prereqs:** M7.
- **Patterns:** FIFO, circular buffer, monotonic deque. **Trigger:** "max/min of every window of size k" → monotonic deque.
- **Ladder:** Implement Queue using Stacks (E), Number of Recent Calls (E), Sliding Window Maximum (H, but learn it here as the canonical deque problem).
- **Gate:** explain why the deque keeps the window's extreme in O(1) amortized.

### M9. Recursion
- **Prereqs:** M1.
- **Patterns:** base case + recursive case, call stack, recursion tree. **Trigger:** "problem defined in terms of smaller versions of itself."
- **Ladder:** Fibonacci / factorial (warmup), Reverse String (recursive) (E), Pow(x,n) (M), Merge Two Sorted Lists recursively (E). Plus: trace recursion trees by hand.
- **Gate:** dry-run an unseen recursion mentally and state its time/space (stack depth).

### M10. Backtracking
- **Prereqs:** M9.
- **Patterns:** choose → explore → un-choose. **Trigger:** "generate all subsets/permutations/combinations" or "explore all paths/placements."
- **Ladder:** Subsets (M), Combination Sum (M), Permutations (M), Subsets II (M), Word Search (M), Palindrome Partitioning (M). *Stretch:* N-Queens (H).
- **Gate:** write the choose/explore/un-choose skeleton from memory and prune correctly.

### M11. Linked Lists
- **Prereqs:** M9 (and M3's pointer intuition).
- **Patterns:** dummy node, reversal, fast/slow pointers, merge. **Trigger:** "detect a cycle / find middle / find kth-from-end" → fast/slow; "reorder/reverse in place" → pointer surgery.
- **Ladder:** Reverse Linked List (E), Merge Two Sorted Lists (E), Linked List Cycle (E), Remove Nth Node From End (M), Reorder List (M), Copy List with Random Pointer (M), Add Two Numbers (M), LRU Cache (M). *Stretch:* Merge k Sorted Lists (H).
- **Gate:** implement reversal and cycle detection from memory; explain Floyd's why.

---

# PHASE 3 — NON-LINEAR

### M12. Trees (binary trees, traversals, DFS/BFS)
- **Prereqs:** M9, M11.
- **Patterns:** DFS (pre/in/post), BFS (level order), "return info up the tree" (tree DP lite). **Trigger:** "process all nodes / depth / path / level" → tree traversal.
- **Ladder:** Invert Binary Tree (E), Maximum Depth (E), Same Tree (E), Diameter of Binary Tree (E/M), Balanced Binary Tree (E/M), Subtree of Another Tree (E/M), Level Order Traversal (M), Right Side View (M), Count Good Nodes (M). *Stretch:* Binary Tree Maximum Path Sum (H), Serialize/Deserialize (H).
- **Gate:** choose DFS vs BFS correctly and solve a medium tree problem independently.

### M13. Binary Search Trees
- **Prereqs:** M12, M6.
- **Patterns:** BST invariant (left<root<right), in-order = sorted. **Trigger:** "ordered tree / kth smallest / validate ordering."
- **Ladder:** Lowest Common Ancestor of a BST (M), Validate Binary Search Tree (M), Kth Smallest Element in a BST (M), Construct BST from preorder (M).
- **Gate:** exploit the BST property to get O(h) instead of O(n).

### M14. Heaps / Priority Queue
- **Prereqs:** M12.
- **Patterns:** min/max heap, "top-K", two-heaps for median. **Trigger:** "k largest/smallest / running median / repeatedly take the extreme."
- **Ladder:** Kth Largest Element in a Stream (E), Last Stone Weight (E), K Closest Points to Origin (M), Kth Largest Element in an Array (M), Task Scheduler (M). *Stretch:* Find Median from Data Stream (H).
- **Gate:** recognize a top-K/streaming-extreme problem and justify heap over sort.

### M15. Tries
- **Prereqs:** M12.
- **Patterns:** prefix tree. **Trigger:** "prefix search / autocomplete / many-words dictionary lookups."
- **Ladder:** Implement Trie (M), Design Add and Search Words (M). *Stretch:* Word Search II (H).
- **Gate:** implement insert/search and explain the time/space tradeoff vs a hash set.

---

# PHASE 4 — GRAPHS

### M16. Graph foundations + BFS/DFS
- **Prereqs:** M12 (traversal), M8 (queue), M9 (recursion).
- **Patterns:** adjacency list, grid-as-graph, flood fill, BFS shortest path on unweighted, multi-source BFS. **Trigger:** "grid/connections, reach/spread/components/shortest unweighted."
- **Ladder:** Number of Islands (M), Clone Graph (M), Max Area of Island (M), Rotting Oranges (M, multi-source BFS), Pacific Atlantic Water Flow (M), Surrounded Regions (M), Number of Connected Components (M).
- **Gate:** model a problem as a graph and pick BFS vs DFS with reasoning.

### M17. Topological Sort
- **Prereqs:** M16.
- **Patterns:** Kahn's (in-degree BFS) / DFS post-order; cycle detection on DAGs. **Trigger:** "ordering with dependencies / prerequisites / can-you-finish."
- **Ladder:** Course Schedule (M), Course Schedule II (M), Graph Valid Tree (M).
- **Gate:** detect a cycle and produce a valid ordering, explaining both methods.

### M18. Union-Find (DSU)
- **Prereqs:** M16.
- **Patterns:** disjoint sets, path compression + union by rank. **Trigger:** "dynamic connectivity / redundant connection / grouping."
- **Ladder:** Number of Connected Components (M), Redundant Connection (M), Accounts Merge (M).
- **Gate:** implement DSU with both optimizations and state the near-O(1) amortized cost.

### M19. Weighted shortest paths (intro)
- **Prereqs:** M16, M14.
- **Patterns:** Dijkstra (non-negative weights, heap). **Trigger:** "shortest/cheapest path with weights." (Bellman-Ford / Floyd-Warshall: learn the idea, treat as stretch.)
- **Ladder:** Network Delay Time (M), Cheapest Flights Within K Stops (M).
- **Gate:** explain why Dijkstra needs non-negative weights and uses a min-heap.

---

# PHASE 5 — DP, GREEDY, BIT

### M20. 1-D Dynamic Programming
- **Prereqs:** M9 (recursion), M1.
- **Patterns:** memoization → tabulation; define state + transition. **Trigger:** "count ways / max-min over choices / optimal substructure + overlapping subproblems."
- **Ladder:** Climbing Stairs (E), House Robber (M), House Robber II (M), Coin Change (M), Longest Increasing Subsequence (M), Word Break (M), Maximum Product Subarray (M), Decode Ways (M), Palindromic Substrings (M).
- **Gate:** go memo→tab on an unseen 1-D problem and state the recurrence cleanly.

### M21. 2-D / grid / sequence DP
- **Prereqs:** M20.
- **Patterns:** two-index state, grid paths, two-sequence DP. **Trigger:** "two strings/arrays compared" or "paths in a grid" or "0/1 knapsack-like."
- **Ladder:** Unique Paths (M), Longest Common Subsequence (M), Coin Change II (M), Target Sum (M), Partition Equal Subset Sum (M). *Stretch:* Edit Distance (M/H), Longest Increasing Path in Matrix (H).
- **Gate:** design the 2-D state and transition for an unseen problem.

### M22. Greedy
- **Prereqs:** M1; M20 (to contrast greedy vs DP).
- **Patterns:** local-optimal-is-global, exchange argument. **Trigger:** "can I justify that the greedy choice is safe?" — and prove it (or fall back to DP).
- **Ladder:** Maximum Subarray / Kadane (M), Jump Game (M), Jump Game II (M), Gas Station (M), Hand of Straights (M), Partition Labels (M).
- **Gate:** give an exchange-argument-style justification for why a greedy choice is correct.

### M23. Intervals
- **Prereqs:** M22 (sorting + greedy).
- **Patterns:** sort by start/end, sweep. **Trigger:** "overlapping intervals / merge / max concurrent."
- **Ladder:** Merge Intervals (M), Insert Interval (M), Non-overlapping Intervals (M), Meeting Rooms (E), Meeting Rooms II (M).
- **Gate:** pick the right sort key and explain it.

### M24. Bit Manipulation
- **Prereqs:** M1 (can start any time after M2).
- **Patterns:** XOR tricks, masks, subset enumeration via bits. **Trigger:** "pairs cancel / toggle / fixed small set of states."
- **Ladder:** Single Number (E), Number of 1 Bits (E), Counting Bits (E/M), Missing Number (E), Reverse Bits (E), Sum of Two Integers (M).
- **Gate:** use XOR/masks to remove a hash map or extra pass.

---

# PHASE 6 — CONSOLIDATION & INTERVIEW

### M25. Mixed pattern drills + problem sets
- Run `DRILL` sessions (name-the-pattern, no full coding) across all Phase 1–5 patterns until recognition is automatic.
- Work a curated track: **Blind 75 → NeetCode 150** (or Grind 169 if more reps help).
- Re-solve previously failed problems from `MISTAKE_JOURNAL.md` cold.

### M26. Interview skills
- `INTERVIEW MODE` mocks: think aloud, state complexity unprompted, test your own code, discuss tradeoffs and alternatives.
- Track communication, decomposition, complexity accuracy, optimization, testing.

---

# PHASE 7 — COMPETITIVE PROGRAMMING TRACK  (the planned back half — starts AFTER interview-ready)

> Decided 2026-06-24: boss wants to be **LeetCode-contest competitive + Codeforces rating climber**.
> This is a *second sport* on top of the interview foundation. Do NOT start until Phases 1–6 are
> solid (interview-ready gate met) — but it IS the plan, not an afterthought. Detailed ladders get
> built when we arrive; this is the scope sketch.

**Why a separate track:** interview prep = recognize ~18 known patterns. CP = *speed on unseen shapes*
under a 90-min, 4-problem, ranked-by-time format. Different muscle. Foundation transfers; ceiling is higher.

### CP-specific TOPICS (not covered, or only grazed, in the interview core)
- **Math heavy:** number theory (primes, sieve, modular inverse, CRT), combinatorics (nCr mod p,
  inclusion-exclusion), probability/expected value, basic game theory (Nim, Grundy).
- **Advanced DP:** bitmask DP, digit DP, DP on trees, DP optimizations (prefix/convex-hull/divide-conquer).
- **Range structures:** Segment Tree (point update/range query), Fenwick/BIT, Sparse Table.
- **Graphs++:** Bellman-Ford, Floyd-Warshall, MST (Kruskal/Prim), bridges/articulation, SCC (Tarjan/Kosaraju),
  LCA (binary lifting).
- **Strings:** KMP, Z-algorithm, Rabin-Karp (rolling hash), tries++.
- **Geometry:** convex hull, line sweep, orientation/cross-product basics.
- **Techniques:** coordinate compression, meet-in-the-middle, ternary search, constructive/greedy with proof, ad-hoc.

### CP-specific REGIMEN (the part that's NOT just "more topics")
- **Weekly timed contests** (LeetCode weekly/biweekly + Codeforces Div 3/2) — the speed rep.
- **Upsolving:** after every contest, solve the 1–2 you couldn't, cold, and journal the trick.
- **Virtual contests** for volume; track a **rating goal** (e.g. CF pupil → specialist → expert).
- **Speed-typing the templates** (the interview track doesn't need this; CP does).

> Until interview-ready is banked, CP stays parked. The moment we clear Phase 6, this becomes the live plan.

---

# PHASE 8 — ADVANCED TIER  (the deepest layer — AFTER you're already contest-competitive)

> Kept on the map (boss's call, 2026-06-24), sequenced **after Phase 7**. This is red-coder / ICPC-deep
> material — overkill for most contests until you're consistently fighting for the hard problems. Don't
> touch until the CP track has you contest-competitive.

- **Range structures++:** Segment Tree with **lazy propagation**, persistent/merge-sort tree, **Mo's
  algorithm** + offline queries.
- **Strings++:** suffix array, suffix automaton, Aho-Corasick.
- **Flows/matching:** max-flow / min-cut (Dinic), min-cost-max-flow, bipartite matching.
- **DP optimizations:** convex-hull trick, divide-and-conquer DP, Knuth, SOS DP.
- **Trees++:** heavy-light decomposition, centroid decomposition, Euler tour + segtree.
- **Math++:** FFT/NTT, advanced number theory (Möbius, multiplicative functions), matrix exponentiation.

---

# APPENDIX A — Foundational Primitives (taught just-in-time)

> These are **not** a sequential module you grind through. They are a toolbox the
> mentor teaches in 5–15 minutes **the moment a problem needs one**, then reinforces.
> The mentor must never assume the learner already has these (see `CLAUDE.md`
> §4, "primitives just-in-time").

### A1. Bitwise operators  (prerequisite for M24; teach before, or as soon as bits appear)
- Binary representation, bit indexing, signed vs unsigned (brief), integer width / overflow.
- Operators: AND `&`, OR `|`, XOR `^`, NOT `~`, left shift `<<`, right shift `>>`.
- Core idioms: get bit `(x>>i)&1` · set `x|(1<<i)` · clear `x & ~(1<<i)` · toggle `x^(1<<i)` · lowest set bit `x & -x` · drop lowest set bit `x & (x-1)` · power of two `x & (x-1) == 0`.
- XOR properties: `a^a=0`, `a^0=a`, commutative + associative — the basis of "Single Number."

### A2. Math you'll actually use
- **Logs & exponents:** why O(log n) appears (halving), 2^k intuition. *(also in M1)*
- **Modular arithmetic:** `(a+b)%m`, `(a*b)%m`, why "mod 1e9+7", avoiding overflow.
- **GCD / LCM + Euclid's algorithm:** also a clean recursion exercise.
- **Fast / binary exponentiation:** practiced via Pow(x,n) in M9.
- **Combinatorics basics:** counting principle, nCr — surfaces in some counting DP / grid-path problems.
- **Overflow & integer limits:** when can a sum/product exceed 32/64-bit?
- *Optional:* primes & Sieve of Eratosthenes (occasional), expected value (rare).

### A3. Teach-on-demand hooks (where each primitive surfaces)
- Modular arithmetic → M2 Hashing, and Rabin-Karp / rolling hash (Advanced).
- GCD → number/array problems; introduce near M9 as a recursion example.
- Bitwise operators → before M24; reused in bitmask DP (Advanced).
- Overflow awareness → flag at M5 (prefix sums) and M20–21 (DP) whenever values grow.

---

## How this file is used
- The mentor picks the **next highest-ROI module** from here based on `PROGRESS.md`.
- Each problem solved updates `PATTERN_JOURNAL.md` (cue) and `PROGRESS.md` (level).
- Clearing a module's gate (L5+) unlocks its dependents in the graph above.
