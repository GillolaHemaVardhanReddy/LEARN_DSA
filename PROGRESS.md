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
- Current phase: Foundations → Linear patterns
- Current module: **M5 Prefix Sum — DONE (L4)** (2026-06-05). M4 Sliding Window DONE (L4).
- Current topic: → **M2 Hashing** (formal lesson next — Striver video [013], then LC1 Two Sum). Flagged #1 gap.
- Overall mastery (started topics): ~60% (M4 L4 + M5 L4 earned; M1 L3*, M2 L2* still provisional)
- Observed velocity: Day 2 = M5 prefix+hash to L4 + **4 problems AC** (LC560/724/974/525). Day 1 = M4 + 3 mediums.
- Workflow change (2026-06-05): **Striver A2Z videos first (see STRIVER_VIDEOS.md), then practice here.** From M6 onward, Striver-first.
- New infra built: `/start-practice` (daily cold interleaved set, practice/day-NN/), STRIVER_VIDEOS.md (315 vids mapped).
- Projected ready date: ~2026-11-04 | vs goal: On track

> **Levels below are PROVISIONAL (self-reported on transfer 2026-06-04).** Marked `*`.
> They convert to earned levels only as I witness the evidence (§6). First verification: this session's revision.

---

## Topic levels
> One row per module from `CURRICULUM.md`. Update the level + the date + a one-line
> evidence note when it changes. Keep `solved` as `easy/medium` counts.

| ID | Module | Level | Last touched | Solved (E/M) | Evidence note |
|----|--------|-------|--------------|--------------|---------------|
| M1 | Complexity Analysis | L3* | 2026-06-04 | 0/0 | *Self-reported: O(1)→O(n²), log-rule (i*=k→log n), 4 rules, Ω/O/Θ. Verify recall. |
| M2 | Arrays & Hashing | L2* | 2026-06-04 | 0/0 | *Arrays understood. HASHING formal lesson NEXT (used unordered_map operationally in M5 but no formal lesson yet — Striver [013] then LC1). |
| M3 | Two Pointers | L0 | — | 0/0 | Upcoming (Striver SW/2P playlist). |
| M4 | Sliding Window | L4 | 2026-06-04 | 2/3 | **WITNESSED L4**: 3 mediums AC — LC209/LC3/LC1004. Recognition + approach independent. Residual: boundary/order values. |
| M5 | Prefix Sum | **L4** | 2026-06-05 | 1/3 | **WITNESSED L4**: prefix+hash engine applied to 3 distinct keys — LC560 (complement sum−k, largely solo), LC974 (remainder mod k, derived structure; needed the negative-modulo PRIMITIVE), LC525 (transform 0→−1 + first-index map; heavily coached on the logic but AC). +LC724 easy AC. Recognition path (window-dead→prefix→isolate complement→hash) understood. Linked to Two Sum. |
| M6 | Binary Search | L0 | — | 0/0 | |
| M7 | Stacks & Monotonic Stack | L0 | — | 0/0 | |
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
- 🆕 **Recognition recall weak** (closed-book 6/6 FAIL) — misclassified UNSORTED Two Sum as "two pointers"
  (it's HASHING; sorted→two pointers). L4 earned via judge, but L5 (recognize cold) NOT yet there. Drill needed.

## Problem counters
- Easy solved: 3 (LC643, LC1343 self-reported · **LC724 judge-verified**) · Medium solved: 6 (LC209, LC3, LC1004, **LC560, LC974, LC525** — judge-verified) · Hard (stretch): 0 · Total: 9

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

2026-06-04 — Module(s): M4 Sliding Window (Variable) | Did: transfer/First-Run setup; closed-book revision (O(log n) reasoning ✓, prefix-sum formula ✗→repaired, window cue ✓); taught Variable Sliding Window (caterpillar); set up SPRINT_PLAYBOOK + readable solutions/ + Notes/ + run.sh (fixed macOS linker bug = Anaconda stale ld) + LeetCode MCP (live next restart). | Levels changed: M4 L3* → L3 EARNED (LC209 Medium coded from understanding, Accepted on judge). Variable window L2 (explained back) → L3 (implemented). | Problems: LC209 + LC3 + LC1004 all Accepted (**3 mediums**). LC3 introduced `unordered_set` (first Hashing taste). | Levels: **M4 → L4**. | KEY INSIGHT: boundary/order values recurred 3× — flagged as the #1 weak area; pre-code boundary checklist is now standing. | Next: **Day 2 (June 5) — Prefix Sum finish (O(n) hashmap, LC560) + revision due** (prefix re-test LC724, variable-window recall). Then Two Pointers.

2026-06-05 — Module(s): M5 Prefix Sum (+ hash) | Did: closed-book revision (prefix formula ✓ derived cold incl. L=0 → MISTAKE#1 CLEARED; variable-window template ✓ but min-init reflex slipped again). Taught prefix+hash from scratch (pedometer/clock intuition) after learner pushed back on too-fast Socratic — the deep-explanation worked. | Levels changed: **M5 L3* → L4 EARNED**. | Problems AC: **LC560** (complement sum−k, ~solo), **LC724** (pure prefix, fixed own `prefix[-1]` OOB), **LC974** (remainder mod k — taught negative-modulo primitive `((x%k)+k)%k`), **LC525** (transform 0→−1 + first-index map, heavily coached). | NEW GAPS: "k=length" overfit (treated target sum as window length), "count-all vs find-one-window" confusion. Boundary leak STILL active (3 slips today). | INFRA: built `/start-practice` (daily cold interleaved, practice/day-01 ready), STRIVER_VIDEOS.md (315 vids + backtracking/trie/bit playlists mapped to our modules), memory: Striver-first workflow. | Next: **Hashing formal lesson** (Striver [013] → LC1 Two Sum). Heaps/Strings videos still to source.
```
