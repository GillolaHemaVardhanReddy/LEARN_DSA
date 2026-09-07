# LC50 — Pow(x, n)  (MEDIUM · ⭐ fast exponentiation / binary power)

🔗 https://leetcode.com/problems/powx-n/

**Goal:** implement `pow(x, n)` — compute `x` raised to the power `n` — in **O(log n)**, not O(n).

## Signature
```cpp
double myPow(double x, int n);
```

## Example
```
myPow(2.0, 10)  -> 1024.0
myPow(2.0,  -2) -> 0.25       (= 1 / 2^2)
myPow(2.1,  3)  -> 9.261
```

## Constraints
- `-100 < x < 100`
- `-2^31 <= n <= 2^31 - 1`
- **Trap 1 — negative n:** `x^n = 1 / x^(-n)`. Do the work on `|n|`, then invert.
- **Trap 2 — INT_MIN overflow:** when `n == INT_MIN` (`-2^31`), `-n` does **not** fit in an
  `int` (`+2^31` overflows). Copy `n` into a `long`/`long long` **before** negating it.

## The idea to derive — fast power
Linear multiply (`x * x * ... ` |n| times) is O(n) and **TLEs** for `|n|` up to 2^31.

The collapse comes from one identity:
```
x^n = (x^(n/2))^2                 (n even)
x^n = (x^(n/2))^2 * x             (n odd)
```
Each step **halves** the exponent instead of decrementing it → only ~log₂(n) multiplies.

Recursion:
- base case `n == 0` → `1`
- `half = myPow(x, n/2);  return half*half*(n%2 ? x : 1)`
- handle negative n up front: widen to `long`, flip sign, return `1.0 / myPow(x, |n|)`.

Recognition cue: **"compute x^n / repeated squaring / exponent up to ~2^31" → binary
exponentiation, halve the exponent → O(log n).** (Same engine powers modular pow in number theory.)
