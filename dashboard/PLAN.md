# PLAN.md — the 11-month DSA + Competitive Programming plan (v2 · written 2026-09-07)

> **One plan, one dose, one topic at a time.** Written after the 1.5-month layoff. This file
> replaces `CURRICULUM.md`, `TRAINING_PLAN.md`, `SPRINT_PLAYBOOK.md`, `SPRINT_SCHEDULE.md`,
> `ROADMAP_PLAN.md`, `FORGE_LADDER.md` and `FILE_GUIDE.md`. Kira reads §4 (the day) every
> session and §7 (the calendar) every Monday. Boss reads §0–§2 once, then lives in §4.
>
> **Status: DECIDED 2026-09-07 (boss's calls in §0). Refactor executed the same day.**

---

## 0. DECISIONS — the ones only boss can make

| # | Decision | Kira's default (used if boss says "go") | Boss's call |
|---|---|---|---|
| D1 | **Daily anchor + budget** | Anchor: *"after ___"* (boss names it). Weekday **60–90 min, hard cap 90**. Sat up to 3 h (hard problem or biweekly). Sun = contest 90 min + one upsolve ≤60 min, nothing else. ≈ **10–13 h/week.** Want more? Add a **second 60-min block** in the day, never a longer session (splitting ≈ 2× retention, §2 rule 2). | **✅ 45 min standard, cap 60, for month 1** (RECALL 10 · BUILD 30 · LOOK BACK 5). Kira raises it to 60–90 after **day 30 (2026-10-07)** if ≥ 20 of 30 days are kept. **Weekends (added later 09-07): 2 h morning + 2 h evening, Sat and Sun** → §4.2b. ≈ 13 h/week. |
| D2 | **Contests** | **LeetCode Weekly** (every Sun 08:00 IST) + **Biweekly** (alt Sat 20:00 IST) from **this Sunday, 2026-09-13**. **GFG Weekly is PAUSED** (see §6) → substitute **CodeChef Starters** (Wed 20:00 IST) from month 2. **Codeforces** Div 3/4 + Educational from month 3 (Dec). | **✅ as proposed.** |
| D3 | **LeetCode username** | Needed: the MCP session is signed out and no username is on file. Give the handle → dashboard tracks ACs + contest rating. (Re-login the MCP only if you want submission verification.) | **✅ `hemavardhan2076`** → `dashboard/CONTESTS.md`. |
| D4 | **Old planning docs** | Delete the 7 superseded files (git history keeps them). Keep `STRIVER_VIDEOS.md`, `CPP_GAPS.md`, `references/` under `dashboard/`. | **✅ deleted.** |
| D5 | **Re-entry style (Tier 0)** | **Test → repair → move** per old topic (1–3 days each): cold checkpoint first, repair only what leaked. Not a from-scratch re-teach. | ✅ default. |
| D6 | **Root folder** | Only `.claude/` + config dotfiles (`.gitignore`, `.mcp.json`, `.vscode/`). **No root README** (GitHub shows `dashboard/README.md` fine when linked). | ✅ default. |
| D7 | **Problem-file ceremony** | LEARN problems keep BRUTE → BRIDGE → OPTIMAL (question-holes). REPS = plain `solution.cpp` (signature + your code). **Stress harness = optional**, added on request only (you run on LC, not locally). | ✅ default. |
| D8 | **Finish the comeback gauntlet first?** | **Yes — Q10→Q20 on days 1–2** (cards, ~2 min each, statements seeded with examples). It's the cheapest full-map baseline we'll ever get, and it becomes the first `tests/mixed/` asset. Parts B/C are replaced by the per-topic Tier-0 checkpoints (same repair idea, one topic at a time). | ✅ default. |
| D9 | **The teaching operating system** | Boss's add-on ask: day→goal traceability, the stuck protocol, topic mastery, how tests are built, references, struggle handling, and a meta-learning lab that experiments with how he learns. | **✅ → `dashboard/SYSTEM.md`** (companion to this file). |

---

## 1. WHY v1 COLLAPSED — receipts, not blame

| Receipt (from the repo) | What it says |
|---|---|
| Commits per week, Jun 8 → Aug 9: **52 → 17 → 10 → 20 → 10 → 6 → 1 → 0 → 2** | A sprint week, then a decay curve to zero. Classic over-ambitious start. |
| **105** problem files scaffolded, **46** never finished | The system generated more work than one person could consume. Every unfinished file = an open loop = quiet guilt. |
| 24-Q mixed gauntlet + 9-hard gauntlet + topic sets + Phase-2 topics + a 30-row revision queue, **all open at once** | Many topics at a time. You said it: *"multiple topics at a time is worst."* The research agrees (§2 rule 3). |
| Per problem: brute + bridge + optimal + stress `main()` + `problem.md` + `notes.md` + journal + mistakes + 6 gates | ~1 h of ceremony per problem, and you only ever run code on LeetCode. |
| A **5-month** target → a 6-topics-in-6-days sprint schedule | "fast fast." Planning-fallacy: people predict 34 days, take 55 (Buehler 1994). |
| CP track **parked until interview-ready**; one contest (Jun 20) zeroed, no follow-up loop | Nothing to *use* the tools on. You said it: *"losing interest due to lacking of how to use the things I learn."* |
| Curriculum listed 24 modules; the **derivation between them** lived only in Kira's head | You learn like a mathematician: A ⇒ B ⇒ C. A list of modules is not a derivation. |

**What survived (also receipts):** on 7/24 you named hashing cold after 8 days off; on 8/09 you *derived* the 4-sum hashing machine and the sliding-window machine cold after a month. The tools are alive; the **names, the machinery details, and the habit** decayed. Relearning after a layoff is ~3–5× cheaper than first learning (Ebbinghaus savings, Murre & Dros 2015). **This is a re-entry, not a restart.**

### 1.1 The 2026-08-10 session (it was only on GitHub — pulled in today) changes two things

That session ran gauntlet Q5–Q9 (running score after 9: **1 ✅ · 5 🟡 · 3 ❌**). Two findings are load-bearing for this plan:

1. **Tool-carryover (M#12), not decay, is the headline leak.** Q5 you chose recursion → Q6 opened *"here also its pick not pick"* (a subarray problem) → you invented sliding window for Q6 → Q7 opened *"this is a fixed sliding window"* (a sort + two-pointer problem). Each answer inherited the previous question's tool. **It hid for weeks because inside a single-topic folder, carrying the topic's tool forward is always right.** It only fires under interleaving — i.e. in an interview or a contest. *What it changes here:* (a) the **4-question disqualifier gate** becomes step one of every problem, before any tool is named (§4.1); (b) the daily **RECALL slot is always a different topic** than the day's BUILD — 10 minutes of mixed retrieval is exactly the instrument that catches this, and it costs nothing. Your "one topic at a time" rule is right for *learning*; this small mixed dose is for *routing*.
2. **Complexity was wrong on 6 of 9 (M#13)** — fluent, fast, and wrong (`O(n log n)` on a problem with no sort and no halving). A wrong bound *hides the bottleneck* (Q3: you called the brute O(n), so there was "nothing to optimize" and the monotonic stack became unreachable). *What it changes here:* topic **00 is an active 2-day item in week 1**, and every LOOK BACK states the bound as a sentence with the work in it — *which line produces each factor*.

Also confirmed that session: **seeding every statement with 2–3 concrete examples removed reading stalls 5 for 5** — standing rule for Kira. And: **a cue that only fires on-topic isn't banked** (the subarray-vs-subsequence cue you wrote on 7/14 did not fire on Q6) — which is why cards get re-fired cold and mixed (§5), never re-read. The good news from the same session: **your repair machinery is fully intact** — Q6 self-corrected unprompted, Q9 you built a correct multiset fix from one probe. Routing is unguarded; everything downstream of a correct route works.

---

## 2. THE 10 RULES (each traces to evidence; sources in §10)

1. **A fixed small dose beats a big variable one.** Floor = one retrieval rep (≤10 min). Standard = ~75–90 min. Hard cap; stop mid-problem if needed and write the resume point. *(Ericsson: effective deliberate practice ≈ 1 h/day; Beshears 2021: rigid windows backfire, flexible timing + a default anchor wins.)*
2. **Split, don't stack.** 9 problems in one sitting retained no better than 3 (Rohrer & Taylor 2006); the *same* problems split over two sessions ≈ **2× retention** at 4 weeks. So: never a 24-problem drill again. Tomorrow's 3 beat today's 9.
3. **Block the NEW, interleave the OLD — in small doses.** Blocked practice is better for *first* learning; interleaving is better for *recognition and retention* (Rohrer 2020 RCT, d = 0.83) — but pure interleaving is an *undesirable* difficulty for a learner still acquiring the pattern (Hwang 2024). Recipe: **one new topic at a time** (2–4 blocked reps), and the only cross-topic work per day is **1–2 short revision reps** from old topics. If practice accuracy drops below ~50 %, re-block.
4. **Retrieve, never re-read.** Testing beats restudy by 2 days out (Roediger & Karpicke 2006; ~80 % vs ~33 % recall at 1 week). Every AC'd problem enters a **cold re-solve ladder**: 1d → 3d → 7d → 14d → 30d → 90d. First review is *tomorrow*, never same-day (sleep consolidates — Rasch & Born 2013).
5. **Derive, don't memorize — and link everything backward.** Knowledge that keeps being *used inside later material* becomes permanent (Bahrick & Hall 1991: algebra used in calculus showed no loss 50 years later). So every topic opens as *"the bottleneck of the previous tool ⇒ the new tool"*, and every journal cue ends with **"reduces to ___"**. This is your math instinct, validated.
6. **Fade the scaffold.** Worked trace → completion holes → solo (Renkl & Atkinson 2004). Full worked examples *hurt* once you're competent (expertise reversal). LEARN files keep question-holes; REPS are bare.
7. **Self-explain to close.** Writing the cue in your own words is your confirmed "really gets it" signal (LEARNING_PROFILE) and the best-supported study technique after testing + spacing (Bisra 2018; Dunlosky 2013).
8. **Range goals with slack.** "5 of 7 days" counts as a kept week; **1 streak-repair token per week** (Sharif & Shu 2017; Silverman & Barasch 2023: broken streaks demotivate *unless repairable*). Never miss twice.
9. **If-then plans, written down** (Gollwitzer & Sheeran 2006, d = 0.65, >8 000 people). See §4.4.
10. **Judge the habit at day 60, judge mastery by delayed cold solves — never by how fluent a session felt** (Lally 2010: automaticity ≈ 66 days; Soderstrom & Bjork 2015: performance during practice is a bad gauge of learning). The calendar re-derives from velocity every month; the **gates never move**.

**Contests are the "use," not the training** (Um_nik: archives teach *solving*, contests teach *fast*). They start week 1 as measurement + fun + the weekly interleaving; the daily dose is where mastery is built.

---

## 3. THE SYLLABUS — 33 topics · 5 tiers · derivation-ordered

### 3.1 The derivation chain (read this like a proof)

```
00 complexity ── "how much work can I afford?"  (every arrow below is a bottleneck being killed)
 │
 ├─► 01 hashing ────── the O(n) inner scan "have I seen X?" → O(1) memory
 │     ├─► 02 two pointers ─── hashing can't do NEAREST/ORDER; SORTED data lets you steer
 │     │     ├─► 03 sliding window ── both pointers move right + a MONOTONE window predicate
 │     │     └─► 12 linked lists ──── fast/slow = two pointers on a chain (Floyd)
 │     ├─► 04 prefix sums ──── window fails on negatives / exact counts → precompute + remember (hash of prefix)
 │     │     ├─► difference arrays (range update) ──► 26 intervals (sweep)  ──► 28 Fenwick/segment tree (prefix sums that UPDATE)
 │     └─► 16 tries ───────── hashing by PREFIX = a tree of characters      ──► 29 string hashing / KMP
 │
 ├─► 05 binary search ── a yes/no predicate that's MONOTONE lets you discard half (n=1e9 ⇒ log)
 │     ├─► 14 BST ──────── binary search built into a structure
 │     └─► search-on-answer ──► 32 ternary/unimodal
 │
 ├─► 06 sorting ──────── merge sort = the first recursion; the preprocessing that unlocks 02 / 05 / 25
 │
 ├─► 07 stacks + monotonic ── "next greater" brute O(n²); smaller-than-newcomer can never win → discard = stack, amortized O(n)
 │     └─► 08 deque ─────── 03 window + 07 monotonic = window max/min  ──► 31 deque DP optimization
 │
 ├─► 09 recursion / D&C ── self-similar problem + leap of faith; the recursion TREE is the cost
 │     ├─► 10 backtracking ── recursion over CHOICES + state restore (n ≤ 20 ⇒ enumerate)
 │     │     └─► 11 bits ───── a mask IS a subset: the other way to enumerate ──► 31 bitmask DP
 │     ├─► 13 trees ──────── recursion on a branching structure; "return info up" = tree DP-lite
 │     │     ├─► 15 heaps ──── "repeatedly take the extreme" — sorting is overkill → complete tree in an array
 │     │     └─► 17 graphs ─── a tree without "one parent" ⇒ need a VISITED set (01 again)
 │     │           ├─► 18 topo sort (DFS finish order / in-degree queue) ── 19 union-find (components that ARRIVE over time)
 │     │           ├─► 20 shortest paths: BFS → Dijkstra (= BFS + heap 15) → Bellman-Ford → Floyd (= DP)
 │     │           ├─► 21 MST (sort 06 + DSU 19 · or heap 15)  ──► 30 bridges / SCC / LCA (= fast power on trees)
 │     └─► 22 DP-1D ──────── backtracking that TLEs + OVERLAPPING subproblems ⇒ memo ⇒ table ⇒ rolling array
 │           ├─► 23 DP-2D (grids · two sequences · knapsack)  ──► 24 DP-3 (strings · intervals · trees)  ──► 31 advanced DP
 │           └─► 25 greedy ── DP whose optimal choice is provably monotone (exchange argument) ──► 26 intervals
 │
 └─► 27 math ─────────── gcd = recursion 09 · sieve · mod arithmetic · nCr · cross product — the CP engine room
```

### 3.2 Coverage audit (the "revalidate end to end" you asked for)

| Source (2026) | Its structure | v2 coverage |
|---|---|---|
| **NeetCode 150 / 250** — 16 categories | Arrays&Hashing → 2P → SW → Stack → BS → LL → Trees → Tries → Heap → Backtracking → Graphs → Adv. Graphs → 1-D DP → 2-D DP → Greedy → Intervals → Math&Geo → Bits | **16/16** (topics 01–27) |
| **Striver A2Z** — 18 steps, 474 problems | Basics · Sorting · Arrays · BS · Strings · LL · Recursion · Bits · Stack/Queue · SW/2P · Heaps · Greedy · Trees · BST · Graphs · DP · Tries · Adv. Strings | **18/18** |
| **USACO Guide** Bronze → Silver → Gold | complete search, sorting/comparators, sets/maps, greedy, prefix sums, 2P, BS-on-answer, PQ, flood fill, tree algos, bits, divisibility/mod/combinatorics, DP family, shortest paths, DSU, topo, MST, BIT/segtree, tree DP, Euler tour/LCA, hashing, meet-in-the-middle, unimodal | **all of Bronze–Gold** (Platinum = beyond this plan) |
| **CSES** — 18 sections, 400 problems | Intro · Sorting&Searching · DP · Graphs · Range Queries · Trees · Math · Strings · Geometry · Advanced · SW · Bitwise · Construction · Adv. Graph · Counting · Interactive | **13 full + 5 partial** (geometry basics only; flows/Platinum-level out of scope) |

**Diff vs v1 (24 modules):** ADDED **06 sorting** (was never a topic; it's the first recursion and the tool that unlocks 2P/BS/greedy), **difference arrays** (04), **21 MST**, **24 DP-3** (strings/intervals/trees), **27 math & number theory**, and the whole **Tier 5**. PROMOTED **11 bits** from last to Tier 0 (a mask is a subset — it's the brute oracle for backtracking and the seed of bitmask DP). KEPT the v1 order for everything you already learned (nothing you did is wasted). MERGED "phases" into one numbered sequence.

### 3.3 The topics (per topic: what it kills · canonical problems · where it runs · checkpoint)

Ladders are **intentionally short** (LEARN 1–2 · REPS 4–6 · HARD 1). Kira scaffolds **one problem at a time, just-in-time** — never a whole ladder ahead. Problems you've already AC'd are marked ✓ (re-entry = cold checkpoint, not re-solve).

**TIER 0 — RE-ENTRY (weeks 1–5). Test → repair → move. Two small NEW topics (06, 11).**

| # | Topic | Kills this bottleneck | Canonical problems | Where it runs in the world |
|---|---|---|---|---|
| 00 | Complexity from constraints | "can I afford this?" — the 10⁸ rule; **count the work off your own code** (per-item cost × items); recurrence cost by tree size | **ACTIVE, week 1, 2 days (M#13: wrong on 6 of 9).** No LC problems: 6 short snippets/algorithms to bound by naming the line behind each factor. Checkpoint = 3 consecutive problems whose bound survives "which line?". M1's self-reported L3\* stays frozen until then. | every code review, ever |
| 01 | Hashing | O(n) inner "seen before?" scan | LC1✓ 217✓ 219✓ 242✓ 49✓ 128✓ 347✓ 36✓ · 706 design · H: 149✓ | DB indexes, caches, dedup |
| 02 | Two pointers | hashing can't do order/nearest; sorted ⇒ steer | LC125✓ 167✓ 15✓ 11✓ 283✓ · 75 Dutch-flag (redo) · H: 42 | merge step of merge sort, stream joins |
| 03 | Sliding window | re-scanning every subarray | LC209✓ 3✓ 424✓ 567✓ 1004✓ 904✓ · H: 76, 992 | rate limiters, network congestion windows |
| 04 | Prefix sums + difference arrays | many range sums / counts | LC303✓ 724✓ 560✓ 974✓ 525✓ 238✓ 523✓ 1590✓ · **NEW:** 1109 (difference array), 304 (2-D prefix) | analytics dashboards, image integral tables |
| 05 | Binary search (+ on answer) | n = 1e9 ⇒ must discard halves | LC704✓ 35✓ 34✓ 875✓ 33✓ 153✓ 162✓ 1011✓ · 74, 540 · H: 410, 4, 719 | any "smallest X that works" (capacity planning) |
| 06 | **Sorting** *(new)* | order as a preprocessing tool; the first D&C recursion | 912 (merge sort by hand) · 493 reverse pairs (inversions) · 215 quickselect · 179 comparator · 41 cyclic sort · 347✓ bucket | everything; `sort()` + comparator fluency is a CP primitive |
| 07 | Stacks + monotonic stack | next-greater brute O(n²) → amortized O(n) | LC20✓ 155✓ 739✓ 503✓ 456✓ 402✓ 735✓ · 150, 901, 853 · H: 84 | parsers, undo stacks, stock spans |
| 08 | Queues + monotonic deque | window max needs 03 + 07 together | LC232✓ 933✓ 239✓ · 622, 1438, 1696 · H: 862 (parked hard) | schedulers, streaming max/min |
| 09 | Recursion + D&C + fast power | self-similar problems; leap of faith | LC50✓ 231✓ 1137✓ 746✓ 198✓ 70✓ · gcd (Euclid) · 779 | file systems, compilers, `pow(x, 1e18) mod p` |
| 10 | Backtracking | "all subsets/perms/placements" with pruning | LC78✓ 46✓ 39✓ 90✓ · 40, 131, 79, 17, 22 · H: 51, 37 | constraint solvers, puzzle engines |
| 11 | **Bit manipulation** *(promoted)* | a mask is a subset; XOR cancels pairs | 136, 191, 338, 268, 190, 371, 260 · submask enumeration primitive | permissions flags, compression, DP over subsets |

**TIER 1 — STRUCTURES (weeks 6–13).**

| # | Topic | Kills | Canonical problems | Where it runs |
|---|---|---|---|---|
| 12 | Linked lists | pointer surgery; fast/slow = 2P on a chain | 206, 21, 141, 142, 19, 143, 138, 2, 287 (Floyd) · 146 LRU (hash + list) · H: 25, 23 (after 15) | memory allocators, LRU caches |
| 13 | Trees (traversals, recursion on trees) | recursion on branching structure; "return info up" | 226, 104, 100, 543, 110, 572, 102, 199, 1448, 105, 236 · H: 124, 297 | DOM, file trees, expression trees |
| 14 | BST | binary search as a structure; in-order = sorted | 700, 701, 450, 98, 230, 235, 108, 1008, 173 | ordered maps (`std::map`), DB B-trees |
| 15 | Heaps / priority queue | "take the extreme repeatedly" without sorting | 703, 1046, 973, 215, 621, 355 · H: 295, 23 | OS schedulers, Dijkstra, event simulation |
| 16 | Tries | prefix queries; hashing by prefix | 208, 211, 1268 · 421 (bit-trie ← 11) · H: 212 | autocomplete, IP routing, spell-check |

**TIER 2 — GRAPHS (weeks 14–20).**

| # | Topic | Kills | Canonical problems | Where it runs |
|---|---|---|---|---|
| 17 | Graph modeling + BFS/DFS | trees without "one parent" ⇒ visited set; grids as graphs; multi-source | 200, 133, 695, 994, 417, 130, 547, 1091, 785, 841 | social graphs, maps, dependency scanners |
| 18 | Topological sort + cycles | ordering with prerequisites | 207, 210, 802 · 269 (alien dictionary, premium/GFG) · H: 1857 | build systems, package managers, schedulers |
| 19 | Union-find (DSU) | components that arrive over time | 547, 684, 721, 1319, 990, 2316 | network connectivity, Kruskal, image segmentation |
| 20 | Shortest paths | BFS → Dijkstra (heap) → Bellman-Ford → Floyd; 0-1 BFS | 743, 1631, 1514, 787, 1334, 2290 · H: 778, 1368 | GPS routing, network routing (OSPF) |
| 21 | MST | connect everything, minimum cost | 1584 (Prim + Kruskal both) · H: 1489 | network design, clustering |

**TIER 3 — DP · GREEDY · MATH (weeks 21–30).**

| # | Topic | Kills | Canonical problems | Where it runs |
|---|---|---|---|---|
| 22 | DP-1D (memo → table → rolling) | backtracking that TLEs + overlap | 70✓ 746✓ 198✓ · 213, 322, 300, 139, 152, 91, 983, 55, 45 | resource allocation, text justification |
| 23 | DP-2D (grid · two sequences · knapsack · stocks) | two-index state | 62, 63, 1143, 72, 518, 494, 416, 474, 1049 · stock family 121/122/309/714/123/188 · H: 97, 329, 115, 10 | diff tools (edit distance), bioinformatics, budgeting |
| 24 | DP-3 (strings · intervals/partition · trees · LIS variants) | states over substrings/subtrees | 5, 647, 516, 1312, 337, 968, 673, 1048 · H: 132, 312, 1547, 354 | compilers (parsing), phylogenetics |
| 25 | Greedy + exchange argument | DP whose choice is provably safe | 53, 55, 45, 134, 846, 763, 678, 1029, 455, 621 · H: 135 | scheduling, Huffman coding, caching policies |
| 26 | Intervals + sweep line | overlap logic; difference array (04) returns | 57, 56, 435, 452, 1288, 986, 1094 · H: 1851 | calendars, meeting rooms, genome ranges |
| 27 | Math & number theory (+ geometry basics) | the CP engine room; your favourite | gcd/lcm (Euclid), 204 sieve, mod pow / mod inverse (Fermat), nCr mod p (118/119 Pascal, 62 as C(m+n−2, m−1)), 172, 1071, 48, 54, 73, 202, 66, 2013 · cross product 149✓, 1232 | cryptography, hashing, graphics |

**TIER 4 — CONSOLIDATION = MONTH 7 (weeks 31–34).** NeetCode-150 **cold sweep** (only what's unsolved or decayed), 3 timed mock interviews, contest review. This is the **"strength & confidence" checkpoint** (§7).

**TIER 5 — CP DEPTH (weeks 35–47).** Practice archive = **CSES** (no editorials — Um_nik-style) + CF problems by rating band (CP-31 sheet 800 → 1400). Contests = measurement.

| # | Topic | Kills | Canonical problems | Where it runs |
|---|---|---|---|---|
| 28 | Range queries: sparse table → Fenwick → segment tree → lazy | prefix sums that must UPDATE | 307, 315, 493 (Fenwick) · CSES Static Range Min, Dynamic Range Sum/Min, Range Update Queries · 2407 · coordinate compression | time-series stores, OLAP, game leaderboards |
| 29 | Strings: KMP/prefix-function, Z, rolling hash, suffix array intro | substring search in O(n + m) | 28, 1392, 187, 214, 1044 · CSES Finding Periods, String Matching | grep, plagiarism detection, DNA search |
| 30 | Advanced graphs: bridges/articulation, SCC, LCA (binary lifting), Euler tour, functional graphs, negative cycles | structure inside graphs | 1192, 1483, 2360 · CSES Planets & Kingdoms, Company Queries I/II, Subtree Queries, Cycle Finding, Planets Cycles | network resilience, dependency analysis |
| 31 | Advanced DP: bitmask, digit, tree rerooting, deque optimization, bitset knapsack, LIS n log n, SOS intro | exponential states made small | 1986, 847, 1349, 902, 834, 1696 (revisit), 300 (n log n) · CSES Hamiltonian Flights, Elevator Rides, Counting Numbers, Tree Distances I/II, Money Sums | scheduling, VLSI, counting problems |
| 32 | Contest craft: constructive/ad-hoc, invariants & parity, meet-in-the-middle, offline queries, ternary search, interactive, fast I/O, CF-style stress testing | speed on unseen shapes | CF Div2 A/B ladder · CSES Construction, Meet in the Middle, Interactive · 1755, 1515 | this IS the contest muscle |

> **Out of scope (deliberately):** flows/matching, suffix automaton, HLD/centroid, FFT, DP optimizations (CHT/D&C). That's Platinum/red-coder territory — a Phase after month 11, if wanted.

---

## 4. THE DAILY HABIT — the shape of a day

### 4.1 The 3-slot day (month 1: standard 45 min, cap 60 · from day 30: 60–90 min, cap 90)

| Slot | Time | What | Rule |
|---|---|---|---|
| **1 · RECALL** | 10 min | 1–2 due items from `REVISION_QUEUE.md`: a *card* (disguised statement → name the pattern + trigger + core idea, 3 min) or a *cold re-solve* (write the core loop from memory, 10 min). **Always a different topic than today's.** | This is the ONLY cross-topic work of the day. Queue overflow (> 3 due) ⇒ Kira prunes to the oldest one per topic. |
| **2 · BUILD** | 30 min (month 1) · 45–60 after | The current topic. **ONE problem, fully** — LEARN (derive: brute → bridge → optimal) or REP (solve → LC submit → look back). A second problem only if the first was quick. **Gate A first, always:** restate in one sentence + 3-element dry run + the **4 disqualifier questions** — *contiguous or not? · sorted, or may I sort? · order or membership? · count, best, or list-all?* — **before any tool is named** (M#12). | One 25–50-min block per problem. **Stop at the cap even mid-problem** — write the resume line, that's tomorrow's warm-up. |
| **3 · LOOK BACK** | 5 min | The **complexity as a sentence with the work in it** ("for each of n days I walk back up to n ⇒ n²" — which line produces each factor, M#13) → the cue in your words into `PATTERN_JOURNAL.md` (**must end with "reduces to ___"**) → queue the re-solve dates → `/endsession` (add + commit + push). | Polya's "look back" — the step everyone skips and the one that makes it stick. |

**Floor (bad day):** slot 1 only, one card, ≤10 min. **It counts as a kept day.** Zero is the only failure.
**Ceiling:** 60 min weekdays in month 1 (boss's call, D1), 90 min after day 30 if ≥ 20 of 30 days are kept. "5 problems a day" happens on contest days and as recall cards, never as 5 new mediums.

### 4.2 The week

| Day | Dose |
|---|---|
| Mon–Thu | 3-slot day (RECALL · BUILD · LOOK BACK) |
| **Fri** | **CHECKPOINT** (`tests/checkpoints/`): 3 cold questions on the current topic — (1) disguised statement → pattern + trigger + complexity, (2) template/core loop from memory, (3) one unseen medium coded cold → LC. Plus 2 cards from older topics. ~30–40 min. Pass = the topic's L4 evidence. |
| **Sat** | **Morning block (2 h): the HARD + a timed variant.** **Evening block (2 h): the REVISION ENGINE** — cold re-solves of the week, 5 mixed cards, teach-back — *or* the **Biweekly** (alt Saturdays 20:00 IST). Details §4.2b. |
| **Sun** | **Morning block (2 h): LeetCode Weekly 08:00 IST** (90 min, all 4 attempted, no help) + 30-min debrief (log, one card per unsolved, receipts). **Evening block (2 h): the one upsolve** (≤1 hint) + 2 ladder re-solves + the week review / next week's line. Details §4.2b. |

Weekly throughput: weekdays 1 h × 5 (≈ 5 build problems + 8 cards) + the two weekend days below (≈ 1 hard + 1 timed medium + 5 cold re-solves + 5–10 cards + 4 contest problems + 1 upsolve + 1 teach-back) ≈ **30 problem-touches at ~13 h/week**. Your "5 a day" in throughput, with no single block longer than 2 hours.

### 4.2b The weekend blocks (boss's offer, 2026-09-07: 2 h morning + 2 h evening, both days)

Each block = at most **two deep problems + retrieval**, a 5-minute break every 50 minutes, and a hard stop at 2 h. Mornings get the high-energy work (the hard, the contest); evenings get retrieval (spaced from the morning — that's the "split sessions ≈ 2× retention" win, §2 rule 2). **Fixed blocks:** Sat morning + Sun morning. **Flexible blocks:** the two evenings — skipping one does not break the week.

| Block | Minutes | What | Why it makes you stronger |
|---|---|---|---|
| **Sat AM — THE HARD** | 10 | 2 RECALL cards (old topics) | warm retrieval, catches carryover |
| | 60–75 | **ONE hard** from the current/previous topic, ≤ 1 hint; you build the hostile input; predict pass/fail before submit | combined-tool variants = the "3 variants" rule (SYSTEM §3.2) |
| | 30 | **ONE timed medium**, a variant you haven't seen, solo, 30-min clock, LC | speed + first-submit-clean under a clock |
| | 5 | look back: cue + "reduces to" + the complexity sentence | Polya's step 4 |
| **Sat PM — REVISION ENGINE** *(alt Saturdays: the Biweekly 20:00–21:30 replaces it; then only the 20-min teach-back happens, after the contest)* | 45 | **cold re-solves** of the week's ladder items (2–3 of Mon–Fri's problems, no notes open) | the +3d / +7d rung — retrieval, not re-reading |
| | 30 | **`/drill`** — 5 mixed cards with adjacent-family traps, marks only, reveal after | recognition; the M#12 tool-carryover killer |
| | 20 | **teach-back** — write one topic's derivation + cue in the journal as if teaching a beginner | the L6 rep; self-explanation is your confirmed "gets it" signal |
| | 15 | **watchlist self-test** — for each live leak in `MISTAKES.md`, state the catch from memory; 3 `CPP_GAPS.md` idioms typed cold | kryptonite pre-load, no re-reading |
| **Sun AM — CONTEST** | 90 | **LC Weekly 08:00 IST**, all 4 attempted, disqualifier gate before each, no help | speed on unseen shapes; the weekly interleaving |
| | 30 | **debrief** — `/contest`: log solved/4 + time per Q, one card per unsolved (*why I missed: reading / routing / machinery / execution / speed*), one same-day receipt before any verdict | turns the contest into test material; pre-empts the calibration leak |
| **Sun PM — UPSOLVE + REVIEW** | 60 | **the one upsolve** (easiest unsolved, ≤ 1 hint) → LC AC | the highest-value unseen problem of the week |
| | 30 | 2 ladder re-solves due (cold) *or*, on the last Sunday of the month, the **10-Q mixed recognition test** (`tests/mixed/`) | +7d / +30d rungs; monthly tier-wide read |
| | 20 | **week review** — Kira prints days kept, checkpoint result, leak board deltas, next week's "why it matters" line; you answer the 5-question self-report if Friday missed it | calibration with receipts; the experiment review (SYSTEM §7) |
| | 10 | stop early. Rest is part of the dose. | consolidation happens asleep |

From month 3, one Saturday morning per month is a **timed 4-problem contest simulation** instead of the hard. During **Tier 0 (weeks 1–5)** the Saturday-morning hard is replaced by the **next old topic's cold checkpoint + its repair**, so re-entry moves at ~2 topics per week and the weekend never opens a new topic.

### 4.3 Slack, streaks, lapses

- **A kept week = 5 of 7 days.** One **repair token** per week: a missed day is repaired by doing the floor the next day. Never miss twice.
- **Automaticity ≈ 66 days** (Lally 2010) ⇒ the habit is judged on **2026-11-12**, not next week. Until then the only metric on the dashboard that matters is *days kept*.
- **Lapse ≠ relapse.** One missed day is noise (Lally: negligible effect). Two missed days ⇒ Kira's first message next session is **one 5-min card, no catch-up, no backlog** (queue auto-prunes). A missed week ⇒ a 30-min cold checkpoint on the current topic, then continue. **No guilt talk** (Adams & Leary 2007: self-compassion, not self-criticism, is what restarts a habit).

### 4.4 If-then plans (boss fills the blanks once; Kira enforces)

- If it's my anchor time → I open the repo and type `/today`.
- If I'm exhausted → slot 1 only (one card), then `/endsession`. Counts.
- If I'm travelling → recall on the phone (read the card, say the answer aloud), log it next session.
- If I miss a contest → virtual/upsolve 2 problems within 48 h.
- If a problem is at 50 min and I'm not done → write the resume line, stop. Tomorrow's warm-up.
- If I feel "I forgot everything" → that's the calibration leak; run one card and read the receipt Kira shows.

### 4.5 The topic protocol (each new topic = 5–8 days)

| Day | Step | Detail |
|---|---|---|
| 1 | **DERIVE** | Striver video(s) for the topic *before* the session (your standing workflow, unopened topics only). In session: closed-book probe (what do you already half-know? dormant knowledge is real) → Kira asks the bottleneck question on a 5-element example → **you derive the tool** (atomic Q&A, never a lecture) → template from memory → first LEARN problem. Kira writes `notes.md` afterwards from *your* derivation (teaching-BITS format). |
| 2–4 | **REPS** | 1–2/day, easy → medium → medium. Plain solves, LC AC, look-back cue each. Blocked (this topic only). |
| 5 | **CHECKPOINT** | Friday test (§4.2). Pass ⇒ L4 evidence + the topic enters the ladder. Fail ⇒ 2 more reps, re-test next Friday. |
| weekend | **HARD** | One hard from this topic (Saturday). |
| later | **LADDER** | One problem from the topic re-solved cold at +7d, +30d, +90d; its checkpoint questions reappear in later Friday tests (L5 = named cold ≥14 days later, or used in a contest). |

**L3 → next topic** (your cadence rule keeps): advance at L3, backfill L4 via the Friday checkpoint and the ladder. **Tier gate:** every topic in the tier at L4 before the next tier opens.

---

## 5. RETENTION — the ladder, concretely

- **Per problem:** AC → **+1d card** (name pattern + idea, 3 min) → **+3d** card → **+7d cold re-solve** (felt easy ⇒ +30d; felt hard ⇒ +7d again) → **+30d** → **+90d**. Fail anywhere ⇒ back to +1d. First review never same-day.
- **Per topic:** Friday checkpoint → mixed into Friday tests at **+14d, +45d, +90d** (2 cards each time).
- **Cards live in `PATTERN_JOURNAL.md`:** front = a disguised statement; back = trigger + core idea + *why* + "reduces to ___" — in your words, no code (Wozniak's minimum-information principle).
- **Dose cap:** slot 1 ≤ 15 min/day. If the queue can't fit, it gets pruned, not you.
- **Contests are the natural interleaving** — every Sunday, four unseen shapes.

---

## 6. CONTESTS + PROFILE (the "use")

**Calendar (IST, verified 2026-09-07):**

| Contest | When | Notes |
|---|---|---|
| **LeetCode Weekly** | every **Sunday 08:00**, 90 min, 4 problems | core — from **2026-09-13** |
| **LeetCode Biweekly** | alternate **Saturdays 20:00**, 90 min, 4 problems | core — check leetcode.com/contest for the next one (Sep 12 or Sep 19) |
| **GFG Weekly Coding Contest** | was Sunday 19:00 | **PAUSED since ~June 2025** ("temporarily paused"; last = #208, 2025-05-25). Kira re-checks monthly; if it returns, it slots into Sunday evening. Keep a GFG account for the POTD streak if you like visible streaks. |
| **CodeChef Starters** | every **Wednesday 20:00**, 2 h | the beginner-friendly rated weekly — **from month 2** as the GFG substitute |
| **Codeforces** Div 3 / Div 4 / Educational | 2–3 rounds/week, usually **20:05 IST** | **from month 3** (Dec) — the real CP ladder |
| AtCoder ABC | Saturday 17:30 IST, 100 min | optional, excellent editorials |

**LeetCode rating (new rule since 2026-04-27):** you start at 1500; your **first 5 contests are "Phase 1"** — rated by percentile only, not globally ranked, no pressure. Elo from the 6th contest. Badges: **Knight = top 25 %** of ≥1600 users (≈ 1850), **Guardian = top 5 %** (≈ 2120).
**Codeforces titles:** Newbie < 1200 · Pupil 1200 · Specialist 1400 · Expert 1600 · CM 1900.

**Rules:** full 90 min, all 4 attempted, no external help. After every contest: **exactly one upsolve** (the easiest unsolved), within 48 h, in `tests/contests/<date>-<contest>/`, and the recognition miss becomes a card. Log every contest in `dashboard/CONTESTS.md` (date · solved/4 · time per problem · rating · upsolved?).

**Profile:** LC username (D3) · Codeforces handle created now, first rated round in Dec · CodeChef handle month 2 · GFG account optional · this repo = the public portfolio (commit history is the proof of work).

**Expectation ladder (estimates, NOT gates — the gates are skills):**

| When | Contest reality | Rating (LC, estimate) |
|---|---|---|
| Month 0–1 | Q1 solved; Q2 attempted | Phase 1 (unranked) → ~1500 |
| Month 3 | Q1 + Q2 reliably | 1500–1600 |
| Month 5 | Q3 sometimes | 1600–1700 |
| **Month 7** | **Q3 regularly, Q4 attempted** | **1650–1800** · CF Pupil |
| Month 11 | Q4 sometimes | Knight attempt (~1850) · CF Specialist (1400+) |

---

## 7. THE CALENDAR (re-derived monthly from velocity; the gates never move)

| Weeks | Dates | Tier | Milestone (measurable) |
|---|---|---|---|
| 1–5 | 2026-09-07 → 10-11 | **0 · Re-entry** (00–11) | days 1–2: gauntlet Q10–Q20 finished = full baseline (D8); 00 complexity cleared (M#13); all 10 old topics re-validated by cold checkpoint (test → repair → move); 06 + 11 at L3; 5 LC contests attended; ≥ 25 of 35 days kept |
| 6–13 | 10-12 → 12-06 | **1 · Structures** (12–16) | habit automatic (~11-12); Q1 reliably; Q2 ≥ half the time; CodeChef started |
| 14–20 | 12-07 → 2027-01-24 | **2 · Graphs** (17–21) | CF handle with ≥ 4 rated rounds; Q2 reliably |
| 21–30 | 01-25 → 04-04 | **3 · DP · Greedy · Math** (22–27) | Q3 sometimes; every Tier ≤ 3 topic at L4+ |
| 31–34 | 04-05 → 05-02 | **4 · Consolidation** | ⭐ **MONTH-7 CHECKPOINT (2027-04-07):** ≥ 80 % of NeetCode-150 mediums solved cold · 3 mocks at lean-hire or better · Q3 in ≥ 1 of the last 4 contests · "I can walk into an interview" |
| 35–47 | 05-03 → 08-01 | **5 · CP depth** (28–32) | ≥ 150 CSES solved · CF Specialist or trending · LC Knight attempt · **MONTH-11 (2027-08-07): expert bar** = the whole map at L4+, top patterns at L5/L6 |

Two weeks of slack are built in (47 weeks of work in a 48-week window). If velocity says "behind," the calendar stretches — the dose and the gates do not.

**Hours model (for the monthly recalibration):** ≈ 350 focused hours to the month-7 bar, ≈ 500 to the expert bar. At ~8 h/week (1 h/day + the Sunday contest) that is ≈ 10 and ≈ 14–15 months; at the designed ~11 h/week it is 7 and 11; at boss's offered ~13 h/week (1 h weekdays + 2+2 h both weekend days) it is ≈ 6 and ≈ 9–10 **on paper** — the calendar above stays until real velocity confirms it.

---

## 8. LEVELS — evidence only, simplified

| Level | Evidence (witnessed, logged in `PROGRESS.md`) |
|---|---|
| L1 introduced | derivation done in session |
| L2 understands | explained back + traced a 5-element run |
| L3 implements | template from memory + 1 LEARN problem AC |
| L4 applies | Friday checkpoint passed + ≥ 2 mediums AC solo |
| L5 recognizes | named cold in a mixed test ≥ 14 days later, **or** used correctly in a contest |
| L6 teaches | cue + "reduces to" written in own words and explained to Kira |

Dashboard % map unchanged (L0=0 L1=15 L2=35 L3=55 L4=75 L5=90 L6=100). **Re-entry rule:** an old topic's level is *provisional* (marked `*`) until its Tier-0 checkpoint confirms or lowers it. No inflation.

**Dashboard adds three habit numbers:** days kept this week (x/7), days kept total (n/66), contests attended + last rating.

---

## 9. THE REPO — 3 folders, nothing at root but `.claude/`

```
LEARN_DSA/
├── .claude/                     Kira: CLAUDE.md (lean rules, auto-loaded) · commands/ · run.sh
├── .gitignore  .mcp.json  .vscode/          config only (dotfiles)
│
├── dashboard/                   MEMORY + FRONT DOOR (Kira writes, you glance)
│   ├── README.md                TODAY — resume line · this week · days kept · leak board   (was COMMAND_CENTER)
│   ├── PLAN.md                  this file
│   ├── PROGRESS.md              levels table + session log
│   ├── REVISION_QUEUE.md        the retrieval ladder (dates)
│   ├── PATTERN_JOURNAL.md       cues / cards, your words, "reduces to ___"
│   ├── MISTAKES.md              root causes + re-tests (phase-1 + phase-2 merged)
│   ├── LEARNING_PROFILE.md      how you learn
│   ├── CHECKLIST.md             gates A / B / C
│   ├── CONTESTS.md              contest log + ratings
│   ├── CPP_GAPS.md              C++ fluency log
│   ├── dsa-map.html             visual map (regenerated for the 33 topics)
│   └── resources/               striver-videos.md · references.md (book map) · PDFs (gitignored)
│
├── practice/                    ONE topic = ONE folder, one numbered sequence, no phases
│   ├── 00-complexity/
│   ├── 01-hashing/
│   │   ├── notes.md             derivation-first notes (teaching-BITS)
│   │   ├── learn/               first-time guided solves (brute → bridge → optimal, question-holes)
│   │   ├── reps/                practice solves (bare solution.cpp)
│   │   └── hard/                weekend hards
│   ├── 02-two-pointers/  …  32-contest-craft/
│
└── tests/                       COLD, closed-book — the only promotion path
    ├── checkpoints/             <NN-topic>-<date>/   Friday topic checkpoints
    ├── mixed/                   weekly mixed cards + the 2026-06 / 2026-08 gauntlets (history)
    ├── contests/                <date>-<contest>/    upsolves + notes
    └── interviews/              mock interviews
```

**Migration map (git mv, history preserved):**

| From | To |
|---|---|
| `CLAUDE.md` | `.claude/CLAUDE.md` — rewritten lean (~8 KB), same persona + gates, new daily-dose + contest + habit protocol |
| `COMMAND_CENTER.md` | `dashboard/README.md` — the 170-line history block moves to `PROGRESS.md` session log |
| `PROGRESS.md`, `REVISION_QUEUE.md`, `PATTERN_JOURNAL.md`, `LEARNING_PROFILE.md`, `CHECKLIST.md`, `CPP_GAPS.md` | `dashboard/` (same names) |
| `phase-1/mistakes.md` + `phase-2/mistakes.md` | `dashboard/MISTAKES.md` |
| `STRIVER_VIDEOS.md`, `references/README.md` | `dashboard/resources/` |
| `CURRICULUM.md`, `TRAINING_PLAN.md`, `SPRINT_PLAYBOOK.md`, `SPRINT_SCHEDULE.md`, `ROADMAP_PLAN.md`, `FORGE_LADDER.md`, `FILE_GUIDE.md`, `README.md` | **deleted** (superseded by this file; git history keeps them) — per D4 |
| `phase-N/notes/<NN>-x.md` | `practice/<NN>-x/notes.md` (renumbered to the 33-topic sequence) |
| `phase-N/learn/<NN>-Topic/*` | `practice/<NN>-x/learn/*` |
| `phase-N/practice/<NN>-Topic/*` | `practice/<NN>-x/reps/*` |
| `phase-1/drills/03-hard-gauntlet/*` | each hard → its topic's `hard/` |
| `phase-1/drills/02-monotonic-stack/*` | `practice/07-stacks/reps/` |
| `phase-1/drills/01-mixed-gauntlet/`, `phase-1/test/cold-recognition/`, `phase-2/test/revision-recognition-2026-08/` | `tests/mixed/<date>-…/` (kept as history + card source) |
| `run.sh` | `.claude/run.sh` (Kira's tool; you never run locally) |
| `.claude/commands/` | rewritten: `/today` (the 3-slot day) · `/learn` · `/checkpoint` · `/contest` · `/revise` · `/drill` (5 cards, name-only) · `/interview` · `/logmistake` · `/dashboard` · `/endsession`. Removed: `/forge`, `/start-practice`, `/recap-patterns`, `/map-pattern-optimisation-problems`. |

**What Kira changes about herself (goes into the new `.claude/CLAUDE.md`):**
1. Session = the 3-slot day. Kira opens with the resume line + due recall, not a dashboard wall.
2. **One topic.** Kira never opens a second topic in a session; the recall slot is the only cross-topic work.
3. **Dose cap is Kira's job too:** at the cap she stops, writes the resume line, ends the session.
4. **Scaffold one problem at a time, just-in-time.** No ladders built ahead. (46 unfinished files = the receipt.)
5. **Derivation-first openings** + "where it runs" line + every cue ends with "reduces to ___".
6. **Contest protocol** (§6) and the habit protocol (§4.3–4.4) are standing.
7. Everything already engraved stays: trace-first, atomic teaching, ≤1 hint, refuse-to-check, LC verdict = truth, teach-it-back, add+commit+push atomic.
8. **Every statement Kira hands you ships with 2–3 concrete input→output examples** (confirmed 5-for-5 on 8/10).
9. **The disqualifier gate is asked before any tool is named, and no bare complexity bound is ever accepted** — "which line produces that factor?" (M#12, M#13). Watch-tell: any answer opening with *"here also…"* / *"this is the same as…"* → stop, ask for the gate.

---

## 10. SOURCES (the ones the rules lean on)

Retention: Cepeda et al. 2008 (spacing gap ∝ retention interval) · Roediger & Karpicke 2006 / Karpicke & Roediger 2008 (testing effect) · Rohrer & Taylor 2006 (9 vs 3 problems; split sessions ≈ 2×) · Rohrer 2020 RCT (interleaving d = 0.83) · Brunmair & Richter 2019 meta · Hwang 2024 (blocked-then-interleaved for novices) · Bjork & Bjork (desirable difficulties) · Renkl & Atkinson 2004 (fading) · Bisra 2018 (self-explanation) · Dunlosky 2013 · Bahrick & Hall 1991 (used-later knowledge is permanent) · Murre & Dros 2015 (savings) · Rasch & Born 2013 (sleep) · Soderstrom & Bjork 2015 (performance ≠ learning).
Habit: Lally 2010 (66 days) · Gollwitzer & Sheeran 2006 (if-then, d = 0.65) · Dai, Milkman & Riis 2014 (fresh start) · Buehler 1994 (planning fallacy) · Sharif & Shu 2017 (slack) · Silverman & Barasch 2023 (repairable streaks) · Adams & Leary 2007 (self-compassion) · Beshears 2021 (flexible timing) · Ericsson 1993 (≈1 h/day effective).
CP practice: Um_nik "How to practice" (2021) · Errichto "How to practice?" wiki · galen_colin (logic before topics) · E869120 rating ladder · SuperJ6 (just-in-time topics, 30–40 % solve band) · USACO Guide · CSES · Striver A2Z · NeetCode 150/250 · TLE CP-31.
Contest facts: leetcode.com/contest (Sun 08:00 IST / alt Sat 20:00 IST; Phase-1 rule 2026-04-27) · geeksforgeeks.org/events (weekly contest paused) · codechef.com (Starters Wed 20:00 IST) · codeforces.com/contests · atcoder.jp.
