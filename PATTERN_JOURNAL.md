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
| **CLOSEST / NEAREST sum, or MIN DIFFERENCE to a target** (pair/triplet near a value, not exactly it) | **Sort + two pointers** — order lets you STEER; **NOT hashing** (hash = exact lookup only, no "nearest") |
| longest/shortest **contiguous** subarray/substring | Sliding window |
| **COUNT subarrays with EXACTLY k _____** | `atMost(k) − atMost(k−1)` (each window-friendly), OR transform→prefix+hash |
| sum/count over many ranges; subarray sum = k | Prefix sum (+ hash) |
| sorted, or monotonic yes/no, or minimize-the-max | Binary search (on answer) |
| find a **PEAK** / "which way is uphill" / **a cheap mid-check lets me DISCARD half (even if UNSORTED)** | Binary search — the trigger is **discard-ability, NOT sortedness** |
| **sort/group by a COUNT or frequency; key is an int in a small range** | Bucket / counting sort (index = the key) |
| **key is a SLOPE / RATIO / DIRECTION** (or any value with many equal-looking forms) | **Canonicalize before hashing** — reduce the integer pair by **gcd + fix sign**; NEVER a float key (collides) |
| matching / nesting | Stack |
| next/previous greater or smaller element | Monotonic stack |
| **build the smallest/largest RESULT by removing/keeping items IN ORDER** | **Greedy monotonic build** — a string/stack you pop bigger (or smaller) predecessors from while a removal budget remains |
| max/min of every window size k | Monotonic **deque** — store **INDICES** (front index vs `i-k` tells you what expired); `pop_front` expire + `pop_back` monotonic |
| window validity depends on **max AND min** | **two** monotonic deques (one decreasing, one increasing) |
| **DP transition = max/min over a sliding window of previous states** | deque over the dp array (turns O(n·k) → O(n)) |
| shortest subarray sum ≥ K **with negatives** | monotonic deque over **prefix sums** (window-shrink fails on negatives) |
| cycle / middle / kth-from-end in a list | Fast & slow pointers |
| **problem BREAKS INTO A SMALLER COPY OF ITSELF** (self-similar) + a reachable base | **Recursion** — assume the smaller call is correct (leap of faith), handle ONE layer; natural over a loop when it BRANCHES |
| **a correct recursion TLEs AND the same subproblem recurs** (forking tree, overlap) | **Memoization** — recursion + a notepad: cache each state once (`memo[state]`), impossible-value sentinel = top-down DP. (Straight-line recursion like factorial → memo does nothing) |
| **"count the ways" / "min-max cost over a sequence of choices" + small-ish n** | brute recursion → **memoize** (the DP on-ramp: LC70/198/322) — small n + "try all / count" often SIGNALS exponential |
| **compute x^n / a^b with a HUGE exponent** (n up to ±2³¹, or "mod 1e9+7 power") | **Fast power (binary exponentiation)** — halve the exponent, recurse **ONCE** into a variable (`t=f(e/2); t*t`, odd → extra `x`) → O(log n). ⚠️ write the call TWICE and it's O(n) again |
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
Level: **L4** — solo set LC217/219/347/36 all AC. **Drill 6/10: Q7 (dup within k) named cold as hashing ✓ → the recurring "→2ptr" miss is CLEARED. Q1 (unsorted Two Sum): first instinct still flickered to "sort + two pointers" before recovering to the map.** L5 is one clean unsorted-pair call away — the recognition is right, the FIRST instinct on unsorted-pair isn't fully reflexive yet. **⭐ 2026-06-25 — strong signal toward L5:** **LC219 Contains Dup II re-solved COLD as an INTERLEAVED TRAP** (sat in the *stacks* practice folder). He *felt the wrong tool fighting him* ("the easy method is hashing but how do I do it in stacks?"), **scrapped the stack and routed to hashing himself** — the friction-as-signal that the folder ≠ the tool. Directly attacks the #9 unsorted-pair-→-2ptr reflex from the OTHER side (rejecting a wrong tool, not just naming the right one). (One smudge: a Compile-Error-then-AC = his C++ mechanical gap, not a logic/recognition miss.)
Trigger (in my words): "seen before? / how many times? / look up a complement in O(1) / group by a shared property" → hash map. **GATE: is the data SORTED? If NOT → hashing, not two pointers.**
Why it works: a hash function squashes ANY key (big int, string, negative) into a small array index → keep the array's O(1) access for arbitrary keys. Collisions are UNAVOIDABLE (pigeonhole: more keys than slots) → resolved by chaining (C++ `unordered_map`) or open addressing. Avg O(1); worst O(n) when many keys pile into one bucket.
Template/skeleton: `unordered_map<int,int> cnt; cnt[x]++;` / `unordered_set<int> s; s.count(x);`
Complexity: avg O(1) per op (worst case O(n) on adversarial collisions).
**The 4 hashing sub-patterns I've now seen (recognition map):**
- **Complement / seen-map** (Two Sum, LC1): unsorted + need a pair → store value→index, look up `target-x`. **Look up BEFORE insert** (else self-match) + **return on find**.
- **Frequency count** (Valid Anagram LC242): count chars; fixed small alphabet → `int[26]` (inc for s, dec for t, all-zero check); **unbounded/Unicode keys → switch to `unordered_map`** (the follow-up). Container changes with the key space.
- **Group / dedup by canonical KEY** (Group Anagrams LC49): compute one fingerprint per item so matches collide → `unordered_map<Key, vector<...>>`, `groups[key].push_back(item)`. Key = sorted string O(k log k) OR 26-count signature O(k). Kills O(n²) pairwise compare → O(n·k log k). No visited/include-self bookkeeping needed.

**⭐ CANONICAL KEY via gcd — SLOPE/RATIO/DIRECTION hashing (LC149 Max Points on a Line, HARD gauntlet P1, 2026-07):** cue in **his own words** — *"if the key to hash is a fraction/ratio/direction, ask: can two different-LOOKING values secretly mean the same thing (equal after dividing by some number)? If yes → reduce by gcd first."* The unlock he FELT: fixing an **anchor** point, group the rest by the **slope** they make with it → biggest bucket + 1 (the anchor itself, never in its own bucket) = most collinear. Two death-traps, both self-discovered by tracing his OWN hostile inputs: **(1) `float slope = int/int`** — int division TRUNCATES toward zero (`1/2`,`1/4`,`5/3`→`0,0,1`) so distinct slopes collapse → PHANTOM lines (traced `[[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]` → his code said 5, truth 4); even real floats COLLIDE on precision. **(2) patching the key with special cases** (map vertical `dx==0`→slope `1.0`) just springs a NEW leak — vertical then collides with a real slope-1 line (`[[0,0],[1,1],[0,5]]` → said 3, truth 2). **THE FIX kills the whole bug class: key = the reduced integer pair `(dy/g, dx/g)`, `g=gcd(dy,dx)`, NOT a number.** gcd strips MAGNITUDE (how far along the line) and keeps DIRECTION (which line) — `(2,1),(4,2),(6,3)` are one arrow at 3 lengths → all reduce to `(2,1)`. **Sign-normalize** so `(2,1)` and `(-2,-1)` (same line, opposite arrows) collapse — force `dx>0`, or if `dx==0` force `dy>0`. **Vertical is NOT a special case anymore**: `(dy,0)`→gcd→`(1,0)`, and no finite slope ever has `dx==0`, so it can't collide — just DELETE the `if(dx==0) continue`. General trigger (transfers to number theory / reduced fractions / "group by ratio"): **many representations → pick ONE canonical form → then hash.** Same instinct as sorting an anagram's letters before hashing. **Anti-pattern banked: a single float can't carry a 2-D thing (direction); collisions are then unavoidable — use the pair.** _(Brute oracle = cross product `(pj−pi)×(pk−pi)==0` for collinearity, division-free, AC.)_ Optimal grind IN PROGRESS — gcd-pair rewrite being coded; judge-AC pending.
- **Set membership for O(1) reasoning** (Longest Consecutive LC128): hash SET avoids sorting; to keep a per-element walk linear, only START work from sequence beginnings (`x` is a start iff `x-1` not in set) → O(n) not O(n²). **(P20 re-solve 2026-06-20: AC, but TLE'd FIRST — the outer loop ran over `nums` WITH DUPLICATES, re-walking a run once per duplicate copy of its start (`[1,1,1,1,2,3,4]` → O(n²)). FIX = iterate the deduped SET, not the raw array. Also: use `unordered_set` for presence, not `unordered_map`. And the brute's "sort+scan" is O(n log n) — he thought `sort = O(log n)`; corrected: binary SEARCH = log n, SORT = n log n.)**
Variants & gotchas: the complement-lookup move (Two Sum) = the core of all the prefix+hash problems.
**Recognition (the gap the 6/8 drill exposed — 0/2 on hashing):** these are HASHING, *not* two pointers:
- **Unsorted** array, need a pair summing to target, return INDICES → store value→index, look up `target-x` (LC1).
- "Have I **seen this value**, and where?" → map value→last index (e.g. duplicate within distance k, LC219: check `i-last≤k`).
- Membership / first-or-count of anything → set or freq map.
RULE: unsorted + pair/duplicate/complement ⇒ hash map (two pointers needs SORTED data).
Taught me by: LC3 (unordered_set), the whole M5 prefix+hash family; 6/8 drill flagged the recognition gap. NEXT: formal lesson + LC1 Two Sum.

### Two Pointers
Level: **L4 (converging) 2026-06-09** — LC167 clean solo + LC11 Container largely his. Full notes: `phase-1/notes/03`. GAPS: Dutch-flag re-code, boundary reflex, L5. **Drill 6/10: Q2 (sorted pair) clean ✓ BUT Q1 (UNSORTED pair) over-fired here — reached for two pointers when the data isn't sorted. The disqualifier check ("is it sorted? loses indices?") isn't automatic yet. L5 held: fix the OVER-application, the twin of the hashing under-fire.**
Trigger: the REAL rule is a **provably-safe move** (discarding one side never loses the answer). SORTED enables that for **sum/pair** problems — but it's NOT the only enabler (Container/Trapping are UNSORTED, use "move the limiting side"). Quick screen: "sorted + pair by sum?".
⚠️ **GATE for the PAIR-SUM family: is it SORTED?** If NOT sorted → **HASHING**, not two pointers. (My #1 recognition leak — see MISTAKE #6.) But "two pointers" ≠ "needs sorted" in general.
Why it works: a provable safe-discard each step → O(n). For sums: too-big drops the largest. For Container: shorter wall caps area, so move it.
The 3 shapes: **converging** (opposite ends — sum-steered or greedy) · **fast/slow** (read/write in place) · **fix-one + two-pointer** (3Sum). Plus **Dutch flag** (3-way partition, low/mid/high — left-known/right-unknown asymmetry: advance mid on a 0-swap, NOT on a 2-swap).
**⚠️ CLOSEST / NEAREST sum — the HASHING-vs-ORDER gate (P22/LC16 3Sum Closest, 2026-06-21):** cue = "pick a pair/triplet whose sum is **closest** to a target (min `|sum−target|`), return the SUM not the indices." He first reached for a **hash map** — KILLED it himself via the trace `{3,7,9,14,20}` goal 10: a hash map answers *"is this EXACT value present?"* in O(1) but has **no order**, so finding the **NEAREST** key costs a full scan. **"Closest/nearest" needs ORDER → sort + fix-one + converging two pointers**, steered by sum vs target: `sum<target → lo++` (grow), `sum>target → hi--` (shrink), `sum==target → return` (distance 0, can't beat). Track best with a SEPARATE distance var (`compare=INT_MAX`, `ans` follows) so the first triplet always wins — he used this cleanly. O(n²) time / O(1) space. **Leaks that fired (NOT first-submit-clean):** (1) brute dropped the "**distinct indices**" constraint (loops from 0 → fixed with `j=i+1,k=j+1`; same constraint-drop family as P19 whole-array); (2) **named pointers backwards** (`l`=high, `r`=low) → moved the WRONG pointer → OOB, then inverted the `while` guard. LESSON: name pointers `lo`/`hi` by ROLE so the direction logic reads itself; a naming flip MANUFACTURES bugs.
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
(fixed window + freq-match, incremental slide)** + **LC438 Find All Anagrams (P18) — fixed window + two
26-count arrays**. **Order rule learned:** include → restore-validity → record
(record only when window is valid). Fixed-window: slide unconditionally, compare after.
**⚠️ FIXED-WINDOW ANAGRAM/PERMUTATION RECOGNITION (P18/LC438, 2026-06-19):** cue = "fixed length `m`,
is this window an **anagram / permutation / same multiset** as a target?" → **drop the sort, keep two
`int[26]` count arrays**: P (frozen counts of the target, never changes) and W (live counts of the current
window in s — mutate it: `--` the char leaving, `++` the char entering). Match ⇔ all 26 buckets equal
(`k==26`, NOT `k==m` — you compare BUCKETS not length; classic leftover-from-brute bug). Per-slide cost
O(26)=O(1) → total **O(n)**, space O(1) (two const-size arrays — say what they are, don't claim "no extra").
**THE BOUNDARY LESSON (his #1 leak, caught again):** a **check-then-advance** loop checks an element ONE
iteration AFTER it's brought in, so the loop must run **one step past** the final add — AND that extra step
must check, then **guard the trailing add** so it doesn't read off the end (`if(r>=n) break;` before the
`++`). Twin fix = flip to **add-first-then-check** so the window is always complete when you look (no
trailing add to guard). Note `r<=n-1` ≡ `r<n` — same bug, no change. GOOD: he added `if(n<m) return {}`
unprompted — boundary muscle firing on its own.
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
**⭐ DESIGN PRINCIPLE — "DERIVE STATE, DON'T MAINTAIN IT" (P23/LC904 ≤2-distinct, 2026-06-22):** he AC'd a
hand-rolled last-index-map variant (`sum`++/--, `key`+`target_remove` min-scan, compound `while(l<=r&&r<n)`,
pre-seeding) — **6 variables to keep in sync** = the bug engine. The clean canonical window cuts it to **2**.
**The rule, his words:** "**one driver, one invariant, derive the rest.**" Concretely: (1) `for r` is the ONE
driver — marches the right edge once, no compound loop, no pre-seed; (2) the inner `while` restores the ONE
invariant the growth broke (here `count.size()>2`); (3) the **data structure owns removal** — `type→count`
map, a type leaves on its own when `--count==0` → no `key`/`target_remove` min-scan; (4) **length is DERIVED**
= `r-l+1` → kill the `sum` variable and its ++/--/decrement-loop entirely. `ans=0` (window always ≥1 elem, no
INT_MIN). **THE META-CUE (schedule it):** *when a solution has variables that must agree with each other, ask
which you can DELETE by deriving them* (length from l,r · distinct-count from map.size()). Fewer maintained
vars → smaller edge-case surface → cleaner first submit. **Canonical shape:** grow(r) → while(invariant
broken) shrink(l) → record `r-l+1`. Use this for EVERY "longest/shortest window with constraint X".
Taught the principle on: **LC904 Fruit Into Baskets (P23)** — recognition was instant (he's L5), the leak was
EXECUTION via over-engineering, not the pattern.

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
**⚠️ REMOVE-A-SUBARRAY-TO-MAKE-DIVISIBLE (P19/LC1590, AC 2026-06-20):** "remove the SHORTEST subarray so the
LEFTOVER sum % p == 0." THE REDUCTION (where I fell in the trap twice): `(S − X) % p == 0 ⟺ X % p == S % p`,
so set `target = S % p` and **find the shortest subarray whose sum % p == target** (NOT sum == target — that
DROPS THE MOD; and NOT "divisible/target 0" — that's the LC974 special case). Then it's LC560 with `%p` on the
key: store **prefix residue → latest index**, and for current residue `cur`, look up `need = (cur − target + p) % p`
(the LC974 negative-normalize: `+p` rotates one full lap into `[0,p)` so it matches stored keys). Length of the
removed chunk = `r − seen[need]` (difference of the two prefix INDICES = the subarray between them; `seen[need]`
is a position, not a subarray). **The 3 guards (all my boundary family, owed overnight):** (1) `target==0 → return 0`
(already divisible, remove nothing/empty); (2) **forbid whole-array removal** — the full prefix always has residue
== target so it's ALWAYS a fake length-`n` "winner"; end with `return ans < n ? ans : -1` (kills both the illegal
n-length answer AND the unfound INT_MAX in one shot); (3) overflow: `accumulate(...,0LL)` — the SEED's type
decides the accumulation type (int seed → overflows before assigning to long long). **Bugs caught in review:**
`unordered_set<int,int>` used like a map (set/map family-leak — needs `unordered_map`); stored `seen[need]=r`
instead of `seen[cur]=r` (filed current index under the looked-up residue, not its OWN residue); missing `seen[0]=-1`
seed. **THE TRANSFER WIN:** he saw it's "LC560 refactored with %p for the hashmap" — same machine, mod wrapped
around the key. **THE DEFENSE (re-stated, MISTAKE #12-ish, reduction trap):** before marrying a reduction, attack
it with a HOSTILE input (an element > p, e.g. `[8,1,2,7], p=7`); hand-run the ORIGINAL and the REDUCED problem — if
they disagree, the reduction dropped something (here: the mod).

### Binary Search (incl. on answer)
Level: **L4 EARNED 2026-06-10** — LC34 (first/last) + LC875 (Koko, search-on-answer) mediums AC, on top of LC704/35 easies. Recognition independent on both. Support on Koko was a PRIMITIVE (integer-overflow magnitude), not the pattern. Drill 6/10 Q5/Q6 (search-on-answer + rotated) named cold — L5 HELD only because it's same-day as L4 (cadence: don't test transfer the day you reach the level). Full notes: `phase-1/notes/06`.
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
**Rotated array (LC33) — AC 2026-06-25, FIRST-SUBMIT CLEAN, recognized cold:** at each mid, ONE half is always sorted — **find the sorted half** (`nums[lo] <= nums[mid]` → left half sorted, else right), then test **if target lies inside that sorted half's KNOWN range** (`nums[lo] <= target < nums[mid]`); if yes search it, else the other. The range-check is what makes the discard provably safe — NOT just "compare first/last to mid." Still O(log n). (Closed a 2-week-open BS leak; was on the discard-ability ladder w/ LC852/LC540.)
**⚠️ BINARY SEARCH ON AN *UNSORTED* ARRAY — trigger = DISCARD-ABILITY, not SORTED (P21/LC162 Find Peak, 2026-06-20):** the array is NOT sorted, yet it's binary search. **The real BS trigger is: "is there a cheap check at `mid` that tells me which half CANNOT hold the answer, so I throw it away?"** Sorted is just ONE way to get that check; here the **slope** gives it. At `mid`, compare `nums[mid]` vs `nums[mid+1]` (never equal — "no two adjacent equal" gift): if `nums[mid] < nums[mid+1]` (uphill right) a peak is GUARANTEED to the right → `l=mid+1`; else `r=mid`. WHY it's safe (not a guess): climbing uphill must end in a peak — either you keep rising to the boundary (beyond it is −∞) or the slope turns down (a peak). The other gift, "**a peak always exists**", is what lets you always pick a half. **Clean code: `while(l<r){ mid=l+(r-l)/2; if(nums[mid]<nums[mid+1]) l=mid+1; else r=mid; } return l;`** — `l<r` (NOT `<=`) converges instead of collapsing; only `mid+1` referenced (always valid since `mid<r≤n-1`); no `mid-1`, no `n==1` special case. **His bug = `while(l<=r)` + both `mid±1` → OOB at both ends** (see MISTAKE watchlist). O(log n).
**⭐ FIND-MIN-IN-ROTATED + the EXACT-vs-BOUNDARY template split (P24/LC153, 2026-06-22):** another discard-ability win — array is sorted-then-rotated, the min sits at the one "drop." **Locate the drop by comparing `nums[mid]` to `nums[right]`** (NOT to neighbors, NOT to `left` — `right` is unambiguous): `nums[mid] > nums[right]` → the drop is to the RIGHT, `l=mid+1`; else `mid..right` is clean-sorted so the min is at `mid` or left → `r=mid`. ONE binary search (his misconception was "two BS, one per side" — no). **THE TEMPLATE-SPLIT LESSON (his #1 boundary leak, root-caused at last):** he reached for the **exact-target** shape (`while(l<=r)`, `r=mid-1`) which *rules mid out* — but in a **boundary/extremum search mid MIGHT BE the answer**, so `r=mid-1` discarded the min (`[3,1,2]→3`). He then **band-aided** it with an `ans=min(...)` tracker (the bolt-on reflex) before getting to the clean form. **THE RULE — decide by "could `mid` itself be the answer?":** YES → boundary search → **`while(l<r)`, keep `mid` (`r=mid`), `return nums[l]`** (pointers CONVERGE on the answer, no `ans` var — *derive-don't-maintain*); NO → exact-target → **`while(l<=r)`, `mid±1`**. Clean: `int l=0,r=n-1; while(l<r){int m=l+(r-l)/2; if(nums[m]>nums[r]) l=m+1; else r=m;} return nums[l];` **Stress-proven: 100k random rotations, optimal==brute.** Ladder mate (LC153 was on the 6/23 discard-ability set, done early). O(log n).
**SEARCH-ON-ANSWER — the universal brute→optimal (P16/LC1011, 2026-06-17):** the BRUTE for *any* search-on-answer is **linearly try every candidate answer + a feasibility check**; the OPTIMAL is **binary-search the candidate** because feasibility is monotonic (NO-NO-NO-YES-YES). Brute & optimal **share the exact same `feasible()`** — only the outer search changes (O(range)·n → O(n·log range)). **The feasibility function is PROBLEM-SPECIFIC — don't import it:** Koko's piles are *divisible* → `feasible(k)=Σceil(pile/k)≤h`; ship packages (LC1011) are *indivisible & in-order* → feasibility is a **greedy consecutive day-count** (`days=1, load=0; for w: if load+w>cap {days++; load=0;} load+=w; feasible ⇔ days≤D`). Using `ceil(sum/cap)` for ships is WRONG (it pretends you can split/repack — counterexample `[3,4,3]`, cap 5: ceil=2 but real greedy=3 days). Range for ship = `[*max_element, accumulate(...)]` (capacity must hold the heaviest single package; one-day upper bound = total). Direction knob: `feasible(mid)` TRUE → store + shrink right (`end=mid-1`); FALSE → `start=mid+1`.
Taught me by: LC704 (exact), LC35 (lower bound), LC34 (first/last), **LC875 Koko (search-on-answer + the overflow lesson, see MISTAKE #8)** AC, **LC1011 Capacity to Ship (search-on-answer; derived the greedy day-count feasibility himself, debugged the trailing-day boundary bug)** AC. Rotated/2D/split-array pending.

### Stack (plain LIFO)
Level: **L3 EARNED 2026-06-22** — LC20 Valid Parentheses coded from memory, **AC on judge**. (Heavy execution coaching on boundaries, so NOT cold/independent — L3 is "coded from memory", which this is; L4 still owed via more solo reps.)
Trigger (WHEN to use): "**matching / nesting / balanced**" or "the **most recent unmatched** thing decides" → stack. Brackets, undo, browser-back, anything LIFO.
Why it works: holds the unresolved items in order, most-recent on top — exactly what a closer/next-item needs to check. Beats a COUNTER: a counter handles ONE bracket type but fails on mixed types (`([)]` counts to 0 yet is invalid) because it forgets WHICH opener is most recent.
Template/skeleton: `stack<char> st;` push openers; on closer, `st.empty()||st.top()!=match → false`, else pop. Balanced ⇔ stack empty at end. All ops O(1).
Complexity: O(n) time / O(n) space.
**⚠️ VALID PARENTHESES — the 3 leaks that fired (LC20, 2026-06-22):**
1. **"Match" ≠ "equal".** First instinct was `if(s[i] != poppedOpen) return false;` — but a close bracket is **never the same char as its opener** (`')' != '('` is always TRUE). The check is "is the popped open the **PARTNER** of this close?", not equality. He read `)` and `(` as "same" because they pair in his head; the computer sees two different symbols. (Caught by tracing his code on `"()"` → it returned false on the simplest valid string.)
2. **Empty-stack-on-close (boundary).** A lone `")"` runs `top()/pop()` on an empty stack → UB. Guard `if(st.empty()) return false;` **before** reading, at the start of the close branch — not just an end-check.
3. **Leftover opens (the ANSWER edge).** `"("` pushes and falls through to `return true` — wrong. Must end with `return st.empty();` (everything must have matched). He fixed #3 but initially missed it was separate from #2 — **both** boundary traps live in this one problem.
**META:** logic was right after the partner fix; *everything else was boundaries* (his #1 leak). The catches were coached (I pointed at each via Gate C); the rep to grow = running the 4 boundary edges on himself BEFORE calling it done. C++ gaps surfaced → CPP_GAPS #6 (`stack::pop()` returns void), #7 (`string::find`→npos), #8 (char vs string literal).
Variants & gotchas: carry extra state on the stack when needed. Empty-stack check BEFORE top()/pop() (boundary!). Brute oracle for bracket validity = **repeated removal** (erase any `"()"/"[]"/"{}"`, loop till no change, valid ⇔ empty) — dead-simple & obviously correct, the whole point of a brute oracle.
**⭐ MIN STACK (LC155, AC 2026-06-25) — O(1) getMin via a LOCKSTEP auxiliary stack:** cue = "stack + retrieve an aggregate (min/max) in O(1)." **DON'T keep a single `min` int** (it can't *recover* the previous min after you pop the current min) and **DON'T keep a sorted structure** (O(n) insert + ambiguous which copy to delete on pop). **The trick: a second `minStack` that grows/shrinks in LOCKSTEP — same size as the main stack, always.** On `push(v)`: `minStack.push(min(v, minStack.top()))` (or `v` if empty). On `pop()`: pop BOTH. `getMin()` = `minStack.back()` — auto-correct, zero scan, because popping the main also pops the min and exposes the prior min underneath. All ops O(1), space O(n). **His boundary edge (self-caught by trace → first-submit clean):** the "first element / minStack empty" branch — guard it as `if(mainStack.size()==1)` (or `minStack.empty()`) BEFORE reading `minStack.back()`, else `minStack[size()-1]` on an empty vector (size is UNSIGNED → `0-1` = huge) is OOB. C++ note: `top()`/`getMin()` must READ (`.back()`), never `.erase()`; pop = `pop_back()`, not `erase(index)`.
Taught me by: theory + Striver [297][298][300] + **LC20 Valid Parentheses (P-learn 07-01, AC) = L3**. Next: monotonic stack (Daily Temperatures) for M7 → L4.

### Monotonic Stack
Level: **L4 EARNED 2026-06-25** — **LC739 Daily Temps + LC503 NGE II both judge-AC** (MCP-confirmed), recognition independent, recording-rule reflex clean. Prior: NGE warm-up coded from memory **100k stress GREEN** (L3, 6/23); concept rebuilt closed-book (WHY/why-monotonic/amortization in his words). **CIRCULAR (NGE II / LC503) owned cold:** loop `i` over `[0, 2n-1)`, read `nums[i%n]`, and **only push on lap 1 (`if(i<n) push(i)`)** — lap 2 is read-only-for-resolving, *closed for new business* (his teach-it-back, Q3: every element already had its one shot as a waiter on lap 1; pushing again makes a phantom duplicate that can never honestly resolve). His own words locked the cue.
**⭐ THE RECORDING RULE (the execution cue that locks it):** pre-fill `vector<int> ans(n, -1)`; when a newcomer pops a waiter, write the answer **at the waiter's OWN slot** → `ans[st.top()] = <value or distance>`, THEN pop. **Never `push_back`** — elements pop in resolution order, so appending lands answers at the wrong positions (pop-order ≠ position-order). Pre-sizing to the default also deletes the trailing leftover loop (leftovers are already `-1`/`0`).
**⚠️ THE 3 OPTIMAL BUGS beaten (NGE warm-up, 2026-06-23) — all EXECUTION, concept was right:**
1. **`if` vs `while`.** A newcomer resolves a BATCH (the `5` in `[3,1,2,5,4]` pops both `2` and `3`). Must be `while(!st.empty() && nums[i] > nums[st.top()])`.
2. **Push the INDEX, not the value.** `st.push(i)`, never `st.push(nums[i])` — else `nums[st.top()]` reads OOB. Stack holds indices; derive value (`nums[j]`) and distance (`i-j`).
3. **Write at the SLOT, don't append in pop-order.** `ans(n,-1)` + `ans[st.top()]=...` (the recording rule above).
**⚠️ DAILY TEMPERATURES (LC739, 2026-06-23) — the distance twist + premature-"done" ×3:** same engine, but record `i - st.top()` (the WAIT, a **distance**), not the value. **Gate A caught the pos-vs-distance restate AGAIN** (he said "find the POSITION of the warmer day" — same slip as 6/22; the gentle example `[73,74,71]` hid it because distance==index there; the hostile `[72,71,76]` exposed it: position 2 ≠ wait 1). Then the **premature-"done" leak fired 3 times**: fixed brute (`push_back` onto a pre-sized vector + `j-i+1` off-by-one → `ans[i]=j-i`) but asked "check"; fixed the optimal subtraction (`top-i` negative → `i-top`) but LEFT the inverted comparison (`t[i] < t[top]` should be `>`); each time a hand-trace on `[72,71,76]` surfaced the still-live bug. Brute+optimal both **100k stress GREEN + canonical `[73,74,75,71,69,72,76,73]→[1,1,4,2,1,1,0,0]`** — **judge-AC PENDING** (MCP not signed in this session, 403 on submit; he submits in browser).
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
Variants & gotchas: direction (next vs previous) = scan L→R vs R→L; greater vs smaller = flip the `>` and the stack's monotonic direction; circular array (NGE II) = loop `i` over `2n` with `%n`, push only on lap 1. Strict vs non-strict (`>` vs `>=`) matters for duplicates (subarray-min problems).
**✅ 132 PATTERN (LC456, AC 2026-06-25) — the "track the best middle value" variant (⭐ RE-DERIVED COLD 2026-06-30 — debt cleared; he rebuilt the engine from the bottleneck up, NO hints. His own teach-it-back cue: _"find `i<j<k` where the MIDDLE index has the biggest value, last index in-between, order matters so I can't sort → right-to-left + stack + best2. Because I want the BIGGEST possible '2' — a bigger '2' gives more room to find a smaller '1' easily. Stack remembers candidate '3's (peaks); best2 remembers the biggest confirmed '2'; win when current < best2 → it's the '1'."_ He also SELF-AUDITED mid-derive — asked "won't a single adjacent compare miss stacked numbers?" → confirmed it's a WHILE loop popping ALL smaller, best2 = LARGEST of the batch, stack stays monotonic so best2 IS the memory. Ownership, not recall.):** cue = "find indices `i<j<k` (ANY positions, a *subsequence*, NOT adjacent) with a **value** pattern — here `nums[i] < nums[k] < nums[j]` = low, then a PEAK, then a value caught IN BETWEEN (NOT increasing — it dips back down)." **The unlock = don't hunt all three (O(n³)); FIX the "2" (the middle value) and let a monotonic stack surface it.** Key realization: **an element becomes a confirmed "2" the moment a BIGGER element appears to its right** (that bigger one is its "3"). **Scan RIGHT→LEFT**, stack of candidate "3"s (peaks, decreasing); when a bigger newcomer pops smaller values, each popped value is a confirmed "2" → keep the **largest** as `best2`. Then for each element: **if `nums[i] < best2` → return TRUE** (it's the "1"). **Execution trap (his bug): check `nums[i] < best2` FIRST, *then* pop/push** — flip the order and an element can be its own "2." His other bug = the **`!(chk.size()>0)` negation** (wrote "empty" where he meant "non-empty" → loop never popped + `.top()` on empty UB) — same boundary/condition family, caught via self-trace (WA→AC). O(n) / O(n).
**⚠️ READING TRAP (132, his miss): index order ≠ value order.** He read "132 pattern" as "3 consecutive increasing." Killed via `[1,2,3,4]` → his reading says TRUE, real answer FALSE (strictly increasing can never put the MIDDLE value last). And the indices are a *subsequence* — `[3,5,0,3,4]` answers TRUE via `i=0,j=1,k=4` (0,1,4 NOT adjacent). Rule banked: **`i<j<k` alone = ANY positions in order; adjacency is a restriction problems always spell out ("subarray/contiguous/consecutive"), never imply.**
**⭐ GREEDY MONOTONIC BUILD (LC402 Remove K Digits, judge-AC 2026-06-29) — the "construct the optimal result digit-by-digit" variant:** cue (his words, banked) = **"build the smallest/largest RESULT by removing/keeping items IN ORDER."** Unlock he DERIVED BY HAND off `1432219,k=3`→`[1,2,1,9]`→"1219": scanning L→R, **a big digit in a HIGH place hurts most**, so while you still have removals (`k>0`) and the incoming digit is SMALLER than the stack top, **pop the bigger predecessor** — the survivors form a monotonic-**increasing** stack, and that stack IS the answer (he saw "the result-list I'm building is the monotonic stack" before it was named). **THE 3 END-TRAPS:** (1) **leftover k** after the pass → trim from the END (the tail is the largest survivors); (2) **leading zeros** → strip from the FRONT (`"10200",k=1`→`"0200"`→`"200"`; **trailing zeros are KEPT** — low place, harmless); (3) **empty result** → return `"0"`. ⚠️ **MAGNITUDE LEAK FIRED:** result can be 1e5 digits → **never `stoi`/`stol`** it (RE `out_of_range`); do the empty/all-zero check string-only (`.empty()`). O(n)/O(n) — already optimal, can't beat. **Cleaner shape (DEFERRED refactor he derived):** use a `string` AS the stack — `push_back` survivors, `pop_back` on a pop, `back()` for top → builds in order, **kills the reverse + the index indirection**. (Brute oracle = bitmask subset enumeration over all keep-(n-k) subsequences — primitive learned just-in-time: `mask&(1<<i)` + `__builtin_popcount`.)
Taught me by: theory + **generic NGE warm-up (100k stress green) = L3 (6/23)** + **LC739 Daily Temperatures (distance variant) + LC503 NGE II (circular) both judge-AC = L4 (6/25)** + **LC456 132 Pattern (track-best-2 R→L, over-revealed, re-derive owed)** + **LC402 Remove K Digits (greedy build, judge-AC 6/29)**; Striver [301][303][302][311]. Next for depth: Stock Span (LC901, previous-greater + span count) + **P5 LC84 histogram-area (in progress — the canonical hard)**.

### Monotonic Deque  (M8 · LC239 Sliding Window Maximum, 2026-07-04)
Level: **L3 EARNED 2026-07-04** — LC239 judge-AC + 20k stress-green + gate explained in his words. Twin of the monotonic stack, second eviction from the front because the window moves.
Trigger (his words): **"max/min of every window of size k → monotonic deque, O(n)."** Also: window validity that needs max AND min (two deques); a DP transition that's "max/min over the last k states" (deque over dp); shortest-subarray-sum-≥K-with-negatives (deque over prefix sums).
**⭐ THE UNLOCK he hit (and it TRANSFERRED from the monotonic stack): store INDICES, not values.** He got stuck on "how do I drop the front?" — his gut correctly refused a counter ("counters make the code worse" = his derive-don't-maintain reflex). The fix: the deque holds indices, so the **front index vs `i-k`** tells you when the front has slid out — you *derive* expiry, no counter. His words: _"the current index and front index comparison is great — if front index `<= i-k` that means it's past the min eligible window limit, then we pop."_ Killed by the hostile trace `[5,3,1,2],k=3` (values-only deque wrongly reports `[5,5]` because it can't tell the 5 at index 0 expired; truth `[5,3]`).
**The 3 moves each step `i` (order matters):**
1. **Expire front:** `while(dq.size() && dq.front() <= i-k) dq.pop_front();`  (⚠️ exact edge = `<= i-k`, not `< i-k`; window ending at `i` is `[i-k+1 .. i]`)
2. **Enter back:** `while(dq.size() && nums[dq.back()] < nums[i]) dq.pop_back();` then `dq.push_back(i);`
3. **Record:** `if(i >= k-1) ans.push_back(nums[dq.front()]);`
Why front = max: the `pop_back` loop keeps values **decreasing front→back**, so front is the max by construction. Why O(n): each index enters once and leaves once → ≤ 2n ops total (his LC232 amortized argument, reused verbatim).
```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; vector<int> ans;          // dq holds INDICES, vals decreasing
    for (int i = 0; i < (int)nums.size(); i++) {
        if (dq.size() && dq.front() <= i-k) dq.pop_front();
        while (dq.size() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k-1) ans.push_back(nums[dq.front()]);
    }
    return ans;                              // window MIN: flip back-pop to '>'
}
```
Stack vs deque line: **unbounded** next/previous greater → monotonic **stack**; extreme inside a **moving bounded window** → monotonic **deque**.
Taught me by: LC232 (two-stack FIFO, amortized O(1)) + LC933 (front-expiry queue) mechanics → **LC239 gate (judge-AC + stress-green) = L3**. Striver [297][312]. **Practice queued** (`phase-2/practice/08-Queues-Deque/`): LC622 ring buffer · LC1438 two-deque · LC862 deque-over-prefix (unlocks the parked hard) · LC1696 deque-over-DP.

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

### Fast Power / Binary Exponentiation  (M9 · LC50 Pow(x,n), 2026-07-07)
Level: **L3 EARNED 2026-07-07** — LC50 judge-AC (boss reports) + 20k stress-green vs iterative oracle. The recursion module's marquee "halve the problem" rep.
Trigger (his words): **"O(n) → O(log n) collapse because each recursion halves n."** Surface cue: compute x^n / a^b where the exponent can be huge (±2³¹, or "answer mod 1e9+7" in contest form) — repeated multiplication is a scale wall by design.
Why it works: `x^n = (x^(n/2))²` — one squaring replaces half the multiplications, every level. ~31 calls at n=2³¹ instead of 2.1 billion. Odd exponent leaves ONE stray `x` to glue on after the square; negative n = `1 / x^|n|`.
Template/skeleton:
```cpp
double getpow(double x, long long e){        // e ≥ 0, long long on purpose
    if(e==0) return 1;
    if(e==1) return x;
    double t = getpow(x, e/2);               // ⭐ call ONCE, hold it
    if(e%2) return x * t * t;                // odd → one leftover x
    else return t * t;
}
double myPow(double x, int n) {
    long long p = n;                          // WIDEN first (INT_MIN trap, M#4)
    if(p<0) p = -p;                           // negate second
    double result = getpow(x, p);
    return n<0 ? 1.0/result : result;
}
```
Complexity: time **O(log n)** · space **O(log n)** call stack (iterative bit-loop version = O(1), see the oracle in the LC50 file).
Variants & gotchas (all three paid for in blood, 2026-07-06/07):
- **⭐ THE TWO-CALL TRAP (his TLE):** `return getpow(x,e/2) * getpow(x,e/2);` runs BOTH calls — the machine can't see they're equal. Calls double per level while e halves → the doubling cancels the halving → **O(n) wearing an O(log n) costume** (T(e)=2T(e/2)+1 = O(e); ~4 billion calls at n=2³¹). His words: *"calling recursion in multiple places made multiple calls where we can just use one time response."* **Fast power wins by halving the WORK, not just the exponent — recurse once per level.**
- **MEMO ≠ the fix here (his MLE):** the fixed recursion visits each exponent ONCE (straight chain e, e/2, e/4…1) → a memo gets ZERO hits while `vector(n)` at n=2³¹ costs ~17 GB. **A memo earns its memory by HITS (forking tree + overlap, like fib). Repeated work on ONE LINE needs a variable, not a table.**
- **INT_MIN negation (M#4, re-test PASSED here unprompted):** widen to `long long` BEFORE flipping the sign — `abs(n)` on the int is UB at −2³¹.
- Doubles: compare with tolerance in tests, never `==`; oracle = your own binary-power, not `std::pow` (different rounding).
Taught me by: LC50 (M9 practice Q3) — brute TLE by design → derived the halving from "2¹⁰ = 32×32" → hit the two-call TLE live → counted the call tree → t-variable fix → memo detour killed by counting cache hits → AC. Related: LC231 power-of-two (halving twin), memoization entry above (when a table IS right).

### Recursion→Memo DP On-Ramp — "choose or skip" on a line  (M9 · LC746 + LC198, ACs 2026-07-07, entry banked 2026-07-08)
Level: **L3** — both judge-AC 7/07 (commits 5d7aee4/6a8e157); entry backfilled at 7/08 endsession from the commit record. _Teach-it-back in his own live words still owed — fold into the 7/11 recall._
Trigger: **linear sequence + at each position a CHOICE (take/skip, 1-or-2 step) + "min cost / max value / count ways" → brute recursion first, then JUSTIFY the memo by naming the overlap** (the same state reachable by different choice paths → forking tree → hits).
Why it works: the answer from position i depends only on answers from a few positions ahead — self-similar subproblems; overlap (fork) is what makes the memo pay (contrast: fast-power's chain, zero hits — M#7).
His derivation on LC198 (from the commit log): **non-standard ALWAYS-TAKE recurrence `f(i) = nums[i] + max(f(i+2), f(i+3))`** — every house is taken as a start candidate, and he **PROVED the gap never needs to exceed 3 when nums≥0** (skipping 3+ leaves a takeable house you'd always rather rob). Answer = max(f(0), f(1), f(2))-style seed. Not the textbook rob/skip pair — his own machine, stress-proven 500k vs brute.
Complexity: brute O(2ⁿ)-ish fork → memo **O(n)** time / O(n) space.
Variants & gotchas:
- **Name the overlap BEFORE reaching for the memo** (M#2/M#7 discipline — both re-tests held on these two problems).
- LC746 twist: can start at step 0 or 1, "top" = one past the last index — the ANSWER edge lives at the seed/return, not the recursion.
- Greedy is the siren on these (LC746 fired a greedy→recursion turnaround before the brute).
Taught me by: LC746 (brute recursion + memo, boss-derived) · LC198 (the always-take recurrence + gap≤3 proof). Related: LC70/LC1137 (count-ways fib family), memoization entry, fast-power entry (when a memo is WRONG).

### Fast & Slow Pointers
Level: L0
Trigger:
Why it works:
Template/skeleton:
Complexity:
Variants & gotchas:
Taught me by:

### Backtracking
Level: **L3** (2026-07-10 — LC78 Subsets, un-choose derived from his own bug)
Trigger: "return ALL X" / "every possible combination" / "enumerate all ways" — an answer that is a
  COLLECTION of built things, not one number. Each element/slot has a small set of choices, and the
  choices compose into a tree. If the answer is one number → think DP/greedy. If it's a LIST of
  built objects → backtracking.
Why it works: one shared `path` array walks the whole 2ⁿ tree without copying, because **every frame
  leaves the world exactly as it found it.** Touch `path`, put it back.
**⭐ THE INVARIANT — boss's own words (2026-07-10, derived from his own bug):**
  > *"if we go to next call with a state and come back then we should have same state of sett"*
  That sentence IS backtracking. Everything else is bookkeeping.
Template/skeleton (choose→explore→un-choose):
```cpp
void solve(int i) {
    if (i == n) { ans.push_back(path); return; }   // base: path is one finished answer
    path.push_back(nums[i]);   // CHOOSE
    solve(i + 1);              // EXPLORE
    path.pop_back();           // UN-CHOOSE  <- restores the invariant
    solve(i + 1);              // the other branch, on a clean path
}
```
  The push and the pop sit in a **straight line in the SAME frame**, pop AFTER the recursion returns.
  Frame `i` owns the decision about `nums[i]`. The root is just `solve(0)` — no special case.
Complexity: O(2ⁿ · n) time (2ⁿ leaves, O(n) to copy each path), O(n) extra space (call stack + path);
  output itself is O(2ⁿ · n).
Variants & gotchas:
- ⚠️ **Never pass a `pick` flag down.** It's *redundant maintained state* (his own derive-don't-maintain
  principle): a variable that must AGREE with "did I push?". See MISTAKE M#8. With the flag, the
  decision lives at the PARENT's call site while the action lives in the child → choose and un-choose
  drift into different frames, the pop lands between the two child calls, and the root forces one
  branch so `{}` can never be born. Flagless = uniform frames = correct.
- The general shape is a **loop over choices** inside the frame: `for (choice : choices) { choose;
  explore; un-choose; }`. Pick/not-pick is that loop unrolled to 2 iterations. Permutations have n
  choices per slot — the boolean flag can't express that. (This is Bridge Q1.)
- Only the **base case** writes into `ans`. Nothing else.
- Duplicates in input (LC90/LC40) → sort first, then skip `i > start && nums[i] == nums[i-1]`.
Taught me by: **himself.** Kira refused to explain un-choose; boss traced his own broken tree on
  `[1,2,3]`, saw duplicates + missing subsets, and named the invariant unprompted.

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

### Geometry — Collinearity (cross product)  (LC149 Max Points on a Line, 2026-06-30)
Level: L2 (derived it back, own words)
Trigger: "are these points on ONE line?" / "most collinear points" / any 3-point-on-a-line check.
Recognition cue (my words): **collinear ⇒ slopes equal ⇒ cross-multiply to kill the division ⇒ integer cross product.** I don't memorize the formula — I rebuild it from slope equality.
Why it works: anchor at `i`, make vectors `A=j−i`, `B=k−i`. Collinear iff same direction (θ=0 or 180) iff `sinθ=0`. Cross product `= |A||B|sinθ`, so **cross == 0 ⇔ collinear**. (Dot product is useless here — nonzero for every angle.) Cross = signed area of the parallelogram = determinant `|ax bx; ay by|`; zero area ⇔ vectors dependent ⇔ parallel.
Formula (DERIVE, don't cram): slopes equal `(yj−yi)/(xj−xi)=(yk−yi)/(xk−xi)` → cross-multiply → `ax*by − ay*bx == 0` where `ax=xj−xi, ay=yj−yi, bx=xk−xi, by=yk−yi`.
Gotchas: (1) **subtract the anchor first** — raw coords measure cross from origin, not translation-invariant → wrong. (2) Cross-pair ACROSS the two vectors (`ax*by`, not `ax*ay`). (3) It's INTEGER math — no float, vertical lines free. Same reason the O(n²) optimal hashes a reduced `(dy,dx)` pair, never a `double` slope. (4) overflow: coords ≤1e4 → `ax*by` ≤ 4e8, safe in int here; larger ⇒ `long long`.
Complexity: brute oracle O(n³); optimal anchor+slope-hash O(n²)/O(n).
Taught me by: Kira — LC149 hard gauntlet P1. Brute AC'd; slope-hash O(n²) optimal still TODO.
