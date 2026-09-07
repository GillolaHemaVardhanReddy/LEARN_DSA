# LC622 — Design Circular Queue  (MEDIUM · ring-buffer mechanics)  🟢 warm-up

🔗 https://leetcode.com/problems/design-circular-queue/

**Goal:** implement a fixed-capacity FIFO **ring buffer** — reuse the freed front slots
instead of marching pointers off the end (that array-queue you instinctively reached for
in LC232, done *right* this time).

## Ops
- `MyCircularQueue(k)` — capacity k
- `enQueue(v)` → false if full
- `deQueue()` → false if empty
- `Front()` / `Rear()` → -1 if empty
- `isEmpty()` / `isFull()`

## Example
```
MyCircularQueue(3); enQueue(1)T enQueue(2)T enQueue(3)T enQueue(4)F
Rear()->3  isFull()->T  deQueue()->T  enQueue(4)->T  Rear()->4
```

## Constraints
- `1 <= k <= 1000`, `0 <= value <= 1000`, ≤ 3000 calls.

## Reach for (help-allowed)
An array of size `k`, a `head` index, and a `count` (size). No `tail` variable needed —
**derive** the write slot: `(head + count) % k`. `deQueue` = `head = (head+1) % k; count--`.
This is your **derive-don't-maintain** principle on a ring — the `% k` is what "connects the
last position back to the first." Watch the empty/full edges: empty ⟺ `count==0`, full ⟺ `count==k`.
