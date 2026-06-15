// See notes.md for the statement + your thinking.
// Workflow: fill notes.md steps 1-4 BEFORE you open LINKS.md / paste the signature.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Paste the exact method signature from the LeetCode link (LINKS.md), implement here.
    int characterReplacement(string s, int k) {
        int ans = 0, n = s.length(), l = 0 , r = 0, max_freq = 0;
        int arr[26] = {0};
        while(r<n){
            arr[s[r]-'A']++;
            int wind_size = r - l + 1;
            max_freq = max(max_freq, arr[s[r]-'A']);
            if(wind_size - max_freq <= k) {
                ans = max(ans, wind_size);
            } else {
                arr[s[l]-'A']--;
                wind_size--;
                l++;
            }
            r++;
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
