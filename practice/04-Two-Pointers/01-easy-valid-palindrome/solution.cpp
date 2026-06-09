// LC 125 — Valid Palindrome  ·  CONVERGING two pointers + skip
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // cue: compare from both ends -> converging two pointers
        int n = s.length();
        int start = 0, end = n-1, ans = true;
        while(start < end) {
            int is_start_char = 0, is_end_char = 0;
            for(char i = 'a'; i <= 'z' ; i++){
                if(s[start] == i) is_start_char = 1;
                if(s[end]==i) is_end_char = 1;
            }
            for(char i = 'A'; i <= 'Z' ; i++){
                if(!is_start_char && s[start] == i) is_start_char = 1;
                if(!is_end_char && s[end]==i) is_end_char = 1;
            }
            for(int i = 0; i <= 9; i++){
                if(!is_start_char && (s[start]-'0') == i) is_start_char = 1;
                if(!is_end_char && (s[end]-'0') == i) is_end_char = 1;
            }
            if(is_start_char && is_end_char){
                if(tolower(s[start]) != tolower(s[end])){
                    ans = false;
                    break;
                } else {
                    start++;
                    end--;
                }
            } else {
                if(!is_start_char) start++;
                if(!is_end_char) end--;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << "  (expect 1)\n";
    cout << sol.isPalindrome("race a car")                     << "  (expect 0)\n";
    cout << sol.isPalindrome(" ")                              << "  (expect 1)\n";
    return 0;
}
