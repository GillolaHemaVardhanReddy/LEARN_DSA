# 🎛️ COMMAND CENTER — Hema Vardhan (the single front door)

> **Read this first, every session.** It indexes everything — it does NOT duplicate the
> journals (those stay the deep store). One place to answer: *where am I, what's due, what's
> next, where's everything for topic X.* Kira keeps it current; commit it with the rest.

---

## ▶️ TODAY  *(Kira re-renders this block at session start)*
- **Date:** 2026-06-20
- **Current topic / workspace:** drill1 **P21 optimal OWED** (`practice/drills/drill1/p21-find-a-peak/`) → then P22
- **Revision due:** P19 prefix-MOD re-derive (6/21) · overdue: MISTAKE #9 unsorted-gate (**FAILED 4× on 6/20 recap**), #10 restate, #11 atMost, #12 reduction-trap · drill tail Q5/Q7/Q8
- **Next action:** fix P21 optimal — clean BS `while(l<r)`, compare `nums[mid]` vs `nums[mid+1]` only, `else r=mid`, `return l` (current code OOBs on `[1,2,3]`/`[3,2,1]`)
- **Clean-streak focus:** first-submit-clean streak = **0** (P20 TLE'd mid-stream, P21 optimal buggy) → next clean shot = P21 fix or P22.

---

## 🗺️ TOPIC HUB  *(status only — links route to the deep files)*
Level scale: L0–L6 (see `PROGRESS.md` §6). 🎥 = Striver video id (`STRIVER_VIDEOS.md`).

| Pattern | Lvl | 🎥 | Solved | Open leaks / re-tests | Next action |
|---|---|---|---|---|---|
| M1 Complexity | L3* | — | — | verify recall | fold into drills |
| M2 Hashing | **L4** | [013] | E:4 M:4 | #9 unsorted→hashing gate (3× fail) | cold drill → L5 |
| M3 Two Pointers | **L4** | [049+] | E:4 M:2 | Dutch-flag re-code (LC75); over-fire gate | weekend LC75 + L5 drill |
| M4 Sliding Window | **L5** ✅ | — | M:3+ | (clean) | keep warm in drills |
| M5 Prefix Sum | **L4** | — | approaching L5 (pulled back, needs track record) | P19 re-derive 6/21 | L5 drill after streak |
| M6 Binary Search | **L4** | [045/046/047/056] | E:2 M:2 | #8 overflow magnitude; LC33/LC74 unsolved | LC33 + LC74 |
| M7 Stacks + Monotonic | **L2** | [297][298][300][301] | 0 | not yet coded from memory | Valid Parens from memory → L3 |
| M8 Queues/Deque | L0 | — | — | — | after M7 |
| M9+ Recursion → DP → Graphs | L0 | see STRIVER_VIDEOS | — | — | back half (heavier per-pattern) |

> Only **M4 Sliding Window** is a confirmed L5. M5 was claimed L5 then honestly pulled back to
> L4 (one clean call ≠ track record). Don't inflate.

---

## 🧭 MODE LEGEND — which mode am I in? (this is why folders are split)
| Mode | Folder | Purpose | Promotes level? | How it runs |
|---|---|---|---|---|
| **LEARN** | `learn/<NN>-Topic/` | first meeting of a pattern | builds toward L3 | full Socratic, brute→bridge→optimal |
| **PRACTICE** | `practice/` (`practice/<NN>-Topic/`, `practice/drills/drillN/`, `practice/day-NN/`) | reps, calibration, disguised recognition | **no** (it's training) | ≤1 hint then stop; no answer key on drills |
| **TEST** | `test/` (`test/cold-recognition/`, `/drill`, `/interview`) | cold, closed-book | **yes — the only L4→L5 path** | no help; help costs signal |

Rule of thumb: if Kira is teaching/hinting, it's LEARN or PRACTICE. If you're cold and alone, it's TEST.

---

## 🩹 LEAK SCOREBOARD — boss's execution bottleneck (the #1 thing we're fixing)
> Recognition is strong; **execution** is the leak. Every bug updates this; every clean solve grows the streak.
> 🔴 = fired recently · 🟡 = building clean days · 🟢 = reflex forming. Update dates whenever a leak fires.

| Leak | Last seen | Days clean | Catch it with |
|---|---|---|---|
| **Boundary / index / sentinel** | 2026-06-20 | 0 🔴 | Gate C: 4 boundary edges + ANSWER edge |
| **Reduction trap** (drops a constraint) | 2026-06-20 | 0 🔴 | Gate B: hostile input, run ORIGINAL vs REDUCED |
| **Overflow magnitude** (#8) | 2026-06-20 | 0 🔴 | Gate C: seed/accumulator type, size the number |
| **Gate slip** (sorted?→2ptr vs hash; set vs map) | 2026-06-20 | 0 🔴 | Gate C: container + sorted check |

**First-submit-clean streak:** `0`  ·  **best:** `0` (baseline — start the count on P20)
*(A clean solve = AC on judge with ZERO boundary band-aids and no overflow/reduction/gate slip.)*

---

## 📚 WHERE EVERYTHING LIVES
- **Rules / how Kira works:** `CLAUDE.md` · **Pre-flight ritual + stress-test template:** `CHECKLIST.md`
- **Levels & session log:** `PROGRESS.md` · **Spaced repetition:** `REVISION_QUEUE.md`
- **Recognition cues:** `PATTERN_JOURNAL.md` · **Mistakes + root causes:** `MISTAKE_JOURNAL.md`
- **How I learn (Kira's model):** `LEARNING_PROFILE.md` · **C++ fluency gaps:** `CPP_GAPS.md`
- **The map:** `CURRICULUM.md` · **Videos:** `STRIVER_VIDEOS.md` · **Study notes:** `Notes/`
- **Code:** `learn/` (LEARN) · `practice/` (PRACTICE) · `test/` (TEST)
