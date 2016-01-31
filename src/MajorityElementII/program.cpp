#include "../include/pre.h"

vector<int> majorityElement(vector<int>& nums)
{
    int n1, n2;
    int t1, t2;
    n1 = n2 = t1 = t2 = 0;
    for (auto i : nums)
    {
        if (i == n1) { t1++; continue; }
        if (i == n2) { t2++; continue; }
        if (t1 == 0) { n1 = i; t1 = 1; continue; }
        if (t2 == 0) { n2 = i; t2 = 1; continue; }
        t1--;
        t2--;
    }
    vector<int> rst;
    if (std::count(nums.begin(), nums.end(), n1) > nums.size() / 3) rst.push_back(n1);
    if (n1 != n2 && std::count(nums.begin(), nums.end(), n2) > nums.size() / 3) rst.push_back(n2);
    return rst;
}

int main()
{
    //cout << majorityElement(vector<int>{1, 2, 3, 4, 5, 1, 2, 1, 2, 1, 2, });
    cout << majorityElement(vector<int>{1, 2, 2, 3});
    return 0;
}