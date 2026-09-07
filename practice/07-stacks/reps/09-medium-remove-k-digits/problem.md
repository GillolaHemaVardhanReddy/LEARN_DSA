# LC402 — Remove K Digits · Medium

🔗 https://leetcode.com/problems/remove-k-digits/

Given a non-negative integer as a string `num` and an integer `k`, remove **exactly `k` digits**
so the remaining number is the **smallest possible**. Return it as a string (no leading zeros,
except `"0"` itself).

- `num = "1432219", k = 3` → `"1219"`
- `num = "10200", k = 1` → `"200"`
- `num = "10", k = 2` → `"0"`

**Constraints:** `1 <= k <= num.length <= 1e5` · digits only · no leading zeros in input.

PATTERN (name it before coding): ______________________
Self-gate: scanning left→right, a digit should **pop any BIGGER digit before it** (a big digit in
a high place hurts most) while you still have removals — a monotonic-**increasing** stack. The
**greedily-build** flavor. THREE end-traps: leftover `k` (trim from the END) · leading zeros (strip)
· everything removed (→ `"0"`).
