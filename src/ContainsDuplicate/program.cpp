#include "../include/pre.h"
#include <unordered_set>

bool containsDuplicate(vector<int>& nums)
{
    std::unordered_set<int> uni;
    for (auto i : nums) uni.insert(i);
    return nums.size() != uni.size();
}
int main()
{
    // 常量的initializer list无法隐式转化为非常量左值引用
    // 这里只能显式声明为非常量右值
    cout << containsDuplicate(vector<int>{1, 2, 3, 4, 5, 6, 1}) << endl;
    return 0;
}