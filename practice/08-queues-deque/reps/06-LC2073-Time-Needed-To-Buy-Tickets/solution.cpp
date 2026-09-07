// LC2073 — Time Needed to Buy Tickets   (EASY · queue simulation -> O(n) counting)  ·  M8 practice
// -----------------------------------------------------------------------------------------------
// n people in line. Person i wants tickets[i] tickets. Each purchase takes 1 second, then that
// person goes to the BACK of the line. People with 0 left leave. Return the second at which the
// person who STARTED at index k finishes.
//   URL: https://leetcode.com/problems/time-needed-to-buy-tickets/
//
// Why this one: the queue simulation is the honest brute. The O(n) answer comes from asking
// "how many seconds does each person actually contribute?" — a counting argument, not a data
// structure. Good rep for BRUTE-AS-ORACLE, and for not reaching for a queue you don't need.
// ===============================================================================================
#include <bits/stdc++.h>
using namespace std;

// 1) BRUTE (the oracle): literally simulate it.  >>> boss fills first <<<
//    Push everyone's INDEX into a queue. Pop the front, they buy one (1 second), decrement.
//    If they still want more, push them to the back. If the person who leaves is the original k
//    and they just hit 0 -> return the elapsed time.
//
//    Careful (Gate A): k is a POSITION IN THE ORIGINAL ARRAY, not a person who keeps index k.
//    Track identity, not position. (Sound familiar? position-vs-distance, LC739.)
//
//    Time: O(__)   Space: O(__)      <<< fill in (what's the worst-case total seconds?)
int timeRequiredToBuyBrute(vector<int>& tickets, int k) {
    int n = tickets.size(), t = 0;
    queue<int> q;
    // TODO(boss): fill q with indices 0..n-1, then simulate second by second.
    //             What EXACTLY is the stopping condition?
    return t;
}

// 2) BRIDGE — the three questions.
//    (1) Where's the repeated work? The simulation loops one second at a time. What is it
//        *recomputing* that you could have known up front?
//    (2) Reframe: forget the queue. Total time = sum over all people of (seconds THEY spend at
//        the counter before person k finishes). So: for ONE person i, how many tickets do they
//        get to buy before k is done?
//    (3) Split on position. Person i is either BEFORE k / AT k / AFTER k in the original line.
//        For each of those three cases, write down that person's contribution in terms of
//        tickets[i] and tickets[k]. Two of the three cases collapse into one formula. Which?
//
//    Hostile input to run BY HAND before you trust your formula:  tickets = [5,1,1,1], k = 0
//    (answer is 8 — if your formula says something else, the formula dropped a case)
//    >>> your words:
//
//
//

// 3) OPTIMAL: one pass, no queue at all.  O(n) time, O(1) space.  >>> boss writes <<<
int timeRequiredToBuy(vector<int>& tickets, int k) {
    int n = tickets.size();
    long long total = 0;                   // magnitude: n<=100, tickets[i]<=100 -> tiny. But
                                           // size the accumulator by REFLEX, every time.
    // TODO(boss): one loop over i. Add person i's contribution. What's the min(...) you need,
    //             and what makes the i<k case differ from the i>k case by exactly one?
    return (int)total;
}

// 4) STRESS: brute vs optimal, 20k random tiny cases.
int main() {
    srand(2073);
    for (int it = 0; it < 20000; it++) {
        int n = 1 + rand() % 6;
        int k = rand() % n;
        vector<int> a(n);
        for (int& x : a) x = 1 + rand() % 5;
        vector<int> b1 = a, b2 = a;
        int g = timeRequiredToBuy(b1, k);
        int e = timeRequiredToBuyBrute(b2, k);
        if (g != e) {
            printf("MISMATCH k=%d tickets=[", k);
            for (int x : a) printf("%d ", x);
            printf("]  got=%d exp=%d\n", g, e);
            return 1;
        }
    }
    printf("all 20000 stress cases passed\n");
    return 0;
}
