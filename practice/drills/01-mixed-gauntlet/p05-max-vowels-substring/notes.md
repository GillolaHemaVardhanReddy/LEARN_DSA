# DRILL 1  —  Problem 5   [easy]

## Statement (disguised — recognize BEFORE you peek at LINKS.md)
Given a string and integer k, find the maximum number of vowels in any contiguous substring of length k.

- **Example:** s="abciiidef", k=3  ->  3
- **Constraints:** 1 <= k <= len <= 1e5

> Fill this TOP-DOWN. Do NOT open LINKS.md or solution.cpp's signature until step 4 is written.

## 1. Restate (one sentence, my own words)
- we are asked to find max no of ovels in all substrings of given string with size k

## 2. Constraints -> target complexity
- n bound / value range: 10^5 
- target Big-O (and WHY):O(n) because if done n^2 it becomes 10^10 which exceeds 10^8 operations per sec

## 3. Pattern guess (FIRST instinct — run the gates aloud)
- sorted / monotonic? -> none
- unsorted pair / duplicate? -> maybe
- negatives or +-1 transform? -> no
- **My pattern:**

## 4. Brute force
- Idea: double loop and check the substrings with a hashmap of ovels
- Time / Space: O(n^2)
- (medium/hard: code it & submit it before optimizing)

## 5. Bottleneck (where brute wastes work)
-

## 6. Optimal
- Pattern that kills the bottleneck: fixed sliding window + hash map
- Why it works: because its fixed window and uses subarrays 
- Time / Space: O(n)

## 7. Compare & extract the CUE
- brute vs optimal (time/space):
- **Cue — surface features that map this kind of problem -> this pattern:**

## 8. Bugs hit (copy recurring ones to ../../MISTAKE_JOURNAL.md)
-

## Result (fill after AC)
- pattern correct on FIRST instinct?  | restated right first try?  | brute done?  | AC on judge?
