# PART A — COLD RECOGNITION TEST · 20 Questions

> **TEST MODE.** Closed-book. No coding. No hints. No LeetCode titles (they'd spoil it).
> For each: **(1) pattern · (2) the trigger in the statement · (3) target time + space complexity.**
> ~2 min each. First instinct is the measurement.
>
> Interleaved on purpose — you never know which topic is coming. That's the skill.

---

### Q1
You're given **four** integer arrays `A`, `B`, `C`, `D`, all of length `n`. Count the number of
index tuples `(i, j, k, l)` such that `A[i] + B[j] + C[k] + D[l] == 0`.
Constraints: `n ≤ 200`. Arrays are unsorted and may contain duplicates and negatives.

---

### Q2
A conveyor belt has packages that must be shipped within `D` days. The packages must be loaded
**in the given order**. Each day you load packages onto a ship whose maximum weight capacity is
some fixed number `C` — you can't exceed `C` on any single day. Find the **least** capacity `C`
that still gets every package shipped within `D` days.

---

### Q3
Stock prices arrive **one at a time** (streaming). After each new price, report the number of
consecutive days — counting today and going backwards — on which the price was **less than or
equal to** today's price.

---

### Q4
A string of uppercase English letters. You may change **at most `k`** characters, each to any
other uppercase letter. Return the length of the **longest substring** you can end up with that
consists of one single repeated letter.

---

### Q5
You have coin denominations with **unlimited supply** of each, and a target amount. Return the
**fewest** number of coins that sum exactly to the amount, or `-1` if it's impossible.

---

### Q6
A **binary** array (only 0s and 1s) and an integer `goal`. Count the number of **subarrays**
whose sum is **exactly** `goal`.

---

### Q7
Each person `i` has weight `people[i]`. Every boat carries **at most 2 people** and has a weight
limit `limit` (guaranteed `people[i] <= limit`). Return the **minimum number of boats** needed to
carry everyone.

---

### Q8
The digits `2`–`9` each map to a set of letters, like an old phone keypad (`2 → "abc"`,
`3 → "def"`, …). Given a string of such digits, return **every** letter combination the string
could spell. Order doesn't matter.

---

### Q9
An integer array and an integer `limit`. Return the length of the **longest subarray** such that
the **difference between the maximum and the minimum** element in that subarray is `<= limit`.

---

### Q10
A list of song durations in seconds. Count the number of pairs `(i, j)` with `i < j` whose
**total duration is divisible by 60**.

**Examples:** `[30,20,150,100,40]` → 3 (30+150, 20+100, 20+40) · `[60,60,60]` → 3 · `[45,30]` → 0
---

### Q11
A **sorted** integer array where every element appears **exactly twice**, except for one element
which appears once. Find that single element. Required: **O(log n)** time, **O(1)** space.

**Examples:** `[1,1,2,3,3,4,4,8,8]` → 2 · `[3,3,7,7,10,11,11]` → 10 · `[5]` → 5
---

### Q12
Asteroids in a row, given as an array. The **absolute value** is the size; the **sign** is the
direction (positive = moving right, negative = moving left). Two asteroids collide only if they
move toward each other; the smaller one explodes, and if they're equal size **both** explode.
Asteroids moving the same direction never meet. Return the final state.

**Examples:** `[5,10,-5]` → `[5,10]` · `[8,-8]` → `[]` · `[10,2,-5]` → `[10]` · `[-2,-1,1,2]` → `[-2,-1,1,2]`
---

### Q13
A string `s` and an integer `k`. Return the **maximum number of vowels** contained in any substring
of `s` of length **exactly** `k`.

**Examples:** `"abciiidef", k=3` → 3 · `"aeiou", k=2` → 2 · `"leetcode", k=3` → 2
---

### Q14
Given a string, split it into pieces such that **every piece is a palindrome**. Return **all
possible** such splittings.

**Examples:** `"aab"` → `[["a","a","b"],["aa","b"]]` · `"a"` → `[["a"]]` · `"ab"` → `[["a","b"]]`
---

### Q15
A string of digits, where `'A' = 1`, `'B' = 2`, …, `'Z' = 26`. Count the number of distinct ways
the string can be decoded into letters. (`"12"` → `"AB"` or `"L"` ⇒ 2 ways. A piece can't start
with `'0'`.)

**Examples:** `"12"` → 2 · `"226"` → 3 (`2-26`, `22-6`, `2-2-6`) · `"06"` → 0
---

### Q16
A car with a fixed passenger `capacity` drives **east only** (never turns around). You're given
trips as `(numPassengers, startLocation, endLocation)`. Passengers get on at `start` and off at
`end`. Return whether it's possible to complete **all** trips without ever exceeding `capacity`.

**Examples:** `trips=[[2,1,5],[3,3,7]], capacity=4` → false · same trips, `capacity=5` → true · `[[3,2,7],[3,7,9],[8,3,9]], capacity=11` → true
---

### Q17
Two strings that may contain the character `'#'`, which means **backspace** (deletes the character
before it; on an empty string it does nothing). Return whether the two strings are **equal** after
all backspaces are applied.
**Constraint: you must do it in O(1) extra space.**

**Examples:** `"ab#c", "ad#c"` → true · `"ab##", "c#d#"` → true · `"a#c", "b"` → false
---

### Q18
A `pattern` string like `"abba"` and a `sentence` like `"dog cat cat dog"`. Return whether the
sentence **follows** the pattern — meaning there's a **one-to-one** correspondence between each
letter in the pattern and each word in the sentence (no two letters map to the same word, and no
word maps to two letters).

**Examples:** `"abba", "dog cat cat dog"` → true · `"abba", "dog cat cat fish"` → false · `"aaaa", "dog cat cat dog"` → false
---

### Q19
An `m × n` matrix where **each row is sorted ascending**, and the **first integer of each row is
greater than the last integer of the previous row**. Search for a target value.
Required: **O(log(m·n))** time.

**Examples:** `[[1,3,5,7],[10,11,16,20],[23,30,34,60]], target=3` → true · same matrix, `target=13` → false
---

### Q20
An integer array that **may contain negative numbers**, and an integer `k`. Return the length of
the **shortest non-empty subarray** whose sum is **at least** `k`. Return `-1` if none exists.
Constraints: `n ≤ 10⁵`.

**Examples:** `[1], k=1` → 1 · `[1,2], k=4` → -1 · `[2,-1,2], k=3` → 3
---

> **After all 20:** score honestly in `RESULTS.md`. **v2 (2026-09-08):** Parts B/C are retired — the per-pattern read feeds the Tier-0 re-entry checkpoints (test → repair → move, one topic at a time). Q10–Q20 examples were seeded on 2026-09-08 (statement-seeding rule, LEARNING_PROFILE 2026-08-10).
