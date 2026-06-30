// See notes.md for the statement + your thinking.
// Workflow: fill notes.md steps 1-4 BEFORE you open LINKS.md / paste the signature.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
};

// ---------- local test harness (optional) — build the example and print the result ----------
int main() {
    Solution sol;
    // Example: construct the input from notes.md and call your method, e.g.:
    //   vector<int> nums = {2, 7, 11, 15};
    //   auto r = sol.yourMethod(nums, 9);
    //   for (auto x : r) cout << x << ' ';
    //   cout << '\n';

    int mySqrt(int x) {
        int lo = 0, hi = x, ans = 0;
        while(lo<=hi){
            int mid = lo + (hi - lo)/2;
            long long check = (long long)mid*mid;
            if(check > x) hi = mid - 1;
            else if(check < x) {
                lo = mid + 1;
                ans = max(ans, mid);
            } else {
                ans = mid;
                break;
            }
        }
        // for(int i = lo; i <= hi; i++) {
        //     if((long long)i*i > x) break;
        //     else if((long long)i*i < x) {
        //         ans = max(ans, i);
        //     } else return i;
        // }
        return ans;
    }
}
