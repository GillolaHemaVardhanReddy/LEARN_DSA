# DRILL 1  —  Problem 3   [easy]

## Statement (disguised — recognize BEFORE you peek at LINKS.md)
Given a non-negative integer x, return the integer (floor) square root, WITHOUT any built-in sqrt.

- **Example:** x=8  ->  2
- **Constraints:** 0 <= x <= 2^31-1

> Fill this TOP-DOWN. Do NOT open LINKS.md or solution.cpp's signature until step 4 is written.

## 1. Restate (one sentence, my own words)
- asked to return floor value of the square root of given number

## 2. Constraints -> target complexity
- n bound / value range:
- target Big-O (and WHY): O(n)

## 3. Pattern guess (FIRST instinct — run the gates aloud)
- sorted / monotonic? -> monotonic
- unsorted pair / duplicate? -> none
- negatives or +-1 transform? -> +ve only always
- **My pattern:** binary search

## 4. Brute force
- Idea: x = sqrt(n) so simply x^2 = n find the x that is nearest min of n
- Time / Space: O(sqrt(n)) / O(1)
- (medium/hard: code it & submit it before optimizing)

## 5. Bottleneck (where brute wastes work) we check all range
- x is 2^31 max almost 10^6 so we can do in O(n) 

## 6. Optimal
- Pattern that kills the bottleneck: Binary search
- Why it works: it jumps directly to the side it is correct and skips one whole half
- Time / Space: O(logn)

## 7. Compare & extract the CUE
- brute vs optimal (time/space):
- **Cue — surface features that map this kind of problem -> this pattern:**

## 8. Bugs hit (copy recurring ones to ../../MISTAKE_JOURNAL.md)
-

## Result (fill after AC)
- pattern correct on FIRST instinct?  | restated right first try?  | brute done?  | AC on judge?
