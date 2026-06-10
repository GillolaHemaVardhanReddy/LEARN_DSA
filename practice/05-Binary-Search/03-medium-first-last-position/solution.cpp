// LC 34 — Find First and Last Position  ·  BOTH boundaries (store-candidate twice)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // knobs: same engine twice. FIRST: on hit store + go LEFT. LAST: on hit store + go RIGHT.
        int n = a.size(), s_ind = -1, e_ind = -1, s = 0 , e = n-1;
        while(s<=e) {
            int mid = (s+e)/2;
            if(a[mid] < k) s = mid + 1;
            else if(a[mid] > k) e = mid - 1;
            else{
                s = mid;
                e = mid;
                while(s >= 0){
                    if(a[s] == k) s_ind = s;
                    else break;
                    s--;
                }
                while(e <n) {
                    if(a[e] == k) e_ind = e;
                    else break;
                    e++;
                }
                break;
            }
        }
        return {s_ind, e_ind};
    }
};

int main() {
    Solution sol;
    vector<int> a = {5,7,7,8,8,10};
    auto r1 = sol.searchRange(a, 8);  cout << "[" << r1[0] << "," << r1[1] << "]  (expect [3,4])\n";
    auto r2 = sol.searchRange(a, 6);  cout << "[" << r2[0] << "," << r2[1] << "]  (expect [-1,-1])\n";
    vector<int> b = {};
    auto r3 = sol.searchRange(b, 0);  cout << "[" << r3[0] << "," << r3[1] << "]  (expect [-1,-1])\n";
    return 0;
}
