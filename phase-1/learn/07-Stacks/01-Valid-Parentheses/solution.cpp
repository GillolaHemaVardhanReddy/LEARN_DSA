// LC20 — Valid Parentheses
// M7 Stacks · L3 gate: code the optimal FROM MEMORY.
//
// =============================================================================
//  BRUTE  — repeated removal
// =============================================================================
//  Idea: keep deleting any adjacent matched pair "()", "[]", "{}" from the
//  string until nothing changes. Valid  <=>  the string is finally empty.
//  Time:  O(n^2)   (each full pass is O(n), and we may do up to n/2 passes)
//  Space: O(n)
#include <bits/stdc++.h>
using namespace std;

class SolutionBrute {
public:
    bool isValid(string s) {
        int n = s.length();
        int pos;
        while ((pos = s.find("()")) != string::npos ||
               (pos = s.find("[]")) != string::npos ||
               (pos = s.find("{}")) != string::npos) {
            s.erase(pos, 2);
        }
        return s.empty();
    }
};

// =============================================================================
//  HOW I DERIVED BRUTE -> OPTIMAL   (The Bridge — fill in your words)
// =============================================================================
//  Q1. Where is the repeated work in the brute?
//      ->
//  Q2. What does the brute recompute on every pass?
//      ->
//  Q3. What tool kills it? (which bracket are we always matching against?)
//      ->
//  My plain-words derivation:
//      ->

// =============================================================================
//  OPTIMAL — stack
// =============================================================================
//  Idea:
//  Time:  O(n)
//  Space: O(n)
class Solution {
public:
    bool isValid(string s) {
        stack<int> bucket;
        int n = s.length();
        for(int i = 0 ; i < n ; i++ ) {
            char first = s[i];
            if(first == '{' || first == '[' || first == '('){
                bucket.push(first);
            } else {
                if(bucket.size()==0) return false;
                char check = bucket.top();
                if((check=='(' && first != ')') || (check == '{' && first != '}') || (check == '[' && first!=']')){
                    return false;
                }
                bucket.pop();
            }
        }
        if(bucket.size()!=0) return false;
        return true;
    }
};

// =============================================================================
//  STRESS TEST — brute is the oracle
// =============================================================================
int main() {
    // Sanity: the 5 LeetCode examples.
    vector<pair<string,bool>> cases = {
        {"()", true}, {"()[]{}", true}, {"(]", false},
        {"([])", true}, {"([)]", false}, {"", true},
        {"(", false}, {")", false}, {"]", false}
    };
    Solution opt;
    SolutionBrute bru;
    for (auto& [str, want] : cases) {
        bool g = opt.isValid(str), b = bru.isValid(str);
        printf("s=%-8s opt=%d brute=%d expect=%d %s\n",
               ("\""+str+"\"").c_str(), g, b, want,
               (g==want && b==want) ? "" : "  <-- MISMATCH");
    }

    // Random stress: brute vs optimal on tiny random bracket strings.
    string chars = "()[]{}";
    unsigned seed = 12345;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    for (int t = 0; t < 100000; ++t) {
        int len = rnd() % 8;
        string s;
        for (int i = 0; i < len; ++i) s += chars[rnd() % 6];
        if (opt.isValid(s) != bru.isValid(s)) {
            printf("STRESS MISMATCH on \"%s\"\n", s.c_str());
            return 1;
        }
    }
    printf("stress: 100k cases passed\n");
    return 0;
}
