#include "../include/pre.h"

int minPathSum(vector<vector<int>>& grid)
{
    int M = grid.size();
    int N = grid[0].size();
    
    vector<vector<int>> minsGrid = grid; //copy make
    for (int i = M - 2; i != -1; i--)
        minsGrid[i][N - 1] = minsGrid[i + 1][N - 1] + minsGrid[i][N - 1];
    for (int j = N - 2; j != -1; j--)
        minsGrid[M - 1][j] = minsGrid[M - 1][j + 1] + minsGrid[M - 1][j];
    for (int i = M - 2; i != -1; i--)
    {
        for (int j = N - 2; j != -1; j--)
        {
            minsGrid[i][j] = std::min(minsGrid[i][j + 1], minsGrid[i + 1][j]) + minsGrid[i][j];
        }
    }
    return minsGrid[0][0];
}
int main()
{
    vector<vector<int>> test = {
        {1, 2, 3,},
        {1, 2, 3,},
        {1, 2, 3,},
    };
    cout << minPathSum(test) << endl;
    return 0;
}