# LC739 — Daily Temperatures  (Medium · array, stack, monotonic-stack)

🔗 https://leetcode.com/problems/daily-temperatures/

Given `temperatures[]`, return `answer[]` where `answer[i]` = how many days you wait
**after** day `i` to hit a **warmer** temperature. No warmer future day → `answer[i] = 0`.

## Examples (your dry-run set)
| temperatures | answer |
|---|---|
| `[73,74,75,71,69,72,76,73]` | `[1,1,4,2,1,1,0,0]` |
| `[30,40,50,60]` | `[1,1,1,0]` |
| `[30,60,90]` | `[1,1,0]` |

Constraints: `1 <= n <= 1e5`, `30 <= temp[i] <= 100`.
(Note: n up to 1e5 → an O(n²) brute is ~1e10 ops → **TLE**. That's the bridge.)

## Why this problem
Your first **monotonic stack** — "elements waiting for their warmer day." Each element
is pushed once and popped once → amortized **O(n)**. Coding it from understanding = L3→L4 evidence.
