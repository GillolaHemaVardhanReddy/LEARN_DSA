# 07 — Stacks & Monotonic Stack (revision notes)

> Revision-first: cover the page, rebuild the template from the recognition cue, THEN check.
> Tied to your reps: LC20 (plain stack), Daily Temps (LC739), NGE warm-up, NGE II (LC503).

---

## A. Plain stack — when?
**Cue:** "match / undo / resolve the MOST RECENT thing first" → LIFO → stack.
- Valid Parentheses (LC20): push opens; on a close, the top MUST be its match (and stack non-empty);
  at the end the stack MUST be empty. Two failure edges in one problem: **close on empty stack**, and
  **leftover opens at the end**.

---

## B. Monotonic stack — the recognition trigger (memorize this line)
> **"For each element, find the NEXT (or PREVIOUS) GREATER / SMALLER element"** → monotonic stack.
> Surface tells: "next warmer day", "next greater", "span of days", "how far until…", histogram bars.

**Why it's O(n):** each index is pushed once and popped once. You never *scan* the stack — you only
ever look at `top()`, pop the ones this new element resolves, and stop. Total work = 2n pushes/pops.

---

## C. The canonical template — Next Greater to the RIGHT (stack of INDICES)
```cpp
vector<int> ans(n, -1);          // default = "none found"
stack<int> st;                   // holds INDICES, not values
for (int i = 0; i < n; ++i) {
    while (!st.empty() && nums[i] > nums[st.top()]) {  // current beats the waiting top
        ans[st.top()] = nums[i]; // <-- write at the RIGHT SLOT (the waiting index), not push_back
        st.pop();
    }
    st.push(i);
}
```
- Stack stays **decreasing by value** (bottom→top). That order is what guarantees the next pop is
  always the correct answer for the resolved element.

---

## D. The 4 variants — only two knobs change
| Want | Scan direction | While-pop condition (pop the loser) |
|---|---|---|
| **Next greater** to the right | left → right | `nums[i] > nums[st.top()]` |
| **Next smaller** to the right | left → right | `nums[i] < nums[st.top()]` |
| **Previous greater** to the left | left → right (answer = new top after popping) | `nums[i] >= nums[st.top()]` |
| **Next greater** (or prev) to the left | right → left | mirror the above |
Knobs = **(1) direction you scan**, **(2) `>` vs `<` in the pop test**. Everything else is the same engine.

---

## E. Variant reps you've done
- **Daily Temperatures (LC739):** store INDEX on the stack; the answer is a **distance** = `i - st.top()`,
  NOT the index. (Your bug: restated "position of warmer day" → answer is the *wait*, `j - i`.)
- **Online Stock Span (LC901):** flip to **previous-greater-or-equal**; the span = `i - prevGreaterIndex`.
- **NGE II (LC503) — CIRCULAR:** one lap leaves the suffix-maxima still on the stack (nothing greater to
  their right yet). Fix:
  ```cpp
  for (int i = 0; i < 2*n - 1; ++i) {
      while (!st.empty() && nums[i % n] > nums[st.top()]) { ans[st.top()] = nums[i % n]; st.pop(); }
      if (i < n) st.push(i);      // only PUSH on lap 1; lap 2 only RESOLVES
  }
  ```
  Key facts: loop `2n-1`, read `nums[i % n]` (NOT `nums[i]` → that's OOB), don't push on lap 2.
  Result rule: only the **global maximum** gets `-1`; everyone else finds an answer via the wrap.

---

## F. YOUR bug-watch on this pattern (from the leak board — read before submit)
1. **Index vs value:** the stack holds the **INDEX**. Compare with `nums[st.top()]`, never `st.top()`.
   (Pushing the value made `nums[st.top()]` read OOB — `nums[5]` on a size-5 array.)
2. **Right slot:** record with `ans[st.top()] = …`. Do NOT `push_back` in pop-order — answers land at
   the wrong indices.
3. **Circular OOB:** `nums[i % n]`, and loop bound `2n-1`.
4. **Premature "done":** after fixing ONE thing, don't ask "is it ok" — **trace your own code** on a
   hostile input (e.g. `[72,71,76]` where position ≠ distance) and read the output yourself first.

---

## G. Complexity
- Time **O(n)** (amortized: each index pushed/popped once). Space **O(n)** for the stack + answer.

## H. One-line recall
> "Next/previous greater/smaller for each element" → **monotonic stack of indices**; pop the losers,
> answer at the waiting slot; circular ⇒ loop `2n`, read `i % n`, push lap 1 only.
