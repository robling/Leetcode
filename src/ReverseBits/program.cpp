/**************************************************************
 * Author   : Robin Liu
 * Date     : 2015-05-01
 * Detail   : https://leetcode.com/submissions/detail/26722746/
 **************************************************************/
#include "../include/pre.h"

uint32_t reverseBits(uint32_t n)
{
    uint32_t val = 0;
    for (int i = 31, j = 0; i != -33; i -= 2, j++)
    {
        val = val | ((1 << j) & ((i > 0)?(n >> i):(n << -i)));
    }
    return val;
}

void Mymain()
{
    TIC
    for (uint32_t i = 43261596; i != 43261696; i++)
    {
        cout << reverseBits(i) << endl;
    }
    TOC
}