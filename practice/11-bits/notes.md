# 11 · Bit manipulation — opens in Tier 0 (week 4–5)

**Derived from:** 10 backtracking — a mask IS a subset (the other way to enumerate; you already used `mask & (1<<i)` as the brute oracle for LC78 / LC402).
**Kills:** "a set of ≤ 20 things needs a cheap identity" and "pairs cancel" (XOR).
**Will cover:** get / set / clear / toggle a bit · lowest set bit `x & -x` · drop lowest `x & (x-1)` · XOR laws (LC136, LC260) · popcount (LC191, LC338) · missing number (LC268) · reverse bits (LC190) · add without `+` (LC371) · **submask enumeration** (the seed of 31 bitmask DP).
**Where it runs:** permission flags, compression, DP over subsets, every CP problem with n ≤ 20.

_Kira writes the full teaching notes AFTER boss's live derivation — never before._
