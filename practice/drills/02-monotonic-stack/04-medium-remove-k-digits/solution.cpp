// LC402 — Remove K Digits · Medium · https://leetcode.com/problems/remove-k-digits/
// DRILL 02 · P4 (medium). Paste ONLY the Solution class into LeetCode. main() is local.
//
// GATES: name the flavor · build your OWN hostile input · self-trace before "done".
//
//   PATTERN (name it BEFORE you code): ____________________
//   Hint to yourself: to make the number small, scanning left->right a digit should POP any BIGGER
//   digit before it (a big digit in a high place hurts most) while k > 0 -> a monotonic-INCREASING
//   stack. (The "greedily build" flavor.) END-TRAPS: leftover k -> trim from the END; leading
//   zeros -> strip; empty result -> "0".
// =============================================================================
#include <bits/stdc++.h>
using namespace std;

// OPTIMAL — monotonic-increasing stack; pop bigger predecessors while k>0; then trim/strip.
//   Idea: ____      Time: O(n)   Space: O(n)
class Solution {
public:
    string removeKdigits(string num, int k) {
        // TODO (boss)
        return "";
    }
};

// HOW I DERIVED BRUTE -> OPTIMAL  (The Bridge — your words)
//   Q1. Which single removal helps MOST, and where does a too-big digit hurt most — a HIGH place
//       or a low place? ->
//   Q2. Scanning left->right, when a digit is SMALLER than the one before it, what do you do to
//       that bigger one (while k remains)? which stack monotonicity is that? ->
//   Q3. The 3 end-traps: k still > 0 after the pass? leading zeros? everything removed? ->
//   My derivation: ->

// BRUTE ORACLE — fill FIRST. Try ALL keep-(n-k) subsequences (preserve order), return the smallest.
//   Exponential — fine for the tiny stress sizes. Strip leading zeros; empty -> "0".
class SolutionBrute {
public:
    string removeKdigits(string num, int k) {
        // TODO (boss): brute-force every keep-(n-k) subsequence, return the min — oracle.
        return "";
    }
};

// STRESS — brute is the oracle. Small n so the exponential brute stays cheap.
int main() {
    Solution opt; SolutionBrute bru;
    vector<pair<string,int>> ex = {{"1432219",3}, {"10200",1}, {"10",2}, {"112",1}, {"1234567890",9}};
    for (auto& pr : ex) {
        string o = opt.removeKdigits(pr.first, pr.second), r = bru.removeKdigits(pr.first, pr.second);
        printf("\"%s\"  %s\n", o.c_str(), (o == r) ? "" : " <-- MISMATCH vs oracle");
    }
    unsigned seed = 2024;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    for (int t = 0; t < 50000; ++t) {
        int n = 1 + rnd() % 7;
        string num;
        for (int i = 0; i < n; ++i) num += char('0' + rnd() % 10);
        int k = 1 + rnd() % n;  // 1..n
        if (opt.removeKdigits(num, k) != bru.removeKdigits(num, k)) {
            printf("STRESS MISMATCH on \"%s\", k=%d\n", num.c_str(), k); return 1;
        }
    }
    printf("stress: 50k cases passed\n");
    return 0;
}
