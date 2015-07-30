#include "../include/prevector.h"
using std::max;

int candy(vector<int>& ratings)
{
    vector<int> nums(ratings.size() + 1, 1);
    nums.rbegin()[0] = 0;
    for (size_t i = 1; i < ratings.size(); )
    {
        while (ratings[i] > ratings[i - 1] && i < ratings.size())
        {
            nums[i] = nums[i - 1] + ((ratings[i] > ratings[i - 1]) ? 1 : 0);
            i++;
        }
        size_t current = i - 1;
        while (ratings[i] < ratings[i - 1] && i < ratings.size()) i++;
        for (size_t j = i - 1; j > current; j--)
        {
            if (j == i - 1) continue;
            nums[j] = nums[j + 1] + 1;
        }
        nums[current] = ratings[current] == ratings[current + 1] ? nums[current] : std::max(nums[current], nums[current + 1] + 1);
        while (ratings[i] == ratings[i - 1] && i < ratings.size()) i++;
    }
    //PrintVector(ratings);
    //PrintVector(nums);
    int sum = 0;
    for (int i : nums){
        sum += i;
    }
    return sum;
}

int Mymain()
{
    vector<int> test = {
        4, 2, 1, 4, 4, 4, 1, 2, 3, 4, 5, 5, 5, 5, //1, 1, 2, 3, 4, 5, 6, 9, 8, 5, 4, 1, 2, 3, 4, 5, 6, 9, 8, 5, 4,
    };
    cout << "MY: \t" << candy(test) << endl;
}
