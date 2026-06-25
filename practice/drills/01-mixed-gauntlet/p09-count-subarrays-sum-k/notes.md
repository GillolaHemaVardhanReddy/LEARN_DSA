# DRILL 1  —  Problem 9   [medium]

## Statement (disguised — recognize BEFORE you peek at LINKS.md)
Given an integer array (values may be NEGATIVE) and integer k, COUNT contiguous subarrays summing to exactly k.

- **Example:** nums=[1,1,1], k=2  ->  2
- **Constraints:** 1 <= n <= 2e4, -1000 <= nums[i] <= 1000

> Fill this TOP-DOWN. Do NOT open LINKS.md or solution.cpp's signature until step 4 is written.

## 1. Restate (one sentence, my own words)
- they are asking us to get count of sub arrays who have sum = k 

## 2. Constraints -> target complexity
- n bound / value range: 10^4
- target Big-O (and WHY): it needs to be O(n)

## 3. Pattern guess (FIRST instinct — run the gates aloud)
- sorted / monotonic? -> no
- unsorted pair / duplicate? -> unsorted
- negatives or +-1 transform? -> -ves also
- **My pattern:** prefix sum + hash map

## 4. Brute force
- Idea: just double loop and run for ever item mapped to next all items
- Time / Space: O(n^2)
- (medium/hard: code it & submit it before optimizing)

## 5. Bottleneck (where brute wastes work)
- need to search and sum repetatively for all

## 6. Optimal
- Pattern that kills the bottleneck:prefix sum + hash map
- Why it works: it removed the inner loop 
- Time / Space: O(n)

## 7. Compare & extract the CUE
- brute vs optimal (time/space):
- **Cue — surface features that map this kind of problem -> this pattern:**

## 8. Bugs hit (copy recurring ones to ../../MISTAKE_JOURNAL.md)
-

## Result (fill after AC)
- pattern correct on FIRST instinct?  | restated right first try?  | brute done?  | AC on judge?
