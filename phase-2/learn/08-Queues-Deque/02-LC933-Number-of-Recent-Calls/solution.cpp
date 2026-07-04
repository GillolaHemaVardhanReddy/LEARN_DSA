// LC933 — Number of Recent Calls  (EASY · plain queue, front-expiry)  ·  M8
// -------------------------------------------------------------------------
// ping(t): record time t (increasing), return # of pings in [t-3000, t].
// Design problem: fill the class, drive it in main(). This drills the
// FRONT-EXPIRY move (pop_front while too old) you reuse in the monotonic deque.
//   URL: https://leetcode.com/problems/number-of-recent-calls/
// =========================================================================
#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------------------------
// THE IDEA: times arrive increasing -> queue. push_back(t); then pop_front
// while front < t-3000 (expired); answer = size.
// ---------------------------------------------------------------------------
class RecentCounter {
public:
    deque<int> chk1;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        chk1.push_front(t);
        int cnt = 0;
        int mini = t-3000;
        while(chk1.back() < mini){
            chk1.pop_back();
        }
        return chk1.size();
    }
};

// ---------------------------------------------------------------------------
// DRIVER — LC example. Expected: 1 2 3 3
// ---------------------------------------------------------------------------
int main() {
    RecentCounter rc;
    printf("%d ", rc.ping(1));      // 1
    printf("%d ", rc.ping(100));    // 2
    printf("%d ", rc.ping(3001));   // 3
    printf("%d\n", rc.ping(3002));  // 3
    printf("(expect 1 2 3 3)\n");
    return 0;
}
