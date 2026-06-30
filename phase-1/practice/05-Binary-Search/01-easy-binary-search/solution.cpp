// LC 704 — Binary Search  ·  EXACT search (core template)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& a, int k) {
        // knobs: cond nums[mid] vs target; move lo=mid+1 / hi=mid-1; range [0,n-1] lo<=hi; return index or -1
        int s = 0, e = a.size()-1, ans = -1;
        if(s==e){
            if(a[s]==k) return 0;
            else return -1;
        }
        while(s<=e){
            int mid = (e+s)/2;
            if(a[mid] > k) e = mid-1;
            else if(a[mid] < k) s = mid+1;
            else {
                ans = mid;
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> a = {-1,0,3,5,9,12};
    cout << sol.search(a, 9) << "  (expect 4)\n";
    cout << sol.search(a, 2) << "  (expect -1)\n";
    return 0;
}
