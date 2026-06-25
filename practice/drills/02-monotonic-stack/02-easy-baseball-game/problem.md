# LC682 — Baseball Game · Easy

🔗 https://leetcode.com/problems/baseball-game/

Apply a list of `operations` to a record (start empty):
- integer `x` → record a new score `x`
- `"+"` → record the **sum of the previous two** scores
- `"D"` → record **double** the previous score
- `"C"` → **invalidate (remove)** the previous score

Return the **sum** of all scores remaining on the record.

- `["5","2","C","D","+"]` → `30`
- `["5","-2","4","C","D","9","+","+"]` → `27`
- `["1","C"]` → `0`

**Constraints:** `1 <= operations.length <= 1000` · all ops valid · everything fits in 32-bit int.

PATTERN (name it before coding): ______________________
Self-gate: every op touches only the **most recent one or two** scores — so the record IS a stack.
This is the **simulation / undo** flavor: read the op, push/pop/peek. Watch parsing a negative int.
