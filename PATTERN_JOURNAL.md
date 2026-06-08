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
Level: **L3 (coached) — formal lesson done 2026-06-08; L4 pending solo set (LC217/219/347/36)**
Trigger (in my words): "seen before? / how many times? / look up a complement in O(1) / group by a shared property" → hash map. **GATE: is the data SORTED? If NOT → hashing, not two pointers.**
Why it works: a hash function squashes ANY key (big int, string, negative) into a small array index → keep the array's O(1) access for arbitrary keys. Collisions are UNAVOIDABLE (pigeonhole: more keys than slots) → resolved by chaining (C++ `unordered_map`) or open addressing. Avg O(1); worst O(n) when many keys pile into one bucket.
Template/skeleton: `unordered_map<int,int> cnt; cnt[x]++;` / `unordered_set<int> s; s.count(x);`
Complexity: avg O(1) per op (worst case O(n) on adversarial collisions).
**The 4 hashing sub-patterns I've now seen (recognition map):**
- **Complement / seen-map** (Two Sum, LC1): unsorted + need a pair → store value→index, look up `target-x`. **Look up BEFORE insert** (else self-match) + **return on find**.
- **Frequency count** (Valid Anagram LC242): count chars; fixed small alphabet → `int[26]` (inc for s, dec for t, all-zero check); **unbounded/Unicode keys → switch to `unordered_map`** (the follow-up). Container changes with the key space.
- **Group / dedup by canonical KEY** (Group Anagrams LC49): compute one fingerprint per item so matches collide → `unordered_map<Key, vector<...>>`, `groups[key].push_back(item)`. Key = sorted string O(k log k) OR 26-count signature O(k). Kills O(n²) pairwise compare → O(n·k log k). No visited/include-self bookkeeping needed.
- **Set membership for O(1) reasoning** (Longest Consecutive LC128): hash SET avoids sorting; to keep a per-element walk linear, only START work from sequence beginnings (`x` is a start iff `x-1` not in set) → O(n) not O(n²).
Variants & gotchas: the complement-lookup move (Two Sum) = the core of all the prefix+hash problems.
**Recognition (the gap the 6/8 drill exposed — 0/2 on hashing):** these are HASHING, *not* two pointers:
- **Unsorted** array, need a pair summing to target, return INDICES → store value→index, look up `target-x` (LC1).
- "Have I **seen this value**, and where?" → map value→last index (e.g. duplicate within distance k, LC219: check `i-last≤k`).
- Membership / first-or-count of anything → set or freq map.
RULE: unsorted + pair/duplicate/complement ⇒ hash map (two pointers needs SORTED data).
Taught me by: LC3 (unordered_set), the whole M5 prefix+hash family; 6/8 drill flagged the recognition gap. NEXT: formal lesson + LC1 Two Sum.

### Two Pointers
Level: L0 (not formally taught — but a recognition RULE is already needed)
Trigger: **SORTED (or monotonic) array, find a pair/triple by a sum/diff condition**, OR compare from both ends.
⚠️ **GATE before reaching for this: is the data SORTED/monotonic?** If NOT sorted → it's almost always **HASHING**, not two pointers. (My #1 recognition leak — I keep parking unsorted pair/duplicate problems here. See MISTAKE #6.)
Why it works: on sorted data, moving the pointer that's "too small/too big" provably can't skip the answer → O(n) instead of O(n²).
Template/skeleton: (to fill at lesson) `l=0, r=n-1; while(l<r){ if(sum<target) l++; else if(sum>target) r--; else return; }`
Complexity: time O(n) after an O(n log n) sort / space O(1).
Variants & gotchas: needs sorting first if unsorted — and sorting destroys original indices (so if the problem wants indices of an UNSORTED array → hashing).
Taught me by: (upcoming, M3)

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
convert "not found" sentinel back to 0; window length = `right-left+1`. **Breaks if values can be
negative — OR if I transform the array (e.g. 0→−1): that introduces negatives → use prefix sum + hash, NOT SW**
(drill Q6 over-fired here). **FIXED-window incremental rule (LC567, learned hard over 5 tries):** build the
first window over `[0, len-1]`, check it, then slide `right` from `len`: `+s2[right]`, `−s2[right-len]` —
the add+remove are **unconditional every step**, NOT a reaction to a mismatch; left is implicit = `right-len`.
Taught me by: LC209 Min Size Subarray Sum (shortest) + LC3 Longest Substring No-Repeat (longest,
`unordered_set`) + LC1004 Max Consecutive Ones III (longest, ≤k zeros) + **LC567 Permutation in String
(fixed window + freq-match, incremental slide)**. **Order rule learned:** include → restore-validity → record
(record only when window is valid). Fixed-window: slide unconditionally, compare after.

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
**BIG GENERALIZATION (2026-06-07):** "prefix sum" is really **prefix AGGREGATE** — the operation can be
+, ×, ^, or count. Cue = "I need an aggregate over ranges/subarrays and brute force recomputes overlapping
pieces." Variants: range sum (P[r]-P[l-1]) · count subarrays=k (complement) · divisible (remainder) ·
equal 0s/1s (transform) · **product except self = prefix×suffix, LC238** (÷ avoided — breaks on 0s) ·
subarray XOR=k · 2D prefix. **Mental model: the hash map IS the inner loop** — it remembers every earlier
prefix so "scan all starts" becomes one O(1) lookup (O(n²)→O(n)). **`map`(O(log n)) vs `unordered_map`(O(1))**:
use unordered_map when you don't need sorted keys (LC523: 150ms→81ms just by switching).

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
