# DRILL 1  —  Problem 1   [easy]   ★ WORKED EXAMPLE (this is how a filled notes.md looks)

## Statement (disguised — recognize BEFORE you peek at LINKS.md)
Given an array of integers and a target value, return the indices of the two numbers that add up to the target. The array is NOT sorted. Exactly one valid answer exists.

- **Example:** nums=[2,7,11,15], target=9  ->  [0,1]
- **Constraints:** n <= 1e4, values can be ±1e9

> Fill this TOP-DOWN. Do NOT open LINKS.md or solution.cpp's signature until step 4 is written.

## 1. Restate (one sentence, my own words)
- Find the two positions in an unsorted array whose values sum to a given target, and return those positions.

## 2. Constraints -> target complexity
- n bound / value range: n ≤ 1e4 (length); values ±1e9 (magnitude — does NOT drive complexity).
- target Big-O (and WHY): O(n). Floor is O(n) because I must read every element at least once to know a pair exists. No O(log n) — you can't find a pair you never looked at.

## 3. Pattern guess (FIRST instinct — run the gates aloud)
- sorted / monotonic? -> NO. So two-pointers/binary-search are OFF the table.
- unsorted pair / duplicate? -> YES, a pair/complement on unsorted data.
- negatives or ±1 transform? -> n/a.
- **My pattern:** Hashing (complement map value->index). [MISTAKE I made: first instinct was sort+2ptr — wrong, sorting destroys the indices the problem asks for.]

## 4. Brute force
- Idea: check every pair (i,j), return when nums[i]+nums[j]==target.
- Time / Space: O(n^2) / O(1).
- (easy — brute is NOT optimal here, so I go straight to the optimal below.)

## 5. Bottleneck (where brute wastes work)
- The inner loop re-scans the array to find target-nums[i]. That repeated "have I seen X?" search is the waste.

## 6. Optimal
- Pattern that kills the bottleneck: hash map replaces the inner scan ("the map IS the inner loop").
- Why it works: one pass; for each x, look up target-x in O(1). Look up BEFORE inserting x (else x can match itself).
- Time / Space: O(n) / O(n).

## 7. Compare & extract the CUE
- brute vs optimal: O(n^2)/O(1)  ->  O(n)/O(n). Trade space for time; the map removes the rescans.
- **Cue:** "find a pair/complement on UNSORTED data, return indices" -> one-pass hash map. Two-pointers needs sorted AND doesn't need original indices.

## 8. Bugs hit (copy recurring ones to ../../MISTAKE_JOURNAL.md)
- Reflex: reached for sort+two-pointers first (MISTAKE #9, recurring). Fix = run the "is it sorted?" gate FIRST.
- Complexity misread: saw 1e9 value and hunted sub-linear; 1e9 is magnitude, not n.

## Result (fill after AC)
- pattern correct on FIRST instinct? NO (recovered) | restated right first try? YES | brute done? n/a (easy) | AC on judge? YES
