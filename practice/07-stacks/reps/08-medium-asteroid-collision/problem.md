# LC735 — Asteroid Collision · Medium

🔗 https://leetcode.com/problems/asteroid-collision/

Asteroids in a row. `+ve` moves right, `-ve` moves left, `|value|` = size, all same speed.
When two meet, the **smaller explodes**; if equal, **both explode**. Same-direction asteroids
never meet. Return the final state.

- `[5,10,-5]` → `[5,10]`
- `[8,-8]` → `[]`
- `[10,2,-5]` → `[10]`
- `[3,5,-6,2,-1,4]` → `[-6,2,4]`

**Constraints:** `2 <= n <= 1e4` · `-1000 <= asteroids[i] <= 1000` · nonzero.

PATTERN (name it before coding): ______________________
Self-gate: a collision happens ONLY when a **right-mover** (`+` on top of the stack) meets a NEW
**left-mover** (`-` incoming). Resolve against the top repeatedly. Nail the **3 outcomes**:
newcomer wins (pop, keep fighting) · both die (pop, stop) · newcomer dies (stop, don't push).
