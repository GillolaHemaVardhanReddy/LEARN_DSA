# CHECKPOINT — topic 01 Hashing · 2026-10-10 (Sat AM, 2 blocks)
> The "combined reps round" promised in README. TEST mode: 0 hints (a hint costs signal and is logged).
> A statement clarification is allowed and not scored. Marks only during the run; full reveal after.
> Bar: 3/3 = pass → L4 evidence, topic 01 enters the ladder (+14d/+45d/+90d), topic 02 Two Pointers opens.

## Q0 — derive (re-entry question, Tier 0)
1. What bottleneck does hashing kill? (what were you paying before the hash table existed)
2. What does hashing reduce to — finish: "a hash table reduces ___ to ___"
3. One place it runs in the world.

## Q1 — the combined round: 6 disguised statements, shuffled, NO labels, cold
For EACH of the 6: (a) the 4 disqualifier answers, (b) the tool + the trigger (the words in the
statement that forced it), (c) the core idea in ONE line.
*(Statements S1–S6 handed over in chat.)*

## Q2 — template from memory (10 min)
## Q3 — one unseen medium, coded cold, LC verdict, 0 hints, 45 min box
## +2 cards from older topics (one adjacent-family trap)

---
## MARKS
**Run 2026-10-10, Sat AM, 2 blocks. VERDICT: 1 of 3 — NOT PASSED.** Topic 01 stays L4*; topic 02 stays shut.
Statements were his own six rungs disguised: S1=LC560 · S2=LC49 · S3=LC454 · S4=LC128 · S5=LC205 · S6=LC347.

### Q0 — PARTIAL
- Bottleneck named as "repeated work in an inner loop ... operation is for loop, *n" = the **symptom**, not the operation.
  The operation hashing kills is **search** ("is x here / how many x"), O(n) scan → one step. n²→n is the consequence.
- ✅ "reduces n² to n by adding space complexity" — right shape AND named the space trade unprompted.
- #3 (where it runs in the world) never answered, even after the question was clarified.

### Q1 — FAIL on the gate · PASS on recognition
**Recognition 6/6** from disguised, shuffled, unlabelled statements. Extras that were his own:
S1 "−ve's involved" (= exactly why sliding window dies there) · S5 "2 ways" (= two maps, the bijection) ·
S4 "what to skip" (= the run-head rule) · S3 "2 sum" (= the a+b = −(c+d) split instinct).
Imprecisions: S2 named the *problem* ("anagrams"), never the **tool** (canonical key + group by key).
S3 said "almost n²" — it is **n⁴ → n²**. Never said the map value is a COUNT.

**Gate run on 3 of 6 (S1, S3, S6) = 7/12.** Not run on S2/S4/S5 (clock).
| | contiguous? | sorted/may I sort? | order or membership? | count/best/list-all? |
|---|---|---|---|---|
| S1 (LC560) | ✅ contiguous | 🟡 "no need to sort" — truth is **may NOT** sort, contiguity depends on original order | 🔴 "have I seen this is enough" → that is the SET answer; `[0,0,0]` k=0 gives 3, answer is 6 | 🔴 "list all" — the statement says **Count how many** |
| S3 (LC454) | ✅ not contiguous | ✅ no need | 🔴 "membership" → needs **how many pairs**; `[1,1],[-1,-1],[0,0],[0,0]` = 16, not 1 | ✅ count |
| S6 (LC347) | ✅ not contiguous | 🔴 **"needs sorting"** against a bolded *"Hard requirement: beat sorting everything"* — constraint dropped twice (also in (b)); the bucket O(n) he derived unaided 09-29 and cold re-solved 10-05 never surfaced | 🔴 "membership" → the whole problem is **counting visits** | ✅ list all |

### Q2 — FAIL (template from memory)
Attempt 1: `ans += map_check[pref[j] - k]` **"if pref[j]-k is present"** → ✅✅ the load-bearing line, cold,
with the guard FIRST and unprompted (V#2 cold hold #2 · CPP_GAPS #16 re-test condition MET).
Attempt 2 (asked to finish it): *"for loop to fill pref array with running sum ... now another loop to find"*
→ 🔴 **TWO LOOPS — 3rd occurrence** (10-03 traced `[0,0,0]`→12, 10-09 re-grew, 10-10 from memory).
🔴 The **insert line was never written at all**, in either attempt — `map_check` appeared only on the lookup side.
🔴 No `m[0] = 1` seed ⇒ every stretch starting at index 0 is missed.
⇒ The invariant he derived himself on 10-03 (*the map holds only the past ⇒ look up BEFORE insert*) was gone at 24 h.

### Q3 — PASS, clean. LC187 Repeated DNA Sequences, unseen, cold, 0 hints
Judge: **TLE id ts 1791634248 → Accepted ts 1791634350**, 102 s apart — he diagnosed and fixed his own TLE.
Budget line up front and correct ("O(n²) so it will surely be TLE"). **The optimal fell out of writing the brute**
("when i tried solving brute i came up with this hashing") — 3rd time the brute→optimal pipeline self-produced the
answer (LC49, LC560, LC187).
✅ `check[x]++` — value is a **count** (V#2 held). ✅ `if(v > 1)` over the map ⇒ `"AAAAAAAAAAAAA"` emits once, not
4× — **the ANSWER edge of this problem**, right by construction. ✅ `for(auto& [k,v] : check)` — map iteration
fluent (CPP_GAPS #12, new to him on 10-03). ✅ `[]`-insert used *correctly* for counting (discriminated from the
#16 `[]`-read case). ❌ Skipped "build the hostile input BEFORE submit" — submitted, took the TLE, then fixed.
**Closing sentence — needed help:** named the capping line (`else if(x.length()>10) break;`) ✅ unaided, but could
not price one trip. Dodged the pricing by proposing `substr` instead (same 10 chars, not cheaper — told plainly).
**CPP_GAPS #18 supplied by Kira:** an `unordered_map<string,int>` hashes the key by **reading every character**;
an `int` key is one step. Then gave `10⁵×10×10 = 10⁷` — ✅ multiplied not added, every factor on real work, but a
**10× over-count**: line 7 sits inside `if(x.length()==10)` so it runs **once** per i, not 10×. Line-numbers
protocol FAILED here ("yes soo what?") → **switched modality to a filled trace table** (`"AAAAAAAAAAAAA"`, i=0)
→ he got it: *"line 7 executes only when x has 10 char."* True total ≈ **2×10⁶**.
Felt difficulty: **3 / 5**.

### +2 old-topic cards — NOT RUN (clock went to Q1/Q3). Carried to the 10-13 re-test.

### RE-TEST — moved EARLIER than the rule's default, on purpose
Rule: 2/3 ⇒ re-test the failed Q next Friday, no new topic until it passes. Letter of 1/3 = reopen with a Day 1 —
**explicitly not applied**, and said so to his face: 7 hashing ACs + an unseen medium cold + 6/6 recognition say
the topic is in him; what failed is the **gate as a reflex** and **one template's insert-order invariant**.
Default Friday 10-16 would cost 4 weekday blocks of pure revision (pace line = ~7 new blocks/wk, zero slack).
⇒ **Re-test Tue 2026-10-13:** the gate on 3 FRESH disguised statements, unprompted, three-branch Q3
+ the prefix-map template written COMPLETE (insert line + `m[0]=1` seed) + the 2 old-topic cards owed.
**Pass ⇒ topic 02 Two Pointers opens Wed 2026-10-14.** Mon 10-12's LC347 +7d repairs S6 on its own.
