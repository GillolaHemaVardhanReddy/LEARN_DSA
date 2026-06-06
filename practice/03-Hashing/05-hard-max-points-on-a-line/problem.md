# LC 149 — Max Points on a Line  ·  Hard   ·   HASHING (count by slope)  ·  STRETCH

**Link:** https://leetcode.com/problems/max-points-on-a-line/
**Topic:** Hash map of slopes  ·  ⚠️ STRETCH (geometry-flavoured; attempt then discuss)

---

## Problem (plain English)
Given points on a 2D plane, return the **max number of points that lie on one straight line**.

## Examples
| points | answer |
|---|---|
| [[1,1],[2,2],[3,3]] | 3 |
| [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]] | 4 |

## Constraints
- `1 ≤ points.length ≤ 300`, coordinates fit in int. O(n²) is fine here.

## Before you code (this is a stretch — partial is OK)
1. Fix one point `A`. Every other point makes a **slope** with `A`. Points sharing the same
   slope (through `A`) are collinear with `A`.
2. For each `A`, count slopes in a hash map; the biggest bucket (+1 for A) is the best line through A.
   Repeat for all `A`, take the max. O(n²).
3. **Gotchas:** vertical lines (dx=0 → infinite slope), and slope as a float is imprecise —
   better to use a **reduced (dy/gcd, dx/gcd) pair** as the key. Duplicates points too.
4. Don't stress the precision details — get the slope-bucket idea, bring questions.

## Result log
- Status: ___   What I want to discuss (slope key / precision): ___
