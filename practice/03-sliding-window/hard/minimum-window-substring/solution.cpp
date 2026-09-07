// LC76 — Minimum Window Substring · Hard
// https://leetcode.com/problems/minimum-window-substring/
// HARD GAUNTLET · P3 (Sliding Window). Paste ONLY the Solution class. main() local.
//
// GATES: name the flavor · build your OWN hostile input · self-trace before "done".
//   ⭐ This is your owed P27 "derive-don't-maintain" re-test — run the variable audit BEFORE coding.
//
//   PATTERN (name it BEFORE you code): ____________________
//   Hint: variable window. Expand r until the window COVERS t (all chars incl. duplicates), then
//   shrink l while still covered, recording the smallest. Track coverage with a need-map + a single
//   `have == required` counter — do NOT re-scan the map each step.
// =============================================================================
#include <bits/stdc++.h>
using namespace std;

// OPTIMAL — grow r (have++ when a needed char hits its required count); while covered, try to shrink l
//   and record (r-l+1); a char leaving drops coverage.   Time: O(m+n)   Space: O(charset)
class Solution {
public:
    string minWindow(string s, string t) {
        // TODO (boss)
        return "";
    }
};

// HOW I DERIVED BRUTE -> OPTIMAL  (The Bridge — your words)
//   Q1. "Smallest window that covers t" — grow-then-shrink shape. What's the ONE invariant that says
//       "this window is still valid"? (a have-counter == t's distinct-need, not a full map compare) ->
//   Q2. Brute checks every (l,r) substring for coverage (O(n^2 * charset)). What does the window reuse
//       from the previous step so you never recount from scratch? ->
//   Q3. Variable audit (your re-test): is there a count I maintain by hand that's really derivable?
//       one driver r, one while-shrink on l, record r-l+1 — no extra synced state? ->
//   My derivation: ->

// BRUTE ORACLE — fill FIRST. All (l,r); if window covers t, track min length (leftmost on tie). O(n^2).
class SolutionBrute {
public:
    string minWindow(string s, string t) {
        // TODO (boss): brute coverage check; return leftmost minimal window ("" if none).
        return "";
    }
};

// STRESS — brute is the oracle (leftmost-minimal, so strings must match exactly).
int main() {
    Solution opt; SolutionBrute bru;
    vector<pair<string,string>> ex = {{"ADOBECODEBANC","ABC"},{"a","a"},{"a","aa"},{"ab","b"}};
    for (auto& [s,t] : ex) {
        string o = opt.minWindow(s,t), r = bru.minWindow(s,t);
        printf("\"%s\"  %s\n", o.c_str(), (o==r) ? "" : " <-- MISMATCH vs oracle");
    }
    unsigned seed = 76;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    auto mk = [&](int n){ string z; for(int i=0;i<n;++i) z += char('a'+rnd()%4); return z; };
    for (int tt = 0; tt < 50000; ++tt) {
        string s = mk(1+rnd()%8), t = mk(1+rnd()%4);
        if (opt.minWindow(s,t) != bru.minWindow(s,t)) {
            printf("STRESS MISMATCH s=%s t=%s\n", s.c_str(), t.c_str()); return 1;
        }
    }
    printf("stress: 50k cases passed\n");
    return 0;
}
