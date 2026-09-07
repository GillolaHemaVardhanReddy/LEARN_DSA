// LC232 — Implement Queue using Stacks  (EASY · mechanics)  ·  M8
// -----------------------------------------------------------------
// FIFO queue built from TWO stacks. Only stack ops allowed.
// Real signature below. This is a DESIGN problem — no brute/optimal split;
// the "bridge" is the two-stacks insight. Fill the class, then drive it in main().
//   URL: https://leetcode.com/problems/implement-queue-using-stacks/
// =================================================================
#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------------------------
// THE IDEA (say it before coding): a stack reverses order. Pour `in` -> `out`
// only when `out` is empty; then `out`'s TOP is the queue's FRONT. Each element
// moves at most once -> amortized O(1).
// ---------------------------------------------------------------------------
class MyQueue {
public:
    stack<int> st1, st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int ans = 0;
        if(!st2.empty()) {ans = st2.top(); st2.pop();}
        return ans;
    }
    
    int peek() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int ans = 0;
        if(!st2.empty()) {ans = st2.top();}
        return ans;
    }
    
    bool empty() {
        if(!st1.empty() || !st2.empty()) return false;
        return true;
    }
};

// ---------------------------------------------------------------------------
// DRIVER — exercises the class against the LC example.
// ---------------------------------------------------------------------------
int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    printf("peek -> %d  (expect 1)\n", q.peek());
    printf("pop  -> %d  (expect 1)\n", q.pop());
    printf("empty-> %d  (expect 0)\n", q.empty() ? 1 : 0);
    return 0;
}
