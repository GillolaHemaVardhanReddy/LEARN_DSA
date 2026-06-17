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
| **COUNT subarrays with EXACTLY k _____** | `atMost(k) − atMost(k−1)` (each window-friendly), OR transform→prefix+hash |
| sum/count over many ranges; subarray sum = k | Prefix sum (+ hash) |
| sorted, or monotonic yes/no, or minimize-the-max | Binary search (on answer) |
| **sort/group by a COUNT or frequency; key is an int in a small range** | Bucket / counting sort (index = the key) |
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
Level: **L4** — solo set LC217/219/347/36 all AC. **Drill 6/10: Q7 (dup within k) named cold as hashing ✓ → the recurring "→2ptr" miss is CLEARED. Q1 (unsorted Two Sum): first instinct still flickered to "sort + two pointers" before recovering to the map.** L5 is one clean unsorted-pair call away — the recognition is right, the FIRST instinct on unsorted-pair isn't fully reflexive yet.
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
Level: **L4 (converging) 2026-06-09** — LC167 clean solo + LC11 Container largely his. Full notes: `Notes/03`. GAPS: Dutch-flag re-code, boundary reflex, L5. **Drill 6/10: Q2 (sorted pair) clean ✓ BUT Q1 (UNSORTED pair) over-fired here — reached for two pointers when the data isn't sorted. The disqualifier check ("is it sorted? loses indices?") isn't automatic yet. L5 held: fix the OVER-application, the twin of the hashing under-fire.**
Trigger: the REAL rule is a **provably-safe move** (discarding one side never loses the answer). SORTED enables that for **sum/pair** problems — but it's NOT the only enabler (Container/Trapping are UNSORTED, use "move the limiting side"). Quick screen: "sorted + pair by sum?".
⚠️ **GATE for the PAIR-SUM family: is it SORTED?** If NOT sorted → **HASHING**, not two pointers. (My #1 recognition leak — see MISTAKE #6.) But "two pointers" ≠ "needs sorted" in general.
Why it works: a provable safe-discard each step → O(n). For sums: too-big drops the largest. For Container: shorter wall caps area, so move it.
The 3 shapes: **converging** (opposite ends — sum-steered or greedy) · **fast/slow** (read/write in place) · **fix-one + two-pointer** (3Sum). Plus **Dutch flag** (3-way partition, low/mid/high — left-known/right-unknown asymmetry: advance mid on a 0-swap, NOT on a 2-swap).
Complexity: O(n) (O(n log n) if you sort first) / O(1) space — the selling point vs hashing.
Variants & gotchas: 3Sum = sort + fix-one + steer + **skip dups at i AND L/R** (structural skip beats set<vector> which TLEs on constant factor). Valid Palindrome II = converging + **commit the ONE deletion at the mismatch** → check both halves fully (helper). Boundary traps: `L<R` bound, skip-dup needs `L<R &&` guard, `a[L]+a[R]` overflow.
Taught me by: LC167 (converging) · LC15 3Sum · LC11 Container (greedy) · LC125/977/283/680 · LC75 (Dutch-flag concept). LC42 Trapping = weekend.

### Sliding Window
Level: **L5 RECOGNIZED 2026-06-10** — named cold across two interleaved drills with ZERO misses (6/08: 3/3 true-SW · 6/10 Q3 shortest-subarray clean). Variable: 3 mediums AC (LC209/LC3/LC1004). The discrimination is solid: rejects negatives/±1-transform problems (routes them to prefix+hash) instead of over-firing.
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
**⚠️ EXACTLY-k COUNT — when a lone window CANNOT do it (P14/LC1248, derived 2026-06-16):** a window
shrinks only on a **one-sided/monotonic violation** ("too many → shrink back"). It can detect crossing
ONE threshold in ONE direction. **"count subarrays with EXACTLY k"** is a **two-sided** target (`> k-1`
AND `≤ k`) — "equal" is the GOAL, not a violation, so there's nothing to shrink *on*. **My own words:** a
window only works on a yes/no (monotonic) condition; "exactly k" is a *third* state (`<`, `>`, `=`) it can't
camp on. **THE FIX (the recognition gold):** `exactly(k) = atMost(k) − atMost(k−1)` — each `atMost` IS a
clean monotonic window (shrink while `> k`), and counting subarrays inside it is `ans += right-left+1` each
step. Convert one impossible question into two easy ones. **Second route:** transform odd→1/even→0, then
"exactly k odds" == "subarray sum exactly k" == LC560 prefix+hash (P9). Family: LC1248, LC992 (K distinct),
LC930 (binary sum).

### Prefix Sum (+ Hash Map of keys)
Level: **L4 (approaching L5)** — drill Q4 (count subarrays sum=k WITH negatives) named cold w/ correct trigger, but it's ONE clean call after a 6/08 miss (routed prefix→SW). L5 needs a clean track record; re-test 6/14. Mediums LC560/LC974/LC525 AC + LC724 easy AC.
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
Level: **L4 EARNED 2026-06-10** — LC34 (first/last) + LC875 (Koko, search-on-answer) mediums AC, on top of LC704/35 easies. Recognition independent on both. Support on Koko was a PRIMITIVE (integer-overflow magnitude), not the pattern. Drill 6/10 Q5/Q6 (search-on-answer + rotated) named cold — L5 HELD only because it's same-day as L4 (cadence: don't test transfer the day you reach the level). Full notes: `Notes/06`.
Trigger (my words): the real cue is **MONOTONICITY** — any "NO NO NO YES YES YES" flip, not just "sorted array".
"sorted + search" · "first/last/boundary/insert-position" · "**min/max value such that feasible**" (search the ANSWER) · "monotonic yes/no".
Why it works: each step halves the search space → O(log n). Safe to discard a half because monotonicity guarantees the answer isn't there.
Template/skeleton (ONE engine, FOUR knobs: condition · move-direction · range · return):
```cpp
// STORE-THE-CANDIDATE (my default for bounds + search-on-answer)
int lo=START, hi=END, ans=DEFAULT;          // array→indices [0,n-1]; answer-search→VALUES [min,max]
while (lo <= hi) {
    int mid = lo + (hi-lo)/2;               // overflow-safe!
    if (condition(mid)) { ans=mid; hi=mid-1; }   // min/first→go LEFT (max/last→lo=mid+1)
    else                  lo=mid+1;
}
return ans;
```
Complexity: O(log n); search-on-answer = O(n · log(range)).
Variants & gotchas: exact / lower-upper bound / **search-on-answer (Koko: lo,hi are VALUES, feasible(k)=Σceil(pile/k)≤h, use long long)** / rotated (one half always sorted) / 2D / on-a-function. **PITFALLS (my #1 leak):** `lo<=hi` vs `lo<hi`, `mid=lo+(hi-lo)/2`, `lo=mid+1` makes progress (no infinite loop), `hi=mid` vs `hi=mid-1`. **NO band-aid `if(s==e)` patches — clean template handles single/empty by design; reason 4 edges BEFORE submit.**
⚠️ **OVERFLOW IS A 5th EDGE (Koko, LC875):** when lo/hi are VALUES up to 1e9, two arithmetic spots overflow `int`: (1) `mid=(lo+hi)/2` — the SUM hits 2.4e9 before the /2; fix = `mid=lo+(hi-lo)/2` (every intermediate ≤ hi). (2) the feasibility accumulator `sum=Σceil(pile/k)` — at k=1 that's the total bananas = up to 1e4·1e9 = **1e13**; `sum` and `find_hours`'s RETURN must be `long long`. Lesson: reason the MAGNITUDE of every `+`/`*`/accumulator, not just indices. (int ≈ ±2.1e9, long long ≈ ±9.2e18.)
**Rotated array (LC33):** at each mid, ONE half is always sorted — test if target lies inside that sorted half; if yes search it, else the other. Still O(log n).
**SEARCH-ON-ANSWER — the universal brute→optimal (P16/LC1011, 2026-06-17):** the BRUTE for *any* search-on-answer is **linearly try every candidate answer + a feasibility check**; the OPTIMAL is **binary-search the candidate** because feasibility is monotonic (NO-NO-NO-YES-YES). Brute & optimal **share the exact same `feasible()`** — only the outer search changes (O(range)·n → O(n·log range)). **The feasibility function is PROBLEM-SPECIFIC — don't import it:** Koko's piles are *divisible* → `feasible(k)=Σceil(pile/k)≤h`; ship packages (LC1011) are *indivisible & in-order* → feasibility is a **greedy consecutive day-count** (`days=1, load=0; for w: if load+w>cap {days++; load=0;} load+=w; feasible ⇔ days≤D`). Using `ceil(sum/cap)` for ships is WRONG (it pretends you can split/repack — counterexample `[3,4,3]`, cap 5: ceil=2 but real greedy=3 days). Range for ship = `[*max_element, accumulate(...)]` (capacity must hold the heaviest single package; one-day upper bound = total). Direction knob: `feasible(mid)` TRUE → store + shrink right (`end=mid-1`); FALSE → `start=mid+1`.
Taught me by: LC704 (exact), LC35 (lower bound), LC34 (first/last), **LC875 Koko (search-on-answer + the overflow lesson, see MISTAKE #8)** AC, **LC1011 Capacity to Ship (search-on-answer; derived the greedy day-count feasibility himself, debugged the trailing-day boundary bug)** AC. Rotated/2D/split-array pending.

### Stack (plain LIFO)
Level: **L2 (theory 2026-06-10; videos [297][298][301] watched)** — not yet coded from memory.
Trigger (WHEN to use): "**matching / nesting / balanced**" or "the **most recent unmatched** thing decides" → stack. Brackets, undo, browser-back, anything LIFO.
Why it works: holds the unresolved items in order, most-recent on top — exactly what a closer/next-item needs to check. Beats a COUNTER: a counter handles ONE bracket type but fails on mixed types (`([)]` counts to 0 yet is invalid) because it forgets WHICH opener is most recent.
Template/skeleton: `stack<char> st;` push openers; on closer, `st.empty()||st.top()!=match → false`, else pop. Balanced ⇔ stack empty at end. All ops O(1).
Complexity: O(n) time / O(n) space.
Variants & gotchas: carry extra state on the stack when needed (Min Stack = push (val, min-so-far)). Empty-stack check BEFORE top()/pop() (boundary!).
Taught me by: theory + Striver [297][298][300]. Code next session (Valid Parentheses) = L3.

### Monotonic Stack
Level: **L2 (theory 2026-06-10; video [301] watched)** — not yet coded from memory.
Trigger (WHEN to use): "**for each element, find the NEXT or PREVIOUS greater/smaller element**" → monotonic stack. Also: Daily Temperatures, Stock Span, histogram-area, "how far until something bigger/smaller."
Why it works: the stack holds elements **still waiting for their answer**, kept in monotonic order. A new element that breaks the order **resolves** the ones it beats — pop each and record the answer as you push. (Next-GREATER → keep a DECREASING stack; pop while new ≥ top.)
Template/skeleton:
```cpp
// Next greater to the RIGHT (indices), answer = distance or value
stack<int> st;                       // holds indices, temps decreasing
for (int i = 0; i < n; i++) {
    while (!st.empty() && a[i] > a[st.top()]) {
        int j = st.top(); st.pop();
        ans[j] = i - j;              // a[i] is j's next-greater
    }
    st.push(i);
}                                    // leftovers in stack have no greater → default 0
```
Complexity: **O(n) AMORTIZED** — each element pushed once & popped at most once = 2n ops total, even with the inner while. (Same "enter once / leave once" argument as sliding window — this is the GATE for the topic.)
Variants & gotchas: direction (next vs previous) = scan L→R vs R→L; greater vs smaller = flip the `>` and the stack's monotonic direction; circular array (NGE II) = loop `i` over `2n` with `%n`. Strict vs non-strict (`>` vs `>=`) matters for duplicates (subarray-min problems).
Taught me by: theory + Daily Temperatures dry run; Striver [301][303][302][311]. Code next session = L3.

### Bucket / Counting Sort (non-comparison sort)
Level: **L3 (2026-06-17)** — P15 LC451 Sort Characters by Frequency: brute (count+sort) AC, then bucket optimal AC from memory after deriving the design himself.
Trigger (my words): "sort or group by a **COUNT / frequency**" or "the sort key is an **integer in a small, bounded range**" → don't comparison-sort, **use the key itself as an array index**. Cue word: "by frequency", "most common", "sort by how many times".
Why it works: comparison sorts are stuck at Ω(n log n) because they *compare*. Bucket sort **refuses to compare** — it scatters each item into `bucket[key(item)]`, then gathers buckets in index order. Index-placement replaces compare-and-sort → O(n + K).
Template/skeleton:
```cpp
// LC451: sort chars by frequency, high→low
int n = s.size();
unordered_map<char,int> cnt;                  // 1) count fully FIRST
for (char c : s) cnt[c]++;
vector<string> bucket(n+1);                    // 2) index = frequency; size n+1 (a char can hit freq n!)
for (auto& [ch, f] : cnt) bucket[f].push_back(ch);   // scatter ONCE at final freq (push_back, don't overwrite)
string ans;
for (int f = n; f >= 1; f--)                    // 3) gather high→low
    for (char ch : bucket[f]) ans.append(f, ch);     // append(count, char) — COUNT first!
return ans;
```
Complexity: time **O(n + K)** / space **O(K)** where K = key range. Special cases: **counting sort** (buckets hold counts of equal keys), **radix sort** (bucket-sort chained per digit).
Variants & gotchas:
- **The bucket array is sized by the KEY RANGE, not the # of distinct items.** Here key = frequency ∈ [0,n] → array size **n+1** (boundary: a char can appear n times → index n; start the gather loop at `f=n`, not `n-1`).
- **It's a TIME↔SPACE TRADEOFF, not always an upgrade.** On THIS problem the distinct-char count is bounded (≤~62), so a plain count+sort is ~same time AND uses **less** aux space (O(1) vs the bucket's O(n)). Bucket *wins* only when the key range is small relative to n (e.g. sort 10⁷ ints in [0,100]). **Decide by: does the key range or the element count dominate?**
- **Each slot needs a COLLECTION** (string / vector) — multiple items can share a key. `bucket[f].push_back(...)`, never `bucket[f] = ...` (overwrite loses data).
- C++ idiom: `s.append(count, ch)` repeats a char — args are **(count, char)**, NOT Python's `ch*count`.
Taught me by: P15 / LC451 (derived count-fully-then-place-once myself; debugged my own overwrite, arg-swap, and n-vs-n+1 boundary). Bucket index = the COUNT, not the char.

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
