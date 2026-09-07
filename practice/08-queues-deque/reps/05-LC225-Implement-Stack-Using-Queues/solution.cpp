// LC225 — Implement Stack using Queues   (EASY · design · queue mechanics)  ·  M8 practice
// -----------------------------------------------------------------------------------------
// Build a LIFO stack out of FIFO queues. Only queue ops allowed:
//   push_back · front · pop_front · size · empty       (NO random access, NO back-peek)
//   URL: https://leetcode.com/problems/implement-stack-using-queues/
//
// Why this one: M8's whole point is that a queue's ORDER is forced. Making it behave like a
// stack forces you to feel exactly what a queue can and cannot do. Cheap rep, real insight.
// =========================================================================================
#include <bits/stdc++.h>
using namespace std;

// 1) BRUTE / v1 — TWO queues.  >>> boss fills first <<<
//    Idea: one queue holds the elements in stack order (top at the FRONT). The second queue
//    is scratch space you use to re-order on one of the operations.
//
//    Q for you before you write a line: a stack's top is the LAST thing pushed. A queue only
//    gives you the FIRST thing pushed. So SOMEBODY has to pay to reverse that.
//      - Which operation do you make expensive: push, or pop?
//      - Whichever you pick, the other one is O(1). Say the two complexities out loud.
//
//    Time: push O(__)  pop O(__)  top O(__)  empty O(__)      <<< fill these in
class MyStackV1 {
public:
    queue<int> q1, q2;

    MyStackV1() {}

    void push(int x) {
        // TODO(boss): if you chose "expensive push" — how do you get x to the FRONT of q1
        //             using only push_back / front / pop_front?
    }

    int pop() {
        // TODO(boss): what does pop() cost if push() already did the reordering work?
        return -1;
    }

    int top() {
        // TODO(boss): which end of which queue holds the stack's top?
        return -1;
    }

    bool empty() {
        // TODO(boss)
        return true;
    }
};

// 2) BRIDGE — the follow-up: can you do it with ONE queue?
//    Qs: (1) after you push x onto the back of a queue of size n, the n older elements sit in
//        FRONT of it. What single loop moves them out of the way?
//        (2) how many rotations exactly? (say the number in terms of n, before you code it)
//        (3) does that change the complexity vs v1, or just the space?
//    >>> your words:
//
//
//

// 3) OPTIMAL / v2 — ONE queue (this is what you submit).  >>> boss writes <<<
class MyStack {
public:
    queue<int> q;

    MyStack() {}

    void push(int x) {
        // TODO(boss): push x, then rotate. How many times? Write the loop bound as an expression.
    }

    int pop() {
        // TODO(boss)
        return -1;
    }

    int top() {
        // TODO(boss)
        return -1;
    }

    bool empty() {
        // TODO(boss)
        return true;
    }
};

// 4) STRESS: random op sequences, MyStack vs std::stack as the oracle.
//    (Design problems still get an oracle — the oracle is just the real data structure.)
int main() {
    srand(225);
    for (int it = 0; it < 20000; it++) {
        MyStack mine;
        stack<int> oracle;
        int ops = 1 + rand() % 12;
        for (int o = 0; o < ops; o++) {
            int choice = rand() % 4;
            if (choice == 0 || oracle.empty()) {          // push (forced if empty)
                int x = 1 + rand() % 9;
                mine.push(x);
                oracle.push(x);
            } else if (choice == 1) {                      // top
                if (mine.top() != oracle.top()) {
                    printf("MISMATCH on top(): got=%d exp=%d\n", mine.top(), oracle.top());
                    return 1;
                }
            } else if (choice == 2) {                      // pop
                int g = mine.pop(), e = oracle.top();
                oracle.pop();
                if (g != e) {
                    printf("MISMATCH on pop(): got=%d exp=%d\n", g, e);
                    return 1;
                }
            } else {                                       // empty
                if (mine.empty() != oracle.empty()) {
                    printf("MISMATCH on empty()\n");
                    return 1;
                }
            }
        }
    }
    printf("all 20000 stress cases passed\n");
    return 0;
}
