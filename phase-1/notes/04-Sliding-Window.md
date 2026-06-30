# 📒 Sliding Window — Study Notes

> Your plain-English reference. Re-read before revising or before a problem you suspect
> is a window problem. (The terse cue version lives in `PATTERN_JOURNAL.md`; this is the
> "explain it to me like a human" version.)

---

## What it is
A **window** is a contiguous chunk of an array/string, marked by two pointers: `left` and
`right`. Instead of re-scanning chunks from scratch (slow), you **slide** the window and
update your answer incrementally (fast). Turns many **O(n²)** brute forces into **O(n)**.

## When to reach for it (the cue)
> "**contiguous** subarray / substring" + asking for a **max / min / longest / shortest /
> count / average / sum** over that chunk.

If the elements must be **next to each other** and you're optimizing something over them →
think sliding window.

---

## Two kinds

### 1. FIXED window — size `k` is given
Both pointers move **in lockstep**. Build the first window of size `k`, then slide: add the
new right element, remove the old left element.

```cpp
// Max sum of any window of size k
int windowSum = 0, best = INT_MIN;
for (int i = 0; i < n; i++) {
    windowSum += a[i];
    if (i >= k) windowSum -= a[i - k];   // drop the element that fell out the left
    if (i >= k - 1) best = max(best, windowSum);
}
```
- ⚠️ Keep `windowSum` and `best` as **separate** variables (a past mistake of yours).
- Solved so far: Max-sum fixed window, LC 643 (Max Average Subarray I), LC 1343.

### 2. VARIABLE window — size is NOT given, a CONDITION is
The window **breathes** 🐛. Picture a **caterpillar**: the head (`right`) reaches forward to
eat a new element; the tail (`left`) catches up when a rule says so.

**The 3 moves, every iteration:**
1. **Expand:** add `a[right]` to the window.
2. **Shrink:** `while` the window meets the shrink condition, remove `a[left]` and `left++`.
3. **Update** the answer.

**Generic templates:**
```cpp
// LONGEST window that stays VALID  → shrink WHILE invalid
int left = 0, best = 0;
for (int right = 0; right < n; right++) {
    add(a[right]);
    while (windowIsInvalid) { remove(a[left]); left++; }
    best = max(best, right - left + 1);   // valid here
}

// SHORTEST window that becomes VALID → shrink WHILE valid (hunt smaller)
int left = 0, best = INT_MAX;
for (int right = 0; right < n; right++) {
    add(a[right]);
    while (windowIsValid) {
        best = min(best, right - left + 1);
        remove(a[left]); left++;
    }
}
return best == INT_MAX ? 0 : best;
```

**Longest vs shortest — the flip:**
| Goal | Shrink while… | Record answer… |
|---|---|---|
| **Longest** valid window | window is **invalid** | after the while (window is valid) |
| **Shortest** valid window | window is **valid** | inside the while (each time it's valid) |

---

## Why variable window is O(n), not O(n²)
It looks like a nested loop (`while` inside `for`), but: `right` advances `n` times total,
and `left` **also advances at most `n` times total** — it never resets or goes backward. So
total pointer movement ≤ `2n` → **O(n)**. (Lesson: a `while` inside a `for` is NOT
automatically O(n²) — it's O(n²) only if the inner index *resets* each outer step.)

## Window length formula
`right - left + 1`  ← the `+1` is the classic off-by-one. Example: left=4, right=5 →
`5 - 4 + 1 = 2` elements. ✅

## Common traps
- Forgetting `best == INT_MAX ? 0 : best` for "no valid window" (shortest variant).
- Putting the answer update on the wrong side of the shrink `while`.
- Variable window relies on **monotonicity**: e.g. LC 209 works because all numbers are
  **positive** (adding always grows the sum). If negatives are allowed, plain window breaks
  — you'd need prefix sum + hashing instead.

## Problems that taught me this
- LC 209 — Minimum Size Subarray Sum (shortest variant) — ✅ Accepted 2026-06-04
- LC 3 — Longest Substring Without Repeating Characters (longest variant, used `unordered_set`
  to detect duplicates in O(1)) — ✅ Accepted 2026-06-04
- LC 1004 — Max Consecutive Ones III (longest window with ≤ k zeros) — ✅ Accepted 2026-06-04

### ⚠️ The ORDER rule (cost me 2 wrong submissions on LC1004)
Do the 3 steps in THIS order, every iteration — never reorder:
1. **include** nums[right] (update window state, e.g. `if(nums[right]==0) zeros++`)
2. **restore** validity (`while(invalid){ remove(nums[left]); left++; }`)
3. **record** (`ans = max(ans, right-left+1)`) — safe now because the window is guaranteed valid.
Recording before restoring = counting an invalid window. And the length is **`right-left+1`**
(the +1 is my recurring off-by-one — see MISTAKE_JOURNAL boundary checklist).

### Detecting "is X in my window?" — the hash set/array trick
When the window condition is about *membership/uniqueness* (no repeats, ≤ K distinct), keep a
side structure of what's currently in the window:
- `unordered_set<char> w;` → `w.insert(c)`, `w.erase(c)`, `w.count(c)` (1/0). O(1) average.
- Or a frequency array `int freq[128]={0};` indexed by the char — faster, no hashing overhead.
This is your first taste of **Hashing** (Module M2). The pattern "use a set/map to answer
*have I seen this?* in O(1)" shows up everywhere.

---
_Last updated: 2026-06-04 (Day 1 of sprint). Topic level: see PROGRESS.md._
