// LC 643 — Maximum Average Subarray I  (Fixed Sliding Window)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // ───── YOUR CODE HERE ─────
        double max_avg = -99999999;
        int n = nums.size();
        int sum = 0;
        for(int i = 0 ; i < k ; i++ ) {
            sum+=nums[i];
        }
        max_avg = max(max_avg, double(sum)/k);
        for(int i = k; i < n; i++) {
            sum = sum - nums[i - k] + nums[i];
            max_avg = max(max_avg, double(sum)/k);
        }
        return max_avg; // replace
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    vector<int> a = {1, 12, -5, -6, 50, 3};
    cout << sol.findMaxAverage(a, 4) << "  (expect 12.75)\n";
    vector<int> b = {5};
    cout << sol.findMaxAverage(b, 1) << "  (expect 5)\n";
    return 0;
}
