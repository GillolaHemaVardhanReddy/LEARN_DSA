// LC51 — N-Queens   (HARD · ⭐ backtracking: CONSTRAINT SETS + real pruning)
//                                                        ·  M10 LEARN — rep 7 (stretch)
// ---------------------------------------------------------------------
// Place n queens on an n x n board so that no two attack each other. Return all distinct
// solutions. Each solution is a board: n strings of 'Q' and '.'.
//   Constraints: 1 <= n <= 9.
//   URL: https://leetcode.com/problems/n-queens/
//
// NEW IDEA: the undoable state isn't just the path — it's a set of CONSTRAINTS
//           (columns used, diagonals used). Every one of them must be un-marked on return.
//           This is where "partial undo" (notes, trap #2) will bite you if it's going to.
//   Striver [L14] — https://youtu.be/i05Ju7AftcM   (watch AFTER your attempt)
// =====================================================================
#include <bits/stdc++.h>
using namespace std;

// 1) BRUTE — the oracle. NO recursion, NO shared constraint sets (M#9).
//    KEY OBSERVATION (derive this before coding): exactly one queen per row, and exactly one
//    per column. So ANY solution is a PERMUTATION of columns: perm[r] = the column in row r.
//    Idea: sort {0..n-1}, walk std::next_permutation over all n! arrangements, and for each,
//          check only the DIAGONALS: rows i,j clash iff |i-j| == |perm[i]-perm[j]|.
//          n<=9 => 362,880 permutations. Fast enough.
//    Time: O(n! * n^2)   Space: O(output)
vector<vector<string>> solveNQueensBrute(int n) {
    // TODO(boss): next_permutation loop; diagonal check; render each valid perm as n strings.
    return {};
}

// 2) BRIDGE
//    Q1: the brute already proved "one queen per row." So a FRAME here = one ROW, and its
//        choices are the n columns. Write the frame's loop header and its base case.
//    >>> your words:
//
//    Q2: the brute re-checks all O(n^2) pairs for every one of the n! permutations. That is
//        the repeated work. A backtracker instead REJECTS a bad column the moment it's placed.
//        To do that in O(1) you need to answer "is this square attacked?" without scanning.
//        You need three memberships. Name them:
//          (a) column c already used?
//          (b) the ↘ diagonal through (r,c) already used?   ← what is CONSTANT along it?
//          (c) the ↙ anti-diagonal through (r,c) already used? ← what is CONSTANT along it?
//        (Hint modality if stuck: draw a 4x4 grid, write r-c in every cell, then r+c. Look.)
//    >>> your words:
//
//    Q3: `r - c` can be negative. If you index an array with it, what happens?
//        What's the offset that fixes it, and how big must the array be?
//        (This is the boundary/index leak wearing a new hat. Name the guard BEFORE you code.)
//    >>> your words:
//
//    Q4: your un-choose here restores FOUR things, not one. List them.
//        Then say what symptom you'd see if you forgot exactly one. (Predict it — then, if the
//        stress fires, check whether you predicted the right symptom.)
//    >>> your words:
//
//    Q5: complexity. Is this polynomial now that you prune? Answer honestly, in one sentence.
//    >>> your words:
//
// 3) OPTIMAL — backtracking row by row with O(1) constraint checks.
//    Time: O(?)   Space: O(?)  (excluding output)
vector<vector<string>> solveNQueens(int n) {
    // TODO(boss): cols[n], diag[2n-1], anti[2n-1]  (index them per your Q2/Q3 answers).
    //             solve(r): r == n → render `pos` into strings and emit.
    //             for c in 0..n-1: if attacked → continue.  mark 3 sets + pos[r]=c
    //                              → solve(r+1) → unmark ALL of them.
    return {};
}

// ---------------------------------------------------------------------
// Normalizer (DO NOT edit): sorts the collection of boards.
vector<vector<string>> normalized(vector<vector<string>> v) {
    sort(v.begin(), v.end());
    return v;
}

// 4) STRESS: brute IS the oracle. The known counts are a THIRD, independent check.
int main() {
    // The number of n-queens solutions (OEIS A000170) — a fact neither implementation can fake.
    int known[10] = {1, 1, 0, 0, 2, 10, 4, 40, 92, 352};

    for (int n = 1; n <= 9; n++) {
        auto bru = normalized(solveNQueensBrute(n));
        auto opt = normalized(solveNQueens(n));

        if ((int)opt.size() != known[n]) {
            printf("COUNT FAIL n=%d: got %zu solutions, want %d\n", n, opt.size(), known[n]);
            return 1;
        }
        if (bru != opt) {
            printf("MISMATCH n=%d: brute %zu vs optimal %zu\n", n, bru.size(), opt.size());
            return 1;
        }
        // shape check: n rows, each n chars, exactly one 'Q' per row
        for (auto& board : opt) {
            if ((int)board.size() != n) { printf("SHAPE FAIL n=%d: %zu rows\n", n, board.size()); return 1; }
            for (auto& row : board) {
                if ((int)row.size() != n || count(row.begin(), row.end(), 'Q') != 1) {
                    printf("SHAPE FAIL n=%d: bad row \"%s\"\n", n, row.c_str());
                    return 1;
                }
            }
        }
    }
    printf("all n-queens cases passed (n=1..9)\n");
    return 0;
}
