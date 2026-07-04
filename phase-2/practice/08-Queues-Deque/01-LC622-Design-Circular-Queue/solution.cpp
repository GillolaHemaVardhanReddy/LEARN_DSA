// LC622 — Design Circular Queue  (MEDIUM · ring buffer)  ·  M8 practice
// ---------------------------------------------------------------------
// Fixed-capacity FIFO that reuses freed front slots via % k.
// Design problem: fill the class, drive it in main() against the example.
//   URL: https://leetcode.com/problems/design-circular-queue/
// =====================================================================
#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
    vector<int> buf;
    int head = 0, count = 0, cap;

    MyCircularQueue(int k) : buf(k), cap(k) {}

    bool enQueue(int value) {
        // TODO: if full -> false. else write at (head+count)%cap, count++, return true.
        return false;
    }

    bool deQueue() {
        // TODO: if empty -> false. else head=(head+1)%cap, count--, return true.
        return false;
    }

    int Front() {
        // TODO: empty -> -1, else buf[head]
        return -1;
    }

    int Rear() {
        // TODO: empty -> -1, else buf[(head+count-1)%cap]
        return -1;
    }

    bool isEmpty() { return count == 0; }
    bool isFull()  { return count == cap; }
};

// -------------------- DRIVER (LC example) --------------------
int main() {
    MyCircularQueue q(3);
    printf("%d %d %d %d\n", q.enQueue(1), q.enQueue(2), q.enQueue(3), q.enQueue(4)); // 1 1 1 0
    printf("Rear=%d (exp 3)\n", q.Rear());
    printf("isFull=%d (exp 1)\n", q.isFull());
    printf("deQueue=%d (exp 1)\n", q.deQueue());
    printf("enQueue4=%d (exp 1)\n", q.enQueue(4));
    printf("Rear=%d (exp 4)\n", q.Rear());
    return 0;
}
