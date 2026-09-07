# DRILL 1  —  Problem 8   [easy]

## Statement (disguised — recognize BEFORE you peek at LINKS.md)
Versions 1..n; from some version onward everything is bad and stays bad. Given an isBad(v) oracle, find the FIRST bad version in the fewest checks.

- **Example:** n=5, first bad=4  ->  4
- **Constraints:** 1 <= n <= 2^31-1

> Fill this TOP-DOWN. Do NOT open LINKS.md or solution.cpp's signature until step 4 is written.

## 1. Restate (one sentence, my own words)
- its just saying us to find the best possible min bad point 

## 2. Constraints -> target complexity
- n bound / value range: 2^31
- target Big-O (and WHY): since constraint is too high we should actually do it in O(logn)

## 3. Pattern guess (FIRST instinct — run the gates aloud)
- sorted / monotonic? -> monotonic
- unsorted pair / duplicate? -> no
- negatives or +-1 transform? -> +ve
- **My pattern:** Binary search

## 4. Brute force
- Idea: just check in a loop where the bad starts happening from first till end and record min
- Time / Space: O(n*TC(api))
- (medium/hard: code it & submit it before optimizing)

## 5. Bottleneck (where brute wastes work)
- checking all api calls

## 6. Optimal
- Pattern that kills the bottleneck: Binary search
- Why it works: it takes best possible steps to reach solution in monotonic pattern
- Time / Space: O(logn)

## 7. Compare & extract the CUE
- brute vs optimal (time/space):
- **Cue — surface features that map this kind of problem -> this pattern:**

## 8. Bugs hit (copy recurring ones to ../../MISTAKE_JOURNAL.md)
-

## Result (fill after AC)
- pattern correct on FIRST instinct?  | restated right first try?  | brute done?  | AC on judge?
