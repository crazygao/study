#include <stack>
#include <utility>
#include <iostream>
using namespace std;
class MinStack {
public:
    stack<pair<int, int>>* stInt;
    /** initialize your data structure here. */
    MinStack() {
        stInt = new stack<pair<int, int>>();
    }
    
    void push(int val) {
        stInt->push({val, stInt->empty() ? val : min(val, stInt->top().second)});
    }
    
    void pop() {
        stInt->pop();
    }
    
    int top() {
        return stInt->top().first;
    }
    
    int getMin() {
        return stInt->top().second;
    }
};

int main() {
    MinStack * minst = new MinStack();
    minst->push(-2);
    minst->push(0);
    minst->push(-3);
    cout << minst->getMin() << endl;
    minst->pop();
    cout << minst->getMin() << endl;
}
