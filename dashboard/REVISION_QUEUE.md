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
| ~~2026-09-30~~ → next block | **LC347 bucket version** — re-derive cold: count ≤ n ⇒ count is the INDEX; walk buckets from n down | card | +1d | slid (he skipped into LC128) |

## Ladder — active items (starts with the first v2 AC)
| Problem / cue | Topic | Last pass | Next due | Stage |
|---|---|---|---|---|
| **LC49 Group Anagrams** — canonical key, built not given | 01 hashing | 2026-09-28 (+1d card ✅) | 2026-10-04 | +7d next |
| **LC347 Top K Frequent** — count, then a 2nd structure on the counts | 01 hashing | 2026-09-29 (+1d card ✅; bucket O(n) AC) | 2026-10-05 | +7d next |
| **LC347 bucket** — count as index, walk down | 01 hashing | 2026-09-29 (AC) | **2026-09-30** | +1d |
| LC347 — cold re-solve from a blank file | 01 hashing | — | 2026-10-05 | +7d |
| LC347 — card | 01 hashing | — | 2026-10-28 | +30d |
| LC347 — card | 01 hashing | — | 2026-12-27 | +90d |
| LC49 — cold re-solve from a blank file | 01 hashing | — | 2026-10-04 | +7d |
| LC49 — card (trigger + idea + complexity-with-the-line) | 01 hashing | — | 2026-10-27 | +30d |
| LC49 — card | 01 hashing | — | 2026-12-26 | +90d |

## Carried-over debts from v1 — settled by the Tier-0 checkpoints, ONE topic at a time (never as a batch)
| Topic | Debt (what must be shown cold) | Source |
|---|---|---|
| 00 | **M#13:** 3 consecutive bounds that survive "which line produces each factor?" · M1 stays frozen at L2\* until then | 8/10 |
| all | **M#12:** the 4-question disqualifier gate stated *unprompted* on a mixed question whose neighbour used a different tool | 8/10 |
| 01 | #9 unsorted-pair → hashing on first instinct (held 7/24 + 8/09) — one more cold confirmation | 6/13 |
| 02 | LC75 Dutch flag re-code · LC42 Trapping (hard) · **Q7 boats MISS** → sort + converging pointers rebuilt cold | 6/09 · 8/10 |
| 03 | LC1004 fresh submit (#2 re-test) · derive-don't-maintain audit aloud · LC76 / LC992 (hards) | 6/25 |
| 04 | P19 prefix-MOD re-derive (#12 reduction trap) · difference array (new) · **Q6:** prefix+hash never surfaced on a count-subarrays statement | 6/21 · 8/10 |
| 05 | LC74 2-D · LC852 / LC540 discard-ability · #8 overflow rule cold · **Q2:** search-on-answer machinery (feasibility check, `lo` bound, the ×n factor) | 6/12 · 8/09 |
| 07 | **Q3 monotonic stack MISS (real decay)** → rebuild NGE cold from the O(n²) brute · LC901 stock span · LC84 (hard) · #10 restate discipline | 8/09 |
| 08 | practice claim unverified — name the ACs or grind ≥2 of LC622/1438/1696 · **Q9:** two-deque half absent (built a multiset) | 7/08 · 8/10 |
| 09 | **Q5:** memo never mentioned — memo two-lines + sentinel cold · call-tree magnitude | 8/10 |
| 10 | LC46 cold re-derive (loop frame, no video) · LC90 loop-frame WHY · LC131 next · **Q8 keypad tap-out** despite naming the trigger | 7/16 · 8/10 |
| — | M#9 / M#10 local-oracle re-tests: **closed as moot** (LC-verdict-only workflow; v2 D7 — noted in MISTAKES.md) | 7/15 |

## Completed (v2 log)
| Date | Item | Result | Next |
|---|---|---|---|
| 2026-09-28 | LC49 +1d card | ✅ cold, unaided | +7d re-solve 10-04 |
