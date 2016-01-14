#include "../include/pre.h"

// Got "Runtime error"  with leetcode but run properly locally
// I don't know whats wrong with this function
int maximalSquare(vector<vector<char>>& matrix)
{
    if (matrix.size() == 0) return 0;
    auto M = matrix.size();
    auto N = matrix[0].size();
    vector<vector<int>> p;
    p.resize(M + 1);
    int maxSideLength = 0;
    for (auto& pi : p) pi.resize(N + 1, 0);
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (matrix[i-1][j-1] == '1') {
                p[i][j] = std::min(std::min(p[i][j-1], p[i-1][j]), p[i-1][j-1]) + 1;
                maxSideLength = std::max(maxSideLength, p[i][j]);
            }
        }
    }
    return maxSideLength * maxSideLength;
}

int main()
{
    // vector<vector<char>> t {
    //     {'0',},
    // };
    vector<vector<char>> t {
        {'1','0','1','0','0',},
        {'1','0','1','1','1',},
        {'1','1','1','1','1',},
        {'1','0','0','1','0',},
    };
    cout << maximalSquare(t);
    return 0;
}