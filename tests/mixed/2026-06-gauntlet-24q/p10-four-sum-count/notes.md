# DRILL 1  —  Problem 10   [medium]

## Statement (disguised — recognize BEFORE you peek at LINKS.md)
Given four integer arrays of length n, COUNT the tuples (i,j,k,l) with A[i]+B[j]+C[k]+D[l]==0.

- **Example:** A=[1,2],B=[-2,-1],C=[-1,2],D=[0,2]  ->  2
- **Constraints:** 1 <= n <= 200

> Fill this TOP-DOWN. Do NOT open LINKS.md or solution.cpp's signature until step 4 is written.

## 1. Restate (one sentence, my own words)
- they asked us to find out indexes the sum of any element one from each array that sums up to 0

## 2. Constraints -> target complexity
- n bound / value range: 200
- target Big-O (and WHY): can go up to O(n^4)

## 3. Pattern guess (FIRST instinct — run the gates aloud)
- sorted / monotonic? -> no never mentioned its sorted so i cant imagine
- unsorted pair / duplicate? -> yes unsorted
- negatives or +-1 transform? -> ys -ve's
- **My pattern:** hash map 

## 4. Brute force
- Idea: write 4 loops and check in all 4 arrays for all combinations
- Time / Space: O(n^4)
- (medium/hard: code it & submit it before optimizing)

## 5. Bottleneck (where brute wastes work)
-

## 6. Optimal
- Pattern that kills the bottleneck: hash map
- Why it works:take 2 loops for 2 arrays and separate 2 loops for another 2 arrays find out the sums of all pairs of 1st and then check if the 2nd one gives us the -ve of same sum in hash if yes then count and at end retun the count
- Time / Space: O(n^2)

## 7. Compare & extract the CUE
- brute vs optimal (time/space):
- **Cue — surface features that map this kind of problem -> this pattern:**

## 8. Bugs hit (copy recurring ones to ../../MISTAKE_JOURNAL.md)
-

## Result (fill after AC)
- pattern correct on FIRST instinct?  | restated right first try?  | brute done?  | AC on judge?
