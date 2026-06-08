// LC 1004 — Max Consecutive Ones III  (Variable Window, LONGEST)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // YOUR CODE HERE.
        int left = 0, n = nums.size(), zeros = 0, ones = 0, ans = 0;
        for(int right = 0 ; right < n; right++) {
            nums[right] == 0 ? zeros++ : ones++;
            while(zeros > k){
                nums[left] == 0 ? zeros-- : ones--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    vector<int> a = {1,1,1,0,0,0,1,1,1,1,0};
    vector<int> b = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout << sol.longestOnes(a, 2) << "  (expect 6)\n";
    cout << sol.longestOnes(b, 3) << "  (expect 10)\n";
    return 0;
}
