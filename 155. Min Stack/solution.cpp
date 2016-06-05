/** 155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.

pop() -- Removes the element on top of the stack.

top() -- Get the top element.

getMin() -- Retrieve the minimum element in the stack.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class MinStack {
    stack<int> s, m;
public:
    void push(int x) {
        s.push(x);
        if (m.empty() || x <= m.top()) m.push(x);
    }

    void pop() {
        int x = s.top();
        s.pop();
        if (x == m.top()) m.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return m.top();
    }
};

int main() {
    MinStack s;
    s.push(1);
    ASSERT s.top() == 1;
    ASSERT s.getMin() == 1;
    s.push(2);
    ASSERT s.top() == 2;
    ASSERT s.getMin() == 1;
    s.push(0);
    ASSERT s.top() == 0;
    ASSERT s.getMin() == 0;
    s.push(0);
    ASSERT s.top() == 0;
    ASSERT s.getMin() == 0;
    s.pop();
    s.pop();
    ASSERT s.top() == 2;
    ASSERT s.getMin() == 1;
    s.pop();
    ASSERT s.top() == 1;
    ASSERT s.getMin() == 1;
    return 0;
}
