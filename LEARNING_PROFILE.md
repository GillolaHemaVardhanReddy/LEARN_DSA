# LEARNING_PROFILE.md — How Hema Vardhan Learns (Kira's model)

> Kira's running hypothesis log about *how* Hema Vardhan learns — which hint
> modalities land, which fall flat, the shapes of his confusion, what "he really
> gets it" sounds like. Read at session start. Update whenever you learn something
> about his learning (not about DSA content — that goes in the other journals).
> This is a hypothesis log, not gospel: revise when evidence changes.

---

## Modalities — what lands vs what slides off

| Modality | Verdict | Evidence |
|---|---|---|
| **Concrete counterexample he traces himself** | ✅ **strongest** | P14: given `[2,2,1,1,1], k=3` he immediately diagnosed "answer should be 3 but comes 1 because it never goes > k." Hand-tracing a breaking input unlocks him fast. |
| **Grounded abstraction** (abstract idea tied to a specific value he computes) | 🟡 likely strong, under-used | Hasn't been tried cleanly yet — predicted to work given the trace result. Try: "on THIS input `starts` should be 3 here — why?" |
| **Prose / verbal model** ("maintain a running variable, add it every step") | ❌ **falls flat for structural ideas** | P14: the `starts`-variable model was given twice in words and did **not** transfer to his code either time. He kept patching the old frame. |
| **Scaffold** (skeleton with holes) | ❔ untried | Try next when a structural rewrite is needed. |
| **Analogy / visual** | ❔ untried | — |

---

## Confusion shapes (the *kind* of stuck, beyond the specific bug)

- **Patches symptoms around a broken frame instead of replacing the frame.** P14: when
  his single-pass `ans++` model couldn't count "exactly k," he added more `ans++`
  sites (else-branch, shrink-loop tweaks) — producing a see-saw where fixing the
  leading-evens case broke the trailing-evens case and vice-versa. Tell: **oscillating
  pass/fail between mirror cases** = the structure is wrong, stop patching. When you
  see this, name it explicitly and move him to a *new* structure (scaffold/grounded),
  don't let him keep bolting on.
  - **RECURRED P24 (2026-06-22), and he climbed out fast once named:** boundary search where
    `r=mid-1` discarded the answer → his fix was to **add an `ans` tracker** (bolt-on), not fix the
    structure. Naming it "band-aid vs structural fix" + giving the rule ("could mid be the answer? →
    keep it") got him to the clean `while(l<r)` form himself. **NEW HYPOTHESIS (strong):** he is now
    *responsive* to "you're patching, replace the frame" as an explicit callable — say it by name.

- **⭐⭐ THE STRONGEST TEACHING MOVE YET, CONFIRMED (2026-07-10, LC78 / un-choose): DON'T TEACH THE
  CONCEPT — LET HIS BUG TEACH IT.** un-choose was deliberately withheld for two sessions. The scaffold
  was built so his own code would *have* to hit it. It worked, in four beats:
  (1) He wrote a broken flag-based recursion. (2) Kira refused to check it → handed him `[1,2,3]` and
  made him trace **his own code**. He came back with the emit list and saw the dupes/missing subsets
  himself. (3) ONE surgical question — *"your `pop_back` sits between the two recursive calls of frame
  i: which element does it pop, and which do those calls decide about?"* — answered instantly and
  correctly. (4) After a single `STUCK`→L3 (words, no code), he **stated the invariant unprompted**:
  *"if we go to next call with a state and come back then we should have same state of sett."*
  **A concept he was never told, produced in his own words, from his own failure.** That is L2-going-on-L6
  in one sitting. **Generalize this: for any pattern whose core is an INVARIANT, do not lecture it —
  scaffold a problem whose bug is the invariant's violation, refuse to check, and ask one question.**
  Cost: ~4 exchanges. Compare with prose-first, which historically slides off him entirely.
- **He asks "why is X wrong?" *after* fixing X — and that question is where the learning consolidates
  (2026-07-10).** He fixed the flag bug, then asked *"but why does pick have disease?"* This is a
  **retention gift, not a delay** — answer it in FULL and connect it to a principle he already owns.
  Here: the `pick` flag = his own **derive-don't-maintain** rule in recursion costume. He did not have
  to be sold on it; naming his own principle back to him closed it instantly. **Rule: when he asks a
  post-hoc "why", spend the tokens, and always route the answer through a principle already in his
  vocabulary rather than a new one.**
- **⚠️ TELL — "run urself" = the tap-out (2026-07-10).** He asked Kira to run the stress test and ended
  the session. Same family as premature-"done". It arrived right after a hard win, and right after he
  mentioned skipping theory — read it as **fatigue, not laziness**. Response that seems right: comply,
  but name it in one line without a lecture, and hand the check back as the FIRST item of next session.
  (Do not moralize — he'd already done the hard cognitive work. The check is cheap; the derivation was not.)
- **⚠️ He asks for "theory / Striver video" when he's stuck — and it's usually a DODGE of the last hard
  inch (2026-07-10).** He requested the video *after* deriving the invariant and *before* writing 6 lines
  of code. Declining was correct: he was one function from owning a self-derived pattern, and a lecture
  would have overwritten his own derivation with someone else's. **Heuristic: if he's ≥80% of the way to
  the idea, video = consolidation AFTER the code, never instruction before it.** (His standing
  Striver-then-practice workflow still holds for *unopened* topics — this exception is for mid-derivation.)

- **⭐⭐ CONFIRMED FIX — SEED EVERY ABSTRACT STATEMENT WITH CONCRETE NUMBERS (hypothesis 2026-08-09,
  CONFIRMED 2026-08-10).** On 8/09 two questions stalled at the *reading* layer before recognition
  ever got a chance: he called a clean statement "a contradiction" (Q4) and "so vague" (Q5), then
  produced the full correct answer the moment he was handed 2–3 input→output lines. On 8/10 I put
  the numbers **in the statement up front** for five straight questions — **zero reading stalls**,
  including on **Q5, the exact statement that had defeated him the previous day**, which he then
  answered immediately. **This is trace-first applied one layer earlier than I had been applying
  it** — not "trace when stuck", but "never hand him a statement without a trace attached".
  **Standing: every problem statement I give him ships with 2–3 concrete examples.** Cost: three
  lines. Payoff: it stops scoring his *reading* as a *recognition* failure, which would have sent
  repair time to entirely the wrong place.

- **🔴🔴 THE BIGGEST FINDING OF THE COMEBACK RUN — TOOL-CARRYOVER (2026-08-10). He answers a new
  question with the PREVIOUS question's tool.** Verbatim sequence: Q5 he chooses recursion; **Q6
  opens *"here also its pick not pick"*** (on a subarray-counting problem where that machine cannot
  work); he then invents sliding window for Q6; **Q7 opens *"this is a fixed sliding window"*** (on
  a sort + two-pointer pairing problem). Three questions, and the tool is *inherited* every time.
  - **Why I nearly mis-scored this as decay:** three ❌/🟡 in a row looks like four patterns rotting.
    It isn't. Q6 he **self-corrected unprompted** minutes later, and Q9 he built a correct multiset
    solution off **one** probe. The knowledge is *there*. What's missing is a **gate between reading
    the statement and reaching for a tool** — his first instinct is unguarded, and an unguarded
    first instinct grabs whatever is warmest, which is the last thing he used.
  - **Why it stayed hidden through four L4 promotions:** inside a topic folder, carrying the topic's
    tool forward is *always correct* and gets rewarded for weeks. It can only fire under
    interleaving — which is to say, **only in an interview**. This is the single strongest argument
    yet for the interleaved gauntlet format; single-topic practice is structurally blind to it.
  - **The move (→ M#12):** make him state the **disqualifier gate** *before* naming any pattern —
    contiguous or not? · sorted / may I sort? · order or membership? · count vs best vs list-all?
    The gate interrogates the **problem**, so it cannot be contaminated by the previous question.
  - **Watch-tell:** any answer opening with *"here also…"* / *"this is the same as…"*, or that names
    a tool before restating what's being returned. When I hear it — stop and ask for the gate.

- **📌 COMPLEXITY IS ANSWERED FLUENTLY AND WRONGLY — and the fluency is what hides it (2026-08-10).**
  Wrong on 6 of 9 gauntlet questions, always delivered fast and confidently, never flagged by him as
  uncertain. He is **pattern-matching the bound to a shape he's seen** (`O(n log n)` appeared on a
  problem containing neither a sort nor a halving) rather than counting the work in his own
  algorithm. **The damage isn't the wrong number — it's that a wrong bound HIDES THE BOTTLENECK**:
  on Q3 he quoted his brute as O(n), so from where he stood there was nothing left to optimize and
  the monotonic stack became structurally unreachable. **Teaching move: never accept a bare bound —
  make him name WHICH LINE produces each factor** ("for each of n days I walk back up to n steps ⇒
  n²"). Per-item cost × number of items = total. (→ M#13)

- **✅ ONE PROBE IS OFTEN ENOUGH — his repair capacity is fully intact even when first instinct
  fails (2026-08-10).** Q9: he'd claimed O(1) space tracking a window's max/min. One question —
  *"you dropped the element that WAS the max; how do you get the new max?"* — and he answered
  *"well well thats a huge problem i didnt see comming"* and **immediately designed a correct
  ordered-multiset fix from nothing**. Q6 he self-corrected with **no** prompt at all. Read this as
  the load-bearing good news of the whole run: **routing is unguarded, but everything downstream of
  a correct route still works.** Repairing a gate is far cheaper than relearning nine patterns —
  say so to him plainly, because the calibration leak will otherwise read three ❌ in a row as
  "I've lost everything."

- **⚠️ A BANKED CUE THAT ONLY FIRES ON-TOPIC IS NOT BANKED (2026-08-10).** The subarray-vs-subsequence
  distinction was caught, corrected, and written into `PATTERN_JOURNAL.md` in his own words on
  7/14 — and it **did not fire** on Q6 four weeks later. Writing a cue down proves he understood it
  *that day*; it does not install it. **Implication for how I use the journal: cues need cold
  interleaved re-firing, not re-reading.** Part C is the right instrument for exactly this.

- **⭐ CROSS-PATTERN PRINCIPLE TRANSFER works, and fast (2026-06-22).** Taught "derive state, don't
  maintain it" on a sliding window (P23), and within the same hour he *spontaneously* applied it to
  BINARY SEARCH (P24 — deleted the `ans` he was maintaining, let the converging pointers hold the
  answer). When a lesson is framed as a **principle with a one-line handle** ("one driver, one
  invariant, derive the rest") rather than a problem-specific fix, it generalizes for him. Prefer
  teaching the portable rule + a memorable phrase over the local patch.

- **Self-trap-calling is emerging (2026-06-22).** He flagged BOTH his own traps unprompted: "this
  optimal is over-engineered" (P23) and "this brute is too easy = I'm dodging the rep" (P24). Lean
  into this — when he names a smell, make HIM articulate the fix before I do; he's often 80% there.

## TRACE-FIRST reconfirmed as the #1 unlock (2026-06-22)
P23 reading miss (summed type-values) AND P24 boundary bug (`r=mid-1` drops the min) were BOTH caught
by handing him a hostile concrete input to trace himself (`[2,2,2]→6-from-3-trees`; `[3,1,2]→returns 3`),
not by prose. Keep leading with the breaking input. Prose-for-structure still slides off.

- **Reduction trap: drops the constraint when simplifying a problem.** P19 (2026-06-19 AND
  again 2026-06-20): twice reduced "remove subarray so leftover `% p == 0`" down to the cleaner
  "subarray sum `== target`" / "equal residues" — silently dropping the **mod**. It's the pull
  toward the *prettier, already-known* shape (LC560, LC974/target-0). Tell: he reaches for a
  pattern he's solved before and the new constraint quietly vanishes. **What fixed it both times:**
  a HOSTILE concrete input (element `> p`, `[8,1,2,7] p=7`) that he traces through BOTH the original
  and his reduction — the disagreement is undeniable and he climbs out himself. Don't argue the
  reduction in prose; hand him the breaking input. (This is the counterexample-trace strength again.)

- **CONFIRMED (2026-06-20): concrete counterexample-trace is his #1 unlock, twice over.** Both P19
  catches (whole-array fake-winner, and the equal-residue reduction) were resolved by making him
  hand-run a specific input, not by explanation. Prose explanations of WHY (`+p` wrap, seed type)
  landed only *after* / alongside a concrete number or clock-walk. Lead with the trace, always.

- **Abstraction → code gap.** He can state an insight verbally ("count subarrays with
  same k but different l") yet not translate it into the right variable/loop. Bridge
  the gap with a concrete trace of *what the variable holds at each step*, not more
  prose.

- **GROWTH (2026-06-16, P14):** this time he *replaced the broken frame himself* — after
  hitting the shrink-on-equal wall he asked "help me strengthen the *identification* so I
  can do this class of problem in future," not "help me patch my code." Then derived the
  WHY unaided: "a window only works on a yes/no (monotonic) condition; exactly-k has a
  third state (`<`, `>`, `=`) so it can't be pushed into a window." That's the
  patches-symptoms shape *self-corrected*. Naming the failure-as-structural (not as a bug)
  is what flipped him from patching to reframing — keep doing that.

---

- **GROWTH (2026-06-20, P21): the 3-bucket edge framework is becoming a REFLEX.** He asked "what are the 3 buckets?" mid-P20, and ~an hour later on P21 he ran SHAPE/VALUE/ANSWER **unprompted** at Gate A. The scaffold is converting to habit fast. Keep naming frameworks explicitly — he internalizes named checklists quickly once they're his.
- **CONFIRMED AGAIN (2026-06-20): lead-with-the-trace is the #1 unlock, now 4×.** P20 TLE (handed `[1,1,1,1,2,3,4]` → he found the duplicate-walk himself), P21 brute OOB (`[1,2,1]` i=0 → he found `nums[-1]`), the slope-discard intuition. Prose-for-structure still slides; a hostile input he hand-runs lands every time.
- **⚠️ MOTIVATION/IDENTITY LEAK — he measures himself by the WRONG scoreboard (3× in ONE day, 2026-06-20).** (1) P20: "embarrassing I couldn't solve this" (a famous Medium that baits everyone). (2) Contest zero: "I can't even solve 1 problem" (16 days in, contests pull from the whole 24-module map). (3) "there's so much left." TELL: he benchmarks day-16-himself against the hardest possible yardstick and ignores the evidence of progress. **FIX THAT WORKS:** name the wrong-scoreboard explicitly + show concrete same-day receipts (5/6 recognition, sort-complexity fixed, reflex firing). He responds to *specific evidence*, not generic reassurance. Watch for this dip after any hard/contest session and pre-empt it.
- **THE "TWO" WORD-COLLISION (2026-06-20) — his reflexes can be triggered by SURFACE WORDS, not structure.** He diagnosed it himself: "2 sum means I just directly go to 2 pointer, I don't know why." "**Two** Sum" ↔ "**Two** Pointers" share the word → keyword match overrides the sorted-gate. Likely generalizes: watch for other name/keyword → wrong-tool reflexes. Re-anchoring by separating the WORD from the TECHNIQUE landed.
- **COACHING NOTE ON MYSELF (2026-06-20): I over-revealed on P21** — asked the recognition question "what algorithm is this?" then answered "binary search" myself two words later. He called it out (his standing pattern — he WILL catch over-reveal). The recognition rep (him naming the pattern cold) is the highest-value rep; do NOT steal it. **Rule: after asking a recognition question, STOP and wait for his answer — full stop.**
- **OVER-REVEAL #2 (2026-06-22) — same mistake, new shape.** He asked me to *re-teach monotonic-stack THEORY* (decayed over ~12d). I taught it via a full worked TRACE of Daily Temperatures — the exact problem he was about to solve. He called it instantly: *"you explained the solution, I wanted theory."* **LESSON: when re-teaching a pattern he's about to apply, teach it ABSTRACTLY (template + the 4 variants + the trigger) on a NEUTRAL/generic example — never trace the live problem.** Lead-with-the-trace is for when HE'S STUCK on HIS own attempt, not for concept revision. Two different modes; don't confuse them.
- **MODALITY-SWITCH WIN (2026-06-22, LC20):** the "trace your code on `()`" hint did NOT land first try — he reasoned the *concept* ("`)` matches `(`") instead of evaluating the literal char compare. SWITCHED modality to a blunt grounded confrontation: *"is `)` the same keyboard symbol as `(`? then `')' != '('` is TRUE → your code returns false on `()`."* THAT landed. Confirms: when he reads symbols semantically, force him to evaluate the literal machine-level value.
- **GATE A KEEPS CATCHING READING MISSES (2026-06-22):** on Daily Temps he restated "find the POS of warmer day" and his dry run wrote the index (2) not the wait-distance (1). The restate-in-exact-units step caught it before any code. His Gate-A discipline is the highest-ROI 30 seconds he spends.
- **OVER-REVEAL CORRECTED (2026-06-23) — held the line this time.** He again asked to re-learn monotonic stack. Lesson from 6/22 applied: taught it **abstractly on a NEUTRAL example (generic Next-Greater on `[3,1,2,5,4]`), kept the live Daily Temperatures completely sealed**, and even scaffolded the warm-up as generic NGE so the real problem stays his to map solo. **It worked** — he rebuilt the concept and now owns it, and Daily Temps is still a clean rep. CONFIRMS the two-modes rule: trace-first is for when HE'S stuck on HIS attempt; concept revision = abstract template + trigger on a neutral example.
- **CLOSED-BOOK-FIRST nails the diagnosis (2026-06-23).** Opening a "re-learn X" request with closed-book recall (instead of lecturing) surfaced the exact gap in seconds: trigger intact, WHY/mechanism decayed. Don't lecture a re-learn — pull first, then repair only the holes. Highest-ROI opening move for any revision.
- **🆕 PREMATURE "DONE" — fixes 1 of N, declares finished (2026-06-23, fired 4× across the day).** Morning (NGE): fixed `if`→`while`, said "done," 2 bugs still live. Evening it fired **3 more times on Daily Temps**: fixed the brute and asked "check"; fixed the optimal's subtraction but left the inverted comparison; each "is it ok?" came after fixing exactly ONE of two live bugs. **It's a near-compulsive loop: fix one thing → reach for external validation ("check now")** instead of self-verifying. **FIX THAT WORKS (confirmed twice):** refuse to be the checker — make him **trace his OWN current code on a hostile input** (`[72,71,76]` where position≠distance, or `[3,1,2,5,4]`) and read the output aloud; the still-live bug surfaces itself. His trace-strength, aimed inward, is the antidote. **GROWTH SIGNAL (real):** on the NGE optimal he found BOTH remaining bugs by tracing his own code with only a pointer at where to look — the muscle is forming. Name the tell to him directly: *"that feeling of wanting to ask 'is it ok' IS the cue to trace it yourself first."* He's starting to feel the pull, which is step one.
- **EXECUTION lag is real even when understanding is solid (2026-06-23).** He hand-traced the batch-resolve perfectly, then wrote `if` not `while`; he agreed "stack holds index," then pushed the value. Understanding → clean-code is a SEPARATE rep for him — the concept landing does NOT mean the code will be clean. The warm-up (code the generic engine before the real problem) is the right bridge; keep using it.
- **TAP-OUT IS CLEAN, NOT A QUIT (2026-06-22):** after the AC + a dense theory re-teach he said "I can't consume right now, teach in the morning." Honored immediately, no push. He self-regulates fatigue well — when he says the tank's empty, it IS; queue it and stop. (Same as 2026-06-19.)
- **⭐ PREMATURE-"DONE" ANTIDOTE IS LANDING (2026-06-25).** The "check now" reflex still fired twice (Min Stack, 132), but each time I **refused to be the checker and handed him the input → he self-traced and found his OWN boundary bug** (empty-container both times). On Min Stack he caught it BEFORE submit → first judge submit clean. The refuse-to-check move is converting the reflex into a self-catch. Keep refusing; the goal is he traces before I have to refuse.
- **🆕 HE NAMED HIS OWN BOTTLENECK: "careful reading / understanding the question fully" (2026-06-25).** He asked: *"should I grind random easy LC problems till it clicks?"* **The prescription that landed: NO — volume just practices the sloppy-reading habit faster; the fix is the non-skippable Gate-A ritual (restate in EXACT units + write the catch + a 3-elem HOSTILE dry-run), and "careful reading IS the first move of solving, not a separate skill you drill on the side."** He took it. Also reframed: easy problems have *gentle* examples that HIDE bugs (distance==index on Daily Temps) → easies build false confidence, not careful reading. Tie his reading leak to *reading his own code* too (same slow-trace muscle). Watch whether the ritual-not-volume frame sticks.
- **🆕 FRICTION-AS-SIGNAL is a NEW recognition strength (2026-06-25, LC219 interleaved trap).** On a hashing problem planted in the *stacks* folder, he *felt the wrong tool fighting him* ("the easy way is hashing but how do I do it in stacks?") and **scrapped the stack himself.** That discomfort = his brain correctly rejecting the tool. Name it for him as a skill: *the friction when a tool doesn't fit IS the signal to switch tools* — it's the same instinct an interview tests (nobody labels the pattern for you). Reinforce it; it's the flip side of the #9 word-collision leak (rejecting wrong tools, not just naming right ones).
- **IDENTITY LEAK FIRED AGAIN (2026-06-25, Gate 6) — and recalibration with receipts still works.** He labeled an AC'd MEDIUM (Min Stack) "worst... I can't do it" — *after he'd already solved it.* Same wrong-scoreboard as 6/20. **Fix that worked again:** quote his own words back, show the same-session receipt (judge-green + he caught the boundary bug himself), and name it: "your *solving* is fine, your *narration* is the leak — you finish the rep then tell yourself you failed." He responds to specific receipts, not generic reassurance. Pre-empt this after every hard rep.
- **🆕 WORKFLOW FACT — HE ONLY RUNS CODE ON LEETCODE, NEVER LOCALLY (2026-07-06, his explicit words: "i would never run the file in pc i will only run code in LC").** When he reports "wrong answer," the evidence is an LC verdict (WA/TLE/Runtime Error on LC's testcases) — NOT the local harness. Do NOT diagnose via local compile/binary/harness mechanics; he never touches them, and doing so reads as noise and cost trust today (he was asking about LOGIC, I answered about stale binaries). First move on any "wrong ans": ask which LC verdict + which testcase, or reason about LC's hostile cases (INT_MIN, max-n). The in-file stress harness is MY verification tool, not his workflow.
- **COACHING NOTE ON MYSELF (2026-06-25): I OVER-REVEALED on the HARD problem (132 Pattern)** — gave the full track-best-2 right-to-left engine (L3/L4) when he was owed a one-nudge. He called it out (as always). **PATTERN forming across 6/20, 6/22, 6/25: my over-reveals cluster on the HARDER problems** — when he's genuinely stuck on a hard, I reach for too much rather than sitting in the struggle with him. **RULE: on hard problems, hold the line TIGHTER, not looser** — give an L2 observation (name the role to fix) and STOP; let the struggle run longer. Logged the 132 re-derive re-test to recover the stolen recognition rep.
- **🆕 EMIT-ORDER > DIAGRAM for tree/recursion checks over chat (2026-07-09, M10 open).** Asked him to trace the subsets tree; he pushed back — *"how am I supposed to give you the whole binary tree from terminal?"* (voice mode, fair point). The fix that landed INSTANTLY: don't ask for the STRUCTURE, ask for the OUTPUT it emits — "type the 8 subsets in the order the base case fires." 8 lines, zero drawing, and the ORDER proves the tree (he nailed exact pick-first DFS order). Generalize: for any recursion/tree concept-check in this medium, ask for the emit/visit ORDER, never the diagram.
- **🆕 DORMANT PRIOR KNOWLEDGE IS REAL — probe before teaching from zero (2026-07-09).** One fib-fork nudge ("per element, what are its 2 choices?") surfaced a 3-year-old Striver seed: he named pick/not-pick + push-at-base-case + pick-first order unaided. The M10 open cost ~2 exchanges instead of a lecture. Standing move on every new module: probe what he already half-knows FIRST (he had years of scattered exposure pre-Kira); teach only into the actual gaps.

## What "he really gets it" sounds like
- Genuine: he restates the mechanism in his *own* concrete terms and predicts a result
  ("it comes 1 because it never goes > k"). That's transfer.
- Faking/surface: "ok" / "got it" with no restatement → DON'T trust it; ask him to
  produce the value or trace before moving on.

---

### ⭐ 2026-08-09 — ABSTRACT STATEMENTS DON'T GRIP; NUMBERS DO (confirmed twice in 20 minutes)
On the comeback recognition test, he stalled on **two consecutive questions at the statement layer,
before recognition ever got a chance to fire**:
- Q4 (window): read *"longest substring of one single repeated letter"* + *"change at most k chars"*
  as a **contradiction** and refused to start. One clarification + one concrete example
  (`"AABABBA", k=1 → 4`) and he produced the **complete correct machine instantly** — expand,
  track maxFreq, shrink on `windowLen − maxFreq > k`, O(n)/O(1). Zero hesitation.
- Q5 (coin change): called a completely standard statement *"so vague"*. Same shape.

**The lesson: a stall is not always a recognition failure — triage WHICH layer stalled.**
Reading-layer stall ⇒ hand him a concrete instance (this is trace-first applied to the *statement*,
not the algorithm). Recognition-layer stall ⇒ that's the real miss, log it. Scoring these the same
would have understated his recognition and wasted repair time on patterns he still owns.
**Standing move: seed EVERY abstract statement with 2–3 concrete input→output lines up front.**
Costs nothing, removes a whole failure mode. (Consistent with his #10 reading-miss leak and with
TRACE-FIRST being his #1 unlock — it applies one layer earlier than I'd been applying it.)

### ⭐ 2026-08-09 — HE NARRATES DEFEAT WHILE PRODUCING THE RIGHT ANSWER
Q1 (4-array sum): he wrote *"I don't really know this pattern... I'm off course by a long way"*
**in the same message** where he derived the correct hashing solution from brute force. He was
missing the **word**, not the tool — and could not tell the difference. This is the calibration
leak (Gate 6) in its purest form yet.
**Move that works:** don't reassure — **quote his own answer back to him** and name what's actually
missing ("you have the tool, you're missing the label"), then produce a same-day receipt (here: the
#9 sort-then-two-pointers reflex did NOT fire on an unsorted pair-sum). Evidence beats encouragement.

### ⛔ 2026-08-09 — KIRA SELF-LEAK: DON'T REVEAL PATTERN NAMES MID-DRILL
I named the pattern after Q1 and Q2 before catching myself. Several later questions in the same
gauntlet sit in adjacent families (plain stack vs monotonic stack vs monotonic deque; window vs
prefix+hash). A name handed over on Q2 primes Q9/Q12/Q20 and **contaminates the measurement** the
whole test exists to produce. **Rule: during a TEST-mode drill, give the MARK only; reveal every
pattern name after the last question.**

---

## Pacing / dose
- Keep to **≤1 hint then stop** (his explicit preference; he calls out over-reveal).
- But **close the loop**: check the one hint landed before letting him grind, and if
  his next attempt shows it didn't, **switch modality** — do not repeat the same hint.

### ⛔ 2026-07-14 — TRIAGE THE BUG BEFORE CHOOSING THE MODE (he called this out, hard)
Not every bug earns a Socratic dance. Classify first:
- **Compiler-catchable** (syntax, missing `;`, wrong overload, `next_permutation(nums)`
  vs iterators) → **JUST TELL HIM.** The compiler names it in 5 seconds. Making him hunt
  teaches nothing and burns his goodwill. He *will* call it out: *"see it's just a cpp
  issue and you tried making me guess for all of that."*
- **Silent / conceptual** (compiles clean, test even passes, still wrong — e.g. `vector<int>&`
  oracle mutating the caller's array that the function-under-test is about to read) → **DIG.**
  No compiler will ever surface it; this is the class worth his time.
Rule: **the Socratic budget is for bugs a tool can't find.** Spend it there, nowhere else.

### ⛔ 2026-07-14 — ANSWER THE QUESTION HE ACTUALLY ASKED
He said *"I couldn't find how to use pick/not-pick **here**"* — i.e. "I know the tool, I
couldn't fit it to permutations." I heard "I don't understand pick/not-pick" and spent 3
turns re-teaching LC78's tree. He got lost (*"wait what are we even doing kira"*) and then
corrected me flatly: *"it's not that I don't know how to pick or not pick."*
**Lesson:** when he reports a *stuck*, parse the precise scope of it. Don't downgrade his
level. Re-teaching something he owns reads as condescension and derails the session.
The real answer was one line: *pick/not-pick can't do permutations at all — wrong tool,
stop searching.* Should have led with that, not a remedial trace.

---

## Open hypotheses to test
- Does a **scaffold** (skeleton with the key holes blank) beat prose for structural
  rewrites? (Strongly suspected yes.)
- Does **grounded abstraction** (abstract var ↔ concrete value) reliably bridge his
  abstraction→code gap?
- Is he faster the *first* time he traces a counterexample himself vs being handed the
  trace? (Prefer making him trace.)
