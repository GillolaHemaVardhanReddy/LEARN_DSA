# LC1696 — Jump Game VI  (MEDIUM · deque-optimized DP)

🔗 https://leetcode.com/problems/jump-game-vi/

**Goal:** start at index 0, each move jump to any index in `[i+1, i+k]`. Score = sum of nums
at visited indices. Return the **max score** to reach the last index.

## Signature
```cpp
int maxResult(vector<int>& nums, int k);
```

## Examples
```
nums=[1,-1,-2,4,-7,3], k=2   -> 7   ([1,-1,4,3])
nums=[10,-5,-2,4,0,3], k=3   -> 17  ([10,4,3])
nums=[1,-5,-20,4,-1,3,-6,-3], k=2 -> 0
```

## Constraints
- `1 <= n, k <= 1e5`, `-1e4 <= nums[i] <= 1e4`.

## Reach for (help-allowed) — the "deque optimizes a DP transition" pattern
DP: `dp[i]` = best score to reach `i`. Transition: `dp[i] = nums[i] + max(dp[i-k .. i-1])`.
That inner `max` over the last k states is O(k) → O(n·k) total (TLE).

But **"max of the last k values"** is exactly the monotonic-deque trigger. Slide a deque of
indices over `dp`, front = max dp in the window `[i-k, i-1]`:
- expire front while `front < i - k`
- `dp[i] = nums[i] + dp[dq.front()]`
- push i after popping back all `dp[back] <= dp[i]`
Answer = `dp[n-1]`. This is LC239's engine wired into a DP recurrence → **O(n)**.
Recognition cue: **"DP transition = max/min over a sliding window of previous states" → monotonic deque.**
