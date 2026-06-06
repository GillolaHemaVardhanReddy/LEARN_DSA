# LC 76 — Minimum Window Substring  ·  Hard   ·   VARIABLE WINDOW + FREQUENCY

**Link:** https://leetcode.com/problems/minimum-window-substring/
**Topic:** Variable sliding window (shortest) + need/have frequency counting

---

## Problem (plain English)
Return the **shortest substring** of `s` that contains **all characters of `t`** (including
duplicates / multiplicities). Return `""` if none. This is the canonical hard sliding window.

## Examples
| s | t | answer |
|---|---|---|
| "ADOBECODEBANC" | "ABC" | "BANC" |
| "a" | "a" | "a" |
| "a" | "aa" | "" |

## Constraints
- `1 ≤ s.length, t.length ≤ 10^5`, upper & lower case letters.

## Before you code (SHORTEST variant — shrink WHILE valid, record INSIDE)
1. `need` = freq map of `t`. Track `required` = number of distinct chars still to satisfy.
2. Expand `right`, decrement need; when a char's need hits 0, `formed++`.
3. **While `formed == required` (valid):** record min window, then shrink `left` to try smaller.
4. Boundary: track best length + start index; return `s.substr(start, len)` or `""`.

## Result log
- Status: ___   need/have bookkeeping I used: ___   What I want to discuss: ___
