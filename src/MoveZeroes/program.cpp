#include "../include/pre.h"

void moveZeroes(vector<int>& nums)
{
    std::stable_sort(nums.begin(), nums.end(), [](int a, int b){return a != 0 && b == 0;});
}
 
int main()
{
    return 0;
}