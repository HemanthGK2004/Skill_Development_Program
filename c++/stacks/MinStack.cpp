//design a min stack that supports push, pop, top, and retrieving the minimum element in constant time.

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> s; // Stack to store elements
    stack<int> minStack; // Stack to store minimum elements

public:
    MinStack() {}

    void push(int val) {
        s.push(val); // Push the value onto the main stack
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val); // Push onto minStack if it's empty or val is less than or equal to current minimum
        }
    }
    
    void pop() {
        if (s.empty()) return; // If the stack is empty, do nothing
        if (s.top() == minStack.top()) {
            minStack.pop(); // Pop from minStack if the top of s is the current minimum
        }
        s.pop(); // Pop from the main stack
    }
    
    int top() {
        return s.top(); // Return the top element of the main stack
    }
    
    int getMin() {
        return minStack.top(); // Return the top element of minStack, which is the minimum element
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Minimum: " << minStack.getMin() << endl; // Returns -3
    minStack.pop();
    cout << "Top: " << minStack.top() << endl; // Returns 0
    cout << "Minimum: " << minStack.getMin() << endl; // Returns -2
    return 0; // Return success
}