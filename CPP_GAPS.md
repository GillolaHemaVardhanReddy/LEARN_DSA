# CPP_GAPS.md — C++ Fluency Track (Hema Vardhan)

> Track 2 of the training plan. A C++ primitive gap is a **vocabulary** gap, not a thinking
> failure — log it with the fix the moment it surfaces, review weekly so it never blindsides
> you twice. ~10 min/session.

| # | Gap (what I didn't know) | The fix / idiom | Surfaced on | Reviewed |
|---|---|---|---|---|
| 1 | How to copy one vector into another | `b = a;` (whole copy) · `b.assign(a.begin(), a.end());` (from range) · `vector<int> b(a);` (at construction). NOTE: `b(a.begin(),a.end())` only works when *declaring*, not on an existing vector. | drill1 P2 | — |
| 2 | Integer overflow — type too small for the arithmetic | See the OVERFLOW DETECTION RULE below. | LC875 Koko + drill1 P3 (MISTAKE #8, recurring) | — |
| 3 | **Method placement** — keep writing the method INSIDE `main()` (nested function) | Methods live INSIDE the `class Solution { public: ... };`. `main()` is separate and only CALLS them: `Solution sol; sol.method(args);`. A function cannot be defined inside another function in C++. | drill1 P3 (3rd time, also 6/10) | — |

---

## ⭐ OVERFLOW DETECTION RULE (run at DESIGN time, every `+`/`*`/accumulator)
**Ceilings:** `int` ≈ ±2.1e9 (2,147,483,647) · `long long` ≈ ±9.2e18.

**The question:** "what's the MAX this expression can reach given the constraints? > ~2e9? → `long long`."

**Three red flags (quick math from constraints):**
1. **Multiply two values** — if both can be ≥ ~46,000, the product overflows int (√2.1e9 ≈ 46,340).
   (`i*i` with i up to 46,341 → 2.15e9 ✗;  `a*b` with a,b up to 1e5 → 1e10 ✗.)
2. **Sum/accumulate many elements** — `n × maxValue`. n=1e5 × val=1e5 → 1e10 ✗. Prefix sums = classic trap.
3. **Add two large values** — `a+b` each ~1e9 → ~2e9 (edge). Binary search: use `mid = lo + (hi-lo)/2`.

**Casting subtlety (bites everyone):** cast BEFORE the op, on ONE operand.
- `long long x = a * b;`            ✗ (a*b done in int first, overflows, THEN widened)
- `long long x = (long long)a * b;` ✓ (promotes whole multiply to 64-bit)
- If the function RETURNS the big value, its return type must be `long long` too.

**Lazy-but-safe default:** values near 1e9, or multiplying/accumulating and unsure → just use `long long`.
Reserve `int` for things known small (indices, counts < ~1e6, loop variables).

---

## Idioms worth drilling (add as they come up)
- Frequency array vs map: `int cnt[26]={0};` for lowercase letters; `unordered_map<int,int>` for arbitrary keys.
- `unordered_map` presence: use `.count(k)` or `.find(k)!=end()` — NOT `if(map[k])` (index/value 0 is falsy, and `[]` inserts).
- Sort with comparator: `sort(v.begin(), v.end(), [](auto&a, auto&b){ return a > b; });` (descending).
- Two-pointer in-place write: `nums[k++] = nums[i];` — overwrite the front, no extra container.
