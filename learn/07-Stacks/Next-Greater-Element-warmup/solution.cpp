// Next Greater Element (to the right) — Monotonic Stack WARM-UP
// M7 Stacks · the GENERIC monotonic-stack engine. Build it from your trace, not memory of code.
//
//   ans[i] = next element to the RIGHT that is strictly greater than nums[i], else -1.
//   [3,1,2,5,4] -> [5,2,5,-1,-1]
//
// =============================================================================
//  BRUTE  — scan forward   (fill this FIRST; it is also the stress-test ORACLE)
// =============================================================================
//  Idea: for each i, walk j = i+1.. to the first nums[j] > nums[i]; record it, else -1.
//  Time:  O(n^2)
//  Space: O(1) extra
#include <bits/stdc++.h>
using namespace std;

class SolutionBrute {
public:
    vector<int> nextGreater(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0 ; i < n ; i++ ) {
            int k = nums[i];
            int check = 1;
            for(int j = i+1 ; j < n ; j++ ) {
                if(k < nums[j]){
                    ans.push_back(nums[j]);
                    check = 0;
                    break;
                }
            }
            if(check){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

// =============================================================================
//  HOW I DERIVED BRUTE -> OPTIMAL   (The Bridge — fill in your OWN words)
// =============================================================================
//  Q1. In the brute, what work does element i re-walk that earlier elements
//      already walked?
//      ->
//  Q2. When a new element arrives that is bigger than the stack top, WHICH waiting
//      elements does it resolve, and how many at once?
//      ->
//  Q3. Why is the stack always DECREASING without you forcing it? (what happens to
//      a smaller waiting element when a bigger one shows up?)
//      ->
//  My plain-words derivation:
//      ->

// =============================================================================
//  OPTIMAL — monotonic stack (of INDICES)
// =============================================================================
//  Idea: stack holds indices of elements still waiting for a greater element, kept
//        decreasing by value. New element pops everyone it beats (records their ans),
//        then waits itself. Leftovers at the end -> -1.
//  Time:  O(n)   (each index pushed once, popped at most once)
//  Space: O(n)
class Solution {
public:
    vector<int> nextGreater(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(nums.size(), -1);
        for(int i = 0 ; i < n ; i++ ) {
            int ch = nums[i];
            while(!(st.empty()) && ch > nums[st.top()]){
                ans[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

// =============================================================================
//  STRESS TEST — brute is the oracle
// =============================================================================
int main() {
    vector<pair<vector<int>, vector<int>>> cases = {
        {{3,1,2,5,4}, {5,2,5,-1,-1}},
        {{2,1,3},     {3,3,-1}},
        {{5,4,3},     {-1,-1,-1}},
        {{1,2,3},     {2,3,-1}},
        {{7},         {-1}},
    };
    Solution opt; SolutionBrute bru;
    for (auto& [in, want] : cases) {
        auto got = opt.nextGreater(const_cast<vector<int>&>(in));
        printf("[");
        for (int x : got) printf("%d ", x);
        printf("]  %s\n", (got == want) ? "OK" : "<-- WRONG vs expected");
    }

    // Random stress: optimal vs brute oracle.
    unsigned seed = 12345;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    for (int trial = 0; trial < 100000; ++trial) {
        int n = 1 + rnd() % 8;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) v[i] = 30 + rnd() % 10;   // small range -> ties (strict-vs-nonstrict check)
        if (opt.nextGreater(v) != bru.nextGreater(v)) {
            printf("STRESS MISMATCH on: ");
            for (int x : v) printf("%d ", x);
            printf("\n");
            return 1;
        }
    }
    printf("stress: 100k cases passed\n");
    return 0;
}
