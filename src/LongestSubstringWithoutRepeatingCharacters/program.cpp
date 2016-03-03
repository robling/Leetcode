#include "../include/pre.h"
#include <unordered_map>
int lengthOfLongestSubstring(string s)
{
    if (s.size() == 0) return 0;
    int max = 0, cur = 0;
    auto it = s.begin();
    std::unordered_map<int, decltype(it)> chs;
    do
    {
        auto f = chs.find(*it);
        if (f == chs.end() || f->second < it - cur) cur++;
        else cur = it - f->second;
        chs[*it] = it;
        max = std::max(max, cur);
    }
    while (++it != s.end());
    return max;
}

int main()
{
    cout << "iterator memory: " << sizeof(decltype(std::declval<vector<int>>().begin())) << endl;
    cout << "int memory: " << sizeof(int) << endl;
    cout << lengthOfLongestSubstring("sdefgdertyhjhj");
    return 0;
}