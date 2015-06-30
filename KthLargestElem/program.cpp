#include "../include/prevector.h"

const auto quickSortCore = [](std::vector<int>& nums, size_t s, size_t e)->size_t{
    if (e - s == 1){
        if (nums[s] > nums[e])
            std::swap(nums[s], nums[e]);
        return 0;
    }
    auto mid = nums[e];
    cout << s << ", " << e << ":" << mid << endl;
    size_t i = s, j = s;
    while (j <= e) {
        if (nums[j] <= mid){
            std::swap(nums[i], nums[j]);
            i++, j++;
            continue;
        }
        j++;
    }
    return i - 1;
};

void quickSort(std::vector<int>& nums, size_t s, size_t e)
{
    PrintVector(nums);
    auto m = quickSortCore(nums, s, e);
    cout << "===" << m << "===" << endl;
    if (m < s || m > e) return;
    if (m - s > 1) quickSort(nums, s, m - 1);
    if (e - m > 1) quickSort(nums, m + 1, e);
}

int quickSortKMin(std::vector<int>& nums, size_t s, size_t e, int k)
{
    auto m = quickSortCore(nums, s, e);
    if (m < s || m > e) return;
    if (m == k) return nums[k];
    if (m < k) quickSortKMin(nums, m + 1, e, k - m);

}

int findKthLargest(vector<int>& nums, int k)
{
    int num = nums.size();

    return num;
}
int Mymain()
{
    //std::vector<int> n {67, 12, 2, 3, 56, 98, 91, 54};
    std::vector<int> n {3, 9, 2, 7, 1, 5, 8};
    quickSort(n, 0, n.size());
    PrintVector(n);
    return 0;
}
