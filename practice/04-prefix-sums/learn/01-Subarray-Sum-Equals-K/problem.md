# LC 560 — Subarray Sum Equals K  ·  Medium

**Link:** https://leetcode.com/problems/subarray-sum-equals-k/
**Module:** M5 Prefix Sum  **Pattern:** Prefix Sum + Hash Map of complements  **Tier:** A (pattern named)

---

## Problem (plain English)
Given an integer array `nums` (may contain **negatives**) and an integer `k`, return the
**total count** of **contiguous** subarrays whose sum equals `k`. Length is free — any
length counts. You **count every** qualifying subarray (this is a TALLY, not a min/max hunt).

## Examples
| nums | k | answer | why |
|---|---|---|---|
| [1,1,1] | 2 | **2** | `[1,1]` at idx 0–1 and idx 1–2 |
| [1,2,3] | 3 | **2** | `[1,2]` and `[3]` — different lengths, both sum 3 |
| [3,4,7] | 7 | **2** | `[3,4]` and `[7]` |

## Constraints
- `1 ≤ nums.length ≤ 2·10^4`   → O(n²) is borderline-slow; aim for **O(n)**
- `-1000 ≤ nums[i] ≤ 1000`   ← **negatives present → sliding window is DEAD**
- `-10^7 ≤ k ≤ 10^7`

---

## Before you code — decide these on purpose
1. What single entry must be **pre-loaded** into the map before the loop, and with what count? (the empty prefix)
2. **ORDER inside the loop:** do you look up `seen[running - k]` **before** or **after** `seen[running]++`? (Why? could an element wrongly match itself?)
3. `k` is a **SUM**, not a length — there is no `i+k-1` anywhere in this solution.

## Why this pattern (recognition cue)
"**count** contiguous subarrays with **sum = k**, negatives allowed" → prefix sum, then
isolate the complement `prefix[L-1] = prefix[R] - k`, then ask "how many earlier prefixes
equal that?" → **hash map**. This is **Two Sum on prefix sums.**

## Result log (fill after submitting)
- Status: ___ (Accepted / WA / TLE)   Hints used (L0–L5): ___
- What tripped me up: ___
