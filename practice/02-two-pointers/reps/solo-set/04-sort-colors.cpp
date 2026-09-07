// LC 75 — Sort Colors  ·  MEDIUM  ·  SOLO (Dutch National Flag, 3-way partition) — L4 gate
// Array of 0s, 1s, 2s. Sort IN PLACE in one pass, O(1) space. (Don't just count-and-overwrite — try the 3-pointer way.)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // cue: 3 distinct values, partition in place -> low/mid/high pointers (Dutch flag)
        int n = a.size(), j = n-1;
        for(int i = 0 ; i < n-1; i++){
            j = n-1;
            while(i < j) {
                if(a[i] > a[j]){
                    int temp = a[j];
                    a[j] = a[i];
                    a[i] = temp;
                }
                j--;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> a = {2,0,2,1,1,0};
    sol.sortColors(a);
    cout << "["; for (int x : a) cout << x << " "; cout << "]  (expect 0 0 1 1 2 2)\n";
    return 0;
}
