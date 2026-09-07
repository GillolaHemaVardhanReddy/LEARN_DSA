# LC 724 — Find Pivot Index  ·  Easy

**Link:** https://leetcode.com/problems/find-pivot-index/
**Module:** M5 Prefix Sum  **Pattern:** Prefix Sum (pure — NO hash)  **Tier:** A (pattern named)

---

## Problem (plain English)
Given an integer array `nums`, find the **leftmost pivot index** `i` where the sum of all
numbers **strictly to the left** of `i` equals the sum of all numbers **strictly to the
right** of `i`. Return that index, or `-1` if none exists. (Edge: index 0 has empty left
sum = 0; last index has empty right sum = 0.)

## Examples
| nums | answer | why |
|---|---|---|
| [1,7,3,6,5,6] | **3** | left of idx3 = 1+7+3 = 11; right = 5+6 = 11 |
| [1,2,3] | **-1** | no pivot |
| [2,1,-1] | **0** | left of idx0 = 0; right = 1+(-1) = 0 |

## Constraints
- `1 ≤ nums.length ≤ 10^4`
- `-1000 ≤ nums[i] ≤ 1000`  (negatives → fine, no window here)

---

## Before you code — decide these on purpose
1. If you know `total` (sum of whole array) and `leftSum` so far, what is `rightSum` at index `i` in ONE expression? (derive it — don't memorize)
2. Empty-left and empty-right **boundary** values — what are they at index 0 and at the last index?
3. This closes MISTAKE #1: use `prefix`/total by **meaning**, sanity-test on a 3-element array first.

## Why this pattern (recognition cue)
"balance point / equal sum on both sides / running comparison of left-vs-right totals" →
prefix sum. `rightSum = total - leftSum - nums[i]`. O(n) time, O(1) space.

## Result log (fill after submitting)
- Status: ___ (Accepted / WA / TLE)   Hints used (L0–L5): ___
- What tripped me up: ___
