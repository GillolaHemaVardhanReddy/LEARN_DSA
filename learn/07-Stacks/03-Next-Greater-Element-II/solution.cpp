// LC503 — Next Greater Element II
// M7 Stacks · monotonic stack, CIRCULAR. Your NGE engine, one twist.
//
//   Return, for each nums[i], the next greater number to the right; the array is
//   CIRCULAR (after the last element you wrap back to the front). -1 if none exists.
//   nums = [1,2,1] -> [2,-1,2]   (the last 1 wraps around to find the 2)
//
// =============================================================================
//  BRUTE  — scan forward, with wraparound   (fill FIRST; it is the stress ORACLE)
// =============================================================================
//  Idea: for each i, walk up to n-1 steps forward using (i+k) % n; first strictly
//        greater value is the answer, else -1.
//  Time:  O(n^2)
//  Space: O(1) extra
#include <bits/stdc++.h>
using namespace std;

class SolutionBrute {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(), chk = 0;
        vector<int> ans(n, -1);
        for(int i = 0 ; i < n ; i++ ) {
            int untill = 2*n-1;
            for(int j = i+1 ; j < untill ; j++){
                if(nums[i] < nums[j%n]){
                    chk++;
                    ans[i] = nums[j%n];
                    break;
                }
            }
        }
        return ans;
    }
};

// =============================================================================
//  HOW I DERIVED BRUTE -> OPTIMAL   (The Bridge — your words)
// =============================================================================
//  Q1. Your generic NGE engine made one left-to-right pass. What's the SMALLEST
//      change that lets a late element still find a greater one that sits earlier?
//      ->
//  Q2. If you walked the indices 0..2n-1 and used (i % n) to read the value, what
//      would the second lap give the elements still waiting on the stack?
//      ->
//  Q3. On the second lap, should you keep PUSHING new indices, or only RESOLVE the
//      ones still waiting? Why?
//      ->
//  My plain-words derivation:
//      ->

// =============================================================================
//  OPTIMAL — monotonic stack (of indices), two laps
// =============================================================================
//  Idea: "find first greater element to its right" => monotonic stack (decreasing, holds
//        INDICES). Circular: one lap stops at the end and leaves the suffix-maxima still on the
//        stack with no greater-to-the-right yet; loop 2n and read nums[i%n] so a 2nd lap lets
//        those leftovers wrap around and get resolved. Only push on lap 1 (if i<n).
//  Time:  O(n)
//  Space: O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> chk;
        for(int i = 0 ; i < 2*n-1 ; i++) {
            while(!chk.empty() && (nums[i%n] > nums[chk.top()])){
                ans[chk.top()] = nums[i%n];
                chk.pop();
            }
            if(i<n) chk.push(i);
        }
        return ans;
    }
};

// =============================================================================
//  STRESS TEST — brute is the oracle
// =============================================================================
int main() {
    vector<vector<int>> inputs = {
        {1,2,1}, {1,2,3,4,3}, {5,4,3,2,1}, {1,1,1}, {7}, {2,1,2,4,3}
    };
    Solution opt; SolutionBrute bru;
    for (auto v : inputs) {
        auto a = opt.nextGreaterElements(v);
        auto b = bru.nextGreaterElements(v);
        printf("[");
        for (int x : a) printf("%d ", x);
        printf("]  %s\n", (a==b) ? "" : " <-- opt/brute MISMATCH");
    }

    // Random stress: brute vs optimal.
    unsigned seed = 4242;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    for (int trial = 0; trial < 100000; ++trial) {
        int n = 1 + rnd() % 8;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) v[i] = 30 + rnd() % 10;  // small range -> ties + wrap cases
        if (opt.nextGreaterElements(v) != bru.nextGreaterElements(v)) {
            printf("STRESS MISMATCH on: ");
            for (int x : v) printf("%d ", x);
            printf("\n");
            return 1;
        }
    }
    printf("stress: 100k cases passed\n");
    return 0;
}
