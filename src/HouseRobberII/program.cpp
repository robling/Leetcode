#include "../include/pre.h"


template<typename FowardIterator>
int robLine(FowardIterator start, FowardIterator end)
{
    if (start == end) return 0;
    int Rn = *start;
    int Rn_ = 0;
    while (++start != end) {
        int tmp = Rn;
        Rn = std::max(Rn_ + *start, Rn);
        Rn_ = std::max(Rn_, tmp);
    }
    return std::max(Rn, Rn_);
}

int rob(vector<int>& nums)
{
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    return std::max(robLine(nums.begin(), nums.end() - 1), robLine(nums.begin() + 1, nums.end()));
}
int main()
{
    cout << rob(vector<int>{1, 2, 3, 4, 5});
    return 0;
}