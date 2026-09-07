// LC 875 — Koko Eating Bananas  ·  SEARCH ON THE ANSWER (lo/hi are VALUES)
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long find_hours(vector<int>& a, int k){
        int n = a.size(), i = 0;
        long long sum = 0;
        while(i < n) {
            if(a[i]%k==0) sum+=(a[i]/k);
            else sum+=((a[i]/k)+1);
            i++;
        }
        return sum;
    }
    int find_max(vector<int>& a){
        int m = 0;
        for(int i = 0 ; i < a.size(); i++ ) {
            m = max(m,a[i]);
        }
        return m;
    }
    int minEatingSpeed(vector<int>& a, int h) {
        int s = 1, e = find_max(a), ans = e+1;
        while(s<=e){
            int mid = (s+e)/2;
            if(find_hours(a, mid) > h) s = mid + 1;
            else {
                ans = min(ans,mid);
                e = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> a = {3,6,7,11};
    cout << sol.minEatingSpeed(a, 8) << "  (expect 4)\n";
    vector<int> b = {30,11,23,4,20};
    cout << sol.minEatingSpeed(b, 5) << "  (expect 30)\n";
    cout << sol.minEatingSpeed(b, 6) << "  (expect 23)\n";
    return 0;
}
