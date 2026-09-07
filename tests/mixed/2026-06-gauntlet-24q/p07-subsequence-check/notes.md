# DRILL 1  —  Problem 7   [easy]

## Statement (disguised — recognize BEFORE you peek at LINKS.md)
Decide whether s is a SUBSEQUENCE of t (all of s's chars appear in t in order, not necessarily contiguous).

- **Example:** s="abc", t="ahbgdc"  ->  true
- **Constraints:** 0 <= len <= 1e4

> Fill this TOP-DOWN. Do NOT open LINKS.md or solution.cpp's signature until step 4 is written.

## 1. Restate (one sentence, my own words)
- it was actually asking that we need to find if the t has s in it or not that too in same order and may not be continuous

## 2. Constraints -> target complexity
- n bound / value range: 10^4 so it can be O(n) to stay in limits of 10^9
- target Big-O (and WHY): O(n)

## 3. Pattern guess (FIRST instinct — run the gates aloud)
- sorted / monotonic? -> no
- unsorted pair / duplicate? -> no
- negatives or +-1 transform? -> no
- **My pattern:** 2 pointer

## 4. Brute force
- Idea: just keep a loop for s and check in another loop inside t if the char are in correct order or not if any char misses return false
and if any char goes out of seq return false, we track out of seq using another separate variable from where to start inner loop after
finding the prev char just from next char index
- Time / Space:O(n^2)
- (medium/hard: code it & submit it before optimizing)

## 5. Bottleneck (where brute wastes work)
- search inner loop

## 6. Optimal
- Pattern that kills the bottleneck: its 2 pointer 
- Why it works: its 2 pointer then only go to next char if we actuallt get a match and if not go on incr
- Time / Space: O(n)

## 7. Compare & extract the CUE
- brute vs optimal (time/space):
- **Cue — surface features that map this kind of problem -> this pattern:**

## 8. Bugs hit (copy recurring ones to ../../MISTAKE_JOURNAL.md)
-

## Result (fill after AC)
- pattern correct on FIRST instinct?  | restated right first try?  | brute done?  | AC on judge?
