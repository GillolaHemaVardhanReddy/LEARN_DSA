# solutions/

Your code lives here, organized by curriculum module. **Layout (one folder per problem):**

```
solutions/
  04-Sliding-Window/                       ← "04" = curriculum order, then the real name
    01-Minimum-Size-Subarray-Sum/          ← "01" = problem order within the topic
      problem.md      ← the question, examples, constraints, "before you code" checklist
      solution.cpp    ← boilerplate you fill in (has a local test harness in main())
  02-Arrays-and-Hashing/
    01-Two-Sum/
      problem.md
      solution.cpp
```

Readable-names rule (no cryptic codes):
- **Topic folder** = `<2-digit order>-<Readable-Topic-Name>` (e.g. `04-Sliding-Window`).
- **Problem folder** = `<2-digit order>-<Readable-Problem-Name>` (e.g. `01-Minimum-Size-Subarray-Sum`).
  The LeetCode number + link live **inside** `problem.md`, not in the folder name.
- Study notes per topic live in the top-level `Notes/` folder (e.g. `Notes/04-Sliding-Window.md`).
- `problem.md` = Tommy writes the problem card. `solution.cpp` = Hema writes the code.
- `solution.cpp` keeps a `main()` test harness so you can run it on onlinegdb; paste **only**
  the `Solution` class into LeetCode.
- A problem only counts as **solved** once it's **Accepted on the judge** (LeetCode), not when
  Tommy approves it. The judge is the final word (see `CLAUDE.md` §16).

The commit history of this repo is your real progress log — every solve, level change,
and revision is captured by `/endsession`.
