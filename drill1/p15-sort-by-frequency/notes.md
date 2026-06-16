# DRILL 1  —  Problem 15   [medium]

## Statement (disguised — recognize BEFORE you peek at LINKS.md)
Sort a string's characters in DECREASING order of frequency (ties: any order). Return the resulting string.

- **Example:** "tree"  ->  "eert"  (or "eetr")
- **Constraints:** 1 <= len <= 5e5

> Fill this TOP-DOWN. Do NOT open LINKS.md or solution.cpp's signature until step 4 is written.

## 1. Restate (one sentence, my own words)
- just we need to sort the string with highest freq element at first and lowest at end and also if same freq then picking any one is fine

## 2. Constraints -> target complexity
- n bound / value range: 10^5
- target Big-O (and WHY): since its 10^5 we need to first not go for any solution bigger than O(n)

## 3. Pattern guess (FIRST instinct — run the gates aloud)
- sorted / monotonic? -> no
- unsorted pair / duplicate? -> no
- negatives or +-1 transform? -> no
- **My pattern:**

## 4. Brute force
- Idea: we need first max freq array of size given string of char array
then take 2 loops one to select a char and another to find how many char and store in that array at the index where freq matches and
then after that just loop that array and store in new array that char index no of times in ans and return 
- Time / Space: O(n^2)
- (medium/hard: code it & submit it before optimizing)

## 5. Bottleneck (where brute wastes work)
-

## 6. Optimal
- Pattern that kills the bottleneck:
- Why it works:
- Time / Space:

## 7. Compare & extract the CUE
- brute vs optimal (time/space):
- **Cue — surface features that map this kind of problem -> this pattern:**

## 8. Bugs hit (copy recurring ones to ../../MISTAKE_JOURNAL.md)
-

## Result (fill after AC)
- pattern correct on FIRST instinct?  | restated right first try?  | brute done?  | AC on judge?
