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
> **THE REAL RULE (corrected 2026-06-09 after LC11):** Two pointers works whenever you can make a
> **provably-safe decision about which pointer to move** — i.e. you can prove discarding one side
> *never* loses the answer. "Sorted" is the most common *enabler* of that proof, NOT the requirement.
> - **Sorted/monotonic** enables it for **sum/pair** problems (too big → drop the largest). Quick screen: *"sorted + pair by sum?"* → two pointers.
> - **But not the only enabler:** **Container With Most Water (LC11) is UNSORTED**, yet two pointers works —
>   the *"shorter wall caps the area"* property proves the safe move (move the shorter wall; any container using it
>   is already capped and ≤ current width, so you lose nothing).
> - So the real screen isn't *"is it sorted?"* — it's **"can I prove which pointer to move without losing the answer?"**
>
> ⚠️ The narrower **"unsorted pair-SUM → hashing, not two pointers"** still holds — that's specifically for the
> complement/pair-sum recognition. It does NOT mean "two pointers needs sorted" in general (LC11/LC42 are unsorted).

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

## ✅ FILLED FROM REPS (2026-06-09)

### Recognition cues in my words
- "Sorted array + find/compare a **pair** by sum" → converging two pointers (LC167/LC15).
- "Compare from **both ends** of a string/array" → converging (LC125 palindrome, LC977 squares).
- "Sorted, and the **extremes** (biggest/smallest) sit at the ends" → converging, decide by comparing the ends (LC977).
- "Triplet/quadruplet sum = target" → **sort + fix one (or two) + two-pointer the rest** (LC15).

### 3Sum — the keystone pattern
1. **Sort** first (lets you two-pointer AND skip duplicates by adjacency).
2. **Fix `nums[i]`** → the rest is **Two Sum II** for target `-nums[i]` (L=i+1, R=n-1).
3. **Steering (DON'T forget — forgetting = infinite loop):** `sum<0 → L++` · `sum>0 → R--` · `sum==0 → record`.
4. **Skip duplicates in 3 spots:** the fixed `i` (`if(i>0 && nums[i]==nums[i-1]) continue;`), and `L`/`R` after a hit.
5. Why structural skip-dups, NOT a `set<vector>`: generating-then-rejecting duplicates **TLEs on the constant factor**
   (millions of vector allocations on inputs like `[0,0,...,0]`). Skipping means you never generate a dup. O(n²), O(1) space.

### My gotchas / boundary bugs (the recurring leak — watch these)
- **Forgot the steering** → the `while(L<R)` loop only moved pointers inside `if(sum==0)` → **infinite loop**. Every branch must move a pointer.
- **Skip-dup loops ran off the end** → guard with the bound: `while(L<R && nums[L]==prev) L++;`.
- **Off-by-one bounds** (`j < n-1` dropped the last element → `[0,0,0]` failed). Loops must touch the LAST element.
- **`unordered_set/map` can't key on `vector`/`pair`** (no default hash) → use ordered `set`/`map`.
- **LC125:** hand-rolled `a..z` check had `< 'z'` (off-by-one) AND missed digits → just use **`isalnum()` / `tolower()`**.
- **LC977:** fill the result **from the back** (write index `n-1` downward); largest squares are at the ends.

### Problems that taught me
- LC125 Valid Palindrome (converging + skip) · LC977 Squares of Sorted Array (converging, compare ends, fill from back)
  · **LC15 3Sum (keystone: sort + fix-one + steer + skip-dups)** · LC11, LC42 — pending.

_Last updated 2026-06-09. Level: learning (2E + 1M done — LC125/977/15 AC). See PROGRESS.md._
