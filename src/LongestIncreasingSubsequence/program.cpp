#include "../include/pre.h"

int lengthOfLIS(vector<int>& nums)
{
    if (nums.size() == 0) return 0;
    vector<int> minEnd;
    minEnd.push_back(nums[0]);
    cout << minEnd << endl;
    for (int i = 1; i < nums.size(); i++)
    {
        auto upper = std::upper_bound(minEnd.begin(), minEnd.end(), nums[i], std::less_equal<int>());
         //if (*(upper - 1) >= nums[i]) continue;
        if (upper == minEnd.end()) {
            minEnd.push_back(nums[i]);
        }
        else {
            *upper = nums[i];
        }
        cout << minEnd << endl;
    }
    return minEnd.size();
}
    
int main()
{
    //vector<int> test = {10,9,2,5,3,7,101,18};
    //vector<int> test = {3,5,6,2,5,4,19,5,6,7,12};
    vector<int> test = {2, 2};
    cout << lengthOfLIS(test) << endl;
    return 0;
}