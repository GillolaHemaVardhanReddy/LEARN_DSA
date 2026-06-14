# DRILL 1  —  Problem 11   [medium]

## Statement (disguised — recognize BEFORE you peek at LINKS.md)
A SORTED array was rotated at an unknown pivot. Find a target's index in O(log n), or -1.

- **Example:** [4,5,6,7,0,1,2], target=0  ->  4
- **Constraints:** 1 <= n <= 5000, distinct

> Fill this TOP-DOWN. Do NOT open LINKS.md or solution.cpp's signature until step 4 is written.

## 1. Restate (one sentence, my own words)
- just need to find the element's index

## 2. Constraints -> target complexity
- n bound / value range: 5000
- target Big-O (and WHY): can go upto O(n^2)

## 3. Pattern guess (FIRST instinct — run the gates aloud)
- sorted / monotonic? -> yes
- unsorted pair / duplicate? -> no
- negatives or +-1 transform? -> never mentioned
- **My pattern:** Binary search

## 4. Brute force
- Idea: keep a loop searching for the target and return index
- Time / Space: O(n)
- (medium/hard: code it & submit it before optimizing)

## 5. Bottleneck (where brute wastes work)
-

## 6. Optimal
- Pattern that kills the bottleneck: binary search
- Why it works: doesnt scan whole array finds best possible instinct
- Time / Space:O(n)

## 7. Compare & extract the CUE
- brute vs optimal (time/space):
- **Cue — surface features that map this kind of problem -> this pattern:**

## 8. Bugs hit (copy recurring ones to ../../MISTAKE_JOURNAL.md)
-

## Result (fill after AC)
- pattern correct on FIRST instinct?  | restated right first try?  | brute done?  | AC on judge?
