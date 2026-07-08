# LC2073 — Time Needed to Buy Tickets  ·  EASY  ·  M8 Queues

https://leetcode.com/problems/time-needed-to-buy-tickets/

`n` people in a line, person `0` at the front. Person `i` wants to buy `tickets[i]` tickets.
Buying **one** ticket takes exactly 1 second, after which that person goes to the **back** of the
line (instantly) if they still want more. A person with 0 tickets left **leaves the line**.

Return the time taken for the person **initially** at position `k` to finish buying.

## Constraints
- `n == tickets.length`, `1 <= n <= 100`
- `1 <= tickets[i] <= 100`
- `0 <= k < n`

## Examples
```
tickets = [2,3,2], k = 2   ->  6
tickets = [5,1,1,1], k = 0 ->  8
```

## Gate A — before you code
Restate in one sentence, **in exact units** (what is being returned — a count of people? a
count of seconds? a position?). Then dry-run `[2,3,2], k=2` and write the queue state each second.

⚠️ The trap: `k` names a person by their **starting position**. As the line rotates, that person
moves. Restating "the person at index k" instead of "the person who *started* at index k" is the
same reading miss as LC739 (position vs distance). Say it right.

## The bridge
The simulation is O(total tickets). The real answer is O(n) and needs no queue at all.

> Forget the line. Ask: **before person k finishes, how many tickets does person `i` get to buy?**

Answer that for `i < k`, `i == k`, and `i > k`. Two of the three collapse into one formula.
