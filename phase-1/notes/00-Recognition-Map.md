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
| subarray **sum = k** with **negative** values | **Prefix Sum + Hash** | window dies on negatives |
| subarray **divisible by k / remainder / equal counts / COUNT-all** (ANY sign) | **Prefix Sum + Hash** | not monotonic → window can't apply, even for positives |
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
- This discrimination is specifically for the **complement / pair-SUM** family: there, two pointers needs sortedness, so unsorted → hashing.
- ⚠️ My repeated leak: parking every pair/duplicate problem under "two pointers." STOP — ask "sorted?" first.
- 🔸 **But "two pointers" is NOT limited to sorted arrays in general.** The real requirement is a *provably-safe move*
  (discarding one side never loses the answer). Sorted enables that for sums; a greedy property enables it elsewhere —
  e.g. **Container/Trapping (LC11/LC42) are UNSORTED** and use the "move the limiting side" proof. See `phase-1/notes/03`.

### 🔴 Sliding Window vs Prefix+Hash
> **THE ONE-LINE TEST:** *Can the window's target move MONOTONICALLY as the window grows?*
> **Yes → sliding window allowed.  No → prefix+hash.**
- Sliding window relies on **monotonicity**: adding an element must *predictably* push the metric one way. Positives → sum only grows → can decide when to shrink. **Negatives break that** → window can't decide → prefix+hash.
- "longest subarray with equal 0s and 1s" → transform 0→−1 introduces negatives → **prefix+hash**, not SW.

**Which problems pass / fail the monotonicity test:**
| Problem | Monotonic? | Tool |
|---|---|---|
| sum = k, **positive** values | yes | sliding window ✔ (or prefix+hash) |
| sum = k, **negative** values | no | prefix + hash |
| **divisible by k / remainder** (ANY sign, incl. positives!) | **no** — mod jumps around, not monotonic | **prefix + hash ONLY** |
| **count ALL** matching subarrays (any sign) | no — it's a tally, not one window | **prefix + hash ONLY** |
> ⚠️ Trap: "divisible by k" with positive numbers is STILL prefix+hash — positivity does NOT make divisibility monotonic. Don't reach for a window just because the values are positive.

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

### 🧱 WHY boundaries break — root-cause fixes (read this when frustrated)
> Off-by-one / boundary bugs are the **#1 bug class in ALL of programming** — everyone hits them, incl. seniors.
> Not a smarts problem — a **discipline** problem (trainable). My logic is right every time; only the edges leak.

**A) The 4 questions — run on every loop:**
1. **In-bounds?** Before any `arr[i]`, what's the max `i` here — is it `< n`? Put the bound INSIDE the loop/while condition as the **first** clause: `i < n && ...` (short-circuits before the read).
2. **Guard agrees with access?** If the body reads `arr[e]`, the condition must guarantee `e < n` *at that line*. A guard at the TOP of the loop is **stale** after an inner mutation → re-guard where the access happens (`if (e == n) break;`). ← this was the Move Zeroes OOB.
3. **Termination?** Does every branch advance *something*? A branch that leaves all indices unchanged → infinite loop.
4. **Trace 4 edges:** empty · single · all-same · none-match.

**B) When boundaries KEEP breaking → REPLACE the structure (don't patch it).**
A single forward loop where **one pointer does all the indexing** (`for read…; write trails`) is boundary-proof *by construction*. Two indices + a nested `while` that mutates one of them = a minefield. (Move Zeroes: the read/write 3-liner can't OOB; the s/e + nested-while can.) **Choosing a boundary-proof structure IS the senior move — not a cop-out.**

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
