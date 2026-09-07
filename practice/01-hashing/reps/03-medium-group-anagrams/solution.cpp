// LC 49 — Group Anagrams  (Hash map keyed by a canonical signature)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // ───── YOUR CODE HERE ─────
        vector<vector<string>> v;
        // unordered_map<string, int> seen;
        // for(int i = 0 ; i < strs.size(); i++) {
        //     int arr[26] = {0};
        //     for(int j = 0 ; j < strs[i].length(); j++){
        //         arr[strs[i][j] - 'a']++;
        //     }
        //     if(seen.count(strs[i])){
        //         continue;
        //     }
        //     seen[strs[i]] = 1;
        //     vector<string> ans;
        //     ans.push_back(strs[i]);
        //     for(int k = i +1 ; k < strs.size(); k++){
        //         int temp[26];
        //         copy(begin(arr), end(arr), begin(temp));
        //         if(strs[i].length() == strs[k].length()){
        //             for(int l = 0 ; l < strs[k].length(); l++){
        //                 temp[strs[k][l] - 'a']--;
        //             }
        //             int is_ans = 1;
        //             for(int l = 0; l < 26; l++ ) {
        //                 if(temp[l] != 0){
        //                     is_ans = 0;
        //                 }
        //             }
        //             if(is_ans){
        //                 seen[strs[k]] = 1;
        //                 ans.push_back(strs[k]);
        //             }
        //         }
        //     }
        //     v.push_back(ans);
        // }

        unordered_map<string, <vector<string>> groups;
        for(string word: strs){
            string key = word;
            sort(key.begin(), key.end());
            groups[key].push_back(word);
        }
        for(auto [key, bucket] : groups){
            v.push_back(bucket);
        }
        return v; // replace
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
