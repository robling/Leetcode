#include "../include/prevector.h"
#include <queue>
#include <utility>

typedef std::pair<int, int> Elem;
struct Comp{
public:
    bool operator()(Elem& a, Elem& b){
        return (a.first < b.first);
    }
};

//复杂度的渐进上界应该是 n log(n)
//Leetcode上耗时为132ms
//需要进一步研究
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    std::priority_queue<Elem, vector<Elem>, Comp> qe;
    vector<int> rst;
    int i = 0;
    for ( ; i < k - 1; i++){
        qe.push(std::make_pair(nums[i], i));
    }
    Elem e;
    for ( ; i < nums.size(); i++){
        qe.push(std::make_pair(nums[i], i));
        e = qe.top();
        while (e.second <= i - k){
            qe.pop();
            e = qe.top();
        }
        rst.push_back(e.first);
    }
    return rst;
}

int Mymain()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    PrintVector(maxSlidingWindow(nums, 3));

    //Boring!
    //Can work on MSVC >= 1800,
    //But not on Leetcode
    //I will find out why, probably
    auto comp = [](int i){return i + 1;};
    decltype(comp) comp2;
    cout << comp2(5);
    return 0;
}
