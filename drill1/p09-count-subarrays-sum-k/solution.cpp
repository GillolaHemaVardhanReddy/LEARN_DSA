// See notes.md for the statement + your thinking.
// Workflow: fill notes.md steps 1-4 BEFORE you open LINKS.md / paste the signature.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Paste the exact method signature from the LeetCode link (LINKS.md), implement here.
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, ans = 0;
        vector<int> prefix;
        unordered_map<int, int> seen;
        seen[0] = 1;
        for(int i = 0 ; i < n; i++){
            sum+=nums[i];
            if(seen.count(sum - k)) ans+=seen[sum - k];
            seen[sum]++;
        }
        return ans;
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
