#include "../include/pre.h"

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    using namespace std;
    int col = matrix[0].size() - 1;
    int row = 0;
    while (col >= 0 && row < matrix.size())
    {
    	if (matrix[row][col] == target) return true;
    	if (matrix[row][col] >  target) {
    		col--;
    		continue;
    	}
    	if (matrix[row][col] <  target) {
    		row++;
    		continue;
    	}
    }
    return false;
}
    
int main()
{
    vector<vector<int>> matrix = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30},
    };
    cout << searchMatrix(matrix, 90);
    return 0;
}