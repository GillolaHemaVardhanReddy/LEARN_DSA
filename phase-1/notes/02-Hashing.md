# 🗂️ 02 — Hashing — Study Notes

> The "explain it like a human" reference. Terse cues live in `PATTERN_JOURNAL.md`;
> the one-look classifier in `00-Recognition-Map.md`. This is the in-depth one.

---

## What it is (the engine, in 4 lines)
- An **array** gives O(1) access — but only if the key is a small int index (`a[37]` = `base+37*size`).
- A **hash function** squashes ANY key (huge int, string, negative) into a **small array index**.
- Then the normal array does its normal O(1) jump. → O(1) lookup for *arbitrary* keys.
- **Collisions are unavoidable** (pigeonhole: more possible keys than slots) → resolved by **chaining** (each slot holds a short list — what C++ `unordered_map` does) or open addressing.

**Complexity:** avg **O(1)** insert/lookup/erase. Worst **O(n)** when many keys pile into one bucket (rare with a good hash + auto-resize). *Average needs keys spread across slots; disaster = everything collides into one chain.*

## When to reach for it (cue)
> "have I **seen** this? / **how many times**? / find the **complement** in O(1) / **group** by a shared property"
>
> **⚠️ GATE: is the data SORTED? If NOT → hashing (not two pointers).**

---

## The C++ toolkit
```cpp
unordered_map<Key,Val> m;     // key → value
unordered_set<Key>     s;     // just "is it here?"
m[key] = val;  m[key]++;      // insert / count
m.count(key);                 // 1/0  ← PRESENCE check
m.find(key) != m.end();       // presence via iterator
s.insert(x); s.count(x);
```
### ⚠️ Gotchas (these cost me real bugs)
- **`if(m[key])` is poison.** Reading a missing key *inserts* it as 0, and 0 looks false. → use **`m.count(key)`**.
- `operator[]` always creates the entry. To only *test*, use `count`/`find`.
- Indexing a freq array by a char → **always `- 'a'`** (missed it twice in LC567).

---

## THE 4 SUB-PATTERNS (this is the recognition map for hashing)

### 1️⃣ Complement / "seen-before" map — *Two Sum family*
**Cue:** unsorted + need a **pair / complement / duplicate**.
**Idea:** walk once, remember what you've passed; ask the map for the piece you need.
```cpp
// Two Sum — return indices of pair summing to target
unordered_map<int,int> seen;             // value → index
for (int i = 0; i < n; i++) {
    int need = target - nums[i];
    if (seen.count(need)) return {seen[need], i};   // LOOK UP first
    seen[nums[i]] = i;                              // INSERT after
}
```
- **Order is correctness, not style:** look up **before** insert (else an element matches itself); **return on find**.
- Variants: LC1 Two Sum, LC219 duplicate within distance k (store value→**last index**, check `i-last ≤ k`).
- **Why not two pointers?** That needs *sorted* data + you'd lose original indices.

### 2️⃣ Frequency count — *Anagram / Top-K family*
**Cue:** "how many times does each thing appear?" (counting is reason enough — no O(n²) search needed).
```cpp
for (int x : nums) freq[x]++;            // one pass, all counts at once → O(n)
```
- This still *is* the "map IS the inner loop" move: the brute force re-scans the array per distinct value (O(n²)); the map counts everything in **one pass**.
- **Bounded keys (a–z, 0–9) → use `int[26]` not a map** (Valid Anagram: inc for s, dec for t, all-zero ⇒ anagram). **Unbounded/Unicode → switch to a map** (the follow-up). *Container changes with the key space.*
- Top-K: phase 1 = count (map), phase 2 = **select** top k via **bucket sort** (`vector<vector<int>> buckets(n+1)`, index = frequency, scan high→low) → **O(n)**. Heap alt = O(n log k), O(k) space (better when k≪n).

### 3️⃣ Group / dedup by canonical KEY — *Group Anagrams family*
**Cue:** "group items that share some property."
**Idea:** give each item a **fingerprint** so matches collide; let the map bucket them — no pairwise compare.
```cpp
unordered_map<string, vector<string>> groups;
for (string& w : strs) {
    string key = w; sort(key.begin(), key.end());   // anagrams → identical key
    groups[key].push_back(w);                        // drops into its bucket
}
// collect groups' values
```
- Kills brute force **O(n²·k) → O(n·k log k)** (sorted key) or **O(n·k)** (26-count signature key, no sort).
- The map removes ALL the bookkeeping: no `visited`, no include-self, no empty groups, no pairwise loop.

### 4️⃣ Set membership for O(1) reasoning — *Longest Consecutive family*
**Cue:** need fast "is value X present?" to avoid sorting.
```cpp
// Longest Consecutive Sequence — O(n)
unordered_set<int> s(nums.begin(), nums.end());
int best = 0;
for (int x : s) {
    if (s.count(x-1)) continue;          // only START from sequence beginnings
    int cur = x, len = 1;
    while (s.count(cur+1)) { cur++; len++; }
    best = max(best, len);
}
```
- **The trick that keeps it O(n):** only walk forward from numbers with no predecessor (`x-1` absent). Each element is visited by a walk **exactly once** → total O(n), not O(n²).
- **Why not sort?** Sort-then-scan is correct but **O(n log n)**; the set gets O(1) "is x present" so you never need order → **O(n)**.

---

## Why hashing, why not the alternative
| Instead of… | …hashing wins because |
|---|---|
| nested-loop search (O(n²)) | O(1) lookup replaces the inner scan |
| sorting first (O(n log n)) | O(1) membership/count needs no order → O(n) |
| two pointers | works on UNSORTED data + preserves indices |

## Problems that taught me this
- LC1 Two Sum (complement) · LC242 Valid Anagram (freq, array vs map) · LC49 Group Anagrams (canonical key) · LC128 Longest Consecutive (set + start-walk) · LC347 Top-K (count + bucket) · LC217/219 (seen-set / last-index).

_Last updated 2026-06-08. Level: L3→L4 (solo set in progress). See PROGRESS.md._
