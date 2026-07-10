// LC131 — Palindrome Partitioning   (MEDIUM · ⭐ backtracking: choices = WHERE TO CUT)
//                                                              ·  M10 LEARN — rep 5
// ---------------------------------------------------------------------
// Given a string `s`, partition it so that EVERY substring of the partition is a
// palindrome. Return all possible palindrome partitionings.
//   Constraints: 1 <= s.length() <= 16,  s contains only lowercase letters.
//   URL: https://leetcode.com/problems/palindrome-partitioning/
//
// NEW IDEA: a "choice" is no longer an ELEMENT — it's a RANGE. At position `start`,
//           the choices are: cut after 1 char, after 2 chars, ... after (n-start) chars.
//   Striver [L17] — https://youtu.be/WBgsABoClE0   (watch AFTER your attempt)
// =====================================================================
#include <bits/stdc++.h>
using namespace std;

bool isPal(const string& s, int l, int r) {           // helper, given to you
    while (l < r) if (s[l++] != s[r--]) return false;
    return true;
}

// 1) BRUTE — the oracle. NO recursion (M#9: different machinery than the optimal).
//    Idea: there are n-1 gaps between characters. Each gap is either a CUT or not
//          => 2^(n-1) possible partitions, one per bitmask. n<=16 so 2^15 = 32768, fine.
//    For each mask: slice s at the chosen gaps, check EVERY piece is a palindrome, keep if so.
//    Time: O(2^n * n)   Space: O(output)
vector<vector<string>> partitionBrute(string s) {
    // TODO(boss): loop mask over 0..(1<<(n-1))-1. Bit g set => cut between s[g] and s[g+1].
    //             Build the pieces, verify each with isPal, push if all pass.
    return {};
}

// 2) BRIDGE
//    Q1: in LC46 a frame asked "what goes in slot d?" and looped over VALUES.
//        Here a frame asks "where does the piece starting at `start` end?"
//        Write the loop header: `for (int end = ___; end ___; end++)`. What do the
//        bounds mean in plain words?
//    >>> your words:
//
//    Q2: not every cut is legal. Where in the loop does the palindrome check go, and what
//        does it do when it fails — `return` or `continue`? Say why the other one is wrong.
//    >>> your words:
//
//    Q3: what is `path` here? (In LC78 it was a vector<int> of chosen numbers.)
//        And what is the base case — when is a partition COMPLETE?
//    >>> your words:
//
//    Q4: the un-choose. You pushed a substring. Trace `s = "aab"` by hand: after the branch
//        that emits ["a","a","b"] returns all the way up to frame `start=0`, what must
//        `path` contain before frame 0 tries its NEXT choice (the piece "aa")?
//    >>> your words:
//
// 3) OPTIMAL — backtracking over cut positions, prune on non-palindrome.
//    Time: O(?)   Space: O(?)
vector<vector<string>> partition(string s) {
    // TODO(boss): solve(start): if start == n → emit path.
    //             loop over `end` per your Q1; skip non-palindromic pieces per Q2;
    //             choose the piece → recurse past it → un-choose.
    return {};
}

// ---------------------------------------------------------------------
// Normalizer (DO NOT edit): sorts the collection. Does NOT sort inside a partition —
// the ORDER of the pieces IS the answer (they concatenate back to s).
vector<vector<string>> normalized(vector<vector<string>> v) {
    sort(v.begin(), v.end());
    return v;
}

// 4) STRESS: brute IS the oracle.
int main() {
    // --- hardcoded edges ---
    {
        auto got = normalized(partition("aab"));      // expect ["a","a","b"] and ["aa","b"]
        auto exp = normalized(partitionBrute("aab"));
        if (got != exp || got.size() != 2) { printf("EDGE FAIL \"aab\": got %zu, want 2\n", got.size()); return 1; }

        if (normalized(partition("a")).size() != 1)   { printf("EDGE FAIL n=1\n"); return 1; }

        // every single char is a palindrome => the all-singletons partition ALWAYS exists.
        if (normalized(partition("abcd")).size() != 1) { printf("EDGE FAIL no-pal: want only all-singletons\n"); return 1; }
    }

    // --- random stress: tiny alphabet => lots of palindromes ---
    srand(131);
    for (int it = 0; it < 5000; it++) {
        int n = rand() % 9 + 1;                       // n in [1,9]
        string s(n, 'a');
        for (char& c : s) c = 'a' + rand() % 2;        // alphabet {a,b}

        auto bru = normalized(partitionBrute(s));
        auto opt = normalized(partition(s));
        if (bru != opt) {
            printf("MISMATCH s=\"%s\" (it=%d): brute %zu vs optimal %zu\n",
                   s.c_str(), it, bru.size(), opt.size());
            return 1;
        }
    }
    printf("all palindrome-partition cases passed\n");
    return 0;
}
