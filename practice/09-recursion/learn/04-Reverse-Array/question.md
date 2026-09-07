# 04 — Reverse an Array/String  (M9 Recursion · two-pointer recursion)

🔗 **LC344 — Reverse String**  ·  https://leetcode.com/problems/reverse-string/  (EASY)
This one HAS a real judge target — reverse in place, and the recursive two-pointer solution
is exactly the muscle this drill builds. Do the drill, then submit LC344 for the AC.

**Goal:** reverse in place using recursion (not a while loop). Two pointers `l, r` walk inward;
swap the ends, recurse on the smaller inside chunk.

## Signature (LC344)
```cpp
void reverseString(vector<char>& s);   // in place, O(1) extra (recursion stack aside)
```
(Our drill uses `vector<int>` + a helper `reverseRec(a, l, r)` — same idea.)

## Example
```
['h','e','l','l','o'] -> ['o','l','l','e','h']
```

## Constraints
- `1 <= s.length <= 1e5`. ⚠️ Note the depth: recursion is O(n) stack — fine at 1e5 on LC, but
  know that an iterative two-pointer is O(1) space. Interviewers may ask for the iterative one too.

## The idea to derive (⭐ the base case is the interesting bit)
Base is **`l >= r`** (pointers meet OR cross), NOT `n==0`. Swap `a[l],a[r]` first, then
recurse `(l+1, r-1)`. Trace `size 1` (l==r, nothing to do) and `size 0` before you submit.

## Judge graduation
✅ **Submit LC344.** First-submit-clean if you reason the `l>=r` edge up front.
