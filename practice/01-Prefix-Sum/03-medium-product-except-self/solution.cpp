// LC 238 — Product of Array Except Self  (Prefix × Suffix products, no division)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // ───── YOUR CODE HERE ─────
        // left-product pass, then right-product pass. No division.
        /*
            here we just have to multiplicate all the numbers other than the nums[i] we are at
            so as a brute force i want to just double loop through the nums each time skils the first loop index 
            for(int i = 0 ; i < nums.size(); i++ ) {
                int prod = 1;
                for(int j = 0 ; j < nums.size() ; j++) {
                    if(i!=j) prod *= nums[j];
                }
                product.push_back(prod); came TLE
            }
        */
        int n = nums.size();
        vector<int> left_p(n), right_p(n), final_p(n);
        // using prefix now after brute force 
        int prod = 1;
        left_p.push_back(1);
        for(int i = 1 ; i < n ; i++){
            prod *= nums[i];
            left_p[i] = prod;
        }
        prod = 1;
        right_p[n-1] = 1;
        for(int i = n-2 ; i >= 0 ; i++){
            prod *= nums[i];
            right_p[i] = prod;
        }
        for(int i = 0 ; i < n ; i++) {
            int product = left[i] * right[i];
            final_p[i] = product;
        }
        return final_p; // replace
    }
};

// ───────── local test harness ─────────
int main() {
    Solution sol;
    vector<int> a = {1, 2, 3, 4};
    for (int x : sol.productExceptSelf(a)) cout << x << " ";
    cout << "  (expect 24 12 8 6)\n";
    vector<int> b = {-1, 1, 0, -3, 3};
    for (int x : sol.productExceptSelf(b)) cout << x << " ";
    cout << "  (expect 0 0 9 0 0)\n";
    return 0;
}
