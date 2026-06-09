// LC 283 — Move Zeroes  ·  easy  ·  SOLO (fast/slow write pointer)
// Move all 0s to the end IN PLACE, keep relative order of non-zeros. Do not copy the array.
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // cue: ___ -> two pointers, which shape?
        int n = nums.size();
        int s = 0 , e = 1;
        if(n==1) return;
        while(e<n){
            while(nums[e]==0) e++;
            if(nums[s]!=0) s++;
            else {
                int temp = nums[e];
                nums[e] = nums[s];
                nums[s] = temp;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> a = {0,1,0,3,12};
    sol.moveZeroes(a);
    cout << "["; for (int x : a) cout << x << " "; cout << "]  (expect 1 3 12 0 0)\n";
    return 0;
}
