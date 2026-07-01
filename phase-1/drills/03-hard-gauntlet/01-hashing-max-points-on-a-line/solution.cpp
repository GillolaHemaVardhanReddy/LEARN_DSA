// LC149 — Max Points on a Line · Hard
// https://leetcode.com/problems/max-points-on-a-line/
// HARD GAUNTLET · P1 (Hashing / geometry). Paste ONLY the Solution class. main() local.
//
// GATES: name the flavor · build your OWN hostile input · self-trace before "done".
//
//   PATTERN (name it BEFORE you code): ____________________
//   Hint: fix one anchor point, group the others by the SLOPE they make with it (hash the slope).
//   The biggest group + the anchor = most collinear. Use a REDUCED (dy/gcd, dx/gcd) pair as the key,
//   NOT a float slope (floats collide / lose precision). Vertical line = dx==0 special key.
// =============================================================================
#include <bits/stdc++.h>
using namespace std;

// OPTIMAL — anchor + slope-hash. For each anchor i, map<slopeKey,count> over j>i. Answer = max group+1.
//   slopeKey = normalize(dy, dx) by gcd, fix sign so (1,-2) and (-1,2) collapse.   Time: O(n^2)  Space: O(n)
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), maxi = INT_MIN;
        unordered_map<float , int> check;
        if(n<=2) return n;
        for(int i = 0 ; i < n ; i++ ) {
            for(int j = 0 ; j < n ; j++ ) {
                if((points[j][0] - points[i][0]) == 0) continue;
                float ans = check[((points[j][1]-points[i][1])/(points[j][0] - points[i][0]))];
                check[ans]++;
                maxi = max(maxi, check[ans]);
            }
        }
        return maxi;
    }
};

// HOW I DERIVED BRUTE -> OPTIMAL  (The Bridge — your words)
//   Q1. Three points are collinear iff the cross product (p2-p1)x(p3-p1) == 0. Why does that avoid
//       division entirely? ->
//   Q2. Brute checks every TRIPLE (O(n^3)). Fixing one anchor, what single number do the other points
//       SHARE iff they're on the same line through the anchor? ->
//   Q3. Why hash a reduced (dy,dx) pair instead of the double dy/dx? ->
//   My derivation: ->

// BRUTE ORACLE — fill FIRST. For each pair (i,j), count points collinear with them via cross product. O(n^3).
class SolutionBrute {
public:
    pair<int, int> getabc(vector<int> point1, vector<int> point2){
        vector<int> ans;
        if((point2[0] - point1[0]) == 0) return {0, 0};
        int m = ((point2[1] - point1[1])/(point2[0] - point1[0]));
        // y - mx = y1 - mx1
        int c = point1[1] - m * point1[0];
        return {m, c};
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), maxi = INT_MIN;
        if(n<=2) return n;
        for(int i = 0 ; i < n ; i++ ) {
            for(int j = i+1 ; j < n ; j++ ) {
                int ans = 0;
                for(int k = 0 ; k < n ; k++ ) {
                    int check = ((points[j][0]-points[i][0])*(points[k][1] - points[i][1]))-((points[j][1]-points[i][1])*(points[k][0] - points[i][0]));
                    if(!(check)){
                        ans++;
                    }
                }
                maxi = max(maxi, ans);
            }
        }
        return maxi;
    }
};

// STRESS — brute is the oracle. Meaningful once BOTH classes are filled. (points are distinct.)
int main() {
    Solution opt; SolutionBrute bru;
    vector<vector<vector<int>>> ex = {{{1,1},{2,2},{3,3}}, {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}}, {{0,0}}};
    for (auto v : ex) {
        int o = opt.maxPoints(v), r = bru.maxPoints(v);
        printf("%d  %s\n", o, (o==r) ? "" : " <-- MISMATCH vs oracle");
    }
    unsigned seed = 149;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    for (int t = 0; t < 20000; ++t) {
        int n = 1 + rnd()%6;
        set<pair<int,int>> used; vector<vector<int>> v;
        while ((int)v.size() < n) {                       // keep points distinct
            int x = rnd()%5, y = rnd()%5;
            if (used.insert({x,y}).second) v.push_back({x,y});
        }
        if (opt.maxPoints(v) != bru.maxPoints(v)) {
            printf("STRESS MISMATCH on: ");
            for (auto& q:v) printf("(%d,%d) ", q[0],q[1]); printf("\n"); return 1;
        }
    }
    printf("stress: 20k cases passed\n");
    return 0;
}
