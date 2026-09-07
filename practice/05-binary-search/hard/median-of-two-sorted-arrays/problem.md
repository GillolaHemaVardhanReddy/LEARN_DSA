# LC4 — Median of Two Sorted Arrays · Hard

🔗 https://leetcode.com/problems/median-of-two-sorted-arrays/

Return the median of two sorted arrays in **O(log(m+n))**.

- `nums1 = [1,3], nums2 = [2]` → `2.0`
- `nums1 = [1,2], nums2 = [3,4]` → `2.5`

**Constraints:** `0 <= m,n <= 1000` · `1 <= m+n <= 2000` · `-1e6 <= vals <= 1e6`.

PATTERN (name it before coding): ______________________
Self-gate: the `O(log)` bound forces BS. Binary-search a **partition** of the SHORTER array; the
other partition is forced (left halves total `(m+n+1)/2`). Valid when `maxLeftA<=minRightB &&
maxLeftB<=minRightA`. Use `±INF` sentinels at the edges. The canonical "BS on something that isn't
the array index" hard.
