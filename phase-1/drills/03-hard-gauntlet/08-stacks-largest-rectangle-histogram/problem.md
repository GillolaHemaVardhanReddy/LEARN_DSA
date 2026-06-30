# LC84 — Largest Rectangle in Histogram · Hard

🔗 https://leetcode.com/problems/largest-rectangle-in-histogram/

Each bar has width `1` and height `heights[i]`. Return the area of the **largest rectangle** that
fits entirely under the histogram.

- `heights = [2,1,5,6,2,3]` → `10`  (bars `5` and `6` → rectangle of height 5 × width 2 = 10)
- `heights = [2,4]` → `4`

**Constraints:** `1 <= n <= 1e5` · `0 <= heights[i] <= 1e4`.

PATTERN (name it before coding): ______________________
Self-gate: fix each bar as the **limiting (shortest) height** — the rectangle stretches left and
right until it hits a **shorter** bar. So per bar you need nearest-smaller-to-the-LEFT and
nearest-smaller-to-the-RIGHT → a monotonic-**increasing** stack delivers both in O(n). The
**measure-width-between-smaller-bars** flavor — the canonical hard. (Sentinel `0` at the end helps flush.)
