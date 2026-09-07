# PRACTICE PROTOCOL — how we run a PRACTICE drill (Hema Vardhan)

> Decided 2026-06-13. This drill (`drill1/`) and the next few are **PRACTICE** drills —
> learning mode. Every ~4th drill is a **TEST** drill (assessment mode, see bottom).
> The goal of practice: build the habit **brute force → find the bottleneck → recognize the
> pattern → optimal**, so that recognition becomes automatic.

---

## File & code structure (so you never write boilerplate)

Each drill is one folder (`drill1/`, `drill2/`, …) containing:
- `README.md` — rules + problem index + recognition log (your scoreboard).
- `PRACTICE_PROTOCOL.md` — this file.
- `LINKS.md` — LeetCode links only (open AFTER you've guessed the pattern).
- one folder **per problem**: `pNN-slug/`

Inside every `pNN-slug/`:
- **`notes.md`** — your THINKING, fixed 8-section template (restate → complexity → pattern
  guess → brute → bottleneck → optimal → compare/cue → bugs → result). Fill it **top-down**;
  don't open LINKS.md or the signature until section 4 is written. See
  `drill1/p01-pair-sum-to-target/notes.md` for a fully filled **worked example**.
- **`solution.cpp`** — ready-to-run skeleton: `#include <bits/stdc++.h>`, `using namespace std;`,
  an empty `Solution` class, and a `main()` test harness. You only paste the LeetCode method
  signature and write the body — no setup, no I/O plumbing.

Compile & run a solution locally:  `g++ -std=c++17 solution.cpp -o sol && ./sol`
(LeetCode is still the final judge — the harness is just for quick sanity checks.)

---

## Per-problem loop (PRACTICE mode)

For each problem, in order:

1. **RESTATE** the problem in ONE plain sentence. (No pattern call until you can.)
2. **DRY-RUN** the given example by hand.
3. **CONSTRAINTS → target complexity.** What Big-O does the input size demand?
   (Remember: value *magnitude* ≠ array *length*. n drives complexity.)
4. **BRUTE FORCE FIRST.** State it, code it, and SUBMIT it (or run locally if it'd TLE).
   Always secure a correct baseline before optimizing. This is the anti-freeze habit.
5. **BOTTLENECK.** Where does the brute force waste work? (the repeated scan, the re-sort, …)
6. **PATTERN HUNT.** Which known pattern attacks that bottleneck? ← *the recognition rep.*
   Run the gates: sorted? → 2ptr/BS possible. unsorted pair/dup? → hashing. negatives/±1? → prefix+hash.
7. **OPTIMAL.** Design it (don't recall it), code it, SUBMIT it.
8. **COMPARE IN DEPTH.** Time & space of brute vs optimal, *why* optimal wins, and the **cue**
   that mapped brute→optimal. The cue gets saved to `PATTERN_JOURNAL.md`.

### Easies vs mediums/hards
- **Mediums & hards:** the full brute-vs-optimal deep-dive is **mandatory**.
- **Easies:** often brute force *is* optimal — note that in one line and move on. Don't pad.

---

## Hint ladder (when stuck)
Kira gives **at most 4 small hints**, one at a time, only escalating when you're still stuck:
1. Nudge toward the right question.
2. Name the key observation / which pattern family.
3. Discuss the approach in words.
4. Pseudocode.

If you're **still** stuck after the 4th hint → Kira explains **fully and in depth**, then you
**re-derive it from scratch** before moving on. (Tapping out is allowed; re-derivation is not optional.)

---

## Grading (logged in this drill's README recognition table)
- **Recognition** = did you name the right pattern on FIRST instinct (before hints)?
- **Restate** = did you restate correctly first try?
- **Brute** = did you produce a correct brute force baseline?
- **AC** = Accepted on the judge (ground truth, not Kira's approval).
- **Notes** = where you slipped + the cue learned.

Misses → `MISTAKE_JOURNAL.md` (root cause + re-test). Cues → `PATTERN_JOURNAL.md`.

---

## TEST drills (every ~4th drill)
Assessment mode — **no brute-force scaffolding, no hints** (or strictly capped). You restate,
recognize cold, and code the optimal directly. Graded against an explicit pass bar. This is
where we prove the practice transferred. Do well → the next practice block gets harder
(fewer easies, harder mediums, more multi-tool hards), all the way to FAANG-ready.
