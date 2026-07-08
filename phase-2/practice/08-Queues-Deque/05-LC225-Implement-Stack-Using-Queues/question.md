# LC225 — Implement Stack using Queues  ·  EASY  ·  M8 Queues

https://leetcode.com/problems/implement-stack-using-queues/

Implement a LIFO stack using only **two queues**. Support `push`, `pop`, `top`, `empty`.

You may use **only** standard queue operations: push to back · peek/pop from front · size · is empty.

**Follow-up (this is the one you submit): can you do it with one queue?**

## Constraints
- `1 <= x <= 9`
- At most `100` calls total across `push`/`pop`/`top`/`empty`
- All calls to `pop` and `top` are valid (never called on empty)

## Examples
```
["MyStack","push","push","top","pop","empty"]
[[],      [1],   [2],   [],   [],   []]
->  [null, null, null, 2, 2, false]
```

## Gate A — before you code
Restate in one sentence. Then dry-run `push(1) push(2) top()` by hand and write down what the
queue physically contains at each step.

## The question that IS the problem
A queue hands you the **oldest** element. A stack wants the **newest**.
Somebody has to pay to reverse that order. **Who — `push` or `pop`?**

Pick, justify, then state both complexities out loud *before* writing a line.
