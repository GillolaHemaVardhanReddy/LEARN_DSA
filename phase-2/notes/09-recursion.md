# M9 — Recursion  (study notes)  ·  THE KEYSTONE

> Recursion is the foundation under Backtracking (M10), Trees (M12), and much of DP (M20–21).
> We go SLOWER and DEEPER here than the linear patterns — it's a way of thinking, not 4 problems.

## 0. Striver videos (Step 7 — watch in order)
- **[008] Re-1 Introduction to Recursion** — https://youtu.be/yVdKa8dnKiE  ⭐ start here
- **[009] Re-2 Problems on Recursion** — https://youtu.be/un6PLygfXrA
- **[010] Re-3 Parameterised & Functional** — https://youtu.be/69ZCDFy-OUo
- **[011] Re-4 Problems on Functional Recursion** — https://youtu.be/twuC1F6gLI8
- **[012] Re-5 Multiple Recursion Calls** — https://youtu.be/kvRjNm4rVBE

---

## 1. What recursion IS
A function that **calls itself on a smaller version of the same problem**, until the problem is
small enough to answer directly. Two non-negotiable parts:

1. **Base case** — the smallest input you can answer WITHOUT recursing. (Missing/wrong base = stack overflow.)
2. **Recursive case** — solve a *smaller* subproblem, then combine. You must make **provable progress**
   toward the base case on every call, or it never terminates.

**The leap of faith (the mental unlock):** *assume* the recursive call already works correctly for
the smaller input. Don't trace it all the way down in your head — trust it, and just handle "what do
I do with that answer + my current piece." This is the single hardest mindset shift; it's the whole game.

## 2. The call stack (why it works)
Each call gets its own frame (its own local variables) pushed on the **call stack**. When a call
returns, its frame pops and control resumes in the caller. The stack IS the memory of "where was I."
Depth of recursion = height of the stack → **O(depth) space**, even if no array is allocated.

## 3. Two shapes (Striver's framing)
- **Parameterised:** carry the answer DOWN as an argument. `f(i, sum+arr[i])`; base case prints/uses `sum`.
- **Functional:** build the answer UP via the return value. `return arr[i] + f(i+1)`.
Same problem, two styles — know both; some problems want one, some the other.

## 4. The starter ladder (what we'll code tomorrow)
Print N times → print 1..N → print N..1 → sum of first N (param + functional) → factorial →
reverse an array (two-pointer via recursion) → check palindrome → **Fibonacci (multiple recursion —
the fork into TWO calls, the gateway to trees & DP).**

## 5. Complexity intuition (build it early)
- One call chain of depth n → **O(n)** time, **O(n)** stack space.
- Each call forks into 2 (Fibonacci) → **O(2ⁿ)** time (the tree of calls) — this pain is exactly
  what **memoization / DP** later fixes. Feel the blow-up here so DP's fix lands.

## 6. Recognition cue (fill in your words after the ladder)
> "problem breaks into a SMALLER copy of itself" / "try all choices" / "explore a tree of options" → recursion.
