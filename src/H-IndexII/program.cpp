#include "../include/pre.h"

int hIndex(vector<int>& citations)
{
    auto size = citations.size();
    if (size == 0) return 0;
    int s = 0, e = size - 1, it = e / 2, max = size;
    while (s < e)
    {
        if (size - it > citations[it]) s = it + 1;
        else e = it;
        it = (e + s) / 2;
    }
    return (size - it > citations[it]) ? 0 : size - s;
}

int main()
{
    vector<int> test = {0};
    cout << hIndex(test);
    return 0;
}