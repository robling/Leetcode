#include "prevector.h"
#include <random>
#include <ctime>
#include <algorithm>

void GenerateRandomArray(vector<int>& nums, size_t size = 100)
{
    std::time_t seed = std::time(nullptr);
    auto rand = std::mt19937(seed);
    nums.clear();
    while (size--) nums.push_back(static_cast<int>(rand() / 2));
}

auto nIncrease = [](int c, int n)->bool{return (n < c);};
auto nReduce = [](int c, int n)->bool{return (n > c);};
bool CheckSorted(vector<int>& nums, decltype(nIncrease) nCompare = nIncrease)
{
    auto it = nums.cbegin();
    auto tmp = *(it++);
    while (it != nums.cend()){
        if (nCompare(tmp, *it)) return false;
        tmp = *(it++);
    }
    return true;
}
