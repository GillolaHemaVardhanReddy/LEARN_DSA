# LC20 — Valid Parentheses  (Easy · string, stack)

Given a string `s` of just `()[]{}`, return whether it's valid:
1. Open brackets close with the **same type**.
2. Open brackets close in the **correct order**.
3. Every close bracket has a matching open.

Constraints: `1 <= s.length <= 1e4`, only the 6 bracket chars.

## The 5 examples (your dry-run set)
| s | answer | why |
|---|---|---|
| `"()"` | true | matched pair |
| `"()[]{}"` | true | three matched pairs |
| `"(]"` | false | wrong type |
| `"([])"` | true | nested, correct order |
| `"([)]"` | **false** | interleaved — the order is wrong (this is the one that kills a counter model) |

## Why this is M7's L3 gate
Code the stack solution **from memory**, clean, handling `"([)]"` and the empty-stack edges → L2 → L3.
