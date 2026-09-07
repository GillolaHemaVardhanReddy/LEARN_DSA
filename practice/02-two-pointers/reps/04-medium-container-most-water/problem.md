# LC 11 — Container With Most Water · MEDIUM · TWO POINTERS

**Link:** https://leetcode.com/problems/container-with-most-water/
**Building block:** GREEDY converging — steer by a **derived** quantity (area), and always move the **limiting** side. New *reasoning*, not just sum-steering.

---

## Problem (plain English)
`height[i]` = a vertical line at x=i. Pick two lines forming a container with the x-axis;
return the **maximum water area** it holds. Area = `min(height[L], height[R]) * (R - L)`.

## Examples
| height | answer |
|---|---|
| [1,8,6,2,5,4,8,3,7] | 49 |
| [1,1] | 1 |

## Constraints
- 2 ≤ n ≤ 10⁵.  (10⁵ → O(n²) brute force = 10¹⁰ ❌ → **target O(n)**.)

## Before you code (recognition-first)
- Brute force = all pairs O(n²) → too slow for n=10⁵.
- Shape = **converging**, but the move rule is **greedy**, not sum-based:
  start `L=0, R=n-1`; area is capped by the **shorter** wall. Moving the **taller** wall can never help
  (width shrinks, height still capped by the short one) → **always move the SHORTER wall inward.**
- That "move the limiting side" insight is the building block — it returns in Trapping Rain Water (05).
- Prove to yourself *why* discarding the shorter wall is safe (same flavor as why two-pointer is safe on sorted data).

## Result log
- Status: ___   Building block (greedy: move the limiting side): ___
