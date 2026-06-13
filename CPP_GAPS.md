# CPP_GAPS.md — C++ Fluency Track (Hema Vardhan)

> Track 2 of the training plan. A C++ primitive gap is a **vocabulary** gap, not a thinking
> failure — log it with the fix the moment it surfaces, review weekly so it never blindsides
> you twice. ~10 min/session.

| # | Gap (what I didn't know) | The fix / idiom | Surfaced on | Reviewed |
|---|---|---|---|---|
| 1 | How to copy one vector into another | `b = a;` (whole copy) · `b.assign(a.begin(), a.end());` (from range) · `vector<int> b(a);` (at construction). NOTE: `b(a.begin(),a.end())` only works when *declaring*, not on an existing vector. | drill1 P2 | — |
| 2 | Integer overflow — type too small for the arithmetic | `int` ≈ ±2.1e9; `long long` ≈ ±9.2e18. Binary search mid: `mid = lo + (hi-lo)/2` (never `(lo+hi)/2`). Accumulators that can exceed ~2e9 → `long long` (incl. the function's return type). | LC875 Koko (MISTAKE #8) | — |

---

## Idioms worth drilling (add as they come up)
- Frequency array vs map: `int cnt[26]={0};` for lowercase letters; `unordered_map<int,int>` for arbitrary keys.
- `unordered_map` presence: use `.count(k)` or `.find(k)!=end()` — NOT `if(map[k])` (index/value 0 is falsy, and `[]` inserts).
- Sort with comparator: `sort(v.begin(), v.end(), [](auto&a, auto&b){ return a > b; });` (descending).
- Two-pointer in-place write: `nums[k++] = nums[i];` — overwrite the front, no extra container.
