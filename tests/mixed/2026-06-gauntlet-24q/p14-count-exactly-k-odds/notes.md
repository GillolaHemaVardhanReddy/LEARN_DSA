# DRILL 1  —  Problem 14   [medium]

## Statement (disguised — recognize BEFORE you peek at LINKS.md)
COUNT the contiguous subarrays that contain EXACTLY k odd numbers.

- **Example:** nums=[1,1,2,1,1], k=3  ->  2
- **Constraints:** 1 <= n <= 5e4

> Fill this TOP-DOWN. Do NOT open LINKS.md or solution.cpp's signature until step 4 is written.

## 1. Restate (one sentence, my own words)
- we need to find the sub arrays count that have k = 3 odd numbers 

## 2. Constraints -> target complexity
- n bound / value range: 10^4
- target Big-O (and WHY): since its 10^4 we need a O(n) solution

## 3. Pattern guess (FIRST instinct — run the gates aloud)
- sorted / monotonic? -> no
- unsorted pair / duplicate? -> unsorted
- negatives or +-1 transform? -> +ve
- **My pattern:** variable sliding window with shrinking while

## 4. Brute force
- Idea: just keep double loop to look up all sub arrays with exactly k odd numbers
- Time / Space: O(n^2)
- (medium/hard: code it & submit it before optimizing)

## 5. Bottleneck (where brute wastes work)
- here we look up all sub arrays for each fixed element

## 6. Optimal
- Pattern that kills the bottleneck: variable sliding window 
- Why it works: it walks through all sub arrays with one loop and removes over lookup
- Time / Space: O(n)

## 7. Compare & extract the CUE
- brute vs optimal (time/space):
- **Cue — surface features that map this kind of problem -> this pattern:**

## 8. Bugs hit (copy recurring ones to ../../MISTAKE_JOURNAL.md)
-

## Result (fill after AC)
- pattern correct on FIRST instinct?  | restated right first try?  | brute done?  | AC on judge?
