// See notes.md for the statement + your thinking.
// Workflow: fill notes.md steps 1-4 BEFORE you open LINKS.md / paste the signature.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Paste the exact method signature from the LeetCode link (LINKS.md), implement here.
    int largestAltitude(vector<int>& gain) {
        int n = gain.size(), sum = 0, ans = 0;
        for(int i = 0 ; i < n; i++){
            ans = min(gain[i], ans);
        }
        for(int i = 0 ; i < n; i++){
            sum+=gain[i];
            ans = max(ans, sum);
        }
        return ans < 0 ? 0 : ans;
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
