#include "../include/pre.h"

int findDuplicate(vector<int>& nums)
{
    auto min = 1;
    auto max = nums.size() - 1;
    auto mid = max / 2;
    while(max - min > 1)
    {
        auto count = std::count_if(nums.begin(), nums.end(), [&mid, &min](int i){return i <= mid && i >= min;});
        if (count <= mid - min + 1) min = mid;
        else max = mid;
        mid = (min + max) / 2;
    }
    if (max == min) return max;
    if (std::count_if(nums.begin(), nums.end(), [min](int i){return i == min;})  <= 1) return max;
    else return min;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 10, 7, 8, 8, 9, 8,};
    cout << findDuplicate(nums);
    return 0;
}