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
| **Logic right, boundary/sentinel/ORDER/INDEX value wrong** (prefix L-1; min-init+return; off-by-one `right-left+1` & `i+1`; `prefix[-1]`/`prefix[n]` OOB; forgot `seen[0]=-1`; `if(map[key])` index-0 trap; first-index overwrite; reverse-loop `i++`) | **7** | Run the pre-code boundary checklist BEFORE coding. #1 leak — STILL recurring, BUT he now self-identifies them as index bugs (progress). | 2026-06-07 (LC238 loop dir, LC523 off-by-one + truthiness + overwrite) |
| (e.g. off-by-one in window shrink) | 0 | | — |
| (e.g. wrong complexity for recursion) | 0 | | — |

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
