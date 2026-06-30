# LC719 — Find K-th Smallest Pair Distance · Hard

🔗 https://leetcode.com/problems/find-k-th-smallest-pair-distance/

Distance of a pair = `|a − b|`. Return the **k-th smallest** distance over all pairs `i < j`.

- `nums = [1,3,1], k = 1` → `0`
- `nums = [1,6,1], k = 3` → `5`

**Constraints:** `2 <= n <= 1e4` · `0 <= nums[i] <= 1e6` · `1 <= k <= n(n−1)/2`.

PATTERN (name it before coding): ______________________
Self-gate: too many distances to sort — but the **answer** is one int in `[0, max−min]`. BS on the
distance `d`; `countPairs(<=d)` is monotonic; smallest `d` with `count >= k` wins. Count in O(n) via
sort + sliding window (for each `r`, smallest `l` with `nums[r]−nums[l] <= d`, add `r−l`). ⭐ The
"k-th smallest distance" you tapped out on before (LC719) — own it now.
