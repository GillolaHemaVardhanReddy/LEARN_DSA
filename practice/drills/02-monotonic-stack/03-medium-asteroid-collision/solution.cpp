// LC735 — Asteroid Collision · Medium · https://leetcode.com/problems/asteroid-collision/
// DRILL 02 · P3 (medium). Paste ONLY the Solution class into LeetCode. main() is local.
//
// GATES: name the flavor · build your OWN hostile input · self-trace before "done".
//
//   PATTERN (name it BEFORE you code): ____________________
//   Hint to yourself: a collision happens ONLY when a right-mover (+ on the stack top) meets a NEW
//   left-mover (- incoming). Resolve against the TOP repeatedly (the "resolve a batch" shape).
//   The 3 outcomes are the whole problem: newcomer wins / both die / newcomer dies.
// =============================================================================
#include <bits/stdc++.h>
using namespace std;

// OPTIMAL — stack of survivors; a new left-mover fights the right-movers on top.
//   Idea: ____      Time: O(n)   Space: O(n)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        stack<int> chk;
        for(int i = n-1 ; i >= 0 ; i-- ) {
            while(chk.size() 
            && ((a[chk.top()] < 0) && (a[i] >= 0))
            && (a[i] > abs(a[chk.top()]))){
                chk.pop();
            }
            if(chk.size() 
            && ((a[chk.top()] < 0) && (a[i] >= 0))
            && (abs(a[i]) < abs(a[chk.top()]))) continue;
            if(chk.size() 
            && ((a[chk.top()] < 0) && (a[i] >= 0))
            && (abs(a[i]) == abs(a[chk.top()]))){
                chk.pop();
                continue;
            }
            chk.push(i);
        }
        vector<int> ans;
        while(chk.size()){
            ans.push_back(a[chk.top()]);
            chk.pop();
        }
        return ans;
    }
};

// HOW I DERIVED BRUTE -> OPTIMAL  (The Bridge — your words)
//   Q1. A collision needs a `+` immediately left of a `-`. After one explosion a NEW pair can
//       become adjacent — which structure exposes that neighbor on top, ready to re-check? ->
//   Q2. New `-` meets top `+`: name the 3 outcomes and which one KEEPS looping. ->
//   Q3. When do you STOP fighting and just push the newcomer? (top is also `-`, or stack empty,
//       or newcomer is `+`) ->
//   My derivation: ->

// BRUTE ORACLE — fill FIRST. Repeatedly scan for an adjacent (+, -) pair, resolve it, loop till stable.
class SolutionBrute {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        // TODO (boss): the obvious repeated-scan version — oracle.
        return {};
    }
};

// STRESS — brute is the oracle. Meaningful once BOTH classes are filled.
int main() {
    Solution opt; SolutionBrute bru;
    vector<vector<int>> ex = {{5,10,-5}, {8,-8}, {10,2,-5}, {3,5,-6,2,-1,4}, {-2,-1,1,2}};
    for (auto v : ex) {
        auto o = opt.asteroidCollision(v), r = bru.asteroidCollision(v);
        printf("[");
        for (int x : o) printf("%d ", x);
        printf("]  %s\n", (o == r) ? "" : " <-- MISMATCH vs oracle");
    }
    unsigned seed = 4242;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    for (int t = 0; t < 100000; ++t) {
        int n = 1 + rnd() % 7;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) { int s = 1 + rnd() % 4; v[i] = (rnd() % 2) ? s : -s; } // small -> ties
        if (opt.asteroidCollision(v) != bru.asteroidCollision(v)) {
            printf("STRESS MISMATCH on: ");
            for (int x : v) printf("%d ", x);
            printf("\n"); return 1;
        }
    }
    printf("stress: 100k cases passed\n");
    return 0;
}
