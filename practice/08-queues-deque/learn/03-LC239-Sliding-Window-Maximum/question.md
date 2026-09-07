# LC239 — Sliding Window Maximum  (HARD · ⭐ monotonic deque GATE)

🔗 https://leetcode.com/problems/sliding-window-maximum/

**Goal:** a window of size `k` slides left→right over `nums`. Return the **max of every window**.

## Signature
```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k);
```

## Example
```
nums=[1,3,-1,-3,5,3,6,7], k=3  ->  [3,3,5,5,6,7]

[1  3 -1] -3  5  3  6  7   -> 3
 1 [3 -1 -3] 5  3  6  7    -> 3
 1  3 [-1 -3 5] 3  6  7    -> 5
 ...
```

## Constraints
- `1 <= n <= 1e5`,  `1 <= k <= n`,  `nums[i] in [-1e4, 1e4]`.
- n·k up to 1e10 → the O(n·k) brute TLEs on the judge (still the correct **oracle** for the local stress test).

## The pattern (M8 gate)
Monotonic **deque** of **indices**, values kept **decreasing front→back**:
- **expire left:** `pop_front` while `front <= i-k` (slid out of window)
- **enter right:** `pop_back` while `nums[back] < nums[i]` (older & smaller can never win), then `push_back(i)`
- **read:** once `i >= k-1`, answer = `nums[front]` (front is the current max by construction)

Each index enters & leaves once → **O(n)**.
**Gate to pass:** explain out loud *why* the front is always the window max in O(1) amortized.
