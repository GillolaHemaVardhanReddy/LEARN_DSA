// LC 167 — Two Sum II (sorted)  ·  MEDIUM  ·  SOLO (pure sum-steered converging) — L4 gate
// Sorted, 1-indexed. Return [i,j] (1-based) of the pair summing to target. Exactly one solution.
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& a, int k) {
        // cue: sorted + pair by sum -> converging; sum<target -> L++, sum>target -> R--. Return 1-INDEXED.
                int n = a.size(), i = 0, j = n-1;
        while(i < j) {
            int sum = a[i] + a[j];
            if(sum > k) j--;
            else if(sum <k) i++;
            else break;
        }
        return {i+1, j+1};
    }
};

int main() {
    Solution sol;
    vector<int> a = {2,7,11,15};
    auto r1 = sol.twoSum(a, 9);  cout << r1[0] << "," << r1[1] << "  (expect 1,2)\n";
    vector<int> b = {2,3,4};
    auto r2 = sol.twoSum(b, 6);  cout << r2[0] << "," << r2[1] << "  (expect 1,3)\n";
    return 0;
}
