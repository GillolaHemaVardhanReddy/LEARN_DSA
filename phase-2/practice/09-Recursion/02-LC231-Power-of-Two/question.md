# LC231 — Power of Two  (EASY · recursion drill)

🔗 https://leetcode.com/problems/power-of-two/

**Goal:** given an integer `n`, return `true` iff `n == 2^x` for some `x >= 0`.
`1 = 2^0` is true; `0` and all negatives are false.

## Signature
```cpp
bool isPowerOfTwo(int n);
```

## Example
```
1  -> true    (2^0)
16 -> true    (2^4)
3  -> false
0  -> false
```

## Constraints
- `-2^31 <= n <= 2^31 - 1`

## The idea to derive — recursion (halve while even)
A power of two is just 2 multiplied by itself: `1, 2, 4, 8, 16, ...`. Peel one factor of 2 at a
time by dividing by 2, and check what's left:
- **Base case:** `n == 1` → true (that's `2^0`, the fully-peeled power).
- **Guard first (his weak spot — boundaries):**
  - `n <= 0` → false. Reject BEFORE recursing: `0/2 = 0` forever (infinite recursion), and
    negatives are never powers of two.
  - `n` odd and `> 1` → false. An odd number other than 1 has a factor that isn't 2, so it can
    never be a power of two (e.g. `12 -> 6 -> 3`: 3 is odd, stop).
- **Recurse:** otherwise `return isPowRec(n / 2)` — halve and repeat.

Recognition cue: **"is it a pure power of b?" → recurse by dividing out b, base = 1, guard
non-positive / non-divisible FIRST.** (Bit-trick shortcut lives in the oracle: `n > 0 && (n & (n-1)) == 0`.)
