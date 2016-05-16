#include "../include/pre.h"

int removeDuplicates(vector<int>& nums)
{
    if (0 == nums.size()) return 0;
    int n = nums.size();
    int cur = nums[0];
    int stack = 1;
    for (auto it = nums.begin() + 1; it != nums.end(); )
    {
        if (*it == cur) stack++;
        else stack = 1, cur = *it;
        if (stack > 2)
        {
            n--;
            it = nums.erase(it);
        }
        else 
        {
            it++;
        }
    }
    return n;
}

int main()
{
    vector<int> test{1, 1, 1, 2, 2, 3, 3, 3, 3, 3, 4, 5, 6, };
    cout << removeDuplicates(test) << endl;
    return 0;
}