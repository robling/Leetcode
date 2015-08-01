#include "../include/prevector.h"

int search(vector<int>& nums, int target)
{
    int st = 0;
    int ed = nums.size() - 1;
    auto mid = [&](){return (ed - st) / 2 + st;};
    auto ifThisRange = [](int left, int right, int target)->bool{
        if (left > right) {
            if (target >= left || target <= right) return true;
        }
        else {
            if (target <= right && target >= left) return true;
        }
        return false;
    };
    while (st != ed){
        //cout << st << "," << ed << ":" << mid() << endl;
        if (nums[mid()] == target) return mid();
        if ((mid() - 1) >= st && ifThisRange(nums[st], nums[mid() - 1], target)) {
            ed = mid() - 1;
            continue;
        }
        if ((mid() + 1) <= ed && ifThisRange(nums[mid() + 1], nums[ed], target)) {
            st = mid() + 1;
            continue;
        }
        return -1;
    }
    if (nums[mid()] == target) return mid();
    return -1;
}

int Mymain()
{
    vector<int> nums = {
        4, 5, 6, 7, 0, 1, 2,
    };
    cout << search(nums, 8) << endl;
}
