# LC933 — Number of Recent Calls  (EASY · plain queue / FIFO expiry)

🔗 https://leetcode.com/problems/number-of-recent-calls/

**Goal:** `ping(t)` records a request at time `t` (strictly increasing each call) and
returns how many requests fell in the window `[t - 3000, t]` (inclusive).

## Signature
```cpp
class RecentCounter {
public:
    RecentCounter();
    int ping(int t);   // returns # of pings in [t-3000, t]
};
```

## Example
```
ping(1)    -> 1     // [1]
ping(100)  -> 2     // [1,100]
ping(3001) -> 3     // [1,100,3001]
ping(3002) -> 3     // [100,3001,3002]  <- the '1' expired ( < 3002-3000 )
```

## Constraints
- `1 <= t <= 1e9`, at most `1e4` calls, `t` strictly increasing.

## The idea (this is the deque/queue muscle)
Times arrive in increasing order → a **queue (FIFO)**. On each `ping(t)`:
1. push `t` at the back,
2. **pop from the front** while `front < t - 3000` (those are too old — expired),
3. the answer is the queue's current size.
This is the *front-expiry* move you'll reuse in the monotonic deque (LC239).
