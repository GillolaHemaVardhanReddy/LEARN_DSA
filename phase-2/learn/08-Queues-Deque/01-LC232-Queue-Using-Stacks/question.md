# LC232 — Implement Queue using Stacks  (EASY · mechanics warm-up)

🔗 https://leetcode.com/problems/implement-queue-using-stacks/

**Goal:** build a FIFO queue (`push`, `pop`, `peek`, `empty`) using **only two stacks**.
Only stack ops allowed: push-to-top, top/pop-from-top, size, empty.

## Signature
```cpp
class MyQueue {
public:
    MyQueue();
    void push(int x);   // add to back of queue
    int  pop();         // remove & return front
    int  peek();        // return front
    bool empty();
};
```

## Example
```
push(1) push(2) peek()->1  pop()->1  empty()->false
```

## Constraints
- `1 <= x <= 9`, at most 100 calls.
- **Follow-up:** make each op **amortized O(1)**.

## The idea to derive (don't peek at solution.cpp bridge until you've tried)
A stack reverses order (LIFO). Pour a stack into another stack → order flips back to FIFO.
Keep two stacks: `in` (for pushes) and `out` (for pops/peeks). When `out` is empty and you
need the front, pour ALL of `in` into `out` once — now the oldest element is on top of `out`.
Each element is moved between stacks at most once → amortized O(1).
