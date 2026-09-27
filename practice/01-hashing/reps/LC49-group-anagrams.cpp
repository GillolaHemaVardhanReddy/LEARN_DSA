// LC 49 — Group Anagrams  ·  Medium  ·  topic 01 hashing, problem 1/6
// 2026-09-25
//
// Given an array of strings, group the ones that are anagrams of each other.
// Return the groups in any order; the strings inside a group in any order.
//
//   ["eat","tea","tan","ate","nat","bat"]  ->  [["bat"],["nat","tan"],["ate","eat","tea"]]
//   [""]                                   ->  [[""]]
//   ["a"]                                  ->  [["a"]]
//
// 1 <= strs.length <= 10^4 · 0 <= strs[i].length <= 100 · lowercase english letters only
//
// ── the only thing to figure out ──────────────────────────────────────────────
// Two anagrams are different strings. A map needs them to hash to the SAME key.
// So: what do you compute from a string, that is identical for "eat" and "tea",
// and different for "bat"?  Build that key. The rest is one pass.
// ─────────────────────────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size ();
        map<string, vector<string>> check;
        for( int i = 0 ; i < n ; i++ ) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            check[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto& [key, value] : check){
            ans.push_back(value);
        }
        return ans;
    }
};

// ── CLOSED 2026-09-27 · ACCEPTED on LeetCode ─────────────────────────────────
// Path: brute (pairwise compare, sorting every string once PER DISTINCT KEY)
//       -> TLE on the judge. Measured locally at the real constraint:
//          n=1000 -> 2,903 ms | n=2000 -> 11,820 ms | n=4000 -> 47,149 ms
//          (double n, time x4 -> that IS n^2, measured, not asserted)
//          n=10000 -> 294,868 ms   vs 295,000 ms predicted from the model.
//       -> the waste: "bat" was sorted once per distinct key, i.e. n times.
//          It only ever needs sorting ONCE. Its key never changes.
//
// COMPLEXITY: O(n * L log L)
//   - the loop runs n times                       (n = strs.size() <= 10^4)
//   - sort(temp.begin(), temp.end()) walks L chars through log L passes
//     (L <= 100 -> 100 * 7 = 700)                 => 10^4 * 700 = 7 * 10^6
//
// STILL TO FIX: `map` is a TREE. check[temp] costs O(L * log n) = 100 * 14 = 1400
//   -- twice the sort, the most expensive line here. `unordered_map` hashes the
//   key once, O(L) = 100. In the hashing topic, unordered_map is the default;
//   reach for map only when you need sorted iteration or lower_bound.
//
// reduces to: hashing -- "have I seen this key before?" -- with the twist that
//             the key is BUILT (a canonical form), not handed to you.
// ─────────────────────────────────────────────────────────────────────────────
