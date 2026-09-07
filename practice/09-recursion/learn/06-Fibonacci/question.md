# 06 — Fibonacci  (M9 Recursion · ⭐ THE FORK → the gateway to DP)

🔗 **LC509 — Fibonacci Number**  ·  https://leetcode.com/problems/fibonacci-number/  (EASY)
🔗 **Twin: LC70 — Climbing Stairs**  ·  https://leetcode.com/problems/climbing-stairs/  (EASY)
Both are real judge targets. LC70 is literally Fibonacci in disguise (ways(n)=ways(n-1)+ways(n-2))
— submitting it proves the RECOGNITION, not just the recall.

**Goal:** `fib(0)=0, fib(1)=1, fib(n)=fib(n-1)+fib(n-2)`. The first recursion that **forks into
two calls** — building a call TREE. That tree is where the O(2ⁿ) catastrophe lives.

## Signature (LC509)
```cpp
int fib(int n);        // 0 <= n <= 30
```

## Example
```
fib(2)=1  fib(3)=2  fib(4)=3  fib(10)=55        LC70: climbStairs(3)=3, climbStairs(5)=8
```

## The idea to derive (⭐ do the BRIDGE — don't skip it)
1. **BRUTE:** naive `fib(n-1)+fib(n-2)`, base `n<=1 -> n`. O(2ⁿ).
2. **BRIDGE:** draw `fib(5)`'s call tree. Count how many times `fib(2)` is computed. That
   repeated work — the SAME subproblem recomputed exponentially — is the whole disease.
3. **OPTIMAL:** a **notepad** (memo array). Compute each `fib(k)` once, store, reuse.
   Recursion + cache = **top-down DP**. O(n).

## Constraints / magnitude
- LC509 caps `n<=30` (fits int). Our drill uses `long long` so you can push `fibMemo(90)`
  and watch it stay instant while `fibBrute(90)` never finishes. THAT gap is why DP exists.

## Judge graduation
✅ **Submit LC509**, then **LC70 Climbing Stairs** cold (recognise it AS Fibonacci — that's the
transfer rep). Memoized version is the clean submit.
