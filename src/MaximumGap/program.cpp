#include "../include/prevector.h"

#define ABS(x) ((x ^ x >> 31) - (x >> 31)) //For *32bit int*
#define MAX(a, b) (a > b ? a : b)
int maximumGap(vector<int>& nums)
{
    int size = nums.size();
    if (size < 2) return 0;
    vector<int> gaps;
    for (int i = 1; i != size; i++)
    {
        gaps.push_back(ABS(nums[i] - nums[i-1]));
    }
    int max = 0;
    for (auto i : gaps)
        max = MAX(max, i);
    return max;
}

int Mymain()
{
    vector<int> test = {1, 2, 8, 11, 16, 6};
    cout << maximumGap(test) << endl;
    return 0;
}
