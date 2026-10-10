// Q3 — CHECKPOINT 01 hashing · 2026-10-10 · COLD, 0 hints · UNSEEN MEDIUM
// https://leetcode.com/problems/repeated-dna-sequences/
// Judge: TLE (ts 1791634248) -> ACCEPTED (ts 1791634350), 102 s apart. Self-diagnosed, self-fixed.
// Felt: 3/5. "when i tried solving brute i came up with this hashing" - the optimal fell out of the brute.
//
// BUDGET (his, up front): "it's O(n^2) so it will surely be TLE my brute approach" - correct, and it TLE'd.
// REAL BOUND of the AC'd version: outer loop runs n times (line 2); the inner loop is capped at ~11 trips
// by line 8's break; line 5 does ~10 appends per i; line 7 runs EXACTLY ONCE per i because it sits inside
// line 6's length==10 guard, and that one call hashes a 10-char key = 10 char reads (CPP_GAPS #18).
//   => n * (10 appends + 10 hash reads) ~= 2 * 10^6 at n = 10^5.   (He first said 10^7 - a 10x over-count,
//      treating line 7 as firing on every inner trip; fixed by tracing "AAAAAAAAAAAAA" at i=0.)
// MEMORY: up to n-9 distinct 10-char keys ~= 10^5 keys * 10 bytes ~= 10^6.
//
// WHY IT IS CORRECT AT THE ANSWER EDGE: the counting loop never pushes. The answer is built by walking the
// map afterwards and taking v > 1, so a sequence seen 4 times ("AAAAAAAAAAAAA") is emitted ONCE. Pushing
// inside the counting loop is the standard failure on this problem.

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> check;
        for(int i = 0 ; i < s.length(); i++ ) {
            string x = "";
            for(int j = i ; j < s.length() ; j++) {
                x += s[j];
                if(x.length() == 10) {
                    check[x]++;                 // [] -insert is CORRECT here: counting wants the default 0
                } else if(x.length() > 10) break;   // <-- the line that kills the n^2
            }
        }
        vector<string> ans;
        for(auto& [k,v] : check) {              // looping a hash container - fluent now (CPP_GAPS #12)
            if(v > 1) ans.push_back(k);         // the ANSWER edge: emit once, however many times it occurred
        }
        return ans;
    }
};
