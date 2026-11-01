// RE-TEST 2b — S3 · LC2364 Count Number of Bad Pairs (medium)
// https://leetcode.com/problems/count-number-of-bad-pairs/
// Handed disguised (plain arrays, no title): "count pairs i<j with j-i != nums[j]-nums[i]"
//   [4,1,3,3] -> 5 · [1,2,3,4,5] -> 0 · [1,1] -> 1 · n <= 1e5, nums[i] <= 1e9
//
// VERDICT 2026-10-31 (sitting ran past midnight into 11-01): AC.
//   NOT a cold pass — the separation move was TAUGHT on 10-30 at his ask. Learning rep.
//
// WHAT WAS HIS, UNAIDED:
//   - the rewrite  j - nums[j] = i - nums[i]   (the separation, once asked for it)
//   - the complement step: answer = all possible pairs - matching pairs  (found himself)
//   - "a set would just say yes it exists at least once"  => needs COUNTS, not membership (V#4)
//   - diagnosed check[0]=1 as a ghost index after ONE hostile input ([0] -> returns -1)
//   - priced n*(n-1) at 1e10 in digits; spotted `int * int`
//   - dropped the helper vector `c` when asked if it needed to exist
//
// WHAT NEEDED TELLING:
//   - WHY rewrite at all: a hashmap looks up exactly ONE key; while i and j sit on both
//     sides there IS no key. Separating the sides is what manufactures the key.
//   - combination vs permutation: nC2 = n(n-1)/2, and "order" in combinatorics means
//     "does (0,1) differ from (1,0)", NOT ascending/descending  (-> V#7)
//   - int max ~= 2.1e9 (he guessed 1e7); long long ~= 9.2e18
//   - `long long(ans)` does not compile: functional-cast syntax needs a single-word type
//
// THE IDEA, HIS WORDS (2026-10-31):
//   "soo now i-nums[i] = j-nums[j] is what we are after ... using the damnnn same logic
//    that if the i-nums[i] did it appear again or not and add it to ans how many times
//    and at end ans should be subtracted from all pairs to get final ans"
//
// COMPLEXITY (his, with the lines): one loop over n = line 51; each step is O(1) because
//   the key is HASHED (count / [] / ++ jump to the bucket, no scan)  => O(n) time.
//   Memory: `check` holds up to n distinct keys => O(n).  (First draft also kept a vector
//   `c` of n labels - a second O(n) source and a second pass - removed in this version.)
//
// GATE C MISS (logged): first submission had int ans + (n*(n-1))/2 in int, after being
//   told twice to price the magnitude. Then the cast was placed AFTER the arithmetic
//   (`- long long(ans)`), which photographs an already-overflowed number.
//   Rule re-learned: WIDEN BEFORE THE ARITHMETIC.

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;                       // matching (= "good") pairs
        unordered_map<int, int> check;           // label -> how many earlier indices carried it
        for (int i = 0; i < n; i++) {
            int temp = i - nums[i];              // this index's private label
            if (check.count(temp)) {
                ans += check[temp];              // every earlier index with the same label
            }
            check[temp]++;                       // insert AFTER the lookup: the map holds only the PAST
        }
        return (((long long)n * (n - 1)) / 2) - ans;   // widened BEFORE the multiply
    }
};
