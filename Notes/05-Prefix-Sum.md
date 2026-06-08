# ➕ 05 — Prefix Sum (+ Hash) — Study Notes

> The "explain it like a human" reference. Terse cues in `PATTERN_JOURNAL.md`;
> classifier in `00-Recognition-Map.md`. This is the in-depth one.

---

## What it is
- `prefix[i]` = the running aggregate of everything up to `i`.
- **Range formula:** `sum(L..R) = prefix[R] - prefix[L-1]`  (derive by *meaning*: total up to R minus the part before L; `L=0` → nothing before → `prefix[R]`). 1-index with `prefix[0]=0` to kill the special case.
- Precompute once (O(n)), then **any range answers in O(1)**.

## ⭐ "Prefix" = ANY cumulative aggregate, not just sums
The operation can be `+`, `×`, `^` (xor), or **count**. Cue = *"I need an aggregate over ranges/subarrays and brute force recomputes overlapping pieces."*
Examples: range sum · product-except-self (prefix×suffix, LC238) · subarray xor=k · 2D prefix.

## When to reach for it (cue)
> subarray **sum = k / divisible by k / equal counts / range query**, ESPECIALLY when **sliding window is dead** (negatives present, or it's a **count** not a window).

---

## 🔑 The big idea: "the hash map IS the inner loop"
A condition on a *subarray* becomes a condition on **two prefix values**:
`sum(L..R)=k`  ⟺  `prefix[R] - prefix[L-1] = k`  ⟺  `prefix[L-1] = prefix[R] - k`.
So as you sweep R, **store every prefix seen so far in a map** and look up the one you need in O(1).
→ "scan all start points" (O(n²)) collapses to one O(1) lookup → **O(n)**. *It's literally Two Sum on prefix sums.*

---

## 🎯 GOAL × KEY — the heart (decide TWO axes separately)

**Axis 1 — GOAL** (what's asked):
| Goal | Store | Pre-load | Update |
|---|---|---|---|
| **COUNT** subarrays | **frequency** of each prefix | `seen[0] = 1` | `ans += seen[key]; seen[key]++` |
| **LONGEST** subarray | **first index** of each prefix | `seen[0] = -1` | `if(seen.count(key)) ans=max(ans, i-seen[key]); else seen[key]=i` |

> ⚠️ My 6/6 drill fail was mixing these. **COUNT → freq + `seen[0]=1`. LONGEST → first-index + `seen[0]=-1`, store on FIRST sight only (earliest = largest gap).**

**Axis 2 — KEY** (what to match on):
| Key | Use it for | Note |
|---|---|---|
| **complement** `key = run`, look up `run - k` | subarray **sum = k** (LC560) | |
| **remainder** `key = ((run % k) + k) % k` | sum **divisible by k** (LC974, LC523) | NORMALIZE negative mod! |
| **transform** (e.g. 0→−1), look for repeat | **equal counts** / balanced (LC525) | repeat of a prefix ⇒ zero-sum stretch |

### Template
```cpp
unordered_map<int,int> seen;
seen[0] = 1;                 // COUNT   (or seen[0] = -1 for LONGEST)
int run = 0, ans = 0;
for (int i = 0; i < n; i++) {
    run += a[i];
    int key = /* run | ((run%k)+k)%k | run-after-transform */;
    // COUNT:   ans += seen[key - k];  seen[key]++;
    // LONGEST: if (seen.count(key)) ans = max(ans, i - seen[key]); else seen[key] = i;
}
```

---

## Why prefix+hash, why not sliding window
> **Sliding window needs monotonicity** (positives: adding always grows the sum, so you know when to shrink). **Prefix+hash does NOT** — it works with **negatives** because it compares stored prefix *values*, not window growth.
- Negatives present, or a ±1 transform, or it's a **count** → prefix+hash.
- All positive + longest/shortest contiguous → sliding window is simpler.

## ⚠️ Gotchas (my real bugs)
- Derive the range formula by **meaning**, never by shape (`prefix[R]-prefix[L-1]`, not "prefix minus prefix").
- **Normalize negative remainders:** `((x % k) + k) % k`.
- **Presence check = `.count()`/`.find()`**, never `if(seen[key])` — a stored index 0 is falsy (the LC523 trap).
- **First-index problems: store ONCE** (`else` branch) — overwriting shrinks every gap.
- `map`(O(log n) ordered) vs `unordered_map`(O(1)) — use unordered unless you need sorted keys (LC523: 150ms→81ms just by switching).

## Problems that taught me this
- LC560 (complement, count) · LC974 (remainder, +neg-mod) · LC525 (transform, longest) · LC523 (remainder) · LC238 (prefix×suffix) · LC724 (pure prefix balance point). Same engine, different KEY each time.
- LC862 PARKED (needs monotonic deque, M8).

_Last updated 2026-06-08. Level: L4. See PROGRESS.md._
