# LC149 — Max Points on a Line · Hard

🔗 https://leetcode.com/problems/max-points-on-a-line/

`points[i] = [x, y]`. Return the max number of points that lie on the same straight line.

- `[[1,1],[2,2],[3,3]]` → `3`
- `[[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]` → `4`

**Constraints:** `1 <= n <= 300` · `-1e4 <= x,y <= 1e4` · all points unique.

PATTERN (name it before coding): ______________________
Self-gate: fix an **anchor**, group the rest by the **slope** to it (hash a gcd-reduced `(dy,dx)` pair,
never a float). Biggest group + anchor = answer. Collinearity test without division = **cross product
== 0**. The hashing flavor in disguise (group-by-key). Edge: `n <= 2` → answer is `n`.
