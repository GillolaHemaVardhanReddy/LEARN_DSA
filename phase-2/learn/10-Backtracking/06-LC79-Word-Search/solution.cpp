// LC79 — Word Search   (MEDIUM · ⭐ backtracking on a GRID)  ·  M10 LEARN — rep 6
// ---------------------------------------------------------------------
// Given an m x n grid of characters and a string `word`, return true if `word` exists
// in the grid. The word is built from letters of SEQUENTIALLY ADJACENT cells
// (horizontal / vertical neighbours). The SAME CELL MAY NOT BE USED MORE THAN ONCE.
//   Constraints: 1 <= m,n <= 6,  1 <= word.length() <= 15,  lowercase+uppercase letters.
//   URL: https://leetcode.com/problems/word-search/
//
// NEW IDEA #1: the answer is a BOOL, not a list. You short-circuit on the first success:
//              `if (solve(next)) return true;`  — you do NOT explore the whole tree.
// NEW IDEA #2: the undoable state is a `visited` grid, not a path vector.
//   Striver [L18] Rat in a Maze (the twin) — https://youtu.be/bLGZhJlt4y0
// =====================================================================
#include <bits/stdc++.h>
using namespace std;

// 1) BRUTE — the oracle. It must NOT be your backtracker (M#9).
//    Idea: an EXPLICIT-STACK search that CARRIES A COPY of its visited-set instead of
//          undoing one. State = (row, col, index-into-word, visited-bitmask).
//          m*n <= 36, so `visited` fits in a `long long` bitmask (bit r*n+c).
//          Push start states; pop; if idx == word.size() return true; else push each
//          in-bounds, unvisited, letter-matching neighbour with an UPDATED COPY of the mask.
//    This is the same SEARCH, but with copy-state instead of backtrack-state — which is
//    exactly the contrast this problem teaches. No shared mutable `visited`, no un-choose.
//    Time: exponential   Space: exponential (that's the point — the optimal fixes the SPACE)
bool existBrute(vector<vector<char>>& board, string word) {
    // TODO(boss): stack<tuple<int,int,int,long long>>; seed with every cell matching word[0].
    return false;
}

// 2) BRIDGE
//    Q1: the brute carries a fresh visited-mask into every branch. Your backtracker will share
//        ONE `visited` grid across the whole search. What does that buy you, and what does it
//        now OBLIGATE you to do? (This is your invariant, restated for a grid.)
//    >>> your words:
//
//    Q2: LC78 collected ALL answers, so every branch had to run. Here you want ONE answer.
//        Write the recursive-call line. What's different about how you use its return value?
//    >>> your words:
//
//    Q3: ⚠️ THE TRAP. Suppose your frame does:
//              visited[r][c] = true;
//              for each neighbour:  if (solve(nr, nc, idx+1)) return true;   // ← early return!
//              visited[r][c] = false;
//              return false;
//        Trace it. When the early `return true` fires, does `visited[r][c]` get restored?
//        Does that matter? Answer BOTH parts — and say what would break if the function
//        returned `void` and collected all paths instead.
//    >>> your words:
//
//    Q4: name every piece of state `make()` touches, and confirm `unmake()` restores each.
//        (Trap #2 in the notes: PARTIAL undo is the quietest bug in this topic.)
//    >>> your words:
//
// 3) OPTIMAL — DFS + backtracking, mark visited, unmark on return.
//    Time: O(?)   Space: O(?)  (excluding the board)
bool exist(vector<vector<char>>& board, string word) {
    // TODO(boss): try every cell as a start. solve(r,c,idx):
    //             base = idx == word.size() → true.  bounds/letter/visited checks → false.
    //             mark → explore 4 neighbours (short-circuit) → unmark → return.
    return false;
}

// ---------------------------------------------------------------------
// 4) STRESS: brute IS the oracle.
int main() {
    // --- hardcoded edges ---
    {
        vector<vector<char>> b = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
        if (!exist(b, "ABCCED")) { printf("EDGE FAIL: ABCCED should exist\n"); return 1; }
        if (!exist(b, "SEE"))    { printf("EDGE FAIL: SEE should exist\n"); return 1; }
        if ( exist(b, "ABCB"))   { printf("EDGE FAIL: ABCB reuses a cell — must be false\n"); return 1; }

        vector<vector<char>> one = {{'a'}};
        if (!exist(one, "a"))    { printf("EDGE FAIL 1x1 hit\n"); return 1; }
        if ( exist(one, "aa"))   { printf("EDGE FAIL 1x1 no-reuse\n"); return 1; }
    }

    // --- random stress: tiny board + tiny alphabet => real collisions ---
    srand(79);
    for (int it = 0; it < 4000; it++) {
        int m = rand() % 3 + 1, n = rand() % 3 + 1;         // up to 3x3
        vector<vector<char>> board(m, vector<char>(n));
        for (auto& row : board) for (char& c : row) c = 'a' + rand() % 2;   // {a,b}

        int L = rand() % 5 + 1;                              // word length 1..5
        string word(L, 'a');
        for (char& c : word) c = 'a' + rand() % 2;

        bool bru = existBrute(board, word);
        bool opt = exist(board, word);
        if (bru != opt) {
            printf("MISMATCH it=%d word=\"%s\" board=", it, word.c_str());
            for (auto& row : board) { for (char c : row) putchar(c); putchar('/'); }
            printf("  brute=%d optimal=%d\n", (int)bru, (int)opt);
            return 1;
        }
    }
    printf("all word-search cases passed\n");
    return 0;
}
