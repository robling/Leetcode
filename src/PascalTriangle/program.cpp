#include "../include/prevector.h"

//For 118
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

//For 119
//杨辉三角为二项式m次幂展开后的各项系数
//组合数C(m, k)表示(x, y)^m展开后第k项系数
//有递推公式：C(m, k + 1) = C(m, k) * (m - k - 1) / (k + 1)
vector<int> getRow(int rowIndex)
{
    if (rowIndex == 0) return {1};
    rowIndex++;
    vector<int> rst(rowIndex);
    rst[0] = rst[rowIndex - 1] = 1;

    for (int i = 1; i <= rowIndex / 2; i++)
    {
        rst[i] = rst[rowIndex - i - 1] = (int)(rst[i - 1] * (uint64_t)(rowIndex - i) / i);
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
    PrintVector(getRow(30));
    PrintVector(getRow(4));
    PrintVector(getRow(1));
    return 0;
}
