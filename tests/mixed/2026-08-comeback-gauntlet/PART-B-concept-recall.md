# PART B — CLOSED-BOOK CONCEPT RECALL (repair pass)

> **Run ONLY on what Part A exposed** — plus the overdue queue block at the bottom (non-negotiable,
> all of it is 23–29 days late). Reconstruct from memory FIRST. Open notes only after you've
> produced an answer, right or wrong — a wrong answer you generated sticks better than a right one
> you read.

---

## M2 — Hashing (L4)
1. Why is a hash map O(1) **average** but O(n) **worst** — what actually causes the worst case?
2. The four sub-patterns: **complement · frequency · group-by-key · membership**. Give the surface
   cue for each in one line.
3. **The #9 gate, out loud:** you see "find a pair / find two things that combine to X."
   What is the FIRST question you ask, and what does each answer route you to?
4. When does the key need **canonicalizing** (and what broke on LC149)?

## M3 — Two Pointers (L4)
1. Name the three shapes: **converging · fast-slow · same-direction**. One cue each.
2. What single precondition makes converging two-pointers legal, and *why* — what does moving a
   pointer let you throw away?
3. Dutch-flag 3-way partition: what do `low`, `mid`, `high` mean, and why does the `high` swap
   **not** advance `mid`?

## M4 — Sliding Window (L5)
1. The template shape in one line (driver, invariant, record).
2. What kills sliding window dead? (Two things. One of them is why Q20 exists.)
3. **Derive-don't-maintain audit:** name two variables people hand-maintain in a window that are
   actually derivable.
4. `atMost(k) − atMost(k−1)`: why does the helper over-count, and why does the subtraction cancel
   exactly? Write `atMost` from memory — is `ans += r−l+1` guarded or unconditional?

## M5 — Prefix Sum (L4)
1. The formula for `sum(l..r)` from a prefix array — and what `L = 0` needs.
2. **GOAL × KEY**: what goes in the map's key, what goes in the value, and how does the choice
   change between *count* subarrays and *longest* subarray?
3. Why does `map[0] = -1` (or `map[0] = 1`) get seeded, and what breaks without it?
4. **Difference array**: when do you reach for it instead of a plain prefix sum?

## M6 — Binary Search (L4)
1. Write the safe `mid`. Why does `(lo + hi) / 2` die?
2. The real trigger is **not** "the array is sorted." State it properly (one sentence).
3. `while (l < r)` vs `while (l <= r)` — which one do you use when **mid could be the answer**, and
   why does the other one lose it?
4. **Search-on-answer**: name the three pieces you must identify before writing a line.

## M7 — Stacks + Monotonic Stack (L4)
1. What does a monotonic stack **hold** — and why is that the answer, not the other one?
2. Why write to `ans[st.top()]` instead of `ans.push_back(...)`?
3. Increasing vs decreasing stack: which one answers "next greater," and when do you pop?
4. Min Stack: why does a single `int minSoFar` fail?

## M8 — Queues / Monotonic Deque (L3)
1. Why does a sliding-window **maximum** need a deque instead of a stack?
2. What's stored in the deque, and how does expiry get tested?
3. Prove the O(n): what happens to each element, at most how many times?

## M9 — Recursion + Memoization (L4)
1. **Leap of faith** in one sentence.
2. The two shapes (parameterized vs functional) — when does each fit?
3. Memo in two lines: where does the lookup go, where does the store go, and what makes a
   sentinel value **legal**?
4. **Chain vs fork:** how do you decide a memo is worth it — what's the test?
5. Fast power: why is `x * pow(x, n/2) * pow(x, n/2)` still O(n)? Produce the
   "doubling cancels halving" line FIRST, no table. *(This one failed cold on 7/08 — it's owed.)*

## M10 — Backtracking (L3, the shakiest)
1. State the **un-choose invariant** in one sentence — what must `path` look like when frame `i`
   returns to its caller?
2. **Why can pick/not-pick NEVER produce permutations?** Want the structural answer, not
   "because order matters."
3. Two frame templates. For each, say where the emit goes and what the recursive call means:
   - **binary fork** (pick / not-pick)
   - **loop over choices** (`for i = start..n`)
   *(This is the LC90 debt — his own words at close: "I don't know why we did all that removal.")*
4. `start` vs `i` vs `i+1` in the recursive call — what does each one buy you, on which problem?
5. What does `used[]` actually buy you that a `start` index cannot?

## M1 — Complexity (L3*)
Folded into Part A — every answer required a complexity. Repair only if those were wrong.

---

## 🔴 OVERDUE QUEUE — run these regardless of Part A (23–29 days late)

| Item | Due since | What it is |
|---|---|---|
| M9 recursion+memo recall (+3d) | 2026-07-11 | Item (3) above cold — the call-tree **magnitude** wasn't instant last time |
| Fast power recall (+3d) | 2026-07-11 | Item (5) above — produce doubling-cancels-halving with **no table** |
| M10 un-choose invariant (+1d) | 2026-07-11 | Items (1)–(3) above |
| **M#9 re-test** — oracle independence | 2026-07-11 | Before coding: name in ONE sentence how the brute's machinery differs from the optimal's. Clears when he flags a contaminated oracle **unprompted** |
| **M#10 re-test** — oracle must not touch what the optimal reads | 2026-07-14 | "Can my brute mutate anything the optimal reads?" Rule: **a brute takes a copy, never a mutable reference** |
| LC46 cold re-derive of the permutation frame (+3d) | 2026-07-17 | The video debt. Write the frame from memory: base → loop → skip-if-used → choose **both** pieces → explore → un-choose **both** |
| M8 deque recall (+7d) | 2026-07-15 | M8 section above |
