#include "../include/pre.h"
#include <queue>

class MedianFinder {
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if (min_heap.empty() || num > min_heap.top()) min_heap.push(num);
        else max_heap.push(num);
        balance();
        if (max_heap.empty() || min_heap.empty()) return;
    }

    // Returns the median of current data stream
    double findMedian() {
        if (min_heap.size() == max_heap.size()) return (min_heap.top() + max_heap.top()) / 2.0;
        if (max_heap.size() > min_heap.size()) return max_heap.top();
        return min_heap.top(); 
    }
private:
    void balance()
    {
        if (min_heap.size() == max_heap.size()) return;
        auto M = max_heap.size(), N = min_heap.size();
        int diff = (M > N ? M - N : N - M) / 2;
        if (M > N)
        {
            while (diff-- != 0)
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
        }
        else
        {
            while (diff-- != 0)
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
    }
    //Elem order :
    //===============max_heap.top()-----min_heap.top()=====================
    std::priority_queue<int, vector<int>, std::less<int>> max_heap;
    std::priority_queue<int, vector<int>, std::greater<int>> min_heap;
};

int main()
{
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    mf.addNum(3);
    mf.addNum(4);
    cout << endl << "______" << mf.findMedian() << endl;
    return 0;
}