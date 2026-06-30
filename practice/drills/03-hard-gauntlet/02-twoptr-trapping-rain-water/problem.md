# LC42 — Trapping Rain Water · Hard

🔗 https://leetcode.com/problems/trapping-rain-water/

`height[i]` = the height of a bar of width `1`. After rain, return how many units of water are
trapped between the bars.

- `height = [0,1,0,2,1,0,1,3,2,1,2,1]` → `6`
- `height = [4,2,0,3,2,5]` → `9`

**Constraints:** `1 <= n <= 2e4` · `0 <= height[i] <= 1e5`.

PATTERN (name it before coding): ______________________
Self-gate: think about ONE position `i`. The water sitting on top of bar `i` is capped by the
**tallest wall to its left** and the **tallest wall to its right** — water level = `min(maxLeft,
maxRight)`, and the trapped amount = `min(maxLeft, maxRight) - height[i]` (never negative). Brute
re-scans both directions per `i` (O(n²)). Bottleneck = recomputing maxLeft / maxRight every time.
Two routes to O(n): precompute both as prefix/suffix arrays, OR the **two-pointer** trick (move the
shorter wall inward — the side with the smaller wall is the one that's *certain*). Build your OWN
hostile input (a deep well? a descending staircase that traps nothing?) and self-trace before "done".
