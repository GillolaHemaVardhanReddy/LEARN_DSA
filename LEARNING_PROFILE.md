# LEARNING_PROFILE.md — How Hema Vardhan Learns (Kera's model)

> Kera's running hypothesis log about *how* Hema Vardhan learns — which hint
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

- **Abstraction → code gap.** He can state an insight verbally ("count subarrays with
  same k but different l") yet not translate it into the right variable/loop. Bridge
  the gap with a concrete trace of *what the variable holds at each step*, not more
  prose.

---

## What "he really gets it" sounds like
- Genuine: he restates the mechanism in his *own* concrete terms and predicts a result
  ("it comes 1 because it never goes > k"). That's transfer.
- Faking/surface: "ok" / "got it" with no restatement → DON'T trust it; ask him to
  produce the value or trace before moving on.

---

## Pacing / dose
- Keep to **≤1 hint then stop** (his explicit preference; he calls out over-reveal).
- But **close the loop**: check the one hint landed before letting him grind, and if
  his next attempt shows it didn't, **switch modality** — do not repeat the same hint.

---

## Open hypotheses to test
- Does a **scaffold** (skeleton with the key holes blank) beat prose for structural
  rewrites? (Strongly suspected yes.)
- Does **grounded abstraction** (abstract var ↔ concrete value) reliably bridge his
  abstraction→code gap?
- Is he faster the *first* time he traces a counterexample himself vs being handed the
  trace? (Prefer making him trace.)
