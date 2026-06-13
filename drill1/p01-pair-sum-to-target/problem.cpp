/*
================================================================
  DRILL 1  —  Problem 1   [easy]
================================================================
  Given an array of integers and a target, return the indices of the two numbers that add up to it. The array is NOT sorted. Exactly one answer exists.

  Example:     nums=[2,7,11,15], target=9  ->  [0,1]
  Constraints: n <= 1e4

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
  My restatement     : we need to find indexes of 2 numbers that sums to given target and return those indexes as array
  My pattern guess   : 2 pointer approach with sorting
  My target Big-O    : O(nlogn) since constrains are too huge
  My thinking : v1: so i just looked and due to 10^9 constrant i thought it should be some solution below O(n) maybe O(logn) i just thought
  2 pointer since there is 2 numbers so 2 pointer needs sorted array and i just sorted first then started doing in 2 pointer but got stuck at
  well if its smaller we can increase low to make it reach the target and if its bigger than we need then we need to reduce move towards target
  so i did the exact same thing and in middle realised after seeing a test case that failed if its bigger then we dont know which side to move
  if we move high towards low we might miss low+1 to high so i am stuck here at first problem only
  v2 after i learnt: so we need to trust length of array not value in array so 10^4 may also be O(n) so i just got hint as hashmap which
  will actually store the value then each time just sub with the k for running index value and then thats it if === target return index of current and
  the index in hash map
================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> seen;
        for(int i = 0; i < n ; i++) {
          int current = k - nums[i];
          if(seen.contains(current)){
            return {seen[current], i};
          }
          seen[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    // Optional: wire up the example above as a local sanity check before submitting.
    return 0;
}
