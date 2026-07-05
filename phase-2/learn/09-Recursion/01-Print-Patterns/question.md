# 01 — Print Patterns  (M9 Recursion · mechanics drill)

🔗 **No direct LeetCode** — this is a Striver Step-7 foundational drill (Re-2/Re-3).
Its job is to install the reflex, not to be judged.

**Goal:** three tiny recursions — `printNTimes(n)`, `print1toN(n)`, `printNto1(n)` — to feel
the base case and the **order trick**: doing the work *before* the recursive call counts UP,
*after* it counts DOWN.

## Signatures
```cpp
void printNTimes(int n);   // "hi" n times
void print1toN(int n);     // 1 2 3 ... n   (work BEFORE the call)
void printNto1(int n);     // n ... 3 2 1   (work AFTER the call)
```

## Example
```
print1toN(5) -> 1 2 3 4 5      printNto1(5) -> 5 4 3 2 1
```

## The idea to derive
Same skeleton for `1toN` and `Nto1` — only the position of the `cout` (before vs after the
recursive call) flips the direction. Base case = `n==0 return`. Run it and SEE the flip.

## Judge graduation (where this muscle gets tested for real, LATER)
These print reps have no judge. The recursion mechanic they build gets its judge-AC in
**06-Fibonacci → LC509 / LC70** and the backtracking module (M10).
