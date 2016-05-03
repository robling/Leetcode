#include "../include/pre.h"

int maxArea(vector<int>& height)
{
    auto i = height.begin();
    auto j = height.rbegin();
    int max = 0;
    while (i != j.base())
    {
        max = std::max(max, (int)(j.base() - i - 1) * std::min(*i, *j));
        if (*i < *j) i++;
        else j++;
    }
    return max;
}

int main()
{
    cout << maxArea(vector<int>{4, 3, 5 ,6 ,}) << endl;
    return 0;
}