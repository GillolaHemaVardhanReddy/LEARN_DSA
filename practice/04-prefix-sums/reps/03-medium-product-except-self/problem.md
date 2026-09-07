# LC 238 — Product of Array Except Self  ·  Medium   ·   PREFIX (× instead of +)

**Link:** https://leetcode.com/problems/product-of-array-except-self/
**Topic:** Prefix — but PRODUCTS (prefix × suffix), and no division allowed

---

## Problem (plain English)
Return `out` where `out[i] = product of every element EXCEPT nums[i]`. **O(n), no division.**

## Examples
| nums | out |
|---|---|
| [1,2,3,4] | [24,12,8,6] |
| [-1,1,0,-3,3] | [0,0,9,0,0] |

## Constraints
- `2 ≤ nums.length ≤ 10^5`, answer fits in 32-bit. Follow-up: O(1) extra space (output aside).

## Before you code
1. `out[i] = (product of all LEFT of i) × (product of all RIGHT of i)`. Two prefix-style passes.
2. Why is division banned? A single `0` in the array breaks the divide trick — see example 2.
3. O(1) space: first pass fills `out` with left-products; second pass multiplies a running right-product.

## Result log
- Status: ___   The prefix idea generalised to products: ___
