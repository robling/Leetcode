#include "../include/pre.h"

int mySqrt(int x)
{
    long long xx = x;
    long long rst = (xx + 1) / 2;
    long long left = 0, right = xx;
    while (left != right)
    {
        if (rst * rst == xx) break;
        if (right - left <= 1) {rst = left; break;}
        if (rst * rst > xx) right = rst;
        else left = rst;
        rst = (right + left + 1) / 2;
    }
    return rst;
}

int main()
{
    cout << mySqrt(0) << endl;
    cout << mySqrt(1) << endl;
    cout << mySqrt(2147483647) << endl;
    cout << mySqrt(2147395599) << endl;
    return 0;
}
