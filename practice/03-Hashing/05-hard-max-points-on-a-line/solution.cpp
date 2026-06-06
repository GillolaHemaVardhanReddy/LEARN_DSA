// LC 149 — Max Points on a Line  (Hash map of slopes)  ·  STRETCH
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // ───── YOUR CODE HERE ─────
        // for each anchor A: map<slopeKey,int>. slopeKey = reduced (dy/g, dx/g) to avoid float error.
        // answer = max bucket + 1 (the anchor). Handle n==1.
        return 0; // replace
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    vector<vector<int>> a = {{1,1},{2,2},{3,3}};
    cout << sol.maxPoints(a) << "  (expect 3)\n";
    vector<vector<int>> b = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout << sol.maxPoints(b) << "  (expect 4)\n";
    return 0;
}
