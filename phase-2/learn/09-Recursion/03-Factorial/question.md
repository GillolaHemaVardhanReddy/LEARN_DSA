# 03 — Factorial  (M9 Recursion · cleanest self-similar definition)

🔗 **No direct LeetCode** — Striver Step-7 foundational drill.
(LC172 "Factorial Trailing Zeroes" exists but tests number theory, NOT this recursion.)

**Goal:** `n! = n * (n-1)!`, `0! = 1`. The textbook self-similar definition — the smaller
problem is literally the same problem.

## Signature
```cpp
long long fact(int n);
```

## Example
```
fact(5) -> 120      fact(0) -> 1
```

## Constraints (⚠️ MAGNITUDE — your overflow leak)
- Keep `n <= 20`. `long long` max ≈ 9.2e18; `20! = 2.4e18` fits, `21! = 5.1e19` **overflows**.
- Base case is `return 1` (empty product), **not** 0 — a 0 would zero out the whole product.

## The idea to derive
Base first (`n==0 -> 1`), then one combine line `return n * fact(n-1)`. Trust `fact(n-1)`.

## Judge graduation (LATER)
No judge for the drill. Recursion mechanics graduate on **LC509 / LC70** (06-Fibonacci).
