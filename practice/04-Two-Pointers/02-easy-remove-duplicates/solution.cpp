// LC 26 — Remove Duplicates from Sorted Array  ·  FAST/SLOW (write pointer)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // cue: in-place rearrange sorted array -> fast/slow write pointer
        // slow 'write' marks next unique slot; fast 'read' scans ahead.
        return 0;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1,1,2};
    int k1 = sol.removeDuplicates(a);
    cout << k1 << "  (expect 2) -> "; for (int i = 0; i < k1; i++) cout << a[i] << " "; cout << "\n";
    vector<int> b = {0,0,1,1,1,2,2,3,3,4};
    int k2 = sol.removeDuplicates(b);
    cout << k2 << "  (expect 5) -> "; for (int i = 0; i < k2; i++) cout << b[i] << " "; cout << "\n";
    return 0;
}
