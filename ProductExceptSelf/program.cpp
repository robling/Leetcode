#include "../include/prevector.h"

//With O(n) time complexity and constant extra space require
vector<int> productExceptSelf(vector<int>& nums)
{
    int product = 1;
    vector<int> rst(nums.size(), 1);
    size_t i = 0;
    std::for_each(nums.begin(), nums.end(), [&](int elem){
        rst[i] *= product;
        product *= elem;
        i++;
    });
    product = 1;
    std::for_each(nums.rbegin(), nums.rend(), [&](int elem){
        i--;
        rst[i] *= product;
        product *= elem;
    });
    return rst;
}

int Mymain()
{
    //vector<int> nums = {1, 2, 3, 4, 5, 6, 7, };
    vector<int> nums = {1, 2, 3, 4, };
    PrintVector(productExceptSelf(nums));
    return 0;
}
