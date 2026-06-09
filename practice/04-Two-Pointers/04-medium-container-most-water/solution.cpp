// LC 11 — Container With Most Water  ·  GREEDY converging (move the shorter wall)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // cue: max area between two lines -> converging two pointers, move the SHORTER wall
        int n = height.size();
        int L = 0 , R = n-1, max_ans = 0;
        while(L < R){
            max_ans = max(max_ans, (min(height[L], height[R])*(R-L)));
            if(height[L] < height[R]){
                L++;
            } else {
                R--;
            }
        }
        return max_ans;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1,8,6,2,5,4,8,3,7};
    cout << sol.maxArea(a) << "  (expect 49)\n";
    vector<int> b = {1,1};
    cout << sol.maxArea(b) << "  (expect 1)\n";
    return 0;
}
