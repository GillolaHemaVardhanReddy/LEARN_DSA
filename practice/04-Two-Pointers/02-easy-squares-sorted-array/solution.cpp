// LC 977 — Squares of a Sorted Array  ·  CONVERGING (compare ends, fill from back)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // cue: sorted, largest squares at the ENDS -> converging two pointers
        int n = nums.size(), start = 0 , end = n-1;
        vector<int> ans(n);
        int insert = n-1;
        while(start < end && insert >=0) {
            cout<< abs(nums[start]) << " " << abs(nums[end]) << "\n";
            if(abs(nums[start]) > abs(nums[end])){
                ans[insert] = nums[start] * nums[start];
                start++;
                insert--;
            } else if(abs(nums[start]) < abs(nums[end])) {
                ans[insert] = nums[end] * nums[end];
                end--;
                insert--;
            } else {
                ans[insert] = nums[end] * nums[end];
                ans[insert-1] = nums[end] * nums[end];
                insert-=2;
                start++;
                end--;
            }
        }
        if(start==end){
            ans[insert] = nums[start] * nums[end];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> a = {-4,-1,0,3,10};
    auto r1 = sol.sortedSquares(a);
    cout << "["; for (int x : r1) cout << x << " "; cout << "]  (expect 0 1 9 16 100)\n";
    vector<int> b = {-7,-3,2,3,11};
    auto r2 = sol.sortedSquares(b);
    cout << "["; for (int x : r2) cout << x << " "; cout << "]  (expect 4 9 9 49 121)\n";
    return 0;
}
