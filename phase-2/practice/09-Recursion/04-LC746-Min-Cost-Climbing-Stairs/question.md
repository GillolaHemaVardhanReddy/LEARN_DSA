# LC746 — Min Cost Climbing Stairs  (EASY · recursion -> memo DP)

🔗 https://leetcode.com/problems/min-cost-climbing-stairs/

**Goal:** each step `i` has a cost `cost[i]`. You may start at index `0` or `1`. From step `i`
you pay `cost[i]` and climb 1 or 2 steps. Reach the **top** (just past the last index) for the
**minimum total cost**. Return that min cost.

## Signature
```cpp
int minCostClimbingStairs(vector<int>& cost);
```

## Example
```
cost=[10,15,20]                        -> 15   (start at idx 1, pay 15, climb 2 -> top)
cost=[1,100,1,1,1,100,1,1,100,1]       -> 6    (hop the 1's, skip every 100)
```

## Constraints
- `2 <= cost.length <= 1000`
- `0 <= cost[i] <= 999`

## The idea to derive
It's the **Fibonacci skeleton** — from step `i` you came from `i+1` or `i+2` — but `+` becomes
`min` (you want the cheaper of the two onward paths):

`f(i)` = min cost to REACH the top starting FROM step `i` = `cost[i] + min(f(i+1), f(i+2))`.

- **Base case:** `f(i) = 0` when `i >= n` — you're already at or past the top, nothing more to pay.
- **Two entry points:** you can start at 0 or 1 -> answer = `min(f(0), f(1))`.
- **Boundary detail:** "the top" is *past* the last index (index `n`), not the last step itself —
  that's what the `i >= n` base captures. Get that off-by-one wrong and you overpay/underpay.
- **Naive recursion recomputes `f(i)` from both `i-1` and `i-2`** -> exponential. **Memoize**
  (cache keyed by step index, sentinel `-1`) -> each index solved once -> **O(n)**.

Recognition cue: **"climb 1 or 2 steps, minimize/count paths" -> Fibonacci-shaped recurrence;
`+`->`min` for cost, memoize the repeated index.**
