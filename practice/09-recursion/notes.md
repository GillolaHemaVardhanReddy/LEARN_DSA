# M9 — Recursion  ·  THE KEYSTONE  (teaching notes — reread cold, they rebuild the model)

> These notes TEACH, they don't just remind. Read top to bottom and the understanding comes back.
> Recursion is the foundation under Backtracking (M10), Trees (M12), and much of DP (M20–21).
> It's a **way of thinking**, not 4 problems — so we go slower and deeper than the linear patterns.

## 0. Striver videos (Step 7 — watch in order, AFTER these notes)
- **[008] Re-1 Introduction to Recursion** — https://youtu.be/yVdKa8dnKiE  ⭐ start here
- **[009] Re-2 Problems on Recursion** — https://youtu.be/un6PLygfXrA
- **[010] Re-3 Parameterised & Functional** — https://youtu.be/69ZCDFy-OUo
- **[011] Re-4 Problems on Functional Recursion** — https://youtu.be/twuC1F6gLI8
- **[012] Re-5 Multiple Recursion Calls** — https://youtu.be/kvRjNm4rVBE

---

## BIT 0 — The one sentence
> **Recursion = solving a problem by assuming you've already solved a smaller version of the SAME problem.**

That's the whole thing. Everything below is just *why that works* and *how to run it in your head*.

---

## BIT 1 — Why it exists (the "why")
Some problems are **self-similar** — they contain smaller copies of themselves:
- "Sum of `[1..n]`" = `n +` "sum of `[1..n-1]`". Subproblem = same shape, just smaller.
- A folder holds files *and folders* (which hold files and folders…).
- A tree node has children that are *themselves* trees.

For a **flat** problem ("add an array left to right"), a **loop** is perfect. But the moment a problem
**branches** — "go left OR right", "include this item OR not" — a loop can't naturally express it;
you'd have to hand-build and manage a stack. Recursion gives you that branching **for free**, because
**the language's call stack becomes your stack.** That's why recursion is the keystone under Trees,
Backtracking, and DP — those are all *branching* problems.

> **Loop = repeat a flat action. Recursion = break a problem into a smaller one of the same kind.**

---

## BIT 2 — The two non-negotiable parts
Every recursion has exactly two jobs:
1. **Base case** — the input so small you answer it *without* recursing. The floor. No base case (or a
   wrong one) = calls forever = **stack overflow / crash.**
2. **Recursive case** — do a little work, then hand a *strictly smaller* input to yourself.

The invariant that makes it terminate: **every call must make provable progress toward the base case.**
`f(n)` must call `f(n-1)` or `f(n/2)` — something *closer to the floor*. `f(n)` → `f(n)` never ends.

```cpp
int factorial(int n){
    if (n == 0) return 1;            // ← BASE: floor, no recursion
    return n * factorial(n - 1);     // ← RECURSIVE: smaller input (n-1), progress guaranteed
}
```

---

## BIT 3 — The leap of faith (THE mental unlock — read twice)
This is the hardest shift, and it's the whole game.

When you write `n * factorial(n-1)`, your brain wants to dive in and trace `factorial(n-1)` all the way
to the bottom. **Don't. You'll drown.**

Instead — **assume `factorial(n-1)` already returns the correct answer.** Treat it like a function
someone *else* wrote and tested. Your only job at this level:

> "Given a correct answer for the SMALLER problem, how do I use it + my current piece to build MY answer?"

For factorial: "If someone hands me `(n-1)!`, I just multiply by `n`. Done." You never think below one level.

Prove two things and it's automatically correct for **all** n (this is literally induction):
1. The **base case** is right.
2. **Assuming** the smaller call is right, your **combine step** is right.

You'll feel the urge to trace all the way down — resist it. **One layer. Trust the rest.**

---

## BIT 4 — The call stack (the "how" — the part you RUN BY HAND)
Leap of faith is how you *design*. This is how the machine *runs* it, so it's not magic.

Every call gets its own **frame** (own copy of params + locals), stacked like plates. Two phases.

**Winding down** (calls pile up, nobody has returned yet):
```
factorial(3)  → needs 3 * factorial(2)     ⟵ PAUSES here, waiting
  factorial(2)  → needs 2 * factorial(1)   ⟵ PAUSES, waiting
    factorial(1)  → needs 1 * factorial(0) ⟵ PAUSES, waiting
      factorial(0)  → hits BASE, returns 1 ⟵ first real answer
```
**Unwinding** (base hit → answers flow back UP, each paused frame resumes):
```
      factorial(0) = 1
    factorial(1) = 1 * 1 = 1     ⟵ resumes, plugs in the 1 it was waiting for
  factorial(2) = 2 * 1 = 2       ⟵ resumes
factorial(3) = 3 * 2 = 6         ⟵ resumes → FINAL
```
Burn in:
- The stack **IS the memory of "where was I."** Each paused frame remembers it still owes a multiply.
  That's why you don't manage a stack yourself — the language does.
- **Nothing after the recursive call runs until the call below returns.** The `n *` waits. This
  "work on the way back up" is the heart of it.
- Depth of stack = **O(depth) space**, even with no array allocated. A recursion `n` deep costs `n` frames.

---

## BIT 5 — The two shapes (Striver hammers these)
Same problem, two ways to move the answer around. Sum of `1..n`:

**Parameterised — carry the answer DOWN as a parameter:**
```cpp
void f(int i, int sum){
    if (i == 0){ cout << sum; return; }  // answer fully built by the time we hit base
    f(i - 1, sum + i);                    // accumulate on the way DOWN
}
```
Answer is complete *at the bottom*. Nothing happens on the way up.

**Functional — build the answer UP via the return value:**
```cpp
int f(int n){
    if (n == 0) return 0;
    return n + f(n - 1);                  // work happens on the way UP (leap-of-faith style)
}
```
Each frame does its bit *as it unwinds*.

Why care: **Trees & DP lean functional** (combine children's returned answers). **Backtracking leans
parameterised** (carry the current path down, collect at a leaf). Know both → pick the natural one.

---

## BIT 6 — The design recipe (how to WRITE any recursion) ⭐ this is your Gate-A
Answer these three, **in order**, BEFORE coding a single line:
1. **Base case?** — the smallest input + its direct answer. *(Wrong here → infinite loop.)*
2. **Smaller subproblem?** — how do I shrink the input by one honest step? *(Must be provably closer to base.)*
3. **Combine step?** — given the (trusted) smaller answer, how do I make mine? *(The leap-of-faith line.)*

Fill those three blanks and the recursion is basically written.

---

## BIT 7 — Complexity, read straight off the shape
- **One call chain, depth n** (factorial, sum): O(1) work × n calls → **O(n) time, O(n) stack space.**
- **Each call forks into two** (Fibonacci `fib(n)=fib(n-1)+fib(n-2)`): calls form a **binary tree**
  → **~O(2ⁿ) time.** A catastrophe — `fib(50)` ≈ 10¹⁵ calls, recomputing `fib(3)` thousands of times.

Feel that blow-up now, because the fix — **memoization / DP** — is literally "stop recomputing the same
subproblem." **DP = recursion + a notepad.** It lands *because* it hurts here first.

---

## BIT 8 — The classic traps (execution focus, boss)
1. **Missing / wrong base case** → stack overflow. Write the base *first*, always.
2. **No progress** → forgot to decrement, `f(n)` calls `f(n)` → infinite. Check: is the arg *strictly* smaller every call?
3. **Base placed after work** → you touch `arr[i]` and *then* check out-of-bounds. Check the base **before** using the current element.
4. **Forgetting O(depth) space** → deep recursion on huge input overflows the stack even with perfect logic.

---

## BIT 9 — Recognition cue (fill in YOUR words after the coding ladder)
> "problem breaks into a SMALLER copy of itself" / "try all choices" / "explore a tree of options" → recursion.

*(Your teach-it-back line goes here once you've coded the ladder — that's the L6 signal.)*

## The starter ladder (what we code next)
Print N times → print 1..N → print N..1 → sum of 1..N (param + functional) → factorial → reverse an
array (two-pointer via recursion) → check palindrome → **Fibonacci (the fork into TWO calls — the
gateway to Trees & DP).**
