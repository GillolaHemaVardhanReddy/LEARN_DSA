# 🎛️ COMMAND CENTER — Hema Vardhan (the single front door)

> **Read this first, every session.** It indexes everything — it does NOT duplicate the
> journals (those stay the deep store). One place to answer: *where am I, what's due, what's
> next, where's everything for topic X.* Kira keeps it current; commit it with the rest.

---

## ▶️ TODAY  *(Kira re-renders this block at session start)*
- **Date:** 2026-06-23 (evening — NGE warm-up FINISHED + Daily Temps coded; session ended, continues morning)
- **Current topic / workspace:** **M7 Monotonic Stack — L3 EARNED** (NGE warm-up 100k stress GREEN). **Daily Temperatures (LC739)** coded, brute+optimal stress-GREEN + canonical example — **judge-AC PENDING** (MCP not signed in → 403). Next folder: `learn/07-Stacks/03-Next-Greater-Element-II/` (scaffolded).
- **MORNING PLAN (3 things):** (1) **Restart Claude Code** so MCP signs in, then **submit LC739 in browser** → confirm AC (link in `02-Daily-Temperatures/problem.md`). (2) **NGE II (LC503)** solo — circular twist: loop `0→2n-1`, read `nums[i%n]`, store value, 2nd lap only RESOLVES. (3) **Stock Span (LC901)** solo — engine flipped to previous-greater + a span count. DT-AC + these 2 = **M7 L4**.
- **WIN to bank loud:** monotonic stack is L3 — he rebuilt the concept closed-book AND coded the engine clean (100k green). Biggest growth: on NGE he **found his own bugs by tracing his own code** — the premature-"done" antidote, working.
- **Revision due:** monotonic concept +1d (6/24) · plain-stack concept recall · C++ gaps #6/#7/#8 standing · P19 prefix-MOD +3d ≈ 6/24 · derive-don't-maintain cold recall 6/25 · BS discard-ability remainder (LC852/540/33) · still overdue: MISTAKE #9 unsorted-gate, #10 restate, #11 atMost · drill tail Q5/Q7/Q8 · **P25 Trapping (LC42, hard) = WEEKEND.**
- **Clean-streak focus:** first-submit-clean streak = **0**. The **premature-"done"** leak fired **3× more on Daily Temps** (fixes one bug, asks "check," doesn't self-trace the rest) — BUT the antidote landed on NGE (he self-traced and found both bugs). The morning rep = on NGE II / Stock Span, **trace his OWN code on a hostile input BEFORE saying done.** Next clean shot = NGE II or Stock Span.

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
| M7 Stacks + Monotonic | **L3** | [297][298][300][301][303] | LC20 · NGE(stress) · LC739(pending) | plain-stack L3 ✓; **monotonic L3 ✓** (NGE 100k green); DT judge-pending | submit LC739 → NGE II + Stock Span → L4 |
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
| **Premature "done" — declared finished before self-running Gate C / trace** 🆕 | 2026-06-23 | 0 🔴 | **Fired 4× on 6/23.** NGE: fixed 1 of 3, said "done." Daily Temps: fixed brute → "check"; fixed optimal subtraction but left inverted comparison → "is it ok"; the "fix one → ask for validation" loop. **ANTIDOTE LANDED on NGE** (he self-traced and found BOTH bugs). Fix = refuse to be the checker; make him **trace his OWN current code on a hostile input** (`[72,71,76]`) before "done." Name the tell: *wanting to ask "is it ok" IS the cue to trace it yourself.* |
| **Band-aid / redundant maintained state** (patch over wrong structure) | 2026-06-22 | 0 🔴 | **⭐ Derive-don't-maintain:** P23 hand-synced 6 vars (cut to 2); P24 bolted on an `ans` tracker to patch a bad `mid±1`. Audit before submit: any var that's really `r-l+1`? any two vars that must agree? |
| **Constraint-drop / reading miss** (brute omits a stated rule, or misreads what's asked) | 2026-06-23 | 0 🔴 | **pos-vs-distance RECURRED on LC739 (6/23, same as 6/22):** restate said "find the POSITION of the warmer day"; gentle example `[73,74,71]` hid it (distance==index), hostile `[72,71,76]` exposed it (position 2 ≠ wait 1) → corrected to `j-i`. `answer[i]` is a DISTANCE, not a position. Lesson: pick the example so position≠distance. Restate WHAT is returned, in exact units; Gate A keeps earning its keep. |
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
