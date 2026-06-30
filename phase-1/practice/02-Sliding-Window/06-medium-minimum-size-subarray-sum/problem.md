# LC 209 — Minimum Size Subarray Sum  ·  Medium   ·   VARIABLE WINDOW

**Link:** https://leetcode.com/problems/minimum-size-subarray-sum/
**Topic:** Variable sliding window (SHORTEST) + running sum

---

## Problem (plain English)
Given an array of **positive** integers `nums` and a target `target`, return the **minimal
length** of a contiguous subarray whose sum is **≥ target**. If no such subarray exists,
return `0`.

## Examples
| nums | target | answer | why |
|---|---|---|---|
| [2,3,1,2,4,3] | 7 | 2 | `[4,3]` sums to 7, length 2 |
| [1,4,4] | 4 | 1 | `[4]` already ≥ 4 |
| [1,1,1,1,1,1,1,1] | 11 | 0 | whole array sums to 8 < 11 |

## Constraints
- `1 ≤ nums.length ≤ 10^5`, `1 ≤ nums[i] ≤ 10^4`, `1 ≤ target ≤ 10^9`
- (numbers are POSITIVE — that's what makes the window monotonic)

## Before you code — contrast this with LC 424
This is the **SHORTEST** variant. Opposite shape from char replacement:
1. Grow `right`, add `nums[right]` to a running `sum`.
2. While the window is **VALID** (`sum ≥ target`), record the length, then **shrink from
   the left** to try for an even shorter one. → this is where you NEED `while`, not `if`.
3. The answer is the **smallest** valid length ever recorded.

Watch your sentinel: what do you initialise the "best length" to, and how do you turn
"never found one" into the required `0`? (Your boundary-value checklist — run it.)

## Result log
- Status: ___   Why `while` is mandatory here (vs `if` in LC 424): ___
