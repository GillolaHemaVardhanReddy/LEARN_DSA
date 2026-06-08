# LC 167 — Two Sum II (Input Array Is Sorted) · easy · TWO POINTERS

**Link:** https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
**Building block:** CONVERGING pointers, sum-steered — the core mechanic of the whole topic.

---

## Problem (plain English)
A **1-indexed**, **sorted** array `numbers` and a `target`. Return the **1-based indices**
`[i, j]` (i < j) of the two numbers that add up to `target`. Exactly one solution; can't reuse an element.

## Examples
| numbers | target | answer |
|---|---|---|
| [2,7,11,15] | 9 | [1,2] |
| [2,3,4] | 6 | [1,3] |
| [-1,0] | -1 | [1,2] |

## Constraints
- 2 ≤ n ≤ 3·10⁴ · sorted ascending · exactly one solution.

## Before you code (recognition-first)
- cue line: it's **sorted** + find a **pair by sum** → __?
- Shape = **converging**: `L=0`, `R=n-1`. Let the **sum vs target** decide which pointer moves.
  - sum too big → which pointer, which way? · sum too small → ?
- Why is hashing *also* possible here but two pointers *preferred*? (think space.)
- ⚠️ Output is **1-indexed** — don't return 0-based.

## Result log
- Status: ___   Building block (converging, sum-steered): ___
