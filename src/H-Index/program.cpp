#include "../include/pre.h"

int hIndex_sort(vector<int>& citations) 
{
    std::sort(citations.begin(), citations.end());
    int max = citations.size();
    //no parallel
    for (auto ci : citations)
    {
        if (max > ci) max--;
        else break;
    }
    return max;
}

// Runtime Error on Leetcode,
// But nothing suprised when I complie on my own computer
int hIndex(vector<int>& citations) 
{
    auto max_index = citations.size();
    if (max_index == 0) return 0;
    auto max = *std::max_element(citations.begin(), citations.end());
    std::vector<int> count {max + 1, 0};
    for (auto ci : citations) {
        count[ci]++;
    }
    for (int i = 0; i != count.size(); i++)
    {
        if (count[i] == 0) continue;
        if (max_index > i) max_index--;
        else break;
    }
    return max_index;
}

int main()
{
    vector<int> test = {1, 7, 9, 2,};//{7, 0, 6, 1, 5, 4};
    cout << hIndex(test) << endl;
    return 0;
}