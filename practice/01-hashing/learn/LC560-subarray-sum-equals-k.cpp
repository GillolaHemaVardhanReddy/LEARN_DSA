// LC 560 — Subarray Sum Equals K  ·  Medium  ·  topic 01 hashing, rung 4/6  ·  LEARN
// 2026-10-03  ·  https://leetcode.com/problems/subarray-sum-equals-k/
//
// Given nums and an integer k, return the TOTAL NUMBER of subarrays whose sum == k.
// A subarray is CONTIGUOUS and NON-EMPTY.
//
//   nums = [1,1,1],  k = 2   ->  2      ( [1,1] at 0..1 and [1,1] at 1..2 — they overlap, both count )
//   nums = [1,2,3],  k = 3   ->  2      ( [1,2] and [3] )
//   nums = [1,-1,0], k = 0   ->  3      ( [1,-1], [0], [1,-1,0] )
//
// 1 <= nums.length <= 2*10^4
// -1000 <= nums[i] <= 1000      <-- read this one twice
// -10^7 <= k <= 10^7
//
// =============================================================================
// STEP 0 — the budget line (say it before writing anything)
//   n = ____, one subarray-sum costs ____, so the brute is ____,
//   which is ____ operations, which the judge ____ afford.
// =============================================================================


// =============================================================================
// STEP 1 — BRUTE.  Write it. Get it right. It is the thing we will then attack.
//   Every subarray is a pair (start i, end j) with i <= j. Walk them all, sum, compare.
// =============================================================================
class BruteSolution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, ans = 0;
        for(int i = 0 ; i < n ; i++ ) {
            sum = 0;
            for(int j = i ; j < n ; j++ ) {
                sum+=nums[j];
                if(sum == k ) ans++;
            }
        }
        return ans;
    }
};


// =============================================================================
// STEP 2 — THE BRIDGE.  Answer these three in words, in chat, before any code.
//
//   B1. Run your brute on nums = [1,2,3,4], k = 5. Write down, for every start i,
//       the running sums you computed. How many ADDITIONS did you do in total?
//       Now: how many of those additions computed a number you had ALREADY computed
//       under a different start?
//
//   B2. Define P[j] = nums[0] + nums[1] + ... + nums[j]   (the prefix sum, "total so far").
//       For nums = [1,2,3,4]: P = [1, 3, 6, 10].
//       Write the sum of the subarray from index i to index j USING ONLY P.
//       (Two values from P, one operator.)
//
//   B3. You are standing at index j. You know P[j]. You want to know
//       HOW MANY starts i make that subarray sum equal k.
//       Using your answer to B2, finish this sentence:
//           "a subarray ending at j has sum k exactly when the prefix before it equals ____"
//       Then: what question are you asking about the past? Is it
//       "have I seen it?" or "how many times have I seen it?" — and which container answers that?
//
//   The 4 disqualifier questions, before you name a tool:
//       contiguous?  ·  sorted / may I sort?  ·  order or membership?  ·  count / best / list-all?
// =============================================================================


// =============================================================================
// STEP 3 — OPTIMAL.  One pass. Real LeetCode signature.
// =============================================================================
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> check;
        int n = nums.size(), sum = 0;
        int ans = 0;
        check[0] = 1;
        for(int i = 0 ; i < n ; i++ ) {
            sum+=nums[i];
            ans += check[sum - k];
            check[sum] += 1;
        }
        return ans;
    }
};


// =============================================================================
// STEP 4 — the hostile inputs you must pass before submitting (you add more)
//   [1,1,1], k=2      -> 2     overlapping subarrays both count
//   [1,-1,0], k=0     -> 3     negatives: a running sum can go DOWN
//   [3], k=3          -> 1     the whole array is a subarray -> tests the pre-seeded entry
//   [0,0], k=0        -> 3     [0],[0],[0,0] — tests lookup-before-insert
//   [1,2,3], k=7      -> 0     no answer at all
//
// STEP 5 — the closing sentence
//   O(____) — this line runs ____ times and each lookup costs ____ .
//   Memory O(____) because ____ .
// =============================================================================
