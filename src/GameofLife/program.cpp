#include "../include/pre.h"

void gameOfLife(vector<vector<int>>& board)
{
    int M = board.size();
    int N = board[0].size();
    auto checkIfLife = [&](int i, int j) {
        if(i < 0 || i >= M) return 0;
        if(j < 0 || j >= N) return 0;
        return board[i][j] & 1;
    };
    for (int i = 0; i != M; i++)
    {
        for (int j = 0; j != N; j++)
        {
            int count = checkIfLife(i - 1, j) + checkIfLife(i, j - 1) + checkIfLife(i + 1, j) + checkIfLife(i, j + 1) +
                        checkIfLife(i - 1, j - 1) + checkIfLife(i + 1, j - 1) + checkIfLife(i - 1, j + 1) + checkIfLife(i + 1, j + 1);
            nbcount[i][j] = count;
            do
            {
                if (count > 3 || count < 2) { board[i][j] &= 1; break; } // * -> 0*
                if (count == 3            ) { board[i][j] |= 2; break; } // * -> 1*
                /*if (count == 2)*/           board[i][j] |= ((board[i][j] & 1) << 1); // 1 -> 11 ; 0 -> 00
            }
            while(false);
        }
        if (i < 1) continue;
        for (auto& b : board[i - 1]) b = (b >> 1);
    }
    for (auto& b : board[M - 1]) b = (b >> 1);
}
int main()
{
    vector<vector<int>> test = {
        {1, 1, 1},
        {0, 1, 1},
        {0, 0, 1},
    };
    gameOfLife(test);
    for (auto& row : test)
    {
        for (auto i : row)
        {
            cout << i << ", ";
        }
        cout << "\n";
    }
    return 0;
}