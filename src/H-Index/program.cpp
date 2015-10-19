#include "../include/pre.h"

int hIndex(vector<int>& citations) 
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

int main()
{
    vector<int> test = {7, 0, 6, 1, 5, 4};
    cout << hIndex(test) << endl;
    return 0;
}