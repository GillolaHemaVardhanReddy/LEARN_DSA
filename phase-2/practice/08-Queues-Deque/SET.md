# M8 Queues / Deque — L4 PRACTICE SET  (built 2026-07-08)

**Mode:** PRACTICE (help-allowed, ≤1 hint then stop). **Promotion:** judge-AC only.
**Current M8 level: L3.** This set is the L4 gate.

Already banked (LEARN set, judge-confirmed 7/04): LC232 · LC933 · LC239.

## The set — run in this order

| # | Problem | Diff | Pattern | Why it's here |
|---|---------|------|---------|---------------|
| 05 | [LC225 Implement Stack using Queues](05-LC225-Implement-Stack-Using-Queues/) | Easy | queue mechanics / design | Feel what a FIFO *cannot* do. Warm-up. |
| 06 | [LC2073 Time Needed to Buy Tickets](06-LC2073-Time-Needed-To-Buy-Tickets/) | Easy | queue sim → O(n) counting | Brute-as-oracle; then realize you don't need the queue. |
| 02 | [LC1438 Longest Subarray Abs Diff ≤ Limit](02-LC1438-Longest-Subarray-Abs-Diff/) | Medium | **two** monotonic deques | LC239 twice at once. The core M8 medium. |
| 04 | [LC1696 Jump Game VI](04-LC1696-Jump-Game-VI/) | Medium | deque-optimized DP | DP whose transition IS a window max. Bridges M8→DP. |
| 03 | [LC862 Shortest Subarray Sum ≥ K](03-LC862-Shortest-Subarray-Sum-At-Least-K/) | **Hard** | deque over prefix sums | The parked Phase-1 hard. Negatives kill the LC209 window. |

*(01-LC622 Design Circular Queue = optional bonus. Ring-buffer index arithmetic, low pattern value.
 Skip unless you want the rep.)*

## Promotion rule — say it plainly
- **≥2 judge-AC from the two mediums (LC1438, LC1696)** → M8 goes **L4**. That's the gate.
- The two easies are warm-up; they don't carry the gate on their own.
- LC862 is a **stretch/weekend** hard. Not required for L4. Cracking it is a separate flex.
- Kira verifies via LeetCode recent-AC. No AC, no level. (See 2026-07-08.)

## Standing rules for every problem here
1. **Gate A** — restate in one sentence *in exact units*, + a 3-element dry run. Before code.
2. **Kryptonite pre-load** — this is a deque topic, so pre-commit out loud:
   - *"the deque holds **indices**, not values"* (expiry is a POSITION question)
   - *"the front is the answer; the back is where dominated candidates die"*
   - *"any accumulator / prefix sum sized for magnitude?"* ← fired 7/06, still 🔴
3. **Brute first, always.** It's the stress-test oracle. No brute → no oracle → no proof.
4. **Gate C before submit** — empty / size-1 / first-last / the ANSWER edge (none-exists,
   whole-thing, do-nothing) + magnitude.
5. **You build the hostile input.** Name the nastiest breaker yourself before submitting.
6. **Predict-before-reveal** — before running the stress test, call which edge breaks.

## Owed
Submit by **2026-07-09**. Report the ACs; Kira pulls the judge to confirm.
