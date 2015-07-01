#include "../include/prevector.h"
#include "../include/presort.h"

//e - s >= 3
//too slow
inline void putMiddleToEnd(std::vector<int>& nums, size_t s, size_t e)
{
    auto it_b = nums.begin();
    std::vector<decltype(it_b)> a = {it_b + s, it_b + std::floor((e - s) / 2 + 0.5), it_b + e};
    int i = 0, min_s = 0, max_s = 0;
    while (i++ != 2){
        if (a[i][0] < a[min_s][0]) min_s = i;
        if (a[i][0] > a[max_s][0]) max_s = i;
    }
    i = 0;
    while(i != 2){
        if (i != min_s && i != max_s) break;
        i++;
    }
    std::swap(a[i][0], a[2][0]);
}

inline void twoSort(std::vector<int>& nums, size_t s){
    if (nums[s] > nums[s + 1]) std::swap(nums[s], nums[s + 1]);
}

inline size_t quickSortCore(std::vector<int>& nums, size_t s, size_t e)
{
    //putMiddleToEnd(nums, s, e);
    auto mid = nums[e];
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
}

void quickSort(std::vector<int>& nums, size_t s, size_t e)
{
    auto m = quickSortCore(nums, s, e);
    //if (m < s || m > e) return;
    if (m - s > 2) quickSort(nums, s, m - 1);
    else if (m - s == 2) twoSort(nums, s);
    if (e - m > 2) quickSort(nums, m + 1, e);
    else if (e - m == 2) twoSort(nums, m + 1);
}

void startQuickSort(std::vector<int>& nums, size_t s, size_t e)
{
    if (s == e) return;
    if (e - s == 1) {
        twoSort(nums, s);
        return;
    }
    quickSort(nums, s, e);
}

int findKthLargest(vector<int>& nums, int k)
{
    //convert to k min's index
    k = nums.size() - k;
    size_t s = 0,  e = nums.size() - 1;
    auto m = quickSortCore(nums, s, e);
    while (k != m) {
        s = (k < m) ? s : m + 1;
        e = (k < m) ? m - 1 : e;
        m = quickSortCore(nums, s, e);
    }
    return nums[k];
}

int Mymain()
{
    std::vector<int> nums;
    GenerateRandomArray(nums, 10001);
    auto nums_s = nums;
    int k = 1539;
    int myk = 0, stdk = 2;
    {TIC
        //startQuickSort(nums, 0, nums.size() - 1);
        myk = findKthLargest(nums, k);
    TOC}
    {TIC
        std::sort(nums_s.begin(), nums_s.end());
        stdk = nums_s[nums.size() - k];
    TOC}
    cout << "Check increase : " << std::boolalpha << CheckSorted(nums, nIncrease) << std::noboolalpha << endl;
    cout << "Check K Largest : " << std::boolalpha << (myk == stdk) << std::noboolalpha << endl;
    return 0;
}
