# MISTAKE_JOURNAL.md — Error Eradication for Hema Vardhan

> Mistakes are the highest-signal data you have. The goal isn't to feel bad — it's
> to find the **root cause** and schedule a **re-test** so the same error can't
> survive. Every entry gets a re-attempt date that also goes into `REVISION_QUEUE.md`.

Mistake types: Logic · Complexity · Edge case · Pattern-recognition · Concept-
misunderstanding · Implementation/syntax.

---

## Entry template
```
### [#id] <short title>
Date:
Module / Pattern:
Problem:
Type:
What I did (the wrong move):
Root cause (the real reason — not "careless"; what mental model was off?):
Correct understanding:
Prevention rule (a checklist item I'll apply next time):
Re-test problem (similar, unseen):
Re-attempt on:  (date — also in REVISION_QUEUE.md)
Status: Open / Re-tested-pass / Re-tested-fail
```

---

## Entries
> Newest first. Keep them short and honest.

### [#10] Skipped "restate the problem" → two MISreads under drill pressure
Date: 2026-06-13
Module / Pattern: Process (problem-solving loop step 1) — surfaced on M6 search-on-answer (Q4) + binary-search-on-answer combo (Q6)
Problem: hard interleaved drill — Q4 (max-min router gap) read as "find min difference / avoid consecutive"; Q6 (k-th smallest pairwise distance) read TWICE as "find the minimum distance".
Type: Concept-misunderstanding / comprehension
What I did (the wrong move): jumped straight to pattern-hunting on the surface words ("distance", "pair", "min") without first restating what the problem actually asks. Q4: collapsed "maximize the minimum gap" into "find the min gap." Q6: collapsed "k-th smallest distance" into "the smallest distance" — even after a correction, repeated the same misread.
Root cause: under drill/time pressure, step 1 of the loop (restate + tiny dry run) gets skipped. The pattern vocabulary is strong enough that it fires on keywords before comprehension finishes — so a misread problem gets a confidently-wrong pattern. Both misses were READING failures, not tool failures: once the statement was pinned down (via a 3-element dry run), the right pattern (binary-search-on-answer) came quickly.
Correct understanding: ALWAYS restate the problem in one plain sentence + run a 3-element dry run BEFORE naming a pattern. For Q4 "largest possible minimum gap" and Q6 "k-th smallest among all pairwise distances," a tiny example (e.g. [1,3,7], k=2 → distances {2,4,6} → 4) instantly exposes the real ask.
Prevention rule: **Before pattern-hunting, write/say: (1) one-sentence restatement, (2) the answer on a 3-5 element example by hand.** If I can't produce both, I don't understand the problem yet — no pattern call allowed.
Re-test problem (similar, unseen): next drill — a wordy/disguised statement (esp. a min/max-of-something or k-th-something) restated correctly on the FIRST read with a dry run, before naming a tool.
Re-attempt on: 2026-06-14 (next drill)
Status: Open

### [#9] Unsorted-pair FIRST instinct still reaches for two pointers (recovers, but isn't reflexive)
Date: 2026-06-10
Module / Pattern: M2 Hashing ↔ M3 Two Pointers discrimination (drill Q1)
Problem: `/drill` Q1 — unsorted array, return indices of a pair summing to target
Type: Pattern-recognition
What I did (the wrong move): led with "sort + two pointers (or binary search), O(n)/O(log n)", THEN hedged to a hash map. The pattern was eventually right but the FIRST move was the over-application — and the sort idea is doubly wrong here (O(n log n), and sorting destroys the original indices the problem asks for). Also claimed an impossible O(log n) (must read every element → O(n) floor).
Root cause: the disqualifier check isn't automatic. "Two pointers" fires on "find a pair" by surface feature, before checking the gate "is the data SORTED? would sorting lose indices?". Twin failure: hashing under-fires while two-pointers over-fires — same coin.
Correct understanding: unsorted + find a pair (esp. return INDICES) → **one-pass hash map** value→index, look up `target-x`, O(n). Two pointers earns the call ONLY when the data is already sorted.
Prevention rule: before saying "two pointers," run the gate OUT LOUD — "Is it sorted? No → two pointers is OFF the table → hashing." Make the disqualifier the first thought, not the recovery.
Re-test problem (similar, unseen): next `/drill` — an unsorted pair/complement question named HASHING on the first instinct, no two-pointers detour. Earns Hashing + Two-Pointers L5 together.
Re-attempt on: 2026-06-14 (next interleaved drill)
Status: **RE-TESTED FAIL ×2 (2026-06-13)** — (a) hard drill Q1, then (b) Drill-1 P1 (Two Sum): AGAIN sorted first + reached for two pointers. 4th occurrence. NEW wrinkle: also misread the complexity — saw value magnitude `1e9` and hunted for O(log n)/sub-linear, not registering that n≤1e4 and that finding a pair has an O(n) FLOOR (must read every element). His two-pointer *completeness* worry ("might miss low+1..high") was actually unfounded (converging 2ptr on sorted misses nothing — taught him the invariant proof). The true disqualifier he keeps missing: Two Sum returns INDICES → sorting destroys them → must be a one-pass hash map. Gate "is it sorted? does sorting cost me the indices? → hashing" still not firing first. Hashing + 2ptr stay L4. Re-coach the gate as the FIRST spoken thought every pair problem.

### [#8] Integer overflow — didn't reason the MAGNITUDE of the arithmetic (only indices)
Date: 2026-06-10
Module / Pattern: M6 Binary Search (LC875 Koko, search-on-answer)
Problem: LC875 Koko Eating Bananas — runtime crash `signed integer overflow: 1610612736 + 805306368 cannot be represented in type 'int'`
Type: Edge case / boundary-value (magnitude)
What I did (the wrong move): wrote `mid=(s+e)/2` with `s,e` as VALUES up to 1e9 → the SUM (2.4e9) overflows `int` before the `/2`. Also `int sum` for the feasibility accumulator Σceil(pile/k), which at k=1 = total bananas up to 1e13 — also overflows. Reasoned the index edges but never the SIZE of the numbers.
Root cause: my boundary checklist covered init values / off-by-one / sentinels / order — but had NO line for "how big can each `+`/`*`/accumulator get? does it fit the type?" The leak is the same family as the index bugs (an edge not reasoned up front), just on magnitude instead of position.
Correct understanding: `mid=lo+(hi-lo)/2` keeps every intermediate ≤ hi (≤1e9, fits int). Accumulators that can exceed ~2.1e9 must be `long long` (and so must the function's RETURN type). int ≈ ±2.1e9; long long ≈ ±9.2e18.
Prevention rule: **NEW checklist line — for every `+`, `*`, and running accumulator, ask "what's the max value, and does it fit `int`?" If it can pass ~2e9 → `long long`. Always use `mid=lo+(hi-lo)/2`.**
Re-test problem (similar, unseen): a future search-on-answer (LC1011 Capacity to Ship / LC410 Split Array) — set the value range + a long-long accumulator correctly on the FIRST write, no overflow crash.
Re-attempt on: 2026-06-12 (next search-on-answer problem)
Status: **RE-TESTED FAIL (2026-06-13, drill1 P3 Sqrt(x))** — brute force `if(i*i > x)` with `i` an int: at x≈INT_MAX, `i*i` (≈2.15e9) overflows int BEFORE the comparison → "signed integer overflow." Same root cause (magnitude not reasoned up front), now on a `*` instead of a `+`. Fix = `(long long)i*i`. The magnitude checklist line is NOT yet a reflex. ALSO recurred: nested-function structure bug (defined mySqrt inside main instead of in the Solution class — same as 6/10). Keep #8 OPEN; clears on a first-write-clean overflow-prone problem.

### [#7] Reactive debugging — band-aid `if(s==e)` patches instead of reasoning edges up front
Date: 2026-06-09
Module / Pattern: M6 Binary Search (LC704, LC35) — but cross-cutting
Type: Process / boundary-execution
What I did (the wrong move): submit → see ONE failing test case → bolt on a special-case patch (`if(s==e){...}`) for exactly that case → resubmit. Repeated every problem. Also wrote `return mid;` at the end (luck-dependent; garbage on empty array). Recognition was fine; the loop was "patch the symptom the judge showed me."
Root cause: not trusting the clean template (which handles single/empty/insert-at-end BY DESIGN), and reasoning edges only AFTER the judge fails, never before. The patches are band-aids that make the code fragile.
Correct understanding: the clean templates (exact search; store-candidate lower bound) need ZERO special cases — single element, empty, target<all/>all all fall out of the standard loop. Return the stored `ans`, never a stray `mid`.
Prevention rule: **BEFORE submitting, trace the 4 edges myself** — single element (present/absent), empty, target < all / > all (insert 0 / n), target at first/last index. No `if(s==e)` patches. Trust the template. (In Notes/00 boundary framework + Notes/06.)
Re-test problem: LC34 First/Last + LC875 Koko (tomorrow) — solve with the clean template, edges reasoned up front, ZERO special-case patches, first-submit AC.
Re-attempt on: 2026-06-10 (BS mediums)
Status: **RE-TESTED PARTIAL (2026-06-10)** — LC34 + LC875 AC, no `if(s==e)` band-aids this time (template trusted ✅). BUT Koko still needed a debug cycle on the overflow (a *different* edge — magnitude, see #8), not first-submit-clean. The band-aid reflex looks fixed; the "reason ALL edges up front" discipline isn't fully there. Keep on watchlist; clears on a first-submit-clean medium.

### [#6] Defaulted HASHING problems to "two pointers"; SW over-fired on a transformed array
Date: 2026-06-08
Module / Pattern: M2 Hashing recognition (drill) · M4/M5 discrimination
Problem: `/drill` mixed set — Q3 (unsorted Two Sum), Q6 (longest equal 0/1), Q7 (duplicate within k). Scored 4/7.
Type: Pattern-recognition
What I did (the wrong move): (a) **Q3** unsorted Two Sum → said "two pointers (didn't complete yet)". (b) **Q7** "duplicate value within index distance k" → said "two pointers" again. (c) **Q6** longest equal-0s/1s → got the 0→−1 transform but classified it as **sliding window**.
Root cause: No formal hashing recognition map yet (M2 still L2), so every pair/duplicate/complement problem gets parked under "two pointers." AND sliding window over-fires onto transformed arrays — once 0→−1 introduces negatives, a window can't decide when to shrink, so it MUST be prefix+hash, not SW.
Correct understanding: **Two pointers requires SORTED / monotonic structure.** Unsorted + pair/complement/duplicate → **HASHING** (Q3 = complement map storing value→index; Q7 = last-seen index map, check `i - last ≤ k`). **Negatives or a ±1 transform kill sliding window → prefix sum + hash** (Q6 = transform 0→−1, first-index map, `seen[0]=-1`, longest run with prefix repeat).
Prevention rule: Before saying "two pointers," ask **"is the data sorted/monotonic?"** If no → hashing. Before saying "sliding window," ask **"can values be negative (or did I transform to ±1)?"** If yes → prefix+hash.
Re-test problem (similar, unseen): LC1 Two Sum (after hashing lesson), LC219 Contains Duplicate II, LC525 cold (already owed), + a fresh `/drill` post-hashing.
Re-attempt on: 2026-06-11 (after M2 Hashing formal lesson)
Status: **RE-TESTED MOSTLY-CLEARED (2026-06-10 drill, 6/7)** — Q7 (dup within k) named cold as hashing ✅ (the exact 6/08 miss, now correct). Q1 (unsorted Two Sum): recognition RECOVERED to the hash map, but the FIRST instinct still reached for "sort + two pointers." So: hashing recognition restored; the residual is the unsorted-pair *first-instinct* (logged fresh as #9). Down from 0/2 hashing → effectively 1.5/2.

### [#5] `if(map[key])` truthiness trap + overwriting the first index
Date: 2026-06-07
Module / Pattern: M5 Prefix Sum + Hash
Problem: LC523 Continuous Subarray Sum (test 97 / [23,0,0])
Type: Logic / boundary-value
What I did (the wrong move): (a) checked map presence with `if(seen[rem])` — but a stored index of **0** is falsy, so a remainder first seen at index 0 looked "absent." (b) Used `seen[rem]=i+1` then compared `i-seen[rem]>=2` → off-by-one (required length ≥3, missed length-2 subarrays). (c) Wrote the index EVERY iteration → overwrote the earliest occurrence, shrinking every gap.
Root cause: `operator[]` can't distinguish "absent" from "value is 0/false"; and for LONGEST/length problems you must keep the FIRST index (earliest = largest gap), never overwrite.
Correct understanding: use `.count()`/`.find()` for presence (so index 0 is valid); store the real index; store ONLY on first occurrence (`else` branch); compare `i - seen[rem] >= 2`.
Prevention rule: **`if(map[key])` is poison for indices.** Presence → `.count()`. Write-once → `else`. For "longest" keep the earliest index.
Re-test problem: re-solve LC523 cold in a week; also LC525 (first-index pattern).
Re-attempt on: 2026-06-14
Status: Open (LC523 AC'd 6/7 after coaching, but the bugs were heavy → re-test cold)

### [#4] Treated target SUM `k` as a window LENGTH
Date: 2026-06-05
Module / Pattern: M5 Prefix Sum
Problem: LC560 Subarray Sum Equals K (design phase)
Type: Pattern-recognition / Concept-misunderstanding
What I did (the wrong move): Tried to use a fixed-length window `i .. i+k-1` and `prefix[i+k-1]-prefix[i]`, treating `k` (a target sum) as a length. Yesterday's fixed-window pattern over-fired.
Root cause: Surface-feature anchoring on "k" → "window of size k" from M4, without re-reading what k MEANS in this problem.
Correct understanding: `k` is a TARGET SUM; subarray length is free. Never write `i+k-1` for a sum target.
Prevention rule: Before coding, state in words what each input MEANS. If "k" is a sum, there is no length window.
Re-test problem: a future "subarray sum = k" variant solved without reaching for a length window.
Re-attempt on: next prefix/hash problem (LC930/LC1248 in day-01).
Status: Open

### [#3] Confused "count ALL subarrays" with "find ONE shortest/longest window"
Date: 2026-06-05
Module / Pattern: M5 Prefix Sum
Problem: LC560 Subarray Sum Equals K (design phase)
Type: Concept-misunderstanding
What I did (the wrong move): When a running prefix repeated, wanted to "pick the nearest occurrence (shortest)" — applying min/max-window thinking to a COUNTING problem.
Root cause: Two paradigms blurred: window problems optimize ONE answer; counting problems TALLY every match.
Correct understanding: For "count subarrays with property", every earlier matching prefix is its own valid subarray → `count += seen[key]`, never pick one.
Prevention rule: First classify the GOAL — count / longest / shortest / exists — that decides the whole shape (tally vs max vs min vs boolean).
Re-test problem: LC1248 Count Nice Subarrays (day-01).
Re-attempt on: day-01 practice.
Status: Open

### [#2] Minimum-tracker initialized so it can never update
Date: 2026-06-04
Module / Pattern: M4 Sliding Window (Variable)
Problem: LC 209 Minimum Size Subarray Sum
Type: Edge case / boundary-value
What I did (the wrong move): For a MIN hunt, init `ans = 0` and update with `if(len < ans)`. Since lengths are positive, `len < 0` is never true → `ans` never updated, returned 0 always. After fixing init, forgot the "no valid window → return 0" case and returned the sentinel (105).
Root cause: Logic was correct; the **boundary values** were wrong. A minimum tracker must start at +∞ (INT_MAX), and the "not found" sentinel must be converted back to 0 at return.
Correct understanding: `ans = INT_MAX`; update with `<`; `return ans == INT_MAX ? 0 : ans`.
Prevention rule: When tracking a min, ask two questions BEFORE coding: (1) what start value guarantees the first real candidate wins? (2) what do I return if nothing ever qualified?
Re-test problem (similar, unseen): LC 1004 Max Consecutive Ones III (longest variant — opposite init/return) — get the boundary values right cold.
Re-attempt on: 2026-06-06  (also in REVISION_QUEUE.md)
Status: RE-TESTED (LC1004, 6/4) — min-init not repeated ✅, BUT the boundary family **recurred**
(off-by-one `right-left+1` + step order). Weakness confirmed → kept active on the watchlist.

### [#1] Prefix-sum range formula recalled as shape, not meaning
Date: 2026-06-04
Module / Pattern: M5 Prefix Sum
Problem: Closed-book revision (transfer session)
Type: Concept-misunderstanding
What I did (the wrong move): Wrote `sum(L,R) = prefix[L] - prefix[R]` — wrong order AND wrong subtracted index. Test on [2,4,1,3,5] gave −4 for sum(1,3) (should be 8).
Root cause (the real reason): Recalled the formula by visual *shape* ("prefix minus prefix") instead of its *meaning*: prefix[R] = sum of everything up to R; subtract the part **before L**, which is prefix[L-1].
Correct understanding: `sum(L,R) = prefix[R] - prefix[L-1]`. L=0 → nothing before it → sum(0,R)=prefix[R]. (Or 1-index prefix with prefix[0]=0 to kill the special case.)
Prevention rule: Don't recall a formula by shape — re-derive it from "total up to R minus total before L," then sanity-test on a 3–5 element array before using it.
Re-test problem (similar, unseen): LC 724 Find Pivot Index (pure prefix-sum reasoning, no hashing) — derive the formula cold.
Re-attempt on: 2026-06-05  (also in REVISION_QUEUE.md)
Status: **RE-TESTED PASS (2026-06-05)** — derived `prefix[R]-prefix[L-1]` cold from meaning, handled L=0 (prefix[-1]=0), sanity-tested on [2,4,1,3,5]. Formula recall is now by meaning, not shape. CLEARED.

---

## Recurring-mistake watchlist
> When the same root cause appears 2+ times, it graduates here and becomes a
> standing pre-submit checklist item until it stops recurring.

| Pattern of error | Times seen | Standing rule | Last occurrence |
|---|---|---|---|
| **Logic right, boundary/sentinel/ORDER/INDEX value wrong** (prefix L-1; min-init+return; off-by-one `right-left+1` & `i+1`; `prefix[-1]`/`prefix[n]` OOB; forgot `seen[0]=-1`; `if(map[key])` index-0 trap; first-index overwrite; reverse-loop `i++`; LC567 missing `-'a'` ×2 + left-never-incremented; LC1 lookup-vs-insert ORDER; LC128 fwd-vs-bwd compare + loop `<size()-1` + empty-array) | **12** | Run the pre-code boundary checklist BEFORE coding. #1 leak — STILL the dominant failure mode. EVERY problem this session leaked here while the logic was right. Standing pre-submit Qs: does the loop touch FIRST & LAST element? empty input? consistent compare direction? lookup-before-insert? RE-RUN after any edit. | 2026-06-08 (LC1 order, LC128 ×3) |
| **Unsorted pair/duplicate/complement → FIRST instinct = "two pointers" instead of HASHING** | **4 (NOT improving on this sub-case)** | Before "two pointers," ask "is the data SORTED/monotonic?" If no → hashing. 6/13 drill Q1: unsorted-pair-sum STILL led with "sort + 2ptr." The dup-within-k sub-case is fixed, but the *unsorted pair-sum* sub-case keeps firing the sort reflex. Make the gate the FIRST spoken thought. See #9. | 2026-06-13 (drill Q1) |
| **Sliding window over-fires onto problems with negatives / ±1 transforms** | **1** | Before "sliding window," ask "can values be negative (or did I transform to ±1)?" If yes → prefix+hash. | 2026-06-08 (drill Q6) |
| **Reactive debugging — patch the failing test instead of reasoning edges up front** | **2ptr+BS** | Trace the edges BEFORE submit. No band-aid `if(s==e)` patches — trust the clean template. 6/10: band-aids GONE on LC34/875 ✅, but Koko still hit a debug cycle on overflow (an edge not reasoned up front). | 2026-06-10 (LC875 overflow) |
| **Integer OVERFLOW — type too small for the magnitude of `+`/`*`/accumulator** | **1** | For every add/multiply/accumulator ask "max value? fits int (±2.1e9)? else long long." Always `mid=lo+(hi-lo)/2`. (LC875: `(s+e)` and `int sum` of Σceil both overflowed.) | 2026-06-10 (LC875) |

---

## Pre-submit checklist (grows from the watchlist)
> Run this before declaring any solution "done."
- [ ] Did I test the empty / single-element / all-same / max-size input?
- [ ] Is my stated complexity actually what the code does?
- [ ] Did I name the pattern before coding, or did I jump in blind?
- [ ] **BOUNDARY CHECK (my #1 leak):** init values right? (min→INT_MAX, max→0/−∞) · length
      formula `right-left+1` (the +1!) · "not found" sentinel converted back at return · derive
      formulas by *meaning* not shape.
- [ ] **ORDER CHECK:** for windows, is it strictly include → restore-validity → record? Record
      only when the window is guaranteed valid. For hash maps: look up BEFORE inserting current.
- [ ] **CLASSIFY THE GOAL FIRST:** count / longest / shortest / exists? → tally (`count+=`) /
      max(first-index, `seen[0]=-1`) / min / boolean. This decides the whole shape.
- [ ] **MEANING OF EACH INPUT:** is `k` a sum, a length, a count? (don't write `i+k-1` for a sum.)
- [ ] **Prefix+hash pre-load:** COUNT → `seen[0]=1`. LONGEST(first-index) → `seen[0]=-1`. Negatives mod k → `((x%k)+k)%k`.
- [ ] **OVERFLOW / MAGNITUDE (new, MISTAKE #8):** for every `+`, `*`, and running accumulator, what's the MAX value? Fits `int` (±2.1e9)? If it can pass ~2e9 → `long long` (incl. the function's return type). Binary search: always `mid=lo+(hi-lo)/2`.
