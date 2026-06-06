// LC 49 — Group Anagrams  (Hash map keyed by a canonical signature)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // ───── YOUR CODE HERE ─────
        // unordered_map<string, vector<string>>: key = sorted word (or 26-count signature).
        return {}; // replace
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    vector<string> a = {"eat","tea","tan","ate","nat","bat"};
    for (auto& g : sol.groupAnagrams(a)) {
        cout << "[ "; for (auto& w : g) cout << w << " "; cout << "] ";
    }
    cout << "  (expect 3 groups: eat/tea/ate, tan/nat, bat)\n";
    return 0;
}
