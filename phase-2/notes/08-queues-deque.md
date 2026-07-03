# M8 — Queues & Deque  (study notes)

## 0. Striver videos (watch in this order)
- **[297] Intro Stack & Queue | Implementations** — https://youtu.be/tqQ5fTamIN4  (the primitive: how a queue/deque works)
- **[312] Sliding Window Maximum (deque)** — https://youtu.be/NwBvene4Imo  ⭐ THE pattern video
- (later, optional design) [314] LRU Cache — https://youtu.be/z9bJUPxzFOw · [315] LFU Cache — https://youtu.be/mzqHlAW7jeE

---

## 1. The tools (primitives)
| Structure | Add | Remove | Peek | Shape |
|---|---|---|---|---|
| **Stack** | push (top) | pop (top) | top | LIFO — one open end |
| **Queue** | push (back) | pop (front) | front | FIFO — in one end, out the other |
| **Deque** (double-ended) | push_front / **push_back** | pop_front / **pop_back** | front / back | **BOTH ends open, all O(1)** |

C++: `std::deque<int> dq;` → `dq.push_back(x) · dq.pop_back() · dq.push_front(x) · dq.pop_front() · dq.front() · dq.back() · dq.empty()`.

**Queue from two stacks** (LC232, warm-up): push onto `in`; to pop/peek, if `out` empty pour `in`→`out` (reverses order), then pop `out`. Amortized O(1).

---

## 2. ⭐ The pattern: MONOTONIC DEQUE
The deque's real job. It's the **twin of the monotonic stack** — same "kick out the useless" idea, but with a **second eviction from the front** because the window moves.

**Problem it solves:** *maximum (or minimum) of EVERY window of size k*, in **O(n)** instead of the O(n·k) brute.

### Why a single running-max FAILS
When the current max **slides out of the window**, you need the next-best — but a lone `max` variable threw the runner-ups away. So keep a **shortlist of live candidates**, not one number.

### The two invariants
Store **INDICES** (not values — you need positions to know what's expired; get the value with `nums[idx]`). Keep the deque so its **values are decreasing front→back**. Then:

1. **ENTER (right side, pop_back):** a new element kills every candidate smaller than it — those are older *and* smaller, so they can never win again.
   `while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();` then `dq.push_back(i);`
   (It's the monotonic-stack while-pop — pop ALL smaller, not just one.)
2. **EXPIRE (left side, pop_front):** the front may have slid out of the window.
   `while(dq.front() <= i - k) dq.pop_front();`  (`i-k` = last index too old for the window ending at `i`)
3. **READ:** once the window is full (`i >= k-1`), the answer for this window is `nums[dq.front()]` — the front is always the current max.

### Why it's O(n)
Each index is **pushed once and popped once** across the whole run → total work O(n) (amortized), even though any single step might pop several. Same accounting as the monotonic stack.

### The skeleton (Sliding Window Maximum, LC239)
```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;               // holds INDICES, values decreasing front→back
    vector<int> ans;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (!dq.empty() && dq.front() <= i - k) dq.pop_front();      // expire (left)
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back(); // enter (right)
        dq.push_back(i);
        if (i >= k - 1) ans.push_back(nums[dq.front()]);            // read
    }
    return ans;
}
```
(For window MIN, flip the back-pop comparison to `>`.)

---

## 3. RECOGNITION TRIGGER (the part that matters most)
> **Sliding a window + need the MAX or MIN *of the current window* fast → monotonic deque, O(n).**
> Dead-giveaway phrase: *"maximum/minimum of every window of size k."*

Stack vs deque — the clean line:
| You see… | Tool |
|---|---|
| next/previous greater/smaller element (**unbounded** reach ahead/behind) | Monotonic **stack** |
| the extreme **inside a moving, bounded window** (drops old elements off the left) | Monotonic **deque** |

## 4. Problem family (where it shows up)
1. **LC239 Sliding Window Maximum** — canonical.
2. **LC862 Shortest Subarray with Sum ≥ K** — monotonic deque over **prefix sums** (⭐ our PARKED hard — this pattern unlocks it).
3. **LC1438 Longest Subarray with abs diff ≤ limit** — need BOTH max and min → **two deques** at once.
4. **LC1696 Jump Game VI / windowed DP** — when a DP transition is "max/min over the last k states," a deque turns O(n·k) → O(n).
5. **LC933 Number of Recent Calls** — plain queue (FIFO), the easy warm-up.

## 5. Gate to pass (M8 mastery check)
Explain out loud: **why does the deque hold the window's extreme in O(1) amortized?** (Answer: decreasing invariant makes the front the max by construction; each index enters/leaves exactly once → O(n) total.)
