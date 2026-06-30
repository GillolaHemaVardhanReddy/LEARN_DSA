// LC 523 — Continuous Subarray Sum  (Prefix + remainder + hash, length >= 2)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // ───── YOUR CODE HERE ─────
        // map: remainder -> FIRST index. seen[0] = -1. running sum, rem = sum % k.
        // if rem seen before AND (i - firstIndex) >= 2 -> true.
        int sum = 0;
        int n = nums.size();
        int count = 0;
        vector<int> prefix;
        map<int, int> seen;
        seen[0] = -1;
        for(int i = 0; i < n ; i++ ) {
            sum += nums[i];
            prefix.push_back(sum);
            int rem = prefix[i]%k;
            if(seen.count(rem)){
                if(i - seen[rem] >= 2) return true;
            } else {
                seen[rem] = i ;
            }
        }
        // brute force approach
        // for(int i = 0 ; i < n ; i++ ) {
        //     for ( int j = 0 ; j < i; j++ ) {
        //         int left = 0;
        //         if(j != 0 ) left = prefix[j-1];
        //         if((((prefix[i] - left) % k) == 0) && (i - j + 1 >=2)) {
        //             cout << i << " " << j << endl;
        //             return true; 
        //         }
        //     }
        // }

        // approach to reduce the inner scan 
        /*
            each time we check (p[r] - p[l-1]) % k == 0 or not so how can we just check this in O(1)
            to get reminder of it to be zero both numerator terms should also have reminder 0 meaning p[r]%k == p[l-1]%k
            we need to store the prefix, index
        */
        return false; // replace
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    vector<int> a = {23, 2, 4, 6, 7};
    cout << sol.checkSubarraySum(a, 6) << "  (expect 1)\n";
    vector<int> b = {23, 2, 6, 4, 7};
    cout << sol.checkSubarraySum(b, 6) << "  (expect 1)\n";
    vector<int> c = {23, 2, 6, 4, 7};
    cout << sol.checkSubarraySum(c, 13) << "  (expect 0)\n";
    return 0;
}
