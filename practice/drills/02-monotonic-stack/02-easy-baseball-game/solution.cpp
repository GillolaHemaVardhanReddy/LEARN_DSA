// LC682 — Baseball Game · Easy · https://leetcode.com/problems/baseball-game/
// DRILL 02 · P2 (easy). Paste ONLY the Solution class into LeetCode. main() is local.
//
// GATES: name the flavor · build your OWN hostile input · self-trace before "done".
//
//   PATTERN (name it BEFORE you code): ____________________
//   Hint to yourself: each op touches only the most recent one/two scores -> a stack IS the record.
//   (The "simulation / undo" flavor.) Parsing trap: "-2" is a number, not the '+' op.
// =============================================================================
#include <bits/stdc++.h>
using namespace std;

// OPTIMAL — a stack of scores; switch on the op string; sum the stack at the end.
//   Idea: ____      Time: O(n)   Space: O(n)
class Solution {
public:
    int calPoints(vector<string>& operations) {
        // TODO (boss)
        return 0;
    }
};

// HOW I DERIVED IT  (The Bridge — short; this is a simulation, the "stack as record" flavor)
//   Q1. Which ops READ the previous one/two scores, and which one REMOVES? ->
//   Q2. Why does a stack model "the record" exactly (LIFO = most-recent-first)? ->
//   Q3. How do you tell a number op from "+"/"D"/"C"? (and parse a leading '-') ->
//   My derivation: ->

// REFERENCE ORACLE — fill FIRST. The obvious straight simulation (your ground truth).
class SolutionBrute {
public:
    int calPoints(vector<string>& operations) {
        // TODO (boss): the obvious sim — oracle.
        return 0;
    }
};

// STRESS — generates only VALID op sequences (C/D need >=1 score, '+' needs >=2).
int main() {
    Solution opt; SolutionBrute bru;
    vector<vector<string>> ex = {
        {"5","2","C","D","+"}, {"5","-2","4","C","D","9","+","+"}, {"1","C"}
    };
    for (auto& v : ex) {
        int o = opt.calPoints(v), r = bru.calPoints(v);
        printf("%d  %s\n", o, (o == r) ? "" : " <-- MISMATCH vs oracle");
    }
    unsigned seed = 99;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    for (int t = 0; t < 100000; ++t) {
        int n = 1 + rnd() % 12, cnt = 0;
        vector<string> v;
        for (int i = 0; i < n; ++i) {
            vector<int> allowed = {0};                 // 0 = push int (always legal)
            if (cnt >= 1) { allowed.push_back(2); allowed.push_back(3); }  // 2='D', 3='C'
            if (cnt >= 2) allowed.push_back(1);        // 1='+'
            int c = allowed[rnd() % allowed.size()];
            if      (c == 0) { v.push_back(to_string((int)(rnd()%21) - 10)); ++cnt; }
            else if (c == 1) { v.push_back("+"); ++cnt; }
            else if (c == 2) { v.push_back("D"); ++cnt; }
            else             { v.push_back("C"); --cnt; }
        }
        if (opt.calPoints(v) != bru.calPoints(v)) { printf("STRESS MISMATCH\n"); return 1; }
    }
    printf("stress: 100k cases passed\n");
    return 0;
}
