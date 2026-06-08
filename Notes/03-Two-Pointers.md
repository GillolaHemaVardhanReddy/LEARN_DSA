# 👉👈 03 — Two Pointers — Study Notes

> ⚠️ **THEORY SEED (2026-06-08)** — written after Stage ① theory + ② Striver video, BEFORE
> problems. The "cues / gotchas / problems that taught me" sections get filled after reps
> (LC167, LC15, …), like the other notes. Terse cue → `PATTERN_JOURNAL.md`; classifier → `00`.

---

## What it is
Two indices walking an array — usually from **opposite ends toward each other**, sometimes
**same direction** (one chasing the other). Exploits **order/structure** to solve in **one
O(n) pass** what brute force does in O(n²).

## When to reach for it (cue)
> **SORTED** array + find a **pair/triple by sum or diff** · compare from **both ends** ·
> **partition / rearrange** in place · (later) fast/slow on a sequence.
>
> **GATE — your big discrimination:** **SORTED → two pointers · UNSORTED → hashing.**
> Two pointers *needs* order to know which pointer to move. No order → no two pointers.

---

## The core mechanic (converging pointers) — sorted Two Sum
```cpp
int L = 0, R = n - 1;
while (L < R) {
    int sum = a[L] + a[R];
    if      (sum == target) return {L, R};
    else if (sum  > target) R--;     // too BIG  → drop the largest
    else                    L++;     // too SMALL → drop the smallest
}
```
**Why it works (and why SORTED is mandatory):**
- Sum too big → `a[R]` (the largest) overshoots with *anything* → discard it: `R--`.
- Sum too small → `a[L]` (the smallest) can't reach target → discard it: `L++`.
- Sorted ⇒ `L++` reliably **increases** the sum, `R--` reliably **decreases** it. Unsorted ⇒ moves are unpredictable ⇒ strategy collapses.
- **O(n):** `L` only goes right, `R` only goes left, they meet → ≤ n steps total. **O(1) space** (often *why* it beats a hash map).

## The 3 shapes (recognition map)
| Shape | Looks like | Pointers |
|---|---|---|
| **Converging (opposite ends)** | sorted pair-sum, 3Sum, container-with-most-water, valid palindrome, reverse | start & end → toward each other |
| **Fast / slow (same direction)** | remove duplicates in place, move zeroes, partition | a *read* pointer races ahead, a *write* pointer trails |
| **Two sequences** | merge two sorted arrays, intersection | one pointer per array |
| _(later, M11)_ cycle/middle of list | Floyd's cycle | slow +1, fast +2 |

## Complexity
- **O(n)** if already sorted; **O(n log n)** if *you* must sort first.
- **O(1)** space usually. ← the selling point vs hashing.

## Two Pointers vs Hashing (the discrimination, both halves now)
| | Two Pointers | Hashing |
|---|---|---|
| needs | **sorted/monotonic** | works on **unsorted** |
| space | **O(1)** | O(n) |
| returns original indices? | no (sort destroys them) | yes |
> Sorted + pair/diff + want O(1) space → two pointers. Unsorted, or need original indices → hashing.

---

## 🔲 TO FILL AFTER REPS
- [ ] Recognition cues in MY words (what surface features screamed "two pointers")
- [ ] 3Sum: the **skip-duplicates** trick + why sort first
- [ ] My gotchas / boundary bugs (the `L<R` bound, dup-skipping, overflow on `a[L]+a[R]`)
- [ ] Problems that taught me: LC167, LC15, LC11, LC125, …

_Last updated 2026-06-08 (theory seed). Level: L0→learning. See PROGRESS.md._
