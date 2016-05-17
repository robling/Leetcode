#include "../include/pre.h"
#include <unordered_map>

vector<int> topKFrequent(vector<int>& nums, int k)
{
    std::unordered_map<int, int> count;
    for (auto n : nums)
    {
        if (count.find(n) != count.end()) count[n]++;
        else count[n] = 1;
    }
    std::vector<std::pair<int, int>> vcount;
    vcount.reserve(nums.size());
    for (const auto& p : count)
    {
        vcount.emplace_back(p.second, p.first);
    }
    std::nth_element(vcount.begin(), vcount.begin() + k, vcount.end(), std::greater<typename decltype(vcount)::value_type>());
    vector<int> rst;
    for (auto it = vcount.begin(); it != vcount.begin() + k; it++)
    {
        rst.push_back(it->second);
    }
    return rst;
}

int main()
{
    vector<int> t = {1,1,1,2,2,3};
    cout << topKFrequent(t, 2);
    return 0;
}