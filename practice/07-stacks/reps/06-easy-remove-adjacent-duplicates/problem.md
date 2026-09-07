# LC1047 — Remove All Adjacent Duplicates In String · Easy

🔗 https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

Repeatedly remove any **two adjacent, equal** letters until you can't anymore. Return the final string.

- `"abbaca"` → `"ca"`  (remove `bb` → `"aaca"`, then `aa` → `"ca"`)
- `"azxxzy"` → `"ay"`

**Constraints:** `1 <= s.length <= 1e5` · lowercase letters. Answer is unique.

PATTERN (name it before coding): ______________________
Self-gate: a stack lets the NEW char check only the **most recent survivor** — equal ⇒ annihilate
(pop), else push. One pass. This is the **collapse** flavor — not "find next greater."
