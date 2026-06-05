# PATTERN_JOURNAL.md — Recognition Engine for Hema Vardhan

> The point of the whole system: see an unseen problem, recognize the tool.
> This file grows as you solve. The **trigger** ("when you see ___ → consider ___")
> is the most important field — fill it in your own words after each problem.
> Pattern mastery is tracked separately from topic mastery.

---

## Quick trigger index  (your cheat-sheet — keep it tight)
> This subsumes the old "Interview Pattern Map." When stuck on classification,
> scan this first.

| If you see… | Consider |
|---|---|
| "seen before? / how many times?" | Hashing / frequency map |
| sorted array, find pair/triple | Two pointers |
| compare from both ends | Two pointers |
| longest/shortest **contiguous** subarray/substring | Sliding window |
| sum/count over many ranges; subarray sum = k | Prefix sum (+ hash) |
| sorted, or monotonic yes/no, or minimize-the-max | Binary search (on answer) |
| matching / nesting | Stack |
| next/previous greater or smaller element | Monotonic stack |
| max/min of every window size k | Monotonic deque |
| cycle / middle / kth-from-end in a list | Fast & slow pointers |
| all subsets / permutations / combinations / placements | Backtracking |
| process nodes / depth / paths in a tree | Tree DFS |
| level-by-level / shortest unweighted | BFS |
| grid of connections, components / spread | Graph BFS/DFS, flood fill |
| ordering with prerequisites | Topological sort |
| dynamic connectivity / grouping | Union-Find |
| shortest path with (non-negative) weights | Dijkstra (heap) |
| k largest/smallest / running median | Heap (or two heaps) |
| prefix / autocomplete / many-word lookups | Trie |
| count ways / optimal over choices + overlapping subproblems | Dynamic programming |
| local choice provably safe | Greedy (justify with exchange argument) |
| overlapping intervals / merge / max concurrent | Sort intervals + sweep |
| pairs cancel / toggle / small fixed state set | Bit manipulation / XOR |

---

## Per-pattern entries
> Mentor adds/updates these as patterns are learned. Template below; keep one
> section per pattern. `Level` uses L0–L6 (same scale as `PROGRESS.md`).

### TEMPLATE
```
### <Pattern name>
Level: L0–L6
Trigger (in my words): when I see ___, I reach for ___
Why it works: <one-sentence intuition>
Template/skeleton: <the reusable code shape, in my chosen language>
Complexity: time __ / space __
Variants & gotchas: <fixed vs variable window, off-by-one, etc.>
Taught me by: <problems that built this — link to MISTAKE_JOURNAL if relevant>
```

---

## Patterns (seed list — start at L0, grow as you go)

### Hashing / Frequency
Level: L1 (used unordered_map/set operationally in M4/M5; FORMAL lesson pending — Striver [013] next)
Trigger (in my words): "seen before? / how many times? / look up a complement in O(1)" → hash map.
Why it works: (to formalize next session) average O(1) insert/lookup via hashing; watch collisions.
Template/skeleton: `unordered_map<int,int> cnt; cnt[x]++;` / `unordered_set<int> s; s.count(x);`
Complexity: avg O(1) per op (worst case O(n) on adversarial collisions).
Variants & gotchas: the complement-lookup move (Two Sum) = the core of all the prefix+hash problems.
Taught me by: LC3 (unordered_set), the whole M5 prefix+hash family. NEXT: formal lesson + LC1 Two Sum.

### Two Pointers
Level: L0
Trigger:
Why it works:
Template/skeleton:
Complexity:
Variants & gotchas:
Taught me by:

### Sliding Window
Level: L4 (variable: 3 mediums AC — LC209/LC3/LC1004) · fixed self-reported
Trigger (my words, polished): When I see "**longest / shortest / min-length** **contiguous**
subarray or substring that **satisfies a condition**" and the **size is not given** → variable
sliding window. If the **size k IS given** → fixed window.
Why it works: Two forward-only pointers; each element enters once and leaves once → O(n)
instead of O(n²). Relies on **monotonicity** (e.g. all-positive numbers: adding grows the sum).
Template/skeleton:
```cpp
// SHORTEST valid window → shrink WHILE valid
int left=0, ans=INT_MAX; /*window state*/
for(int right=0; right<n; right++){
    add(a[right]);
    while(valid){ ans=min(ans, right-left+1); remove(a[left]); left++; }
}
return ans==INT_MAX?0:ans;
// LONGEST valid window → shrink WHILE invalid, record AFTER the while
```
Complexity: time O(n) / space O(1) (or O(k) with a freq map/set).
Variants & gotchas: **shortest** = shrink while VALID, record INSIDE while. **longest** =
shrink while INVALID, record AFTER while. Boundary traps: min-tracker must start at INT_MAX;
convert "not found" sentinel back to 0; window length = `right-left+1`. Breaks if values can be
negative (then use prefix sum + hash instead).
Taught me by: LC209 Min Size Subarray Sum (shortest) + LC3 Longest Substring No-Repeat (longest,
`unordered_set`) + LC1004 Max Consecutive Ones III (longest, ≤k zeros). **Order rule learned:**
include → restore-validity → record (record only when window is valid).

### Prefix Sum (+ Hash Map of keys)
Level: L4 (LC560/LC974/LC525 mediums AC + LC724 easy AC)
Trigger (my words): "sum/count over RANGES" or "subarray sum = / divisible-by / equal-counts"
**and sliding window is dead** (negatives present, or it's a count not a window) → prefix sum.
If I then need to MATCH/COUNT something about two prefixes → put prefixes in a **hash map**.
Why it works: `sum(L..R) = prefix[R] - prefix[L-1]`. A condition on a subarray becomes a
condition on TWO prefix values → store prefixes seen so far, look up the one I need in O(1).
It's **Two Sum on prefix sums.**
Template/skeleton:
```cpp
unordered_map<int,int> seen;   // KEY = a function of the running prefix
seen[0] = 1;                   // empty prefix (count) ... or seen[0] = -1 (first-index for LONGEST)
int run = 0, ans = 0;
for (int i = 0; i < n; i++) {
    run += a[i];
    int key = /* sum  |  ((run%k)+k)%k  |  run-after-transform */;
    // COUNT variant:   ans += seen[key - target]; seen[key]++;
    // LONGEST variant: if (seen.count(key)) ans = max(ans, i - seen[key]); else seen[key] = i;
}
```
Complexity: time O(n) / space O(n) (or O(k) for remainders).
Variants & gotchas (the 3 KEYS I've used):
- **complement** key=running sum, look up `sum-k` → LC560 (count subarrays sum=k).
- **remainder** key=`((sum%k)+k)%k` (NORMALIZE negatives!), match equal remainder → LC974.
- **equal-prefix after transform** (0→−1), longest run with sum 0, store FIRST index, `seen[0]=-1` → LC525.
- COUNT → store frequency & `seen[0]=1`. LONGEST → store first index & `seen[0]=-1`. Don't mix them up.
- Derive the prefix formula by MEANING (total up to R minus total before L), never by shape.
Taught me by: LC560 (complement) + LC724 (pure prefix, balance point) + LC974 (remainder, +negative-mod
primitive) + LC525 (transform + longest). Same engine, different KEY each time.

### Binary Search (incl. on answer)
Level: L0
Trigger:
Why it works:
Template/skeleton:
Complexity:
Variants & gotchas:
Taught me by:

### Monotonic Stack
Level: L0
Trigger:
Why it works:
Template/skeleton:
Complexity:
Variants & gotchas:
Taught me by:

### Fast & Slow Pointers
Level: L0
Trigger:
Why it works:
Template/skeleton:
Complexity:
Variants & gotchas:
Taught me by:

### Backtracking
Level: L0
Trigger:
Why it works:
Template/skeleton (choose→explore→un-choose):
Complexity:
Variants & gotchas:
Taught me by:

### Tree DFS / BFS
Level: L0
Trigger:
Why it works:
Template/skeleton:
Complexity:
Variants & gotchas:
Taught me by:

### Graph BFS/DFS (+ flood fill)
Level: L0
Trigger:
Why it works:
Template/skeleton:
Complexity:
Variants & gotchas:
Taught me by:

### Topological Sort
Level: L0
Trigger:
Why it works:
Template/skeleton:
Complexity:
Variants & gotchas:
Taught me by:

### Union-Find
Level: L0
Trigger:
Why it works:
Template/skeleton:
Complexity:
Variants & gotchas:
Taught me by:

### Heap / Top-K / Two-Heaps
Level: L0
Trigger:
Why it works:
Template/skeleton:
Complexity:
Variants & gotchas:
Taught me by:

### Dynamic Programming (1-D → 2-D)
Level: L0
Trigger:
Why it works:
Template/skeleton (state + transition):
Complexity:
Variants & gotchas:
Taught me by:

### Greedy
Level: L0
Trigger:
Why it works:
Template/skeleton:
Complexity:
Variants & gotchas:
Taught me by:

### Intervals
Level: L0
Trigger:
Why it works:
Template/skeleton:
Complexity:
Variants & gotchas:
Taught me by:

### Bit Manipulation
Level: L0
Trigger:
Why it works:
Template/skeleton:
Complexity:
Variants & gotchas:
Taught me by:
