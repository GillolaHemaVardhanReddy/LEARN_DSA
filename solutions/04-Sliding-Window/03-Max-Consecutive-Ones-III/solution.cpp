// LC 1004 — Max Consecutive Ones III  (Variable Sliding Window, LONGEST)
// L4 test — solve it solo. Paste ONLY the Solution class into LeetCode.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // ───── YOUR CODE HERE ─────
        // Longest window with at most k zeros. Expand right; while zeros > k, shrink left.
        int ans = 0;
        int n = nums.size();
        int zeros = 0;
        int left = 0;
        for(int right = 0; right<n; right++){
            if(nums[right] == 0) zeros++;
            while(zeros > k){
                if(nums[left] == 0) zeros-=1;
                left++;
            }
            ans = max(ans, right - left +1);
        }
        return ans; // replace
    }
};

// ───────── local test harness (ignore when pasting to LeetCode) ─────────
int main() {
    Solution sol;

    vector<int> a = {1,1,1,0,0,0,1,1,1,1,0};
    cout << sol.longestOnes(a, 2) << "  (expect 6)\n";

    vector<int> b = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout << sol.longestOnes(b, 3) << "  (expect 10)\n";

    return 0;
}
