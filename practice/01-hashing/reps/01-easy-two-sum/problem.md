# LC 1 — Two Sum  ·  Easy   ·   HASHING (complement lookup)

**Link:** https://leetcode.com/problems/two-sum/
**Topic:** Hash map — the canonical "look up the complement in O(1)" move

---

## Problem (plain English)
Return the **indices** of the two numbers that add to `target`. Exactly one answer; can't
reuse an element. This is the seed idea behind ALL the prefix+hash problems you solved.

## Examples
| nums | target | answer |
|---|---|---|
| [2,7,11,15] | 9 | [0,1] |
| [3,2,4] | 6 | [1,2] |
| [3,3] | 6 | [0,1] |

## Constraints
- `2 ≤ nums.length ≤ 10^4`, exactly one solution. Beat O(n²).

## Before you code (the move to internalise)
1. Brute force O(n²): try every pair. Bottleneck = re-searching for the complement.
2. **One pass + hash map** `value -> index`: for each `x`, look up `target - x`. If present, done.
   Look up BEFORE inserting `x` (so you don't pair an element with itself).

## Result log
- Status: ___   Why look up before insert: ___
