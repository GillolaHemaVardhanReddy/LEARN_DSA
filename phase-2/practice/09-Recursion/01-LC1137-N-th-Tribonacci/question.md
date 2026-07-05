# LC1137 — N-th Tribonacci Number  (EASY · recursion -> memoization)

🔗 https://leetcode.com/problems/n-th-tribonacci-number/

**Goal:** the Tribonacci sequence is `T0=0, T1=1, T2=1`, and `T(n)=T(n-1)+T(n-2)+T(n-3)`
for `n>=3`. Return `T(n)`.

## Signature
```cpp
int tribonacci(int n);
```

## Example
```
trib(4)  = 4        (0,1,1,2,4)
trib(25) = 1389537
```

## Constraints
- `0 <= n <= 37`, answer fits in a signed 32-bit int.

## The idea to derive
It's Fibonacci with **three** terms instead of two. Naive triple recursion recomputes the
same `T(k)` exponentially often → O(3^n).

Each `T(k)` only ever has ONE value, so compute it once and cache it — **memoization** (a
notepad). Check the cache, compute + store, reuse → O(n) time, O(n) space.
- base cases: `T0=0`, `T1=1`, `T2=1`
- recurrence: `T(n) = T(n-1) + T(n-2) + T(n-3)`
Recognition cue: **"value depends on a fixed number of smaller subproblems, recomputed
overlapping" → memoize the recursion.**
