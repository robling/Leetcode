#include "../include/prevector.h"
#include "cstring"
int FactorialCalc(int n)
{
    int rst = 1;
    while (n != 1)
        rst *= n--;
    return rst;
}

int xStep = 0, yStep = 0;
int** mapOfRst;
/// \return minimal required health
int CalcByCurrentPosition(vector<vector<int>>& dungeon, int nXoff, int nYoff)
{
	if (nXoff == xStep - 1)
	{
		int rst = 1;
        int tmpy = yStep;
		while (nYoff != tmpy)
        {
			rst -= dungeon[nXoff][--tmpy];
            rst = (rst <= 0) ? 1 : rst;
        }
		cout << "nXoff : " << nXoff << " | nYoff : " << nYoff << " | COST : " << rst << " : " << endl;
        mapOfRst[nXoff][nYoff] = rst;
        return rst;
	}
	if (nYoff == yStep - 1)
	{
		int rst = 1;
        int tmpx = xStep;
		while (nXoff != tmpx)
    	{
            rst -= dungeon[--tmpx][nYoff];
            rst = (rst <= 0) ? 1 : rst;
        }
		cout << "nXoff : " << nXoff << " | nYoff : " << nYoff << " | COST : " << rst << " : " << endl;
        mapOfRst[nXoff][nYoff] = rst;
        return rst;
	}
	int a = mapOfRst[nXoff + 1][nYoff] != 0 ? mapOfRst[nXoff + 1][nYoff] : CalcByCurrentPosition(dungeon, nXoff + 1, nYoff);
	int b = mapOfRst[nXoff][nYoff + 1] != 0 ? mapOfRst[nXoff][nYoff + 1] : CalcByCurrentPosition(dungeon, nXoff, nYoff + 1);
	int rst = (a < b ? a : b) - dungeon[nXoff][nYoff];
    rst = (rst <= 0) ? 1 : rst;
    cout << "nXoff : " << nXoff << " | nYoff : " << nYoff << " | COST : " << rst << " | " << "a : " << a << " b : " << b << endl;
    mapOfRst[nXoff][nYoff] = rst;
	return rst;
}

int calculateMinimumHP(vector<vector<int>>& dungeon)
{
    xStep = dungeon.size();
    yStep = dungeon.at(0).size();
    if (xStep == 0 || yStep == 0) throw "Invalid input";
    mapOfRst = new int *[xStep];
    for (int i = 0; i != xStep; i++)
    {
        mapOfRst[i] = new int[yStep];
        memset(mapOfRst[i], 0, sizeof(int) * yStep);
    }
    int rst = CalcByCurrentPosition(dungeon, 0, 0);
    for (int i = 0; i != xStep; i++)
    {
        delete [] mapOfRst[i];
    }
    delete [] mapOfRst;
    return rst;
}

int Mymain()
{
    TIC
    vector<vector<int>> test = {
        {1, -3, 3},
        {0, -2, 0},
        {-3, -3, -3}
    };
    vector<vector<int>> test0 = {
        {1, 2, 1},
        {-2, -3, -3},
        {3, 2, -2}
    };
    vector<vector<int>> test1 = {
        {-2, -3, -1},
        {-10, -10, 1},
        {10, 30, -5},
        {-2, -3, -1},
        {-10, -10, 1},
        {10, 30, -5},
        {-2, -3, -1},
        {-10, -10, 1},
        {10, 30, -5}
    };
    vector<vector<int>> test2 = {
        {-9}
    };
    cout << "Result : " << calculateMinimumHP(test) << endl;
    TOC
}
