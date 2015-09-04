#include "../include/pre.h"

int findPeakElementHelper(vector<int>& nums, int start, int end)
{
    if (start == end) return start;
    int mid = (start + end) / 2;
    if (mid > 0 && nums[mid] < nums[mid - 1]) {
        return findPeakElementHelper(nums, start, mid - 1);
    }
    else if (mid < nums.size() - 1 && nums[mid] < nums[mid + 1]) {
        return findPeakElementHelper(nums, mid + 1, end);
    }
    else {
        return mid;
    }
}

int findPeakElement(vector<int>& nums)
{
    return findPeakElementHelper(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> test = {1, 2, 3, 4, 5, 6, 1};
    //vector<int> test = {1, 2, };
    cout << findPeakElement(test) << endl;
    return 0;
}
