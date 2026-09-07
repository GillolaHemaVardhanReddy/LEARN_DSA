// LC 1480 — Running Sum of 1d Array  (Prefix Sum)
// Paste ONLY the Solution class into LeetCode. main() is for local testing on onlinegdb.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // ───── YOUR CODE HERE ─────
        vector <int> prefix;
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++ ) {
            sum += nums[i];
            prefix.push_back(sum);
        }
        return prefix;
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    vector<int> a = {1, 2, 3, 4};
    for (int x : sol.runningSum(a)) cout << x << " ";
    cout << "  (expect 1 3 6 10)\n";
    vector<int> b = {3, 1, 2, 10, 1};
    for (int x : sol.runningSum(b)) cout << x << " ";
    cout << "  (expect 3 4 6 16 17)\n";
    return 0;
}
