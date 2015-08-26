#include "../include/prevector.h"
#include <cstring>
using std::memset;

bool row[9][9];
bool col[9][9];
bool table[3][3][9];

inline bool testValid(int i, int j, char ch)
{
    return !(row[i][ch - '1'] || col[j][ch - '1'] || table[i / 3][j / 3][ch - '1']);
}
inline void set(int i, int j, char ch, bool val)
{
    row[i][ch - '1'] = col[j][ch - '1'] = table[i / 3][j / 3][ch - '1'] = val;
}
inline void initChecks(const vector<vector<char>>& board)
{
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(table, 0, sizeof(table));
    for (int i = 0; i != 9; i++)
    {
        for (int j = 0; j != 9; j++)
        {
            if (board[i][j] == '.') continue;
            set(i, j, board[i][j], true);
        }
    }
}
bool plot(vector<vector<char>>& board, int i, int j)
{
    if (i > 8) return true;
    if (board[i][j] != '.') return plot(board, i + j / 8, (j + 1) % 9);
    for (int ch = '1'; ch <='9'; ch++){
        if (testValid(i, j, ch)){
            board[i][j] = ch;
            //cout << "TEST:" << ii << ", " << jj << ":\t" << ch << endl;
            set(i, j, ch, true);
            if (plot(board, i + j / 9, (j + 1) % 9))
                return true;
            set(i, j, ch, false);
            board[i][j] = '.';
        }
    }
    //cout << "TEST:" << i << ", " << j << "\t" << ":\tFAILED" << endl;
    return false;
}
void solveSudoku(vector<vector<char>>& board)
{
    initChecks(board);
    plot(board, 0, 0);
}
int Mymain()
{
    vector<vector<char>> board {
        {'5','3','.',  '.','7','.',  '.','.','.'},
        {'6','.','.',  '1','9','5',  '.','.','.'},
        {'.','9','8',  '.','.','.',  '.','6','.'},

        {'8','.','.',  '.','6','.',  '.','.','3'},
        {'4','.','.',  '8','.','3',  '.','.','1'},
        {'7','.','.',  '.','2','.',  '.','.','6'},

        {'.','6','.',  '.','.','.',  '2','8','.'},
        {'.','.','.',  '4','1','9',  '.','.','5'},
        {'.','.','.',  '.','8','.',  '.','.','9'},
    };
    solveSudoku(board);
    for (auto& line : board){
        PrintVector(line, " ");
    }
}
