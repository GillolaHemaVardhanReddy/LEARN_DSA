# REVISION_QUEUE.md — the retrieval ladder (dates drive it)

> **Rules (PLAN §5, sized to the slots):** only **BUILD problems and contest upsolves** enter the ladder (≈ 6–7/week).
> Per problem: **+1d card** (the first 3 min of the next day's BUILD, same topic) → **+7d cold re-solve** (a weekend block;
> felt easy ⇒ next at +30d, felt hard ⇒ +7d again) → **+30d card** (RECALL) → **+90d card** (RECALL). Fail ⇒ back to +1d.
> Per topic: checkpoint pass → 2 mixed cards at **+14d / +45d / +90d** (a ✅ ≥ 14d after the pass, unseen statement, = L5 evidence).
> **RECALL slot = 10 min = the 2 oldest due items, always a different topic than the day's BUILD.** More due ⇒ they **slide** a day,
> never drop; backlog > 10 ⇒ collapse to one item per topic, the rest jump to their next rung marked "skipped" — written here, never silent.
> A ❌ on an L4/L5 topic ⇒ ⚠ + a +1d card; a second ❌ within 30d ⇒ the level drops one notch (regression rule, PLAN §5).
> A **card** = disguised statement (2–3 seeded examples) → the 4 disqualifier answers → pattern + trigger + idea + complexity-with-the-work.

## Due — Kira fills the RECALL slot from here (oldest first)
| Due | Item | Kind | Stage | Result |
|---|---|---|---|---|
| ~~2026-09-08~~ | ~~Comeback gauntlet Q10 → Q20~~ | test | **RETIRED 2026-09-27** — boss killed the quiz format on 09-25 ("stop asking test questions — I lost interest"); retrieval now happens by re-solving problems only | — |
| ~~2026-09-09~~ | ~~RECALL: 2 cards from gauntlet misses~~ | card | **RETIRED 2026-09-27** — same reason; there is no RECALL slot in the hour-block day | — |
| 2026-09-28 | **LC49 Group Anagrams** — re-derive the key cold, first 3 min of the next block | card | +1d | ✅ 09-28 cold, unaided |
| 2026-09-29 | **LC347 Top K Frequent** — re-derive cold: count → pairs → sort by count → take k (+ the complexity with d) | card | +1d | ✅ 09-29 cold (one precision: copy map to vector<pair>) |
| ~~2026-09-30~~ → ~~next block~~ | **LC347 bucket version** — count ≤ n ⇒ count is the INDEX; walk buckets from n down | card | +1d | ✅ **settled 2026-10-05** by the full cold re-solve (said "count can't be bigger than length of array" unprompted) |
| ~~2026-10-10~~ | **LC128 Longest Consecutive** — cold re-solve | re-solve | +1d/+7d | ✅ **pulled forward, done 2026-10-08** — run-start rule cold, but TLE first (outer loop over nums, 3rd time) → self-fixed → AC. Felt hard (tired) ⇒ **+7d again 2026-10-15** |
| 2026-10-09 | **LC560 Subarray Sum = K** — cold re-solve | re-solve | +1d/+7d | ✅ **10-09 AC** — first draft re-grew both old bugs (two loops, `count` vs `[]`); self-fixed the loop order → felt medium ⇒ **+7d 2026-10-16** |

| ~~2026-10-08~~ | **LC454 4Sum II** — cold re-solve | re-solve | +1d | ✅ **VERIFIED 2026-10-08** — file written 10-07 night on the MacBook, submitted from it on 10-08: **AC id 2166496160**. `ans += check[...]` cold, 24 h after V#2's 4th fire on that exact line ⇒ **V#2 beaten pre-warned**. One flaw: line 20 reads the map with `operator[]` (CPP_GAPS #16, 3rd fire) — he named the mechanism and the fix himself. ⇒ **+7d 2026-10-14** |
| 2026-10-09 | **LC205 Isomorphic Strings** — +1d cold re-solve | re-solve | +1d | ✅ **10-09 AC clean**, both directions, < 15 min |
| ~~2026-10-10~~ | **Combined reps round / HASHING CHECKPOINT** — all 6 shuffled, no labels, cold, one sitting | test | — | 🔴 **RAN 2026-10-10 — 1 of 3, NOT PASSED** (`tests/checkpoints/01-hashing-2026-10-10/`). Q3 PASS (LC187 unseen, cold, AC) · Q1 recognition 6/6 but gate **7/12** (→ V#4) · Q2 FAIL (two-loop template, insert line absent). **Re-test pulled to Tue 2026-10-13**; topic 02 shut until it passes |
| ~~2026-10-12~~ | **LC347 Top K Frequent** — +7d cold re-solve | re-solve | +7d | ✅ **DONE 2026-10-12 — AC** (1 bug `j++`; `sort` returns void self-caught; bucket needed 2 prompts) ⇒ next rung **2026-10-26** |
| **2026-10-13** | **THE RE-TEST** — the gate on **3 fresh disguised statements, unprompted**, three-branch question 3 · + the **prefix-map template written COMPLETE** (the insert line and the `m[0]=1` seed) · + the **2 old-topic cards owed** from 10-10 (different families, one adjacent-family trap). **Pass ⇒ topic 02 Two Pointers opens Wed 10-14** | test | — | Tue 🟡 **PART 1 RAN 10-13 — S1 (LC560 disguised) tapped out clean.** Budget ✅ · gate Q2–4 cold ✅ (Q3 "how many times" first try) · Q1 after a prompt · broke his own window by trace · recognition ✗ (Kira revealed) · `P[j]−k` didn't land. Gate handed over as HIS today (never was before). → part 2 below |
| ~~2026-10-14~~ → ~~2026-10-23~~ | **RE-TEST PART 2a — LC930** Binary Subarrays With Sum https://leetcode.com/problems/binary-subarrays-with-sum/ | test | — | 🟡 **DONE 2026-10-28 — AC.** Seed `check[0]=1` + lookup-before-insert cold (the 10-10 failure lines). Gate Q1 MISSED (subarray = contiguous, V#6) · bridge needed a table · brute WA untraced → TLE. Code `tests/checkpoints/01-hashing-2026-10-10/retest-2a-LC930.cpp` |
| 🔴 ~~2026-10-15~~ → ~~10-23/24~~ → **2026-10-29 (Thu)** | **RE-TEST PART 2b** — S2 + S3, disguised by NAME only, **plain array vocabulary** (V#5), gate unprompted (**Q1 "subarray ⇒ contiguous" is the watch — V#6**) + the 2 old-topic cards. First 3 min = LC930 +1d card. **Pass ⇒ topic 02 Two Pointers opens** | test | — | next block |
| ~~2026-10-16~~ **RETIRED 2026-10-18** | **Biweekly 193 Q1 clean brute re-solve** — its whole purpose was to be a judge-as-debugger hold, first-submit-clean. **That leak CLOSED on far better evidence: 10-12 BusBooking AC first submission, then 10-18 Weekly Q1 AND Q2 one submission each in a rated contest.** A practice rep cannot outrank a live one. Dropped as a re-test; **optional** as a plain rep if he ever wants the M#12 lesson in hand (`n ≤ 100` ⇒ the map bought nothing) | re-solve | — | **retired, not missed** |
| 🔴 ~~2026-10-17~~ → ~~10-25~~ → **2026-11-01 (Sun PM)** | **LC187 Repeated DNA Sequences** — +7d cold re-solve (felt 3/5). Missed twice, slid (10-25 no session). Carries the **CPP_GAPS #18 re-test** | re-solve | +7d | Sun PM |
| 🔴 ~~2026-10-14~~ → ~~10-24~~ → **2026-10-31 (Sat AM)** | **LC454 4Sum II** — +7d cold re-solve. Missed twice, slid (10-24 no session) | re-solve | +7d | Sat AM block 1 |
| 🔴 ~~2026-10-15~~ → ~~10-25~~ → **2026-11-01 (Sun PM)** | **LC128 Longest Consecutive** — +7d cold re-solve (3rd pass at this rung). Missed twice, slid | re-solve | +7d AGAIN | Sun PM |
| 🔴 ~~2026-10-15~~ → ~~10-26~~ → **2026-10-31 (Sat PM)** | **LC205 Isomorphic Strings** — +7d cold re-solve. Missed twice, slid (weekday blocks go to 2b) | re-solve | +7d | Sat PM |
| 🔴 ~~2026-10-26~~ → **2026-10-31 (Sat PM)** | **LC347 Top K Frequent (bucket)** — +7d cold re-solve. Missed (no session 10-26), slid | re-solve | +7d | Sat PM |
| 🔴 ~~2026-10-16~~ → ~~10-24~~ → **2026-10-31 (Sat AM)** | **LC560 Subarray Sum = K** — +7d cold re-solve, blank file, the `m[0]=1` seed included. Missed twice, slid. *(Template now confirmed on the judge via LC930 10-28)* | re-solve | +7d | Sat AM block 2 |
| ~~2026-10-12~~ | **THE ONE UPSOLVE — LC Weekly Q3 `Design Bus Seat Booking System`** | upsolve | new | ✅ **DONE 2026-10-12 — AC, FIRST SUBMISSION** (judge-as-debugger hold #2) |
| ~~2026-10-14~~ → ~~10-19 (vacation kit, optional)~~ → **2026-10-30 (Fri)** | **LC Weekly Q3 `BusBooking`** — card: *"total calls ≤ 10⁵ ⇒ the getter RETURNS, the setter MAINTAINS"* — re-state the shape cold, no code. Kit not used (it was optional) — slid | card | +1d | Fri, 10 min |

> **⚠️ CAPACITY NOTE (2026-10-07).** At **1 block/weekday** the ladder now competes with new rungs for the same hour.
> Rule from here: a **+1d re-solve runs inside the block it precedes** (first 15 min, blank file), and **+7d cold re-solves
> are weekend-only** (Sat AM block 1 takes 2 of them). Nothing is dropped; 10-06's two slid to Sat 10-10 because the
> block went to LC454. If three or more +7d items pile up, Sat AM block 1 takes the two oldest and the rest slide a week —
> written here, never silent.

## Ladder — active items (starts with the first v2 AC)
| Problem / cue | Topic | Last pass | Next due | Stage |
|---|---|---|---|---|
| **LC930 Binary Subarrays With Sum** — count slices with sum = goal ⇒ look up `total − goal`, seed `{0:1}`, look up then insert | 01 hashing | **2026-10-28 — re-test 2a ✅ AC** (gate Q1 slipped; bridge scaffolded) | **2026-10-29** +1d card (inside 2b) · **2026-11-04** +7d | +1d card |
| **LC Weekly Q3 BusBooking** (design class) — getter RETURNS, setter MAINTAINS · store the cost it was charged | design / 01 | **2026-10-12 — upsolve ✅ AC first submission** (shell + getters typed by Kira) | **10-14 card** · **2026-10-18 PM** blank-file re-solve | +7d cold re-solve |
| **LC49 Group Anagrams** — canonical key, built not given | 01 hashing | **2026-10-03 — +7d cold re-solve ✅ AC** (3rd pass; only bug = the `sort` returns void recurrence) → felt EASY | **2026-11-02** | +30d card |
| **LC347 Top K Frequent (bucket O(n))** — count as index, walk down | 01 hashing | **2026-10-12 — +7d cold re-solve ✅ AC** (1 bug, `j++`; sort self-caught; bucket needed 2 prompts) — 3 bugs → 1 | **2026-10-19** | +7d again (prompts needed ⇒ not yet easy) |
| **LC128 Longest Consecutive** — set for membership · only a run's head starts a walk | 01 hashing | **2026-10-08 cold re-solve ✅ AC** (TLE first — outer loop over nums, 3rd time; felt hard) | **2026-10-15** | **+7d AGAIN** |
| **LC560 Subarray Sum = K** — hash what you have seen so far (prefix as key) | 01 hashing | **2026-10-09 cold re-solve ✅ AC** (two-loop + `count` bugs re-grew, self-fixed) | **2026-10-16** | +7d cold re-solve |
| **LC205 Isomorphic Strings** — bijection = two maps, s→t and t→s | 01 hashing | **2026-10-08 — LEARN, AC first submit** (felt easy) | **10-09 +1d ✅** · next **2026-10-15** | +7d cold re-solve cold re-solve |
| LC205 — card | 01 hashing | — | 2026-11-07 | +30d |
| **LC454 4Sum II** — split the equation in half, hash one half, the value is a COUNT | 01 hashing | **2026-10-08 — +1d cold re-solve ✅ AC** (id 2166496160; written 10-07 night, submitted 10-08 — `ans +=` held cold) → felt clean | **2026-10-14** | +7d cold re-solve |
| LC454 — card | 01 hashing | — | 2026-11-06 | +30d |
| LC454 — card | 01 hashing | — | 2027-01-05 | +90d |
| LC49 — card | 01 hashing | — | 2026-12-26 | +90d |
| LC347 — card | 01 hashing | — | 2026-11-04 | +30d (re-anchored to the 10-05 pass) |
| LC347 — card | 01 hashing | — | 2027-01-03 | +90d |
| LC128 — card | 01 hashing | — | 2026-11-02 | +30d |
| **Biweekly 193 Q1 Maximum Product Pair** — `n ≤ 100` ⇒ **brute**; strict `>` kills the equal case for free; max product can be **NEGATIVE** (init `INT_MIN`) | contest / 01+02 | **2026-10-10 — AC in contest, but after 5 WAs and with a hash map that was never needed (M#12 live)** | **2026-10-12** | clean re-solve, brute, first-submit target |
| **LC187 Repeated DNA Sequences** — hash the 10-char window as a KEY, the value is a count; answer = walk the map and take `v > 1` (so it emits once) | 01 hashing | **2026-10-10 — checkpoint Q3, UNSEEN + COLD + 0 hints, ✅ AC** (TLE self-diagnosed and fixed in 102 s; the `break` at length > 10 is what killed the n²) → felt **3/5** | **2026-10-17** | +7d cold re-solve |
| LC187 — card | 01 hashing | — | 2026-11-09 | +30d |
| LC187 — card | 01 hashing | — | 2027-01-08 | +90d |
| LC560 — card | 01 hashing | — | 2026-11-02 | +30d |

## Carried-over debts from v1 — settled by the Tier-0 checkpoints, ONE topic at a time (never as a batch)
| Topic | Debt (what must be shown cold) | Source |
|---|---|---|
| 00 | ✅ **CLEARED 2026-10-09 (3 of 3, last = LC560)** ~~**M#13:** 3 consecutive bounds that survive "which line produces each factor?" · M1 stays frozen at L2\* until then~~ | 8/10 |
| all | **M#12:** the 4-question disqualifier gate stated *unprompted* on a mixed question whose neighbour used a different tool | 8/10 |
| 01 | #9 unsorted-pair → hashing on first instinct (held 7/24 + 8/09) — one more cold confirmation | 6/13 |
| 02 | LC75 Dutch flag re-code · LC42 Trapping (hard) · **Q7 boats MISS** → sort + converging pointers rebuilt cold | 6/09 · 8/10 |
| 03 | LC1004 fresh submit (#2 re-test) · derive-don't-maintain audit aloud · LC76 / LC992 (hards) | 6/25 |
| 04 | P19 prefix-MOD re-derive (#12 reduction trap) · difference array (new) · ~~**Q6:** prefix+hash never surfaced~~ → **PAID 2026-10-03** (LC560 derived from scratch + AC) | 6/21 · 8/10 |
| 05 | LC74 2-D · LC852 / LC540 discard-ability · #8 overflow rule cold · **Q2:** search-on-answer machinery (feasibility check, `lo` bound, the ×n factor) | 6/12 · 8/09 |
| 07 | **Q3 monotonic stack MISS (real decay)** → rebuild NGE cold from the O(n²) brute · LC901 stock span · LC84 (hard) · #10 restate discipline | 8/09 |
| 08 | practice claim unverified — name the ACs or grind ≥2 of LC622/1438/1696 · **Q9:** two-deque half absent (built a multiset) | 7/08 · 8/10 |
| 09 | **Q5:** memo never mentioned — memo two-lines + sentinel cold · call-tree magnitude | 8/10 |
| 10 | LC46 cold re-derive (loop frame, no video) · LC90 loop-frame WHY · LC131 next · **Q8 keypad tap-out** despite naming the trigger | 7/16 · 8/10 |
| — | M#9 / M#10 local-oracle re-tests: **closed as moot** (LC-verdict-only workflow; v2 D7 — noted in MISTAKES.md) | 7/15 |

## Completed (v2 log)
| Date | Item | Result | Next |
|---|---|---|---|
| 2026-10-12 | **LC Weekly 10-11 Q3 BusBooking — THE UPSOLVE** | ✅ **AC first submission** — design decisions his; Kira wrote the class shell + getters (over the ≤1-hint rule, logged) | card 10-14 · blank-file re-solve 10-18 PM |
| 2026-10-12 | LC347 bucket +7d cold re-solve | ✅ AC — 1 bug (`j++`), sort self-caught | +7d 2026-10-19 |
| 2026-10-10 | **LC Biweekly 193 — PLAYED LIVE** (v2 contest #1, joined ~15 min late) | **1/4** — Q1 AC after **5 WAs**, ~20–25 min. Q2 triaged out in ~5 min (**correctly** — unopened number theory); Q3 = the same problem as Q2; Q4 = trees. **3 of 4 problems off-map.** | **No upsolve** (all unsolved are off-map; the weekend's one upsolve is held for the 10-11 Weekly). Q1 → clean brute re-solve **2026-10-12** |
| 2026-10-10 | Biweekly 193 Q2/Q3 ("Longest Resilient Subarray I/II") · Q4 (trees) | **"not yet" — UNOPENED TOPICS.** No card, never a recognition miss, no debt. Q2/Q3 need modular-divisibility number theory (off the Tier-0 map entirely); Q4 needs trees (Tier 1) | revisit when those topics open |
| 2026-10-10 | **THE HASHING CHECKPOINT** (the combined reps round) | 🔴 **1 of 3 — NOT PASSED.** Q3 ✅ LC187 unseen medium cold AC · Q1 recognition 6/6 / gate 7/12 ✗ · Q2 ✗ two-loop template | **re-test Tue 2026-10-13**; topic 02 shut |
| 2026-10-10 | LC187 Repeated DNA Sequences (checkpoint Q3) | ✅ **AC** ts 1791634350 after TLE ts 1791634248 — unseen, cold, 0 hints | +7d 2026-10-17 |
| 2026-10-09 | LC560 cold re-solve | ✅ AC (self-fixed loop order) | +7d 2026-10-16 |
| 2026-10-09 | LC205 +1d cold re-solve | ✅ AC clean | +7d 2026-10-15 |
| 2026-10-08 | **LC454 +1d cold re-solve** (written 10-07 night, submitted 10-08) | ✅ **AC id 2166496160** — `ans += check[...]` cold, V#2 beaten pre-warned; one flaw = `operator[]` read (#16, 3rd fire) | +7d, 2026-10-14 |
| 2026-10-08 | LC128 cold re-solve (pulled from Sat) | ✅ AC — TLE first (outer loop over nums, 3rd time), self-fixed; felt hard | +7d again, 2026-10-15 |
| 2026-10-05 | LC347 bucket +7d cold re-solve | ✅ AC — but felt HARD (3 bugs) | +7d again, 2026-10-12 |
| 2026-10-03 | LC49 +7d cold re-solve (3rd pass) | ✅ AC — key + both tools named unprompted | +30d card, 2026-11-02 |
| 2026-09-29 | LC347 +1d card | ✅ cold (one precision: copy map to `vector<pair>`) | — |
| 2026-09-28 | LC49 +1d card | ✅ cold, unaided | +7d re-solve → done 10-03 |
