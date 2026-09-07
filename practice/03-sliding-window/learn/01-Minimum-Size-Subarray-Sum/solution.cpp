// LC 209 — Minimum Size Subarray Sum  (Variable Sliding Window)
// Write your solution inside the Solution class.
// Paste ONLY the Solution class into LeetCode. The main() below is just so you
// can run + test locally on onlinegdb before submitting.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // ───── YOUR CODE HERE ─────
        // Caterpillar: expand right, shrink left while the window is valid.
        // (No algorithm steps spelled out on purpose — code it from understanding.)

        int ans = nums.size()+100;
        int sum = 0;
        int start_ind = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] >= target) return 1;
            sum += nums[i];
            while(sum >= target){
                if(i+1 - start_ind < ans) ans = i + 1 - start_ind;
                sum -= nums[start_ind];
                start_ind += 1;
            }
        }
        int final_ans = ans == nums.size()+100 ? 0 : ans;
        return final_ans; // replace
    }
};

// ───────── local test harness (ignore when pasting to LeetCode) ─────────
int main() {
    Solution sol;

    vector<int> a = {2, 3, 1, 2, 4, 3};
    cout << sol.minSubArrayLen(7, a)  << "  (expect 2)\n";

    vector<int> b = {1, 4, 4};
    cout << sol.minSubArrayLen(4, b)  << "  (expect 1)\n";

    vector<int> c = {1, 1, 1, 1, 1};
    cout << sol.minSubArrayLen(11, c) << "  (expect 0)\n";

    return 0;
}
