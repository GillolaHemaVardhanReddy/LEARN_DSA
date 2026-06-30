// LC 128 — Longest Consecutive Sequence  (Hash set, O(n))
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // ───── YOUR CODE HERE ─────
        // sort(nums.begin(), nums.end());
        // int max_ans = 1, longest = 1;
        // for(int i = 1 ; i < nums.size()-1; i++) {
        //     if(nums[i] == nums[i-1]) continue;
        //     else if(nums[i] == nums[i-1]+1) max_ans++;
        //     else max_ans = 1;
        //     longest = max(max_ans,longest);
        // }
        // return longest; // replace


        unordered_set<int> s(nums.begin(), nums.end());   // O(n) build, dedups for free
        int longest = 0;
        for (int x : s) {
            if (s.count(x - 1)) continue;       // not a start → skip
            int cur = x, len = 1;               // x is a sequence start
            while (s.count(cur + 1)) { cur++; len++; }   // walk the run forward
            longest = max(longest, len);
        }
        return longest;
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    vector<int> a = {100, 4, 200, 1, 3, 2};
    cout << sol.longestConsecutive(a) << "  (expect 4)\n";
    vector<int> b = {0,3,7,2,5,8,4,6,0,1};
    cout << sol.longestConsecutive(b) << "  (expect 9)\n";
    return 0;
}
