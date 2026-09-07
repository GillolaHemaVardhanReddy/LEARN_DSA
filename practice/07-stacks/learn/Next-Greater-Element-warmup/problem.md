# Next Greater Element (to the right) — Monotonic Stack WARM-UP

> **Not a ladder rung — a skeleton-builder.** This is the *generic* monotonic-stack
> problem. Build the engine here once, from your own hand-trace, so the muscle is in
> your hands BEFORE you map it onto Daily Temperatures (LC739) solo. (2026-06-23)

## Statement
Given `vector<int> nums`, return `vector<int> ans` where `ans[i]` is the **next element
to the right of `i` that is strictly greater than `nums[i]`**, or `-1` if none exists.

## Examples
```
nums = [3, 1, 2, 5, 4]  ->  ans = [5, 2, 5, -1, -1]
   3's next-greater is 5, 1's is 2, 2's is 5, 5 has none, 4 has none.

nums = [2, 1, 3]        ->  ans = [3, 3, -1]
nums = [5, 4, 3]        ->  ans = [-1, -1, -1]   (strictly decreasing -> none)
nums = [1, 2, 3]        ->  ans = [2, 3, -1]
```

## What you already locked (2026-06-23, from your own trace)
- **When:** "nearest conditioned element in one direction" — you had this cold.
- **Why a stack:** it parks the elements *still waiting for their answer*; a newcomer
  pays off a whole **batch** at once (in `[3,1,2,5,4]`, the `5` resolved both `2` and `3`).
- **Why monotonic:** decreasing order is a *consequence* — anything bigger pops the
  smaller ones on arrival, so a bigger element can never sit on a smaller one.
- **Why O(n):** each index is pushed once and popped at most once -> ≤2n ops, not O(n²).
- **Stack holds INDICES** (derive value `nums[j]` and distance `i-j` from the index —
  one driver, derive the rest).

Now turn that trace into code in `solution.cpp`.
