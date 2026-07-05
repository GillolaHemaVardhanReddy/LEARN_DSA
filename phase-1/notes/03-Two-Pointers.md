# 👉👈 03 — Two Pointers  (teaching notes — reread cold, they rebuild the model)

> These notes TEACH, they don't just remind. Read top to bottom and the understanding comes back.
> Two Pointers is your first "prove it, then discard half the work" pattern — the mindset under
> sliding window, merge steps, and partitioning. We go slow because the *proof* is the whole point.

## 0. Striver videos (watch AFTER these notes)
- **Two Pointers / sorted-array intro** — Striver A2Z arrays/two-pointer step (see PATTERN_JOURNAL).
- Reps that taught this note: **LC167** Two Sum II · **LC11** Container With Most Water · **LC15** 3Sum
  · **LC75** Sort Colors (Dutch flag) · **LC125** Valid Palindrome · **LC977** Squares of Sorted Array
  · **LC283** Move Zeroes · **LC680** Valid Palindrome II.

---

## BIT 0 — The one sentence
> **Two pointers = two indices walking an array so that each step you can PROVE which one to move,
> discarding a whole candidate you'll never need — turning an O(n²) search into one O(n) pass.**

Everything below is *why that discard is safe* and *how to run the pointers without an off-by-one.*

---

## BIT 1 — Why it exists (the "why")
Brute force for "find a pair that sums to target" checks **every** pair: O(n²). That's a nested loop
re-asking the same question. Two pointers kills the inner loop by using **structure** (usually sorted
order) so that after looking at one pair, you can *rule out* a bunch of pairs at once — without
checking them.

Think of a locked combination where the numbers are laid out **smallest-to-largest**. You put one
finger on each end. If the two ends are too big, you *know* the biggest number is too big for its
partner — slide that finger inward. You never had to test it against every other number; the order
told you.

> **Nested loop = re-ask every pair. Two pointers = ask once, prove, throw away a candidate.**

---

## BIT 2 — The mental UNLOCK (read twice — this is the whole topic)
> **On a SORTED array, comparing the two ends lets you PROVABLY discard one candidate per step.
> Move the pointer that CAN'T improve the answer.**

The magic isn't "two pointers." It's the **provably-safe discard.** Sorted order is what usually
gives you the proof: moving `L` right *reliably increases* the sum, moving `R` left *reliably
decreases* it. Because the moves are predictable, you can reason about what to drop.

**THE REAL RULE (corrected after LC11):** two pointers works whenever you can make a
**provably-safe decision about which pointer to move** — you can prove discarding one side *never*
loses the answer. "Sorted" is the most common *enabler* of that proof, NOT the requirement.
- **Sorted/monotonic** enables it for **sum/pair** problems (too big → drop the largest).
  Quick screen: *"sorted + pair by sum?"* → two pointers.
- **But not only sorted:** **Container With Most Water (LC11) is UNSORTED**, yet two pointers works —
  the *"shorter wall caps the area"* property gives the proof. Move the shorter wall; every container
  using it is already capped by its height AND has ≤ the current width, so you lose nothing.
- Real screen isn't *"is it sorted?"* — it's **"can I prove which pointer to move without losing the answer?"**

⚠️ The narrow rule **"unsorted pair-SUM → hashing, not two pointers"** still holds — that's the
complement/pair-sum case. It does NOT mean "two pointers needs sorted" in general (LC11/LC42 unsorted).

---

## BIT 3 — The HAND-RUN trace (converging — Two Sum II) ⭐ run this yourself
Input **`a = [2, 7, 11, 15]`, `target = 9`**. Sorted. `L=0` (left end), `R=3` (right end).

```
a:   2   7   11   15
idx  0   1    2    3
     L                R
```

| step | L | R | a[L] | a[R] | sum | vs target | move + WHY it's safe |
|---|---|---|---|---|---|---|---|
| 1 | 0 | 3 | 2 | 15 | 17 | too BIG | `R--`. 15 is the **largest** element left. Even paired with the smallest (2) it overshoots — so 15 can't be in ANY valid pair. Discard it forever. |
| 2 | 0 | 2 | 2 | 11 | 13 | too BIG | `R--`. Same logic: 11 is now the largest; overshoots even with the smallest. Drop it. |
| 3 | 0 | 1 | 2 | 7 | 9 | == target | **return {0,1}.** |

Feel step 1: we discarded 15 **without checking it against 7 or 11.** Sorted order *proved* that if
`2 + 15` is already too big, then `7 + 15` and `11 + 15` are even bigger — all dead. One comparison
killed three pairs. That is the engine.

Symmetric case: if the sum were **too SMALL**, `a[L]` (the smallest) can't reach target even paired
with the largest → `L++`, discard the smallest.

---

## BIT 4 — The converging mechanic (the code you run by hand above)
```cpp
int L = 0, R = n - 1;
while (L < R) {                       // ← STRICT <. L==R is ONE element, not a pair.
    int sum = a[L] + a[R];
    if      (sum == target) return {L, R};
    else if (sum  > target) R--;      // too BIG  → drop the largest
    else                    L++;      // too SMALL → drop the smallest
}
```
Why it's O(n): `L` only moves right, `R` only moves left, they march toward each other → **≤ n steps
total**, then they meet. **O(1) space** — often the whole reason to prefer this over a hash map.

Sorted ⇒ `L++` reliably **increases** the sum, `R--` reliably **decreases** it. Unsorted ⇒ moves are
unpredictable ⇒ the strategy collapses (for pair-sum — hash instead).

---

## BIT 5 — The OTHER family: same-direction / fast-slow (write + read pointers)
Converging is opposite ends. The second family runs **both pointers the same direction**: a **read**
pointer races ahead scanning every element, a **write** pointer trails, marking where the next "kept"
element goes. Used for **in-place rearrange / dedup / move zeroes** — no sorted requirement.

**Move Zeroes (LC283)** — push all non-zeros forward, zeros to the back, in place:
```cpp
int write = 0;                         // next slot for a kept (non-zero) value
for (int read = 0; read < n; read++) { // read scans EVERYTHING
    if (a[read] != 0)
        swap(a[write++], a[read]);     // keep it → place at write, advance write
}
```
Mental model: `read` inspects each element; `write` is "how many good elements I've committed so far,"
which is also the index of the next free slot. Everything left of `write` is finished and correct.

**Dedup a sorted array** is the same shape: `if (a[read] != a[write]) a[++write] = a[read];`.

---

## BIT 6 — Dutch-flag 3-way partition (low / mid / high) — your gap, own BIT
Problem shape: **Sort Colors (LC75)** — array of only `0,1,2`, sort in **one pass, O(1) space.** Three
pointers carve the array into four zones:

```
[ 0 0 0 | 1 1 1 | ? ? ? ? | 2 2 2 ]
         ^low     ^mid    ^high
  <low = settled 0s   low..mid-1 = settled 1s   mid..high = UNKNOWN   >high = settled 2s
```
- `low` = boundary just past the last 0. `mid` = the scanner. `high` = boundary just before the first 2.
- **Invariant to burn in:** everything `< low` is 0, everything in `[low, mid)` is 1, everything `> high`
  is 2. `mid` walks the unknown region until it collides with `high`.

```cpp
int low = 0, mid = 0, high = n - 1;
while (mid <= high) {                   // ← <=, because high is a VALID unknown slot
    if      (a[mid] == 0) swap(a[low++], a[mid++]); // 0 → send left; both advance
    else if (a[mid] == 1) mid++;                    // 1 → already home; just scan on
    else                  swap(a[mid], a[high--]);  // 2 → send right; DON'T advance mid
}
```
**The one trap that bites everyone:** on a `2`, you swap it to `high` and do `high--` but **do NOT
`mid++`** — the value you just pulled *from* `high` is unexamined, so `mid` must re-check it next loop.
On a `0` you *can* advance `mid`, because the value swapped up from `low` was already scanned (it was a
1, or `low==mid`).

---

## BIT 7 — 3Sum: the keystone (converging INSIDE a loop)
**LC15** — find all unique triplets summing to 0. It's Two Sum II wearing a hat.
1. **Sort** first (enables the two-pointer scan AND lets you skip duplicates by adjacency).
2. **Fix `nums[i]`** → the rest is **Two Sum II** for target `-nums[i]`, with `L=i+1, R=n-1`.
3. **Steering (forgetting this = infinite loop):** `sum<0 → L++` · `sum>0 → R--` · `sum==0 → record`.
   Every branch MUST move a pointer.
4. **Skip duplicates in 3 spots:** the fixed `i` (`if (i>0 && nums[i]==nums[i-1]) continue;`), and
   `L`/`R` *after* recording a hit (`while (L<R && nums[L]==nums[L-1]) L++;`).
5. **Why structural skip, NOT a `set<vector>`:** generating-then-rejecting dups **TLEs on the constant
   factor** (millions of vector allocations on inputs like `[0,0,...,0]`). Skipping means you never
   generate a dup. Overall **O(n²) time, O(1) extra space.**

---

## BIT 8 — The DECISION RECIPE (run before coding) ⭐ this is your Gate-A
Answer these **in order**, out loud, before a line of code:
1. **Is it sorted (or can I sort)?** If a pair/triple-by-sum and unsorted → *sort first* (O(n log n))
   OR switch to **hashing** if I need original indices / can't afford to sort.
2. **Which family?**
   - Compare/shrink from **both ends** (pair-sum, palindrome, container, reverse) → **converging**,
     `L=0, R=n-1`, `while (L<R)`.
   - **Rearrange in place / dedup / move** → **same-direction**, `write` trails `read`.
   - Only `{0,1,2}` or a 3-way split → **Dutch flag** (`low/mid/high`).
3. **Which pointer moves, and WHY is that provably safe?** State the discard proof in one sentence
   ("sum too big → the largest overshoots with anything → drop it"). If I can't state the proof, two
   pointers is the wrong tool.

---

## BIT 9 — Complexity, read off the shape
- **O(n)** if already sorted; **O(n log n)** if *you* must sort first. 3Sum = **O(n²)** (outer fix × inner scan).
- **O(1)** extra space almost always — the selling point vs hashing.

**Two Pointers vs Hashing (the discrimination):**
| | Two Pointers | Hashing |
|---|---|---|
| needs | **sorted/monotonic** (or a provable discard) | works on **unsorted** |
| space | **O(1)** | O(n) |
| returns original indices? | no (sort destroys them) | yes |
> Sorted + pair/diff + want O(1) space → two pointers. Unsorted, or need original indices → hashing.

---

## BIT 10 — The classic TRAPS (execution focus, boss — these are YOUR leaks)
1. **`while (L<R)` vs `while (L<=R)`.** Converging pair-sum uses **strict `<`** (L==R is one element,
   not a pair). Dutch flag uses **`<=`** (`high` is a valid unknown slot you must still examine). Pick
   by asking "is the crossing index still a real candidate?"
2. **The write-index in same-direction.** `write` is *both* the count of kept elements *and* the next
   free slot. Advancing it on the wrong branch scrambles the array. Advance `write` only when you commit.
3. **Dutch flag: don't `mid++` after a `2`-swap.** The pulled-in value is unexamined. `mid++` on 0/1 only.
4. **3Sum steering** — a branch with no pointer move → infinite loop. Every branch moves a pointer.
5. **Skip-dup loops running off the end** — always guard with the bound: `while (L<R && nums[L]==nums[L-1]) L++;`.
6. **Off-by-one bounds** — `j < n-1` dropped the last element (`[0,0,0]` failed). Loops must touch the LAST element.
7. **`unordered_set/map` can't key a `vector`/`pair`** (no default hash) → use ordered `set`/`map`.
8. **LC125 palindrome:** don't hand-roll `a..z` checks (off-by-one `< 'z'` + missed digits) → use
   **`isalnum()` / `tolower()`**. **LC680** = same but allow ONE skip (try `L+1..R` OR `L..R-1`).
9. **LC977 squares of sorted array:** biggest squares sit at the *ends* → converge, and **fill the
   result from the BACK** (write index `n-1` downward).

---

## BIT 11 — Recognition cue (my words, from the reps)
- "Sorted array + find/compare a **pair** by sum/diff" → converging two pointers (LC167).
- "Compare from **both ends** of a string/array" → converging (LC125 palindrome, LC977 squares, LC11).
- "Sorted, and the **extremes** (biggest/smallest) sit at the ends" → converge, decide by the ends (LC977).
- "Triplet/quadruplet sum = target" → **sort + fix one (or two) + two-pointer the rest** (LC15).
- "**Rearrange / dedup / move** in place, O(1) space" → same-direction write+read (LC283).
- "Only values are `0/1/2` (or 3 buckets), one pass" → **Dutch flag** low/mid/high (LC75).
- The deep cue: **"can I prove which pointer to move without losing the answer?"** → yes = two pointers.

_Reps that built this: LC125, LC977, LC15 (AC 2026-06-09); LC11/LC42 container/trapping; LC75 Dutch flag;
LC167 Two Sum II; LC283 Move Zeroes; LC680 palindrome-II. See PROGRESS.md for current level._
