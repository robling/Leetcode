#include "../include/pre.h"
#include <stack>

class Queue {
private:
    std::stack<int> cache_in;
    std::stack<int> cache_out;
    void move_to_out_cache() //require cache_out to be empty
    {
        while(!cache_in.empty()) {
            cache_out.push(cache_in.top());
            cache_in.pop();
        }
    }
public:
    // Push element x to the back of queue.
    void push(int x) {
        cache_in.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (cache_out.empty()) move_to_out_cache();
        cache_out.pop();
    }

    // Get the front element.
    int peek(void) {
        if (cache_out.empty()) move_to_out_cache();
        return cache_out.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return cache_in.empty() && cache_out.empty();
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    return 0;
}