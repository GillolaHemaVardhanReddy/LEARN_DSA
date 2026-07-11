# ROADMAP_PLAN.md — the "upgrade Kira's machine" initiative

> Created 2026-07-11 (research + planning session). This file is the blueprint for a
> multi-part upgrade: (1) ratify a syllabus diff, (2) add a book/reference layer, (3)
> build an interactive HTML progress-map (dependency tree), (4) gather resources.
> **This session = research + plan only. Build happens next session.** The exact
> kickoff prompt is at the bottom (§4).

---

## §0. STATUS OF THE 4 ASKS
| Ask | This session | Next session |
|---|---|---|
| 1. Verify syllabus authentic/best-practice | ✅ DONE — audited vs NeetCode150 / Striver A2Z / Blind75 / AlgoMonster / Grokking. Verdict **8.5/10**, additive diff proposed (§1). | Boss ratifies the diff → apply to `CURRICULUM.md`. |
| 2. Best books → references file | ✅ DONE — `references/README.md` created (shortlist + per-module map). | Update chapters/editions once boss brings PDFs. |
| 3. Interactive HTML dependency-tree dashboard | ✅ DESIGNED — full spec (§3). | **BUILD it** to spec. |
| 4. Gather resources / reference PDFs | ✅ Checklist created (§2). | Boss brings PDFs; we wire exact page refs. |

---

## §1. SYLLABUS DIFF — proposed, to RATIFY next session (additive only)

**Decision: additive-only. No renumbering.** Boss is mid-flight at L3/L4 across M7–M10 with
built folders; a 24-module renumber would destroy in-flight work for cosmetic gain. So we
KEEP all module numbers and only *add* to ladders + append one new module.

**Audit verdict:** authentic + best-practice, **8.5/10**. Zero broken dependencies. The
ordering choices (Recursion after Stacks; Backtracking before Trees; Greedy after DP) are
deliberate and defensible — **keep them.**

### Accepted changes
1. **NEW M25 — Math & Geometry** (light module, low-dependency, slots late like Bit Manip).
   Closes the single biggest hole (0 of NeetCode's 8 covered).
   Ladder: Rotate Image (M), Spiral Matrix (M), Set Matrix Zeroes (M), Happy Number (E),
   Plus One (E), Valid Sudoku (M), Detect Squares (M). *(Renumber old M25/M26 consolidation →
   M26/M27, or fold them into Phase 6 prose — decide at ratify.)*
2. **M20/M21 — add the Stock-DP family:** Buy/Sell Stock with Cooldown (M), with Transaction
   Fee (M), II/III/IV. **Add Longest Palindromic Substring to M20** (distinct from Palindromic
   Substrings). Highest-frequency DP family, currently absent.
3. **M17 — add Alien Dictionary** (the most-cited topo-sort question after Course Schedule).
   **M19 — pull Min Cost to Connect All Points (Prim/MST) in from Phase 7** (it's in NeetCode
   150's own core list; don't defer it past interview-ready).
4. **Small completeness fixes:**
   - M11 ← Find the Duplicate Number (directly exercises the Floyd's-cycle gate M11 claims).
   - M6 ← Time Based Key-Value Store (binary-search-on-timestamps design problem).
   - M2 ← Valid Sudoku + Encode and Decode Strings.
   - M15 — promote Word Search II from "stretch" to **core** (it's 1 of only 3 in NeetCode's
     Tries category).
5. **M8 — annotate as a "light" module** (no source treats Queue as first-class; keep it, don't
   merge, don't inflate its gate). One-line note in CURRICULUM.md.

### Rejected
- **Merge M7+M8** → REJECTED (renumber cost > benefit; boss already invested).
- Any reordering → REJECTED (current order is defensible; several choices deliberate).

---

## §2. RESOURCE-GATHERING — ✅ DONE (PDFs gathered 2026-07-11)

Boss gathered the PDFs. Editions verified from real TOCs; chapters pinned in `references/README.md`.

- [x] **Skiena — Algorithm Design Manual, 3rd ed.** — ✅ in `references/` (739pp, 3e confirmed). The recognition brain.
- [x] **Competitive Programmer's Handbook** (Laaksonen) — ✅ `book.pdf` (296pp). C++ implementation reference.
- [x] **Cracking the Coding Interview, 6th ed.** — ✅ in `references/` (708pp). *Substituted for* the
      recommended *Beyond* CtCI — fine; covers the interview-process / C++ / testing layer. *Beyond* = optional later.
- [x] **Competitive Programming 4, Book 1** (Halim, 2020 official eBook) — ✅ `cp4-1.pdf` (329pp). Landed
      early (I'd said Phase 7, but it's a best-in-set ref for M16–M22 graphs/DP/greedy too — folded in now).
- [ ] *(Phase 7 only)* CP4 **Book 2** — the deep ICPC volume (segment trees, flows, strings, geometry). Buy when CP track opens.

**Housekeeping done:** PDFs are `.gitignore`d (large + copyrighted → local only); the tracked
artifact is `references/README.md`. Editions confirmed; per-module chapters pinned to real TOCs.

Kira's free companions (no PDF): cp-algorithms.com, usaco.guide, algs4 booksite, Skiena's Stony Brook lectures.

---

## §3. HTML DASHBOARD — full build spec (BUILD NEXT SESSION)

### 3.1 What it is
A **single self-contained HTML file** (inline CSS + JS, zero external deps — so it also works
as a publishable Artifact and offline). It visualizes the whole 24-module DSA journey as an
**interactive dependency tree**, colored by mastery level, with boss's *current position*
highlighted, and a details popup per module.

Target file: `dashboard/dsa-map.html` (data embedded as a JS object regenerated from the
state files — see 3.6).

### 3.2 The open animation (boss's "DSA button")
- Landing state: a centered, large, glowing **"DSA"** hero button on a clean canvas; subtle
  idle pulse. A one-line subtitle: "click to open your map."
- On click: the button **morphs/expands** outward — scale-up + fade — and the dependency graph
  **grows in** from the center: nodes spring outward to their layout positions (staggered,
  ~40ms apart), edges draw themselves (SVG stroke-dashoffset animation), phases fade in top→bottom.
- Total animation ≈ 1.2s, `prefers-reduced-motion` → instant render (accessibility).
- A "collapse / back to DSA" control returns to the hero (reverse animation).

### 3.3 The graph — layered dependency DAG
- **Layout:** layered top-to-bottom by **phase** (Phase 1 at top → Phase 5/6 at bottom),
  mirroring `CURRICULUM.md`'s dependency graph. Within a layer, spread modules horizontally.
  Node x = assigned by layer + sibling index; y = phase depth. Hand-rolled SVG layout (no D3/CDN
  — CSP-safe). Compute layer depth = longest-path-from-root over the `deps` edges.
- **Node = a module** (M1…M25). Each subtree/cluster = a phase (grouped + subtly boxed/labeled).
- **Edges = prerequisites** (M2→M3 etc.), drawn as curved SVG paths with arrowheads.
- **Color = mastery level** (from PROGRESS.md, the L0–L6 scale). Legend swatch:
  `L0 gray · L1–L2 dim blue · L3 amber · L4 green · L5 bright green · L6 gold`. Must read in
  BOTH light and dark theme (theme-aware CSS; `prefers-color-scheme` + `[data-theme]` override).
- **Current position:** the active module(s) get a distinct **pulsing ring** + "you are here"
  tag. (Currently: M10 Backtracking, with M8 practice open in parallel.)
- **Progress summary bar** (top): `X / 24 modules at L4+ · overall XX% · current: M10`. Numbers
  derive from the same L0–L6→% map CLAUDE.md §6 uses (L0=0 L1=15 L2=35 L3=55 L4=75 L5=90 L6=100).

### 3.4 The per-module popup (click a node)
Modal card, dismiss on outside-click / Esc. Contents pulled from the module's data object:
- **Header:** module number + name + phase + a colored level chip (e.g. "L3 · implements").
- **Objective:** one line (from CURRICULUM.md).
- **Patterns + recognition trigger** ("if you see ___ → consider ___").
- **Topics covered** (bulleted).
- **Problem ladder** (E/M/H tags), with solved ones checkmarked.
- **Prereqs** (links to parent nodes) + **unlocks** (children).
- **Current status line:** level + open leaks/re-tests (from COMMAND_CENTER topic hub) + "next action."
- **Reference:** the book chapter from `references/README.md`.

### 3.5 Interactions / polish
- Hover a node → highlight its full prerequisite chain (ancestors) + dependents (descendants),
  dim the rest.
- Optional filter chips: "show only in-progress" / "show mastered" / "show locked (prereq unmet)".
- Fully responsive; graph pans/zooms on small screens (or scrolls inside an `overflow:auto` box).
- No horizontal body scroll; wide graph lives in its own scroll container.

### 3.6 Data model (embedded JS, regenerated from state files)
Single source array; each entry:
```js
{ id:"M10", name:"Backtracking", phase:2, level:3,           // L0..L6
  deps:["M9"], unlocks:["M11"],
  objective:"...", trigger:"generate all subsets/perms/combos → choose/explore/un-choose",
  topics:["choose-explore-un-choose","pruning","state restore"],
  ladder:[{p:"Subsets",d:"M",done:false}, ...],
  status:"L3 · LC78 AC claimed; M#8 re-test on LC46", next:"LC46 → LC39/90/79/131",
  ref:"ADM Ch.9 (Combinatorial Search)" }
```
**Regeneration rule:** the data object is generated from `PROGRESS.md` (levels) + `CURRICULUM.md`
(objectives/ladders/deps) + `COMMAND_CENTER.md` (status/leaks) + `references/README.md` (ref).
When those change, Kira regenerates the embedded `MODULES` array (a small script or by hand at
session end) so the map never drifts from the source of truth. **The map READS the state files;
it never becomes a second source of truth.**

### 3.7 Build acceptance checklist (next session)
- [ ] Opens with the DSA-button animation; reduced-motion instant path works.
- [ ] All 24(+M25) modules present, correctly layered by phase, edges = real prereqs.
- [ ] Colors match live levels from PROGRESS.md; legend present; light+dark both readable.
- [ ] Current position (M10 + M8) pulses.
- [ ] Every node opens a correct popup (objective, topics, ladder, status, ref).
- [ ] Progress summary numbers derive from the §6 level→% map (no invented figures).
- [ ] Self-contained (no external fetch); publishable as an Artifact.

---

## §4. ⭐ NEXT-SESSION KICKOFF PROMPT  (boss: paste this to start next session)

```
Kira — resume the ROADMAP_PLAN initiative (see ROADMAP_PLAN.md). Do these in order:

1. RATIFY THE SYLLABUS DIFF (§1). Walk me through the additive changes one screen at a
   time; I approve/tweak each; then apply the approved diff to CURRICULUM.md (additive,
   NO renumbering) and commit.

2. BUILD THE HTML DASHBOARD to the §3 spec: dashboard/dsa-map.html, a single
   self-contained file — DSA hero button → animated expand into a layered dependency
   tree of all modules, colored by my real mastery levels from PROGRESS.md, my current
   position (M10 + M8) pulsing, and a per-module popup (objective, topics, ladder,
   status, book ref). Generate the embedded MODULES data from the state files so the
   map reads the source of truth, never duplicates it. Run the §3.7 acceptance checklist.
   Then publish it as an Artifact so I can open it in the browser.

3. Books are already in + verified (Skiena ADM 3e, Laaksonen CPH, CTCI 6e, CP4 Book 1) —
   references/README.md chapters are pinned. Just confirm nothing drifted.

Then hand me back to normal DSA work — LC46 Permutations is still mid-rep (Bridge Q1/Q2),
and the M10 consolidation reading (Skiena Ch.7 + Ch.14, CP4 3.2) is teed up for after the AC.
```

---

## §5. WHERE WE PAUSED THE DSA WORK (so it's not lost)
- **LC46 Permutations** is open mid-rep — `phase-2/learn/10-Backtracking/02-LC46-Permutations/solution.cpp`.
- Boss's live question was Bridge Q1/Q2: *at slot 0, how many branches, and what's the pool of
  choices at slot 1?* — the trace of `[1,2,3]` grouped by position-0 was handed to him. Resume
  there after the roadmap build.
