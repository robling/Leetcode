#include "../include/prevector.h"
#include <bitset>
using std::bitset;

bool isValidSudoku(vector<vector<char>>& board)
{
    bitset<27 * 9> checkboard;
    auto hash_1 = [](int i, int j, char c){
        return ((i / 3) * 3 + (j / 3)) * 9 + (c - '1');
    };
    auto hash_2 = [](int i, int j, char c){
        return 81 + 9 * i + (c - '1');
    };
    auto hash_3 = [](int i, int j, char c){
        return 162 + 9 * j + (c - '1');
    };
    for (int i = 0; i != 9; i++)
    {
        for (int j = 0; j != 9; j++)
        {
            cout << i << ", " << j << ": " << board[i][j] << "\t\t";
            cout << hash_1(i, j, board[i][j]) << "\t"
                 << hash_2(i, j, board[i][j]) << "\t"
                 << hash_3(i, j, board[i][j]) << endl;
            if (board[i][j] == '.') continue;
            if (checkboard.test(hash_1(i, j, board[i][j]))) cout << "!!!!" << i << ", " << j << ": " << board[i][j] << endl;//, return false;
            checkboard[hash_1(i, j, board[i][j])] = true;
            if (checkboard.test(hash_2(i, j, board[i][j]))) cout << "!!!!" << i << ", " << j << ": " << board[i][j] << endl;//, return false;
            checkboard[hash_2(i, j, board[i][j])] = true;
            if (checkboard.test(hash_3(i, j, board[i][j]))) cout << "!!!!" << i << ", " << j << ": " << board[i][j] << endl;//, return false;
            checkboard[hash_3(i, j, board[i][j])] = true;
        }
    }
    return true;
}

int Mymain()
{
    cout << (int)'1' << ": " << (int)'9' << endl;
    vector<vector<char>> board {
        {'5','.','.',  '.','7','.',  '.','.','.'},
        {'6','.','.',  '1','9','5',  '.','.','.'},
        {'.','9','8',  '.','.','.',  '.','6','.'},

        {'8','.','.',  '.','6','.',  '.','.','3'},
        {'4','.','.',  '8','.','3',  '.','.','1'},
        {'7','.','.',  '.','2','.',  '.','.','6'},

        {'.','6','.',  '.','.','.',  '2','8','.'},
        {'.','.','.',  '4','1','9',  '.','.','5'},
        {'.','.','.',  '.','8','.',  '.','.','9'},
    };
    cout << isValidSudoku(board) << endl;
}
