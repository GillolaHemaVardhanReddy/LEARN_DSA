# M10 — Backtracking  ·  RECURSION'S PAYOFF  (teaching notes — reread cold, they rebuild the model)

> These notes TEACH, they don't just remind. Read top to bottom and the understanding comes back.
> Backtracking sits directly on M9 Recursion, and it feeds M12 Trees, M16 Graphs (DFS), and the
> "try every option" family of hards (N-Queens, Sudoku, Word Search).
> This is a **way of searching**, not 6 problems.

## 0. Striver videos (Recursion + Backtracking series)
Watch **[L6] first** — it's the bridge from M9 and it's where subsets actually come from.
- **[L6] Recursion on Subsequences** — https://youtu.be/AxNNVECce8c  ⭐ start here
- **[L7] All Patterns in Recursion (print/count/any)** — https://youtu.be/eQCS_v3bw0Q  ⭐ the shape-changer
- **[L10] Subset Sum I** — https://youtu.be/rYkfBRtMJr8
- **[L12] Permutations (Approach 1 — used[] array)** — https://youtu.be/YK78FU5Ffjw
- **[L13] Permutations (Approach 2 — swap)** — https://youtu.be/f2ic2Rsc9pU
- **[L8] Combination Sum** — https://youtu.be/OyZFFqQtu98
- **[L11] Subset Sum II (the duplicate-skip rule)** — https://youtu.be/RIn3gOkbhQE
- **[L17] Palindrome Partitioning** — https://youtu.be/WBgsABoClE0
- **[L14] N-Queens** — https://youtu.be/i05Ju7AftcM  *(stretch)*
- **[L18] Rat in a Maze** — https://youtu.be/bLGZhJlt4y0  *(grid version — the LC79 twin)*

Visualizer: https://visualgo.net/en/recursion · draw the tree, watch the path grow and shrink.

---

## BIT 0 — The one sentence
> **Backtracking = walk down a decision tree building ONE partial answer, and whenever you return
> from a branch, undo the choice you made so the path is exactly as you found it.**

Everything below is *why that undo exists* and *how to run it in your head*.

---

## BIT 1 — Why it exists (the "why")

Some problems don't ask for *the* answer. They ask for **every arrangement that satisfies a rule**:
- every subset of `[1,2,3]`
- every permutation
- every way to place 8 queens so none attack
- every valid way to fill a Sudoku grid
- every path through a maze

You cannot compute these with a formula. There's no clever O(n) trick. **You have to try things.**
The answer set is exponential — 2ⁿ subsets, n! permutations — so touching all of them is not a
failure of your algorithm, it's the size of the output.

So the honest question isn't "how do I avoid the exponential?" It's:

> **How do I enumerate every possibility without (a) missing any, (b) repeating any, and
> (c) burning memory on n! separate copies?**

Naive answer: build every candidate from scratch, independently. For subsets you *can* do this — the
bitmask trick, `mask & (1<<i)`, one fresh vector per mask. That's what your LC78 brute does. But it
**hard-codes "2 choices per element."** The moment a slot has *n* choices (permutations), or a
variable number (combination sum, where you may reuse a number k times), the mask dies. It cannot
express the tree.

Backtracking is the general answer. And its trick is a memory trick:

> **Keep ONE path. Mutate it on the way down. Un-mutate it on the way up.**

Instead of n! vectors, you hold **one** vector of length ≤ n, and it walks the whole tree.

---

## BIT 2 — The hand-run trace (do this, don't skim it)

`nums = [1,2,3]`, subsets, pick-branch first. Track ONE array called `path`.

```
frame 0: path=[]        choose 1 → path=[1]
  frame 1: path=[1]     choose 2 → path=[1,2]
    frame 2: path=[1,2] choose 3 → path=[1,2,3]
      frame 3: i==n     EMIT [1,2,3]
    frame 2: UN-CHOOSE 3 → path=[1,2]        ← the undo
    frame 2:            skip 3
      frame 3: i==n     EMIT [1,2]
  frame 1: UN-CHOOSE 2 → path=[1]            ← the undo
  frame 1:              skip 2
    frame 2: path=[1]   choose 3 → path=[1,3]
      frame 3: i==n     EMIT [1,3]
    frame 2: UN-CHOOSE 3 → path=[1]
    frame 2:            skip 3
      frame 3: i==n     EMIT [1]
frame 0: UN-CHOOSE 1 → path=[]               ← the undo
frame 0:              skip 1
  ... same subtree, without the 1 ...        EMIT [2,3] [2] [3] []
```

Eight subsets. **One array.** Read the un-choose lines again and notice *what they guarantee*:

> **Every frame receives `path` in exactly the state it will hand back.** Frame 1 got `path=[1]`.
> After all its work, frame 1 returns with `path=[1]`. It cleans up after itself.

That is the invariant. **Boss stated it himself, cold, 2026-07-10:**

> *"if we go to next call with a state and come back then we should have same state of sett"*

That sentence **is** backtracking. The rest is bookkeeping.

---

## BIT 3 — The unlock (why the undo is *forced*, not stylistic)

Ask: why not just skip `pop_back()` and pass a fresh copy of `path` into each call?

You can! `solve(i+1, path)` by value. It's correct. It's also **O(n) copying per node × 2ⁿ nodes**,
and it throws away the whole point. The shared-path version is the reason backtracking is cheap.

But the moment `path` is **shared**, the sibling branch *inherits your mess*. Frame 1's not-pick
branch must start from `[1]`, not from `[1,2,3]` that the pick branch left behind. Nobody else can
clean that up — the parent doesn't know what you pushed, the child already returned.

> **The frame that made the choice is the only frame that knows how to unmake it.**

Hence: `choose → explore → un-choose`, three consecutive lines, always in the same frame.

### ⛔ The trap this kills (boss's M#8, 2026-07-10)
Threading a `pick` flag down as a parameter — `solve(i, pick)` with `if(pick) push` … `if(pick) pop` —
is **derive-don't-maintain in recursion costume**. You've created a variable that must *agree* with
"did I push?", and it desyncs instantly:
- the decision is made at the parent's call-site, but the action happens in the child
- the `pop` ends up between the two child calls, popping the wrong element
- forcing `pick=1` at the root means `{}` can never be born

Delete the flag. **A frame owns its own choice.** Then the root is just `solve(0)`, every frame is
uniform, and `push / recurse / pop / recurse` reads in a straight line.

---

## BIT 4 — The recipe (the shape of every backtracking function)

```cpp
void solve(STATE) {
    if (isComplete(STATE)) { ans.push_back(path); return; }   // base: emit

    for (each choice c available at this step) {               // the fork
        if (!isValid(c)) continue;                             // prune (optional)

        make(c);          // choose    → mutate path (+ any side state)
        solve(NEXT);      // explore
        unmake(c);        // un-choose → restore EVERYTHING make() touched
    }
}
```

**Four questions answer any backtracking problem:**
1. **What is a partial answer?** (`path` — a vector, a string, a board)
2. **When is it complete?** (base case → emit)
3. **What are the choices at this step?** (the loop body)
4. **What state must be undone?** (everything `make()` touched — *all* of it)

The two-branch shape you wrote for LC78 is just this recipe where the loop has exactly two
iterations: *take `nums[i]`* and *don't*. Same machine.

### The two frame identities — know which one you're in
| | Frame = **INDEX** ("do I take `nums[i]`?") | Frame = **SLOT** ("what goes in position d?") |
|---|---|---|
| Fork | 2 branches (in / out) | loop over all valid candidates |
| Advance | `i+1` | `d+1` |
| Typical | subsets, subset-sum, pick/not-pick | permutations, N-Queens, Sudoku |
| Extra state | usually none | usually a `used[]` / column-set |

**Combination-style problems (LC39/77/216) use a hybrid:** a `for` loop over `start..n-1` with a
`start` index, which is the index-frame written as a loop so it can both skip *and* reuse.

---

## BIT 5 — Complexity (say it right in an interview)

Backtracking cost = **(number of nodes in the tree) × (work per node)**.
- Subsets: 2ⁿ leaves, ~2ⁿ⁺¹ nodes; copying a subset at each leaf is O(n) → **O(n · 2ⁿ)** time.
- Permutations: n! leaves; O(n) copy at each → **O(n · n!)**.
- Space: **O(n)** for the path + **O(n)** call stack (excluding the output).
  *Always state output-space separately* — you can't beat O(n · 2ⁿ) output if they asked for all of it.

Pruning changes the constant *and* can change the exponent's base in practice (N-Queens), but the
worst-case bound stays exponential. Say that out loud; don't claim pruning makes it polynomial.

---

## BIT 6 — Traps (the ones that will actually bite you)

1. **Forgetting the un-choose.** Symptom: duplicate subsets + missing subsets, both at once.
   *Cure:* the three lines are always adjacent. If `choose` and `un-choose` are not visibly wrapped
   around the recursive call, you have a bug.
2. **Un-choosing only *some* of the state.** If `make()` pushed to `path` **and** set `used[c]=true`,
   then `unmake()` must pop **and** clear. Partial undo = the nastiest, quietest bug in the topic.
3. **A flag/parameter that must agree with the path** (M#8). Delete it. Derive, don't maintain.
4. **Emitting a reference instead of a copy.** `ans.push_back(path)` copies — good. Storing
   `&path` or a pointer means every answer aliases the same (eventually empty) array.
5. **Oracle contamination when stress-testing** (M#9). The brute must be built with *different
   machinery* than the optimal — bitmask vs DFS, `next_permutation` vs DFS. Two independent
   derivations agreeing is evidence. One agreeing with itself is a tautology.
6. **Duplicates in the input** (LC90/LC40/LC47). Sort first, then at each loop level skip
   `if (i > start && nums[i] == nums[i-1]) continue;`. The rule is *skip duplicates at the same
   depth*, not globally — a value may legitimately repeat *down* a path.

---

## BIT 7 — The recognition cue (paste this into PATTERN_JOURNAL)

> **If you see: "return ALL / every / list the possible ___", or "count the number of ways" where a
> formula won't do, or a constraint that screams tiny (`n ≤ 10`, `n ≤ 20`, a 9×9 board) —
> → consider BACKTRACKING.**

Supporting tells:
- The output is itself exponential (all subsets / permutations / partitions / placements).
- **`n ≤ 20` is the loudest signal on LeetCode.** A tiny bound is permission to be exponential.
- The problem has *choices per step* and choices constrain later choices (queens, Sudoku, maze).
- "Find *a* valid configuration" → same machine, but return `bool` and short-circuit on the first
  success (`if (solve(next)) return true;`) instead of collecting all.

**Then ask the four questions** (BIT 4), write the frame, and make sure `choose / explore /
un-choose` are three consecutive lines.
