#include "../include/prevector.h"

vector<vector<int>> generate(int numRows)
{
    if (numRows == 0) return {};
    vector<vector<int>> rst;
    for (int i = 1; i <= numRows; i++)
    {
        rst.push_back(vector<int>(i));
        rst[i - 1][0] = 1;
        rst[i - 1][i - 1] = 1;
    }
    for (int i = 2; i < numRows; i++)
    {
        for (int j = 1; j < i; j++)
        {
            rst[i][j] = rst[i - 1][j - 1] + rst[i - 1][j];
        }
    }
    return rst;
}

int Mymain()
{
    auto rst = generate(10);
    for (auto& vec : rst)
    {
        for (int i : vec)
        {
            cout << i << ", ";
        }
        cout << endl;
    }
    return 0;
}
