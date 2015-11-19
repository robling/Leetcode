#include "../include/pre.h"

class NumMatrix
{
public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        makePartlySumArray(matrix);
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        row2++, col2++;
        return PartlySum_[row2][col2] - PartlySum_[row1][col2] - PartlySum_[row2][col1] + PartlySum_[row1][col1];
    }
private:
    void makePartlySumArray(const vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0) {
            PartlySum_ = {{0}};
            return;
        }
        auto& rst = PartlySum_;
        PartlySum_.resize(matrix.size() + 1);
        for (int i = 0; i != matrix.size() + 1; i++) rst[i].resize(matrix[0].size() + 1);
        for (int i = 1; i != matrix.size() + 1; i++) {
            for (int j = 1; j != matrix[0].size() + 1; j++) {
                rst[i][j] = rst[i][j - 1] + matrix[i - 1][j - 1];
            }
        }
        for (int i = 1; i != matrix[0].size() + 1; i++) {
            for (int j = 1; j != matrix.size() + 1; j++) {
                rst[j][i] = rst[j - 1][i] + rst[j][i];
            }
        }
        for (auto& v : rst) {
            for (auto i : v) {
                cout << i << ", ";
            }
            cout << "\n";
        }
    }
    vector<vector<int>> PartlySum_;
};

int main()
{
    // vector<vector<int>> matrix = {
    //     {3, 0, 1, 4, 2},
    //     {5, 6, 3, 2, 1},
    //     {1, 2, 0, 1, 5},
    //     {4, 1, 0, 1, 7},
    //     {1, 0, 3, 0, 5},
    // };
    vector<vector<int>> matrix = {
        {-4, -5},
    };
    NumMatrix test(matrix);
    cout << test.sumRegion(0, 1, 0, 1) << "\n";
    //cout << test.sumRegion(2, 1, 4, 3) << "\n";
    //cout << test.sumRegion(1, 1, 2, 2) << "\n";
    //cout << test.sumRegion(1, 2, 2, 4) << "\n";
    return 0;
}