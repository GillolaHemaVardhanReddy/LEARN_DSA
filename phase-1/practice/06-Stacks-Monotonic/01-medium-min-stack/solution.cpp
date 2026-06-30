// LC155 — Min Stack  ·  Medium  ·  https://leetcode.com/problems/min-stack/
// PRACTICE (cold/interleaved). Paste ONLY the MinStack class into LeetCode. main() is local.
//
// GATES while you solve:  name the pattern FIRST  ·  build your own hostile input
//                         ·  self-trace before you say "done" (don't reach for "is it ok")
//
//   Design a stack: push / pop / top / getMin — every one in O(1) time.
//   Constraints: -2^31 <= val <= 2^31-1 · pop/top/getMin only called on NON-empty stacks
//                · up to 3*10^4 calls.
//
//   PATTERN (name it BEFORE you code — this is the rep): ______________________________
//   The catch is getMin() in O(1). A plain stack scans for the min = O(n). What extra
//   thing could each element carry so the min is always sitting right on top?
// =============================================================================
#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    vector<int> stack;
    vector<int> minstack;
    MinStack() {}

    void push(int value) {
        stack.push_back(value);
        if(stack.size()==1) minstack.push_back(value);
        else {
            int val = min(minstack[minstack.size()-1], value);
            minstack.push_back(val);
        }
    }
    void pop() {
        stack.pop_back();
        minstack.pop_back();
    }
    int top() {
        return stack.back();
    }
    int getMin() {
        if(minstack.size()) return minstack[minstack.size()-1];
        return 0;
    }
};

// =============================================================================
//  REFERENCE ORACLE — a slow-but-correct min-stack (O(n) getMin). Your job: beat it to O(1).
// =============================================================================
class MinStackRef {
    vector<int> s;
public:
    void push(int v){ s.push_back(v); }
    void pop(){ s.pop_back(); }
    int top(){ return s.back(); }
    int getMin(){ return *min_element(s.begin(), s.end()); }
    bool empty(){ return s.empty(); }
};

int main() {
    // Canonical example: expect getMin -3, then top 0, then getMin -2.
    MinStack m;
    m.push(-2); m.push(0); m.push(-3);
    printf("getMin=%d (expect -3)\n", m.getMin());
    m.pop();
    printf("top=%d (expect 0)\n", m.top());
    printf("getMin=%d (expect -2)\n", m.getMin());

    // Random op stress vs the reference (push / pop / top / getMin, never on empty).
    unsigned seed = 991;
    auto rnd = [&](){ seed = seed*1103515245u + 12345u; return seed; };
    for (int trial = 0; trial < 100000; ++trial) {
        MinStack a; MinStackRef b;
        int size = 0;
        for (int step = 0; step < 30; ++step) {
            int op = rnd() % 4;
            if (op == 0) { int v = (int)(rnd() % 21) - 10; a.push(v); b.push(v); size++; }
            else if (size > 0) {
                if (op == 1) { a.pop(); b.pop(); size--; }
                else if (op == 2) { if (a.top() != b.top()) { printf("TOP MISMATCH\n"); return 1; } }
                else { if (a.getMin() != b.getMin()) { printf("MIN MISMATCH\n"); return 1; } }
            }
        }
    }
    printf("stress: 100k op-sequences passed\n");
    return 0;
}
