// LC1047 — Remove All Adjacent Duplicates In String · Easy
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// DRILL 02 · P1 (easy). Paste ONLY the Solution class into LeetCode. main() is local.
//
// GATES: name the flavor FIRST · build your OWN hostile input · self-trace before "done".
//
//   PATTERN (name it BEFORE you code): ____________________
//   Hint to yourself: a stack lets the NEW char check only the MOST RECENT survivor — equal ⇒
//   annihilate (pop), else push. One pass, O(n). (The "collapse" flavor.)
// =============================================================================
#include <bits/stdc++.h>
using namespace std;

// OPTIMAL — one stack pass; new char cancels the top if equal, else pushes.
//   Idea: ____      Time: O(n)   Space: O(n)
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        stack<int> chk;
        for(int i = n-1; i>=0; i--){
            int push = 1;
            while(chk.size() && (s[i]==s[chk.top()])){
                chk.pop();
                push = 0;
            }
            if(push) chk.push(i);
        }
        string ans = "";
        while(chk.size()){
            ans+=s[chk.top()];
            chk.pop();
        }
        return ans;
    }
};

// HOW I DERIVED BRUTE -> OPTIMAL  (The Bridge — your words)
//   Q1. The brute re-scans the whole string after every removal. What's recomputed each pass? ->
//   Q2. When you remove a pair, which characters might NEWLY become adjacent-equal? What structure
//       keeps that left-neighbor sitting right on top, ready to check? ->
//   Q3. So a single left-to-right pass with a ____ replaces all the rescans. ->
//   My derivation: ->

// BRUTE ORACLE — fill FIRST. Repeatedly erase the first adjacent-equal pair until none remain. O(n^2).
class SolutionBrute {
public:
    string removeDuplicates(string s) {
        
        return "";
    }
};

// STRESS — brute is the oracle. Meaningful once BOTH classes are filled.
int main() {
    Solution opt; SolutionBrute bru;
    vector<string> ex = {"abbaca", "azxxzy", "aaaaa", "a", "abba"};
    for (auto& s : ex) {
        string o = opt.removeDuplicates(s), r = bru.removeDuplicates(s);
        printf("\"%s\"  %s\n", o.c_str(), (o == r) ? "" : " <-- MISMATCH vs oracle");
    }
    unsigned seed = 7;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    for (int t = 0; t < 100000; ++t) {
        int n = rnd() % 9;
        string s;
        for (int i = 0; i < n; ++i) s += char('a' + rnd() % 3);  // tiny alphabet -> many collisions
        if (opt.removeDuplicates(s) != bru.removeDuplicates(s)) {
            printf("STRESS MISMATCH on \"%s\"\n", s.c_str()); return 1;
        }
    }
    printf("stress: 100k cases passed\n");
    return 0;
}
