// RE-TEST PART 2b · S2 — LC1248 Count Number of Nice Subarrays (disguised: "exactly k odd numbers")
// https://leetcode.com/problems/count-number-of-nice-subarrays/
// Gate 10-28 clean (V#6 held). 10-29: tool NOT named cold ("not hashing") -> 1 hint (the 0/1 "adds" table)
// -> he saw "odd = 1, even = 0 -> LC930". Converted to a LEARN rep (not a cold pass). AC first submit, untraced.
// Complexity his: O(n) time (3 loops of n, map lookup O(1) avg), O(n) space (trans + pref + map <= n+1 keys).
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, ans = 0;
        vector<int> trans, pref(n+1, 0);
        for(int  i = 0 ; i < n ; i++) {
            if(nums[i]&1) trans.push_back(1);
            else trans.push_back(0);
        }
        for(int i = 0 ; i < n ; i++ ) {
            sum+=trans[i];
            pref[i] = sum;
        }
        unordered_map<int, int> check;
        check[0] = 1;
        for(int i = 0 ; i < n ; i++){
            if(check.count(pref[i] - k)) ans+=check[pref[i] - k];
            check[pref[i]]++;
        }
        return ans;
    }
};
