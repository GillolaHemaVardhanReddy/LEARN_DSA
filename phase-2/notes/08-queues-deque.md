# M8 — Queues & Deque  (teaching notes — reread cold, they rebuild the model)

> These notes TEACH, they don't just remind. Read top to bottom and the understanding comes back.
> The star of this module is the **MONOTONIC DEQUE** for sliding-window max/min — everything else
> (FIFO queue, two-stack queue, front-expiry queue, ring buffer) is the toolbox that makes it click.

## 0. Striver videos (watch in this order, AFTER these notes)
- **[297] Intro Stack & Queue | Implementations** — https://youtu.be/tqQ5fTamIN4  (the primitive: how a queue/deque works)
- **[312] Sliding Window Maximum (deque)** — https://youtu.be/NwBvene4Imo  ⭐ THE pattern video
- (later, optional design) [314] LRU Cache — https://youtu.be/z9bJUPxzFOw · [315] LFU Cache — https://youtu.be/mzqHlAW7jeE

---

## BIT 0 — The one sentence
> **A queue is FIFO (first in, first out). A deque is a queue open at BOTH ends — and a monotonic
> deque uses that second end to keep a live shortlist of "who could be the window's max."**

That's the whole module. Everything below is *why each tool exists* and *how to run it by hand*.

---

## BIT 1 — Why they exist (the "why")
A **stack** is LIFO — one open end, last in comes out first. Perfect for "undo", "matching brackets",
"next greater element" — anything where the *most recent* thing matters most.

A **queue** is FIFO — you join at the back, you leave from the front, like a line at a shop. Perfect
for "process in arrival order": BFS levels, task schedulers, "how many events in the last 3000ms."

A **deque** (double-ended queue) opens BOTH ends — push/pop at front *and* back, every op O(1). Why
would you want both ends? Because sometimes you add candidates at one end but *retire stale ones from
the other end*. That exact need is the sliding window: new elements enter on the right, old elements
expire off the left. Hold that thought — it's BIT 5.

> **Stack = one open end (recency). Queue = in one end, out the other (order). Deque = both ends
> open (add here, expire there).**

---

## BIT 2 — The tools, at a glance
| Structure | Add | Remove | Peek | Shape |
|---|---|---|---|---|
| **Stack** | push (top) | pop (top) | top | LIFO — one open end |
| **Queue** | push (back) | pop (front) | front | FIFO — in one end, out the other |
| **Deque** | push_front / **push_back** | pop_front / **pop_back** | front / back | **BOTH ends open, all O(1)** |

C++: `std::deque<int> dq;` gives you `dq.push_back(x) · dq.pop_back() · dq.push_front(x) ·
dq.pop_front() · dq.front() · dq.back() · dq.empty()`. `std::queue<int> q;` gives you the FIFO-only
subset: `q.push(x)` (back) · `q.pop()` (front) · `q.front()` · `q.back()` · `q.empty()`.

---

## BIT 3 — Queue from TWO stacks (LC232) + the amortization idea
The warm-up that teaches an accounting trick you'll reuse forever. You only have stacks (LIFO); build
a FIFO queue from two of them.

**Setup:** an `in` stack and an `out` stack.
- **push(x):** just `in.push(x)`. O(1), always.
- **pop()/peek():** if `out` is **empty**, pour ALL of `in` into `out` (this *reverses* the order, so
  the oldest element ends up on top of `out`). Then pop/peek `out`.

```cpp
stack<int> in, out;
void push(int x){ in.push(x); }
int pop(){
    if (out.empty())                    // ⭐ pour ONLY when out is empty
        while(!in.empty()){ out.push(in.top()); in.pop(); }
    int v = out.top(); out.pop(); return v;
}
```

**The mistake to kill:** pouring `in`→`out` and then back every single pop. That's O(n) per op. The
whole trick is the guard `if (out.empty())` — **pour only when `out` runs dry.**

**Why it's amortized O(1) (the accounting):** each element is moved at most a fixed number of times
across its whole life — pushed to `in` once, poured to `out` once, popped from `out` once. Three
touches, ever. Spread the cost of one expensive pour over all the cheap pops that follow it and the
*average* per operation is O(1). Any single pop might be O(n), but a *run* of n ops is O(n) total.
(Same accounting shows up again in BIT 5 — remember this phrase: **"each element enters once, leaves
once."**)

---

## BIT 4 — Front-expiry queue (LC933 Number of Recent Calls)
A plain FIFO queue, but it teaches the "expired forever" insight the monotonic deque leans on.

**Problem:** each `ping(t)` gets a timestamp `t`, and `t` is **strictly increasing** (monotonic time).
Return how many pings landed in `[t-3000, t]`.

**Trick:** push `t` to the back. Then pop from the **front** every timestamp that's now too old
(`front < t - 3000`). Answer = current queue size.

```cpp
queue<int> q;
int ping(int t){
    q.push(t);
    while(q.front() < t - 3000) q.pop();   // expire the stale front(s)
    return q.size();
}
```

**Why front-only expiry is safe:** because time only moves forward, once a timestamp falls out of the
window it can NEVER come back in. Expired = expired forever. So you throw it away and never look
again. That "monotonic ⇒ expired-forever" property is *exactly* what makes the sliding window's
left-side eviction legal. This tiny problem is the seed of the star.

---

## BIT 5 — ⭐ THE MONOTONIC DEQUE (the star of the module)
The deque's real job, and the twin of the monotonic stack: same "kick out the useless" idea, but with
a **second eviction from the front** because the window moves.

**Problem it solves:** the **maximum (or minimum) of EVERY window of size k**, in **O(n)** instead of
the O(n·k) brute (re-scan each window).

**Why a single running-max FAILS:** when the current max **slides out of the window**, you need the
next-best — but a lone `max` variable already threw the runners-up away. So you must keep a
**shortlist of live candidates**, not one number.

### ⭐ THE UNLOCK (center this — say it in your own words)
> A monotonic deque holds **INDICES (not values)** of candidates for the window's max. The **front is
> always the max**. An index **expires when `front <= i - k`** — derived straight from the index, no
> separate counter. And you **pop from the BACK** any index whose value is `<=` the newcomer, because
> an older-AND-smaller element can never be the max again.

Two reasons it's indices, not values: (1) you need the *position* to know when a candidate is too old
for the window; (2) the value is always one lookup away as `nums[idx]`. Store the index, read the
value.

The deque is kept so its **values are decreasing front→back**. Given that, three moves per step:

1. **EXPIRE (front, pop_front):** the front may have slid out. `if (dq.front() <= i - k) dq.pop_front();`
   `i - k` = the last index too old for a window ending at `i`.
2. **ENTER (back, pop_back):** a new element kills every candidate `<=` it — those are older *and*
   not-bigger, so they can never win again. `while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();`
   then `dq.push_back(i);` (the monotonic-stack while-pop — pop ALL, not just one).
3. **READ:** once the window is full (`i >= k-1`), the answer is `nums[dq.front()]` — front is the max
   by construction.

---

## BIT 6 — HAND-RUN the sliding window (run this yourself, don't skim)
`nums = [1, 3, -1, -3, 5, 3, 6, 7]`, `k = 3`. Deque holds **indices**; values shown in `()`.
Expire rule: drop front if `front <= i - k`. Enter rule: pop back while `nums[back] <= nums[i]`.

```
i=0 val=1  : expire? front≤-3 no · enter: empty → push 0        dq=[0(1)]              (window not full)
i=1 val=3  : expire? 0≤-2 no   · enter: nums[0]=1≤3 pop0 → push1 dq=[1(3)]              (window not full)
i=2 val=-1 : expire? 1≤-1 no   · enter: nums[1]=3≤-1 no → push2  dq=[1(3),2(-1)]  READ nums[1]=3  → 3
i=3 val=-3 : expire? 1≤0 no    · enter: nums[2]=-1≤-3 no → push3 dq=[1(3),2(-1),3(-3)] READ nums[1]=3 → 3
i=4 val=5  : expire? 1≤1 YES pop front → dq=[2,3]
             enter: nums[3]=-3≤5 pop3, nums[2]=-1≤5 pop2 → push4 dq=[4(5)]         READ nums[4]=5  → 5
i=5 val=3  : expire? 4≤2 no    · enter: nums[4]=5≤3 no → push5    dq=[4(5),5(3)]   READ nums[4]=5  → 5
i=6 val=6  : expire? 4≤3 no    · enter: nums[5]=3≤6 pop5, nums[4]=5≤6 pop4 → push6 dq=[6(6)]  READ 6 → 6
i=7 val=7  : expire? 6≤4 no    · enter: nums[6]=6≤7 pop6 → push7  dq=[7(7)]        READ nums[7]=7  → 7
```
Answer = `[3, 3, 5, 5, 6, 7]`. Watch three things happen: indices **enter the back**, the max **dies
off the front by the `i-k` rule** (at i=4, index 1 finally too old), and the **front is always the
window max**. That's the whole algorithm — you just ran it.

### The skeleton (Sliding Window Maximum, LC239)
```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;                 // holds INDICES, values decreasing front→back
    vector<int> ans;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (!dq.empty() && dq.front() <= i - k) dq.pop_front();          // expire (front)
        while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back(); // enter (back)
        dq.push_back(i);
        if (i >= k - 1) ans.push_back(nums[dq.front()]);                 // read
    }
    return ans;
}
```
(For window MIN, flip the back-pop comparison to `>=`.)

---

## BIT 7 — Ring buffer / circular queue (LC622, fixed capacity)
When capacity is **fixed** and you want O(1) push/pop without shifting elements, use a **ring buffer**:
one array of size `k`, plus `head`, `count` (or `head`/`tail`). Indices wrap with `% k`.

```cpp
int a[k], head = 0, count = 0;
void enqueue(int x){ a[(head + count) % k] = x; count++; }   // write at tail = (head+count)%k
void dequeue(){ head = (head + 1) % k; count--; }            // advance head, wrap around
int front(){ return a[head]; }
bool full(){ return count == k; }  bool empty(){ return count == 0; }
```

The `% k` is the whole idea — the array end folds back to the start, so a bounded queue reuses its
slots forever. Watch the wrap arithmetic: the tail slot is `(head + count) % k`, NOT `tail++`
unbounded.

---

## BIT 8 — Why the deque is O(n) (read straight off the shape)
Each index is **pushed once and popped once** across the whole run. Total pushes ≤ n, total pops ≤ n
→ **O(n) total**, even though a single step's `while` might pop several. This is the SAME amortized
accounting as the two-stack queue (BIT 3) and the monotonic stack: **"each element enters once, leaves
once."** Space is O(k) — the deque never holds more than one window's worth of live candidates.

---

## BIT 9 — Decision recipe (run BEFORE coding a deque problem) ⭐ your Gate-A
Answer these, in order:
1. **Does the deque hold an INDEX or a VALUE?** → For sliding-window max/min, **INDEX** (you need the
   position for expiry; read the value as `nums[idx]`). Only store raw values if position never matters.
2. **Which end does each op hit?** → Newcomers/candidates enter the **back** (pop_back the useless).
   Stale elements expire off the **front** (pop_front). The answer is read at the **front**.
3. **What's the expiry condition, and is it derived from the index?** → `front <= i - k`, computed from
   the stored index — **no separate age counter**. If you're tempted to add a counter, you're storing
   values when you should store indices.
4. **Max or min?** → Max ⇒ pop_back while `nums[back] <= nums[i]` (keep decreasing). Min ⇒ flip to `>=`.

---

## BIT 10 — The classic traps (execution focus, boss — this is where you bleed)
1. **⭐ Reading `.front()`/`.back()` on an EMPTY deque/queue is UNDEFINED BEHAVIOR** — it does NOT
   return 0, it reads garbage or crashes. **Guard `!dq.empty()` BEFORE every read/pop.** In LC933 the
   `while(q.front()...)` is only safe because you just pushed, so it's non-empty; in LC239 every
   `.front()`/`.back()` sits behind `!dq.empty()`. Never assume "it'll just be 0."
2. **Index vs value confusion.** You stored indices — so compare with `nums[dq.back()]`, but expire
   with the raw `dq.front()` (that IS the index). Mixing them (`nums[dq.front()] <= i - k`) is a silent
   wrong answer. Say out loud "this slot is an INDEX" every time you touch the deque.
3. **Expire edge is `<=`, not `<`.** The window ending at `i` covers indices `[i-k+1 .. i]`. So index
   `i-k` is the FIRST one too old — kill it with `front <= i - k`. Using `<` keeps one stale element
   and corrupts the max. (This is your boundary leak — trace i=4 in BIT 6 to feel it: front index 1,
   `1 <= 4-3=1` YES, must die.)
4. **Popping the wrong end / not popping ALL.** Enter is a `while` (pop every smaller candidate off the
   back), not an `if`. Expire is the front. Swap them and the invariant dies.
5. **Two-stack queue: pouring back every pop** (BIT 3) → O(n) per op. Pour ONLY when `out` is empty.
6. **Off-by-one on "window full":** read the answer only when `i >= k - 1`, else you emit maxes of
   half-formed windows.

---

## BIT 11 — Recognition cue (fill in YOUR words after the coding ladder)
> **Sliding a window + need the MAX or MIN *of the current window* fast → monotonic deque, O(n).**
> Dead-giveaway phrase: *"maximum/minimum of every window of size k."*

Stack vs deque — the clean line:
| You see… | Tool |
|---|---|
| next/previous greater/smaller element (**unbounded** reach ahead/behind) | Monotonic **stack** |
| the extreme **inside a moving, bounded window** (drops old elements off the left) | Monotonic **deque** |

*(Your teach-it-back line goes here once you've coded the ladder — that's the L6 signal.)*

---

## BIT 12 — Problem family (where it shows up)
1. **LC232 Implement Queue using Stacks** — the two-stack / amortized-O(1) warm-up (BIT 3).
2. **LC933 Number of Recent Calls** — plain FIFO front-expiry queue (BIT 4), the easy warm-up.
3. **LC622 Design Circular Queue** — ring buffer, fixed capacity, `% k` wrap (BIT 7).
4. **LC239 Sliding Window Maximum** — the canonical monotonic deque (BIT 5–6).
5. **LC1438 Longest Subarray with abs diff ≤ limit** — need BOTH max and min → **two deques** at once.
6. **LC862 Shortest Subarray with Sum ≥ K** — monotonic deque over **prefix sums** (⭐ the PARKED hard
   — this pattern unlocks it).
7. **LC1696 Jump Game VI / windowed DP** — when a DP transition is "max/min over the last k states," a
   deque turns O(n·k) → O(n).

## The gate to pass (M8 mastery check)
Explain out loud: **why does the deque hold the window's extreme in O(1) amortized?** (Answer: the
decreasing invariant makes the front the max by construction; each index enters and leaves exactly once
→ O(n) total.)
