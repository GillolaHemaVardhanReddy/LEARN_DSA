// LC 724 — Find Pivot Index  (Pure Prefix Sum, no hash)
// Paste ONLY the Solution class into LeetCode. main() is for local testing on onlinegdb.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // ───── YOUR CODE HERE ─────
        // total = sum of all; sweep i, keep leftSum.
        // rightSum = total - leftSum - nums[i].  If leftSum == rightSum -> return i.
        // Add nums[i] to leftSum AFTER the check.
        int n = nums.size();
        int sum = 0;
        vector<int> prefix;
        for(int i = 0 ; i < n ; i++){
            sum+=nums[i];
            prefix.push_back(sum);
        }
        for(int i = 0 ; i < n ; i++){
            int left_sum, right_sum;
            if(i == 0){
                left_sum = 0;
                right_sum = prefix[n-1] - prefix[0];
            }else if(i == n-1){
                right_sum = 0;
                left_sum = prefix[i-1];
            } else {
                left_sum = prefix[i-1];
                right_sum = prefix[n-1] - prefix[i];
            }
            if(right_sum == left_sum) return i;
        }
        return -1; // replace
    }
};

// ───────── local test harness (ignore when pasting to LeetCode) ─────────
int main() {
    Solution sol;

    vector<int> a = {1, 7, 3, 6, 5, 6};
    cout << sol.pivotIndex(a) << "  (expect 3)\n";

    vector<int> b = {1, 2, 3};
    cout << sol.pivotIndex(b) << "  (expect -1)\n";

    vector<int> c = {2, 1, -1};
    cout << sol.pivotIndex(c) << "  (expect 0)\n";

    return 0;
}
