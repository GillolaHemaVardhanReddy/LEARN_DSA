// LC 875 — Koko Eating Bananas  ·  SEARCH ON THE ANSWER (lo/hi are VALUES)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // knobs: range [1, max(pile)] (VALUES); feasible(k)= sum(ceil(pile/k)) <= h;
        // feasible -> ans=mid, hi=mid-1 (smaller k); else lo=mid+1. Use long long for the sum!
        // YOUR CODE HERE
        return 0;
    }
};

int main() {
    Solution sol;
    vector<int> a = {3,6,7,11};
    cout << sol.minEatingSpeed(a, 8) << "  (expect 4)\n";
    vector<int> b = {30,11,23,4,20};
    cout << sol.minEatingSpeed(b, 5) << "  (expect 30)\n";
    cout << sol.minEatingSpeed(b, 6) << "  (expect 23)\n";
    return 0;
}
