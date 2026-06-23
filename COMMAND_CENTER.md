# 🎛️ COMMAND CENTER — Hema Vardhan (the single front door)

> **Read this first, every session.** It indexes everything — it does NOT duplicate the
> journals (those stay the deep store). One place to answer: *where am I, what's due, what's
> next, where's everything for topic X.* Kira keeps it current; commit it with the rest.

---

## ▶️ TODAY  *(Kira re-renders this block at session start)*
- **Date:** 2026-06-23 (morning — M7 monotonic-stack re-learn + NGE warm-up, **paused for 1hr break mid-rep**)
- **Current topic / workspace:** **M7 Monotonic Stack — concept REBUILT, generic NGE warm-up IN PROGRESS** (`learn/07-Stacks/Next-Greater-Element-warmup/`). Brute AC-correct; **optimal still buggy (2 of 3 bugs live)**. Then: **Daily Temperatures (LC739)** solo at `learn/07-Stacks/02-Daily-Temperatures/`.
- **RESUME PLAN (after the 1hr break):** finish the NGE **optimal** — two fixes owed: (1) **push the INDEX `i`, not the value `ch`** (currently `st.push(ch)` → `nums[st.top()]` reads OOB, e.g. `nums[5]` on a size-5 array); (2) **`vector<int> ans(n,-1)` pre-sized + write `ans[j]=nums[i]` by index** (currently `ans.push_back(st.top())` records in pop-order at the wrong slots; this also deletes the trailing `-1` loop). He must **re-trace `[3,1,2,5,4]→[5,2,5,-1,-1]` on paper** before compiling, then run the 100k stress GREEN. That = monotonic stack **coded-from-memory → L3**. THEN map onto Daily Temperatures solo → **M7 L4.** Daily Temps stays SEALED (held the line abstractly today — keep it).
- **Concept WIN to bank loud at resume:** closed-book, he had the TRIGGER cold, rebuilt the WHY (elements park & wait; a newcomer pays a BATCH) + WHY-monotonic (order is a consequence) + **stated the O(n) amortization in his own words** ("push once, pop once → 2n, not n²"). The concept is genuinely his now — the gap left is pure EXECUTION (translate trace → clean code).
- **Revision due:** Daily Temps (morning) · plain-stack concept +1d (6/23) · C++ gaps #6/#7/#8 standing · P19 prefix-MOD +3d ≈ 6/24 · derive-don't-maintain cold recall 6/25 · BS discard-ability remainder (LC852/540/33, 6/23) · still overdue: MISTAKE #9 unsorted-gate, #10 restate, #11 atMost · drill tail Q5/Q7/Q8 · **P25 Trapping (LC42, hard) = WEEKEND.**
- **Clean-streak focus:** first-submit-clean streak = **0**. NEW leak shape fired today: **declared "done" after fixing 1 of 3 flagged bugs — self-Gate-C / self-trace NOT run.** The rep at resume = trace his OWN code before calling it done. Next clean shot = **Daily Temperatures** (run the 4 boundary edges + the trace on himself BEFORE submit).

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
| M7 Stacks + Monotonic | **L3** | [297][298][300][301] | LC20 | plain-stack L3 ✓; monotonic still L2 (theory only) | Daily Temps (LC739) → L4 |
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
| **Boundary / index / sentinel** | 2026-06-23 | 0 🔴 | Gate C: 4 boundary edges + ANSWER edge — **NGE warm-up 6/23: pushed VALUE not INDEX → `nums[st.top()]` read OOB (`nums[5]` on size-5); built `ans` by `push_back` in pop-order → answers land at wrong slots** (fix = `ans(n,-1)` + `ans[j]=nums[i]`). **LC20: TWO traps in one** (empty-stack-on-close; leftover-opens). **P24: `r=mid-1` discarded the min**. Cue: "could mid be the answer?" + "what does the stack HOLD — index or value?" + "is `ans` written at the right SLOT?" |
| **Premature "done" — declared finished before self-running Gate C / trace** 🆕 | 2026-06-23 | 0 🔴 | NGE warm-up: given 3 flagged bugs, he fixed **1** (`if`→`while`) and said "done" — the other 2 still live. The fix = before saying done, **trace your OWN current code on the canonical input** and confirm the output. This is the self-Gate-C rep (the leak underneath the streak-of-0). |
| **Band-aid / redundant maintained state** (patch over wrong structure) | 2026-06-22 | 0 🔴 | **⭐ Derive-don't-maintain:** P23 hand-synced 6 vars (cut to 2); P24 bolted on an `ans` tracker to patch a bad `mid±1`. Audit before submit: any var that's really `r-l+1`? any two vars that must agree? |
| **Constraint-drop / reading miss** (brute omits a stated rule, or misreads what's asked) | 2026-06-22 | 0 🔴 | Gate A: **LC739 restate said "find the POS of warmer day" → dry-run wrote `answer[1]=2` (the index) instead of 1 (the WAIT)** — `answer[i]` is a DISTANCE `j-i`, not a position. Also P23 summed VALUES instead of counting. Restate WHAT is returned, in exact units; Gate A keeps earning its keep. |
| **Reduction trap** (drops a constraint) | 2026-06-20 | 1 🟡 | Gate B: hostile input, run ORIGINAL vs REDUCED |
| **Overflow magnitude** (#8) | 2026-06-20 | 1 🟡 | Gate C: seed/accumulator type, size the number |
| **Gate slip** (sorted?→2ptr vs hash; set vs map) | 2026-06-21 | 0 🔴 | Gate C: container + sorted check |

**First-submit-clean streak:** `0`  ·  **best:** `0`  (P23 AC — Gate-A reading miss + over-engineered optimal · P24 AC — band-aid→clean, not first-submit → next clean shot = **P25**, a hard)
*(A clean solve = AC on judge with ZERO boundary band-aids and no overflow/reduction/gate slip.)*
*Positive signals 2026-06-22: **the ⭐ DERIVE-DON'T-MAINTAIN principle TRANSFERRED across patterns in one session** — taught on a window (P23), he applied it to BINARY SEARCH an hour later (P24: killed his own `ans` band-aid → clean `while(l<r)` converge). **TRACE-FIRST caught BOTH misses** (P23 reading, P24 boundary) — his #1 modality confirmed again. **First local stress-test ever run** (100k cases, oracle silent) — toolchain unblocked, this is now standing. **He CALLED his own traps** twice (P23 "this is over-engineered", P24 "this is too easy = I'm dodging the rep"). Residual leak = FIRST-INSTINCT execution (defaults to exact-target BS template + redundant maintained state), then fixes on review — now NAMED + SCHEDULED.*

---

## 📚 WHERE EVERYTHING LIVES
- **Rules / how Kira works:** `CLAUDE.md` · **Pre-flight ritual + stress-test template:** `CHECKLIST.md`
- **Levels & session log:** `PROGRESS.md` · **Spaced repetition:** `REVISION_QUEUE.md`
- **Recognition cues:** `PATTERN_JOURNAL.md` · **Mistakes + root causes:** `MISTAKE_JOURNAL.md`
- **How I learn (Kira's model):** `LEARNING_PROFILE.md` · **C++ fluency gaps:** `CPP_GAPS.md`
- **The map:** `CURRICULUM.md` · **Videos:** `STRIVER_VIDEOS.md` · **Study notes:** `Notes/`
- **Code:** `learn/` (LEARN) · `practice/` (PRACTICE) · `test/` (TEST)
