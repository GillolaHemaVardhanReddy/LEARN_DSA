# LC862 — Shortest Subarray with Sum ≥ K  (HARD · ⭐ the PARKED one, now unlocked)

🔗 https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

**Goal:** length of the **shortest** non-empty subarray with sum **≥ k**, or `-1` if none.
⚠️ Array has **negatives** — that's why plain sliding window (LC209) fails and you need the deque.

## Signature
```cpp
int shortestSubarray(vector<int>& nums, int k);
```

## Examples
```
nums=[1], k=1        -> 1
nums=[1,2], k=4      -> -1
nums=[2,-1,2], k=3   -> 3
```

## Constraints
- `1 <= n <= 1e5`, `-1e5 <= nums[i] <= 1e5`, `1 <= k <= 1e9`.
- Sum of 1e5 values up to 1e5 → **prefix sums overflow int. Use `long long`.** (Your overflow leak — pre-size it.)

## Reach for (help-allowed) — this IS your LC239 engine over prefix sums
1. Build prefix sums `P[0..n]` (`P[i]` = sum of first i elements), as `long long`.
2. A subarray `(l,r]` has sum `P[r] - P[l]`. You want the shortest `r-l` with `P[r]-P[l] >= k`.
3. Sweep `r` left→right with a **monotonic INCREASING deque of indices** into P:
   - **Answer-pop (front):** while `P[r] - P[dq.front()] >= k` → candidate `r - dq.front()`, then
     `pop_front` (that l can never give a shorter answer for a later r — it's used up).
   - **Monotonic-pop (back):** while `P[r] <= P[dq.back()]` → `pop_back` (a bigger-or-equal earlier
     prefix is strictly worse as a left endpoint — smaller P[l] gives bigger sum AND is closer).
   - push `r`.
Recognition cue: **"shortest subarray, sum ≥ K, WITH negatives → monotonic deque over prefix sums."**
Why the deque (not sliding window): negatives break monotonicity of window sums, so you can't
just shrink from the left. The deque keeps only *useful* left endpoints.
