#include "../include/pre.h"


int countDigitOne_ugly(int n)
{
    auto per = [](int p){
        int rst = 0;
        while (p != 0){
            if (p % 10 == 1) rst++;
            p /= 10;
        }
        return rst;
    };
    int rst = 0;
    while (n != 0){
        rst += per(n);
        n--;
    }
    return rst;
}

//Right
//but very dirty
int countDigitOne(int n)
{
    if (n <= 0) return 0;
    auto pow10 = [](int k){
        int rst = 1;
        while (k != 0) {
            rst *= 10;
            k--;
        }
        return rst;
    };
    int num = n;
    int rst = n % 10 == 0 ? 0 : 1;
    int bit = 1;
    n /= 10;
    int t = 0;
    while (n != 0){
        t = n % 10;
        if (t != 0)
            rst += t * bit * pow10(bit - 1) + ((t > 1) ? pow10(bit) : (num - n * pow10(bit) + 1));
        n /= 10;
        bit++;
    }
    return rst;
}

int Mymain()
{
    {TIC
        cout << countDigitOne(10) << endl;
    TOC}
    {TIC
        cout << countDigitOne_ugly(0) << endl;
    TOC}
}
