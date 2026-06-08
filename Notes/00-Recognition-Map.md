# 🧭 00 — MASTER RECOGNITION MAP (the before-exam sheet)

> **Read this ONE page before any interview/exam.** It answers the only question that
> matters under pressure: *"I see this problem — which tool does it want?"*
> Deep per-topic notes live in the other files; this is the **classifier** that points you there.
> Covers everything learned so far: **Sliding Window · Prefix Sum+Hash · Hashing**.

---

## ① THE CLASSIFIER — "if you see ___ → reach for ___"

| Surface features in the problem | Tool | Why |
|---|---|---|
| **contiguous** subarray/substring + max/min/longest/shortest/sum/avg, size **given** | **Fixed Sliding Window** | window slides in lockstep, O(n) |
| **contiguous** + longest/shortest satisfying a **condition**, size **not given**, values **positive/monotonic** | **Variable Sliding Window** | breathe the window, O(n) |
| subarray **sum = k / divisible by k / equal counts**, values can be **negative** | **Prefix Sum + Hash** | window dies on negatives; prefixes + map = O(n) |
| **count / range-query** an aggregate (sum, xor, product) over many subarrays | **Prefix Sum** | precompute once, answer ranges in O(1) |
| "have I **seen** this value? / how many times? / find the **complement**", data **UNSORTED** | **Hashing (map/set)** | O(1) lookup kills the O(n) inner scan |
| **group / dedup** items sharing a property (anagrams, etc.) | **Hashing — canonical key → bucket** | same key collides into same bucket |
| find a **pair by sum/diff**, data is **SORTED** | **Two Pointers** | move the wrong-side pointer inward (not yet learned formally) |

---

## ② THE DISCRIMINATIONS — the calls that trip me up (memorize cold)

These are the *exact* mistakes from my drill (scored 4/7). Each is a "looks like X, is actually Y."

### 🔴 Two Pointers vs Hashing
> **Is the data SORTED?**  **Sorted → two pointers.  UNSORTED → hashing.**
- Unsorted Two Sum / "duplicate within distance k" → **HASHING**, not two pointers.
- Two pointers *needs* sorted/monotonic structure to know which pointer to move. No sort → no two pointers.
- ⚠️ My repeated leak: parking every pair/duplicate problem under "two pointers." STOP — ask "sorted?" first.

### 🔴 Sliding Window vs Prefix+Hash
> **Can values be NEGATIVE? (or did I transform to ±1?)  → Prefix+Hash, NOT sliding window.**
- Sliding window relies on **monotonicity**: adding an element must *predictably* push the metric one way. Positives → sum only grows → can decide when to shrink. **Negatives break that** → window can't decide → use prefix+hash.
- "longest subarray with equal 0s and 1s" → transform 0→−1 introduces negatives → **prefix+hash**, not SW.

### 🔴 GOAL: count vs longest vs shortest (decides the whole code shape)
> **Classify the goal FIRST — it picks your machinery:**

| Goal | Machinery |
|---|---|
| **count** all matching | tally: `ans += seen[key]`, `seen[0]=1` |
| **longest** | first-index map: `ans=max(ans, i - seen[key])`, `seen[0]=-1`, store on **first** sight only |
| **shortest** | shrink-while-valid window, record inside the `while` |
| **exists?** | boolean / set membership |

### 🔴 Bounded keys: array vs hash map
> **Are the keys small bounded ints (a–z, 0–9, frequencies 1..n)? → ARRAY. Unbounded/arbitrary/Unicode → HASH MAP.**
- `int cnt[26]` beats `unordered_map<char,int>` (no hashing overhead, obviously correct).
- Same lesson everywhere: anagrams (26), Top-K buckets (freq 1..n), sudoku.

---

## ③ THE BOUNDARY CHECKLIST — my #1 leak (run before EVERY submit)

> Logic is almost always right; the **edges** leak. This has bitten **12×** across LC209/567/1/128/etc.

- [ ] **Loop touches FIRST and LAST element?** (off-by-one `< n` vs `< n-1`; `right-left+1` with the +1)
- [ ] **Empty / single-element input?** (return value for "nothing found")
- [ ] **Sentinels:** min-tracker `= INT_MAX`, max-tracker `= 0/-∞`; convert "not found" back at return
- [ ] **Loop direction matches start/end?** (reverse loop must be `i--`, not `i++` ← TLE'd LC347)
- [ ] **Consistent compare direction?** (`nums[i]==nums[i-1]+1` backward, not `nums[i+1]-1` forward)
- [ ] **Hash maps:** look up **before** insert (else self-match); use **`.count()`**, never `if(map[key])` (index-0 trap)
- [ ] **Index by char?** always `- 'a'` / `- '0'`
- [ ] **After ANY edit:** re-read the whole function top-to-bottom before submitting (catches dangling vars / leftover returns)

---

## ④ COMPLEXITY — the rules I keep re-deriving

- **A `while` inside a `for` is NOT automatically O(n²).** It's O(n) if the inner index never *resets* (sliding window: `left` only moves forward → ≤2n total).
- **"There's a sort" ≠ O(n log n).** Sort of `X` items = `O(X log X)`. Sort `k` items, `n` times = **`O(n·k log k)`**, not `O(n log n)`. The `log` attaches to *what one sort call eats*; the *count of calls* multiplies outside.
- **A loop of n iterations is O(n) only if each iteration is O(1).** Each iter does a k-sort → `O(n·k log k)`. Collapses to O(n) only if `k` is a fixed constant.
- **Hashing:** avg O(1), worst O(n) (when many keys collide into one bucket).
- **Lower bound:** if you must read every element (e.g. Top-K), you can't beat **Ω(n)** — don't chase a faster-than-O(n).

---

## ⑤ STATUS (from PROGRESS.md)
| Pattern | Level | Recognition |
|---|---|---|
| Sliding Window | **L4** | strong (drill 3/3) |
| Prefix Sum + Hash | **L4** | good (transform-cue still sharpening) |
| Hashing | **L3→L4** | rebuilding (drill 0/2 → now fixing via solo set) |

_Last updated 2026-06-08._
