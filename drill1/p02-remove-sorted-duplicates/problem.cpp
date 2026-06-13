/*
================================================================
  DRILL 1  —  Problem 2   [easy]
================================================================
  Given a SORTED array, remove duplicates IN PLACE so each unique value appears once, keeping order; return the count of unique elements.

  Example:     [0,0,1,1,1,2,2,3,3,4]  ->  5  (array starts 0,1,2,3,4)
  Constraints: 1 <= n <= 3e4

  ----------------------------------------------------------------
  BEFORE YOU CODE (in order — this IS the drill):
    1. RESTATE the problem in ONE plain sentence.
    2. DRY-RUN the example above by hand.
    3. CONSTRAINTS  ->  target complexity?
    4. NAME THE PATTERN. Gates to say out loud:
         - "Is the data SORTED?"  no  -> probably hashing, not two pointers.
         - "Any NEGATIVES / a +-1 transform?"  yes -> prefix+hash, not a window.
    5. Open the link (LINKS.md), code below, and SUBMIT to LeetCode (the judge is truth).
    6. Boundary checklist before submit: empty / single / first&last / overflow.
  ----------------------------------------------------------------
  My restatement     : we need to remove duplicates and keep the numbers in correct order and return count of unique numbers left
  My pattern guess   : this is simple i first got into my mind simple one look and count with hash map count if not in hash map since we only need count
  My target Big-O    : O(n)
================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int n = nums.size(), ans = 0, k = nums[0], j = 0 ;
      vector<int> d(n);
      d[j] = nums[0];
      j++;
      for(int i = 1 ; i < n ; i++) {
        if(nums[i] != k){
          d[j] = nums[i];
          j++;
          ans++;
        } 
        k = nums[i];
      }
      nums.assign(d.begin(), d.end());
      return ans;
    }
};

int main() {
    // Optional: wire up the example above as a local sanity check before submitting.
    return 0;
}
