# CPP_GAPS.md — C++ Fluency Track (Hema Vardhan)

> Track 2 of the training plan. A C++ primitive gap is a **vocabulary** gap, not a thinking
> failure — log it with the fix the moment it surfaces, review weekly so it never blindsides
> you twice. ~10 min/session.

| # | Gap (what I didn't know) | The fix / idiom | Surfaced on | Reviewed |
|---|---|---|---|---|
| 1 | How to copy one vector into another | `b = a;` (whole copy) · `b.assign(a.begin(), a.end());` (from range) · `vector<int> b(a);` (at construction). NOTE: `b(a.begin(),a.end())` only works when *declaring*, not on an existing vector. | drill1 P2 | — |
| 2 | Integer overflow — type too small for the arithmetic | See the OVERFLOW DETECTION RULE below. | LC875 Koko + drill1 P3 (MISTAKE #8, recurring) | — |
| 3 | **Method placement** — keep writing the method INSIDE `main()` (nested function) | Methods live INSIDE the `class Solution { public: ... };`. `main()` is separate and only CALLS them: `Solution sol; sol.method(args);`. A function cannot be defined inside another function in C++. | drill1 P3 (3rd time, also 6/10) | — |
| 4 | **Can't sort a `map`/`unordered_map` by value** (map is ordered by KEY, unordered has no order) | Copy it into a `vector<pair<K,V>>`, then sort the vector. Put the field you sort on **FIRST** in the pair so the default/`greater<>()` comparator just works: `vector<pair<int,char>> v; for(auto& [ch,cnt]: freq) v.push_back({cnt,ch}); sort(v.begin(),v.end(),greater<>());` | drill1 P15 | — |
| 5 | **Loop a map** + **build a repeated-char string** | Structured bindings (C++17): `for(auto& [key,val] : mp){...}`. Make a char repeated N times: `string(n, ch)` or `ans.append(n, ch)` — **count FIRST, char second**. | drill1 P15 | — |
| 6 | **`std::stack::pop()` returns `void`** — wrote `char c = st.pop();` (won't compile) | Reading and removing are TWO calls: `char c = st.top();` (read) then `st.pop();` (remove). Same for `queue`/`priority_queue`. | phase-1/learn/07 Valid Parentheses (LC20) | — |
| 7 | **`string::find()` returns a position OR `string::npos`** — used it as a bool (`if(s.find("()"))`) → inverted logic + crash | `find` returns the index if found (can be `0`!) or **`npos`** = `(size_t)-1` (unsigned → max value ≈ 1.8e19) if NOT found. **Always compare `!= string::npos`**, never truthiness (index 0 is falsy, npos is truthy = exactly backwards). Same sentinel family as a boundary leak. | phase-1/learn/07 Valid Parentheses (LC20) | — |
| 8 | **char literal vs string literal** — wrote `s.find('()')` and `s.find({})` | Single quotes = **one char** (`'a'`); double quotes = **string** (`"()"`). `'()'` is a (bad) multi-char constant, `{}` won't compile. A pair pattern is a string → `s.find("()")`. | phase-1/learn/07 Valid Parentheses (LC20) | — |
| 9 | **`.back()`/`.front()`/`.top()` on an EMPTY container is UNDEFINED BEHAVIOR — believed it "returns 0"** | It does NOT return 0 — it reads unowned memory (garbage or crash). **Always guarantee non-empty before reading an end**, either with `!c.empty()` in the loop condition or a proven invariant (LC933: the just-pushed `t` is always `≥ t-3000`, so it's a sentinel that keeps the deque non-empty). This is his #1 boundary/empty-container leak in C++ clothing. | phase-2/learn/08 LC933 Recent Calls (7/04) | — |

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
- **`vector`/pair as a set/map key:** `unordered_set<vector<int>>` does NOT compile — `vector` has no built-in `std::hash`. Use `set<vector<int>>` (tree, needs only `<`, which vector has) — auto-sorts + dedupes. Same for `map` vs `unordered_map` with vector/pair keys.
- **Return a set as a vector:** `return vector<vector<int>>(s.begin(), s.end());` (or `return {s.begin(), s.end()};`). A `set` is not implicitly a `vector`.
- **STRIP debug `cout` before submitting:** a `cout` inside a hot loop is slow I/O — turns an O(n) solution into 30–50× wall-clock (P13: 1459ms → ~35ms once removed). Recurred P9 + P13. Delete all debug prints before submit.
- Frequency array vs map: `int cnt[26]={0};` for lowercase letters; `unordered_map<int,int>` for arbitrary keys.
- `unordered_map` presence: use `.count(k)` or `.find(k)!=end()` — NOT `if(map[k])` (index/value 0 is falsy, and `[]` inserts).
- Sort with comparator: `sort(v.begin(), v.end(), [](auto&a, auto&b){ return a > b; });` (descending).
- Two-pointer in-place write: `nums[k++] = nums[i];` — overwrite the front, no extra container.
