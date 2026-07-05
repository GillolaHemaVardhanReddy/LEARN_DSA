# M4 — Sliding Window  (teaching notes — reread cold, they rebuild the model)

> These notes TEACH, they don't just remind. Read top to bottom and the understanding comes back.
> Sliding Window turns a whole family of O(n²) "scan every subarray" brute forces into O(n).
> (The terse cue lives in `PATTERN_JOURNAL.md`; this is the "explain it to me like a human" version.)

## 0. Striver videos (watch AFTER these notes)
- **Sliding Window & Two Pointer — full playlist / patterns lecture** — https://youtu.be/9kdHxplyl5I ⭐ start here
- Covers the 4 templates: constant window · longest-subarray-with-condition · number-of-subarrays · shortest/minimum window.

---

## BIT 0 — The one sentence
> **A window is a contiguous chunk marked by `left`/`right`; instead of re-scanning it from scratch, you SLIDE it and update the answer incrementally — O(n²) → O(n).**

Everything below is *why that slide is legal* and *how to run it by hand*.

---

## BIT 1 — Why it exists (the "why")
Brute force for "best contiguous chunk" tries **every** subarray: pick a start, pick an end, re-add
everything inside. That's O(n²) starts × O(n) to re-sum = O(n³), or O(n²) if you're careful. The waste:
when you slide from window `[l..r]` to `[l..r+1]`, you **recompute the whole overlap** you already knew.

Sliding window kills that. The two windows share almost all their elements — so don't rebuild, just
**patch the difference**: one element entered on the right, maybe one left on the left. That patch is O(1).

> **Brute = re-measure the whole chunk every time. Window = measure once, then only account for what changed.**

The cue that you're in window territory:
> "**contiguous** subarray / substring" **+** asking for a **max / min / longest / shortest / count / average / sum** over it.

If the elements must sit **next to each other** and you're optimizing something over them → sliding window.

---

## BIT 2 — The two shapes (fixed vs variable)

**FIXED window — size `k` is handed to you.** Both pointers move in lockstep. Build the first `k`, then
each step: add the new right element, drop the element that fell off the left.
```cpp
// Max sum of any window of size k
int windowSum = 0, best = INT_MIN;
for (int i = 0; i < n; i++) {
    windowSum += a[i];
    if (i >= k) windowSum -= a[i - k];   // drop the element that just fell out the left
    if (i >= k - 1) best = max(best, windowSum);   // window is full → it's a candidate
}
```
Keep `windowSum` and `best` as **separate** variables (a past leak of yours — don't fold them).
Family: LC643 (Max Average Subarray I), LC1343.

**VARIABLE window — size is NOT given, a CONDITION is.** The window **breathes** 🐛. Picture a
**caterpillar**: the head (`right`) reaches forward to eat a new element; the tail (`left`) catches up
only when a rule forces it. This is the real workhorse — BIT 3 is its whole engine.

---

## BIT 3 — THE UNLOCK: grow right, shrink left on the broken invariant → O(n) (read twice)
This is the heart of the topic.

> **Grow the window with the RIGHT pointer. The MOMENT the invariant breaks, shrink from the LEFT until it holds again. Each element enters once and leaves at most once → O(n).**

Every iteration is exactly three moves, **in this fixed order**:
1. **include** `a[right]` — update window state (a sum, a count, a freq map).
2. **restore** validity — `while (invalid) { remove(a[left]); left++; }`.
3. **record** the answer — safe now, the window is guaranteed valid.

```cpp
// LONGEST valid window  → shrink WHILE invalid, record AFTER the while
int left = 0, best = 0;
for (int right = 0; right < n; right++) {
    add(a[right]);
    while (windowIsInvalid) { remove(a[left]); left++; }
    best = max(best, right - left + 1);          // window valid here
}

// SHORTEST valid window → shrink WHILE valid (hunt smaller), record INSIDE the while
int left = 0, best = INT_MAX;
for (int right = 0; right < n; right++) {
    add(a[right]);
    while (windowIsValid) {
        best = min(best, right - left + 1);
        remove(a[left]); left++;
    }
}
return best == INT_MAX ? 0 : best;               // no valid window → 0
```

**Longest vs shortest — the flip:**
| Goal | Shrink while… | Record answer… |
|---|---|---|
| **Longest** valid window | window is **invalid** | AFTER the while (window is valid) |
| **Shortest** valid window | window is **valid** | INSIDE the while (each valid moment) |

**Why it's O(n), not O(n²)** (a `while` inside a `for` scares you — don't let it): `right` advances `n`
times total; `left` **also advances at most `n` times total** — it never resets, never goes backward. Total
pointer motion ≤ `2n` → **O(n)**. A `while` inside a `for` is only O(n²) if the inner index *resets* each
outer step. Here it doesn't.

---

## BIT 4 — HAND-RUN it: longest substring without repeat, `s = "abcabcbb"`
Invariant = "no duplicate char in the window." Shrink while a duplicate exists. Freq/set tracks membership.

```
Legend: [ ] = current window,  best = longest valid length so far
r=0 'a'  window [a]        no dup      best=1     (0-0+1)
r=1 'b'  window [ab]       no dup      best=2
r=2 'c'  window [abc]      no dup      best=3
r=3 'a'  add 'a' → dup!    shrink: remove s[left=0]'a', left=1 → [bca] valid   best=max(3,3)=3
r=4 'b'  add 'b' → dup!    shrink: remove s[left=1]'b', left=2 → [cab] valid   best=3
r=5 'c'  add 'c' → dup!    shrink: remove s[left=2]'c', left=3 → [abc] valid   best=3
r=6 'b'  add 'b' → dup!    shrink: remove 'a'(l=3),'b'(l=4) left=5 → [cb] valid best=3
r=7 'b'  add 'b' → dup!    shrink: remove 'c'(l=5),'b'(l=6) left=7 → [b] valid  best=3
answer = 3   ("abc")
```
Watch the unlock live: 'a' at r=3 **broke** the invariant; the left pointer walked forward *just enough*
to restore it, never further. No element was ever visited by `left` twice. That's the O(n).

Membership check ("is this char already in my window?") is done with a side structure:
`unordered_set<char>` (`insert`/`erase`/`count`, O(1) avg) or a `int freq[128]={0}` indexed by the char
(faster, no hashing). This is your first taste of **Hashing (M2)**: "use a set/map to answer *have I seen
this?* in O(1)."

---

## BIT 5 — ⭐ DERIVE-DON'T-MAINTAIN (your confirmed principle — burn this in)
The window has ONE driver: `right`. Everything else should be **derived from `left` and `right`**, not
hand-maintained as a parallel bookkeeping variable you can desync.

> **One driver loop (`right`). One while-shrink on the invariant. DERIVE the window length as `r - l + 1` — never keep a separate `len` / `count` variable that just mirrors it.**

The window **length is already implied** by the two pointers — `r - l + 1`. If you also carry an `int len`
that you `len++` on grow and `len--` on shrink, you now have **two sources of truth** for one fact. The
day they disagree (you shrink but forget a `len--`) is a silent wrong answer. Delete it. Read it off the
pointers.

Same logic for anything the pointers already pin down:
- Window **length** → `r - l + 1`. Never a maintained `len`.
- "Have I filled `k` elements?" (fixed window) → `i >= k - 1`. Never a maintained counter.

**The ONE thing you *do* maintain** is state you genuinely can't cheaply re-derive: a running `sum`, or a
`freq`/count map. Those cost O(n) to recompute from scratch, so you patch them incrementally (add on grow,
subtract on shrink) — that's the whole point of the window. The rule isn't "never maintain"; it's **never
maintain what a subtraction of two indices already gives you for free.**

Gut check before you add any variable: *"Is this already implied by `left` and `right`? Then don't store it."*

---

## BIT 6 — The atMost(k) − atMost(k−1) counting trick (its own idea)
Some problems ask **"how many subarrays have EXACTLY k of something"** (k distinct integers, exactly k odd
numbers…). "Exactly" is awkward for a window — the shrink condition isn't clean. The move:

> **exactly(k) = atMost(k) − atMost(k − 1).**

`atMost(k)` — "count subarrays with **at most** k" — *is* a clean sliding window: grow right, and while the
window has **more than k**, shrink left. Here's the counting insight: **when the window `[l..r]` is valid,
every subarray ending at `r` with start in `[l..r]` is also valid — that's `r - l + 1` new subarrays.** Add
that each step. (Note: `r - l + 1` again — DERIVE, don't maintain.)

```cpp
int atMost(vector<int>& a, int k) {
    if (k < 0) return 0;                      // guard — atMost(k-1) with k=0 asks atMost(-1)
    int left = 0, cnt = 0;
    unordered_map<int,int> freq;
    for (int right = 0; right < a.size(); right++) {
        freq[a[right]]++;
        while ((int)freq.size() > k) {        // more than k distinct → shrink
            if (--freq[a[left]] == 0) freq.erase(a[left]);
            left++;
        }
        cnt += right - left + 1;              // all subarrays ending at right that are valid
    }
    return cnt;
}
int subarraysWithKDistinct(vector<int>& a, int k){ return atMost(a,k) - atMost(a,k-1); }
```
Family: **LC992** (Subarrays with K Different Integers), **LC930** (Binary Subarrays With Sum — atMost by
sum ≤ k). Trap baked into the code above: the `k < 0` guard — `atMost(k-1)` can be handed `k = 0 → -1`.

---

## BIT 7 — The design recipe (run BEFORE coding) ⭐ your Gate-A for windows
Answer these, in order:
1. **Fixed or variable?** — is a size `k` given (fixed, lockstep) or a *condition* given (variable, breathes)?
2. **What's the invariant that triggers a shrink?** — state it as one sentence ("sum ≥ target", "no dup",
   "≤ k zeros", "≤ k distinct"). No clean invariant → maybe it's not a window (see BIT 8 monotonicity trap).
3. **Longest or shortest?** — sets shrink-while-invalid + record-after (longest) vs shrink-while-valid +
   record-inside (shortest). See the BIT 3 table.
4. **Am I maintaining a variable I could DERIVE?** — kill any `len`/`count` that's just `r - l + 1`. Keep
   only genuinely-incremental state (running sum, freq map).
5. **"Exactly k"?** — reach for atMost(k) − atMost(k−1) (BIT 6).

---

## BIT 8 — Complexity + the monotonicity precondition
- **Time O(n):** `right` moves n times, `left` moves ≤ n times total (BIT 3). Fixed window is plainly O(n).
- **Space:** O(1) for a running sum; O(k) or O(alphabet) for a freq map/set.
- **The precondition that makes shrinking legal — MONOTONICITY.** LC209 works because all numbers are
  **positive**: adding an element only ever *grows* the sum, so once you're valid, shrinking is the only way
  back. If **negatives are allowed**, adding can shrink the sum and a plain window **breaks** — you'd need
  prefix-sum + hashing instead. Always ask: "does growing the window move my quantity in ONE direction?"

---

## BIT 9 — The classic traps (execution focus, boss)
1. **`k = length` overfit** — treating a target *SUM* as if it were a window *length*. LC209 gives you a
   target sum `≥ target`; the window size is *unknown* and variable. Don't lock the window to `k` elements
   because you saw a `k`. Ask: is `k` a length or a condition?
2. **Off-by-one on window size** — it's `right - left + 1`. left=4,right=5 → `5-4+1 = 2` elements. The `+1`
   is your recurring miss. (Also your reason to DERIVE it once, not re-type it — BIT 5.)
3. **Wrong side of the shrink for the answer** — recording BEFORE restoring validity = counting an invalid
   window. Longest records AFTER the while; shortest records INSIDE. (Cost you 2 subs on LC1004.)
4. **Boundary init / return on longest** — `best = 0` (empty is valid, length 0), but shortest inits
   `best = INT_MAX` and **must** return `best == INT_MAX ? 0 : best` for "no valid window."
5. **Reordering the 3 steps** — always include → restore → record. Never reorder.
6. **atMost with k−1 = −1** — guard `if (k < 0) return 0;` (BIT 6).

---

## BIT 10 — Recognition cue (fill in YOUR words after the coding ladder)
> "contiguous subarray/substring" + "longest/shortest/count/max/min under a condition" → sliding window;
> given size `k` → fixed; given a condition → variable (grow right, shrink left on the broken invariant);
> "exactly k" → atMost(k) − atMost(k−1).

*(Your teach-it-back line goes here once you've coded the ladder — that's the L6 signal.)*

## Problems that taught me this
- **LC209** — Minimum Size Subarray Sum (shortest, sum ≥ target; positives → monotonic) — ✅ 2026-06-04
- **LC3** — Longest Substring Without Repeating Characters (longest, set for membership) — ✅ 2026-06-04
- **LC1004** — Max Consecutive Ones III (longest window with ≤ k zeros) — ✅ 2026-06-04
- **LC567** — Permutation in String (fixed window, freq-match)
- **LC76** — Minimum Window Substring (shortest, freq-cover invariant)
- **LC992** — Subarrays with K Different Integers (atMost trick) · **LC930** — Binary Subarrays With Sum (atMost by sum)

---
_This note teaches the model; PROGRESS.md holds the mastery level. Last restructured into teaching-BITS format._
