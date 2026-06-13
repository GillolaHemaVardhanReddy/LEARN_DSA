# DRILL 1  —  Problem 6   [easy]

## Statement (disguised — recognize BEFORE you peek at LINKS.md)
Decide if a ransom note can be built using the letters of a magazine, each magazine letter used at most once.

- **Example:** note="aa", magazine="aab"  ->  true ;  note="aa", magazine="ab" -> false
- **Constraints:** lengths <= 1e5

> Fill this TOP-DOWN. Do NOT open LINKS.md or solution.cpp's signature until step 4 is written.

## 1. Restate (one sentence, my own words)
- its just saying that if the note word can be built from the letters present in magazine or not i dont know if the order matters or not since its not in the statement given above, but as per example i assume its potreying as if the note is substring of main string or not question

## 2. Constraints -> target complexity
- n bound / value range: 10^5
- target Big-O (and WHY): O(n) at most since ^2 makes it go to 10^10

## 3. Pattern guess (FIRST instinct — run the gates aloud)
- sorted / monotonic? -> no
- unsorted pair / duplicate? -> no
- negatives or +-1 transform? -> no
- **My pattern:** frequency map 

## 4. Brute force
- Idea: just check all letters in note loop in magazine if not present return false and if loop goes till end its true
- Time / Space: O(n^2)
- (medium/hard: code it & submit it before optimizing)

## 5. Bottleneck (where brute wastes work)
-

## 6. Optimal
- Pattern that kills the bottleneck: frequency array meaning hashmap with value of char to be frequncy
- Why it works: hashmap removed the internal loop for lookup
- Time / Space: O(n)

## 7. Compare & extract the CUE
- brute vs optimal (time/space): moves from O(n^2) to n
- **Cue — surface features that map this kind of problem -> this pattern:**

## 8. Bugs hit (copy recurring ones to ../../MISTAKE_JOURNAL.md)
-

## Result (fill after AC)
- pattern correct on FIRST instinct?  | restated right first try?  | brute done?  | AC on judge?
