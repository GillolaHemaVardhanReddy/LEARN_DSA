// LC 49 — Group Anagrams  ·  +7d COLD RE-SOLVE  ·  2026-10-03  ·  3rd pass
// First solve 09-27 (AC) · +1d card 09-28 (cold, unaided) · this = the +7d rung.
// Blank file on purpose. Do not open LC49-group-anagrams.cpp.
//
//   ["eat","tea","tan","ate","nat","bat"] -> [["bat"],["nat","tan"],["ate","eat","tea"]]
//   [""]                                  -> [[""]]
//   ["a"]                                 -> [["a"]]
//
// 1 <= strs.length <= 10^4 · 0 <= strs[i].length <= 100 · lowercase only

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<string> sorted;
        unordered_map<string, vector<string>> check;
        for(int i = 0 ; i < n ; i++ ) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            sorted.push_back(temp);
            check[sorted[i]].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto& [k,v]: check) {
            ans.push_back(v);
        }
        return ans;
    }
};

// Closing sentence:
//   O(____) — ____ runs n times and building one key costs ____ .
//   Memory O(____) because ____ .
