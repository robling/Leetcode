#include "../include/pre.h"

int singleNumber(vector<int>& nums)
{
    int rst = 0;
    for (auto x : nums)
        rst ^= x;
    return rst;
}

int main()
{
    vector<int> test {1, 2, 3, 1, 2, 4, 3, 5, 5};
    cout << singleNumber(test) << endl;
    return 0;
}
