# LC992 — Subarrays with K Different Integers · Hard

🔗 https://leetcode.com/problems/subarrays-with-k-different-integers/

Count contiguous subarrays with **exactly** `k` distinct integers.

- `nums = [1,2,1,2,3], k = 2` → `7`
- `nums = [1,2,1,3,4], k = 3` → `3`

**Constraints:** `1 <= n <= 2e4` · `1 <= nums[i], k <= n`.

PATTERN (name it before coding): ______________________
Self-gate: **exactly(k) = atMost(k) − atMost(k−1)**. `atMost(m)` is a clean variable window — shrink
while distinct > m, then `ans += r − l + 1` **unconditionally** (counts all subarrays ending at r).
⭐ Your owed **MISTAKE #11** re-test: the unconditional add (no `if`, no `ans++`) is the exact thing
you slipped on. Explain WHY the subtraction leaves exactly-k.
