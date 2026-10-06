// LC 454 — 4Sum II  ·  Medium  ·  topic 01 hashing, rung 5/6  ·  LEARN
// 2026-10-05  ·  https://leetcode.com/problems/4sum-ii/
//
// Four arrays nums1, nums2, nums3, nums4, ALL of length n.
// Count the tuples (i, j, k, l) with  nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0.
// One index per array. Indices are independent — i can equal j. Count TUPLES, not distinct values.
//
//   nums1=[1,2] nums2=[-2,-1] nums3=[-1,2] nums4=[0,2]  ->  2
//        (0,0,0,1): 1 + (-2) + (-1) + 2 = 0
//        (1,1,0,0): 2 + (-1) + (-1) + 0 = 0
//   nums1=[0] nums2=[0] nums3=[0] nums4=[0]              ->  1
//
// n == every length · 1 <= n <= 200 · -2^28 <= nums_x[i] <= 2^28   (2^28 = 268,435,456)
//
// =============================================================================
// STEP 0 — the budget line. NO ADJECTIVES. Write the digits.
//   n = ____ .  The brute walks every tuple: that is ____ tuples.
//   Write that number out: ____________ .  Judge does ~10^8/sec, so the brute is ____ .
//   Then: what is the biggest the ANSWER itself can be? ____________
//   Does it fit in an `int` (ceiling 2.147 x 10^9)?  ____     <-- Gate C, magnitude
// =============================================================================


// =============================================================================
// STEP 1 — BRUTE.  Four nested loops. Don't write it out in full, just answer:
//   how many additions, and what is the complexity in n?
// =============================================================================


// =============================================================================
// STEP 2 — THE BRIDGE.  Three questions, in words, before any code.
//
//   B1. On LC560 you were standing at position j holding ONE number (the prefix),
//       and you asked the map for ONE number (P[j] - k).
//       Here you are holding FOUR numbers that must add to 0.
//       Rewrite the condition  a + b + c + d == 0  so that ONE side is (a + b)
//       and the other side has no a and no b in it.
//
//   B2. Your brute's 4 nested loops cost n^4. But how many DISTINCT values can
//       (a + b) take at most? And how many can (c + d) take at most?
//       Write both numbers for n = 200.
//       So: how much work is it to enumerate every (a+b), and every (c+d), SEPARATELY
//       instead of all four together?
//
//   B3. ANSWERED 2026-10-05: key = the SUM (a+b), value = HOW MANY (i,j) pairs produce it.
//       A set cannot count — it can only ever add 1. Worked example:
//         nums1=[1,1] nums2=[0,0] -> sum 1 reachable 4 ways
//         nums3=[-1,0] nums4=[0,-1] -> sum -1 reachable 2 ways   => 4 x 2 = 8 tuples
//
//   (original wording) You now have a pile of (a+b) values and a pile of (c+d) values.
//       For one particular (c+d), what do you need to know about the first pile?
//       Is it "is that value present?" or "HOW MANY of the pile equal it?" — and WHY
//       does that distinction matter here? (hint: nums1=[1,1], nums2=[0,0] — how many
//       index-pairs (i,j) produce the sum 1?)
//
//   The 4 disqualifiers, before naming a tool:
//       contiguous?  ·  sorted / may I sort?  ·  order or membership?  ·  count / best / list-all?
// =============================================================================


// =============================================================================
// STEP 3 — OPTIMAL.  Real LeetCode signature.
// =============================================================================
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> check1;
        int a = nums1.size(), b = nums2.size(), c = nums3.size(), d = nums4.size();
        for(int i = 0 ; i < a ; i++ ) {
            for(int j = 0 ; j < b ; j++ ) {
                check1[nums1[i]+nums2[j]]++;
            }
        }
        int ans = 0;
        for(int i = 0 ; i < c ; i++ ) {
            for(int j = 0 ; j < d ; j++ ) {
                int temp = nums3[i] + nums4[j];
                if(check1[-1*temp] > 0){
                    ans+=check1[-1*temp];
                }
            }
        }
        return ans;
    }
};


// =============================================================================
// STEP 4 — hostile inputs before submit (add your own)
//   [1,2] [-2,-1] [-1,2] [0,2]            -> 2    the given example
//   [0] [0] [0] [0]                        -> 1    n = 1, the smallest legal input
//   [1,1] [0,0] [-1,0] [0,-1]              -> 8    counts MULTIPLY: sum 1 reachable 4 ways x sum -1 reachable 2 ways
//   [1,1] [0,0] [-1,-1] [0,0]              -> 16   duplicates: counts must MULTIPLY, not collapse
//                                                 (4 pairs from the first half x 4 from the second)
//   [1] [1] [1] [1]                        -> 0    no answer at all
//   [2^28] [2^28] [-2^28] [-2^28]          -> 1    magnitude: does (a+b) overflow? show the number
//
// STEP 5 — the closing sentence  ·  BANKED 2026-10-07, AC id 2164619908
//   All four lengths are n (given), so a = b = c = d = n.
//
//   O(n^2) TIME. Lines 69-73 run n*n = 4x10^4 times. Lines 75-82 run n*n = 4x10^4 times.
//   ADDED, not multiplied — the two double loops are independent, neither is inside the other.
//   Each map operation costs O(1) average, because unordered_map HASHES the key straight to a
//   bucket: the same single step whether the map holds 10 keys or 40,000.
//   Total = 8x10^4 steps against a ~10^8/sec judge.  <-- the line that says it passes
//
//   What the container was worth (the factor that is easy to forget):
//     unordered_map : 1 step per op      -> 8x10^4         total
//     map (a balanced BST)   : log2(40000) ~ 16 steps/op -> ~1.3x10^6 total
//   A map is a binary search built into a structure (same machine as LC704/LC153): finding a key
//   WALKS DOWN from the root halving the range = log L comparisons. It is NOT L log L — L log L is
//   the cost of sorting all L items once; one insert into an already-ordered tree just hooks in.
//   (Here map would still have AC'd. The difference bites when the loop count is 10^7, not 10^4.)
//
//   O(n^2) MEMORY — check1 holds at most n*n = 40,000 distinct sums, one key per (i,j) pair (line 71).
//   LEAK: line 78/79 read with operator[], which INSERTS a 0 for every MISSING (c+d) too, so the map
//   can reach 8x10^4 entries. Reading a map with [] is the 2026-09-27 gap firing again — use
//   .count()/.find() to test, or just drop the `if` entirely: `ans += check1[-temp];` adds 0 when
//   absent, which makes the guard on line 78 redundant anyway.
// =============================================================================
