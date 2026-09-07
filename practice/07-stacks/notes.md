# 07 — Stacks & Monotonic Stack  (teaching notes — reread cold, they rebuild the model)

> These notes TEACH, they don't just remind. Read top to bottom and the understanding comes back.
> The plain stack is a tool; the **monotonic stack** is the pattern that earns you O(n) on a
> whole family of "next/previous greater/smaller" problems. We go slow on the ONE idea that unlocks it.

## 0. Striver + LeetCode reps (watch/solve AFTER these notes)
- **Valid Parentheses** — LC20 (plain LIFO stack)
- **Next Greater Element** warm-up + **NGE II (circular)** — LC503
- **Daily Temperatures** — LC739
- **Online Stock Span** — LC901
- **132 Pattern** — LC456
- **Min Stack** — LC155
- **Remove K Digits** — LC402 (monotonic stack as a greedy shaper)

---

## BIT 0 — The one sentence
> **A stack answers "what's the MOST RECENT unfinished thing?" — Last In, First Out.**

Everything below is *when that question is the right question*, and how the **monotonic** version
turns a nested O(n²) scan into a single O(n) pass.

---

## BIT 1 — Why it exists (the "why")
A stack is a pile of plates: you only touch the **top**. Push a plate on, pop the top off. You can't
reach into the middle. That restriction sounds like a weakness — it's the whole point.

Reach for a stack when the natural order is **"resolve the most recent thing first"**:
- **Matching / undo:** brackets, nested tags, undo history — the thing you close is always the one you
  opened *most recently*.
- **Waiting for a future event:** each element is "waiting" for the next bigger/smaller one to show up.
  The one that's been waiting *shortest* (most recent) is the first to get resolved by a newcomer.

That second shape is the **monotonic stack**, and it's the money pattern. Keep BIT 3 in your head as
the anchor for the whole page.

> **Queue = fairness (oldest first). Stack = recency (newest first).**

---

## BIT 2 — Plain stack mechanics + balanced parentheses
The C++ container and its three gotchas:
```cpp
stack<char> st;
st.push(c);           // put on top
char x = st.top();    // READ the top — does NOT remove it
st.pop();             // REMOVE the top — returns void, gives you NOTHING
if (st.empty()) ...   // ALWAYS check before top()/pop()
```
Burn in now: **`pop()` returns `void`.** To use-and-remove you do `x = st.top();` *then* `st.pop();`.
Two statements, never one.

**Valid Parentheses (LC20)** — the model plain-stack problem. Push every opener; on a closer, the top
must be its partner:
```cpp
bool isValid(string s){
    stack<char> st;
    for (char c : s){
        if (c=='(' || c=='[' || c=='{') st.push(c);
        else {
            if (st.empty()) return false;          // ① closer with nothing open → fail
            char open = st.top(); st.pop();
            if (!match(open, c)) return false;      // ② top is the WRONG partner → fail
        }
    }
    return st.empty();                              // ③ leftover openers at the end → fail
}
```
Three distinct failure edges live in this one problem — memorize them, they're the classic misses:
1. **Empty-on-close** — a `)` arrives with an empty stack. Guard BEFORE reading top.
2. **Partner-not-equal** — top exists but isn't the matching opener.
3. **Empty-at-end** — you survived the loop but openers are still stacked → unbalanced.

---

## BIT 3 — THE mental unlock (read twice — this is the whole pattern) ⭐
> **A monotonic stack holds the INDICES of elements still WAITING for their answer. When a newcomer
> resolves them, you WRITE into the reserved `ans[st.top()]` SLOT — you never `push_back` the answer.**

Why indices and not values? Because the answer belongs to a *position*, and once you pop you need to
know *which* slot to fill. The index is the address; `nums[st.top()]` gets the value when you need it.

Why the SLOT and not `push_back`? Because elements get resolved in **pop-order**, which is NOT
position-order. If you `push_back`, answers land in the sequence they were *resolved*, scrambled
against the indices they belong to. Writing `ans[st.top()] = …` puts each answer at its own address.
This is the #1 bug on the pattern — the answer at the wrong slot.

**Direction rule:** for *next-greater*, keep the stack **decreasing** by value — so the moment a bigger
element shows up, it's exactly the answer for everyone smaller than it that's still waiting. Pop them
all, resolve each. The stack only ever shrinks from the top and grows on top; you never scan it.

---

## BIT 4 — The hand-run trace (RUN THIS YOURSELF — indices going in, getting resolved)
Next Greater Element to the right. `nums = [2, 1, 5, 3]`, so `n = 4`. Answer `-1` = "none to the right".
Stack holds **indices**; it stays decreasing *by the value they point to*.

```
ans = [-1,-1,-1,-1]   st = []          (bottom → top)

i=0  nums[0]=2   stack empty, nobody waiting → push 0.        st=[0]        (values: [2])
i=1  nums[1]=1   1 > nums[top]=nums[0]=2 ? NO. don't pop.
                 push 1.                                       st=[0,1]      (values: [2,1] ✓ decreasing)
i=2  nums[2]=5   5 > nums[top]=nums[1]=1 ? YES → ans[1]=5, pop.  st=[0]
                 5 > nums[top]=nums[0]=2 ? YES → ans[0]=5, pop.  st=[]
                 push 2.                                       st=[2]        (values: [5])
i=3  nums[3]=3   3 > nums[top]=nums[2]=5 ? NO. don't pop.
                 push 3.                                       st=[2,3]      (values: [5,3] ✓ decreasing)

loop ends. st=[2,3] still WAITING → they keep their default -1 (nothing bigger to their right).
ans = [5, 5, -1, -1]
```
Read what happened: index 1 (value 1) had been waiting the *shortest*, so the newcomer 5 resolved it
**first** — that's pop-order. If we'd `push_back`, we'd get `[5,5]` appended in that pop-order and lose
which index each belongs to. Writing `ans[st.top()]` dropped each 5 at its own address (slots 1 then 0).
Indices 2 and 3 never got a bigger neighbor, so they kept the `-1` default. **That's the pattern, whole.**

The template that trace runs:
```cpp
vector<int> nextGreater(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n, -1);                 // default = "none found"
    stack<int> st;                          // INDICES, decreasing by value
    for (int i = 0; i < n; ++i){
        while (!st.empty() && nums[i] > nums[st.top()]){   // guard empty BEFORE reading top
            ans[st.top()] = nums[i];        // write at the WAITING SLOT, not push_back
            st.pop();
        }
        st.push(i);
    }
    return ans;                             // whoever's left keeps -1
}
```
**Why O(n):** each index is pushed once and popped at most once → 2n stack ops total. You never *scan*
the stack; you only touch `top()`, pop what this newcomer resolves, and stop. Amortized O(1) per element.

---

## BIT 5 — The variant knobs (one engine, two dials)
Every next/previous-greater/smaller problem is the SAME engine with two dials turned:
| Want | Scan direction | While-pop condition (pop the loser) |
|---|---|---|
| **Next greater** to the right | left → right | `nums[i] >  nums[st.top()]` |
| **Next smaller** to the right | left → right | `nums[i] <  nums[st.top()]` |
| **Previous greater** to the left | left → right (answer = the top that *survives* after popping) | `nums[i] >= nums[st.top()]` |
| **Next greater to the LEFT** etc. | right → left | mirror the above |

Dials = **(1) which direction you scan**, **(2) `>` vs `<` in the pop test**. Nothing else changes.

**Reps that turn a dial:**
- **Daily Temperatures (LC739):** stack of indices, next-greater. But the answer is a **distance**, not a
  value: `ans[st.top()] = i - st.top()`. (Classic slip: restate "position of warmer day" → you wanted the
  *wait*, `i - j`. Read the question — value vs index vs distance.)
- **Online Stock Span (LC901):** previous-greater-**or-equal** (note the `>=`); span `= i - prevGreaterIndex`
  = the survivor on top after popping, or `i + 1` if the stack empties.
- **NGE II — CIRCULAR (LC503):** one lap leaves the suffix-maxima unresolved (nothing bigger to their right
  *yet* — the answer may wrap around). Do two laps:
  ```cpp
  for (int i = 0; i < 2*n - 1; ++i){
      while (!st.empty() && nums[i % n] > nums[st.top()]){ ans[st.top()] = nums[i % n]; st.pop(); }
      if (i < n) st.push(i);         // PUSH only on lap 1; lap 2 only RESOLVES
  }
  ```
  Three facts: loop bound `2n-1`, read `nums[i % n]` (plain `nums[i]` on lap 2 is **OOB**), push lap 1 only.
  Result rule: only the **global maximum** ends at `-1`; everyone else finds an answer through the wrap.
- **132 Pattern (LC456):** scan right→left, keep a **decreasing** stack as candidate "3"s, and track the
  largest popped value as "2" (the biggest thing beaten by some earlier bigger 3). If any current
  `nums[i] < the-2` you've got a `1 < 2 < 3` triple → true. Same monotonic engine, used as a detector.
- **Remove K Digits (LC402):** monotonic stack as a **greedy shaper** — to make the smallest number, pop a
  larger digit off the top whenever a smaller digit arrives and you still have removals left (`k`). Leftover
  `k` trims from the end; strip leading zeros. The stack keeps the result **increasing** so the high places
  stay as small as possible.

---

## BIT 6 — Min Stack (LC155) — the aux-stack design (remember, don't recompute)
Goal: a stack where `push`, `pop`, `top`, **and `getMin`** are all O(1). The trap is `getMin` — scanning
for the minimum is O(n). The fix is the reusable idea: **carry a second stack in lockstep that records
the min-so-far at each level.**
```cpp
class MinStack {
    stack<int> s, mn;                       // mn.top() = min of everything currently in s
public:
    void push(int x){
        s.push(x);
        mn.push(mn.empty() ? x : min(x, mn.top()));  // remember the running min at THIS level
    }
    void pop(){ s.pop(); mn.pop(); }        // lockstep — pop BOTH, always
    int top(){ return s.top(); }
    int getMin(){ return mn.top(); }        // O(1): read, never recompute
};
```
The insight that transfers: when a query would cost a scan, **precompute-and-store it alongside** so the
query is a read. `mn` moves exactly in step with `s` — every push pushes both, every pop pops both.
(Alt one-stack trick exists via storing deltas, but the aux stack is the one to know cold.)

---

## BIT 7 — The design recipe (run this BEFORE coding) ⭐ your Gate-A for stacks
Answer these four out loud before a line of code:
1. **INDEX or VALUE on the stack?** — Monotonic → almost always **INDEX** (you need the slot to write and
   the distance to compute). Compare with `nums[st.top()]`, never bare `st.top()`.
2. **Is `ans` written to the SLOT?** — `ans[st.top()] = …`, NOT `push_back` (pop-order ≠ position-order).
3. **Increasing or decreasing?** — Next-greater → decreasing stack, pop on `>`. Next-smaller → increasing,
   pop on `<`. Say which and why before you type the while.
4. **Is the empty-stack branch guarded BEFORE `.top()`?** — `while (!st.empty() && …)`. The `!st.empty()`
   comes FIRST (short-circuit) so you never read the top of an empty stack.

---

## BIT 8 — Complexity, read off the shape
- **Plain stack (LC20):** one pass, O(1) per char → **O(n) time, O(n) space** (worst case all openers).
- **Monotonic stack:** each index pushed once, popped once → **O(n) time** amortized, **O(n) space** for the
  stack + the answer array. The circular version is still O(n) — 2 laps is a constant factor.
- **Min Stack:** every op **O(1)**; **O(n) space** for the two stacks.

---

## BIT 9 — The classic traps (execution focus, boss — your leak board lives here)
1. **⭐ Reading `.top()`/`.back()` on an EMPTY stack is UNDEFINED BEHAVIOR — not 0, not -1, garbage/crash.**
   Guard the empty branch BEFORE the read, every time: `while (!st.empty() && nums[i] > nums[st.top()])`.
   This is your #1 boundary leak wearing a stack costume.
2. **Index vs value.** The stack holds the **INDEX**. Pushing the *value* makes `nums[st.top()]` read
   out-of-bounds (`nums[5]` on a size-5 array). Push `i`, compare via `nums[i] ? nums[st.top()]`.
3. **Answer at the wrong slot.** `ans[st.top()] = newcomer`. `push_back` scatters answers in pop-order.
4. **`pop()` returns void.** `int x = st.pop();` does NOT compile the way you want. It's `x = st.top();
   st.pop();` — two lines.
5. **Circular OOB.** In NGE II: read `nums[i % n]` and loop to `2n - 1`; plain `nums[i]` on lap 2 is OOB.
6. **Distance vs value vs index.** Daily Temps wants `i - st.top()` (a wait), not the warmer temperature.
   Reread what the question actually asks for before you assign to `ans`.
7. **Premature "done".** After fixing ONE thing, don't ask "is it ok?" — **trace your own code** on a
   hostile input (e.g. `[72,71,76]` where position ≠ distance) and read the output aloud yourself first.

---

## BIT 10 — Recognition cue (fill in YOUR words after the coding ladder)
> **"Match / undo / resolve the MOST RECENT thing first"** → plain stack (LIFO).
> **"For each element, find the NEXT or PREVIOUS greater/smaller"** — "next warmer day", "next greater",
> "span of days", "how far until…", histogram bars → **monotonic stack of INDICES**: pop the losers,
> answer at the waiting slot. Circular ⇒ loop `2n`, read `i % n`, push lap 1 only.
> **"O(1) min alongside the stack"** → aux stack recording min-so-far in lockstep.

*(Your teach-it-back line goes here once you've coded the ladder — that's the L6 signal.)*
