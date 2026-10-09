# C++ for CP — the 12-item track (agreed 2026-09-28)

**Format:** one item per day · 10 min · AFTER the block's problem closes · short explanation on a neutral example → boss writes 3–5 lines → mark done here. No quiz.
Keep it simple and short when teaching — boss: "text dumped is not understandable".

| # | Item | Status |
|---|---|---|
| 1 | Number types — `int` vs `long long`, overflow | ✅ 2026-10-09 — fix `1LL*n*n` his; first predicted "correct value" for `long long x = n*n` (n=5e4) while saying n*n is int → corrected: the INTERMEDIATE overflows. Rule: every step must fit, widen BEFORE the math |
| 2 | `&` reference — don't copy big arrays | ▶ next |
| 3 | vector + string — all the tools | |
| 4 | pair — two values together | |
| 5 | map + set | (started: LC49, LC347) |
| 6 | stack, queue, priority_queue | |
| 7 | iterators — what `.begin()` / `.end()` are | |
| 8 | built-in functions — sort, reverse, max_element… | |
| 9 | lambdas | (started: LC347) |
| 10 | bits — `&` `|` `^` `<<` | |
| 11 | math — gcd, `% 1e9+7` | |
| 12 | writing `main()` yourself (Codeforces format) | before first CF round |
