# DRILL 1  —  Problem 13   [medium]

## Statement (disguised — recognize BEFORE you peek at LINKS.md)
Given a string of uppercase letters and integer k, replace AT MOST k characters with any letter to maximize a run of one repeated letter. Return that length.

- **Example:** s="AABABBA", k=1  ->  4
- **Constraints:** 1 <= len <= 1e5

> Fill this TOP-DOWN. Do NOT open LINKS.md or solution.cpp's signature until step 4 is written.

## 1. Restate (one sentence, my own words)
- we just have to find at max k char different between most frequency char and return that length

## 2. Constraints -> target complexity
- n bound / value range: 10^5 
- target Big-O (and WHY): meaning we need O(n) solution

## 3. Pattern guess (FIRST instinct — run the gates aloud)
- sorted / monotonic? -> no
- unsorted pair / duplicate? -> no
- negatives or +-1 transform? -> no
- **My pattern:** variable sliding window and shrink while

## 4. Brute force
- Idea: double loop to get all sub strings and check if k replacements gives high max
- Time / Space: O(n^2)
- (medium/hard: code it & submit it before optimizing)

## 5. Bottleneck (where brute wastes work)
- scanning all in inner loop repeatedly wont help us

## 6. Optimal
- Pattern that kills the bottleneck: variable sliding window and shrink while
- Why it works: because it helps remove inner loop multiple repeated scans 
- Time / Space: O(n)

## 7. Compare & extract the CUE
- brute vs optimal (time/space):
- **Cue — surface features that map this kind of problem -> this pattern:**

## 8. Bugs hit (copy recurring ones to ../../MISTAKE_JOURNAL.md)
-

## Result (fill after AC)
- pattern correct on FIRST instinct?  | restated right first try?  | brute done?  | AC on judge?
