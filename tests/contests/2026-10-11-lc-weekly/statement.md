# LC Weekly 2026-10-11 — Q3 · BusBooking (design)

**LC link:** https://leetcode.com/problems/design-bus-seat-booking-system/

**THE ONE UPSOLVE for the weekend of 2026-10-11.** Due within 48 h (target: Sun 10-11 PM block).
Kira coaches at **≤ 1 hint**. The class *syntax* is a told library fact (CPP_GAPS #19). Every
design decision is yours.

---

## Statement

Design a seat booking system for a bus.

The bus has `n` rows. Each row has four seats labeled `"A"`, `"B"`, `"C"`, `"D"`.

Seats `"A"` and `"D"` are **window** seats; seats `"B"` and `"C"` are **middle** seats.
In each row, seat `A` is adjacent to seat `B`, and seat `D` is adjacent to seat `C`.

**Booking rules**
- Booking a middle seat (`B` or `C`) always takes **1 second**.
- Booking a window seat (`A` or `D`) takes **1 second** if its adjacent middle seat is **not** booked,
  or **3 seconds** (an extra delay of 2) if its adjacent middle seat **is already booked**.

A seat is identified by a string such as `"A1"` or `"D20"` — one letter `A`–`D` followed by its row number.

**Implement the `BusBooking` class**
- `BusBooking(int n)` — initialize the system with `n` empty rows.
- `void toggle(string seat)` — book `seat` if it is free, or free it if it is already booked.
- `int getTotalTime()` — the total time (seconds) to book all **currently booked** seats, where the seats
  are booked **in the order their `toggle` calls were made**. If no seats are currently booked, return `0`.
- `int getMinTime()` — the **smallest possible** total time to book all currently booked seats, over
  **every possible order** of booking them. If no seats are currently booked, return `0`.

> **Note:** the time cost of a seat is **fixed at the moment it is booked**, based on the seats booked at
> that time. Booking or freeing other seats afterward does **not** change the cost of a seat already booked.

### Example 1
```
Input:
["BusBooking","toggle","toggle","getTotalTime","getMinTime","toggle","toggle","getTotalTime","getMinTime"]
[[20],["B3"],["A3"],[],[],["C3"],["D3"],[],[]]

Output:
[null,null,null,4,2,null,null,8,4]
```
- `toggle("B3")` — middle, costs 1. Total = 1.
- `toggle("A3")` — window, adjacent `B3` already booked ⇒ costs 3. Total = 1 + 3 = 4.
- `getTotalTime()` → **4** (in toggle order: 1, 3).
- `getMinTime()` → **2**. Booking `A3` *before* `B3` avoids the delay ⇒ 2 seats, 2 seconds.
- `toggle("C3")` — middle, costs 1. Total = 5.
- `toggle("D3")` — window, adjacent `C3` booked ⇒ costs 3. Total = 8.
- `getTotalTime()` → **8** (costs were 1, 3, 1, 3).
- `getMinTime()` → **4**. Best order adds no delay ⇒ 4 × 1 = 4.

### Example 2
```
Input:
["BusBooking","toggle","toggle","getTotalTime","toggle","toggle","toggle","getTotalTime","getMinTime"]
[[10],["C7"],["D7"],[],["D7"],["C7"],["D7"],[],[]]

Output:
[null,null,null,4,null,null,null,1,1]
```
- `toggle("C7")` — middle, 1. Total = 1.
- `toggle("D7")` — window, `C7` booked ⇒ 3. Total = 4.
- `getTotalTime()` → **4**.
- `toggle("D7")` — already booked ⇒ **free it**, removes its cost of 3. Total = 1.
- `toggle("C7")` — already booked ⇒ **free it**, removes its cost of 1. Total = 0; row 7 empty.
- `toggle("D7")` — book again; `C7` is **not** booked this time ⇒ costs only 1. Total = 1.
- `getTotalTime()` → **1**.
- `getMinTime()` → **1**.

### Constraints
```
1 <= n <= 10^5
seat[0] is one of 'A','B','C','D'
the remaining characters of seat form an integer row with 1 <= row <= n
total number of calls to toggle, getTotalTime and getMinTime  <=  10^5
```

---

## Gate A — run it before you name a single container (write your answers in `gate.md`)

0. **BUDGET, in digits.** Calls ≤ 10^5. What is the per-call budget, and what does that forbid?
1. Restate the problem in **exact units** — what is a "second" attached to? What object owns a cost?
2. **3-element dry run** — do Example 1 by hand, writing the cost of each seat as it is booked.
3. The four disqualifiers: contiguous? · sorted / may I sort? · **order · membership · or how many times?** · count / best / list-all?

## Gate C — before you submit
- The **ANSWER edge** is written into the statement: *"If no seats are currently booked, return 0."* Trace it.
- The **double toggle** (Example 2) — book, free, re-book. Does your bookkeeping survive it?
- `n = 1`. A row with all four seats booked. A window booked before its middle, and after.
- Magnitude: 10^5 calls × 3 seconds — does the total fit in an `int`?
