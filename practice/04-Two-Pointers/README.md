# Two Pointers — Practice Set (building-block ladder)

> Each rung adds exactly ONE new sub-skill. Do them IN ORDER — later rungs assume the earlier.
> Recognition-first: write the cue line + identify the SHAPE before coding. Judge = ground truth.

## The ladder (why this order)
| # | Problem | Diff | NEW building block it teaches |
|---|---------|------|-------------------------------|
| 01 | LC167 Two Sum II (sorted) | easy | **Converging** pointers, sum-steered (`L++`/`R--` by comparison). THE core mechanic. |
| 02 | LC26 Remove Duplicates from Sorted Array | easy | **Fast/slow** same-direction — the **write pointer** (in-place rearrange). |
| 03 | LC15 3Sum | med | **Fix one + two-pointer the rest** + the **skip-duplicates** trick. The keystone. |
| 04 | LC11 Container With Most Water | med | **Greedy** converging — move the **limiting** side; steer by a *derived* quantity (area). |
| 05 | LC42 Trapping Rain Water | hard | **Stateful** converging — track left-max / right-max while two pointers close in. Capstone. |

## The 3 shapes (from `Notes/03-Two-Pointers.md`)
- **Converging** (opposite ends → toward each other): 01, 03, 04, 05
- **Fast/slow** (same direction, read races / write trails): 02
- **Fix-one-then-two-pointer**: 03 (and its extension, 4Sum)

## The rule for each problem
1. Cue line: `cue: ___ → two pointers because ___` (and: is the data SORTED? which shape?)
2. Brute force + complexity + where the wasted work is.
3. Use the **constraints → target complexity** (10⁸ rule) to know what you're aiming for.
4. Code it. Run the **boundary checklist** before submit (your #1 leak):
   - `while(L < R)` bound · skip-duplicate edges · `a[L]+a[R]` overflow (use `long`/`int` care) · empty/size-1.
5. Submit to LeetCode. Bring Tommy whichever fights back.

## After the set
We fill the `🔲 TO FILL AFTER REPS` section of `Notes/03-Two-Pointers.md` with your real cues + gotchas,
then a `/drill` to test recognition. Optional extensions: LC16 (3Sum Closest), LC18 (4Sum), LC75 (Sort Colors / Dutch flag), LC680 (Valid Palindrome II).
