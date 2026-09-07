# LC 977 — Squares of a Sorted Array · easy · TWO POINTERS

**Link:** https://leetcode.com/problems/squares-of-a-sorted-array/
**Building block:** CONVERGING + a **compare-the-ends decision** (move the bigger side). Primes the "move one side by comparison" idea that 3Sum / Container / Trapping all use.

---

## Problem (plain English)
A **sorted** array `nums` (can include negatives). Return the **squares**, sorted non-decreasing.

## Examples
| nums | answer |
|---|---|
| [-4,-1,0,3,10] | [0,1,9,16,100] |
| [-7,-3,2,3,11] | [4,9,9,49,121] |

## Constraints
- 1 ≤ n ≤ 10⁴ · −10⁴ ≤ nums[i] ≤ 10⁴ · sorted non-decreasing.
- **Follow-up: O(n)** without a sort.

## Before you code (recognition-first)
- Trivial brute force: square each, then `sort` → O(n log n). Get it if you like, then beat it.
- **The two-pointer insight:** the array is sorted, so the **largest squares live at the ENDS**
  (most-negative on the left, most-positive on the right). Compare `|nums[L]|` vs `|nums[R]|`,
  take the bigger square, **fill the result from the BACK**, and move that side inward. O(n).
- This "compare the two ends, move the bigger one" is the building block — it returns in greedy two-pointer problems.
- ⚠️ Boundary: fill index starts at `n-1` and goes down; `L <= R` loop; squaring negatives (use `long`? values ≤ 10⁴ so `int` square ≤ 10⁸, fits — but know why you checked).

## Result log
- Status: ___   Did O(n) two-pointer (not just sort)? ___   Building block (compare ends, move bigger): ___
