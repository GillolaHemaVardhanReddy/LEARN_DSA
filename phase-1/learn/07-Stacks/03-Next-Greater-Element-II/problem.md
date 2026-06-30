# LC503 — Next Greater Element II  (Medium · array, stack, monotonic-stack)

🔗 https://leetcode.com/problems/next-greater-element-ii/

Given a **circular** array `nums`, return `ans[]` where `ans[i]` = the first number
greater than `nums[i]` when scanning to the right **with wraparound**. If none exists, `-1`.

## Examples (your dry-run set)
| nums | ans | why |
|---|---|---|
| `[1,2,1]` | `[2,-1,2]` | last `1` wraps to the front to find `2` |
| `[1,2,3,4,3]` | `[2,3,4,-1,4]` | last `3` wraps to find `4` |
| `[5,4,3,2,1]` | `[-1,-1,-1,-1,-1]` | strictly decreasing, nothing greater |

Constraints: `1 <= n <= 1e4`, `-1e9 <= nums[i] <= 1e9`.

## Why this problem
Your NGE engine, **one twist: circular**. Walk indices `0 → 2n-1`, read with `% n`,
store the value (not a distance). On the second lap, only RESOLVE waiters — don't push
fresh ones. Still O(n): 2n iterations, each index pushed/popped once.
