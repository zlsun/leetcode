/** 232. Implement Queue using Stacks

Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.

pop() -- Removes the element from in front of queue.

peek() -- Get the front element.

empty() -- Return whether the queue is empty.

Notes:

You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Queue {
private:
    stack<int> head, tail;
public:
    // Push element x to the back of queue.
    void push(int x) {
        tail.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (head.empty()) {
            while (!tail.empty()) {
                head.push(tail.top());
                tail.pop();
            }
        }
        head.pop();
    }

    // Get the front element.
    int peek(void) {
        if (head.empty()) {
            while (!tail.empty()) {
                head.push(tail.top());
                tail.pop();
            }
        }
        return head.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return head.empty() && tail.empty();
    }
};

int main() {
    Queue q;
    q.push(1);
    ASSERT q.peek() == 1;
    q.push(2);
    ASSERT q.peek() == 1;
    q.pop();
    ASSERT q.peek() == 2;
    q.pop();
    ASSERT q.empty();
    return 0;
}
