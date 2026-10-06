# CPP_GAPS.md — C++ Fluency Track (Hema Vardhan)

> Track 2 of the training plan. A C++ primitive gap is a **vocabulary** gap, not a thinking
> failure — log it with the fix the moment it surfaces, review weekly so it never blindsides
> you twice. ~10 min/session.

| # | Gap (what I didn't know) | The fix / idiom | Surfaced on | Reviewed |
|---|---|---|---|---|
| 1 | How to copy one vector into another | `b = a;` (whole copy) · `b.assign(a.begin(), a.end());` (from range) · `vector<int> b(a);` (at construction). NOTE: `b(a.begin(),a.end())` only works when *declaring*, not on an existing vector. | drill1 P2 | — |
| 2 | Integer overflow — type too small for the arithmetic | See the OVERFLOW DETECTION RULE below. | LC875 Koko + drill1 P3 (MISTAKE #8, recurring) | — |
| 3 | **Method placement** — keep writing the method INSIDE `main()` (nested function) | Methods live INSIDE the `class Solution { public: ... };`. `main()` is separate and only CALLS them: `Solution sol; sol.method(args);`. A function cannot be defined inside another function in C++. | drill1 P3 (3rd time, also 6/10) | — |
| 4 | **Can't sort a `map`/`unordered_map` by value** (map is ordered by KEY, unordered has no order) | Copy it into a `vector<pair<K,V>>`, then sort the vector. Put the field you sort on **FIRST** in the pair so the default/`greater<>()` comparator just works: `vector<pair<int,char>> v; for(auto& [ch,cnt]: freq) v.push_back({cnt,ch}); sort(v.begin(),v.end(),greater<>());` | drill1 P15 | **resurfaced 2026-09-28 (LC347) — forgotten; re-taught, used, AC** |
| 5 | **Loop a map** + **build a repeated-char string** | Structured bindings (C++17): `for(auto& [key,val] : mp){...}`. Make a char repeated N times: `string(n, ch)` or `ans.append(n, ch)` — **count FIRST, char second**. | drill1 P15 | — |
| 6 | **`std::stack::pop()` returns `void`** — wrote `char c = st.pop();` (won't compile) | Reading and removing are TWO calls: `char c = st.top();` (read) then `st.pop();` (remove). Same for `queue`/`priority_queue`. | practice/07-stacks/learn Valid Parentheses (LC20) | — |
| 7 | **`string::find()` returns a position OR `string::npos`** — used it as a bool (`if(s.find("()"))`) → inverted logic + crash | `find` returns the index if found (can be `0`!) or **`npos`** = `(size_t)-1` (unsigned → max value ≈ 1.8e19) if NOT found. **Always compare `!= string::npos`**, never truthiness (index 0 is falsy, npos is truthy = exactly backwards). Same sentinel family as a boundary leak. | practice/07-stacks/learn Valid Parentheses (LC20) | — |
| 8 | **char literal vs string literal** — wrote `s.find('()')` and `s.find({})` | Single quotes = **one char** (`'a'`); double quotes = **string** (`"()"`). `'()'` is a (bad) multi-char constant, `{}` won't compile. A pair pattern is a string → `s.find("()")`. | practice/07-stacks/learn Valid Parentheses (LC20) | — |
| 9 | **`.back()`/`.front()`/`.top()` on an EMPTY container is UNDEFINED BEHAVIOR — believed it "returns 0"** | It does NOT return 0 — it reads unowned memory (garbage or crash). **Always guarantee non-empty before reading an end**, either with `!c.empty()` in the loop condition or a proven invariant (LC933: the just-pushed `t` is always `≥ t-3000`, so it's a sentinel that keeps the deque non-empty). This is his #1 boundary/empty-container leak in C++ clothing. | practice/08-queues-deque/learn LC933 Recent Calls (7/04) | — |
| 10 | **`sort`'s 3rd argument (comparator)** — didn't know what it is or how to pass it | It's a function `bool cmp(a, b)` = *"should a come BEFORE b?"* Pass a **named function** (by name, no `()`; inside `class Solution` it must be `static`) or a **lambda** `[](const pair<int,int>& a, const pair<int,int>& b){ return a.second > b.second; }`. `>` = biggest first, `<` = smallest first (the default). **Strict only — never `>=`** (breaks sort / can crash). Also: `map<count,val>` is NOT a fix — equal counts overwrite. | LC347 Top K Frequent (2026-09-28) | — |
| 11 | **3 slips in one file** — renamed a binding (`val`) then used another name (`value`); no `;` after `sort(...)` with a lambda; pushed a `pair` into `vector<int>` | Name once, reuse the exact name · a lambda call still ends in `;` · know the element TYPE of what you index (`s[j]` is a pair → `.first`). All compiler-catchable. | LC347 (2026-09-28) | — |
| 12 | **Never looped a hash container before** — "i never looped over map its my first" | **Set** gives the element: `for (int x : s)`. **Map** gives a pair: `for (auto& p : m)` → `p.first` key, `p.second` value (or `for (auto& [k,v] : m)`). Three things that bite: (a) **no index** — there is no `m[i]` meaning "the i-th entry", a hash table has no i-th; (b) **order is neither sorted nor insertion order** and may differ run to run; (c) `auto&` not `auto` — plain `auto` copies every pair. | LC128 (2026-10-03) — the fix for the TLE was *iterate the set, not `nums`* | — |
| 13 | **`unordered_map` used where `unordered_set` was meant** — stored `check[x] = 1` and never read the value | If you never read the stored value, the value is dead weight: use `unordered_set`. Disqualifier: *"order or membership?"* → membership ⇒ set. Same complexity, half the memory, and the loop variable becomes the element instead of a pair. | LC128 (2026-10-03) | — |
| 14 | **`vector`'s `operator[]` does NOT create slots — unlike `map`'s** | `vector<vector<int>> b;` then `b[4].push_back(x)` is **undefined behaviour** (sanitizer: *"applying non-zero offset to null pointer"*). A vector must be **pre-sized**: `vector<vector<int>> b(n+1);` makes `n+1` empty inner vectors. Contrast `map`/`unordered_map`, where `m[key]` *inserts* a default entry just by being touched — which is why `check[nums[i]]++` works. **Two containers, opposite rules; mixing them up is the classic.** Bucket sizing: counts run 0..n ⇒ **`n+1` slots**, and the walk must start at **`n`**, not `n-1`. | LC347 bucket re-solve (2026-10-05) | — |
| 15 | **One bucket slot cannot hold one value** — `vector<int> dummy(n+1)` and `dummy[count] = value` | **A count is not unique**: two values can share a frequency, and the second assignment destroys the first (`[1,2,1,2,1,2,3,1,3,2]`, both `1` and `2` appear 4×). Bucket-by-key ⇒ the slot type is a **collection**: `vector<vector<int>>`. Bonus: testing `.empty()` instead of truthiness also removes the **0-sentinel bug** — `if(dummy[i])` would silently skip the legitimate value `0` (`-10^4 <= nums[i] <= 10^4` includes 0). Same sentinel family as #7 and #9. | LC347 bucket re-solve (2026-10-05) | — |

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

## 2026-09-27 — LC49 brute (topic 01, problem 1)
Idea was correct unaided (sorted string as the key). All 7 errors were C++ mechanics, in 3 buckets:

**A. in-place vs returning.** Wrote `y = sort(s.begin(), s.end())`. `std::sort` returns **void** and mutates in place — it also would have destroyed the original string needed for output. Fix: copy first, then sort the copy.
- void/in-place: `sort` `reverse` `fill` · returns a value: `substr` `max` `accumulate`
- **Re-test:** next time he writes `x = <algorithm>(...)`, does he pause to ask which kind it is?
- 🔴 **RE-TEST FAILED 2026-10-03** (LC49 cold re-solve, +7d). Wrote `string temp = sort(strs[i].begin(), strs[i].end());` — byte-identical shape, same problem, 6 days later. It was his **only** bug in the whole re-solve, and it was this one. **Promoted to the weekly review list: `sort` / `reverse` / `fill` / `swap` mutate and return `void`; `substr` / `max` / `accumulate` / `find` / `lower_bound` / `max_element` return something. Before writing `x = f(...)`, say which list `f` is on.**

**B. container API.**
- `strs.length()` on a vector → `.size()` (`.length()` is std::string only)
- `if(!x[y])` on a `map<string, vector<string>>` → no `operator!` on a vector; and **`operator[]` INSERTS** a default entry just by reading. Use `x.count(y) == 0`.
- `map<string, vector<string> check;` → missing `>`
- `x[y] = map[check[y]];` → `map` is a type, not an object

**C. Python leaking in.** `for(key,value in x)` → `for (auto& [key, value] : x)` (C++17 structured binding).

**Topic-relevant:** reached for `map` (BST, O(log n)) in the hashing topic. Default should be `unordered_map` (O(1) avg) unless sorted order is needed.

## 2026-10-07 — LC454 (topic 01, rung 5)  ·  gap #16 + two re-fires
**#16 — the COST OF ONE OPERATION is part of the bound, and the container sets it.** He gave `O(a*b) + O(c*d)` with no per-step factor, and priced a `map` insert at **`L log L`** (the cost of sorting all L items *once*) instead of **`log L`** (one walk down an already-ordered tree).
- `unordered_map` / `unordered_set`: hash the key → jump to its bucket → **O(1) average**, the same single step at L = 10 and L = 40,000. Worst case O(L) if every key collides.
- `map` / `set`: a balanced BST = **binary search built into a structure** (the LC704/LC153 machine). Find or insert = walk from the root halving the range = **O(log L)**. At L = 40,000 that is ~16 steps, not 40,000·16.
- **Rule to say out loud:** a bound = *how many times the loop runs* × *what one iteration costs*. Name both. `O(n²)` for LC454 is only true because the inside costs 1 and not 16.
- Worked digits, LC454: 8×10⁴ ops × 1 = **8×10⁴** with `unordered_map`; × 16 = **1.3×10⁶** with `map`. Both pass a 10⁸/sec judge — the gap bites at 10⁷ ops.

**🔴 RE-FIRE of the 2026-09-27 gap B — reading a map with `operator[]` INSERTS.** Lines 78–79: `if(check1[-1*temp] > 0){ ans += check1[-1*temp]; }`. Every **missing** `(c+d)` silently creates a `0` entry, so the map can grow from 40,000 to 80,000 keys. The rule was already written on 09-27 ("use `x.count(y) == 0`") and did not transfer. To **test** membership: `.count()` / `.find()` / C++20 `.contains()`. To **accumulate**: just `ans += check1[-temp];` — a missing key yields 0, which makes the `if` on line 78 redundant anyway (band-aid echo).

**Also:** two lookups of the same key where one would do — hoist it (`auto it = check1.find(-temp); if(it != check1.end()) ans += it->second;`).

