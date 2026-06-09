// LC 35 — Search Insert Position  ·  LOWER BOUND (store-candidate)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& a, int k) {
        // knobs: cond nums[mid]>=target -> ans=mid, hi=mid-1 (look left); else lo=mid+1; default ans=n
        // lower bound 
        int n = a.size(), s = 0, e = n-1, ans = 0, mid;
        while(s<=e){
            if(s==e){
                if(k > a[s]) return s+1;
                else if(k<a[s]) return s;
            }
            mid = (s+e)/2;
            if(a[mid] > k) e = mid - 1;
            else if(a[mid] < k) s = mid + 1;
            else {
                return mid;
            }
        }
        return mid;
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
