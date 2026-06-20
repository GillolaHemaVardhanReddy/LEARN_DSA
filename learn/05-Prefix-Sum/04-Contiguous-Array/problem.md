# LC 525 — Contiguous Array  ·  Medium

**Link:** https://leetcode.com/problems/contiguous-array/
**Module:** M5 Prefix Sum  **Pattern:** Prefix family — TRANSFORM REQUIRED  **Tier:** B

---

## Problem (plain English)
Given a binary array `nums` (only 0s and 1s), return the **length of the longest
contiguous subarray** with an **equal number of 0s and 1s**.

## Examples
| nums | answer | why |
|---|---|---|
| [0,1] | **2** | one 0, one 1 |
| [0,1,0] | **2** | `[0,1]` or `[1,0]` |
| [0,1,1,1,0,0] | **6** | three 0s, three 1s |

## Constraints
- `1 ≤ nums.length ≤ 10^5`   → **O(n)**
- `nums[i] ∈ {0, 1}`

---

## Your job (transfer — a transform unlocks it)
Prefix sum doesn't obviously apply to "equal count of 0s and 1s"… until you **transform
the array** so that "equal counts" becomes "**sum = 0**."
- What if you treat every `0` as `-1` and every `1` as `+1`? What does a subarray summing
  to `0` then mean?
- Now it's a prefix-sum problem. But note: this asks for the **LONGEST** subarray, not a
  count. So the map should store something different from LC560. What do you store as the
  **value** to recover a length? (first-occurrence index vs. a frequency — which?)

## Result log (fill after submitting)
- Status: ___   The transform + what the map stored: ___   Hints used (L0–L5): ___
- What tripped me up: ___
