# LC 523 — Continuous Subarray Sum  ·  Medium   ·   PREFIX + REMAINDER + HASH

**Link:** https://leetcode.com/problems/continuous-subarray-sum/
**Topic:** Prefix sum + hash of remainders (cousin of LC974) — with a length twist

---

## Problem (plain English)
Return `true` if `nums` has a **contiguous subarray of length ≥ 2** whose sum is a
**multiple of `k`** (i.e. sum % k == 0). Length must be at least 2.

## Examples
| nums | k | answer | why |
|---|---|---|---|
| [23,2,4,6,7] | 6 | true | [2,4] sums to 6 |
| [23,2,6,4,7] | 6 | true | whole array sums to 42 = 6×7 |
| [23,2,6,4,7] | 13 | false | no length≥2 multiple of 13 |

## Constraints
- `1 ≤ nums.length ≤ 10^5`, `0 ≤ nums[i]`, `1 ≤ k ≤ 2^31-1`

## Before you code
1. Same idea as LC974: two prefixes with the **same remainder mod k** ⇒ the chunk between
   them is divisible by k. Store remainder → **earliest index** it appeared.
2. **The length≥2 twist:** you need the gap `i - firstIndex(rem) ≥ 2`. So store the FIRST
   index of each remainder and only accept when current index is at least 2 ahead.
3. Pre-load remainder `0` at index `-1`. Use a map `remainder -> first index`.

## Result log
- Status: ___   How the length≥2 condition changed the map usage: ___
