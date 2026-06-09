// LC 35 — Search Insert Position  ·  LOWER BOUND (store-candidate)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // knobs: cond nums[mid]>=target -> ans=mid, hi=mid-1 (look left); else lo=mid+1; default ans=n
        // YOUR CODE HERE
        return 0;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1,3,5,6};
    cout << sol.searchInsert(a, 5) << "  (expect 2)\n";
    cout << sol.searchInsert(a, 2) << "  (expect 1)\n";
    cout << sol.searchInsert(a, 7) << "  (expect 4)\n";
    cout << sol.searchInsert(a, 0) << "  (expect 0)\n";
    return 0;
}
