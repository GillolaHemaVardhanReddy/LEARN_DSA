# 🎒 VACATION KIT — 2026-10-19 → 10-22 (Mon → Thu)

> **Phone only. Zero code. Zero LeetCode. Nothing to install, nothing to open.**
> One card a day, ~10 minutes. That is the **floor and the ceiling** — doing more is not the goal here.
> **Zero is the only failure.** Four cards = four kept days = the streak survives the vacation.
>
> **How to run a card, or it doesn't count as retrieval:**
> 1. Read the FRONT only.
> 2. Say the answer **out loud**, or type it into your notes app. Commit to it.
> 3. *Then* scroll to the BACK at the bottom and compare.
> Scrolling first turns this into reading, and reading banks nothing.

---

## 🃏 Day 1 — Mon 2026-10-19
**(This is the card owed from 10-14 — the `BusBooking` upsolve you AC'd on 10-12.)**

> A booking system is created with `n` rows. Two operations, and the problem tells you
> **total calls across both ≤ 10⁵**: one *books* a seat in some row, the other *asks* for
> the current minimum time across all rows.
>
> **Q: Why can the "ask" operation NOT be a loop over the rows — and where does the work go instead?**
> Say the rule in one sentence, then say what the booking operation has to do differently because of it.

---

## 🃏 Day 2 — Tue 2026-10-20
**(The template you rebuilt 12 minutes before the Weekly. Prove it survived the beach.)**

> *"Given an integer array — negatives allowed — and an integer k, count how many contiguous
> subarrays sum to exactly k."* `[1,2,3], k=3` → **2** · `[0,0,0], k=0` → **6** · `[1], k=0` → **0**
>
> **Q, four parts, no code — words only:**
> 1. Standing at index `i`, which value do you already HAVE, and which one do you ASK the map for?
> 2. The three lines of the loop body, **in order**.
> 3. Why that order and not the other one? Give the 1-element input that breaks it.
> 4. What is seeded before the loop starts, and what does that seeded thing MEAN?

---

## 🃏 Day 3 — Wed 2026-10-21
**(The gate. This is the half of the 10-10 checkpoint you failed — 7/12.)**

> **Part A — recite, cold:** the **zeroth** question, then the **four** disqualifier questions.
> Question 3 has **three** branches now. All three. That is the one that cost you the checkpoint.
>
> **Part B — run the whole gate on these two, out loud. Name the tool only AFTER all five answers:**
>
> **(i)** *"You're given a log of website visits as an array of user IDs, and a number k.
> Return the k users who appear most often. `n ≤ 10⁵`. Hard requirement: do better than
> sorting everything."*
>
> **(ii)** *"Given an array of integers, return the length of the longest run of consecutive
> integers that can be formed from its elements. The elements are scattered in any order.
> `n ≤ 10⁵`, and it must run in linear time."*

---

## 🃏 Day 4 — Thu 2026-10-22
**(The two that have TLE'd you repeatedly. Not the idea — the specific line that saves you.)**

> **(i)** Longest consecutive run. You have the numbers in a hash set. **What is the test that
> decides a number is allowed to START a walk** — and what happens to your complexity if you
> skip that test? (You have TLE'd this one **three separate times**: 06-20, 10-03, 10-08.)
>
> **(ii)** Top-K frequent, the O(n) version — no sorting. You have a map from value → count.
> **What is the one fact about `count` that lets you use it as an array INDEX**, and which
> direction do you walk the buckets?

---
---
---

# 🛑 STOP. Answer first, in your notes app. Then scroll.

---
---
---

## ✅ BACKS

**Day 1 — BusBooking.** *A getter with a call budget does not COMPUTE, it RETURNS — the setter MAINTAINS.*
Total calls ≤ 10⁵ is a budget on **calls**, not on rows: if "ask" loops the rows it costs O(rows) **per call**,
and 10⁵ calls × up to 10⁵ rows = **10¹⁰**, dead. So the minimum is kept as a maintained variable and the
**booking** operation updates it as it writes. Work moves out of the frequent read and into the write.
**reduces to** → the invariant *"state you can maintain cheaply, you never recompute."*

**Day 2 — prefix + map.**
1. You HAVE `p[i]` (you just added `nums[i]`). You ASK for `p[j-1]`. Rearrange for the **unknown**:
   **`p[j-1] = p[i] − k`** → *look up current minus k*. (`p[i] = p[j-1] + k` is true but solves for the wrong side.)
2. `p += nums[i];` → `if (m.count(p-k)) ans += m[p-k];` → `m[p]++;`
3. **Ask before record**, because the map must hold only the **PAST**. `nums=[1], k=0`: record first and you
   look up `1`, **find yourself**, return **1** — an empty subarray. Record after → absent → **0**. ✅
4. **`m[0] = 1`** — the prefix that is **itself exactly k**. On `[1,2,3], k=3`, the seed is what makes `[1,2]` count.
   `ans +=` carries the stored **count**, never a `1`.

**Day 3 — the gate.**
- **(0)** Read the constraints and say the **budget out loud in digits**. *(n ≤ 100 → stay dumb, brute it ·
  n ≤ 10³ → n² · n ≤ 10⁵ → n log n · n ≤ 10⁶ → O(n) only.)*
- **(1)** Contiguous? **(2)** Sorted / may I sort? **(3)** Do I need **order**, **membership**, or **how many times**?
  **(4)** Count, best, or list-all?
- **(i)** not contiguous · **may not sort** (the statement forbids beating-sorting's cost) · **how many times** —
  this is frequency, *not* membership · **list-all** (k of them) → counts + **bucket by count**, O(n).
  *This is the exact statement you missed twice on 10-10 — you answered "needs sorting" against a bolded "beat sorting everything".*
- **(ii)** not contiguous · order is irrelevant, so sorting is *allowed* but **n log n is forbidden** by "linear" ·
  **membership** (genuinely, this time) · **best** (a length) → hash set + walk only from run heads.
- The point of running (i) and (ii) back to back: **they are adjacent and they take different tools.** That is where
  tool-carryover (M#12) lives.

**Day 4.**
- **(i)** A number `x` may start a walk **only if `x-1` is NOT in the set** — it must be a run **head**. Without it
  you re-walk the same run from every member, and the total goes quadratic. Also: iterate **the set**, not the
  original array (duplicates re-walk). That pair of lines is the whole O(n).
- **(ii)** **A count can never exceed `n`**, the array length — so a count is a legal **array index**. Make `n+1`
  buckets, drop each value into `bucket[count]`, and walk **from `n` downward**, taking until you have k.

---

## 🧭 The one line for 10-23 (Fri — first block back)

**RE-TEST PART 2a: LC930 Binary Subarrays With Sum**, cold, **plain words, no costumes**. Part 1 ran on 10-13 and
tapped out clean — but that tap-out is logged as **V#5, Kira's fault**: the statement was dressed up as a "sensor
log" with "clickers" and "stretches", and the costume buried an idea you already own. Five days later, in plain
array vocabulary, you rebuilt the whole template in 12 minutes on one nudge.

**So Day 2's card is literally part 2a, minus the judge.** Day 3's gate is part of 2b. Four 10-minute cards on a
vacation is not busywork — it is you walking into that test **warm** instead of cold after ten days off.

Zero is the only failure. Day 66 = **2026-12-01**.
