// See notes.md for the statement + your thinking.
// Workflow: fill notes.md steps 1-4 BEFORE you open LINKS.md / paste the signature.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Paste the exact method signature from the LeetCode link (LINKS.md), implement here.
    int maxVowels(string s, int k) {
        int n = s.length(), ans = 0, sum = 0;
        unordered_set<char> ch;
        ch.insert({'a', 'e', 'i','o', 'u'});
        for(int i = 0 ; i < k; i++) {
            if(ch.count(s[i])){
                sum++;
            }
        }
        ans = max(ans, sum);
        
        for(int i = k; i < n; i++){
            if(ch.count(s[i-k])) sum--;
            if(ch.count(s[i])) sum++;
            ans = max(ans, sum);
        }
        return ans;
    }
};

// ---------- local test harness (optional) — build the example and print the result ----------
int main() {
    Solution sol;
    // Example: construct the input from notes.md and call your method, e.g.:
    //   vector<int> nums = {2, 7, 11, 15};
    //   auto r = sol.yourMethod(nums, 9);
    //   for (auto x : r) cout << x << ' ';
    //   cout << '\n';
    return 0;
}
