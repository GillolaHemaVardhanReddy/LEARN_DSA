# 🗂️ 02 — Hashing  (teaching notes — reread cold, they rebuild the model)

> These notes TEACH, they don't just remind. Read top to bottom and the understanding comes back.
> Terse cues live in `PATTERN_JOURNAL.md`; the one-look classifier in `00-Recognition-Map.md`.
> Hashing is the single most-used tool in interviews — the reflex that turns O(n²) into O(n).

---

## BIT 0 — The one sentence
> **A hash map trades SPACE for TIME: it REPLACES an O(n) inner scan with an O(1) lookup.**

Every hashing problem is that one move wearing a different hat. Memorise the sentence; the rest is *why* and *how to run it.*

---

## BIT 1 — Why it exists (the "why")
An **array** already gives O(1) access — but *only* when the key is a small int index: `a[37]` is just `base + 37*size`, one jump. The moment your key is a huge int, a string, or a negative number, that trick dies.

A **hash function** fixes that: it squashes ANY key (string, big int, negative) into a **small array index**. Then the normal array does its normal O(1) jump. Result: **O(1) lookup for arbitrary keys.**

Why you care: tons of problems have a brute force that is "for each element, scan the rest to find a partner / a count / a match" → **O(n²)**. That inner scan is the enemy. A hash map lets you *pre-remember* what you've seen so the inner scan becomes a single O(1) question. That's the whole pattern.

> **Nested loop = ask the array n times. Hash map = ask your memory once.**

---

## BIT 2 — The mechanics (the C++ toolkit)
Two containers. Pick by *what you need to remember.*
```cpp
unordered_map<Key,Val> m;     // key → value   (remember something ABOUT each key)
unordered_set<Key>     s;     // just "is it here?"  (remember only PRESENCE)

m[key] = val;   m[key]++;     // insert / count
m.count(key);                 // 1 or 0  ← PRESENCE check (safe)
m.find(key) != m.end();       // presence via iterator
s.insert(x);    s.count(x);
```
Three storage shapes — this is the decision you make every time:
- **value → index** (Two Sum: I need *where* it was)
- **value → count** (frequency: I need *how many*)
- **just presence** → a **set** (membership: I only need *is it here*)

---

## BIT 3 — The mental UNLOCK (read twice) ⭐
Here is Two Sum, brute force first — the shape you must learn to *kill*:
```cpp
// BRUTE: for each i, scan the rest for a partner → O(n²)
for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
        if (nums[i] + nums[j] == target) return {i, j};
```
The inner `j` loop is an **O(n) scan** that asks: "is `target - nums[i]` somewhere ahead of me?" We ask that question n times → O(n²).

**The unlock:** that question — "does value X exist, and where?" — is *exactly* what a hash map answers in O(1). So carry a map of everything you've already walked past, and replace the inner scan with one lookup:
```cpp
// OPTIMAL: map REPLACES the inner scan → O(n)
unordered_map<int,int> seen;                 // value → index
for (int i = 0; i < n; i++) {
    int need = target - nums[i];
    if (seen.count(need)) return {seen[need], i};   // O(1) LOOK UP first
    seen[nums[i]] = i;                              // INSERT after
}
```
The O(n²) collapsed to O(n) because the inner loop *became a lookup.* When you feel a nested scan searching for a partner/count/match — that inner loop is a hash map wearing a disguise.

---

## BIT 4 — HAND-RUN the trace (run this yourself, boss)
`nums = [2, 7, 11, 15]`, `target = 9`. Map starts empty `{}`.

| i | nums[i] | need = 9−nums[i] | `seen.count(need)`? | action |
|---|---------|------------------|---------------------|--------|
| 0 | 2       | 7                | no (`{}`)           | insert → `seen = {2:0}` |
| 1 | 7       | 2                | **YES**, at index 0 | **return {0, 1}** ✅ |

Feel the two beats: **look up BEFORE insert**, then **insert after.** That order is *correctness, not style* —
- If you inserted first, at i=0 you'd store `2`, and if `target` were `4` element `2` would find *itself* (`need = 2`, already in map) and wrongly return `{0,0}`. Looking up first means you only ever match an *earlier* element.

Now the frequency shape, one pass, all counts at once:
```cpp
for (int x : nums) freq[x]++;   // O(n) — no re-scan per distinct value
```
Same move: brute force re-scans the array once per distinct value (O(n²)); the map tallies everything in **one pass.**

---

## BIT 5 — THE 4 SUB-PATTERNS (the recognition map)

**1️⃣ Complement / "seen-before" map — *Two Sum family***
Cue: unsorted + need a **pair / complement / duplicate**. Store **value→index**, look up `target-x` before inserting.
Variants: **LC1** Two Sum · **LC219** duplicate within distance k (store value→**last index**, check `i-last ≤ k`).
Why not two pointers? That needs *sorted* data and loses original indices.

**2️⃣ Frequency count — *Anagram / Top-K family***
Cue: "how many times does each thing appear?" Counting alone justifies it — no O(n²) search needed. One pass → all counts.
- **Bounded keys (a–z, 0–9) → use `int[26]`, not a map** (Valid Anagram: `++` for s, `--` for t, all-zero ⇒ anagram). **Unbounded / Unicode → map.** *Container tracks the key space.*
- Top-K: phase 1 = count (map); phase 2 = **select** top k via **bucket sort** (`vector<vector<int>> buckets(n+1)`, index = frequency, scan high→low) → **O(n)**. Heap alt = O(n log k), O(k) space (better when k≪n).

**3️⃣ Group / dedup by canonical KEY — *Group Anagrams family***
Cue: "group items that share a property." Give each item a **fingerprint** so matches collide into the same bucket — no pairwise compare.
```cpp
unordered_map<string, vector<string>> groups;
for (string& w : strs) {
    string key = w; sort(key.begin(), key.end());   // anagrams → identical key
    groups[key].push_back(w);
}
```
Kills brute **O(n²·k) → O(n·k log k)** (sorted key) or **O(n·k)** (26-count signature key, no sort). Map erases all bookkeeping: no `visited`, no include-self, no empty groups. **LC49.**

**4️⃣ Set membership for O(1) reasoning — *Longest Consecutive family***
Cue: need fast "is value X present?" to avoid sorting.
```cpp
unordered_set<int> s(nums.begin(), nums.end());
int best = 0;
for (int x : s) {
    if (s.count(x-1)) continue;          // only START from a sequence's beginning
    int cur = x, len = 1;
    while (s.count(cur+1)) { cur++; len++; }
    best = max(best, len);
}
```
The trick that keeps it O(n): only walk forward from numbers with **no predecessor** (`x-1` absent), so each element is visited by a walk exactly once. Why not sort? Sort-scan is O(n log n); the set's O(1) membership means you never need order → **O(n). LC128.**

---

## BIT 6 — The design RECIPE (run this BEFORE coding) ⭐ your Gate-A
Three questions, in order:
1. **Is it SORTED?** — **NO → hashing, not two pointers.** (This is *your* recognition leak — call it out loud every time. Two-pointer needs sorted input; on unsorted pair problems, reach for the map.)
2. **What do I store?** — value→**index** (need where), value→**count** (need how many), or just **presence** (need is-it-here → a `set`)? Pick the container from the answer: map vs set.
3. **Which of the 4 sub-patterns is this?** — complement · frequency · group-by-key · membership. Naming it hands you the template.

Answer those three and the code writes itself.

---

## BIT 7 — Complexity, read off the shape
- Insert / lookup / erase: **avg O(1)**, because a good hash spreads keys evenly across buckets and each bucket is a tiny chain.
- **Worst O(n)**: if many keys collide into ONE bucket, that slot becomes a linear list you scan. Rare in practice (good hash + auto-resize), but real.
- **Collisions are unavoidable** — pigeonhole: more possible keys than slots. C++ `unordered_map` resolves by **chaining** (each slot holds a short list); the alternative is open addressing.
- Space: **O(n)** for the map — that's the "trade space for time" price. You spend memory to buy the O(1) lookup.

---

## BIT 8 — The classic TRAPS (execution focus, boss)
1. **Two-pointers on an UNSORTED pair problem** (your recurring miss). Two-pointer *requires* sorted data; if it's unsorted and you need a pair, the answer is a hash map. Run recipe Q1 first, every time.
2. **`if(m[key])` is poison.** Reading a missing key with `[]` *inserts it as 0*, and 0 reads as false — silent corruption. Test presence with **`m.count(key)`** or `m.find(key)`.
3. **Set-vs-map confusion.** If you only ever ask "is it here?", a `set` is right — reaching for a map means you're storing a value you never use. If you need *where* or *how many*, it must be a map. Match container to recipe Q2.
4. **Forgetting the `seen[0]` sentinel** in prefix-sum + hash count problems (e.g. subarray-sum-equals-k). Seed the map with `seen[0] = 1` before the loop, so a prefix that equals the target *from index 0* is counted. Miss it → you drop every subarray starting at index 0.
5. **Bounded key → forgot `- 'a'`** when indexing a `int[26]` freq array by a char (cost real bugs in LC567). Char keys need the offset.

---

## BIT 9 — Recognition cue (fill in YOUR words after the coding ladder)
> "have I **seen** this? / **how many times**? / find the **complement** in O(1) / **group** by a shared property" → hash map.
> And the master cue: *a nested loop searching for a partner/count/match = an O(n) inner scan a map can kill.*

*(Your teach-it-back line goes here once you've coded the ladder — that's the L6 signal.)*

## Why hashing, why not the alternative
| Instead of… | …hashing wins because |
|---|---|
| nested-loop search (O(n²)) | O(1) lookup replaces the inner scan |
| sorting first (O(n log n)) | O(1) membership/count needs no order → O(n) |
| two pointers | works on UNSORTED data + preserves indices |

## Problems that taught me this
- **LC1** Two Sum (complement) · **LC242** Valid Anagram (freq, array vs map) · **LC49** Group Anagrams (canonical key) · **LC128** Longest Consecutive (set + start-walk) · **LC347** Top-K (count + bucket) · **LC217/219** (seen-set / last-index).

_Rewritten 2026-07-05 into teaching-BITS format. Level tracked in PROGRESS.md._
