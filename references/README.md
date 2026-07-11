# references/ — the book layer for Kira's teaching

> **Purpose.** Ground every explanation in a *named, authoritative reference* — the way a
> good teacher says "this is Skiena's war story about X." This file pins, for each module,
> the exact book + chapter, and — critically — **HOW we use each book** (they have
> different jobs). Books reinforce the live derivation; they NEVER replace it.
>
> We already have: **Striver A2Z + videos** (`STRIVER_VIDEOS.md`) and **NeetCode 150**.
> This adds the *book* layer on top.

---

## 📚 OWNED — the PDFs in this folder (verified from their real tables of contents, 2026-07-11)

| Book | File | Pages | Edition confirmed | Its JOB on this journey |
|---|---|---|---|---|
| **Skiena — The Algorithm Design Manual** | `The Algorithm Design Manual by Steven S. Skiena.pdf` | 739 | **3rd ed.** (Ch.7 Combinatorial Search, Ch.8 DP, catalog Ch.11–18 = 3e) | ⭐ **The RECOGNITION brain.** War stories + Ch.10 "How to Design Algorithms" + the Ch.11–18 problem catalog = a pattern-transfer engine. Our #1 goal lives here. |
| **Laaksonen — Competitive Programmer's Handbook** | `book.pdf` | 296 | current (CSES) | **The C++ IMPLEMENTATION + technique reference.** Tightest idiomatic code; exact templates. Also our CP bridge for Phase 7. |
| **McDowell — Cracking the Coding Interview** | `Cracking the Coding Interview.pdf` | 708 | **6th ed.** | **The INTERVIEW-CONTEXT layer.** Big-O refresher, the **C/C++ chapter (12)**, **Testing (11) → feeds Gate C**, behavioral, and per-topic problem sets for extra reps. |
| **Halim — Competitive Programming 4, Book 1** | `cp4-1.pdf` | 329 | **CP4 Book 1** (19 Jul 2020 eBook) | **The CONTEST-DEPTH + graph/paradigm reference.** Ch.3 Problem-Solving Paradigms (Complete Search, binary-search-on-answer, Greedy, DP) and Ch.4 Graph (MST, Dijkstra, Bellman, Floyd) are best-in-set for our M16–M22. Backbone of Phase 7. *(Book 2 = the Phase-7 add.)* |

> **Note on the swap:** the plan recommended *Beyond* Cracking the Coding Interview (2025, pattern
> chapters). You brought the **original CTCI 6e** instead — that's fine: it covers the
> interview-process / C++ / testing layer the other two skip. If you ever want the pattern-first
> chapters, *Beyond* is an optional add later, not a need.

**Free companions (no PDF needed — cite freely):** `cp-algorithms.com` · `usaco.guide` ·
`algs4.cs.princeton.edu` (best union-find / BST **visuals**) · `cs.stonybrook.edu/~skiena`
(Skiena's free lectures tied to the book). *(Competitive Programming 4 — buy at Phase 7.)*

---

## 🛠️ HOW WE USE THE BOOKS — the protocol (fits how boss learns)

**Division of labor — never open all four for one thing:**
- **Stuck on WHAT approach?** → Skiena (Ch.10 decision framework + Ch.11–18 catalog + the war story for that pattern).
- **Writing the optimal / need the C++ idiom?** → Laaksonen (the template) or CTCI Ch.12 (C++ specifics).
- **Interview logistics / Big-O refresher / test-your-code discipline?** → CTCI.
- **Graph algorithm, DP paradigm, binary-search-on-answer, or contest depth?** → CP4 Book 1 (Ch.3–4). The go-to for M16–M22 and everything in Phase 7.

**The per-module protocol (standing):**
1. **Derive live FIRST.** Striver-then-practice holds — a book NEVER precedes boss's own
   derivation. Consolidation only. (Mid-derivation ≥80% there, not even the video overwrites him.)
2. **After the judge-AC:** read the ONE pinned primary section + its **war story** (Skiena) →
   boss writes the sharpened recognition cue in his own words into `PATTERN_JOURNAL.md`
   (that's Gate 4, teach-it-back — the book gives him better language for the cue).
3. **C++ idiom pass:** compare his code to Laaksonen's template for that technique. Bank any gap
   in `CPP_GAPS.md`.
4. **Recognition fuel:** Skiena Ch.10 ("How to Design Algorithms") + the catalog are the raw
   material for `/drill` — "you see this archetype → here's the known tool."

**Two Skiena chapters worth reading standalone (recognition multipliers):**
- **Ch.10 "How to Design Algorithms"** — a decision checklist for attacking any unseen problem.
  Read it once M10 closes; it *is* the meta-skill we're building.
- **Ch.11 "A Catalog of Algorithmic Problems"** (intro to Ch.12–18) — how to look up an archetype.

---

## 🎯 PER-MODULE REFERENCE MAP (pinned to the OWNED PDFs' real chapters)

> **S** = Skiena ADM 3e · **L** = Laaksonen CPH · **C** = CTCI 6e · **P** = CP4 Book 1. ⭐ = the standout for that module.

### Phase 1 — Foundations
| Module | Primary | Secondary |
|---|---|---|
| M1 Complexity | **S Ch.2** (Algorithm Analysis) | L "Time complexity" · C Part VI (Big O) |
| M2 Arrays & Hashing | **S Ch.3.7** (Hashing and Strings) | C IX.1 (Arrays & Strings) · L "Data structures" |
| M3 Two Pointers | **L "Amortized analysis → Two pointers method"** ⭐ | S Ch.4 (Searching) |
| M4 Sliding Window | **L "Amortized analysis → Sliding window minimum"** ⭐ | — (window logic threaded through L) |
| M5 Prefix Sum | **L "Range queries → Static array queries"** | S Ch.3 |
| M6 Binary Search | **S Ch.4** (Binary Search and Related Algorithms) | **P 3.3.1 "Interesting Usages of Binary Search"** ⭐ (binary-search-on-answer, your exact pattern) · L "Sorting → Binary search" |

### Phase 2 — Linear + Recursion
| Module | Primary | Secondary |
|---|---|---|
| M7 Stacks & Monotonic | **L "Amortized → Nearest smaller elements"** ⭐ (monotonic stack) | C IX.3 · S Ch.3.2 (Stacks/Queues) |
| M8 Queues/Deque *(light)* | **L "Amortized → Sliding window minimum"** ⭐ (monotonic deque) | C IX.3 |
| M9 Recursion | **C IX.8** (Recursion and Dynamic Programming) | S Ch.4 (Divide-and-Conquer: mergesort/quicksort) |
| **M10 Backtracking** *(current)* | **S Ch.7.1–7.2** (Backtracking + Search Pruning + Sudoku) ⭐ **+ S Ch.14** (Generating Permutations / Generating Subsets = LC46/LC78 literally) | **L Ch.5 "Complete search"** ⭐ · **P 3.2 "Complete Search"** (recursive complete search + pruning tips) |
| M11 Linked Lists | **C IX.2** (Linked Lists) | S Ch.3.1 (Contiguous vs Linked) |

### Phase 3 — Non-linear
| Module | Primary | Secondary |
|---|---|---|
| M12 Trees / traversals | **C IX.4** (Trees and Graphs) | L "Tree algorithms" · S Ch.3.4 |
| M13 BST | **S Ch.3.4** (Binary Search Trees) | free `algs4` booksite (best BST visuals) · C IX.4 |
| M14 Heaps / PQ | **S Ch.3.5** (Priority Queues) + **S Ch.4.3** (Heapsort) | P 2.3.1 (Binary Heap) · L "Data structures" |
| M15 Tries | **L "String algorithms → Trie structure"** | S Ch.12 (Suffix Trees/Arrays) · C IX.4 |

### Phase 4 — Graphs
| Module | Primary | Secondary |
|---|---|---|
| M16 Graph BFS/DFS | **S Ch.5** (Graph Traversal) ⭐ war stories | **P 4.2** (DFS/BFS/flood-fill/components — very thorough) · L "Graph traversal" · C IX.4 |
| M17 Topological Sort | **P 4.2.6 "Topological Sort"** ⭐ | L "Directed graphs → Topological sorting" · S Ch.5 + Ch.15 catalog |
| M18 Union-Find | **P 2.4.2 "Union-Find Disjoint Sets"** ⭐ (impl + apps) | L "Spanning trees → Union-find" · free `algs4` visuals |
| M19 Dijkstra (+ MST) | **P 4.3 (MST: Kruskal/Prim) + 4.4 (SSSP: Dijkstra/Bellman) + 4.5 (Floyd)** ⭐ best single ref | S Ch.6 (Weighted Graph Algorithms) · L "Shortest paths" |

### Phase 5 — DP, Greedy, Bit, Math
| Module | Primary | Secondary |
|---|---|---|
| M20 1-D DP | **S Ch.8** (Dynamic Programming) ⭐ | **P 3.5** (DP Illustration + classical examples) · L "Dynamic programming" · C IX.8 |
| M21 2-D / sequence DP | **P 3.5.2 "Classical Examples"** (knapsack/LCS) + **L "DP → Edit distance / grid paths"** | S Ch.8 (approx string matching, LIS, partition) |
| M22 Greedy | **L "Greedy algorithms"** + **P 3.4 "Greedy"** | S Ch.1.2 (Selecting the Right Jobs) · free K-T Ch.4 |
| M23 Intervals | **L "Greedy → Scheduling"** | S Ch.1.2 |
| M24 Bit Manipulation | **L "Bit manipulation"** ⭐ | C IX.5 · S |
| M25 Math & Geometry *(proposed §1 ROADMAP)* | **L "Number theory" + "Geometry"** | S Ch.13 (Numerical) / Ch.17 (Geometry) · C IX.6 |

---

## ⚡ IMMEDIATE — boss is on M10 Backtracking RIGHT NOW
After he closes **LC46 Permutations** (currently mid-derivation), the consolidation reading is:
- **Skiena Ch.7.1 Backtracking + Ch.7.2 Search Pruning** (the general skeleton + when to prune).
- **Skiena Ch.14 → "Generating Permutations" & "Generating Subsets"** — the catalog entries for
  the exact two problems he's doing (LC46 + LC78). See how the pro states the general algorithm.
- **Laaksonen Ch.5 "Complete search"** — the tight C++ version of subsets/perms/backtracking/pruning.
Then he writes the sharpened cue into `PATTERN_JOURNAL.md`. Do NOT hand these before he derives LC46.

---

## MAINTENANCE
- When a module opens, Kira names its pinned chapter live (consolidation, after the derivation).
- New PDF arrives → add to the OWNED table with confirmed edition; fix any chapter drift here.
- Changes rarely (a reference, not a live tracker).
