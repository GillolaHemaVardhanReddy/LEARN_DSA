// LC454 Four Sum II — +1d COLD RE-SOLVE · 2026-10-07 block, first 15 min
// Blank file. No scrolling up, no opening learn/LC454-4sum-ii.cpp.
// Constraints: n == A.size() == B.size() == C.size() == D.size(), 1 <= n <= 200
// Return the number of tuples (i,j,k,l) with A[i]+B[j]+C[k]+D[l] == 0.

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int a = A.size(), b = B.size(), c = C.size(), d = D.size();
        unordered_map<int, int> check;
        for(int i = 0 ; i < a ; i++ ) {
            for(int j = 0 ; j < b ; j++ ) {
                check[A[i] + B[j]]++;
            }
        }

        int ans = 0 ;
        for(int i = 0 ; i < c ; i++ ) {
            for(int j = 0; j < d; j++ ) {
                ans += check[-1 * (C[i] + D[j])];
            }
        }
        return ans;
    }
};
