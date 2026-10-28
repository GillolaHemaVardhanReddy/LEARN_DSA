// RE-TEST PART 2a — LC930 Binary Subarrays With Sum (cold, plain words)
// https://leetcode.com/problems/binary-subarrays-with-sum/
// Run 2026-10-23 → 2026-10-28. Budget line his: n ≤ 3·10^4 ⇒ n² = 9·10^8 ⇒ need n log n or n.

// BRUTE — 1st submit WA (checked the count BEFORE adding nums[j] ⇒ counted the empty slice,
// e.g. [1], goal 0 → 1 instead of 0). Fixed by moving the add first → TLE (expected, n²).
class SolutionBrute {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int ans = 0;
        int oneCount = 0;
        for( int i = 0 ; i <= n ; i++ ) {
            oneCount = 0;
            for(int j = i ; j < n ; j++ ) {
                if(nums[j] == 1) oneCount++;
                if(oneCount == goal) {
                    ans++;
                } else if(oneCount > goal) {
                    oneCount = -1;
                    break;
                }
            }
        }
        return ans;
    }
};

// OPTIMAL — AC 2026-10-28. Seed + lookup-before-insert cold.
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int ans = 0, sum = 0;
        vector<int> pref;
        unordered_map<int, int> check;
        check[0] = 1;
        for(int i = 0 ; i < n ; i++ ) {
            sum+=nums[i];
            pref.push_back(sum);
        }
        for(int i = 0 ; i < n ; i++ ) {
            if(check.count(pref[i] - goal)){
                ans+=check[pref[i] - goal];
            }
            check[pref[i]]++;
        }
        return ans;
    }
};
