// See notes.md for the statement + your thinking.
// Workflow: fill notes.md steps 1-4 BEFORE you open LINKS.md / paste the signature.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Paste the exact method signature from the LeetCode link (LINKS.md), implement here.
    bool canConstruct(string ransomNote, string magazine) {
        int n = magazine.length(), m = ransomNote.length();
        char arr[26] = {0};
        for(int i = 0 ; i < m; i++){
            arr[ransomNote[i]-'a']++;
        }
        for(int i = 0 ; i < n ; i++){
            if(arr[magazine[i]-'a']){
                arr[magazine[i]-'a']--;
            }
        }
        for(int i = 0 ; i < m; i++){
            if(arr[ransomNote[i]-'a']){
                return false;
            }
        }
        return true;
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
