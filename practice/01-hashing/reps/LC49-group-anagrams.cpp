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

    }
};
