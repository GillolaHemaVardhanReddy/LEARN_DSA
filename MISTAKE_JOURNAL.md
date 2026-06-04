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
Status: Open

---

## Recurring-mistake watchlist
> When the same root cause appears 2+ times, it graduates here and becomes a
> standing pre-submit checklist item until it stops recurring.

| Pattern of error | Times seen | Standing rule | Last occurrence |
|---|---|---|---|
| **Logic right, boundary/sentinel/ORDER value wrong** (prefix L-1; min-init+return; off-by-one `right-left+1`; step order include→restore→record) | **3** | Run the pre-code boundary checklist below BEFORE coding. This is the #1 leak. | 2026-06-04 (LC1004) |
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
      only when the window is guaranteed valid.
