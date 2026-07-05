# 02 — Sum of 1..N  (M9 Recursion · the TWO SHAPES)

🔗 **No direct LeetCode** — Striver Step-7 foundational drill (Re-3/Re-4, parameterised vs functional).

**Goal:** compute `1+2+...+n` **two ways**, so both shapes live in your hands:
- **Parameterised** — carry the running sum DOWN as an argument; base case uses it.
- **Functional** — build the answer UP through the return value (`return n + f(n-1)`).

## Signatures
```cpp
long long sumParam(int i, long long acc);   // accumulate on the way down
long long sumFunc(int n);                    // build up via return value
```

## Example
```
sumParam(5, 0) -> 15      sumFunc(5) -> 15
```

## The idea to derive
Both have base `n==0`. Parameterised RETURNS the carried `acc` at the floor (answer already
built). Functional does the `+` on the way back UP (leap of faith: trust `f(n-1)`).

## Judge graduation (LATER)
No judge for the drill itself. The functional-shape muscle graduates on **LC509 Fibonacci**
and every "combine children's answers" tree problem in M12.
