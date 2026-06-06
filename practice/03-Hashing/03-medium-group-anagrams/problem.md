# LC 49 — Group Anagrams  ·  Medium   ·   HASHING (map with a computed KEY)

**Link:** https://leetcode.com/problems/group-anagrams/
**Topic:** Hash map where the KEY is a canonical signature of each string

---

## Problem (plain English)
Group the strings that are anagrams of each other. Return the groups (any order).

## Examples
| strs | output (any order) |
|---|---|
| ["eat","tea","tan","ate","nat","bat"] | [["eat","tea","ate"],["tan","nat"],["bat"]] |
| [""] | [[""]] |
| ["a"] | [["a"]] |

## Constraints
- `1 ≤ strs.length ≤ 10^4`, `0 ≤ strs[i].length ≤ 100`, lowercase.

## Before you code (the KEY idea)
1. Anagrams share a **canonical key**. Two natural keys:
   - the **sorted string** ("eat"→"aet"), or
   - a **count signature** like "1#0#0#...#1#..." (26 counts) — O(n) per word vs O(L log L).
2. `unordered_map<string, vector<string>>`: push each word under its key, then collect values.

## Result log
- Status: ___   The key I chose and why: ___
