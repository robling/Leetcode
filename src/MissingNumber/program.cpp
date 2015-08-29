#include "../include/pre.h"

int missingNumber(vector<int>& nums)
{
    int sum = 0;
    int n = nums.size() + 1;
    for (auto x : nums) { sum += x; }
    return n * (n - 1) / 2 - sum;
}

int main()
{
    cout << missingNumber(std::vector<int> {3, 8, 4, 5, 6, 1, 7, 0}) << endl;
    return 0;
}
