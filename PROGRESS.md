# PROGRESS.md — Live Tracker for Hema Vardhan

> The mentor reads this at session start and updates it at session end (via an
> UPDATE BLOCK you paste back, or directly if file-writing is wired up).
> **Every level must be backed by witnessed evidence (see `CLAUDE.md` §6).
> No level is raised without the proof logged in the session log.**

Level key: L0 not started · L1 introduced · L2 understands · L3 implements (from
memory) · L4 applies (≥2 easy + ≥2 medium solo) · L5 recognizes (named cold on
unseen) · L6 teaches. Dashboard %: L0=0, L1=15, L2=35, L3=55, L4=75, L5=90, L6=100.

---

## Learner setup
- Primary language: **C++** (using onlinegdb.com — macOS 26 beta toolchain bug locally; rebuilding fundamentals, self-rated ~4/10)
- Weekly hours available: **~25 hrs/week** (≈3h × weekdays + 5h × weekend days)
- Start date: **2026-06-04**
- Goal bar: majority of medium problems solved independently — **stretch goal: FAANG-level interviews in ~5 months** (FAANG bar leans into some hards + tight communication)
- Target horizon: ~5 months → projected ready ≈ **2026-11-04** (recompute after observing velocity)

## Snapshot
- Current phase: Foundations → Linear patterns. **M7 Stacks STARTED (theory, L2) — next session: templates + Valid Parentheses → Daily Temperatures to earn L3/L4.**
- Current module: **M5 Prefix Sum — DONE (L4)** (2026-06-05). M4 Sliding Window DONE (L4).
- Current topic: **M6 Binary Search — L4 EARNED (2026-06-10)** (LC34 + LC875 mediums AC; overflow primitive learned, MISTAKE #8). NEXT BS reps for L5 coverage: LC33 rotated + LC74 2D-matrix (banked, not yet scaffolded). **SW + Prefix → L5 RECOGNIZED today via 6/7 interleaved drill.** Mastered **L4: SW, Prefix, Hashing, Two Pointers** (2ptr GAPS: Dutch-flag re-code, boundary reflex, L5 pending). CADENCE (memory): weekday=L4 (easy+medium), HARDS=weekend, L5 deferred to spaced drills. WEEKEND: LC42 Trapping + LC410 Split Array. **#1 leak = boundary EXECUTION (reactive debug-by-failing-test)** — fix = trust clean template + reason 4 edges before submit (Notes/00 + 06). REVISIT: 2ptr Dutch-flag (LC75).
  Plan: reason through practice sets understanding WHY; last 1–2 of each with GOAL×KEY map CLOSED; then **L5 test**
  = `/drill` + 1–2 unseen cold solves. Earlier recall FAILED 6/6 (count↔longest, Two Sum→2ptr) — heavily reinforced
  this session via LC238/LC523; re-test recognition next via `/drill`.
- Overall mastery (started topics): **~74%** (mean of M1 L3*=55, M2 L4=75, M3 L4=75, M4 L5=90, M5 L4=75, M6 L4=75 → 445/6). M4 SW the only confirmed L5 (cold across 2 sessions). M5 Prefix pulled back to L4 (one clean call ≠ track record). |
- Observed velocity: ~Day 5–6 (2026-06-08/09) = M2 Hashing L4 (8 problems) + M3 Two Pointers L4 (theory→video→ladder→solo) + M6 Binary Search L3 (theory→video→2 easies) + full Notes/00-06 buildout. **32 problems AC total.** Pace on FOUNDATIONS is fast & quality-first; back-half (DP/Graphs/Trees) will be slower per-pattern. Day 2 = M5 prefix+hash L4 (LC560/724/974/525). Day 1 = M4 + 3 mediums.
- Projection: started 2026-06-04; **4.5 patterns at L4 in ~6 days** → ON TRACK for ~2026-11-06. Caveat (he derived this himself): % by pattern-count overstates progress — later topics are heavier; realistically ~12–15% of total *work* done. The reusable foundation (hashing/2ptr/prefix/window/BS + complexity instinct) carries into the hard topics.
- Workflow change (2026-06-05): **Striver A2Z videos first (see STRIVER_VIDEOS.md), then practice here.** From M6 onward, Striver-first.
- New infra built: `/start-practice` (daily cold interleaved set, practice/day-NN/), STRIVER_VIDEOS.md (315 vids mapped).
- **TARGET (decided 2026-06-06): interview-ready in ~5 months → ≈ 2026-11-06, at ~25h/wk.**
  Scope CUT to **NeetCode 150 high-frequency patterns** (NOT full A2Z). **Bar = L4 broadly, L5 on top ~8 patterns.**
  One topic at a time, L4-then-move (no over-polish), spaced revision + drills circle back. Deferred as optional:
  Tries, deep Bit-Manip, advanced graphs (SCC/bridges), exotic partition DP.
  Roadmap: M1 finish Phase1 (Hashing→Two Pointers→Binary Search→Stacks). M2 Queues→Recursion→Backtracking→LinkedLists.
  M3 Trees→BST→Heaps. M4 Graphs. M5 DP(1D→2D)→Greedy→Intervals + consolidation/mocks.
- **Teaching change:** give the FULL recognition map per pattern UP FRONT (all variants + cues), not one example.

> **Levels below are PROVISIONAL (self-reported on transfer 2026-06-04).** Marked `*`.
> They convert to earned levels only as I witness the evidence (§6). First verification: this session's revision.

---

## Topic levels
> One row per module from `CURRICULUM.md`. Update the level + the date + a one-line
> evidence note when it changes. Keep `solved` as `easy/medium` counts.

| ID | Module | Level | Last touched | Solved (E/M) | Evidence note |
|----|--------|-------|--------------|--------------|---------------|
| M1 | Complexity Analysis | L3* | 2026-06-04 | 0/0 | *Self-reported: O(1)→O(n²), log-rule (i*=k→log n), 4 rules, Ω/O/Θ. Verify recall. |
| M2 | Arrays & Hashing | **L4** | 2026-06-08 | 4/4 | **L4 EARNED 2026-06-08**: solo set all AC — LC217/219 (easy, clean solo), **LC347 Top-K (medium, recognized + built bucket-sort himself)**, **LC36 Valid Sudoku (medium, designed 3-sets-by-row/col/box himself)**. Recognition + approach INDEPENDENT (huge flip from drill 0/2); help was only on execution/boundary bugs, not the pattern. **L5 (cold unseen) pending re-drill.** |
| M3 | Two Pointers | **L4** | 2026-06-09 | 4/2 | **L4 EARNED (converging mechanic)**: solo set done — **LC167 Two Sum II CLEAN SOLO** (converging, sum-steered) + LC11 Container largely his (derived "move shorter wall"); ladder LC125/977/15. **Honest GAPS (his own read — accurate):** (1) LC75 Sort Colors solved SOLO via selection-sort, NOT Dutch-flag — but this was a **DELIBERATE constraint-based choice** (saw n≤300, chose O(n²); good 10⁸-rule instinct, NOT an inability). Dutch-flag *technique* still worth practicing for toolkit+interviews; (2) Move Zeroes/Palindrome II easies needed coaching (boundary leak + skip-derivation); (3) **boundaries still the #1 leak**. **L5/mastery NOT yet** (his instinct correct) → deferred drill. REVISIT: redo LC75 as Dutch-flag, boundary reflex. LC42 Trapping = weekend. |
| M4 | Sliding Window | **L5** | 2026-06-10 | 2/3 | **L5 RECOGNIZED 2026-06-10**: named cold across TWO interleaved drills with zero misses (6/08 3/3 true-SW + 6/10 Q3 shortest-subarray). Correctly REJECTS negatives/±1-transform (routes to prefix+hash), no over-fire. Earlier L4: 3 mediums AC LC209/LC3/LC1004. |
| M5 | Prefix Sum | **L4** | 2026-06-10 | 1/3 | **L4** — approaching L5 but NOT yet (honest pull-back 2026-06-10 after learner challenged it): drill Q4 (count subarrays=k w/ negatives) named cold + correct trigger ✅, BUT this is ONE clean call after a recent MISS (6/08 Q6 routed prefix→SW). L5 needs a clean track record, not one good call. Re-test 6/14. Mediums AC: LC560/LC974/LC525 + LC724. |
| M6 | Binary Search | **L4** | 2026-06-10 | 2/2 | **L4 EARNED 2026-06-10**: mediums **LC34 (first/last)** + **LC875 Koko (search-on-answer)** AC, on top of LC704/35 easies. Recognition independent on both; support on Koko was a PRIMITIVE (int-overflow magnitude, MISTAKE #8), not the pattern. No `if(s==e)` band-aids this time (template trusted). Drill Q5/Q6 (search-on-answer + rotated) named cold — **L5 HELD** (same-day as L4 = short-term recall, not transfer; cadence rule). Residual: overflow/edge reasoning up front; rotated(LC33)+2D(LC74) unsolved. |
| M7 | Stacks & Monotonic Stack | **L2** | 2026-06-10 | 0/0 | **L2 (understands)** — theory taught (LIFO, push/pop/top all O(1), the "most recent unmatched" model). Explained back: nailed LIFO pop order (D,C); parentheses needed sharpening (had a COUNTER model "cancel to 0" → corrected with `([)]` why a counter fails & a stack is needed). **Monotonic stack** taught: next-greater family, "elements waiting for their answer," amortized O(n) (each pushed once/popped once) via Daily Temperatures dry run. NEXT: templates + Valid Parentheses → Daily Temps (code from memory = L3). Striver [297]/[300]. |
| M8 | Queues & Deque | L0 | — | 0/0 | |
| M9 | Recursion | L0 | — | 0/0 | |
| M10 | Backtracking | L0 | — | 0/0 | |
| M11 | Linked Lists | L0 | — | 0/0 | |
| M12 | Trees | L0 | — | 0/0 | |
| M13 | Binary Search Trees | L0 | — | 0/0 | |
| M14 | Heaps / Priority Queue | L0 | — | 0/0 | |
| M15 | Tries | L0 | — | 0/0 | |
| M16 | Graphs + BFS/DFS | L0 | — | 0/0 | |
| M17 | Topological Sort | L0 | — | 0/0 | |
| M18 | Union-Find | L0 | — | 0/0 | |
| M19 | Shortest Paths (Dijkstra) | L0 | — | 0/0 | |
| M20 | 1-D DP | L0 | — | 0/0 | |
| M21 | 2-D / sequence DP | L0 | — | 0/0 | |
| M22 | Greedy | L0 | — | 0/0 | |
| M23 | Intervals | L0 | — | 0/0 | |
| M24 | Bit Manipulation | L0 | — | 0/0 | |

_Advanced-tier modules added here only if pursued._

---

## Weak / repaired topics
> Topics where a gate failed or a revision recall failed. Cleared when re-passed.
- ⚠️ **Boundary / sentinel / order values** (cross-cutting execution weakness) — STILL ACTIVE, recurred again Day 2.
  Day 2 occurrences: closed-book recall reached for `ans=0` on a min-tracker (the LC209 reflex);
  LC724 `prefix[-1]` & `prefix[n]` out-of-bounds; LC525 forgot `seen[0]=-1`. Pattern logic is fine;
  the *edge values* are the leak. Standing fix: the **pre-code boundary checklist**. Clears when 2
  consecutive mediums are solved with ZERO boundary bugs (not yet met).
- 🆕 **"k = length" overfit** — twice treated a target SUM `k` as a window length (`i+k-1`). Fixed-window
  pattern over-firing. Re-test: a future "subarray sum=k" solved without reaching for a length window.
- 🆕 **"count-all" vs "find-one-window"** — confused counting every matching subarray with a shortest/longest
  hunt (wanted to "pick the nearest"). Counting = tally all. Re-test: LC1248 / LC930.
- 🆕 **Prefix+Hash GOAL×KEY confusion** (closed-book 6/6 FAIL) — applies LONGEST machinery (first-index, max gap)
  to a COUNT problem (needs frequency, `count+=`). Fix = decide 2 axes separately: GOAL (count→freq,seen[0]=1 /
  longest→first-index,seen[0]=-1) × KEY (complement/remainder/equal). The practice/ Prefix-Sum set drills this.
- 🆕 **Recognition recall weak** — 2026-06-08 `/drill` = **4/7**. SW recognition now STRONG (3/3 true-SW). The leak
  narrowed to **HASHING recognition (0/2)**: unsorted Two Sum (Q3) + duplicate-within-k (Q7) both misfiled as
  "two pointers" (the same Two-Sum→2ptr miss, now 2×). Also SW over-fired onto a ±1-transform/prefix problem (Q6).
  Root = M2 Hashing never formally taught. Clears after hashing lesson + a fresh drill ≥6/7. See MISTAKE #6.

## Problem counters
- Easy solved: 9 (LC643, LC1343 self-reported · **LC724, LC1480, LC303 judge-verified** · **LC1 Two Sum, LC242 Valid Anagram** AC 6/8 · **LC217 Contains Duplicate, LC219 Contains Duplicate II** — SOLO AC 6/8) · Medium solved: 13 (LC209, LC3, LC1004, **LC560, LC974, LC525, LC238, LC523** — judge-verified · **LC567** AC self-reported 6/8 ⚠️ repo file broken, reconcile · **LC49, LC128** AC 6/8 · **LC347 Top-K, LC36 Valid Sudoku** — SOLO AC 6/8 · **LC125 Valid Palindrome, LC977 Squares** — 2ptr easy 6/9 · **LC283 Move Zeroes, LC680 Valid Palindrome II** — 2ptr solo easy 6/9 · **LC704 Binary Search, LC35 Search Insert** — BS easy 6/9) · Medium: **LC15 3Sum, LC11 Container** (coached) · **LC167 Two Sum II (clean solo), LC75 Sort Colors (solo)** — 2ptr 6/9 · **LC34 Find First/Last, LC875 Koko Eating Bananas** — BS mediums 6/10 (Koko AC after overflow fix) · Hard (stretch): 0 (LC862 PARKED; LC42 Trapping + LC410 Split Array = weekend) · Total: 34

## Interview readiness (estimate — label as such)
- Problem solving: 0/100
- Complexity analysis: 0/100
- Coding quality: 0/100
- Communication: 0/100
- **Overall: 0/100**

---

## Session log
> Append one block per session. This is the audit trail for every level change.

```
[Date] — Module(s): — | Did: — | Levels changed: — (evidence) | Problems: — | Next: —

2026-06-10 — Module(s): M6 Binary Search (mediums → L4) + interleaved recognition drill (M4/M5 → L5) | Did: **Debugged LC875 Koko overflow** (`signed integer overflow: 1610612736+805306368`) — taught the OVERFLOW primitive: `(s+e)` overflows int before /2 → `mid=lo+(hi-lo)/2`; and `int sum` of Σceil(pile/k) hits 1e13 at k=1 → `long long`. He'd reasoned index edges but not MAGNITUDE → MISTAKE #8 + new checklist line. Also cleaned a nested-function structure bug. **LC875 + LC34 AC → M6 L4.** Then ran **7-question interleaved `/drill`: scored 6/7** (up from 4/7 on 6/08). Clean: Q2 sorted-2ptr, Q3 SW-shortest, Q4 prefix+hash-w/-negatives (perfect "breaks in SW" reasoning), Q5 BS-on-answer, Q6 rotated-BS, Q7 dup-within-k = HASHING (the old 6/08 miss, now CORRECT). Miss: Q1 unsorted-pair — first instinct flickered to "sort+2ptr" before recovering to hash map (MISTAKE #9). | Levels changed: **M6 L3→L4** (LC34+LC875 AC, recognition independent), **M4 SW L4→L5** (cold across 2 drills, 0 misses), **M5 Prefix L4→L5** (Q4 named cold w/ trigger). Hashing & Two-Pointers HELD at L4 (both tangled in Q1 flicker — hashing under-fired, 2ptr over-fired; L5 = one clean unsorted-pair call away). BS L5 HELD (same-day-as-L4 cadence). | Problems AC: LC34, LC875 (BS mediums) → total 34. | KEY: hashing recognition hole (0/2 on 6/08) is essentially CLOSED — only the unsorted-pair FIRST instinct remains. Boundary leak evolved: band-aids gone, but magnitude/overflow is the new face of "edges not reasoned up front." | Next: **LC33 Rotated + LC74 2D-matrix** (BS L5 coverage) OR start **M7 Stacks/Monotonic Stack**; + a fresh drill ~6/14 to clear the unsorted-pair first-instinct (earns Hashing+2ptr L5).

2026-06-04 — Module(s): M4 Sliding Window (Variable) | Did: transfer/First-Run setup; closed-book revision (O(log n) reasoning ✓, prefix-sum formula ✗→repaired, window cue ✓); taught Variable Sliding Window (caterpillar); set up SPRINT_PLAYBOOK + readable solutions/ + Notes/ + run.sh (fixed macOS linker bug = Anaconda stale ld) + LeetCode MCP (live next restart). | Levels changed: M4 L3* → L3 EARNED (LC209 Medium coded from understanding, Accepted on judge). Variable window L2 (explained back) → L3 (implemented). | Problems: LC209 + LC3 + LC1004 all Accepted (**3 mediums**). LC3 introduced `unordered_set` (first Hashing taste). | Levels: **M4 → L4**. | KEY INSIGHT: boundary/order values recurred 3× — flagged as the #1 weak area; pre-code boundary checklist is now standing. | Next: **Day 2 (June 5) — Prefix Sum finish (O(n) hashmap, LC560) + revision due** (prefix re-test LC724, variable-window recall). Then Two Pointers.

2026-06-05 — Module(s): M5 Prefix Sum (+ hash) | Did: closed-book revision (prefix formula ✓ derived cold incl. L=0 → MISTAKE#1 CLEARED; variable-window template ✓ but min-init reflex slipped again). Taught prefix+hash from scratch (pedometer/clock intuition) after learner pushed back on too-fast Socratic — the deep-explanation worked. | Levels changed: **M5 L3* → L4 EARNED**. | Problems AC: **LC560** (complement sum−k, ~solo), **LC724** (pure prefix, fixed own `prefix[-1]` OOB), **LC974** (remainder mod k — taught negative-modulo primitive `((x%k)+k)%k`), **LC525** (transform 0→−1 + first-index map, heavily coached). | NEW GAPS: "k=length" overfit (treated target sum as window length), "count-all vs find-one-window" confusion. Boundary leak STILL active (3 slips today). | INFRA: built `/start-practice` (daily cold interleaved, practice/day-01 ready), STRIVER_VIDEOS.md (315 vids + backtracking/trie/bit playlists mapped to our modules), memory: Striver-first workflow. | Next: **Hashing formal lesson** (Striver [013] → LC1 Two Sum). Heaps/Strings videos still to source.

2026-06-09 — Module(s): M3 Two Pointers (solo → L4) + M6 Binary Search (theory→videos→easies, L3) | Did: **Two Pointers solo set** — LC167 Two Sum II CLEAN SOLO (converging), LC11 Container largely his (derived "move shorter wall" greedy proof himself), LC283 Move Zeroes + LC680 Valid Palindrome II (coached — boundary OOB + the "commit-the-deletion" skip derivation), LC75 Sort Colors solved SOLO via selection-sort (DELIBERATE constraint-based O(n²) choice — good 10⁸ instinct, not inability). Taught **Dutch National Flag** (low/mid/high partition, the left-known/right-unknown asymmetry) — he understands it conceptually now. **M3 Two Pointers → L4 EARNED (converging)**, with honest GAPS he flagged himself (Dutch-flag re-code, boundary reflex, L5). Then **M6 Binary Search**: theory + Striver videos [045/046/047/056] done; he reasoned out the Koko search-on-answer + the "one tool, four knobs" model + store-candidate himself; built MCP-verified ladder (LC704/35/34/875/410); **AC LC704 + LC35** but with reactive band-aid `if(s==e)` patches. **HUGE notes buildout** (Notes/00-06: recognition map + boundary root-cause framework + complexity-from-constraints + hashing + two-pointers + binary-search + the corrected "two-pointer ≠ sorted-only" rule). **3 memories added** (old-LC-history-not-current-knowledge, study-cadence L4-weekday/hards-weekend, refined Striver→theory→video→problems pipeline). | Levels: **M3 L3→L4**, **M6 L1→L3**. | Problems AC: LC167, LC75, LC283, LC680 (2ptr), LC704, LC35 (BS). | KEY: recognition is consistently STRONG; the ONLY recurring leak is boundary EXECUTION (reactive debug-by-failing-test) — gave him the 4-question boundary framework + "reason 4 edges before submit" rule. | Next: **BS mediums LC34 (first/last) + LC875 (Koko)** tomorrow, clean-template + edges-up-front.

2026-06-08 (cont.) — Module(s): M2 Hashing (formal lesson + first practice set) | Did: **Taught hashing from scratch** Socratically — why it exists (kills the O(n) inner search, "hash map IS the inner loop"), hash fn = squash any key → small array index, pigeonhole ⇒ collisions unavoidable, chaining vs open-addressing (he *invented* open-addressing himself), avg O(1) / worst O(n) (collisions pile into one bucket). Then 4 problems: **LC1 Two Sum** (insert-before-lookup + no-return bugs → fixed: lookup-then-insert, return-on-find), **LC242 Valid Anagram** (AC, then optimized to single int[26] inc/dec; taught the Unicode follow-up = when to switch array→map), **LC49 Group Anagrams** (insisted on brute-force-first — good instinct; brute O(n²·k) AC after ~6 buggy iterations, then optimized to canonical-key + map O(n·k log k); long complexity tangent: n sorts of size k = n·k log k, NOT n log n), **LC128 Longest Consecutive** (sort+scan O(n log n) AC after 4 rounds of boundary bugs; then taught the O(n) hash-set + "only walk from sequence starts" trick). | Levels changed: **M2 Hashing L2* → L3 EARNED (coached)**. NOT L4 — every medium was heavily coached/bug-heavy. | Problems AC (self-reported 6/8): LC1, LC242, LC49, LC128. | KEY: learner self-identified lower confidence on hashing vs SW/prefix (accurate — it's one stage behind, zero revisions). Recurring **boundary/index leak hit AGAIN** ~6× today (LC1 lookup/insert order, LC567 `-'a'`×2 + left, LC128 fwd-vs-bwd compare + loop bound + empty). Good meta-insight from him: "get a correct brute force first, THEN optimize." | Next: **SOLO SET LC217/219/347/36** (practice/03-Hashing/solo-set/) to earn L4 cold, then fresh `/drill`, then Two Pointers. Revision alone won't build the baseline — needs solo reps first.

2026-06-08 — Module(s): M4 Sliding Window consolidation + L5 recognition drill | Did: Deep-dived LC424 (high-water-mark `maxFreq` never-decremented trick — why `if` not `while`, and why a STALE maxFreq is harmless: it can keep a window from shrinking but can NEVER inflate the answer above a genuinely-valid window). Added practice 06/07/08 (LC209/LC3/LC1004 scaffolds). **LC567 Permutation in String: AC but a 5-attempt grind** — fixed-window incremental slide finally clicked (build first window→check→slide `right` from `len` with unconditional `+s2[right]`/`−s2[right-len]`); en route hit 3 more index bugs (`seen[s[left]]` missing `-'a'` ×2, `left` never incremented after a "cleanup" edit, right-start off-by-one) → MISTAKE #6 + watchlist now 9×. Ran **`/drill` (the owed L5 recognition re-test): scored 4/7.** | Levels changed: none raised. M4 SW recognition **strong (3/3 on true-SW Qs: Q1 at-most-2-distinct, Q4 fixed, Q5 shortest)** — approaching L5 but NOT awarded (Q6 false-positive: routed a prefix problem to SW). M5 prefix recognition 1/2 (Q2 ✓ count, Q6 ✗ called SW). **M2 Hashing recognition 0/2 — both Q3 & Q7 defaulted to "two pointers"** (expected: no formal hashing lesson yet). | Problems: LC567 AC (8th medium). | KEY DIAGNOSIS: the drill *proves* hashing is the right next topic — every unsorted pair/duplicate problem gets misfiled under "two pointers." Two new recognition rules banked: (1) "two pointers" needs SORTED data, else HASHING; (2) negatives or ±1 transform ⇒ prefix+hash, never SW. | Next: **M2 Hashing formal lesson** (Striver [013] → LC1 Two Sum), then re-drill recognition.

2026-06-06/07 — Module(s): M5 Prefix Sum practice set + planning | Did: HUGE planning + consolidation session. Set **5-month NeetCode-150 target** (~Nov 2026, L4 bar, one-topic-at-a-time, recognition-map-first) + pinned operating model to memory. Rebuilt `practice/` into 3 topic mastery sets (Prefix/SW/Hashing, 2E+2M+1H each). `/revise` closed-book = **FAILED 6/6** (count↔longest conflated, Two Sum misclassified as two-pointers) → gave the **GOAL×KEY** clarity map. Taught full curriculum/timeline. Added `/map-pattern-optimisation-problems`. | Problems AC (judge): **LC1480, LC303** (easy prefix; LC303 handled left==0 boundary ✓), **LC238** (prefix×suffix — learned "prefix = ANY cumulative aggregate, not just sums"; fixed own loop-direction buffer overflow), **LC523** (prefix+remainder — long debug: off-by-one `i+1`, `if(map[key])` truthiness trap on index 0, first-index overwrite; all index-bugs = boundary family). | KEY BREAKTHROUGHS: "the hash map IS the inner loop" (O(n²)→O(n)); GOAL(count→freq,seen[0]=1 / longest→first-index,seen[0]=-1) × KEY(complement/remainder/transform); discovered `map`(O(log n)) vs `unordered_map`(O(1)) empirically (LC523 150ms→81ms). | Levels: **M5 Prefix Sum solidly L4** (practice set 2E+2M solo; recall improving but L5 not yet — recognition drill pending). | LC862 hard **PARKED** (needs monotonic deque / M8). | Boundary leak STILL active but he's now self-identifying them as index bugs (progress). | Next: **M2 Hashing formal lesson** (Striver [013] → LC1 Two Sum), then SW practice set; `/drill` for the L5 recognition re-test.
```
