// See notes.md for the statement + your thinking.
// Workflow: fill notes.md steps 1-4 BEFORE you open LINKS.md / paste the signature.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Paste the exact method signature from the LeetCode link (LINKS.md), implement here.
    int search(vector<int>& nums, int target) {
        int n = nums.size(), lo = 0, hi = n-1;
        while (lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target) return mid;
            if(nums[lo] <= nums[mid]){          // LEFT half is the sorted one
                if(nums[lo] <= target && target < nums[mid])   // target inside left's range?
                    hi = mid - 1;              // go left
                else
                    lo = mid + 1;                 // go right
            }
            else{                               // RIGHT half is the sorted one
                if(nums[mid] < target && target <= nums[hi]) // target inside right's range?
                    lo = mid + 1;                 // go right
                else
                    hi = mid - 1;                 // go left
            }
        }
        return -1;
    }
};

// ---------- local test harness (optional) — build the example and print the result ----------
int main() {
    Solution sol;
    // Example: construct the input from notes.md and call your method, e.g.:
    //   vector<int> nums = {2, 7, 11, 15};
    //   auto r = sol.yourMethod(nums, 9);
    //   for (auto x : r) cout << x << ' ';
    //   cout << '\n';
    return 0;
}
