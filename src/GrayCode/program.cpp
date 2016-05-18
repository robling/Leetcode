#include "../include/pre.h"

vector<int> grayCode(int n)
{
    if (0 == n) return {};
    vector<int> rst;
    rst.reserve(1 << n);
    rst.push_back(0);
    rst.push_back(1);
    for (int i = 1; i != n; i++)
    {
        auto curSize = rst.size();
        int plus = 1 << i;
        while (curSize--)
            rst.push_back(rst[curSize] + plus);
    }
    return rst;
}

int main()
{
    cout << grayCode(2) << endl;
    cout << grayCode(3) << endl;
    cout << grayCode(8) << endl;
    return 0;
}