# Hashing — SOLO SET (the L4 gate)

> Goal: convert hashing from *coached-L3* to *witnessed-L4*. **Solve these on your own.**
> No looking up the approach — that defeats the purpose. The whole skill being tested is
> **recognition**: seeing the problem and reaching for the right hashing tool yourself.

## The rule for each problem (recognition-first)
1. Restate it in one line.
2. **Write the cue BEFORE coding:** `cue: ___ → hashing because ___`
   (is it "seen-before? / how many times? / group-by-shared-key? / O(1) membership?")
3. Brute force + its complexity + the wasted work.
4. Code it. Run the **pre-code boundary checklist** before submitting (your #1 leak):
   - loop touches FIRST and LAST element? empty input? consistent compare direction?
   - look-up BEFORE insert for pair problems? `.count()` not `if(map[x])`?
5. Submit to LeetCode. Bring Kera only the ones that fight back.

## The set (do in this order)
| # | Problem | Difficulty | Link |
|---|---------|-----------|------|
| 1 | LC 217 — Contains Duplicate | easy | https://leetcode.com/problems/contains-duplicate/ |
| 2 | LC 219 — Contains Duplicate II | easy | https://leetcode.com/problems/contains-duplicate-ii/ |
| 3 | LC 347 — Top K Frequent Elements | **medium** | https://leetcode.com/problems/top-k-frequent-elements/ |
| 4 | LC 36 — Valid Sudoku | **medium** | https://leetcode.com/problems/valid-sudoku/ |

**L4 is earned when you solve #3 and #4 largely on your own** (≥2 mediums solo).
#2 is also your drill re-test (Q7 — you misfiled it as "two pointers"; prove it's hashing).

## After this set
Ping Kera for a fresh `/drill` — if hashing recognition is ≥ solid there, M2 Hashing
advances toward L5 and we move to the next topic (Two Pointers / Binary Search).
