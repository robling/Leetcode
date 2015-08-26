#include "../include/pre.h"
#include <stack>
#include <limits>
class MinStack
{
private:
    std::stack<int> data;
    std::stack<int> min;
public:
    void push(int x) {
        data.push(x);
        if (getMin() >= x) min.push(x);
    }
    void pop() {
        if (top() == min.top()) min.pop();
        data.pop();
    }
    int top() {
        return data.top();
    }
    int getMin() {
        return min.empty() ? std::numeric_limits<int>::max() : min.top();
    }
};

int Mymain()
{
    MinStack s;
    s.push(9000);
    cout << s.getMin() << endl;
    s.push(10);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.push(50);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.push(1);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
}
