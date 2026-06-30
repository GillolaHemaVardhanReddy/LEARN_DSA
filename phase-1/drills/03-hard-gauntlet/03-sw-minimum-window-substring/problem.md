# LC76 — Minimum Window Substring · Hard

🔗 https://leetcode.com/problems/minimum-window-substring/

Return the **smallest substring** of `s` containing every char of `t` (including duplicates), or `""`.

- `s = "ADOBECODEBANC", t = "ABC"` → `"BANC"`
- `s = "a", t = "aa"` → `""`

**Constraints:** `1 <= m,n <= 1e5` · letters (upper + lower).

PATTERN (name it before coding): ______________________
Self-gate: variable window — grow `r` to cover `t`, shrink `l` while still covered, record smallest.
Coverage = a `need` map + a single `have == required` counter (don't re-scan the map). ⭐ Your owed
**derive-don't-maintain (P27)** re-test: run the variable audit before coding — one driver, one
invariant, no redundant synced state.
