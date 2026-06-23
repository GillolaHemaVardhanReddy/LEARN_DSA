// LC739 — Daily Temperatures
// M7 Stacks · first MONOTONIC stack. Build the optimal from understanding.
//
// =============================================================================
//  BRUTE  — scan forward
// =============================================================================
//  Idea: for each day i, walk forward to the first day j with a warmer temp;
//        answer[i] = j - i. If none, answer[i] = 0.
//  Time:  O(n^2)   (n up to 1e5 -> ~1e10 -> TLE on the judge)
//  Space: O(1) extra
#include <bits/stdc++.h>
using namespace std;

class SolutionBrute {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n, 0);
        for(int i = 0 ; i < n ; i++) {
            for(int j = i+1 ; j < n ; j++ ) {
                if(t[i]<t[j]){
                    ans[i] = j-i;
                    break;
                }
            }
        }
        return ans;
    }
};

// =============================================================================
//  HOW I DERIVED BRUTE -> OPTIMAL   (The Bridge — fill in your words)
// =============================================================================
//  Q1. In the brute, what work gets redone for day i that day i-1 already did?
//      ->
//  Q2. When you find a warmer day, which earlier days' answers does it resolve?
//      ->
//  Q3. What structure holds the days still "waiting for a warmer day," and in
//      what order are they sitting in it (by temperature)?
//      ->
//  My plain-words derivation:
//      ->

// =============================================================================
//  OPTIMAL — monotonic stack (of indices)
// =============================================================================
//  Idea:
//  Time:  O(n)   (each index pushed once, popped once)
//  Space: O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n, 0);
        stack<int> check;
        for(int i = 0 ; i < n ; i++) {
            while((!check.empty()) && (t[check.top()] < t[i])){
                ans[check.top()] = i - check.top();
                check.pop();
            }
            check.push(i);
        }
        return ans;
    }
};

// =============================================================================
//  STRESS TEST — brute is the oracle
// =============================================================================
int main() {
    // Sanity: the LeetCode examples.
    vector<vector<int>> inputs = {
        {73,74,75,71,69,72,76,73}, {30,40,50,60}, {30,60,90}, {100}, {50,40,30}
    };
    Solution opt; SolutionBrute bru;
    for (auto v : inputs) {
        auto a = opt.dailyTemperatures(v);
        auto b = bru.dailyTemperatures(v);
        printf("[");
        for (int x : a) printf("%d ", x);
        printf("]  %s\n", (a==b) ? "" : " <-- opt/brute MISMATCH");
    }

    // Random stress: brute vs optimal.
    unsigned seed = 999;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    for (int trial = 0; trial < 100000; ++trial) {
        int n = 1 + rnd() % 8;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) v[i] = 30 + rnd() % 10;  // small range -> ties
        if (opt.dailyTemperatures(v) != bru.dailyTemperatures(v)) {
            printf("STRESS MISMATCH on: ");
            for (int x : v) printf("%d ", x);
            printf("\n");
            return 1;
        }
    }
    printf("stress: 100k cases passed\n");
    return 0;
}
