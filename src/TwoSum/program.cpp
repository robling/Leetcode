#include "../include/pre.h"
#include <unordered_map>

vector<int> twoSum(vector<int>& nums, int target)
{
    std::unordered_map<int, int> all_nums;
    for (int i = 0; i != nums.size(); i++) all_nums[nums[i]] = i;
    for (int i = 0; i != nums.size(); i++) {
        auto it = all_nums.find(target - nums[i]);
        if (it != all_nums.end() && i != it->second) {
            vector<int> rst(2);
            rst[0] = i; rst[1] = it->second;
            return rst;
        }
    }
    assert(false);//"No pair that makes target");
    return {};
}

int main()
{
    cout << twoSum(vector<int>{3, 2, 4, 6}, 6);
    return 0;
}