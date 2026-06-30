# LC410 — Split Array Largest Sum · Hard

🔗 https://leetcode.com/problems/split-array-largest-sum/

Split `nums` into `k` non-empty **contiguous** subarrays so the **largest subarray sum is
minimized**. Return that minimized largest sum.

- `nums = [7,2,5,10,8], k = 2` → `18`  (`[7,2,5]` + `[10,8]`)
- `nums = [1,2,3,4,5], k = 2` → `9`

**Constraints:** `1 <= n <= 1000` · `0 <= nums[i] <= 1e6` · `1 <= k <= min(50, n)`.

PATTERN (name it before coding): ______________________
Self-gate: "minimize the largest ___" + a monotonic feasibility check = **binary search on the
answer**. Twin of LC1011 (Capacity to Ship in D days) you already AC'd. Search the answer in
`[max(nums), sum(nums)]`; `feasible(cap)` = greedily count pieces, new piece when sum would exceed
`cap`, feasible if pieces ≤ k. **Magnitude:** sum of 1000×1e6 = 1e9 → fits int, but watch the seed.
