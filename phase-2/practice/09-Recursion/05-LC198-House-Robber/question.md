# LC198 — House Robber  (MEDIUM · THE keystone "choice" recursion)

🔗 https://leetcode.com/problems/house-robber/

**Goal:** rob houses along a street for the **max money**, but you CANNOT rob two
**adjacent** houses (adjacent robberies trip the alarm). Return the max you can steal.

## Signature
```cpp
int rob(vector<int>& nums);
```

## Example
```
nums=[1,2,3,1]     -> 4    (rob house 0 + house 2 = 1+3)
nums=[2,7,9,3,1]   -> 12   (rob house 0 + house 2 + house 4 = 2+9+1)
```

## Constraints
- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 400`

## The idea to derive — the DP "choice" template
Stand at each house `i` and make ONE decision:
- **ROB it** → take `nums[i]`, but the neighbor `i-1` is now off-limits, so jump to `f(i-2)`.
- **SKIP it** → take nothing here, fall back to `f(i-1)`.
- Answer for this house = **MAX** of the two: `f(i) = max(nums[i] + f(i-2), f(i-1))`.

Base case: `i < 0 → 0` (no houses left, no money). Final answer = `f(n-1)`.

Naive recursion is exponential — the two branches re-solve the same `i` again and again.
The subproblem is indexed by **just `i`**, so **memoize on `i`** (cache, sentinel `-1`) → O(n).

Recognition cue: **"at each item, take-it (+skip a neighbor) vs skip-it → MAX" → this is the
canonical DP choice recurrence.** Every take/skip DP is a variation of House Robber.
