# LC1438 — Longest Subarray with |max−min| ≤ limit  (MEDIUM · TWO deques)

🔗 https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

**Goal:** length of the longest subarray where the abs diff between ANY two elements ≤ limit.
(Equivalently: `max(window) − min(window) ≤ limit`.)

## Signature
```cpp
int longestSubarray(vector<int>& nums, int limit);
```

## Examples
```
nums=[8,2,4,7], limit=4        -> 2   ([2,4] or [4,7])
nums=[10,1,2,4,7,2], limit=5   -> 4   ([2,4,7,2])
nums=[4,2,2,2,4,4,2,2], limit=0-> 3
```

## Constraints
- `1 <= n <= 1e5`, `1 <= nums[i] <= 1e9`, `0 <= limit <= 1e9`. (values up to 1e9 — watch types.)

## Reach for (help-allowed)
This is a **variable sliding window** where the validity test needs **both the window MAX and
the window MIN**. One monotonic deque gives you one extreme — so run **TWO deques**:
- `maxDq` decreasing (front = window max), `minDq` increasing (front = window min).
- Grow `r`. While `nums[maxDq.front()] - nums[minDq.front()] > limit`, shrink `l` (and pop
  either front whose index falls behind `l`).
- Track `r - l + 1`.
This is your LC239 engine, doubled. Recognition cue: **"window validity depends on max AND min" → two monotonic deques.**
