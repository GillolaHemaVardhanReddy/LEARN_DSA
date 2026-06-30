# LC 242 — Valid Anagram  ·  Easy   ·   HASHING (frequency count)

**Link:** https://leetcode.com/problems/valid-anagram/
**Topic:** Hash map / frequency array — counting occurrences

---

## Problem (plain English)
Return `true` if `t` is an anagram of `s` (same letters, same counts, reordered).

## Examples
| s | t | answer |
|---|---|---|
| "anagram" | "nagaram" | true |
| "rat" | "car" | false |

## Constraints
- `1 ≤ s.length, t.length ≤ 5·10^4`, lowercase letters.

## Before you code
1. If lengths differ → false immediately.
2. Count each letter of `s` (freq array of 26 or a hash map), decrement for each letter of `t`.
   All zero at the end → anagram. (Or sort both and compare — O(n log n), discuss the tradeoff.)

## Result log
- Status: ___   freq array vs hash map vs sort — which and why: ___
