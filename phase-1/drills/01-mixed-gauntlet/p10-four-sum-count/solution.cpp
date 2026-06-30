// See notes.md for the statement + your thinking.
// Workflow: fill notes.md steps 1-4 BEFORE you open LINKS.md / paste the signature.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Paste the exact method signature from the LeetCode link (LINKS.md), implement here.
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size(), ans = 0;
        // TLE
        // for(int i = 0 ; i < n ; i++) {
        //     for(int j = 0 ; j < n ; j++){
        //         for(int k = 0 ; k < n ; k++){
        //             for(int l = 0 ; l < n ;l++){
        //                 if((long long)(nums1[i]+nums2[j]+nums3[k]+nums4[l]) == 0){
        //                     ans++;
        //                 }
        //             }
        //         }
        //     }
        // }

        //optimal
        unordered_map<long long, int> sum1;
        for(int i = 0 ; i < n ; i++ ) {
            for(int j = 0 ; j < n ; j++ ) {
                sum1[(long long)(nums1[i]+nums2[j])]++;
            }
        } 
        for(int k = 0 ; k < n ; k++ ) {
            for(int l = 0; l<n ; l++) {
                long long t = (long long)(nums3[k]+nums4[l]);
                if(sum1.count(-t)){
                    ans+=sum1[-t];
                }
            }
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
